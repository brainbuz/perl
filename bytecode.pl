use strict;
my %alias_to = (
    U32 => [qw(PADOFFSET STRLEN)],
    I32 => [qw(SSize_t long)],
    U16 => [qw(OPCODE line_t short)],
    U8 => [qw(char)],
);

my @optype= qw(OP UNOP BINOP LOGOP CONDOP LISTOP PMOP SVOP GVOP PVOP LOOP COP);

# Nullsv *must* come first in the following so that the condition
# ($$sv == 0) can continue to be used to test (sv == Nullsv).
my @specialsv = qw(Nullsv &PL_sv_undef &PL_sv_yes &PL_sv_no);

my (%alias_from, $from, $tos);
while (($from, $tos) = each %alias_to) {
    map { $alias_from{$_} = $from } @$tos;
}

my $c_header = <<'EOT';
/*
 *      Copyright (c) 1996-1998 Malcolm Beattie
 *
 *      You may distribute under the terms of either the GNU General Public
 *      License or the Artistic License, as specified in the README file.
 *
 */
/*
 * This file is autogenerated from bytecode.pl. Changes made here will be lost.
 */
EOT

my $perl_header;
($perl_header = $c_header) =~ s{[/ ]?\*/?}{#}g;

unlink "byterun.c", "byterun.h", "ext/B/B/Asmdata.pm";

#
# Start with boilerplate for Asmdata.pm
#
open(ASMDATA_PM, ">ext/B/B/Asmdata.pm") or die "ext/B/B/Asmdata.pm: $!";
print ASMDATA_PM $perl_header, <<'EOT';
package B::Asmdata;
use Exporter;
@ISA = qw(Exporter);
@EXPORT_OK = qw(%insn_data @insn_name @optype @specialsv_name);
use vars qw(%insn_data @insn_name @optype @specialsv_name);

EOT
print ASMDATA_PM <<"EOT";
\@optype = qw(@optype);
\@specialsv_name = qw(@specialsv);

# XXX insn_data is initialised this way because with a large
# %insn_data = (foo => [...], bar => [...], ...) initialiser
# I get a hard-to-track-down stack underflow and segfault.
EOT

#
# Boilerplate for byterun.c
#
open(BYTERUN_C, ">byterun.c") or die "byterun.c: $!";
print BYTERUN_C $c_header, <<'EOT';

#include "EXTERN.h"
#include "perl.h"

void *
bset_obj_store(void *obj, I32 ix)
{
    if (ix > PL_obj_list_fill) {
	if (PL_obj_list_fill == -1)
	    New(666, PL_obj_list, ix + 1, void*);
	else
	    Renew(PL_obj_list, ix + 1, void*);
	PL_obj_list_fill = ix;
    }
    PL_obj_list[ix] = obj;
    return obj;
}

#ifdef INDIRECT_BGET_MACROS
void byterun(struct bytestream bs)
#else
void byterun(PerlIO *fp)
#endif /* INDIRECT_BGET_MACROS */
{
    dTHR;
    int insn;
    while ((insn = BGET_FGETC()) != EOF) {
	switch (insn) {
EOT


my (@insn_name, $insn_num, $insn, $lvalue, $argtype, $flags, $fundtype);

while (<DATA>) {
    chop;
    s/#.*//;			# remove comments
    next unless length;
    if (/^%number\s+(.*)/) {
	$insn_num = $1;
	next;
    } elsif (/%enum\s+(.*?)\s+(.*)/) {
	create_enum($1, $2);	# must come before instructions
	next;
    }
    ($insn, $lvalue, $argtype, $flags) = split;
    $insn_name[$insn_num] = $insn;
    $fundtype = $alias_from{$argtype} || $argtype;

    #
    # Add the case statement and code for the bytecode interpreter in byterun.c
    #
    printf BYTERUN_C "\t  case INSN_%s:\t\t/* %d */\n\t    {\n",
	uc($insn), $insn_num;
    my $optarg = $argtype eq "none" ? "" : ", arg";
    if ($optarg) {
	printf BYTERUN_C "\t\t$argtype arg;\n\t\tBGET_%s(arg);\n", $fundtype;
    }
    if ($flags =~ /x/) {
	print BYTERUN_C "\t\tBSET_$insn($lvalue$optarg);\n";
    } elsif ($flags =~ /s/) {
	# Store instructions store to PL_obj_list[arg]. "lvalue" field is rvalue.
	print BYTERUN_C "\t\tBSET_OBJ_STORE($lvalue$optarg);\n";
    }
    elsif ($optarg && $lvalue ne "none") {
	print BYTERUN_C "\t\t$lvalue = arg;\n";
    }
    print BYTERUN_C "\t\tbreak;\n\t    }\n";

    #
    # Add the initialiser line for %insn_data in Asmdata.pm
    #
    print ASMDATA_PM <<"EOT";
\$insn_data{$insn} = [$insn_num, \\&PUT_$fundtype, "GET_$fundtype"];
EOT

    # Find the next unused instruction number
    do { $insn_num++ } while $insn_name[$insn_num];
}

#
# Finish off byterun.c
#
print BYTERUN_C <<'EOT';
	  default:
	    croak("Illegal bytecode instruction %d\n", insn);
	    /* NOTREACHED */
	}
    }
}
EOT

#
# Write the instruction and optype enum constants into byterun.h
#
open(BYTERUN_H, ">byterun.h") or die "byterun.h: $!";
print BYTERUN_H $c_header, <<'EOT';
#ifdef INDIRECT_BGET_MACROS
struct bytestream {
    void *data;
    int (*fgetc)(void *);
    int (*fread)(char *, size_t, size_t, void*);
    void (*freadpv)(U32, void*);
};
#endif /* INDIRECT_BGET_MACROS */

void *bset_obj_store _((void *, I32));

enum {
EOT

my $i = 0;
my $add_enum_value = 0;
my $max_insn;
for ($i = 0; $i < @insn_name; $i++) {
    $insn = uc($insn_name[$i]);
    if (defined($insn)) {
	$max_insn = $i;
	if ($add_enum_value) {
	    print BYTERUN_H "    INSN_$insn = $i,\t\t\t/* $i */\n";
	    $add_enum_value = 0;
	} else {
	    print BYTERUN_H "    INSN_$insn,\t\t\t/* $i */\n";
	}
    } else {
	$add_enum_value = 1;
    }
}

print BYTERUN_H "    MAX_INSN = $max_insn\n};\n";

print BYTERUN_H "\nenum {\n";
for ($i = 0; $i < @optype - 1; $i++) {
    printf BYTERUN_H "    OPt_%s,\t\t/* %d */\n", $optype[$i], $i;
}
printf BYTERUN_H "    OPt_%s\t\t/* %d */\n};\n\n", $optype[$i], $i;
print BYTERUN_H <<'EOT';
EXT int optype_size[]
#ifdef DOINIT
= {
EOT
for ($i = 0; $i < @optype - 1; $i++) {
    printf BYTERUN_H "    sizeof(%s),\n", $optype[$i], $i;
}
printf BYTERUN_H "    sizeof(%s)\n}\n", $optype[$i], $i;
print BYTERUN_H <<'EOT';
#endif /* DOINIT */
;

EOT

print BYTERUN_H <<'EOT';
#define INIT_SPECIALSV_LIST STMT_START { \
EOT
for ($i = 0; $i < @specialsv; $i++) {
    print BYTERUN_H "\tPL_specialsv_list[$i] = $specialsv[$i]; \\\n";
}
print BYTERUN_H <<'EOT';
    } STMT_END
EOT

#
# Finish off insn_data and create array initialisers in Asmdata.pm
#
print ASMDATA_PM <<'EOT';

my ($insn_name, $insn_data);
while (($insn_name, $insn_data) = each %insn_data) {
    $insn_name[$insn_data->[0]] = $insn_name;
}
# Fill in any gaps
@insn_name = map($_ || "unused", @insn_name);

1;

__END__

=head1 NAME

B::Asmdata - Autogenerated data about Perl ops, used to generate bytecode

=head1 SYNOPSIS

	use Asmdata;

=head1 DESCRIPTION

See F<ext/B/B/Asmdata.pm>.

=head1 AUTHOR

Malcolm Beattie, C<mbeattie@sable.ox.ac.uk>

=cut
EOT

__END__
# First set instruction ord("#") to read comment to end-of-line (sneaky)
%number 35
comment		arg			comment_t
# Then make ord("\n") into a no-op
%number 10
nop		none			none
# Now for the rest of the ordinary ones, beginning with \0 which is
# ret so that \0-terminated strings can be read properly as bytecode.
%number 0
#
#opcode		lvalue			argtype		flags	
#
ret		none			none		x
ldsv		PL_sv			svindex
ldop		PL_op			opindex
stsv		PL_sv			U32		s
stop		PL_op			U32		s
ldspecsv	PL_sv			U8		x
newsv		PL_sv			U8		x
newop		PL_op			U8		x
newopn		PL_op			U8		x
newpv		none			PV
pv_cur		PL_pv.xpv_cur		STRLEN
pv_free		PL_pv			none		x
sv_upgrade	PL_sv			char		x
sv_refcnt	SvREFCNT(PL_sv)		U32
sv_refcnt_add	SvREFCNT(PL_sv)		I32		x
sv_flags	SvFLAGS(PL_sv)		U32
xrv		SvRV(PL_sv)		svindex
xpv		PL_sv			none		x
xiv32		SvIVX(PL_sv)		I32
xiv64		SvIVX(PL_sv)		IV64
xnv		SvNVX(PL_sv)		double
xlv_targoff	LvTARGOFF(PL_sv)		STRLEN
xlv_targlen	LvTARGLEN(PL_sv)		STRLEN
xlv_targ	LvTARG(PL_sv)		svindex
xlv_type	LvTYPE(PL_sv)		char
xbm_useful	BmUSEFUL(PL_sv)		I32
xbm_previous	BmPREVIOUS(PL_sv)		U16
xbm_rare	BmRARE(PL_sv)		U8
xfm_lines	FmLINES(PL_sv)		I32
xio_lines	IoLINES(PL_sv)		long
xio_page	IoPAGE(PL_sv)		long
xio_page_len	IoPAGE_LEN(PL_sv)		long
xio_lines_left	IoLINES_LEFT(PL_sv)	long
xio_top_name	IoTOP_NAME(PL_sv)		pvcontents
xio_top_gv	*(SV**)&IoTOP_GV(PL_sv)	svindex
xio_fmt_name	IoFMT_NAME(PL_sv)		pvcontents
xio_fmt_gv	*(SV**)&IoFMT_GV(PL_sv)	svindex
xio_bottom_name	IoBOTTOM_NAME(PL_sv)	pvcontents
xio_bottom_gv	*(SV**)&IoBOTTOM_GV(PL_sv)	svindex
xio_subprocess	IoSUBPROCESS(PL_sv)	short
xio_type	IoTYPE(PL_sv)		char
xio_flags	IoFLAGS(PL_sv)		char
xcv_stash	*(SV**)&CvSTASH(PL_sv)	svindex
xcv_start	CvSTART(PL_sv)		opindex
xcv_root	CvROOT(PL_sv)		opindex
xcv_gv		*(SV**)&CvGV(PL_sv)	svindex
xcv_filegv	*(SV**)&CvFILEGV(PL_sv)	svindex
xcv_depth	CvDEPTH(PL_sv)		long
xcv_padlist	*(SV**)&CvPADLIST(PL_sv)	svindex
xcv_outside	*(SV**)&CvOUTSIDE(PL_sv)	svindex
xcv_flags	CvFLAGS(PL_sv)		U8
av_extend	PL_sv			SSize_t		x
av_push		PL_sv			svindex		x
xav_fill	AvFILLp(PL_sv)		SSize_t
xav_max		AvMAX(PL_sv)		SSize_t
xav_flags	AvFLAGS(PL_sv)		U8
xhv_riter	HvRITER(PL_sv)		I32
xhv_name	HvNAME(PL_sv)		pvcontents
hv_store	PL_sv			svindex		x
sv_magic	PL_sv			char		x
mg_obj		SvMAGIC(PL_sv)->mg_obj	svindex
mg_private	SvMAGIC(PL_sv)->mg_private	U16
mg_flags	SvMAGIC(PL_sv)->mg_flags	U8
mg_pv		SvMAGIC(PL_sv)		pvcontents	x
xmg_stash	*(SV**)&SvSTASH(PL_sv)	svindex
gv_fetchpv	PL_sv			strconst	x
gv_stashpv	PL_sv			strconst	x
gp_sv		GvSV(PL_sv)		svindex
gp_refcnt	GvREFCNT(PL_sv)		U32
gp_refcnt_add	GvREFCNT(PL_sv)		I32		x
gp_av		*(SV**)&GvAV(PL_sv)	svindex
gp_hv		*(SV**)&GvHV(PL_sv)	svindex
gp_cv		*(SV**)&GvCV(PL_sv)	svindex
gp_filegv	*(SV**)&GvFILEGV(PL_sv)	svindex
gp_io		*(SV**)&GvIOp(PL_sv)	svindex
gp_form		*(SV**)&GvFORM(PL_sv)	svindex
gp_cvgen	GvCVGEN(PL_sv)		U32
gp_line		GvLINE(PL_sv)		line_t
gp_share	PL_sv			svindex		x
xgv_flags	GvFLAGS(PL_sv)		U8
op_next		PL_op->op_next		opindex
op_sibling	PL_op->op_sibling	opindex
op_ppaddr	PL_op->op_ppaddr	strconst	x
op_targ		PL_op->op_targ		PADOFFSET
op_type		PL_op			OPCODE		x
op_seq		PL_op->op_seq		U16
op_flags	PL_op->op_flags		U8
op_private	PL_op->op_private	U8
op_first	cUNOP->op_first		opindex
op_last		cBINOP->op_last		opindex
op_other	cLOGOP->op_other	opindex
op_true		cCONDOP->op_true	opindex
op_false	cCONDOP->op_false	opindex
op_children	cLISTOP->op_children	U32
op_pmreplroot	cPMOP->op_pmreplroot	opindex
op_pmreplrootgv	*(SV**)&cPMOP->op_pmreplroot	svindex
op_pmreplstart	cPMOP->op_pmreplstart	opindex
op_pmnext	*(OP**)&cPMOP->op_pmnext	opindex
pregcomp	PL_op			pvcontents	x
op_pmflags	cPMOP->op_pmflags	U16
op_pmpermflags	cPMOP->op_pmpermflags	U16
op_sv		cSVOP->op_sv		svindex
op_gv		*(SV**)&cGVOP->op_gv	svindex
op_pv		cPVOP->op_pv		pvcontents
op_pv_tr	cPVOP->op_pv		op_tr_array
op_redoop	cLOOP->op_redoop	opindex
op_nextop	cLOOP->op_nextop	opindex
op_lastop	cLOOP->op_lastop	opindex
cop_label	cCOP->cop_label		pvcontents
cop_stash	*(SV**)&cCOP->cop_stash		svindex
cop_filegv	*(SV**)&cCOP->cop_filegv	svindex
cop_seq		cCOP->cop_seq		U32
cop_arybase	cCOP->cop_arybase	I32
cop_line	cCOP->cop_line		line_t
main_start	PL_main_start		opindex
main_root	PL_main_root		opindex
curpad		PL_curpad		svindex		x

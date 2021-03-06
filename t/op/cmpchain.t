#!./perl

BEGIN {
    chdir 't' if -d 't';
    require "./test.pl";
    set_up_inc("../lib");
}

use feature "isa";
no warnings qw(experimental::smartmatch experimental::isa);

my @cheqop = qw(== != eq ne);
my @nceqop = qw(<=> cmp ~~);
my @chrelop = qw(< > <= >= lt gt le ge);
my @ncrelop = qw(isa);

plan tests => @nceqop*@nceqop + 2*@cheqop*@nceqop + 2*@cheqop*@cheqop*@nceqop +
	@ncrelop*@ncrelop + 2*@chrelop*@ncrelop + 2*@chrelop*@chrelop*@ncrelop +

	@cheqop*@cheqop + @chrelop*@chrelop +
	@cheqop*@cheqop*@cheqop + @chrelop*@chrelop*@chrelop +
	(9 + 6*9)*13;

foreach my $c0 (@nceqop) {
    foreach my $c1 (@nceqop) {
	is eval("sub { no strict 'vars'; \$a $c0 \$b $c1 \$c }"), undef,
	    "$c0 $c1 non-associative";
    }
}
foreach my $c (@nceqop) {
    foreach my $e (@cheqop) {
	is eval("sub { no strict 'vars'; \$a $c \$b $e \$c }"), undef, "$c $e non-associative";
	is eval("sub { no strict 'vars'; \$a $e \$b $c \$c }"), undef, "$e $c non-associative";
    }
}
foreach my $c (@nceqop) {
    foreach my $e0 (@cheqop) {
	foreach my $e1 (@cheqop) {
	    is eval("sub { no strict 'vars'; \$a $c \$b $e0 \$c $e1 \$d }"), undef,
		"$c $e0 $e1 non-associative";
	    is eval("sub { no strict 'vars'; \$a $e0 \$b $e1 \$c $c \$d }"), undef,
		"$e0 $e1 $c non-associative";
	}
    }
}

foreach my $c0 (@ncrelop) {
    foreach my $c1 (@ncrelop) {
	is eval("sub { no strict 'vars'; \$a $c0 \$b $c1 \$c }"), undef,
	    "$c0 $c1 non-associative";
    }
}
foreach my $c (@ncrelop) {
    foreach my $e (@chrelop) {
	is eval("sub { no strict 'vars'; \$a $c \$b $e \$c }"), undef, "$c $e non-associative";
	is eval("sub { no strict 'vars'; \$a $e \$b $c \$c }"), undef, "$e $c non-associative";
    }
}
foreach my $c (@ncrelop) {
    foreach my $e0 (@chrelop) {
	foreach my $e1 (@chrelop) {
	    is eval("sub { no strict 'vars'; \$a $c \$b $e0 \$c $e1 \$d }"), undef,
		"$c $e0 $e1 non-associative";
	    is eval("sub { no strict 'vars'; \$a $e0 \$b $e1 \$c $c \$d }"), undef,
		"$e0 $e1 $c non-associative";
	}
    }
}

foreach my $e0 (@cheqop) {
    foreach my $e1 (@cheqop) {
	isnt eval("sub { no strict 'vars'; \$a $e0 \$b $e1 \$c }"), undef, "$e0 $e1 legal";
    }
}
foreach my $r0 (@chrelop) {
    foreach my $r1 (@chrelop) {
	isnt eval("sub { no strict 'vars'; \$a $r0 \$b $r1 \$c }"), undef, "$r0 $r1 legal";
    }
}
foreach my $e0 (@cheqop) {
    foreach my $e1 (@cheqop) {
	foreach my $e2 (@cheqop) {
	    isnt eval("sub { no strict 'vars'; \$a $e0 \$b $e1 \$c $e2 \$d }"), undef,
		"$e0 $e1 $e2 legal";
	}
    }
}
foreach my $r0 (@chrelop) {
    foreach my $r1 (@chrelop) {
	foreach my $r2 (@chrelop) {
	    isnt eval("sub { no strict 'vars'; \$a $r0 \$b $r1 \$c $r2 \$d }"), undef,
		"$r0 $r1 $r2 legal";
	}
    }
}

foreach(
    [5,3,2], [5,3,3], [5,3,4], [5,3,5], [5,3,6],
    [5,5,4], [5,5,5], [5,5,6],
    [5,7,4], [5,7,5], [5,7,6], [5,7,7], [5,7,8],
) {
    is join(",", "x", $_->[0] == $_->[1] != $_->[2], "y"),
	join(",", "x", !!($_->[0] == $_->[1] && $_->[1] != $_->[2]), "y"),
	"$_->[0] == $_->[1] != $_->[2]";
    is join(",", "x", $_->[0] != $_->[1] == $_->[2], "y"),
	join(",", "x", !!($_->[0] != $_->[1] && $_->[1] == $_->[2]), "y"),
	"$_->[0] != $_->[1] == $_->[2]";
    is join(",", "x", $_->[0] < $_->[1] <= $_->[2], "y"),
	join(",", "x", !!($_->[0] < $_->[1] && $_->[1] <= $_->[2]), "y"),
	"$_->[0] < $_->[1] <= $_->[2]";
    is join(",", "x", $_->[0] > $_->[1] >= $_->[2], "y"),
	join(",", "x", !!($_->[0] > $_->[1] && $_->[1] >= $_->[2]), "y"),
	"$_->[0] > $_->[1] >= $_->[2]";
    is join(",", "x", $_->[0] < $_->[1] > $_->[2], "y"),
	join(",", "x", !!($_->[0] < $_->[1] && $_->[1] > $_->[2]), "y"),
	"$_->[0] < $_->[1] > $_->[2]";
    my $e = "";
    is join(",", "x",
	    ($e .= "a", $_->[0]) == ($e .= "b", $_->[1]) !=
		($e .= "c", $_->[2]),
	    "y"),
	join(",", "x", !!($_->[0] == $_->[1] && $_->[1] != $_->[2]), "y"),
	"$_->[0] == $_->[1] != $_->[2] with side effects";
    is $e, "ab".($_->[0] == $_->[1] ? "c" : ""), "operand evaluation order";
    $e = "";
    is join(",", "x",
	    ($e .= "a", $_->[0]) < ($e .= "b", $_->[1]) <= ($e .= "c", $_->[2]),
	    "y"),
	join(",", "x", !!($_->[0] < $_->[1] && $_->[1] <= $_->[2]), "y"),
	"$_->[0] < $_->[1] <= $_->[2] with side effects";
    is $e, "ab".($_->[0] < $_->[1] ? "c" : ""), "operand evaluation order";
    foreach my $p (1..9) {
	is join(",", "x", $_->[0] == $_->[1] != $_->[2] == $p, "y"),
	    join(",", "x",
		!!($_->[0] == $_->[1] && $_->[1] != $_->[2] && $_->[2] == $p),
		"y"),
	    "$_->[0] == $_->[1] != $_->[2] == $p";
	is join(",", "x", $_->[0] < $_->[1] <= $_->[2] > $p, "y"),
	    join(",", "x",
		!!($_->[0] < $_->[1] && $_->[1] <= $_->[2] && $_->[2] > $p),
		"y"),
	    "$_->[0] < $_->[1] <= $_->[2] > $p";
	$e = "";
	is join(",", "x",
		($e .= "a", $_->[0]) == ($e .= "b", $_->[1]) !=
		    ($e .= "c", $_->[2]) == ($e .= "d", $p),
		"y"),
	    join(",", "x",
		!!($_->[0] == $_->[1] && $_->[1] != $_->[2] && $_->[2] == $p),
		"y"),
	    "$_->[0] == $_->[1] != $_->[2] == $p with side effects";
	is $e,
	    "ab".($_->[0] == $_->[1] ?
		    ("c".($_->[1] != $_->[2] ? "d" : "")) : ""),
	    "operand evaluation order";
	$e = "";
	is join(",", "x",
		($e .= "a", $_->[0]) < ($e .= "b", $_->[1]) <=
		    ($e .= "c", $_->[2]) > ($e .= "d", $p),
		"y"),
	    join(",", "x",
		!!($_->[0] < $_->[1] && $_->[1] <= $_->[2] && $_->[2] > $p),
		"y"),
	    "$_->[0] < $_->[1] <= $_->[2] > $p with side effects";
	is $e,
	    "ab".($_->[0] < $_->[1] ?
		    ("c".($_->[1] <= $_->[2] ? "d" : "")) : ""),
	    "operand evaluation order";
    }
}

/* !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!! 
   This file is built by embed.pl from global.sym, intrpvar.h,
   and thrdvar.h.  Any changes made here will be lost!
*/

/* (Doing namespace management portably in C is really gross.) */

/*  EMBED has no run-time penalty, but helps keep the Perl namespace
    from colliding with that used by other libraries pulled in
    by extensions or by embedding perl.  Allow a cc -DNO_EMBED
    override, however, to keep binary compatability with previous
    versions of perl.
*/


/* Put interpreter-specific symbols into a struct? */

#ifdef MULTIPLICITY

#ifndef USE_THREADS
/* If we do not have threads then per-thread vars are per-interpreter */

#define PL_Sv			(PL_curinterp->TSv)
#define PL_Xpv			(PL_curinterp->TXpv)
#define PL_av_fetch_sv		(PL_curinterp->Tav_fetch_sv)
#define PL_bodytarget		(PL_curinterp->Tbodytarget)
#define PL_bostr		(PL_curinterp->Tbostr)
#define PL_chopset		(PL_curinterp->Tchopset)
#define PL_colors		(PL_curinterp->Tcolors)
#define PL_colorset		(PL_curinterp->Tcolorset)
#define PL_curcop		(PL_curinterp->Tcurcop)
#define PL_curpad		(PL_curinterp->Tcurpad)
#define PL_curpm		(PL_curinterp->Tcurpm)
#define PL_curstack		(PL_curinterp->Tcurstack)
#define PL_curstackinfo		(PL_curinterp->Tcurstackinfo)
#define PL_curstash		(PL_curinterp->Tcurstash)
#define PL_defoutgv		(PL_curinterp->Tdefoutgv)
#define PL_defstash		(PL_curinterp->Tdefstash)
#define PL_delaymagic		(PL_curinterp->Tdelaymagic)
#define PL_dirty		(PL_curinterp->Tdirty)
#define PL_extralen		(PL_curinterp->Textralen)
#define PL_firstgv		(PL_curinterp->Tfirstgv)
#define PL_formtarget		(PL_curinterp->Tformtarget)
#define PL_hv_fetch_ent_mh	(PL_curinterp->Thv_fetch_ent_mh)
#define PL_hv_fetch_sv		(PL_curinterp->Thv_fetch_sv)
#define PL_in_eval		(PL_curinterp->Tin_eval)
#define PL_last_in_gv		(PL_curinterp->Tlast_in_gv)
#define PL_lastgotoprobe	(PL_curinterp->Tlastgotoprobe)
#define PL_lastscream		(PL_curinterp->Tlastscream)
#define PL_localizing		(PL_curinterp->Tlocalizing)
#define PL_mainstack		(PL_curinterp->Tmainstack)
#define PL_markstack		(PL_curinterp->Tmarkstack)
#define PL_markstack_max	(PL_curinterp->Tmarkstack_max)
#define PL_markstack_ptr	(PL_curinterp->Tmarkstack_ptr)
#define PL_maxscream		(PL_curinterp->Tmaxscream)
#define PL_modcount		(PL_curinterp->Tmodcount)
#define PL_nrs			(PL_curinterp->Tnrs)
#define PL_ofs			(PL_curinterp->Tofs)
#define PL_ofslen		(PL_curinterp->Tofslen)
#define PL_op			(PL_curinterp->Top)
#define PL_opsave		(PL_curinterp->Topsave)
#define PL_reg_call_cc		(PL_curinterp->Treg_call_cc)
#define PL_reg_eval_set		(PL_curinterp->Treg_eval_set)
#define PL_reg_flags		(PL_curinterp->Treg_flags)
#define PL_reg_re		(PL_curinterp->Treg_re)
#define PL_reg_start_tmp	(PL_curinterp->Treg_start_tmp)
#define PL_reg_start_tmpl	(PL_curinterp->Treg_start_tmpl)
#define PL_regbol		(PL_curinterp->Tregbol)
#define PL_regcc		(PL_curinterp->Tregcc)
#define PL_regcode		(PL_curinterp->Tregcode)
#define PL_regcomp_parse	(PL_curinterp->Tregcomp_parse)
#define PL_regcomp_rx		(PL_curinterp->Tregcomp_rx)
#define PL_regcompp		(PL_curinterp->Tregcompp)
#define PL_regdata		(PL_curinterp->Tregdata)
#define PL_regdummy		(PL_curinterp->Tregdummy)
#define PL_regendp		(PL_curinterp->Tregendp)
#define PL_regeol		(PL_curinterp->Tregeol)
#define PL_regexecp		(PL_curinterp->Tregexecp)
#define PL_regflags		(PL_curinterp->Tregflags)
#define PL_regindent		(PL_curinterp->Tregindent)
#define PL_reginput		(PL_curinterp->Treginput)
#define PL_reginterp_cnt	(PL_curinterp->Treginterp_cnt)
#define PL_reglastparen		(PL_curinterp->Treglastparen)
#define PL_regnarrate		(PL_curinterp->Tregnarrate)
#define PL_regnaughty		(PL_curinterp->Tregnaughty)
#define PL_regnpar		(PL_curinterp->Tregnpar)
#define PL_regprecomp		(PL_curinterp->Tregprecomp)
#define PL_regprev		(PL_curinterp->Tregprev)
#define PL_regprogram		(PL_curinterp->Tregprogram)
#define PL_regsawback		(PL_curinterp->Tregsawback)
#define PL_regseen		(PL_curinterp->Tregseen)
#define PL_regsize		(PL_curinterp->Tregsize)
#define PL_regstartp		(PL_curinterp->Tregstartp)
#define PL_regtill		(PL_curinterp->Tregtill)
#define PL_regxend		(PL_curinterp->Tregxend)
#define PL_restartop		(PL_curinterp->Trestartop)
#define PL_retstack		(PL_curinterp->Tretstack)
#define PL_retstack_ix		(PL_curinterp->Tretstack_ix)
#define PL_retstack_max		(PL_curinterp->Tretstack_max)
#define PL_rs			(PL_curinterp->Trs)
#define PL_savestack		(PL_curinterp->Tsavestack)
#define PL_savestack_ix		(PL_curinterp->Tsavestack_ix)
#define PL_savestack_max	(PL_curinterp->Tsavestack_max)
#define PL_scopestack		(PL_curinterp->Tscopestack)
#define PL_scopestack_ix	(PL_curinterp->Tscopestack_ix)
#define PL_scopestack_max	(PL_curinterp->Tscopestack_max)
#define PL_screamfirst		(PL_curinterp->Tscreamfirst)
#define PL_screamnext		(PL_curinterp->Tscreamnext)
#define PL_secondgv		(PL_curinterp->Tsecondgv)
#define PL_seen_evals		(PL_curinterp->Tseen_evals)
#define PL_seen_zerolen		(PL_curinterp->Tseen_zerolen)
#define PL_sortcop		(PL_curinterp->Tsortcop)
#define PL_sortcxix		(PL_curinterp->Tsortcxix)
#define PL_sortstash		(PL_curinterp->Tsortstash)
#define PL_stack_base		(PL_curinterp->Tstack_base)
#define PL_stack_max		(PL_curinterp->Tstack_max)
#define PL_stack_sp		(PL_curinterp->Tstack_sp)
#define PL_start_env		(PL_curinterp->Tstart_env)
#define PL_statbuf		(PL_curinterp->Tstatbuf)
#define PL_statcache		(PL_curinterp->Tstatcache)
#define PL_statgv		(PL_curinterp->Tstatgv)
#define PL_statname		(PL_curinterp->Tstatname)
#define PL_tainted		(PL_curinterp->Ttainted)
#define PL_timesbuf		(PL_curinterp->Ttimesbuf)
#define PL_tmps_floor		(PL_curinterp->Ttmps_floor)
#define PL_tmps_ix		(PL_curinterp->Ttmps_ix)
#define PL_tmps_max		(PL_curinterp->Ttmps_max)
#define PL_tmps_stack		(PL_curinterp->Ttmps_stack)
#define PL_top_env		(PL_curinterp->Ttop_env)
#define PL_toptarget		(PL_curinterp->Ttoptarget)

#endif /* !USE_THREADS */

/* These are always per-interpreter if there is more than one */

#define PL_Argv			(PL_curinterp->IArgv)
#define PL_Cmd			(PL_curinterp->ICmd)
#define PL_DBcv			(PL_curinterp->IDBcv)
#define PL_DBgv			(PL_curinterp->IDBgv)
#define PL_DBline		(PL_curinterp->IDBline)
#define PL_DBsignal		(PL_curinterp->IDBsignal)
#define PL_DBsingle		(PL_curinterp->IDBsingle)
#define PL_DBsub		(PL_curinterp->IDBsub)
#define PL_DBtrace		(PL_curinterp->IDBtrace)
#define PL_ampergv		(PL_curinterp->Iampergv)
#define PL_archpat_auto		(PL_curinterp->Iarchpat_auto)
#define PL_argvgv		(PL_curinterp->Iargvgv)
#define PL_argvoutgv		(PL_curinterp->Iargvoutgv)
#define PL_basetime		(PL_curinterp->Ibasetime)
#define PL_beginav		(PL_curinterp->Ibeginav)
#define PL_bytecode_iv_overflows	(PL_curinterp->Ibytecode_iv_overflows)
#define PL_bytecode_obj_list	(PL_curinterp->Ibytecode_obj_list)
#define PL_bytecode_obj_list_fill	(PL_curinterp->Ibytecode_obj_list_fill)
#define PL_bytecode_pv		(PL_curinterp->Ibytecode_pv)
#define PL_bytecode_sv		(PL_curinterp->Ibytecode_sv)
#define PL_cddir		(PL_curinterp->Icddir)
#define PL_compcv		(PL_curinterp->Icompcv)
#define PL_compiling		(PL_curinterp->Icompiling)
#define PL_comppad		(PL_curinterp->Icomppad)
#define PL_comppad_name		(PL_curinterp->Icomppad_name)
#define PL_comppad_name_fill	(PL_curinterp->Icomppad_name_fill)
#define PL_comppad_name_floor	(PL_curinterp->Icomppad_name_floor)
#define PL_copline		(PL_curinterp->Icopline)
#define PL_curcopdb		(PL_curinterp->Icurcopdb)
#define PL_curstname		(PL_curinterp->Icurstname)
#define PL_dbargs		(PL_curinterp->Idbargs)
#define PL_debdelim		(PL_curinterp->Idebdelim)
#define PL_debname		(PL_curinterp->Idebname)
#define PL_debstash		(PL_curinterp->Idebstash)
#define PL_defgv		(PL_curinterp->Idefgv)
#define PL_diehook		(PL_curinterp->Idiehook)
#define PL_dlevel		(PL_curinterp->Idlevel)
#define PL_dlmax		(PL_curinterp->Idlmax)
#define PL_doextract		(PL_curinterp->Idoextract)
#define PL_doswitches		(PL_curinterp->Idoswitches)
#define PL_dowarn		(PL_curinterp->Idowarn)
#define PL_dumplvl		(PL_curinterp->Idumplvl)
#define PL_e_script		(PL_curinterp->Ie_script)
#define PL_endav		(PL_curinterp->Iendav)
#define PL_envgv		(PL_curinterp->Ienvgv)
#define PL_errgv		(PL_curinterp->Ierrgv)
#define PL_eval_root		(PL_curinterp->Ieval_root)
#define PL_eval_start		(PL_curinterp->Ieval_start)
#define PL_exitlist		(PL_curinterp->Iexitlist)
#define PL_exitlistlen		(PL_curinterp->Iexitlistlen)
#define PL_fdpid		(PL_curinterp->Ifdpid)
#define PL_filemode		(PL_curinterp->Ifilemode)
#define PL_forkprocess		(PL_curinterp->Iforkprocess)
#define PL_formfeed		(PL_curinterp->Iformfeed)
#define PL_generation		(PL_curinterp->Igeneration)
#define PL_gensym		(PL_curinterp->Igensym)
#define PL_globalstash		(PL_curinterp->Iglobalstash)
#define PL_hintgv		(PL_curinterp->Ihintgv)
#define PL_in_clean_all		(PL_curinterp->Iin_clean_all)
#define PL_in_clean_objs	(PL_curinterp->Iin_clean_objs)
#define PL_incgv		(PL_curinterp->Iincgv)
#define PL_initav		(PL_curinterp->Iinitav)
#define PL_inplace		(PL_curinterp->Iinplace)
#define PL_last_proto		(PL_curinterp->Ilast_proto)
#define PL_lastfd		(PL_curinterp->Ilastfd)
#define PL_lastsize		(PL_curinterp->Ilastsize)
#define PL_lastspbase		(PL_curinterp->Ilastspbase)
#define PL_laststatval		(PL_curinterp->Ilaststatval)
#define PL_laststype		(PL_curinterp->Ilaststype)
#define PL_leftgv		(PL_curinterp->Ileftgv)
#define PL_lineary		(PL_curinterp->Ilineary)
#define PL_linestart		(PL_curinterp->Ilinestart)
#define PL_localpatches		(PL_curinterp->Ilocalpatches)
#define PL_main_cv		(PL_curinterp->Imain_cv)
#define PL_main_root		(PL_curinterp->Imain_root)
#define PL_main_start		(PL_curinterp->Imain_start)
#define PL_maxsysfd		(PL_curinterp->Imaxsysfd)
#define PL_mess_sv		(PL_curinterp->Imess_sv)
#define PL_minus_F		(PL_curinterp->Iminus_F)
#define PL_minus_a		(PL_curinterp->Iminus_a)
#define PL_minus_c		(PL_curinterp->Iminus_c)
#define PL_minus_l		(PL_curinterp->Iminus_l)
#define PL_minus_n		(PL_curinterp->Iminus_n)
#define PL_minus_p		(PL_curinterp->Iminus_p)
#define PL_modglobal		(PL_curinterp->Imodglobal)
#define PL_multiline		(PL_curinterp->Imultiline)
#define PL_mystrk		(PL_curinterp->Imystrk)
#define PL_ofmt			(PL_curinterp->Iofmt)
#define PL_oldlastpm		(PL_curinterp->Ioldlastpm)
#define PL_oldname		(PL_curinterp->Ioldname)
#define PL_op_mask		(PL_curinterp->Iop_mask)
#define PL_origargc		(PL_curinterp->Iorigargc)
#define PL_origargv		(PL_curinterp->Iorigargv)
#define PL_origfilename		(PL_curinterp->Iorigfilename)
#define PL_ors			(PL_curinterp->Iors)
#define PL_orslen		(PL_curinterp->Iorslen)
#define PL_parsehook		(PL_curinterp->Iparsehook)
#define PL_patchlevel		(PL_curinterp->Ipatchlevel)
#define PL_pending_ident	(PL_curinterp->Ipending_ident)
#define PL_perl_destruct_level	(PL_curinterp->Iperl_destruct_level)
#define PL_perldb		(PL_curinterp->Iperldb)
#define PL_preambleav		(PL_curinterp->Ipreambleav)
#define PL_preambled		(PL_curinterp->Ipreambled)
#define PL_preprocess		(PL_curinterp->Ipreprocess)
#define PL_profiledata		(PL_curinterp->Iprofiledata)
#define PL_replgv		(PL_curinterp->Ireplgv)
#define PL_rightgv		(PL_curinterp->Irightgv)
#define PL_rsfp			(PL_curinterp->Irsfp)
#define PL_rsfp_filters		(PL_curinterp->Irsfp_filters)
#define PL_sawampersand		(PL_curinterp->Isawampersand)
#define PL_sawstudy		(PL_curinterp->Isawstudy)
#define PL_sawvec		(PL_curinterp->Isawvec)
#define PL_siggv		(PL_curinterp->Isiggv)
#define PL_splitstr		(PL_curinterp->Isplitstr)
#define PL_statusvalue		(PL_curinterp->Istatusvalue)
#define PL_statusvalue_vms	(PL_curinterp->Istatusvalue_vms)
#define PL_stdingv		(PL_curinterp->Istdingv)
#define PL_strchop		(PL_curinterp->Istrchop)
#define PL_strtab		(PL_curinterp->Istrtab)
#define PL_strtab_mutex		(PL_curinterp->Istrtab_mutex)
#define PL_sub_generation	(PL_curinterp->Isub_generation)
#define PL_sublex_info		(PL_curinterp->Isublex_info)
#define PL_sv_arenaroot		(PL_curinterp->Isv_arenaroot)
#define PL_sv_count		(PL_curinterp->Isv_count)
#define PL_sv_objcount		(PL_curinterp->Isv_objcount)
#define PL_sv_root		(PL_curinterp->Isv_root)
#define PL_sys_intern		(PL_curinterp->Isys_intern)
#define PL_tainting		(PL_curinterp->Itainting)
#define PL_threadnum		(PL_curinterp->Ithreadnum)
#define PL_thrsv		(PL_curinterp->Ithrsv)
#define PL_unsafe		(PL_curinterp->Iunsafe)
#define PL_warnhook		(PL_curinterp->Iwarnhook)

#else	/* !MULTIPLICITY */

#define PL_IArgv		PL_Argv
#define PL_ICmd			PL_Cmd
#define PL_IDBcv		PL_DBcv
#define PL_IDBgv		PL_DBgv
#define PL_IDBline		PL_DBline
#define PL_IDBsignal		PL_DBsignal
#define PL_IDBsingle		PL_DBsingle
#define PL_IDBsub		PL_DBsub
#define PL_IDBtrace		PL_DBtrace
#define PL_Iampergv		PL_ampergv
#define PL_Iarchpat_auto	PL_archpat_auto
#define PL_Iargvgv		PL_argvgv
#define PL_Iargvoutgv		PL_argvoutgv
#define PL_Ibasetime		PL_basetime
#define PL_Ibeginav		PL_beginav
#define PL_Ibytecode_iv_overflows	PL_bytecode_iv_overflows
#define PL_Ibytecode_obj_list	PL_bytecode_obj_list
#define PL_Ibytecode_obj_list_fill	PL_bytecode_obj_list_fill
#define PL_Ibytecode_pv		PL_bytecode_pv
#define PL_Ibytecode_sv		PL_bytecode_sv
#define PL_Icddir		PL_cddir
#define PL_Icompcv		PL_compcv
#define PL_Icompiling		PL_compiling
#define PL_Icomppad		PL_comppad
#define PL_Icomppad_name	PL_comppad_name
#define PL_Icomppad_name_fill	PL_comppad_name_fill
#define PL_Icomppad_name_floor	PL_comppad_name_floor
#define PL_Icopline		PL_copline
#define PL_Icurcopdb		PL_curcopdb
#define PL_Icurstname		PL_curstname
#define PL_Idbargs		PL_dbargs
#define PL_Idebdelim		PL_debdelim
#define PL_Idebname		PL_debname
#define PL_Idebstash		PL_debstash
#define PL_Idefgv		PL_defgv
#define PL_Idiehook		PL_diehook
#define PL_Idlevel		PL_dlevel
#define PL_Idlmax		PL_dlmax
#define PL_Idoextract		PL_doextract
#define PL_Idoswitches		PL_doswitches
#define PL_Idowarn		PL_dowarn
#define PL_Idumplvl		PL_dumplvl
#define PL_Ie_script		PL_e_script
#define PL_Iendav		PL_endav
#define PL_Ienvgv		PL_envgv
#define PL_Ierrgv		PL_errgv
#define PL_Ieval_root		PL_eval_root
#define PL_Ieval_start		PL_eval_start
#define PL_Iexitlist		PL_exitlist
#define PL_Iexitlistlen		PL_exitlistlen
#define PL_Ifdpid		PL_fdpid
#define PL_Ifilemode		PL_filemode
#define PL_Iforkprocess		PL_forkprocess
#define PL_Iformfeed		PL_formfeed
#define PL_Igeneration		PL_generation
#define PL_Igensym		PL_gensym
#define PL_Iglobalstash		PL_globalstash
#define PL_Ihintgv		PL_hintgv
#define PL_Iin_clean_all	PL_in_clean_all
#define PL_Iin_clean_objs	PL_in_clean_objs
#define PL_Iincgv		PL_incgv
#define PL_Iinitav		PL_initav
#define PL_Iinplace		PL_inplace
#define PL_Ilast_proto		PL_last_proto
#define PL_Ilastfd		PL_lastfd
#define PL_Ilastsize		PL_lastsize
#define PL_Ilastspbase		PL_lastspbase
#define PL_Ilaststatval		PL_laststatval
#define PL_Ilaststype		PL_laststype
#define PL_Ileftgv		PL_leftgv
#define PL_Ilineary		PL_lineary
#define PL_Ilinestart		PL_linestart
#define PL_Ilocalpatches	PL_localpatches
#define PL_Imain_cv		PL_main_cv
#define PL_Imain_root		PL_main_root
#define PL_Imain_start		PL_main_start
#define PL_Imaxsysfd		PL_maxsysfd
#define PL_Imess_sv		PL_mess_sv
#define PL_Iminus_F		PL_minus_F
#define PL_Iminus_a		PL_minus_a
#define PL_Iminus_c		PL_minus_c
#define PL_Iminus_l		PL_minus_l
#define PL_Iminus_n		PL_minus_n
#define PL_Iminus_p		PL_minus_p
#define PL_Imodglobal		PL_modglobal
#define PL_Imultiline		PL_multiline
#define PL_Imystrk		PL_mystrk
#define PL_Iofmt		PL_ofmt
#define PL_Ioldlastpm		PL_oldlastpm
#define PL_Ioldname		PL_oldname
#define PL_Iop_mask		PL_op_mask
#define PL_Iorigargc		PL_origargc
#define PL_Iorigargv		PL_origargv
#define PL_Iorigfilename	PL_origfilename
#define PL_Iors			PL_ors
#define PL_Iorslen		PL_orslen
#define PL_Iparsehook		PL_parsehook
#define PL_Ipatchlevel		PL_patchlevel
#define PL_Ipending_ident	PL_pending_ident
#define PL_Iperl_destruct_level	PL_perl_destruct_level
#define PL_Iperldb		PL_perldb
#define PL_Ipreambleav		PL_preambleav
#define PL_Ipreambled		PL_preambled
#define PL_Ipreprocess		PL_preprocess
#define PL_Iprofiledata		PL_profiledata
#define PL_Ireplgv		PL_replgv
#define PL_Irightgv		PL_rightgv
#define PL_Irsfp		PL_rsfp
#define PL_Irsfp_filters	PL_rsfp_filters
#define PL_Isawampersand	PL_sawampersand
#define PL_Isawstudy		PL_sawstudy
#define PL_Isawvec		PL_sawvec
#define PL_Isiggv		PL_siggv
#define PL_Isplitstr		PL_splitstr
#define PL_Istatusvalue		PL_statusvalue
#define PL_Istatusvalue_vms	PL_statusvalue_vms
#define PL_Istdingv		PL_stdingv
#define PL_Istrchop		PL_strchop
#define PL_Istrtab		PL_strtab
#define PL_Istrtab_mutex	PL_strtab_mutex
#define PL_Isub_generation	PL_sub_generation
#define PL_Isublex_info		PL_sublex_info
#define PL_Isv_arenaroot	PL_sv_arenaroot
#define PL_Isv_count		PL_sv_count
#define PL_Isv_objcount		PL_sv_objcount
#define PL_Isv_root		PL_sv_root
#define PL_Isys_intern		PL_sys_intern
#define PL_Itainting		PL_tainting
#define PL_Ithreadnum		PL_threadnum
#define PL_Ithrsv		PL_thrsv
#define PL_Iunsafe		PL_unsafe
#define PL_Iwarnhook		PL_warnhook

#ifndef USE_THREADS

#define PL_TSv			PL_Sv
#define PL_TXpv			PL_Xpv
#define PL_Tav_fetch_sv		PL_av_fetch_sv
#define PL_Tbodytarget		PL_bodytarget
#define PL_Tbostr		PL_bostr
#define PL_Tchopset		PL_chopset
#define PL_Tcolors		PL_colors
#define PL_Tcolorset		PL_colorset
#define PL_Tcurcop		PL_curcop
#define PL_Tcurpad		PL_curpad
#define PL_Tcurpm		PL_curpm
#define PL_Tcurstack		PL_curstack
#define PL_Tcurstackinfo	PL_curstackinfo
#define PL_Tcurstash		PL_curstash
#define PL_Tdefoutgv		PL_defoutgv
#define PL_Tdefstash		PL_defstash
#define PL_Tdelaymagic		PL_delaymagic
#define PL_Tdirty		PL_dirty
#define PL_Textralen		PL_extralen
#define PL_Tfirstgv		PL_firstgv
#define PL_Tformtarget		PL_formtarget
#define PL_Thv_fetch_ent_mh	PL_hv_fetch_ent_mh
#define PL_Thv_fetch_sv		PL_hv_fetch_sv
#define PL_Tin_eval		PL_in_eval
#define PL_Tlast_in_gv		PL_last_in_gv
#define PL_Tlastgotoprobe	PL_lastgotoprobe
#define PL_Tlastscream		PL_lastscream
#define PL_Tlocalizing		PL_localizing
#define PL_Tmainstack		PL_mainstack
#define PL_Tmarkstack		PL_markstack
#define PL_Tmarkstack_max	PL_markstack_max
#define PL_Tmarkstack_ptr	PL_markstack_ptr
#define PL_Tmaxscream		PL_maxscream
#define PL_Tmodcount		PL_modcount
#define PL_Tnrs			PL_nrs
#define PL_Tofs			PL_ofs
#define PL_Tofslen		PL_ofslen
#define PL_Top			PL_op
#define PL_Topsave		PL_opsave
#define PL_Treg_call_cc		PL_reg_call_cc
#define PL_Treg_eval_set	PL_reg_eval_set
#define PL_Treg_flags		PL_reg_flags
#define PL_Treg_re		PL_reg_re
#define PL_Treg_start_tmp	PL_reg_start_tmp
#define PL_Treg_start_tmpl	PL_reg_start_tmpl
#define PL_Tregbol		PL_regbol
#define PL_Tregcc		PL_regcc
#define PL_Tregcode		PL_regcode
#define PL_Tregcomp_parse	PL_regcomp_parse
#define PL_Tregcomp_rx		PL_regcomp_rx
#define PL_Tregcompp		PL_regcompp
#define PL_Tregdata		PL_regdata
#define PL_Tregdummy		PL_regdummy
#define PL_Tregendp		PL_regendp
#define PL_Tregeol		PL_regeol
#define PL_Tregexecp		PL_regexecp
#define PL_Tregflags		PL_regflags
#define PL_Tregindent		PL_regindent
#define PL_Treginput		PL_reginput
#define PL_Treginterp_cnt	PL_reginterp_cnt
#define PL_Treglastparen	PL_reglastparen
#define PL_Tregnarrate		PL_regnarrate
#define PL_Tregnaughty		PL_regnaughty
#define PL_Tregnpar		PL_regnpar
#define PL_Tregprecomp		PL_regprecomp
#define PL_Tregprev		PL_regprev
#define PL_Tregprogram		PL_regprogram
#define PL_Tregsawback		PL_regsawback
#define PL_Tregseen		PL_regseen
#define PL_Tregsize		PL_regsize
#define PL_Tregstartp		PL_regstartp
#define PL_Tregtill		PL_regtill
#define PL_Tregxend		PL_regxend
#define PL_Trestartop		PL_restartop
#define PL_Tretstack		PL_retstack
#define PL_Tretstack_ix		PL_retstack_ix
#define PL_Tretstack_max	PL_retstack_max
#define PL_Trs			PL_rs
#define PL_Tsavestack		PL_savestack
#define PL_Tsavestack_ix	PL_savestack_ix
#define PL_Tsavestack_max	PL_savestack_max
#define PL_Tscopestack		PL_scopestack
#define PL_Tscopestack_ix	PL_scopestack_ix
#define PL_Tscopestack_max	PL_scopestack_max
#define PL_Tscreamfirst		PL_screamfirst
#define PL_Tscreamnext		PL_screamnext
#define PL_Tsecondgv		PL_secondgv
#define PL_Tseen_evals		PL_seen_evals
#define PL_Tseen_zerolen	PL_seen_zerolen
#define PL_Tsortcop		PL_sortcop
#define PL_Tsortcxix		PL_sortcxix
#define PL_Tsortstash		PL_sortstash
#define PL_Tstack_base		PL_stack_base
#define PL_Tstack_max		PL_stack_max
#define PL_Tstack_sp		PL_stack_sp
#define PL_Tstart_env		PL_start_env
#define PL_Tstatbuf		PL_statbuf
#define PL_Tstatcache		PL_statcache
#define PL_Tstatgv		PL_statgv
#define PL_Tstatname		PL_statname
#define PL_Ttainted		PL_tainted
#define PL_Ttimesbuf		PL_timesbuf
#define PL_Ttmps_floor		PL_tmps_floor
#define PL_Ttmps_ix		PL_tmps_ix
#define PL_Ttmps_max		PL_tmps_max
#define PL_Ttmps_stack		PL_tmps_stack
#define PL_Ttop_env		PL_top_env
#define PL_Ttoptarget		PL_toptarget

#endif /* USE_THREADS */

/* Hide what would have been interpreter-specific symbols? */

#ifdef EMBED


#ifndef USE_THREADS


#endif /* USE_THREADS */
#endif /* EMBED */
#endif /* MULTIPLICITY */

/* Now same trickey for per-thread variables */

#ifdef USE_THREADS

#define PL_Sv			(thr->TSv)
#define PL_Xpv			(thr->TXpv)
#define PL_av_fetch_sv		(thr->Tav_fetch_sv)
#define PL_bodytarget		(thr->Tbodytarget)
#define PL_bostr		(thr->Tbostr)
#define PL_chopset		(thr->Tchopset)
#define PL_colors		(thr->Tcolors)
#define PL_colorset		(thr->Tcolorset)
#define PL_curcop		(thr->Tcurcop)
#define PL_curpad		(thr->Tcurpad)
#define PL_curpm		(thr->Tcurpm)
#define PL_curstack		(thr->Tcurstack)
#define PL_curstackinfo		(thr->Tcurstackinfo)
#define PL_curstash		(thr->Tcurstash)
#define PL_defoutgv		(thr->Tdefoutgv)
#define PL_defstash		(thr->Tdefstash)
#define PL_delaymagic		(thr->Tdelaymagic)
#define PL_dirty		(thr->Tdirty)
#define PL_extralen		(thr->Textralen)
#define PL_firstgv		(thr->Tfirstgv)
#define PL_formtarget		(thr->Tformtarget)
#define PL_hv_fetch_ent_mh	(thr->Thv_fetch_ent_mh)
#define PL_hv_fetch_sv		(thr->Thv_fetch_sv)
#define PL_in_eval		(thr->Tin_eval)
#define PL_last_in_gv		(thr->Tlast_in_gv)
#define PL_lastgotoprobe	(thr->Tlastgotoprobe)
#define PL_lastscream		(thr->Tlastscream)
#define PL_localizing		(thr->Tlocalizing)
#define PL_mainstack		(thr->Tmainstack)
#define PL_markstack		(thr->Tmarkstack)
#define PL_markstack_max	(thr->Tmarkstack_max)
#define PL_markstack_ptr	(thr->Tmarkstack_ptr)
#define PL_maxscream		(thr->Tmaxscream)
#define PL_modcount		(thr->Tmodcount)
#define PL_nrs			(thr->Tnrs)
#define PL_ofs			(thr->Tofs)
#define PL_ofslen		(thr->Tofslen)
#define PL_op			(thr->Top)
#define PL_opsave		(thr->Topsave)
#define PL_reg_call_cc		(thr->Treg_call_cc)
#define PL_reg_eval_set		(thr->Treg_eval_set)
#define PL_reg_flags		(thr->Treg_flags)
#define PL_reg_re		(thr->Treg_re)
#define PL_reg_start_tmp	(thr->Treg_start_tmp)
#define PL_reg_start_tmpl	(thr->Treg_start_tmpl)
#define PL_regbol		(thr->Tregbol)
#define PL_regcc		(thr->Tregcc)
#define PL_regcode		(thr->Tregcode)
#define PL_regcomp_parse	(thr->Tregcomp_parse)
#define PL_regcomp_rx		(thr->Tregcomp_rx)
#define PL_regcompp		(thr->Tregcompp)
#define PL_regdata		(thr->Tregdata)
#define PL_regdummy		(thr->Tregdummy)
#define PL_regendp		(thr->Tregendp)
#define PL_regeol		(thr->Tregeol)
#define PL_regexecp		(thr->Tregexecp)
#define PL_regflags		(thr->Tregflags)
#define PL_regindent		(thr->Tregindent)
#define PL_reginput		(thr->Treginput)
#define PL_reginterp_cnt	(thr->Treginterp_cnt)
#define PL_reglastparen		(thr->Treglastparen)
#define PL_regnarrate		(thr->Tregnarrate)
#define PL_regnaughty		(thr->Tregnaughty)
#define PL_regnpar		(thr->Tregnpar)
#define PL_regprecomp		(thr->Tregprecomp)
#define PL_regprev		(thr->Tregprev)
#define PL_regprogram		(thr->Tregprogram)
#define PL_regsawback		(thr->Tregsawback)
#define PL_regseen		(thr->Tregseen)
#define PL_regsize		(thr->Tregsize)
#define PL_regstartp		(thr->Tregstartp)
#define PL_regtill		(thr->Tregtill)
#define PL_regxend		(thr->Tregxend)
#define PL_restartop		(thr->Trestartop)
#define PL_retstack		(thr->Tretstack)
#define PL_retstack_ix		(thr->Tretstack_ix)
#define PL_retstack_max		(thr->Tretstack_max)
#define PL_rs			(thr->Trs)
#define PL_savestack		(thr->Tsavestack)
#define PL_savestack_ix		(thr->Tsavestack_ix)
#define PL_savestack_max	(thr->Tsavestack_max)
#define PL_scopestack		(thr->Tscopestack)
#define PL_scopestack_ix	(thr->Tscopestack_ix)
#define PL_scopestack_max	(thr->Tscopestack_max)
#define PL_screamfirst		(thr->Tscreamfirst)
#define PL_screamnext		(thr->Tscreamnext)
#define PL_secondgv		(thr->Tsecondgv)
#define PL_seen_evals		(thr->Tseen_evals)
#define PL_seen_zerolen		(thr->Tseen_zerolen)
#define PL_sortcop		(thr->Tsortcop)
#define PL_sortcxix		(thr->Tsortcxix)
#define PL_sortstash		(thr->Tsortstash)
#define PL_stack_base		(thr->Tstack_base)
#define PL_stack_max		(thr->Tstack_max)
#define PL_stack_sp		(thr->Tstack_sp)
#define PL_start_env		(thr->Tstart_env)
#define PL_statbuf		(thr->Tstatbuf)
#define PL_statcache		(thr->Tstatcache)
#define PL_statgv		(thr->Tstatgv)
#define PL_statname		(thr->Tstatname)
#define PL_tainted		(thr->Ttainted)
#define PL_timesbuf		(thr->Ttimesbuf)
#define PL_tmps_floor		(thr->Ttmps_floor)
#define PL_tmps_ix		(thr->Ttmps_ix)
#define PL_tmps_max		(thr->Ttmps_max)
#define PL_tmps_stack		(thr->Ttmps_stack)
#define PL_top_env		(thr->Ttop_env)
#define PL_toptarget		(thr->Ttoptarget)

#endif /* USE_THREADS */

#ifdef PERL_GLOBAL_STRUCT

#define PL_No			(PL_Vars.GNo)
#define PL_Yes			(PL_Vars.GYes)
#define PL_amagic_generation	(PL_Vars.Gamagic_generation)
#define PL_an			(PL_Vars.Gan)
#define PL_bufend		(PL_Vars.Gbufend)
#define PL_bufptr		(PL_Vars.Gbufptr)
#define PL_collation_ix		(PL_Vars.Gcollation_ix)
#define PL_collation_name	(PL_Vars.Gcollation_name)
#define PL_collation_standard	(PL_Vars.Gcollation_standard)
#define PL_collxfrm_base	(PL_Vars.Gcollxfrm_base)
#define PL_collxfrm_mult	(PL_Vars.Gcollxfrm_mult)
#define PL_cop_seqmax		(PL_Vars.Gcop_seqmax)
#define PL_cryptseen		(PL_Vars.Gcryptseen)
#define PL_cshlen		(PL_Vars.Gcshlen)
#define PL_cshname		(PL_Vars.Gcshname)
#define PL_curinterp		(PL_Vars.Gcurinterp)
#define PL_curthr		(PL_Vars.Gcurthr)
#define PL_debug		(PL_Vars.Gdebug)
#define PL_do_undump		(PL_Vars.Gdo_undump)
#define PL_egid			(PL_Vars.Gegid)
#define PL_error_count		(PL_Vars.Gerror_count)
#define PL_euid			(PL_Vars.Geuid)
#define PL_eval_cond		(PL_Vars.Geval_cond)
#define PL_eval_mutex		(PL_Vars.Geval_mutex)
#define PL_eval_owner		(PL_Vars.Geval_owner)
#define PL_evalseq		(PL_Vars.Gevalseq)
#define PL_expect		(PL_Vars.Gexpect)
#define PL_gid			(PL_Vars.Ggid)
#define PL_he_root		(PL_Vars.Ghe_root)
#define PL_hexdigit		(PL_Vars.Ghexdigit)
#define PL_hints		(PL_Vars.Ghints)
#define PL_in_my		(PL_Vars.Gin_my)
#define PL_in_my_stash		(PL_Vars.Gin_my_stash)
#define PL_last_lop		(PL_Vars.Glast_lop)
#define PL_last_lop_op		(PL_Vars.Glast_lop_op)
#define PL_last_swash_hv	(PL_Vars.Glast_swash_hv)
#define PL_last_swash_key	(PL_Vars.Glast_swash_key)
#define PL_last_swash_klen	(PL_Vars.Glast_swash_klen)
#define PL_last_swash_slen	(PL_Vars.Glast_swash_slen)
#define PL_last_swash_tmps	(PL_Vars.Glast_swash_tmps)
#define PL_last_uni		(PL_Vars.Glast_uni)
#define PL_lex_brackets		(PL_Vars.Glex_brackets)
#define PL_lex_brackstack	(PL_Vars.Glex_brackstack)
#define PL_lex_casemods		(PL_Vars.Glex_casemods)
#define PL_lex_casestack	(PL_Vars.Glex_casestack)
#define PL_lex_defer		(PL_Vars.Glex_defer)
#define PL_lex_dojoin		(PL_Vars.Glex_dojoin)
#define PL_lex_expect		(PL_Vars.Glex_expect)
#define PL_lex_fakebrack	(PL_Vars.Glex_fakebrack)
#define PL_lex_formbrack	(PL_Vars.Glex_formbrack)
#define PL_lex_inpat		(PL_Vars.Glex_inpat)
#define PL_lex_inwhat		(PL_Vars.Glex_inwhat)
#define PL_lex_op		(PL_Vars.Glex_op)
#define PL_lex_repl		(PL_Vars.Glex_repl)
#define PL_lex_starts		(PL_Vars.Glex_starts)
#define PL_lex_state		(PL_Vars.Glex_state)
#define PL_lex_stuff		(PL_Vars.Glex_stuff)
#define PL_linestr		(PL_Vars.Glinestr)
#define PL_malloc_mutex		(PL_Vars.Gmalloc_mutex)
#define PL_max_intro_pending	(PL_Vars.Gmax_intro_pending)
#define PL_maxo			(PL_Vars.Gmaxo)
#define PL_min_intro_pending	(PL_Vars.Gmin_intro_pending)
#define PL_multi_close		(PL_Vars.Gmulti_close)
#define PL_multi_end		(PL_Vars.Gmulti_end)
#define PL_multi_open		(PL_Vars.Gmulti_open)
#define PL_multi_start		(PL_Vars.Gmulti_start)
#define PL_na			(PL_Vars.Gna)
#define PL_nexttoke		(PL_Vars.Gnexttoke)
#define PL_nexttype		(PL_Vars.Gnexttype)
#define PL_nextval		(PL_Vars.Gnextval)
#define PL_nice_chunk		(PL_Vars.Gnice_chunk)
#define PL_nice_chunk_size	(PL_Vars.Gnice_chunk_size)
#define PL_ninterps		(PL_Vars.Gninterps)
#define PL_nomemok		(PL_Vars.Gnomemok)
#define PL_nthreads		(PL_Vars.Gnthreads)
#define PL_nthreads_cond	(PL_Vars.Gnthreads_cond)
#define PL_numeric_local	(PL_Vars.Gnumeric_local)
#define PL_numeric_name		(PL_Vars.Gnumeric_name)
#define PL_numeric_standard	(PL_Vars.Gnumeric_standard)
#define PL_oldbufptr		(PL_Vars.Goldbufptr)
#define PL_oldoldbufptr		(PL_Vars.Goldoldbufptr)
#define PL_op_seqmax		(PL_Vars.Gop_seqmax)
#define PL_origalen		(PL_Vars.Gorigalen)
#define PL_origenviron		(PL_Vars.Gorigenviron)
#define PL_osname		(PL_Vars.Gosname)
#define PL_pad_reset_pending	(PL_Vars.Gpad_reset_pending)
#define PL_padix		(PL_Vars.Gpadix)
#define PL_padix_floor		(PL_Vars.Gpadix_floor)
#define PL_patleave		(PL_Vars.Gpatleave)
#define PL_pidstatus		(PL_Vars.Gpidstatus)
#define PL_runops		(PL_Vars.Grunops)
#define PL_sh_path		(PL_Vars.Gsh_path)
#define PL_sighandlerp		(PL_Vars.Gsighandlerp)
#define PL_specialsv_list	(PL_Vars.Gspecialsv_list)
#define PL_subline		(PL_Vars.Gsubline)
#define PL_subname		(PL_Vars.Gsubname)
#define PL_sv_mutex		(PL_Vars.Gsv_mutex)
#define PL_sv_no		(PL_Vars.Gsv_no)
#define PL_sv_undef		(PL_Vars.Gsv_undef)
#define PL_sv_yes		(PL_Vars.Gsv_yes)
#define PL_svref_mutex		(PL_Vars.Gsvref_mutex)
#define PL_thisexpr		(PL_Vars.Gthisexpr)
#define PL_thr_key		(PL_Vars.Gthr_key)
#define PL_threads_mutex	(PL_Vars.Gthreads_mutex)
#define PL_threadsv_names	(PL_Vars.Gthreadsv_names)
#define PL_tokenbuf		(PL_Vars.Gtokenbuf)
#define PL_uid			(PL_Vars.Guid)
#define PL_utf8_alnum		(PL_Vars.Gutf8_alnum)
#define PL_utf8_alpha		(PL_Vars.Gutf8_alpha)
#define PL_utf8_digit		(PL_Vars.Gutf8_digit)
#define PL_utf8_lower		(PL_Vars.Gutf8_lower)
#define PL_utf8_mark		(PL_Vars.Gutf8_mark)
#define PL_utf8_print		(PL_Vars.Gutf8_print)
#define PL_utf8_space		(PL_Vars.Gutf8_space)
#define PL_utf8_tolower		(PL_Vars.Gutf8_tolower)
#define PL_utf8_totitle		(PL_Vars.Gutf8_totitle)
#define PL_utf8_toupper		(PL_Vars.Gutf8_toupper)
#define PL_utf8_upper		(PL_Vars.Gutf8_upper)
#define PL_xiv_arenaroot	(PL_Vars.Gxiv_arenaroot)
#define PL_xiv_root		(PL_Vars.Gxiv_root)
#define PL_xnv_root		(PL_Vars.Gxnv_root)
#define PL_xpv_root		(PL_Vars.Gxpv_root)
#define PL_xrv_root		(PL_Vars.Gxrv_root)

#else /* !PERL_GLOBAL_STRUCT */

#define PL_GNo			PL_No
#define PL_GYes			PL_Yes
#define PL_Gamagic_generation	PL_amagic_generation
#define PL_Gan			PL_an
#define PL_Gbufend		PL_bufend
#define PL_Gbufptr		PL_bufptr
#define PL_Gcollation_ix	PL_collation_ix
#define PL_Gcollation_name	PL_collation_name
#define PL_Gcollation_standard	PL_collation_standard
#define PL_Gcollxfrm_base	PL_collxfrm_base
#define PL_Gcollxfrm_mult	PL_collxfrm_mult
#define PL_Gcop_seqmax		PL_cop_seqmax
#define PL_Gcryptseen		PL_cryptseen
#define PL_Gcshlen		PL_cshlen
#define PL_Gcshname		PL_cshname
#define PL_Gcurinterp		PL_curinterp
#define PL_Gcurthr		PL_curthr
#define PL_Gdebug		PL_debug
#define PL_Gdo_undump		PL_do_undump
#define PL_Gegid		PL_egid
#define PL_Gerror_count		PL_error_count
#define PL_Geuid		PL_euid
#define PL_Geval_cond		PL_eval_cond
#define PL_Geval_mutex		PL_eval_mutex
#define PL_Geval_owner		PL_eval_owner
#define PL_Gevalseq		PL_evalseq
#define PL_Gexpect		PL_expect
#define PL_Ggid			PL_gid
#define PL_Ghe_root		PL_he_root
#define PL_Ghexdigit		PL_hexdigit
#define PL_Ghints		PL_hints
#define PL_Gin_my		PL_in_my
#define PL_Gin_my_stash		PL_in_my_stash
#define PL_Glast_lop		PL_last_lop
#define PL_Glast_lop_op		PL_last_lop_op
#define PL_Glast_swash_hv	PL_last_swash_hv
#define PL_Glast_swash_key	PL_last_swash_key
#define PL_Glast_swash_klen	PL_last_swash_klen
#define PL_Glast_swash_slen	PL_last_swash_slen
#define PL_Glast_swash_tmps	PL_last_swash_tmps
#define PL_Glast_uni		PL_last_uni
#define PL_Glex_brackets	PL_lex_brackets
#define PL_Glex_brackstack	PL_lex_brackstack
#define PL_Glex_casemods	PL_lex_casemods
#define PL_Glex_casestack	PL_lex_casestack
#define PL_Glex_defer		PL_lex_defer
#define PL_Glex_dojoin		PL_lex_dojoin
#define PL_Glex_expect		PL_lex_expect
#define PL_Glex_fakebrack	PL_lex_fakebrack
#define PL_Glex_formbrack	PL_lex_formbrack
#define PL_Glex_inpat		PL_lex_inpat
#define PL_Glex_inwhat		PL_lex_inwhat
#define PL_Glex_op		PL_lex_op
#define PL_Glex_repl		PL_lex_repl
#define PL_Glex_starts		PL_lex_starts
#define PL_Glex_state		PL_lex_state
#define PL_Glex_stuff		PL_lex_stuff
#define PL_Glinestr		PL_linestr
#define PL_Gmalloc_mutex	PL_malloc_mutex
#define PL_Gmax_intro_pending	PL_max_intro_pending
#define PL_Gmaxo		PL_maxo
#define PL_Gmin_intro_pending	PL_min_intro_pending
#define PL_Gmulti_close		PL_multi_close
#define PL_Gmulti_end		PL_multi_end
#define PL_Gmulti_open		PL_multi_open
#define PL_Gmulti_start		PL_multi_start
#define PL_Gna			PL_na
#define PL_Gnexttoke		PL_nexttoke
#define PL_Gnexttype		PL_nexttype
#define PL_Gnextval		PL_nextval
#define PL_Gnice_chunk		PL_nice_chunk
#define PL_Gnice_chunk_size	PL_nice_chunk_size
#define PL_Gninterps		PL_ninterps
#define PL_Gnomemok		PL_nomemok
#define PL_Gnthreads		PL_nthreads
#define PL_Gnthreads_cond	PL_nthreads_cond
#define PL_Gnumeric_local	PL_numeric_local
#define PL_Gnumeric_name	PL_numeric_name
#define PL_Gnumeric_standard	PL_numeric_standard
#define PL_Goldbufptr		PL_oldbufptr
#define PL_Goldoldbufptr	PL_oldoldbufptr
#define PL_Gop_seqmax		PL_op_seqmax
#define PL_Gorigalen		PL_origalen
#define PL_Gorigenviron		PL_origenviron
#define PL_Gosname		PL_osname
#define PL_Gpad_reset_pending	PL_pad_reset_pending
#define PL_Gpadix		PL_padix
#define PL_Gpadix_floor		PL_padix_floor
#define PL_Gpatleave		PL_patleave
#define PL_Gpidstatus		PL_pidstatus
#define PL_Grunops		PL_runops
#define PL_Gsh_path		PL_sh_path
#define PL_Gsighandlerp		PL_sighandlerp
#define PL_Gspecialsv_list	PL_specialsv_list
#define PL_Gsubline		PL_subline
#define PL_Gsubname		PL_subname
#define PL_Gsv_mutex		PL_sv_mutex
#define PL_Gsv_no		PL_sv_no
#define PL_Gsv_undef		PL_sv_undef
#define PL_Gsv_yes		PL_sv_yes
#define PL_Gsvref_mutex		PL_svref_mutex
#define PL_Gthisexpr		PL_thisexpr
#define PL_Gthr_key		PL_thr_key
#define PL_Gthreads_mutex	PL_threads_mutex
#define PL_Gthreadsv_names	PL_threadsv_names
#define PL_Gtokenbuf		PL_tokenbuf
#define PL_Guid			PL_uid
#define PL_Gutf8_alnum		PL_utf8_alnum
#define PL_Gutf8_alpha		PL_utf8_alpha
#define PL_Gutf8_digit		PL_utf8_digit
#define PL_Gutf8_lower		PL_utf8_lower
#define PL_Gutf8_mark		PL_utf8_mark
#define PL_Gutf8_print		PL_utf8_print
#define PL_Gutf8_space		PL_utf8_space
#define PL_Gutf8_tolower	PL_utf8_tolower
#define PL_Gutf8_totitle	PL_utf8_totitle
#define PL_Gutf8_toupper	PL_utf8_toupper
#define PL_Gutf8_upper		PL_utf8_upper
#define PL_Gxiv_arenaroot	PL_xiv_arenaroot
#define PL_Gxiv_root		PL_xiv_root
#define PL_Gxnv_root		PL_xnv_root
#define PL_Gxpv_root		PL_xpv_root
#define PL_Gxrv_root		PL_xrv_root

#ifdef EMBED


#endif /* EMBED */
#endif /* PERL_GLOBAL_STRUCT */


#ifndef MIN_PERL_DEFINE  

#define DBsingle		PL_DBsingle
#define DBsub			PL_DBsub
#define compiling		PL_compiling
#define curcop			PL_curcop
#define curstash		PL_curstash
#define debstash		PL_debstash
#define defgv			PL_defgv
#define diehook			PL_diehook
#define dirty			PL_dirty
#define dowarn			PL_dowarn
#define errgv			PL_errgv
#define na			PL_na
#define perl_destruct_level	PL_perl_destruct_level
#define perldb			PL_perldb
#define rsfp			PL_rsfp
#define rsfp_filters		PL_rsfp_filters
#define stack_base		PL_stack_base
#define stack_sp		PL_stack_sp
#define stdingv			PL_stdingv
#define sv_arenaroot		PL_sv_arenaroot
#define sv_no			PL_sv_no
#define sv_undef		PL_sv_undef
#define sv_yes			PL_sv_yes
#define tainted			PL_tainted
#define tainting		PL_tainting

#endif /* MIN_PERL_DEFINE */

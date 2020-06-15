/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__D_Somatostatin
#define _nrn_initial _nrn_initial__D_Somatostatin
#define nrn_cur _nrn_cur__D_Somatostatin
#define _nrn_current _nrn_current__D_Somatostatin
#define nrn_jacob _nrn_jacob__D_Somatostatin
#define nrn_state _nrn_state__D_Somatostatin
#define _net_receive _net_receive__D_Somatostatin 
#define states states__D_Somatostatin 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define iCaL _p[0]
#define iCaPQ _p[1]
#define tmsb _p[2]
#define con _p[3]
#define alpha _p[4]
#define vmdl _p[5]
#define vmdPQ _p[6]
#define fVl _p[7]
#define B _p[8]
#define fVPQ _p[9]
#define kpmca _p[10]
#define kserca _p[11]
#define pleak _p[12]
#define vCaPQm _p[13]
#define sCaPQm _p[14]
#define vCaPQh _p[15]
#define sCaPQh _p[16]
#define tCaPQh1 _p[17]
#define tCaPQh2 _p[18]
#define tausom _p[19]
#define bas _p[20]
#define fcyt _p[21]
#define fmd _p[22]
#define fer _p[23]
#define sigmav _p[24]
#define vc _p[25]
#define f _p[26]
#define JL _p[27]
#define JPQ _p[28]
#define Jserca _p[29]
#define Jer _p[30]
#define mCaPQ_inf _p[31]
#define hCaPQ_inf _p[32]
#define tauCaPQm _p[33]
#define tauCaPQh _p[34]
#define Jmem _p[35]
#define y _p[36]
#define Jleak _p[37]
#define som _p[38]
#define JSS _p[39]
#define mCaPQ _p[40]
#define hCaPQ _p[41]
#define c _p[42]
#define cmdl _p[43]
#define cmdPQ _p[44]
#define cer _p[45]
#define S _p[46]
#define DmCaPQ _p[47]
#define DhCaPQ _p[48]
#define Dc _p[49]
#define Dcmdl _p[50]
#define DcmdPQ _p[51]
#define Dcer _p[52]
#define DS _p[53]
#define v _p[54]
#define _g _p[55]
#define _ion_iCaL	*_ppvar[0]._pval
#define _ion_iCaPQ	*_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_D_Somatostatin", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double S0 = 0;
 static double cer0 = 0;
 static double cmdPQ0 = 0;
 static double cmdl0 = 0;
 static double c0 = 0;
 static double delta_t = 0.01;
 static double hCaPQ0 = 0;
 static double mCaPQ0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"D_Somatostatin",
 "iCaL_D_Somatostatin",
 "iCaPQ_D_Somatostatin",
 "tmsb_D_Somatostatin",
 "con_D_Somatostatin",
 "alpha_D_Somatostatin",
 "vmdl_D_Somatostatin",
 "vmdPQ_D_Somatostatin",
 "fVl_D_Somatostatin",
 "B_D_Somatostatin",
 "fVPQ_D_Somatostatin",
 "kpmca_D_Somatostatin",
 "kserca_D_Somatostatin",
 "pleak_D_Somatostatin",
 "vCaPQm_D_Somatostatin",
 "sCaPQm_D_Somatostatin",
 "vCaPQh_D_Somatostatin",
 "sCaPQh_D_Somatostatin",
 "tCaPQh1_D_Somatostatin",
 "tCaPQh2_D_Somatostatin",
 "tausom_D_Somatostatin",
 "bas_D_Somatostatin",
 "fcyt_D_Somatostatin",
 "fmd_D_Somatostatin",
 "fer_D_Somatostatin",
 "sigmav_D_Somatostatin",
 "vc_D_Somatostatin",
 "f_D_Somatostatin",
 0,
 "JL_D_Somatostatin",
 "JPQ_D_Somatostatin",
 "Jserca_D_Somatostatin",
 "Jer_D_Somatostatin",
 "mCaPQ_inf_D_Somatostatin",
 "hCaPQ_inf_D_Somatostatin",
 "tauCaPQm_D_Somatostatin",
 "tauCaPQh_D_Somatostatin",
 "Jmem_D_Somatostatin",
 "y_D_Somatostatin",
 "Jleak_D_Somatostatin",
 "som_D_Somatostatin",
 "JSS_D_Somatostatin",
 0,
 "mCaPQ_D_Somatostatin",
 "hCaPQ_D_Somatostatin",
 "c_D_Somatostatin",
 "cmdl_D_Somatostatin",
 "cmdPQ_D_Somatostatin",
 "cer_D_Somatostatin",
 "S_D_Somatostatin",
 0,
 0};
 static Symbol* _CaL_sym;
 static Symbol* _CaPQ_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 56, _prop);
 	/*initialize range parameters*/
 	iCaL = 0;
 	iCaPQ = 0;
 	tmsb = 0;
 	con = 0;
 	alpha = 0;
 	vmdl = 0;
 	vmdPQ = 0;
 	fVl = 0;
 	B = 0;
 	fVPQ = 0;
 	kpmca = 0;
 	kserca = 0;
 	pleak = 0;
 	vCaPQm = 0;
 	sCaPQm = 0;
 	vCaPQh = 0;
 	sCaPQh = 0;
 	tCaPQh1 = 0;
 	tCaPQh2 = 0;
 	tausom = 0;
 	bas = 0;
 	fcyt = 0;
 	fmd = 0;
 	fer = 0;
 	sigmav = 0;
 	vc = 0;
 	f = 0;
 	_prop->param = _p;
 	_prop->param_size = 56;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaL */
 prop_ion = need_memb(_CaPQ_sym);
 	_ppvar[1]._pval = &prop_ion->param[3]; /* iCaPQ */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Delta_Somatostatin_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaL", -10000.);
 	ion_reg("CaPQ", -10000.);
 	_CaL_sym = hoc_lookup("CaL_ion");
 	_CaPQ_sym = hoc_lookup("CaPQ_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 56, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaPQ_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 D_Somatostatin /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Con/x86_64/Delta_Somatostatin.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[7], _dlist1[7];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DmCaPQ = ( mCaPQ_inf - mCaPQ ) / tauCaPQm ;
   DhCaPQ = ( hCaPQ_inf - hCaPQ ) / tauCaPQh ;
   Dc = fcyt * ( Jmem + Jer ) ;
   Dcmdl = fmd * JL - fmd * B * ( cmdl - c ) ;
   DcmdPQ = fmd * JPQ - fmd * B * ( cmdPQ - c ) ;
   Dcer = - fer * sigmav * Jer ;
   DS = JSS / vc - f * S ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DmCaPQ = DmCaPQ  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCaPQm )) ;
 DhCaPQ = DhCaPQ  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCaPQh )) ;
 Dc = Dc  / (1. - dt*( 0.0 )) ;
 Dcmdl = Dcmdl  / (1. - dt*( ( - ( fmd * B )*( ( 1.0 ) ) ) )) ;
 DcmdPQ = DcmdPQ  / (1. - dt*( ( - ( fmd * B )*( ( 1.0 ) ) ) )) ;
 Dcer = Dcer  / (1. - dt*( 0.0 )) ;
 DS = DS  / (1. - dt*( ( - ( f )*( 1.0 ) ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    mCaPQ = mCaPQ + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCaPQm)))*(- ( ( ( mCaPQ_inf ) ) / tauCaPQm ) / ( ( ( ( - 1.0 ) ) ) / tauCaPQm ) - mCaPQ) ;
    hCaPQ = hCaPQ + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCaPQh)))*(- ( ( ( hCaPQ_inf ) ) / tauCaPQh ) / ( ( ( ( - 1.0 ) ) ) / tauCaPQh ) - hCaPQ) ;
    c = c - dt*(- ( ( fcyt )*( ( Jmem + Jer ) ) ) ) ;
    cmdl = cmdl + (1. - exp(dt*(( - ( fmd * B )*( ( 1.0 ) ) ))))*(- ( ( fmd )*( JL ) - ( ( fmd )*( B ) )*( ( ( - c ) ) ) ) / ( ( - ( ( fmd )*( B ) )*( ( 1.0 ) ) ) ) - cmdl) ;
    cmdPQ = cmdPQ + (1. - exp(dt*(( - ( fmd * B )*( ( 1.0 ) ) ))))*(- ( ( fmd )*( JPQ ) - ( ( fmd )*( B ) )*( ( ( - c ) ) ) ) / ( ( - ( ( fmd )*( B ) )*( ( 1.0 ) ) ) ) - cmdPQ) ;
    cer = cer - dt*(- ( ( ( - fer )*( sigmav ) )*( Jer ) ) ) ;
    S = S + (1. - exp(dt*(( - ( f )*( 1.0 ) ))))*(- ( ( JSS ) / vc ) / ( ( - ( f )*( 1.0 ) ) ) - S) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 7;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  iCaL = _ion_iCaL;
  iCaPQ = _ion_iCaPQ;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  iCaL = _ion_iCaL;
  iCaPQ = _ion_iCaPQ;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaPQ_sym, _ppvar, 1, 3);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  S = S0;
  cer = cer0;
  cmdPQ = cmdPQ0;
  cmdl = cmdl0;
  c = c0;
  hCaPQ = hCaPQ0;
  mCaPQ = mCaPQ0;
 {
   tmsb = 0.001 ;
   con = 0.00000000594 ;
   alpha = 5.18e-15 ;
   vmdl = 2.12e-15 ;
   vmdPQ = 1.41e-15 ;
   fVl = 0.00340 ;
   B = 1.0 ;
   cmdl = 19.82903375122306 ;
   c = 0.3051356309084454 ;
   fVPQ = 0.00226 ;
   cmdPQ = 27.93917378868966 ;
   kpmca = 0.3 ;
   kserca = 0.4 ;
   pleak = 0.0003 ;
   cer = 413.8135591677398 ;
   mCaPQ = 0.5089033026581684 ;
   hCaPQ = 0.6672499701175263 ;
   vCaPQm = - 15.0 ;
   sCaPQm = 10.0 ;
   vCaPQh = - 33.0 ;
   sCaPQh = - 5.0 ;
   tCaPQh1 = 60.0 ;
   tCaPQh2 = 51.0 ;
   tausom = 2000.0 ;
   bas = 0.0009 ;
   fcyt = 0.01 ;
   fmd = 0.01 ;
   fer = 0.01 ;
   sigmav = 31.0 ;
   vc = 1e-13 ;
   f = 0.003 ;
   S = 18.71318922819339 ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  iCaL = _ion_iCaL;
  iCaPQ = _ion_iCaPQ;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  iCaL = _ion_iCaL;
  iCaPQ = _ion_iCaPQ;
 {   states(_p, _ppvar, _thread, _nt);
  } {
   JL = - alpha * iCaL / vmdl ;
   JPQ = - alpha * iCaPQ / vmdPQ ;
   Jserca = kserca * c ;
   Jer = ( Jleak - Jserca ) ;
   mCaPQ_inf = 1.0 / ( 1.0 + exp ( - ( v - vCaPQm ) / sCaPQm ) ) ;
   hCaPQ_inf = 1.0 / ( 1.0 + exp ( - ( v - vCaPQh ) / sCaPQh ) ) ;
   tauCaPQm = ( 1.0 / ( exp ( - ( v + 23.0 ) / 20.0 ) + exp ( ( v + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   tauCaPQh = ( tCaPQh1 / ( exp ( - ( v + 0.0 ) / 20.0 ) + exp ( ( v + 0.0 ) / 20.0 ) ) ) + tCaPQh2 ;
   Jmem = fVl * B * ( cmdl - c ) + fVPQ * B * ( cmdPQ - c ) - kpmca * c ;
   y = pow ( cmdPQ / 200.0 , 4.0 ) / ( pow ( 0.2 , 4.0 ) + pow ( cmdPQ / 200.0 , 4.0 ) ) ;
   Jleak = pleak * ( cer - c ) ;
   som = ( 200.0 * mCaPQ * hCaPQ * y / tausom ) + bas ;
   JSS = tmsb * som * con ;
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mCaPQ) - _p;  _dlist1[0] = &(DmCaPQ) - _p;
 _slist1[1] = &(hCaPQ) - _p;  _dlist1[1] = &(DhCaPQ) - _p;
 _slist1[2] = &(c) - _p;  _dlist1[2] = &(Dc) - _p;
 _slist1[3] = &(cmdl) - _p;  _dlist1[3] = &(Dcmdl) - _p;
 _slist1[4] = &(cmdPQ) - _p;  _dlist1[4] = &(DcmdPQ) - _p;
 _slist1[5] = &(cer) - _p;  _dlist1[5] = &(Dcer) - _p;
 _slist1[6] = &(S) - _p;  _dlist1[6] = &(DS) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Con/Delta_Somatostatin.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX D_Somatostatin\n"
  "USEION CaL READ iCaL\n"
  "USEION CaPQ READ iCaPQ\n"
  "RANGE iCaL, iCaPQ, tmsb, con, alpha, vmdl, vmdPQ, fVl, B, fVPQ, kpmca, kserca, pleak, vCaPQm, sCaPQm, vCaPQh, sCaPQh, tCaPQh1, tCaPQh2, tausom, bas, fcyt, fmd, fer, sigmav, vc, f \n"
  "RANGE JL, JPQ, Jserca, Jer, mCaPQ_inf, hCaPQ_inf, tauCaPQm, tauCaPQh, Jmem, y, Jleak, som, JSS \n"
  "}\n"
  "\n"
  "PARAMETER{   \n"
  "iCaL\n"
  "iCaPQ\n"
  "tmsb\n"
  "con\n"
  "alpha \n"
  "vmdl \n"
  "vmdPQ \n"
  "fVl \n"
  "B    \n"
  "fVPQ   \n"
  "kpmca \n"
  "kserca \n"
  "pleak  \n"
  "vCaPQm \n"
  "sCaPQm \n"
  "vCaPQh \n"
  "sCaPQh \n"
  "tCaPQh1 \n"
  "tCaPQh2 \n"
  "tausom \n"
  "bas \n"
  "fcyt\n"
  "fmd \n"
  "fer \n"
  "sigmav \n"
  "vc \n"
  "f \n"
  "v : This is the voltage when I run h.initial.....\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "JL \n"
  "JPQ \n"
  "Jserca \n"
  "Jer\n"
  "mCaPQ_inf \n"
  "hCaPQ_inf \n"
  "tauCaPQm \n"
  "tauCaPQh \n"
  "Jmem \n"
  "y \n"
  "Jleak \n"
  "som \n"
  "JSS \n"
  "}\n"
  "\n"
  "STATE{\n"
  "mCaPQ\n"
  "hCaPQ\n"
  "c\n"
  "cmdl\n"
  "cmdPQ\n"
  "cer\n"
  "S\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "tmsb = 0.001\n"
  "con = 0.00000000594\n"
  "alpha = 5.18e-15\n"
  "vmdl = 2.12e-15\n"
  "vmdPQ = 1.41e-15\n"
  "fVl = 0.00340\n"
  "B = 1 \n"
  "cmdl = 19.82903375122306 \n"
  "c = 0.3051356309084454  \n"
  "fVPQ = 0.00226\n"
  "cmdPQ = 27.93917378868966 \n"
  "kpmca = 0.3\n"
  "kserca = 0.4\n"
  "pleak = 0.0003\n"
  "cer = 413.8135591677398 \n"
  "mCaPQ = 0.5089033026581684  \n"
  "hCaPQ = 0.6672499701175263 \n"
  "vCaPQm = -15\n"
  "sCaPQm = 10\n"
  "vCaPQh = -33\n"
  "sCaPQh = -5\n"
  "tCaPQh1 = 60\n"
  "tCaPQh2 = 51\n"
  "tausom = 2000\n"
  "bas = 0.0009\n"
  "fcyt = 0.01\n"
  "fmd = 0.01\n"
  "fer = 0.01\n"
  "sigmav = 31\n"
  "vc = 1e-13\n"
  "f = 0.003\n"
  "S = 18.71318922819339 \n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "JL = -alpha * iCaL/vmdl\n"
  "JPQ = -alpha * iCaPQ/vmdPQ\n"
  "Jserca = kserca * c\n"
  "Jer = (Jleak - Jserca)\n"
  "mCaPQ_inf = 1/(1 + exp(-(v - vCaPQm)/sCaPQm))\n"
  "hCaPQ_inf = 1/(1 + exp(-(v - vCaPQh)/sCaPQh))\n"
  "tauCaPQm = (1/(exp(-(v + 23)/20) + exp((v + 23)/20))) + 0.05\n"
  "tauCaPQh = (tCaPQh1/(exp(-(v + 0)/20) + exp((v + 0)/20))) + tCaPQh2\n"
  "SOLVE states METHOD cnexp : Put current equation below this\n"
  "Jmem = fVl * B * (cmdl - c) + fVPQ * B * (cmdPQ - c) - kpmca * c\n"
  "y = pow(cmdPQ/200,4)/(pow(0.2,4) + pow(cmdPQ/200,4))\n"
  "Jleak = pleak * (cer - c)\n"
  "som = (200 * mCaPQ * hCaPQ * y/tausom) + bas\n"
  "JSS = tmsb * som * con\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "mCaPQ' = (mCaPQ_inf - mCaPQ)/tauCaPQm\n"
  "hCaPQ' = (hCaPQ_inf - hCaPQ)/tauCaPQh\n"
  "c' = fcyt * (Jmem + Jer) \n"
  "cmdl' = fmd * JL - fmd * B * (cmdl - c)\n"
  "cmdPQ' = fmd * JPQ - fmd * B * (cmdPQ-c)\n"
  "cer' = -fer * sigmav * Jer\n"
  "S' = JSS/vc - f * S\n"
  "}\n"
  ;
#endif

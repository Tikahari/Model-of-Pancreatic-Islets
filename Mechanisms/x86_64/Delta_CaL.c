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
 
#define nrn_init _nrn_init__D_CaL
#define _nrn_initial _nrn_initial__D_CaL
#define nrn_cur _nrn_cur__D_CaL
#define _nrn_current _nrn_current__D_CaL
#define nrn_jacob _nrn_jacob__D_CaL
#define nrn_state _nrn_state__D_CaL
#define _net_receive _net_receive__D_CaL 
#define states states__D_CaL 
 
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
#define sCaLm _p[0]
#define sCaLh _p[1]
#define vCaLm _p[2]
#define vCaLh _p[3]
#define tCaLh1 _p[4]
#define tCaLh2 _p[5]
#define gCaL _p[6]
#define mCaL_inf _p[7]
#define hCaL_inf _p[8]
#define tauCaLm _p[9]
#define tauCaLh _p[10]
#define iCaL _p[11]
#define mCaL _p[12]
#define hCaL _p[13]
#define DiCaL _p[14]
#define eCa _p[15]
#define DeCa _p[16]
#define DmCaL _p[17]
#define DhCaL _p[18]
#define v _p[19]
#define _g _p[20]
#define _ion_iCaL	*_ppvar[0]._pval
#define _ion_diCaLdv	*_ppvar[1]._pval
#define _ion_eCa	*_ppvar[2]._pval
 
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
 "setdata_D_CaL", _hoc_setdata,
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
 static double delta_t = 0.01;
 static double eCa0 = 0;
 static double hCaL0 = 0;
 static double iCaL0 = 0;
 static double mCaL0 = 0;
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
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"D_CaL",
 "sCaLm_D_CaL",
 "sCaLh_D_CaL",
 "vCaLm_D_CaL",
 "vCaLh_D_CaL",
 "tCaLh1_D_CaL",
 "tCaLh2_D_CaL",
 "gCaL_D_CaL",
 0,
 "mCaL_inf_D_CaL",
 "hCaL_inf_D_CaL",
 "tauCaLm_D_CaL",
 "tauCaLh_D_CaL",
 0,
 "iCaL_D_CaL",
 "mCaL_D_CaL",
 "hCaL_D_CaL",
 0,
 0};
 static Symbol* _CaL_sym;
 static Symbol* _Ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 21, _prop);
 	/*initialize range parameters*/
 	sCaLm = 0;
 	sCaLh = 0;
 	vCaLm = 0;
 	vCaLh = 0;
 	tCaLh1 = 0;
 	tCaLh2 = 0;
 	gCaL = 0;
 	_prop->param = _p;
 	_prop->param_size = 21;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaL */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diCaLdv */
 prop_ion = need_memb(_Ca_sym);
 nrn_promote(prop_ion, 0, 3);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eCa */
 
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

 void _Delta_CaL_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaL", 2.0);
 	ion_reg("Ca", 2.0);
 	_CaL_sym = hoc_lookup("CaL_ion");
 	_Ca_sym = hoc_lookup("Ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 21, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "Ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 D_CaL /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Delta_CaL.mod\n");
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
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DmCaL = ( mCaL_inf - mCaL ) / tauCaLm ;
   DhCaL = ( hCaL_inf - hCaL ) / tauCaLh ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DmCaL = DmCaL  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCaLm )) ;
 DhCaL = DhCaL  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCaLh )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    mCaL = mCaL + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCaLm)))*(- ( ( ( mCaL_inf ) ) / tauCaLm ) / ( ( ( ( - 1.0 ) ) ) / tauCaLm ) - mCaL) ;
    hCaL = hCaL + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCaLh)))*(- ( ( ( hCaL_inf ) ) / tauCaLh ) / ( ( ( ( - 1.0 ) ) ) / tauCaLh ) - hCaL) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
   _ion_eCa = eCa;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
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
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_Ca_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  eCa = eCa0;
  hCaL = hCaL0;
  iCaL = iCaL0;
  mCaL = mCaL0;
 {
   eCa = 65.0 ;
   gCaL = 0.7 ;
   mCaL = 0.8218051702003508 ;
   hCaL = 0.6672499701175263 ;
   sCaLm = 10.0 ;
   sCaLh = - 5.0 ;
   vCaLm = - 30.0 ;
   vCaLh = - 33.0 ;
   tCaLh1 = 60.0 ;
   tCaLh2 = 51.0 ;
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
 initmodel(_p, _ppvar, _thread, _nt);
   _ion_eCa = eCa;
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   mCaL_inf = 1.0 / ( 1.0 + exp ( - ( v - vCaLm ) / sCaLm ) ) ;
   hCaL_inf = 1.0 / ( 1.0 + exp ( - ( v - vCaLh ) / sCaLh ) ) ;
   tauCaLm = ( 1.0 / ( exp ( - ( v + 23.0 ) / 20.0 ) + exp ( ( v + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   tauCaLh = ( tCaLh1 / ( exp ( - ( v + 0.0 ) / 20.0 ) + exp ( ( v + 0.0 ) / 20.0 ) ) ) + tCaLh2 ;
   iCaL = gCaL * pow ( mCaL , 2.0 ) * hCaL * ( v - eCa ) ;
   }
 _current += iCaL;

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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _diCaL;
  _diCaL = iCaL;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diCaLdv += (_diCaL - iCaL)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iCaL += iCaL ;
  _ion_eCa = eCa;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
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
 {   states(_p, _ppvar, _thread, _nt);
  }   _ion_eCa = eCa;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mCaL) - _p;  _dlist1[0] = &(DmCaL) - _p;
 _slist1[1] = &(hCaL) - _p;  _dlist1[1] = &(DhCaL) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/Delta_CaL.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX D_CaL\n"
  "USEION CaL WRITE iCaL VALENCE 2\n"
  "USEION Ca WRITE eCa VALENCE 2\n"
  "RANGE sCaLm, sCaLh, vCaLm, vCaLh, tCaLh1, tCaLh2, gCaL\n"
  "RANGE mCaL_inf, hCaL_inf, tauCaLm, tauCaLh, iCaL\n"
  "}\n"
  "\n"
  "PARAMETER{   \n"
  "sCaLm\n"
  "sCaLh\n"
  "vCaLm \n"
  "vCaLh\n"
  "tCaLh1\n"
  "tCaLh2\n"
  "gCaL\n"
  "\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "mCaL_inf\n"
  "hCaL_inf\n"
  "tauCaLm\n"
  "tauCaLh\n"
  "v : This is the voltage when I run h.initial.....\n"
  "}\n"
  "\n"
  "STATE{\n"
  "iCaL\n"
  "eCa\n"
  "mCaL\n"
  "hCaL\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "eCa = 65\n"
  "gCaL = 0.7\n"
  "mCaL = 0.8218051702003508\n"
  "hCaL = 0.6672499701175263\n"
  "sCaLm = 10\n"
  "sCaLh = -5\n"
  "vCaLm = -30\n"
  "vCaLh = -33\n"
  "tCaLh1 = 60\n"
  "tCaLh2 = 51\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "mCaL_inf = 1/(1 + exp(-(v - vCaLm)/sCaLm))\n"
  "hCaL_inf = 1/(1 + exp(-(v - vCaLh)/sCaLh))    \n"
  "tauCaLm = (1/(exp(-(v + 23)/20) + exp((v + 23)/20))) + 0.05\n"
  "tauCaLh = (tCaLh1/(exp(-(v + 0)/20) + exp((v + 0)/20)))+tCaLh2\n"
  "SOLVE states METHOD cnexp :were putting this before current variable    \n"
  "iCaL = gCaL*pow(mCaL,2)*hCaL*(v-eCa)\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "mCaL'= (mCaL_inf - mCaL)/tauCaLm\n"
  "hCaL'=(hCaL_inf - hCaL)/tauCaLh\n"
  "}\n"
  "\n"
  ;
#endif

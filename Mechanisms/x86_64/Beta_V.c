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
 
#define nrn_init _nrn_init__B_V
#define _nrn_initial _nrn_initial__B_V
#define nrn_cur _nrn_cur__B_V
#define _nrn_current _nrn_current__B_V
#define nrn_jacob _nrn_jacob__B_V
#define nrn_state _nrn_state__B_V
#define _net_receive _net_receive__B_V 
#define states states__B_V 
 
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
#define Cm _p[0]
#define Vreal _p[1]
#define iCaL _p[2]
#define iCaP _p[3]
#define iCaT _p[4]
#define iKDR _p[5]
#define iPCa _p[6]
#define iKCa _p[7]
#define iBK _p[8]
#define iKATP _p[9]
#define iHERG _p[10]
#define iNaB _p[11]
#define iNa _p[12]
#define Vmi _p[13]
#define DVmi _p[14]
#define v _p[15]
#define _g _p[16]
#define _ion_iCaL	*_ppvar[0]._pval
#define _ion_iCaP	*_ppvar[1]._pval
#define _ion_iCaT	*_ppvar[2]._pval
#define _ion_iKDR	*_ppvar[3]._pval
#define _ion_iPCa	*_ppvar[4]._pval
#define _ion_iKCa	*_ppvar[5]._pval
#define _ion_iBK	*_ppvar[6]._pval
#define _ion_iKATP	*_ppvar[7]._pval
#define _ion_iHERG	*_ppvar[8]._pval
#define _ion_iNaB	*_ppvar[9]._pval
#define _ion_iNa	*_ppvar[10]._pval
#define _ion_Vmi	*_ppvar[11]._pval
#define _style_Vm	*((int*)_ppvar[12]._pvoid)
 
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
 "setdata_B_V", _hoc_setdata,
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
 static double Vmi0 = 0;
 static double delta_t = 0.01;
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
 
#define _cvode_ieq _ppvar[13]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"B_V",
 "Cm_B_V",
 "Vreal_B_V",
 0,
 0,
 0,
 0};
 static Symbol* _CaL_sym;
 static Symbol* _CaP_sym;
 static Symbol* _CaT_sym;
 static Symbol* _KDR_sym;
 static Symbol* _PCa_sym;
 static Symbol* _KCa_sym;
 static Symbol* _BK_sym;
 static Symbol* _KATP_sym;
 static Symbol* _HERG_sym;
 static Symbol* _NaB_sym;
 static Symbol* _Na_sym;
 static Symbol* _Vm_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	Cm = 0;
 	Vreal = 0;
 	_prop->param = _p;
 	_prop->param_size = 17;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 14, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaL */
 prop_ion = need_memb(_CaP_sym);
 	_ppvar[1]._pval = &prop_ion->param[3]; /* iCaP */
 prop_ion = need_memb(_CaT_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* iCaT */
 prop_ion = need_memb(_KDR_sym);
 	_ppvar[3]._pval = &prop_ion->param[3]; /* iKDR */
 prop_ion = need_memb(_PCa_sym);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* iPCa */
 prop_ion = need_memb(_KCa_sym);
 	_ppvar[5]._pval = &prop_ion->param[3]; /* iKCa */
 prop_ion = need_memb(_BK_sym);
 	_ppvar[6]._pval = &prop_ion->param[3]; /* iBK */
 prop_ion = need_memb(_KATP_sym);
 	_ppvar[7]._pval = &prop_ion->param[3]; /* iKATP */
 prop_ion = need_memb(_HERG_sym);
 	_ppvar[8]._pval = &prop_ion->param[3]; /* iHERG */
 prop_ion = need_memb(_NaB_sym);
 	_ppvar[9]._pval = &prop_ion->param[3]; /* iNaB */
 prop_ion = need_memb(_Na_sym);
 	_ppvar[10]._pval = &prop_ion->param[3]; /* iNa */
 prop_ion = need_memb(_Vm_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[11]._pval = &prop_ion->param[1]; /* Vmi */
 	_ppvar[12]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for Vm */
 
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

 void _Beta_V_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaL", -10000.);
 	ion_reg("CaP", -10000.);
 	ion_reg("CaT", -10000.);
 	ion_reg("KDR", -10000.);
 	ion_reg("PCa", -10000.);
 	ion_reg("KCa", -10000.);
 	ion_reg("BK", -10000.);
 	ion_reg("KATP", -10000.);
 	ion_reg("HERG", -10000.);
 	ion_reg("NaB", -10000.);
 	ion_reg("Na", -10000.);
 	ion_reg("Vm", 1.0);
 	_CaL_sym = hoc_lookup("CaL_ion");
 	_CaP_sym = hoc_lookup("CaP_ion");
 	_CaT_sym = hoc_lookup("CaT_ion");
 	_KDR_sym = hoc_lookup("KDR_ion");
 	_PCa_sym = hoc_lookup("PCa_ion");
 	_KCa_sym = hoc_lookup("KCa_ion");
 	_BK_sym = hoc_lookup("BK_ion");
 	_KATP_sym = hoc_lookup("KATP_ion");
 	_HERG_sym = hoc_lookup("HERG_ion");
 	_NaB_sym = hoc_lookup("NaB_ion");
 	_Na_sym = hoc_lookup("Na_ion");
 	_Vm_sym = hoc_lookup("Vm_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 14);
  hoc_register_dparam_semantics(_mechtype, 0, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaP_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "CaT_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "KDR_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "PCa_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "KCa_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "BK_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "KATP_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "HERG_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "NaB_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "Na_ion");
  hoc_register_dparam_semantics(_mechtype, 11, "Vm_ion");
  hoc_register_dparam_semantics(_mechtype, 12, "#Vm_ion");
  hoc_register_dparam_semantics(_mechtype, 13, "cvodeieq");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_V /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Beta_V.mod\n");
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
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DVmi = - ( ( iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa ) / Cm ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DVmi = DVmi  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    Vmi = Vmi - dt*(- ( - ( ( ( iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa ) ) / Cm ) ) ) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 1;}
 
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
  iCaP = _ion_iCaP;
  iCaT = _ion_iCaT;
  iKDR = _ion_iKDR;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iBK = _ion_iBK;
  iKATP = _ion_iKATP;
  iHERG = _ion_iHERG;
  iNaB = _ion_iNaB;
  iNa = _ion_iNa;
  Vmi = _ion_Vmi;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_Vmi = Vmi;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[0] = &(_ion_Vmi);
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
  iCaP = _ion_iCaP;
  iCaT = _ion_iCaT;
  iKDR = _ion_iKDR;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iBK = _ion_iBK;
  iKATP = _ion_iKATP;
  iHERG = _ion_iHERG;
  iNaB = _ion_iNaB;
  iNa = _ion_iNa;
  Vmi = _ion_Vmi;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaP_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_CaT_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_KDR_sym, _ppvar, 3, 3);
   nrn_update_ion_pointer(_PCa_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_KCa_sym, _ppvar, 5, 3);
   nrn_update_ion_pointer(_BK_sym, _ppvar, 6, 3);
   nrn_update_ion_pointer(_KATP_sym, _ppvar, 7, 3);
   nrn_update_ion_pointer(_HERG_sym, _ppvar, 8, 3);
   nrn_update_ion_pointer(_NaB_sym, _ppvar, 9, 3);
   nrn_update_ion_pointer(_Na_sym, _ppvar, 10, 3);
   nrn_update_ion_pointer(_Vm_sym, _ppvar, 11, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   Vmi = - 62.0 ;
   Cm = 9990.0 ;
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
  iCaP = _ion_iCaP;
  iCaT = _ion_iCaT;
  iKDR = _ion_iKDR;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iBK = _ion_iBK;
  iKATP = _ion_iKATP;
  iHERG = _ion_iHERG;
  iNaB = _ion_iNaB;
  iNa = _ion_iNa;
  Vmi = _ion_Vmi;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_Vmi = Vmi;
  nrn_wrote_conc(_Vm_sym, (&(_ion_Vmi)) - 1, _style_Vm);
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
  iCaP = _ion_iCaP;
  iCaT = _ion_iCaT;
  iKDR = _ion_iKDR;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iBK = _ion_iBK;
  iKATP = _ion_iKATP;
  iHERG = _ion_iHERG;
  iNaB = _ion_iNaB;
  iNa = _ion_iNa;
  Vmi = _ion_Vmi;
 {   states(_p, _ppvar, _thread, _nt);
  } {
   Vreal = Vmi ;
   }
  _ion_Vmi = Vmi;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(Vmi) - _p;  _dlist1[0] = &(DVmi) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/Beta_V.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_V\n"
  "USEION CaL READ iCaL\n"
  "USEION CaP READ iCaP\n"
  "USEION CaT READ iCaT\n"
  "USEION KDR READ iKDR\n"
  "USEION PCa READ iPCa\n"
  "USEION KCa READ iKCa\n"
  "USEION BK READ iBK\n"
  "USEION KATP READ iKATP\n"
  "USEION HERG READ iHERG\n"
  "USEION NaB READ iNaB\n"
  "USEION Na READ iNa\n"
  "USEION Vm WRITE Vmi VALENCE 1\n"
  "RANGE Cm, Vreal\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "Cm\n"
  "Vreal\n"
  "iCaL\n"
  "iCaP\n"
  "iCaT\n"
  "iKDR\n"
  "iPCa\n"
  "iKCa\n"
  "iBK\n"
  "iKATP\n"
  "iHERG\n"
  "iNaB\n"
  "iNa\n"
  "}\n"
  "\n"
  "STATE{\n"
  "Vmi\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "Vmi = -62\n"
  "Cm = 9990\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "Vreal = Vmi\n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "Vmi' =  - ((iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa) / Cm)\n"
  "}\n"
  ;
#endif

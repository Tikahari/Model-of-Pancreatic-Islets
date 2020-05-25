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
 
#define nrn_init _nrn_init__B_CaL
#define _nrn_initial _nrn_initial__B_CaL
#define nrn_cur _nrn_cur__B_CaL
#define _nrn_current _nrn_current__B_CaL
#define nrn_jacob _nrn_jacob__B_CaL
#define nrn_state _nrn_state__B_CaL
#define _net_receive _net_receive__B_CaL 
#define states states__B_CaL 
 
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
#define gmCaL _p[0]
#define kdCaL _p[1]
#define kfCaL _p[2]
#define tf1CaL _p[3]
#define tf2CaL _p[4]
#define VdCaL _p[5]
#define VfCaL _p[6]
#define dCaLi _p[7]
#define fCaLi _p[8]
#define iCaL _p[9]
#define tdCaL _p[10]
#define f1CaL _p[11]
#define f2CaL _p[12]
#define dCaL _p[13]
#define eCa _p[14]
#define Vmi _p[15]
#define Df1CaL _p[16]
#define Df2CaL _p[17]
#define DdCaL _p[18]
#define v _p[19]
#define _g _p[20]
#define _ion_iCaL	*_ppvar[0]._pval
#define _ion_diCaLdv	*_ppvar[1]._pval
#define _ion_eCa	*_ppvar[2]._pval
#define _ion_Vmi	*_ppvar[3]._pval
 
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
 "setdata_B_CaL", _hoc_setdata,
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
 static double dCaL0 = 0;
 static double f2CaL0 = 0;
 static double f1CaL0 = 0;
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
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"B_CaL",
 "gmCaL_B_CaL",
 "kdCaL_B_CaL",
 "kfCaL_B_CaL",
 "tf1CaL_B_CaL",
 "tf2CaL_B_CaL",
 "VdCaL_B_CaL",
 "VfCaL_B_CaL",
 0,
 "dCaLi_B_CaL",
 "fCaLi_B_CaL",
 "iCaL_B_CaL",
 "tdCaL_B_CaL",
 0,
 "f1CaL_B_CaL",
 "f2CaL_B_CaL",
 "dCaL_B_CaL",
 0,
 0};
 static Symbol* _CaL_sym;
 static Symbol* _Ca_sym;
 static Symbol* _Vm_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 21, _prop);
 	/*initialize range parameters*/
 	gmCaL = 0;
 	kdCaL = 0;
 	kfCaL = 0;
 	tf1CaL = 0;
 	tf2CaL = 0;
 	VdCaL = 0;
 	VfCaL = 0;
 	_prop->param = _p;
 	_prop->param_size = 21;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaL */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diCaLdv */
 prop_ion = need_memb(_Ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eCa */
 prop_ion = need_memb(_Vm_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[3]._pval = &prop_ion->param[1]; /* Vmi */
 
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

 void _Beta_CaL_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaL", 2.0);
 	ion_reg("Ca", -10000.);
 	ion_reg("Vm", -10000.);
 	_CaL_sym = hoc_lookup("CaL_ion");
 	_Ca_sym = hoc_lookup("Ca_ion");
 	_Vm_sym = hoc_lookup("Vm_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 21, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "Ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "Vm_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_CaL /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/x86_64/Beta_CaL.mod\n");
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
 static int _slist1[3], _dlist1[3];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   Df1CaL = ( ( fCaLi - f1CaL ) / tf1CaL ) ;
   Df2CaL = ( ( fCaLi - f2CaL ) / tf2CaL ) ;
   DdCaL = ( ( dCaLi - dCaL ) / tdCaL ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 Df1CaL = Df1CaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tf1CaL ) )) ;
 Df2CaL = Df2CaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tf2CaL ) )) ;
 DdCaL = DdCaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaL ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    f1CaL = f1CaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tf1CaL ))))*(- ( ( ( ( fCaLi ) ) / tf1CaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tf1CaL ) ) - f1CaL) ;
    f2CaL = f2CaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tf2CaL ))))*(- ( ( ( ( fCaLi ) ) / tf2CaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tf2CaL ) ) - f2CaL) ;
    dCaL = dCaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaL ))))*(- ( ( ( ( dCaLi ) ) / tdCaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaL ) ) - dCaL) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 3;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eCa = _ion_eCa;
  Vmi = _ion_Vmi;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 3; ++_i) {
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
  eCa = _ion_eCa;
  Vmi = _ion_Vmi;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_Ca_sym, _ppvar, 2, 0);
   nrn_update_ion_pointer(_Vm_sym, _ppvar, 3, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  dCaL = dCaL0;
  f2CaL = f2CaL0;
  f1CaL = f1CaL0;
 {
   dCaL = 0.001 ;
   f1CaL = 0.1 ;
   f2CaL = 0.7 ;
   gmCaL = 2700.0 ;
   kdCaL = 8.0 ;
   kfCaL = 8.0 ;
   tf1CaL = 6.8 ;
   tf2CaL = 65.0 ;
   VdCaL = - 15.0 ;
   VfCaL = - 25.0 ;
   tdCaL = 0.41 ;
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
  eCa = _ion_eCa;
  Vmi = _ion_Vmi;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   tdCaL = ( 2.2 - ( 1.79 * exp ( - ( .00020292043084065876 * ( - 9.7 + v ) * ( - 9.7 + v ) ) ) ) ) ;
   fCaLi = ( 1.0 / ( 1.0 + exp ( ( ( v - VfCaL ) / kfCaL ) ) ) ) ;
   dCaLi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaL - v ) / kdCaL ) ) ) ) ;
   iCaL = ( gmCaL * dCaL * f1CaL * f2CaL * ( v - eCa ) ) ;
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
  eCa = _ion_eCa;
  Vmi = _ion_Vmi;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _diCaL;
  _diCaL = iCaL;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diCaLdv += (_diCaL - iCaL)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iCaL += iCaL ;
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
  eCa = _ion_eCa;
  Vmi = _ion_Vmi;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(f1CaL) - _p;  _dlist1[0] = &(Df1CaL) - _p;
 _slist1[1] = &(f2CaL) - _p;  _dlist1[1] = &(Df2CaL) - _p;
 _slist1[2] = &(dCaL) - _p;  _dlist1[2] = &(DdCaL) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/Beta_CaL.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_CaL\n"
  "USEION CaL WRITE iCaL VALENCE 2\n"
  "USEION Ca READ eCa\n"
  "USEION Vm READ Vmi\n"
  "RANGE dCaL, f1CaL, f2CaL , gmCaL, kdCaL , kfCaL , tf1CaL, tf2CaL, VdCaL, VfCaL, eCa\n"
  "RANGE dCaLi, fCaLi, iCaL, tdCaL\n"
  "}\n"
  "\n"
  "PARAMETER{ \n"
  "gmCaL\n"
  "kdCaL \n"
  "kfCaL \n"
  "tf1CaL\n"
  "tf2CaL\n"
  "VdCaL\n"
  "VfCaL \n"
  "eCa\n"
  "v\n"
  "Vmi\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "dCaLi \n"
  "fCaLi \n"
  "iCaL    \n"
  "tdCaL\n"
  "}\n"
  "\n"
  "STATE{\n"
  "f1CaL\n"
  "f2CaL\n"
  "dCaL\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "dCaL = 0.001\n"
  "f1CaL = 0.1\n"
  "f2CaL = 0.7\n"
  "gmCaL = 2700\n"
  "kdCaL = 8\n"
  "kfCaL = 8\n"
  "tf1CaL = 6.8\n"
  "tf2CaL = 65\n"
  "VdCaL = -15\n"
  "VfCaL = -25\n"
  "tdCaL = 0.41\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + v) * ( - 9.7 + v)))))                \n"
  "fCaLi = (1.0 / (1.0 + exp(((v - VfCaL) / kfCaL))))                \n"
  "dCaLi = (1.0 / (1.0 + exp(((VdCaL - v) / kdCaL))))                \n"
  "iCaL = (gmCaL * dCaL * f1CaL * f2CaL * (v - eCa))    \n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "f1CaL' = ((fCaLi - f1CaL) / tf1CaL)                \n"
  "f2CaL' = ((fCaLi - f2CaL) / tf2CaL) \n"
  "dCaL' = ((dCaLi - dCaL) / tdCaL)    \n"
  "}\n"
  ;
#endif

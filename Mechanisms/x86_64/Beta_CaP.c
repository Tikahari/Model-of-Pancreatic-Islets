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
 
#define nrn_init _nrn_init__B_CaP
#define _nrn_initial _nrn_initial__B_CaP
#define nrn_cur _nrn_cur__B_CaP
#define _nrn_current _nrn_current__B_CaP
#define nrn_jacob _nrn_jacob__B_CaP
#define nrn_state _nrn_state__B_CaP
#define _net_receive _net_receive__B_CaP 
#define states states__B_CaP 
 
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
#define gmCaP _p[0]
#define VfCaP _p[1]
#define VdCaP _p[2]
#define tdCaP _p[3]
#define tfCaP _p[4]
#define kfCaP _p[5]
#define kdCaP _p[6]
#define dCaP _p[7]
#define fCaP _p[8]
#define eCa _p[9]
#define iCaP _p[10]
#define DdCaP _p[11]
#define DfCaP _p[12]
#define v _p[13]
#define _g _p[14]
#define _ion_iCaP	*_ppvar[0]._pval
#define _ion_diCaPdv	*_ppvar[1]._pval
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
 "setdata_B_CaP", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
 static int _thread1data_inuse = 0;
static double _thread1data[2];
#define _gth 0
#define dCaPi_B_CaP _thread1data[0]
#define dCaPi _thread[_gth]._pval[0]
#define fCaPi_B_CaP _thread1data[1]
#define fCaPi _thread[_gth]._pval[1]
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double delta_t = 0.01;
 static double dCaP0 = 0;
 static double fCaP0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "dCaPi_B_CaP", &dCaPi_B_CaP,
 "fCaPi_B_CaP", &fCaPi_B_CaP,
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
"B_CaP",
 "gmCaP_B_CaP",
 "VfCaP_B_CaP",
 "VdCaP_B_CaP",
 "tdCaP_B_CaP",
 "tfCaP_B_CaP",
 "kfCaP_B_CaP",
 "kdCaP_B_CaP",
 0,
 0,
 "dCaP_B_CaP",
 "fCaP_B_CaP",
 0,
 0};
 static Symbol* _CaP_sym;
 static Symbol* _Ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 15, _prop);
 	/*initialize range parameters*/
 	gmCaP = 0;
 	VfCaP = 0;
 	VdCaP = 0;
 	tdCaP = 0;
 	tfCaP = 0;
 	kfCaP = 0;
 	kdCaP = 0;
 	_prop->param = _p;
 	_prop->param_size = 15;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaP_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaP */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diCaPdv */
 prop_ion = need_memb(_Ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eCa */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Beta_CaP_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaP", 2.0);
 	ion_reg("Ca", -10000.);
 	_CaP_sym = hoc_lookup("CaP_ion");
 	_Ca_sym = hoc_lookup("Ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 2);
  _extcall_thread = (Datum*)ecalloc(1, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
  _thread1data_inuse = 0;
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 15, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "CaP_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaP_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "Ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_CaP /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Beta_CaP.mod\n");
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
   DdCaP = ( ( dCaPi - dCaP ) / tdCaP ) ;
   DfCaP = ( ( fCaPi - fCaP ) / tfCaP ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DdCaP = DdCaP  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaP ) )) ;
 DfCaP = DfCaP  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfCaP ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    dCaP = dCaP + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaP ))))*(- ( ( ( ( dCaPi ) ) / tdCaP ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaP ) ) - dCaP) ;
    fCaP = fCaP + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfCaP ))))*(- ( ( ( ( fCaPi ) ) / tfCaP ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfCaP ) ) - fCaP) ;
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
  eCa = _ion_eCa;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
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
  eCa = _ion_eCa;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
  if (_thread1data_inuse) {_thread[_gth]._pval = (double*)ecalloc(2, sizeof(double));
 }else{
 _thread[_gth]._pval = _thread1data; _thread1data_inuse = 1;
 }
 }
 
static void _thread_cleanup(Datum* _thread) {
  if (_thread[_gth]._pval == _thread1data) {
   _thread1data_inuse = 0;
  }else{
   free((void*)_thread[_gth]._pval);
  }
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaP_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaP_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_Ca_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  dCaP = dCaP0;
  fCaP = fCaP0;
 {
   gmCaP = 1200.0 ;
   dCaP = 0.1 ;
   fCaP = 0.1 ;
   VfCaP = - 25.0 ;
   VdCaP = - 5.0 ;
   tdCaP = 0.41 ;
   tfCaP = 65.0 ;
   kfCaP = 8.0 ;
   kdCaP = 6.0 ;
   iCaP = 0.0 ;
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
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   dCaPi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaP - v ) / kdCaP ) ) ) ) ;
   fCaPi = ( 1.0 / ( 1.0 + exp ( ( ( v - VfCaP ) / kfCaP ) ) ) ) ;
   iCaP = ( gmCaP * dCaP * fCaP * ( v - eCa ) ) ;
   }
 _current += iCaP;

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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _diCaP;
  _diCaP = iCaP;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diCaPdv += (_diCaP - iCaP)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iCaP += iCaP ;
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
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(dCaP) - _p;  _dlist1[0] = &(DdCaP) - _p;
 _slist1[1] = &(fCaP) - _p;  _dlist1[1] = &(DfCaP) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/Beta_CaP.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_CaP\n"
  "USEION CaP WRITE iCaP VALENCE 2\n"
  "USEION Ca READ eCa\n"
  ":USEION Vm READ Vmi\n"
  "RANGE gmCaP, dCaP, fCaP, VfCaP, VdCaP, tdCaP, tfCaP, kfCaP, kdCaP, eCa\n"
  "}\n"
  "\n"
  "PARAMETER{ \n"
  "gmCaP\n"
  "VfCaP\n"
  "VdCaP\n"
  "tdCaP\n"
  "tfCaP\n"
  "kfCaP\n"
  "kdCaP\n"
  "eCa\n"
  "v\n"
  "\n"
  "dCaPi\n"
  "fCaPi\n"
  "iCaP    \n"
  "}\n"
  "\n"
  "\n"
  "STATE{\n"
  "dCaP\n"
  "fCaP\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "gmCaP = 1200\n"
  "dCaP = 0.1\n"
  "fCaP = 0.1\n"
  "VfCaP = -25\n"
  "VdCaP = -5\n"
  "tdCaP = 0.41\n"
  "tfCaP = 65\n"
  "kfCaP = 8\n"
  "kdCaP = 6\n"
  "iCaP = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "dCaPi = (1.0 / (1.0 + exp(((VdCaP - v) / kdCaP))))                \n"
  "fCaPi =  (1.0 / (1.0 + exp(((v - VfCaP) / kfCaP))))                \n"
  "iCaP = (gmCaP * dCaP * fCaP * (v - eCa))                \n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "dCaP' = ((dCaPi - dCaP) / tdCaP)                \n"
  "fCaP' = ((fCaPi - fCaP) / tfCaP) \n"
  "}\n"
  ;
#endif

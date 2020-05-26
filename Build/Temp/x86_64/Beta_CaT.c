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
 
#define nrn_init _nrn_init__B_CaT
#define _nrn_initial _nrn_initial__B_CaT
#define nrn_cur _nrn_cur__B_CaT
#define _nrn_current _nrn_current__B_CaT
#define nrn_jacob _nrn_jacob__B_CaT
#define nrn_state _nrn_state__B_CaT
#define _net_receive _net_receive__B_CaT 
#define states states__B_CaT 
 
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
#define gmCaT _p[0]
#define kdCaT _p[1]
#define kfCaT _p[2]
#define tdCaT _p[3]
#define tfCaT _p[4]
#define VdCaT _p[5]
#define VfCaT _p[6]
#define dCaTi _p[7]
#define fCaTi _p[8]
#define iCaT _p[9]
#define dCaT _p[10]
#define fCaT _p[11]
#define eCa _p[12]
#define DdCaT _p[13]
#define DfCaT _p[14]
#define v _p[15]
#define _g _p[16]
#define _ion_iCaT	*_ppvar[0]._pval
#define _ion_diCaTdv	*_ppvar[1]._pval
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
 "setdata_B_CaT", _hoc_setdata,
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
 static double dCaT0 = 0;
 static double fCaT0 = 0;
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
"B_CaT",
 "gmCaT_B_CaT",
 "kdCaT_B_CaT",
 "kfCaT_B_CaT",
 "tdCaT_B_CaT",
 "tfCaT_B_CaT",
 "VdCaT_B_CaT",
 "VfCaT_B_CaT",
 0,
 "dCaTi_B_CaT",
 "fCaTi_B_CaT",
 "iCaT_B_CaT",
 0,
 "dCaT_B_CaT",
 "fCaT_B_CaT",
 0,
 0};
 static Symbol* _CaT_sym;
 static Symbol* _Ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	gmCaT = 0;
 	kdCaT = 0;
 	kfCaT = 0;
 	tdCaT = 0;
 	tfCaT = 0;
 	VdCaT = 0;
 	VfCaT = 0;
 	_prop->param = _p;
 	_prop->param_size = 17;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaT_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaT */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diCaTdv */
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
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Beta_CaT_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaT", 2.0);
 	ion_reg("Ca", -10000.);
 	_CaT_sym = hoc_lookup("CaT_ion");
 	_Ca_sym = hoc_lookup("Ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "CaT_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaT_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "Ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_CaT /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Temp/x86_64/Beta_CaT.mod\n");
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
   DdCaT = ( ( dCaTi - dCaT ) / tdCaT ) ;
   DfCaT = ( ( fCaTi - fCaT ) / tfCaT ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DdCaT = DdCaT  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaT ) )) ;
 DfCaT = DfCaT  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfCaT ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    dCaT = dCaT + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaT ))))*(- ( ( ( ( dCaTi ) ) / tdCaT ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaT ) ) - dCaT) ;
    fCaT = fCaT + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfCaT ))))*(- ( ( ( ( fCaTi ) ) / tfCaT ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfCaT ) ) - fCaT) ;
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
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaT_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaT_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_Ca_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  dCaT = dCaT0;
  fCaT = fCaT0;
 {
   dCaT = 0.1 ;
   fCaT = 0.1 ;
   gmCaT = 250.0 ;
   kdCaT = 6.0 ;
   kfCaT = 8.0 ;
   tdCaT = 0.41 ;
   tfCaT = 6.8 ;
   VdCaT = - 50.0 ;
   VfCaT = - 64.0 ;
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
   dCaTi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaT - v ) / kdCaT ) ) ) ) ;
   fCaTi = ( 1.0 / ( 1.0 + exp ( ( ( v - VfCaT ) / kfCaT ) ) ) ) ;
   iCaT = ( gmCaT * dCaT * fCaT * ( v - eCa ) ) ;
   }
 _current += iCaT;

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
 	{ double _diCaT;
  _diCaT = iCaT;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diCaTdv += (_diCaT - iCaT)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iCaT += iCaT ;
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
 _slist1[0] = &(dCaT) - _p;  _dlist1[0] = &(DdCaT) - _p;
 _slist1[1] = &(fCaT) - _p;  _dlist1[1] = &(DfCaT) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Temp/Beta_CaT.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_CaT\n"
  "USEION CaT WRITE iCaT VALENCE 2\n"
  "USEION Ca READ eCa\n"
  ":USEION Vm READ Vmi\n"
  "RANGE gmCaT, kdCaT, kfCaT, tdCaT, tfCaT, VdCaT, VfCaT\n"
  "RANGE dCaTi, fCaTi, iCaT \n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "gmCaT \n"
  "kdCaT \n"
  "kfCaT \n"
  "tdCaT \n"
  "tfCaT \n"
  "VdCaT\n"
  "VfCaT \n"
  ":Vmi\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "dCaTi\n"
  "fCaTi \n"
  "iCaT \n"
  "eCa\n"
  "v\n"
  "}\n"
  "\n"
  "STATE{\n"
  "dCaT                \n"
  "fCaT \n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "dCaT = 0.1\n"
  "fCaT = 0.1\n"
  "gmCaT = 250\n"
  "kdCaT = 6\n"
  "kfCaT = 8\n"
  "tdCaT = 0.41\n"
  "tfCaT = 6.8\n"
  "VdCaT = -50\n"
  "VfCaT = -64\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "dCaTi = (1.0 / (1.0 + exp(((VdCaT - v) / kdCaT)))) \n"
  "fCaTi = (1.0 / (1.0 + exp(((v - VfCaT) / kfCaT))))                \n"
  "iCaT = (gmCaT * dCaT * fCaT * (v - eCa))                \n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "dCaT' = ((dCaTi - dCaT) / tdCaT)                \n"
  "fCaT' = ((fCaTi - fCaT) / tfCaT)                \n"
  "}\n"
  ;
#endif

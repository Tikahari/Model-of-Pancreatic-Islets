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
 
#define nrn_init _nrn_init__B_BK
#define _nrn_initial _nrn_initial__B_BK
#define nrn_cur _nrn_cur__B_BK
#define _nrn_current _nrn_current__B_BK
#define nrn_jacob _nrn_jacob__B_BK
#define nrn_state _nrn_state__B_BK
#define _net_receive _net_receive__B_BK 
#define states states__B_BK 
 
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
#define hdk _p[0]
#define gmKCaB _p[1]
#define kCaBK _p[2]
#define kdKCaB _p[3]
#define kfKCaB _p[4]
#define tdKCaB _p[5]
#define tfKCaB _p[6]
#define VfKCaB _p[7]
#define VBKo _p[8]
#define kshift _p[9]
#define dKCaBi _p[10]
#define fKCaBi _p[11]
#define VdKCaB _p[12]
#define iBK _p[13]
#define dKCaB _p[14]
#define fKCaB _p[15]
#define eK _p[16]
#define Caci _p[17]
#define eCac _p[18]
#define DdKCaB _p[19]
#define DfKCaB _p[20]
#define v _p[21]
#define _g _p[22]
#define _ion_iBK	*_ppvar[0]._pval
#define _ion_diBKdv	*_ppvar[1]._pval
#define _ion_eK	*_ppvar[2]._pval
#define _ion_Caci	*_ppvar[3]._pval
#define _ion_eCac	*_ppvar[4]._pval
 
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
 "setdata_B_BK", _hoc_setdata,
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
 static double dKCaB0 = 0;
 static double fKCaB0 = 0;
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"B_BK",
 "hdk_B_BK",
 "gmKCaB_B_BK",
 "kCaBK_B_BK",
 "kdKCaB_B_BK",
 "kfKCaB_B_BK",
 "tdKCaB_B_BK",
 "tfKCaB_B_BK",
 "VfKCaB_B_BK",
 "VBKo_B_BK",
 "kshift_B_BK",
 "dKCaBi_B_BK",
 "fKCaBi_B_BK",
 "VdKCaB_B_BK",
 "iBK_B_BK",
 0,
 0,
 "dKCaB_B_BK",
 "fKCaB_B_BK",
 0,
 0};
 static Symbol* _BK_sym;
 static Symbol* _K_sym;
 static Symbol* _Cac_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 23, _prop);
 	/*initialize range parameters*/
 	hdk = 0;
 	gmKCaB = 0;
 	kCaBK = 0;
 	kdKCaB = 0;
 	kfKCaB = 0;
 	tdKCaB = 0;
 	tfKCaB = 0;
 	VfKCaB = 0;
 	VBKo = 0;
 	kshift = 0;
 	dKCaBi = 0;
 	fKCaBi = 0;
 	VdKCaB = 0;
 	iBK = 0;
 	_prop->param = _p;
 	_prop->param_size = 23;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_BK_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iBK */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diBKdv */
 prop_ion = need_memb(_K_sym);
 nrn_promote(prop_ion, 0, 3);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eK */
 prop_ion = need_memb(_Cac_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[3]._pval = &prop_ion->param[1]; /* Caci */
 	_ppvar[4]._pval = &prop_ion->param[0]; /* eCac */
 
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

 void _Beta_BK_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("BK", 1.0);
 	ion_reg("K", 1.0);
 	ion_reg("Cac", -10000.);
 	_BK_sym = hoc_lookup("BK_ion");
 	_K_sym = hoc_lookup("K_ion");
 	_Cac_sym = hoc_lookup("Cac_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 23, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "BK_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "BK_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "K_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "Cac_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "Cac_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_BK /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/x86_64/Beta_BK.mod\n");
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
   DdKCaB = ( ( dKCaBi - dKCaB ) / tdKCaB ) ;
   DfKCaB = ( ( fKCaBi - fKCaB ) / tfKCaB ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DdKCaB = DdKCaB  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdKCaB ) )) ;
 DfKCaB = DfKCaB  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfKCaB ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    dKCaB = dKCaB + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdKCaB ))))*(- ( ( ( ( dKCaBi ) ) / tdKCaB ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdKCaB ) ) - dKCaB) ;
    fKCaB = fKCaB + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfKCaB ))))*(- ( ( ( ( fKCaBi ) ) / tfKCaB ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfKCaB ) ) - fKCaB) ;
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
  Caci = _ion_Caci;
  eCac = _ion_eCac;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
   _ion_eK = eK;
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
  Caci = _ion_Caci;
  eCac = _ion_eCac;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_BK_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_BK_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_K_sym, _ppvar, 2, 0);
   nrn_update_ion_pointer(_Cac_sym, _ppvar, 3, 1);
   nrn_update_ion_pointer(_Cac_sym, _ppvar, 4, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  dKCaB = dKCaB0;
  fKCaB = fKCaB0;
 {
   dKCaB = 0.1 ;
   hdk = 2.0 ;
   gmKCaB = 25000.0 ;
   kCaBK = 1.5 ;
   kdKCaB = 30.0 ;
   kfKCaB = 9.2 ;
   fKCaB = 0.1 ;
   tdKCaB = 1.9 ;
   tfKCaB = 22.6 ;
   VfKCaB = 30.0 ;
   VBKo = 0.1 ;
   eK = - 75.0 ;
   kshift = 18.0 ;
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
  Caci = _ion_Caci;
  eCac = _ion_eCac;
 initmodel(_p, _ppvar, _thread, _nt);
   _ion_eK = eK;
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   VdKCaB = ( VBKo - ( kshift * log ( ( Caci / kCaBK ) ) ) ) ;
   fKCaBi = ( 1.0 / ( 1.0 + exp ( - ( ( VfKCaB - v ) / kfKCaB ) ) ) ) ;
   dKCaBi = ( 1.0 / ( 1.0 + exp ( ( ( VdKCaB - v ) / kdKCaB ) ) ) ) ;
   iBK = ( gmKCaB * pow ( dKCaB , hdk ) * fKCaB * ( v - eK ) ) ;
   }
 _current += iBK;

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
  Caci = _ion_Caci;
  eCac = _ion_eCac;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _diBK;
  _diBK = iBK;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diBKdv += (_diBK - iBK)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iBK += iBK ;
  _ion_eK = eK;
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
  Caci = _ion_Caci;
  eCac = _ion_eCac;
 {   states(_p, _ppvar, _thread, _nt);
  }   _ion_eK = eK;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(dKCaB) - _p;  _dlist1[0] = &(DdKCaB) - _p;
 _slist1[1] = &(fKCaB) - _p;  _dlist1[1] = &(DfKCaB) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/Beta_BK.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_BK\n"
  "USEION BK WRITE iBK VALENCE 1\n"
  "USEION K WRITE eK VALENCE 1\n"
  "USEION Cac READ Caci, eCac\n"
  ":USEION Vm READ Vmi\n"
  "\n"
  "RANGE hdk, gmKCaB, kCaBK, kdKCaB, kfKCaB, tdKCaB, tfKCaB, VfKCaB, VBKo, eK, kshift\n"
  "RANGE dKCaBi, fKCaBi, VdKCaB, iBK\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "v\n"
  "hdk\n"
  "gmKCaB\n"
  "kCaBK    \n"
  "kdKCaB  \n"
  "kfKCaB \n"
  "tdKCaB\n"
  "tfKCaB \n"
  "VfKCaB \n"
  "VBKo \n"
  "eK\n"
  "kshift\n"
  "Caci\n"
  "eCac\n"
  "\n"
  "dKCaBi\n"
  "fKCaBi \n"
  "VdKCaB \n"
  "iBK\n"
  "}\n"
  "\n"
  "STATE{\n"
  "dKCaB\n"
  "fKCaB\n"
  "}\n"
  "\n"
  "\n"
  "INITIAL{\n"
  "dKCaB = 0.1\n"
  "hdk = 2\n"
  "gmKCaB = 25000\n"
  "kCaBK = 1.5\n"
  "kdKCaB = 30\n"
  "kfKCaB = 9.2\n"
  "fKCaB = 0.1\n"
  "tdKCaB = 1.9\n"
  "tfKCaB = 22.6\n"
  "VfKCaB = 30\n"
  "VBKo = 0.1\n"
  "eK = -75\n"
  "kshift = 18\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "VdKCaB =   (VBKo - (kshift * log((Caci / kCaBK)))) \n"
  "fKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - v) / kfKCaB))))                \n"
  "dKCaBi = (1.0 / (1.0 + exp(((VdKCaB - v) / kdKCaB)))) \n"
  "iBK =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (v - eK))                          \n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "dKCaB' = ((dKCaBi - dKCaB) / tdKCaB)                \n"
  "fKCaB' = ((fKCaBi - fKCaB) / tfKCaB) \n"
  "}\n"
  ;
#endif

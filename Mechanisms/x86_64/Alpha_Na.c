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
 
#define nrn_init _nrn_init__A_Na
#define _nrn_initial _nrn_initial__A_Na
#define nrn_cur _nrn_cur__A_Na
#define _nrn_current _nrn_current__A_Na
#define nrn_jacob _nrn_jacob__A_Na
#define nrn_state _nrn_state__A_Na
#define _net_receive _net_receive__A_Na 
#define states states__A_Na 
 
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
#define gNa _p[0]
#define mNa_inf _p[1]
#define hNa_inf _p[2]
#define tau_mNa _p[3]
#define tau_hNa _p[4]
#define iNa _p[5]
#define mNa _p[6]
#define hNa _p[7]
#define eNa _p[8]
#define DeNa _p[9]
#define DiNa _p[10]
#define DmNa _p[11]
#define DhNa _p[12]
#define v _p[13]
#define _g _p[14]
#define _ion_iNa	*_ppvar[0]._pval
#define _ion_diNadv	*_ppvar[1]._pval
#define _ion_eNa	*_ppvar[2]._pval
 
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
 "setdata_A_Na", _hoc_setdata,
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
 static double eNa0 = 0;
 static double hNa0 = 0;
 static double iNa0 = 0;
 static double mNa0 = 0;
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
"A_Na",
 "gNa_A_Na",
 0,
 "mNa_inf_A_Na",
 "hNa_inf_A_Na",
 "tau_mNa_A_Na",
 "tau_hNa_A_Na",
 0,
 "iNa_A_Na",
 "mNa_A_Na",
 "hNa_A_Na",
 0,
 0};
 static Symbol* _Na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 15, _prop);
 	/*initialize range parameters*/
 	gNa = 0;
 	_prop->param = _p;
 	_prop->param_size = 15;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_Na_sym);
 nrn_promote(prop_ion, 0, 3);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iNa */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diNadv */
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eNa */
 
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

 void _Alpha_Na_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("Na", 1.0);
 	_Na_sym = hoc_lookup("Na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 15, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "Na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "Na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "Na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 A_Na /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Alpha_Na.mod\n");
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
   DmNa = ( mNa_inf - mNa ) / tau_mNa ;
   DhNa = ( hNa_inf - hNa ) / tau_hNa ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DmNa = DmNa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_mNa )) ;
 DhNa = DhNa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_hNa )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    mNa = mNa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_mNa)))*(- ( ( ( mNa_inf ) ) / tau_mNa ) / ( ( ( ( - 1.0 ) ) ) / tau_mNa ) - mNa) ;
    hNa = hNa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_hNa)))*(- ( ( ( hNa_inf ) ) / tau_hNa ) / ( ( ( ( - 1.0 ) ) ) / tau_hNa ) - hNa) ;
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
   _ion_eNa = eNa;
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
   nrn_update_ion_pointer(_Na_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_Na_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_Na_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  eNa = eNa0;
  hNa = hNa0;
  iNa = iNa0;
  mNa = mNa0;
 {
   eNa = 70.0 ;
   gNa = 11.0 ;
   mNa = 0.007938786735335676 ;
   hNa = 0.2498175179717122 ;
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
   _ion_eNa = eNa;
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   mNa_inf = 1.0 / ( 1.0 + exp ( ( - ( v + 30.0 ) ) / 4.0 ) ) ;
   hNa_inf = 1.0 / ( 1.0 + exp ( ( - ( v + 52.0 ) ) / ( - 8.0 ) ) ) ;
   tau_mNa = ( 6.0 / ( exp ( ( - ( v + 50.0 ) ) / 10.0 ) + exp ( ( v + 50.0 ) / 10.0 ) ) ) + 0.05 ;
   tau_hNa = ( 120.0 / ( exp ( ( - ( v + 50.0 ) ) / 8.0 ) + exp ( ( v + 50.0 ) / 8.0 ) ) ) + 0.5 ;
   iNa = gNa * pow ( mNa , 3.0 ) * hNa * ( v - eNa ) ;
   }
 _current += iNa;

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
 	{ double _diNa;
  _diNa = iNa;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diNadv += (_diNa - iNa)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iNa += iNa ;
  _ion_eNa = eNa;
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
  }   _ion_eNa = eNa;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mNa) - _p;  _dlist1[0] = &(DmNa) - _p;
 _slist1[1] = &(hNa) - _p;  _dlist1[1] = &(DhNa) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/Alpha_Na.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX A_Na\n"
  "USEION Na WRITE iNa, eNa VALENCE 1\n"
  "RANGE mNa_inf, hNa_inf, tau_mNa, tau_hNa\n"
  "RANGE gNa\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "gNa\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "mNa_inf\n"
  "hNa_inf\n"
  "tau_mNa\n"
  "tau_hNa\n"
  "v\n"
  "}\n"
  "\n"
  "STATE{\n"
  "eNa\n"
  "iNa\n"
  "mNa\n"
  "hNa\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "eNa = 70\n"
  "gNa = 11\n"
  "mNa = 0.007938786735335676\n"
  "hNa = 0.2498175179717122\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "mNa_inf = 1/(1 + exp((-(v + 30))/4))\n"
  "hNa_inf = 1/(1 + exp((-(v + 52))/(-8)))\n"
  "tau_mNa = (6/(exp((-(v + 50))/10) + exp((v + 50)/10))) + 0.05\n"
  "tau_hNa = (120/(exp((-(v + 50))/8) + exp((v + 50)/8))) + 0.5\n"
  "SOLVE states METHOD cnexp\n"
  "iNa = gNa * pow(mNa,3) * hNa*(v - eNa)\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "mNa' = (mNa_inf - mNa)/tau_mNa\n"
  "hNa' = (hNa_inf - hNa)/tau_hNa\n"
  "}\n"
  ;
#endif

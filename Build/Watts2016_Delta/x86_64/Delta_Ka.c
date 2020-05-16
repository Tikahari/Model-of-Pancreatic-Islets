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
 
#define nrn_init _nrn_init__D_Ka
#define _nrn_initial _nrn_initial__D_Ka
#define nrn_cur _nrn_cur__D_Ka
#define _nrn_current _nrn_current__D_Ka
#define nrn_jacob _nrn_jacob__D_Ka
#define nrn_state _nrn_state__D_Ka
#define _net_receive _net_receive__D_Ka 
#define states states__D_Ka 
 
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
#define gKa _p[0]
#define vKam _p[1]
#define sKam _p[2]
#define vKah _p[3]
#define sKah _p[4]
#define tauKam _p[5]
#define tKah1 _p[6]
#define tKah2 _p[7]
#define mKa_inf _p[8]
#define hKa_inf _p[9]
#define tauKah _p[10]
#define iKa _p[11]
#define mKa _p[12]
#define hKa _p[13]
#define eK _p[14]
#define DmKa _p[15]
#define DhKa _p[16]
#define v _p[17]
#define _g _p[18]
#define _ion_iKa	*_ppvar[0]._pval
#define _ion_diKadv	*_ppvar[1]._pval
#define _ion_eK	*_ppvar[2]._pval
 
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
 "setdata_D_Ka", _hoc_setdata,
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
 static double hKa0 = 0;
 static double mKa0 = 0;
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
"D_Ka",
 "gKa_D_Ka",
 "vKam_D_Ka",
 "sKam_D_Ka",
 "vKah_D_Ka",
 "sKah_D_Ka",
 "tauKam_D_Ka",
 "tKah1_D_Ka",
 "tKah2_D_Ka",
 0,
 "mKa_inf_D_Ka",
 "hKa_inf_D_Ka",
 "tauKah_D_Ka",
 "iKa_D_Ka",
 0,
 "mKa_D_Ka",
 "hKa_D_Ka",
 0,
 0};
 static Symbol* _Ka_sym;
 static Symbol* _K_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 19, _prop);
 	/*initialize range parameters*/
 	gKa = 0;
 	vKam = 0;
 	sKam = 0;
 	vKah = 0;
 	sKah = 0;
 	tauKam = 0;
 	tKah1 = 0;
 	tKah2 = 0;
 	_prop->param = _p;
 	_prop->param_size = 19;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_Ka_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iKa */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diKadv */
 prop_ion = need_memb(_K_sym);
 nrn_promote(prop_ion, 0, 3);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eK */
 
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

 void _Delta_Ka_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("Ka", 1.0);
 	ion_reg("K", 1.0);
 	_Ka_sym = hoc_lookup("Ka_ion");
 	_K_sym = hoc_lookup("K_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 19, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "Ka_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "Ka_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "K_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 D_Ka /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Watts2016_Delta/x86_64/Delta_Ka.mod\n");
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
   DmKa = ( mKa_inf - mKa ) / tauKam ;
   DhKa = ( hKa_inf - hKa ) / tauKah ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DmKa = DmKa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauKam )) ;
 DhKa = DhKa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauKah )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    mKa = mKa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauKam)))*(- ( ( ( mKa_inf ) ) / tauKam ) / ( ( ( ( - 1.0 ) ) ) / tauKam ) - mKa) ;
    hKa = hKa + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauKah)))*(- ( ( ( hKa_inf ) ) / tauKah ) / ( ( ( ( - 1.0 ) ) ) / tauKah ) - hKa) ;
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
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_Ka_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_Ka_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_K_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  hKa = hKa0;
  mKa = mKa0;
 {
   eK = - 75.0 ;
   gKa = 0.5 ;
   vKam = - 45.0 ;
   sKam = 10.0 ;
   vKah = - 68.0 ;
   sKah = - 10.0 ;
   tauKam = 0.1 ;
   tKah1 = 60.0 ;
   tKah2 = 5.0 ;
   mKa = 0.9480884005315277 ;
   hKa = 0.02771925786328598 ;
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
   _ion_eK = eK;
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   mKa_inf = 1.0 / ( 1.0 + exp ( - ( v - vKam ) / sKam ) ) ;
   hKa_inf = 1.0 / ( 1.0 + exp ( - ( v - vKah ) / sKah ) ) ;
   tauKah = ( tKah1 / ( exp ( - ( v - 5.0 ) / 20.0 ) + exp ( ( v - 5.0 ) / 20.0 ) ) ) + tKah2 ;
   iKa = gKa * mKa * hKa * ( v - eK ) ;
   }
 _current += iKa;

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
 	{ double _diKa;
  _diKa = iKa;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diKadv += (_diKa - iKa)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iKa += iKa ;
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
 {   states(_p, _ppvar, _thread, _nt);
  }   _ion_eK = eK;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mKa) - _p;  _dlist1[0] = &(DmKa) - _p;
 _slist1[1] = &(hKa) - _p;  _dlist1[1] = &(DhKa) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Watts2016_Delta/Delta_Ka.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX D_Ka\n"
  "USEION Ka WRITE iKa VALENCE 1\n"
  "USEION K WRITE eK VALENCE 1\n"
  "RANGE gKa, vKam, sKam, vKah, sKah, tauKam, tKah1, tKah2 \n"
  "RANGE mKa_inf, hKa_inf, tauKah, iKa\n"
  "}\n"
  "\n"
  "PARAMETER{   \n"
  "gKa \n"
  "vKam \n"
  "sKam \n"
  "vKah \n"
  "sKah \n"
  "tauKam \n"
  "tKah1 \n"
  "tKah2 \n"
  "eK\n"
  "v : This is the voltage when I run h.initial.....\n"
  "\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "mKa_inf\n"
  "hKa_inf\n"
  "tauKah\n"
  "iKa\n"
  "}\n"
  "\n"
  "STATE{\n"
  "mKa\n"
  "hKa\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "eK = -75\n"
  "gKa = 0.5\n"
  "vKam = -45\n"
  "sKam = 10\n"
  "vKah = -68\n"
  "sKah = -10\n"
  "tauKam = 0.1\n"
  "tKah1 = 60\n"
  "tKah2 = 5\n"
  "mKa = 0.9480884005315277 \n"
  "hKa = 0.02771925786328598\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "mKa_inf = 1/(1 + exp(-(v - vKam)/sKam))\n"
  "hKa_inf = 1/(1 + exp(-(v - vKah)/sKah))\n"
  "tauKah = (tKah1/(exp(-(v - 5)/20) + exp((v - 5)/20))) + tKah2\n"
  "SOLVE states METHOD cnexp : Put current equation below this\n"
  "iKa = gKa * mKa * hKa * (v - eK)\n"
  "\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "mKa' = (mKa_inf - mKa)/tauKam\n"
  "hKa' = (hKa_inf - hKa)/tauKah\n"
  "}\n"
  "\n"
  ;
#endif

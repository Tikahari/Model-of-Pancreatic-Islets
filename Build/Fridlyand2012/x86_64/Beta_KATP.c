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
 
#define nrn_init _nrn_init__KATP
#define _nrn_initial _nrn_initial__KATP
#define nrn_cur _nrn_cur__KATP
#define _nrn_current _nrn_current__KATP
#define nrn_jacob _nrn_jacob__KATP
#define nrn_state _nrn_state__KATP
#define _net_receive _net_receive__KATP 
 
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
#define gmKATP _p[0]
#define ATP _p[1]
#define EK _p[2]
#define ADPf _p[3]
#define kdd _p[4]
#define ktt _p[5]
#define ktd _p[6]
#define iKATP _p[7]
#define MgADP _p[8]
#define OKATP _p[9]
#define v _p[10]
#define _g _p[11]
#define _ion_iKATP	*_ppvar[0]._pval
#define _ion_diKATPdv	*_ppvar[1]._pval
 
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
 "setdata_KATP", _hoc_setdata,
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"KATP",
 "gmKATP_KATP",
 "ATP_KATP",
 "EK_KATP",
 "ADPf_KATP",
 "kdd_KATP",
 "ktt_KATP",
 "ktd_KATP",
 0,
 "iKATP_KATP",
 "MgADP_KATP",
 "OKATP_KATP",
 0,
 0,
 0};
 static Symbol* _KATP_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	gmKATP = 0;
 	ATP = 0;
 	EK = 0;
 	ADPf = 0;
 	kdd = 0;
 	ktt = 0;
 	ktd = 0;
 	_prop->param = _p;
 	_prop->param_size = 12;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_KATP_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iKATP */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diKATPdv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Beta_KATP_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("KATP", 1.0);
 	_KATP_sym = hoc_lookup("KATP_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 12, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "KATP_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "KATP_ion");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 KATP /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/x86_64/Beta_KATP.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_KATP_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_KATP_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   gmKATP = 65000.0 ;
   ATP = 3600.0 ;
   EK = - 75.0 ;
   ADPf = 15.0 ;
   kdd = 17.0 ;
   ktt = 50.0 ;
   ktd = 26.0 ;
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
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   iKATP = ( gmKATP * OKATP * ( v - EK ) ) ;
   MgADP = ( 0.55 * ADPf ) ;
   OKATP = ( ( ( 0.08 * ( 1.0 + ( 2.0 * MgADP / kdd ) ) ) + ( 0.89 * MgADP * MgADP / kdd / kdd ) ) / ( ( 1.0 + ( MgADP / kdd ) ) * ( 1.0 + ( MgADP / kdd ) ) * ( 1.0 + ( 0.45 * MgADP / ktd ) + ( ATP / ktt ) ) ) ) ;
   }
 _current += iKATP;

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
 	{ double _diKATP;
  _diKATP = iKATP;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_diKATPdv += (_diKATP - iKATP)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iKATP += iKATP ;
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

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Fridlyand2012/Beta_KATP.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX KATP\n"
  "USEION KATP WRITE iKATP VALENCE 1\n"
  "RANGE gmKATP, ATP, EK, ADPf, kdd, ktt, ktd\n"
  "RANGE iKATP, MgADP, OKATP\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "gmKATP   \n"
  "ATP\n"
  "EK\n"
  "ADPf\n"
  "kdd\n"
  "ktt\n"
  "ktd\n"
  "v\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "iKATP \n"
  "MgADP             \n"
  "OKATP \n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "gmKATP = 65000\n"
  "ATP = 3600\n"
  "EK = -75\n"
  "ADPf = 15.0\n"
  "kdd = 17\n"
  "ktt = 50\n"
  "ktd = 26\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "iKATP =  (gmKATP * OKATP * (v - EK))                \n"
  "MgADP =  (0.55 * ADPf)                \n"
  "OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))                \n"
  "}\n"
  ;
#endif

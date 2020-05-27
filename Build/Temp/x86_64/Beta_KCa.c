/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
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
 
#define nrn_init _nrn_init__B_KCa
#define _nrn_initial _nrn_initial__B_KCa
#define nrn_cur _nrn_cur__B_KCa
#define _nrn_current _nrn_current__B_KCa
#define nrn_jacob _nrn_jacob__B_KCa
#define nrn_state _nrn_state__B_KCa
#define _net_receive _net_receive__B_KCa 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gmKCa _p[0]
#define KKCa _p[1]
#define dKCa _p[2]
#define iKCa _p[3]
#define eK _p[4]
#define _g _p[5]
#define _ion_iKCa	*_ppvar[0]._pval
#define _ion_diKCadv	*_ppvar[1]._pval
#define Cac	*_ppvar[2]._pval
#define _p_Cac	_ppvar[2]._pval
 
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
 static int hoc_nrnpointerindex =  2;
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
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_B_KCa", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define Caci Caci_B_KCa
 double Caci = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Caci_B_KCa", &Caci_B_KCa,
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
"B_KCa",
 "gmKCa_B_KCa",
 "KKCa_B_KCa",
 0,
 "dKCa_B_KCa",
 "iKCa_B_KCa",
 0,
 0,
 "Cac_B_KCa",
 0};
 static Symbol* _KCa_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 6, _prop);
 	/*initialize range parameters*/
 	gmKCa = 0;
 	KKCa = 0;
 	_prop->param = _p;
 	_prop->param_size = 6;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_KCa_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iKCa */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diKCadv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Beta_KCa_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("KCa", 1.0);
 	_KCa_sym = hoc_lookup("KCa_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 6, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "KCa_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "KCa_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_KCa /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Temp/x86_64/Beta_KCa.mod\n");
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
   nrn_update_ion_pointer(_KCa_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_KCa_sym, _ppvar, 1, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
{
 {
   gmKCa = 150.0 ;
   KKCa = 0.2 ;
   dKCa = 0.1 ;
   eK = - 75.0 ;
   }

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   dKCa = ( pow ( Cac , 4.0 ) / ( pow ( KKCa , 4.0 ) + pow ( Cac , 4.0 ) ) ) ;
   iKCa = ( gmKCa * dKCa * ( v - eK ) ) ;
   }
 _current += iKCa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 _g = _nrn_current(_v + .001);
 	{ double _diKCa;
  _diKCa = iKCa;
 _rhs = _nrn_current(_v);
  _ion_diKCadv += (_diKCa - iKCa)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iKCa += iKCa ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Temp/Beta_KCa.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_KCa\n"
  "USEION KCa WRITE iKCa VALENCE 1\n"
  ":USEION Cac READ Caci\n"
  "POINTER Cac\n"
  ":USEION K READ eK\n"
  ":USEION Vm READ Vmi\n"
  "RANGE gmKCa, KKCa\n"
  "RANGE dKCa, iKCa\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "gmKCa\n"
  "KKCa\n"
  "Caci\n"
  "Cac\n"
  ":Vmi\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "dKCa\n"
  "iKCa\n"
  "v\n"
  "eK\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "gmKCa = 150\n"
  "KKCa = 0.2\n"
  "dKCa = 0.1\n"
  "eK = -75\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))                \n"
  "iKCa =  (gmKCa * dKCa * (v - eK))                \n"
  "}\n"
  ;
#endif

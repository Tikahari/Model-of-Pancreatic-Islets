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
 
#define nrn_init _nrn_init__B_Ins
#define _nrn_initial _nrn_initial__B_Ins
#define nrn_cur _nrn_cur__B_Ins
#define _nrn_current _nrn_current__B_Ins
#define nrn_jacob _nrn_jacob__B_Ins
#define nrn_state _nrn_state__B_Ins
#define _net_receive _net_receive__B_Ins 
#define states states__B_Ins 
 
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
#define Vpi _p[0]
#define kpi _p[1]
#define Ni _p[2]
#define kci _p[3]
#define KiCa _p[4]
#define kre _p[5]
#define ksi _p[6]
#define fsi _p[7]
#define IS _p[8]
#define fiCa _p[9]
#define In _p[10]
#define iCaP _p[11]
#define DIn _p[12]
#define _g _p[13]
#define _ion_iCaP	*_ppvar[0]._pval
#define Cac	*_ppvar[1]._pval
#define _p_Cac	_ppvar[1]._pval
 
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
 static int hoc_nrnpointerindex =  1;
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
 "setdata_B_Ins", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define Caci Caci_B_Ins
 double Caci = 0;
#define F_ins F_ins_B_Ins
 double F_ins = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double In0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "F_ins_B_Ins", &F_ins_B_Ins,
 "Caci_B_Ins", &Caci_B_Ins,
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
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"B_Ins",
 "Vpi_B_Ins",
 "kpi_B_Ins",
 "Ni_B_Ins",
 "kci_B_Ins",
 "KiCa_B_Ins",
 "kre_B_Ins",
 "ksi_B_Ins",
 0,
 "fsi_B_Ins",
 "IS_B_Ins",
 "fiCa_B_Ins",
 0,
 "In_B_Ins",
 0,
 "Cac_B_Ins",
 0};
 static Symbol* _CaP_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	Vpi = 0;
 	kpi = 0;
 	Ni = 0;
 	kci = 0;
 	KiCa = 0;
 	kre = 0;
 	ksi = 0;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaP_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaP */
 
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

 void _Beta_Ins_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("CaP", -10000.);
 	_CaP_sym = hoc_lookup("CaP_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 14, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "CaP_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "pointer");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_Ins /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Fridlyand2012/x86_64/Beta_Ins.mod\n");
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
 static int _ode_spec1 () {_reset=0;
 {
   DIn = ( ( fsi * Ni / Vpi ) - ( kpi * In ) ) ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 DIn = DIn  / (1. - dt*( ( ( - ( ( kpi )*( 1.0 ) ) ) ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
    In = In + (1. - exp(dt*(( ( - ( ( kpi )*( 1.0 ) ) ) ))))*(- ( ( ( ( ( fsi )*( Ni ) ) / Vpi ) ) ) / ( ( ( - ( ( kpi )*( 1.0 ) ) ) ) ) - In) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  iCaP = _ion_iCaP;
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  iCaP = _ion_iCaP;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaP_sym, _ppvar, 0, 3);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  In = In0;
 {
   Vpi = 45000.0 ;
   kpi = 0.0001 ;
   Ni = 600.0 ;
   In = 1.0 ;
   kci = 2.0 ;
   KiCa = 0.2 ;
   kre = 0.00073 ;
   ksi = 10000.0 ;
   F_ins = 96480.0 ;
   }
  _sav_indep = t; t = _save;

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
  iCaP = _ion_iCaP;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
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
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  iCaP = _ion_iCaP;
 { error =  states();
 if(error){fprintf(stderr,"at line 50 in file Beta_Ins.mod:\nSOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } {
   fiCa = ( Cac * Cac / ( ( KiCa * KiCa ) + ( Cac * Cac ) ) ) ;
   fsi = ( - ( kci * fiCa * iCaP / F_ins ) + kre ) ;
   IS = ( kpi * ksi * In ) ;
   }
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(In) - _p;  _dlist1[0] = &(DIn) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Build/Fridlyand2012/Beta_Ins.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_Ins\n"
  ":USEION Cac READ Caci\n"
  "POINTER Cac\n"
  "USEION CaP READ iCaP\n"
  "RANGE Vpi, kpi, Ni, In, kci, KiCa, kre, ksi\n"
  "RANGE fsi, IS, fiCa\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "Vpi\n"
  "kpi\n"
  "Ni\n"
  "F_ins\n"
  "kci\n"
  "KiCa\n"
  "kre\n"
  "ksi\n"
  "Caci\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "fsi\n"
  "IS\n"
  "fiCa\n"
  "Cac\n"
  "iCaP\n"
  "}\n"
  "\n"
  "STATE{\n"
  "In\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "Vpi = 45000\n"
  "kpi = 0.0001\n"
  "Ni = 600\n"
  "In = 1.0\n"
  "kci = 2\n"
  "KiCa = 0.2\n"
  "kre = 0.00073\n"
  "ksi = 10000\n"
  "F_ins = 96480\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "fiCa =  (Cac * Cac / ((KiCa * KiCa) + (Cac * Cac)))                \n"
  "fsi = ( - (kci * fiCa * iCaP / F_ins) + kre)                \n"
  "IS =  (kpi * ksi * In) \n"
  "SOLVE states METHOD cnexp\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "In' = ((fsi * Ni / Vpi) - (kpi * In)) \n"
  "}\n"
  ;
#endif

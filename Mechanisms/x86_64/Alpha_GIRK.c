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
 
#define nrn_init _nrn_init__A_GIRK
#define _nrn_initial _nrn_initial__A_GIRK
#define nrn_cur _nrn_cur__A_GIRK
#define _nrn_current _nrn_current__A_GIRK
#define nrn_jacob _nrn_jacob__A_GIRK
#define nrn_state _nrn_state__A_GIRK
#define _net_receive _net_receive__A_GIRK 
 
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
#define knockoutda _p[0]
#define gGIRKko _p[1]
#define sombara2 _p[2]
#define ssom2 _p[3]
#define gGIRKbar _p[4]
#define gGIRK _p[5]
#define EffS _p[6]
#define iGIRK _p[7]
#define DiGIRK _p[8]
#define eGIRK _p[9]
#define DeGIRK _p[10]
#define _g _p[11]
#define _ion_iGIRK	*_ppvar[0]._pval
#define _ion_diGIRKdv	*_ppvar[1]._pval
#define _ion_eGIRK	*_ppvar[2]._pval
#define Sst	*_ppvar[3]._pval
#define _p_Sst	_ppvar[3]._pval
 
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
 static int hoc_nrnpointerindex =  3;
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
 "setdata_A_GIRK", _hoc_setdata,
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
 static double eGIRK0 = 0;
 static double iGIRK0 = 0;
 static double v = 0;
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
"A_GIRK",
 "knockoutda_A_GIRK",
 "gGIRKko_A_GIRK",
 "sombara2_A_GIRK",
 "ssom2_A_GIRK",
 0,
 "gGIRKbar_A_GIRK",
 "gGIRK_A_GIRK",
 "EffS_A_GIRK",
 0,
 "iGIRK_A_GIRK",
 0,
 "Sst_A_GIRK",
 0};
 static Symbol* _GIRK_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	knockoutda = 0;
 	gGIRKko = 0;
 	sombara2 = 0;
 	ssom2 = 0;
 	_prop->param = _p;
 	_prop->param_size = 12;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_GIRK_sym);
 nrn_promote(prop_ion, 0, 3);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iGIRK */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_diGIRKdv */
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eGIRK */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Alpha_GIRK_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("GIRK", 1.0);
 	_GIRK_sym = hoc_lookup("GIRK_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 12, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "GIRK_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "GIRK_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "GIRK_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 A_GIRK /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Alpha_GIRK.mod\n");
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
   nrn_update_ion_pointer(_GIRK_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_GIRK_sym, _ppvar, 1, 4);
   nrn_update_ion_pointer(_GIRK_sym, _ppvar, 2, 0);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
{
  eGIRK = eGIRK0;
  iGIRK = iGIRK0;
 {
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
   _ion_eGIRK = eGIRK;
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gGIRKbar = ( 1.0 - knockoutda ) * 0.025 + knockoutda * gGIRKko ;
   EffS = 1.0 / ( 1.0 + exp ( - ( Sst - sombara2 ) / ssom2 ) ) ;
   gGIRK = gGIRKbar * EffS ;
   iGIRK = gGIRKbar * EffS * ( v - eGIRK ) ;
   }
 _current += iGIRK;

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
 	{ double _diGIRK;
  _diGIRK = iGIRK;
 _rhs = _nrn_current(_v);
  _ion_diGIRKdv += (_diGIRK - iGIRK)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_iGIRK += iGIRK ;
  _ion_eGIRK = eGIRK;
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
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/Alpha_GIRK.mod";
static const char* nmodl_file_text = 
  ": Sst inhibits G secretion by reducing cAMP, which primarily reduces exocytosis but also through\n"
  ": act. of G protein-coupled inward rect potass (GIRK) chans\n"
  "NEURON{\n"
  "SUFFIX A_GIRK\n"
  "USEION GIRK WRITE iGIRK, eGIRK VALENCE 1\n"
  "RANGE knockoutda, gGIRKko, sombara2, ssom2\n"
  "RANGE gGIRKbar, gGIRK, EffS\n"
  "POINTER Sst\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "knockoutda \n"
  "gGIRKko \n"
  "sombara2\n"
  "ssom2\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "gGIRKbar\n"
  "gGIRK\n"
  "EffS\n"
  "Sst\n"
  "v\n"
  "}\n"
  "\n"
  "STATE{\n"
  "iGIRK\n"
  "eGIRK \n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "gGIRKbar = (1 - knockoutda) * 0.025 + knockoutda * gGIRKko\n"
  "EffS = 1/(1 + exp(-(Sst - sombara2)/ssom2)) : Effect of Sst \n"
  "gGIRK = gGIRKbar * EffS \n"
  "iGIRK = gGIRKbar * EffS * (v - eGIRK)\n"
  "}\n"
  "\n"
  ;
#endif

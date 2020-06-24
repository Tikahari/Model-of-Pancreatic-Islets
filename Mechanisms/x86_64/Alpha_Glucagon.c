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
 
#define nrn_init _nrn_init__A_Glucagon
#define _nrn_initial _nrn_initial__A_Glucagon
#define nrn_cur _nrn_cur__A_Glucagon
#define _nrn_current _nrn_current__A_Glucagon
#define nrn_jacob _nrn_jacob__A_Glucagon
#define nrn_state _nrn_state__A_Glucagon
#define _net_receive _net_receive__A_Glucagon 
#define states states__A_Glucagon 
 
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
#define t_ _p[0]
#define dir _p[1]
#define temp _p[2]
#define Ins _p[3]
#define alphaa _p[4]
#define Ba _p[5]
#define fcyta _p[6]
#define fVpqa _p[7]
#define tmsb _p[8]
#define vcella _p[9]
#define vmdpq _p[10]
#define kpmcaa _p[11]
#define ksercaa _p[12]
#define pleaka _p[13]
#define fera _p[14]
#define sigmava _p[15]
#define fmda _p[16]
#define k1a _p[17]
#define km1a _p[18]
#define r1a _p[19]
#define rm1a _p[20]
#define r20a _p[21]
#define r30a _p[22]
#define rm3a _p[23]
#define u1a _p[24]
#define u2a _p[25]
#define u3a _p[26]
#define kpa _p[27]
#define kp2a _p[28]
#define GlucFacta _p[29]
#define knockoutda _p[30]
#define ra _p[31]
#define sombara _p[32]
#define rako _p[33]
#define ssom _p[34]
#define fa _p[35]
#define vc _p[36]
#define caerbara _p[37]
#define ssoca _p[38]
#define gsocbara _p[39]
#define vsoca _p[40]
#define iCaPQ _p[41]
#define iCaT _p[42]
#define iCaL _p[43]
#define JPQ _p[44]
#define JTa _p[45]
#define JLa _p[46]
#define Jera _p[47]
#define rm2a _p[48]
#define r2a _p[49]
#define r3a _p[50]
#define Jsercaa _p[51]
#define Jleaka _p[52]
#define Jmema _p[53]
#define JGS _p[54]
#define cinfa _p[55]
#define isoca _p[56]
#define Sst _p[57]
#define ca _p[58]
#define cera _p[59]
#define cmdpqa _p[60]
#define N1a _p[61]
#define N2a _p[62]
#define N3a _p[63]
#define N4a _p[64]
#define N5a _p[65]
#define N6a _p[66]
#define NFa _p[67]
#define NRa _p[68]
#define G _p[69]
#define Dca _p[70]
#define Dcera _p[71]
#define Dcmdpqa _p[72]
#define DN1a _p[73]
#define DN2a _p[74]
#define DN3a _p[75]
#define DN4a _p[76]
#define DN5a _p[77]
#define DN6a _p[78]
#define DNFa _p[79]
#define DNRa _p[80]
#define DG _p[81]
#define v _p[82]
#define _g _p[83]
#define _ion_iCaPQ	*_ppvar[0]._pval
#define _ion_iCaT	*_ppvar[1]._pval
#define _ion_iCaL	*_ppvar[2]._pval
 
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
 "setdata_A_Glucagon", _hoc_setdata,
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
 static double G0 = 0;
 static double NRa0 = 0;
 static double NFa0 = 0;
 static double N6a0 = 0;
 static double N5a0 = 0;
 static double N4a0 = 0;
 static double N3a0 = 0;
 static double N2a0 = 0;
 static double N1a0 = 0;
 static double cmdpqa0 = 0;
 static double cera0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
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
"A_Glucagon",
 "t__A_Glucagon",
 "dir_A_Glucagon",
 "temp_A_Glucagon",
 "Ins_A_Glucagon",
 "alphaa_A_Glucagon",
 "Ba_A_Glucagon",
 "fcyta_A_Glucagon",
 "fVpqa_A_Glucagon",
 "tmsb_A_Glucagon",
 "vcella_A_Glucagon",
 "vmdpq_A_Glucagon",
 "kpmcaa_A_Glucagon",
 "ksercaa_A_Glucagon",
 "pleaka_A_Glucagon",
 "fera_A_Glucagon",
 "sigmava_A_Glucagon",
 "fmda_A_Glucagon",
 "k1a_A_Glucagon",
 "km1a_A_Glucagon",
 "r1a_A_Glucagon",
 "rm1a_A_Glucagon",
 "r20a_A_Glucagon",
 "r30a_A_Glucagon",
 "rm3a_A_Glucagon",
 "u1a_A_Glucagon",
 "u2a_A_Glucagon",
 "u3a_A_Glucagon",
 "kpa_A_Glucagon",
 "kp2a_A_Glucagon",
 "GlucFacta_A_Glucagon",
 "knockoutda_A_Glucagon",
 "ra_A_Glucagon",
 "sombara_A_Glucagon",
 "rako_A_Glucagon",
 "ssom_A_Glucagon",
 "fa_A_Glucagon",
 "vc_A_Glucagon",
 "caerbara_A_Glucagon",
 "ssoca_A_Glucagon",
 "gsocbara_A_Glucagon",
 "vsoca_A_Glucagon",
 0,
 "iCaPQ_A_Glucagon",
 "iCaT_A_Glucagon",
 "iCaL_A_Glucagon",
 "JPQ_A_Glucagon",
 "JTa_A_Glucagon",
 "JLa_A_Glucagon",
 "Jera_A_Glucagon",
 "rm2a_A_Glucagon",
 "r2a_A_Glucagon",
 "r3a_A_Glucagon",
 "Jsercaa_A_Glucagon",
 "Jleaka_A_Glucagon",
 "Jmema_A_Glucagon",
 "JGS_A_Glucagon",
 "cinfa_A_Glucagon",
 "isoca_A_Glucagon",
 "Sst_A_Glucagon",
 0,
 "ca_A_Glucagon",
 "cera_A_Glucagon",
 "cmdpqa_A_Glucagon",
 "N1a_A_Glucagon",
 "N2a_A_Glucagon",
 "N3a_A_Glucagon",
 "N4a_A_Glucagon",
 "N5a_A_Glucagon",
 "N6a_A_Glucagon",
 "NFa_A_Glucagon",
 "NRa_A_Glucagon",
 "G_A_Glucagon",
 0,
 0};
 static Symbol* _CaPQ_sym;
 static Symbol* _CaT_sym;
 static Symbol* _CaL_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 84, _prop);
 	/*initialize range parameters*/
 	t_ = 0;
 	dir = 0;
 	temp = 0;
 	Ins = 0;
 	alphaa = 0;
 	Ba = 0;
 	fcyta = 0;
 	fVpqa = 0;
 	tmsb = 0;
 	vcella = 0;
 	vmdpq = 0;
 	kpmcaa = 0;
 	ksercaa = 0;
 	pleaka = 0;
 	fera = 0;
 	sigmava = 0;
 	fmda = 0;
 	k1a = 0;
 	km1a = 0;
 	r1a = 0;
 	rm1a = 0;
 	r20a = 0;
 	r30a = 0;
 	rm3a = 0;
 	u1a = 0;
 	u2a = 0;
 	u3a = 0;
 	kpa = 0;
 	kp2a = 0;
 	GlucFacta = 0;
 	knockoutda = 0;
 	ra = 0;
 	sombara = 0;
 	rako = 0;
 	ssom = 0;
 	fa = 0;
 	vc = 0;
 	caerbara = 0;
 	ssoca = 0;
 	gsocbara = 0;
 	vsoca = 0;
 	_prop->param = _p;
 	_prop->param_size = 84;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_CaPQ_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* iCaPQ */
 prop_ion = need_memb(_CaT_sym);
 	_ppvar[1]._pval = &prop_ion->param[3]; /* iCaT */
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* iCaL */
 
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

 void _Alpha_Glucagon_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("CaPQ", -10000.);
 	ion_reg("CaT", -10000.);
 	ion_reg("CaL", -10000.);
 	_CaPQ_sym = hoc_lookup("CaPQ_ion");
 	_CaT_sym = hoc_lookup("CaT_ion");
 	_CaL_sym = hoc_lookup("CaL_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 84, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "CaPQ_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "CaT_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 A_Glucagon /ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Alpha_Glucagon.mod\n");
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
 static int _slist1[12], _dlist1[12];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   Dca = fcyta * ( Jmema + Jera ) ;
   Dcera = - fera * sigmava * Jera ;
   Dcmdpqa = fmda * JPQ - fmda * Ba * ( cmdpqa - ca ) ;
   DN1a = tmsb * ( - ( 3.0 * k1a * cmdpqa + rm1a ) * N1a + km1a * N2a + r1a * N5a ) ;
   DN2a = tmsb * ( 3.0 * k1a * cmdpqa * N1a - ( 2.0 * k1a * cmdpqa + km1a ) * N2a + 2.0 * km1a * N3a ) ;
   DN3a = tmsb * ( 2.0 * k1a * cmdpqa * N2a - ( 2.0 * km1a + k1a * cmdpqa ) * N3a + 3.0 * km1a * N4a ) ;
   DN4a = tmsb * ( k1a * cmdpqa * N3a - ( 3.0 * km1a + u1a ) * N4a ) ;
   DN5a = tmsb * ( rm1a * N1a - ( r1a + rm2a ) * N5a + r2a * N6a ) ;
   DN6a = tmsb * ( r3a + rm2a * N5a - ( rm3a + r2a ) * N6a ) ;
   DNFa = tmsb * ( u1a * N4a - u2a * NFa ) ;
   DNRa = tmsb * ( u2a * NFa - u3a * NRa ) ;
   DG = JGS / vc - fa * G ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 Dca = Dca  / (1. - dt*( 0.0 )) ;
 Dcera = Dcera  / (1. - dt*( 0.0 )) ;
 Dcmdpqa = Dcmdpqa  / (1. - dt*( ( - ( fmda * Ba )*( ( 1.0 ) ) ) )) ;
 DN1a = DN1a  / (1. - dt*( ( tmsb )*( ( ( - ( 3.0 * k1a * cmdpqa + rm1a ) )*( 1.0 ) ) ) )) ;
 DN2a = DN2a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * k1a * cmdpqa + km1a ) )*( 1.0 ) ) ) ) )) ;
 DN3a = DN3a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * km1a + k1a * cmdpqa ) )*( 1.0 ) ) ) ) )) ;
 DN4a = DN4a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 3.0 * km1a + u1a ) )*( 1.0 ) ) ) ) )) ;
 DN5a = DN5a  / (1. - dt*( ( tmsb )*( ( ( - ( ( r1a + rm2a ) )*( 1.0 ) ) ) ) )) ;
 DN6a = DN6a  / (1. - dt*( ( tmsb )*( ( ( - ( ( rm3a + r2a ) )*( 1.0 ) ) ) ) )) ;
 DNFa = DNFa  / (1. - dt*( ( tmsb )*( ( ( - ( u2a )*( 1.0 ) ) ) ) )) ;
 DNRa = DNRa  / (1. - dt*( ( tmsb )*( ( ( - ( u3a )*( 1.0 ) ) ) ) )) ;
 DG = DG  / (1. - dt*( ( - ( fa )*( 1.0 ) ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    ca = ca - dt*(- ( ( fcyta )*( ( Jmema + Jera ) ) ) ) ;
    cera = cera - dt*(- ( ( ( - fera )*( sigmava ) )*( Jera ) ) ) ;
    cmdpqa = cmdpqa + (1. - exp(dt*(( - ( fmda * Ba )*( ( 1.0 ) ) ))))*(- ( ( fmda )*( JPQ ) - ( ( fmda )*( Ba ) )*( ( ( - ca ) ) ) ) / ( ( - ( ( fmda )*( Ba ) )*( ( 1.0 ) ) ) ) - cmdpqa) ;
    N1a = N1a + (1. - exp(dt*(( tmsb )*( ( ( - ( 3.0 * k1a * cmdpqa + rm1a ) )*( 1.0 ) ) ))))*(- ( ( tmsb )*( ( ( km1a )*( N2a ) + ( r1a )*( N5a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 3.0 )*( k1a ) )*( cmdpqa ) + rm1a ) )*( 1.0 ) ) ) ) - N1a) ;
    N2a = N2a + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 2.0 * k1a * cmdpqa + km1a ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( ( 3.0 )*( k1a ) )*( cmdpqa ) )*( N1a ) + ( ( 2.0 )*( km1a ) )*( N3a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( ( 2.0 )*( k1a ) )*( cmdpqa ) + km1a ) )*( 1.0 ) ) ) ) ) - N2a) ;
    N3a = N3a + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 2.0 * km1a + k1a * cmdpqa ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( ( 2.0 )*( k1a ) )*( cmdpqa ) )*( N2a ) + ( ( 3.0 )*( km1a ) )*( N4a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 2.0 )*( km1a ) + ( k1a )*( cmdpqa ) ) )*( 1.0 ) ) ) ) ) - N3a) ;
    N4a = N4a + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 3.0 * km1a + u1a ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( k1a )*( cmdpqa ) )*( N3a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 3.0 )*( km1a ) + u1a ) )*( 1.0 ) ) ) ) ) - N4a) ;
    N5a = N5a + (1. - exp(dt*(( tmsb )*( ( ( - ( ( r1a + rm2a ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( rm1a )*( N1a ) + ( r2a )*( N6a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( r1a + rm2a ) )*( 1.0 ) ) ) ) ) - N5a) ;
    N6a = N6a + (1. - exp(dt*(( tmsb )*( ( ( - ( ( rm3a + r2a ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( r3a + ( rm2a )*( N5a ) ) ) ) / ( ( tmsb )*( ( ( - ( ( rm3a + r2a ) )*( 1.0 ) ) ) ) ) - N6a) ;
    NFa = NFa + (1. - exp(dt*(( tmsb )*( ( ( - ( u2a )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( u1a )*( N4a ) ) ) ) / ( ( tmsb )*( ( ( - ( u2a )*( 1.0 ) ) ) ) ) - NFa) ;
    NRa = NRa + (1. - exp(dt*(( tmsb )*( ( ( - ( u3a )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( u2a )*( NFa ) ) ) ) / ( ( tmsb )*( ( ( - ( u3a )*( 1.0 ) ) ) ) ) - NRa) ;
    G = G + (1. - exp(dt*(( - ( fa )*( 1.0 ) ))))*(- ( ( JGS ) / vc ) / ( ( - ( fa )*( 1.0 ) ) ) - G) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 12;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  iCaPQ = _ion_iCaPQ;
  iCaT = _ion_iCaT;
  iCaL = _ion_iCaL;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 12; ++_i) {
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
  iCaPQ = _ion_iCaPQ;
  iCaT = _ion_iCaT;
  iCaL = _ion_iCaL;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_CaPQ_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_CaT_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 2, 3);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  G = G0;
  NRa = NRa0;
  NFa = NFa0;
  N6a = N6a0;
  N5a = N5a0;
  N4a = N4a0;
  N3a = N3a0;
  N2a = N2a0;
  N1a = N1a0;
  cmdpqa = cmdpqa0;
  cera = cera0;
  ca = ca0;
 {
   t_ = 0.0 ;
   dir = 0.0 ;
   temp = 0.0 ;
   alphaa = 5.18e-15 ;
   Ba = 1.0 ;
   fcyta = 0.01 ;
   fVpqa = 0.00226 ;
   tmsb = 0.001 ;
   vcella = 0.624e-12 ;
   vmdpq = 1.41e-15 ;
   cmdpqa = 11.51299890826233 ;
   ca = 0.3449148387259899 ;
   kpmcaa = 0.3 ;
   ksercaa = 0.05 ;
   pleaka = 0.0003 ;
   cera = 58.71698724650182 ;
   N1a = 1.057203539612775e-05 ;
   N2a = 2.113947666062938e-05 ;
   N3a = 2.388848788981755e-05 ;
   N4a = 2.391806975716259e-06 ;
   N5a = 0.008850176609826538 ;
   N6a = 12.69715161782077 ;
   NFa = 0.001724142875712899 ;
   NRa = 0.1927364884362762 ;
   fera = 0.01 ;
   sigmava = 31.0 ;
   fmda = 0.01 ;
   k1a = 20.0 ;
   km1a = 100.0 ;
   r1a = 0.6 ;
   rm1a = 1.0 ;
   r20a = 0.006 ;
   r30a = 1.205 ;
   rm3a = 0.0001 ;
   u1a = 2000.0 ;
   u2a = 3.0 ;
   u3a = 0.025 ;
   kpa = 2.3 ;
   kp2a = 2.3 ;
   GlucFacta = 0.05 ;
   knockoutda = 0.0 ;
   ra = 4.5 ;
   sombara = 50.0 ;
   rako = 0.001 ;
   ssom = 15.0 ;
   fa = 150.0 ;
   vc = 1e-13 ;
   caerbara = 70.0 ;
   ssoca = - 20.0 ;
   vsoca = 0.0 ;
   gsocbara = 0.025 ;
   v = - 49.03736299581227 ;
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
  iCaPQ = _ion_iCaPQ;
  iCaT = _ion_iCaT;
  iCaL = _ion_iCaL;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
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
  iCaPQ = _ion_iCaPQ;
  iCaT = _ion_iCaT;
  iCaL = _ion_iCaL;
 {   states(_p, _ppvar, _thread, _nt);
  } {
   if ( t_ > 2.0 ) {
     dir = 1.0 ;
     }
   else if ( t_  == 0.0 ) {
     dir = 0.0 ;
     }
   if ( dir  == 0.0 ) {
     t_ = t_ + 1.0 ;
     }
   else {
     t_ = t_ - 1.0 ;
     }
   JPQ = - alphaa * iCaPQ / vmdpq ;
   JTa = - alphaa * iCaT / vcella ;
   JLa = - alphaa * iCaL / vcella ;
   rm2a = ( 1.0 - knockoutda ) * ra / ( 1.0 + exp ( - ( Sst - sombara ) / ssom ) ) + knockoutda * rako ;
   r2a = r20a * ca / ( ca + kp2a ) ;
   r3a = GlucFacta * r30a * ca / ( ca + kpa ) ;
   Jsercaa = ksercaa * ca ;
   Jleaka = pleaka * ( cera - ca ) ;
   Jera = Jleaka - Jsercaa ;
   Jmema = JTa + JLa + fVpqa * Ba * ( cmdpqa - ca ) - kpmcaa * ca ;
   JGS = tmsb * u3a * NRa * 0.0000988 ;
   cinfa = 1.0 / ( 1.0 + exp ( - ( cera - caerbara ) / ssoca ) ) ;
   isoca = gsocbara * cinfa * ( v - vsoca ) ;
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(ca) - _p;  _dlist1[0] = &(Dca) - _p;
 _slist1[1] = &(cera) - _p;  _dlist1[1] = &(Dcera) - _p;
 _slist1[2] = &(cmdpqa) - _p;  _dlist1[2] = &(Dcmdpqa) - _p;
 _slist1[3] = &(N1a) - _p;  _dlist1[3] = &(DN1a) - _p;
 _slist1[4] = &(N2a) - _p;  _dlist1[4] = &(DN2a) - _p;
 _slist1[5] = &(N3a) - _p;  _dlist1[5] = &(DN3a) - _p;
 _slist1[6] = &(N4a) - _p;  _dlist1[6] = &(DN4a) - _p;
 _slist1[7] = &(N5a) - _p;  _dlist1[7] = &(DN5a) - _p;
 _slist1[8] = &(N6a) - _p;  _dlist1[8] = &(DN6a) - _p;
 _slist1[9] = &(NFa) - _p;  _dlist1[9] = &(DNFa) - _p;
 _slist1[10] = &(NRa) - _p;  _dlist1[10] = &(DNRa) - _p;
 _slist1[11] = &(G) - _p;  _dlist1[11] = &(DG) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/robert727/Model-of-Pancreatic-Islets/Mechanisms/Alpha_Glucagon.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX A_Glucagon\n"
  "USEION CaPQ READ iCaPQ\n"
  "USEION CaT READ iCaT\n"
  "USEION CaL READ iCaL\n"
  "RANGE alphaa, Ba, fcyta, fVpqa, tmsb, vcella, vmdpq, kpmcaa, ksercaa, pleaka, fera, sigmava, fmda, k1a, km1a, r1a, rm1a, r20a, r30a, rm3a, u1a, u2a, u3a, kpa, kp2a, GlucFacta, knockoutda, ra, sombara, rako, ssom, fa, vc, caerbara, ssoca, vsoca, gsocbara, G \n"
  "RANGE iCaPQ, iCaT, iCaL, JPQ, JTa, JLa, Jera, rm2a, r2a, r3a, Jsercaa, Jleaka, Jmema, JGS, cinfa, isoca\n"
  "RANGE Sst, Ins\n"
  "RANGE t_, dir, temp\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  ": hormone secretion variables\n"
  "t_\n"
  "dir\n"
  "temp\n"
  "Ins\n"
  "alphaa \n"
  "Ba \n"
  "fcyta \n"
  "fVpqa \n"
  "tmsb \n"
  "vcella\n"
  "vmdpq \n"
  "kpmcaa \n"
  "ksercaa \n"
  "pleaka \n"
  "fera \n"
  "sigmava \n"
  "fmda \n"
  "k1a \n"
  "km1a \n"
  "r1a \n"
  "rm1a \n"
  "r20a \n"
  "r30a \n"
  "rm3a \n"
  "u1a \n"
  "u2a \n"
  "u3a \n"
  "kpa \n"
  "kp2a \n"
  "GlucFacta \n"
  "knockoutda \n"
  "ra \n"
  "sombara \n"
  "rako \n"
  "ssom \n"
  "fa \n"
  "vc \n"
  "caerbara \n"
  "ssoca \n"
  "gsocbara\n"
  "vsoca \n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "iCaPQ\n"
  "iCaT\n"
  "iCaL\n"
  "JPQ\n"
  "JTa\n"
  "JLa\n"
  "Jera\n"
  "rm2a\n"
  "r2a \n"
  "r3a \n"
  "Jsercaa\n"
  "Jleaka \n"
  "Jmema \n"
  "JGS \n"
  "cinfa\n"
  "isoca\n"
  "Sst\n"
  "v\n"
  "}\n"
  "\n"
  "STATE{\n"
  "ca\n"
  "cera\n"
  "cmdpqa\n"
  "N1a\n"
  "N2a\n"
  "N3a\n"
  "N4a\n"
  "N5a\n"
  "N6a\n"
  "NFa\n"
  "NRa\n"
  "G\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "t_ = 0\n"
  "dir = 0\n"
  "temp = 0\n"
  "alphaa = 5.18e-15\n"
  "Ba = 1\n"
  "fcyta = 0.01\n"
  "fVpqa = 0.00226\n"
  "tmsb = 0.001\n"
  "vcella = 0.624e-12\n"
  "vmdpq = 1.41e-15\n"
  "cmdpqa = 11.51299890826233\n"
  "ca = 0.3449148387259899\n"
  "kpmcaa = 0.3\n"
  "ksercaa = 0.05\n"
  "pleaka = 0.0003\n"
  "cera = 58.71698724650182\n"
  "N1a = 1.057203539612775e-05\n"
  "N2a = 2.113947666062938e-05\n"
  "N3a = 2.388848788981755e-05\n"
  "N4a = 2.391806975716259e-06\n"
  "N5a = 0.008850176609826538\n"
  "N6a = 12.69715161782077\n"
  "NFa = 0.001724142875712899\n"
  "NRa = 0.1927364884362762\n"
  "fera = 0.01\n"
  "sigmava = 31\n"
  "fmda = 0.01\n"
  "k1a = 20\n"
  "km1a = 100\n"
  "r1a = 0.6\n"
  "rm1a = 1\n"
  "r20a = 0.006\n"
  "r30a = 1.205\n"
  "rm3a = 0.0001\n"
  "u1a = 2000\n"
  "u2a = 3\n"
  "u3a = 0.025\n"
  "kpa = 2.3\n"
  "kp2a = 2.3\n"
  "GlucFacta = 0.05\n"
  "knockoutda = 0\n"
  "ra = 4.5\n"
  "sombara = 50\n"
  "rako = 0.001\n"
  "ssom = 15\n"
  "fa = 150\n"
  "vc = 1e-13\n"
  "caerbara = 70\n"
  "ssoca = -20\n"
  "vsoca = 0\n"
  "gsocbara = 0.025\n"
  "v = -49.03736299581227\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "if (t_ > 2){\n"
  "dir = 1\n"
  "}\n"
  "else if (t_ == 0){\n"
  "dir = 0\n"
  "}\n"
  "if (dir == 0){\n"
  "t_ = t_ + 1\n"
  "}\n"
  "else{\n"
  "t_ = t_ - 1\n"
  "}\n"
  "JPQ = -alphaa*iCaPQ / vmdpq\n"
  "JTa = -alphaa*iCaT/vcella\n"
  "JLa = -alphaa*iCaL/vcella\n"
  "rm2a=(1-knockoutda)*ra/(1+exp(-(Sst-sombara)/ssom))+knockoutda*rako :Delta inhibiting alphaa by Sst increasing the rate of depriming of G granules.\n"
  "SOLVE states METHOD cnexp\n"
  "r2a = r20a*ca/(ca+kp2a)\n"
  "r3a = GlucFacta*r30a*ca/(ca+kpa)\n"
  "Jsercaa = ksercaa*ca\n"
  "Jleaka = pleaka*(cera - ca)\n"
  "Jera = Jleaka - Jsercaa\n"
  "Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca\n"
  "JGS = tmsb*u3a*NRa*0.0000988\n"
  "cinfa = 1/(1 + exp(-(cera - caerbara)/ssoca))\n"
  "isoca = gsocbara * cinfa * (v - vsoca)\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "ca'= fcyta*(Jmema+Jera)\n"
  "cera'= -fera*sigmava*Jera\n"
  "cmdpqa' = fmda*JPQ-fmda*Ba*(cmdpqa-ca)\n"
  "N1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*N1a + km1a*N2a + r1a*N5a)\n"
  "N2a' = tmsb*(3*k1a*cmdpqa*N1a -(2*k1a*cmdpqa + km1a)*N2a + 2*km1a*N3a)\n"
  "N3a' = tmsb*(2*k1a*cmdpqa*N2a -(2*km1a + k1a*cmdpqa)*N3a + 3*km1a*N4a)\n"
  "N4a' = tmsb*(k1a*cmdpqa*N3a - (3*km1a + u1a)*N4a)\n"
  "N5a' = tmsb*(rm1a*N1a - (r1a + rm2a)*N5a + r2a*N6a)\n"
  "N6a' = tmsb*(r3a + rm2a*N5a - (rm3a + r2a)*N6a)\n"
  "NFa' = tmsb*(u1a*N4a - u2a*NFa)\n"
  "NRa' = tmsb*(u2a*NFa - u3a*NRa)\n"
  "G' = JGS/vc-fa*G\n"
  "}\n"
  ;
#endif

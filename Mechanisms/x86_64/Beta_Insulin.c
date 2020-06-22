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
 
#define nrn_init _nrn_init__B_Insulin
#define _nrn_initial _nrn_initial__B_Insulin
#define nrn_cur _nrn_cur__B_Insulin
#define _nrn_current _nrn_current__B_Insulin
#define nrn_jacob _nrn_jacob__B_Insulin
#define nrn_state _nrn_state__B_Insulin
#define _net_receive _net_receive__B_Insulin 
#define states states__B_Insulin 
 
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
#define G _p[3]
#define Sst _p[4]
#define vmd _p[5]
#define vcell _p[6]
#define alpha _p[7]
#define B _p[8]
#define kpmca _p[9]
#define cbas _p[10]
#define kserca2b _p[11]
#define kserca3 _p[12]
#define per _p[13]
#define phigk _p[14]
#define KGPDH _p[15]
#define kappa _p[16]
#define Jgk _p[17]
#define fcyt _p[18]
#define delta _p[19]
#define p23 _p[20]
#define p24 _p[21]
#define psim _p[22]
#define p21 _p[23]
#define p22 _p[24]
#define fer _p[25]
#define sigmav _p[26]
#define fmd _p[27]
#define lambda _p[28]
#define VmaxPFK _p[29]
#define weight1 _p[30]
#define topa1 _p[31]
#define bottom1 _p[32]
#define atot _p[33]
#define k4 _p[34]
#define k3 _p[35]
#define f43 _p[36]
#define k2 _p[37]
#define f42 _p[38]
#define f23 _p[39]
#define amp _p[40]
#define k1 _p[41]
#define f41 _p[42]
#define f13 _p[43]
#define gamma _p[44]
#define p19 _p[45]
#define Amtot _p[46]
#define p20 _p[47]
#define FRT _p[48]
#define p16 _p[49]
#define p13 _p[50]
#define p14 _p[51]
#define p15 _p[52]
#define fmito _p[53]
#define p8 _p[54]
#define p9 _p[55]
#define p10 _p[56]
#define p11 _p[57]
#define p17 _p[58]
#define p18 _p[59]
#define Cmito _p[60]
#define p1 _p[61]
#define p2 _p[62]
#define p3 _p[63]
#define NADmtot _p[64]
#define Jgpdh_bas _p[65]
#define p4 _p[66]
#define p5 _p[67]
#define p6 _p[68]
#define p7 _p[69]
#define vm _p[70]
#define sm _p[71]
#define gCa _p[72]
#define nCa _p[73]
#define vCa _p[74]
#define raL _p[75]
#define khyd _p[76]
#define JhydSS _p[77]
#define taua _p[78]
#define tmsb _p[79]
#define u1 _p[80]
#define u2 _p[81]
#define u3 _p[82]
#define gthresh _p[83]
#define Kp2 _p[84]
#define Kp _p[85]
#define r30 _p[86]
#define factor _p[87]
#define amplify _p[88]
#define bas_r3 _p[89]
#define rm3 _p[90]
#define rb _p[91]
#define knockoutdb _p[92]
#define sombarb _p[93]
#define ssomb _p[94]
#define r1 _p[95]
#define rm1 _p[96]
#define km1 _p[97]
#define bas_cmd _p[98]
#define max_cmd _p[99]
#define cmdp _p[100]
#define kcmd _p[101]
#define exo_k1 _p[102]
#define vc _p[103]
#define fb _p[104]
#define minf _p[105]
#define iCa _p[106]
#define iCaL _p[107]
#define iCaR _p[108]
#define vmdcyt _p[109]
#define JL _p[110]
#define JR _p[111]
#define Jmem _p[112]
#define Jserca _p[113]
#define Jleak _p[114]
#define Jer _p[115]
#define f6p _p[116]
#define Jgpdh _p[117]
#define Jgk_ms _p[118]
#define JNaCa _p[119]
#define Juni _p[120]
#define Jmito _p[121]
#define ATPm _p[122]
#define RATm _p[123]
#define JANT _p[124]
#define b2 _p[125]
#define JF1F0 _p[126]
#define JHatp _p[127]
#define MM2 _p[128]
#define JHres _p[129]
#define JHleak _p[130]
#define NADm _p[131]
#define JPDH _p[132]
#define MM1 _p[133]
#define JO _p[134]
#define atp _p[135]
#define Jhyd _p[136]
#define weight2 _p[137]
#define topa2 _p[138]
#define bottom2 _p[139]
#define weight3 _p[140]
#define topa3 _p[141]
#define bottom3 _p[142]
#define weight4 _p[143]
#define topa4 _p[144]
#define bottom4 _p[145]
#define weight5 _p[146]
#define topa5 _p[147]
#define bottom5 _p[148]
#define weight6 _p[149]
#define topa6 _p[150]
#define bottom6 _p[151]
#define weight7 _p[152]
#define topa7 _p[153]
#define bottom7 _p[154]
#define weight8 _p[155]
#define topa8 _p[156]
#define bottom8 _p[157]
#define weight9 _p[158]
#define topa9 _p[159]
#define bottom9 _p[160]
#define weight10 _p[161]
#define topa10 _p[162]
#define bottom10 _p[163]
#define weight11 _p[164]
#define topa11 _p[165]
#define bottom11 _p[166]
#define weight12 _p[167]
#define topa12 _p[168]
#define bottom12 _p[169]
#define weight13 _p[170]
#define topa13 _p[171]
#define bottom13 _p[172]
#define weight14 _p[173]
#define topa14 _p[174]
#define bottom14 _p[175]
#define weight15 _p[176]
#define topa15 _p[177]
#define topb _p[178]
#define bottom15 _p[179]
#define weight16 _p[180]
#define topa16 _p[181]
#define bottom16 _p[182]
#define pfk _p[183]
#define pfk_ms _p[184]
#define r20 _p[185]
#define ampfactor _p[186]
#define r3 _p[187]
#define r2 _p[188]
#define rm2b _p[189]
#define mod_cmd _p[190]
#define JIS _p[191]
#define c _p[192]
#define cer _p[193]
#define cmd _p[194]
#define g6p _p[195]
#define fbp _p[196]
#define ADPm _p[197]
#define cam _p[198]
#define Psim _p[199]
#define adp _p[200]
#define NADHm _p[201]
#define N1 _p[202]
#define N2 _p[203]
#define N3 _p[204]
#define N4 _p[205]
#define N5 _p[206]
#define N6 _p[207]
#define NF _p[208]
#define NR _p[209]
#define Ins _p[210]
#define Dc _p[211]
#define Dcer _p[212]
#define Dcmd _p[213]
#define Dg6p _p[214]
#define Dfbp _p[215]
#define DADPm _p[216]
#define Dcam _p[217]
#define DPsim _p[218]
#define Dadp _p[219]
#define DNADHm _p[220]
#define DN1 _p[221]
#define DN2 _p[222]
#define DN3 _p[223]
#define DN4 _p[224]
#define DN5 _p[225]
#define DN6 _p[226]
#define DNF _p[227]
#define DNR _p[228]
#define DIns _p[229]
#define v _p[230]
#define _g _p[231]
 
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
 "setdata_B_Insulin", _hoc_setdata,
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
 static double ADPm0 = 0;
 static double Ins0 = 0;
 static double NR0 = 0;
 static double NF0 = 0;
 static double N60 = 0;
 static double N50 = 0;
 static double N40 = 0;
 static double N30 = 0;
 static double N20 = 0;
 static double N10 = 0;
 static double NADHm0 = 0;
 static double Psim0 = 0;
 static double adp0 = 0;
 static double cam0 = 0;
 static double cmd0 = 0;
 static double cer0 = 0;
 static double c0 = 0;
 static double delta_t = 0.01;
 static double fbp0 = 0;
 static double g6p0 = 0;
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
 
#define _cvode_ieq _ppvar[0]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"B_Insulin",
 "t__B_Insulin",
 "dir_B_Insulin",
 "temp_B_Insulin",
 "G_B_Insulin",
 "Sst_B_Insulin",
 "vmd_B_Insulin",
 "vcell_B_Insulin",
 "alpha_B_Insulin",
 "B_B_Insulin",
 "kpmca_B_Insulin",
 "cbas_B_Insulin",
 "kserca2b_B_Insulin",
 "kserca3_B_Insulin",
 "per_B_Insulin",
 "phigk_B_Insulin",
 "KGPDH_B_Insulin",
 "kappa_B_Insulin",
 "Jgk_B_Insulin",
 "fcyt_B_Insulin",
 "delta_B_Insulin",
 "p23_B_Insulin",
 "p24_B_Insulin",
 "psim_B_Insulin",
 "p21_B_Insulin",
 "p22_B_Insulin",
 "fer_B_Insulin",
 "sigmav_B_Insulin",
 "fmd_B_Insulin",
 "lambda_B_Insulin",
 "VmaxPFK_B_Insulin",
 "weight1_B_Insulin",
 "topa1_B_Insulin",
 "bottom1_B_Insulin",
 "atot_B_Insulin",
 "k4_B_Insulin",
 "k3_B_Insulin",
 "f43_B_Insulin",
 "k2_B_Insulin",
 "f42_B_Insulin",
 "f23_B_Insulin",
 "amp_B_Insulin",
 "k1_B_Insulin",
 "f41_B_Insulin",
 "f13_B_Insulin",
 "gamma_B_Insulin",
 "p19_B_Insulin",
 "Amtot_B_Insulin",
 "p20_B_Insulin",
 "FRT_B_Insulin",
 "p16_B_Insulin",
 "p13_B_Insulin",
 "p14_B_Insulin",
 "p15_B_Insulin",
 "fmito_B_Insulin",
 "p8_B_Insulin",
 "p9_B_Insulin",
 "p10_B_Insulin",
 "p11_B_Insulin",
 "p17_B_Insulin",
 "p18_B_Insulin",
 "Cmito_B_Insulin",
 "p1_B_Insulin",
 "p2_B_Insulin",
 "p3_B_Insulin",
 "NADmtot_B_Insulin",
 "Jgpdh_bas_B_Insulin",
 "p4_B_Insulin",
 "p5_B_Insulin",
 "p6_B_Insulin",
 "p7_B_Insulin",
 "vm_B_Insulin",
 "sm_B_Insulin",
 "gCa_B_Insulin",
 "nCa_B_Insulin",
 "vCa_B_Insulin",
 "raL_B_Insulin",
 "khyd_B_Insulin",
 "JhydSS_B_Insulin",
 "taua_B_Insulin",
 "tmsb_B_Insulin",
 "u1_B_Insulin",
 "u2_B_Insulin",
 "u3_B_Insulin",
 "gthresh_B_Insulin",
 "Kp2_B_Insulin",
 "Kp_B_Insulin",
 "r30_B_Insulin",
 "factor_B_Insulin",
 "amplify_B_Insulin",
 "bas_r3_B_Insulin",
 "rm3_B_Insulin",
 "rb_B_Insulin",
 "knockoutdb_B_Insulin",
 "sombarb_B_Insulin",
 "ssomb_B_Insulin",
 "r1_B_Insulin",
 "rm1_B_Insulin",
 "km1_B_Insulin",
 "bas_cmd_B_Insulin",
 "max_cmd_B_Insulin",
 "cmdp_B_Insulin",
 "kcmd_B_Insulin",
 "exo_k1_B_Insulin",
 "vc_B_Insulin",
 "fb_B_Insulin",
 0,
 "minf_B_Insulin",
 "iCa_B_Insulin",
 "iCaL_B_Insulin",
 "iCaR_B_Insulin",
 "vmdcyt_B_Insulin",
 "JL_B_Insulin",
 "JR_B_Insulin",
 "Jmem_B_Insulin",
 "Jserca_B_Insulin",
 "Jleak_B_Insulin",
 "Jer_B_Insulin",
 "f6p_B_Insulin",
 "Jgpdh_B_Insulin",
 "Jgk_ms_B_Insulin",
 "JNaCa_B_Insulin",
 "Juni_B_Insulin",
 "Jmito_B_Insulin",
 "ATPm_B_Insulin",
 "RATm_B_Insulin",
 "JANT_B_Insulin",
 "b2_B_Insulin",
 "JF1F0_B_Insulin",
 "JHatp_B_Insulin",
 "MM2_B_Insulin",
 "JHres_B_Insulin",
 "JHleak_B_Insulin",
 "NADm_B_Insulin",
 "JPDH_B_Insulin",
 "MM1_B_Insulin",
 "JO_B_Insulin",
 "atp_B_Insulin",
 "Jhyd_B_Insulin",
 "weight2_B_Insulin",
 "topa2_B_Insulin",
 "bottom2_B_Insulin",
 "weight3_B_Insulin",
 "topa3_B_Insulin",
 "bottom3_B_Insulin",
 "weight4_B_Insulin",
 "topa4_B_Insulin",
 "bottom4_B_Insulin",
 "weight5_B_Insulin",
 "topa5_B_Insulin",
 "bottom5_B_Insulin",
 "weight6_B_Insulin",
 "topa6_B_Insulin",
 "bottom6_B_Insulin",
 "weight7_B_Insulin",
 "topa7_B_Insulin",
 "bottom7_B_Insulin",
 "weight8_B_Insulin",
 "topa8_B_Insulin",
 "bottom8_B_Insulin",
 "weight9_B_Insulin",
 "topa9_B_Insulin",
 "bottom9_B_Insulin",
 "weight10_B_Insulin",
 "topa10_B_Insulin",
 "bottom10_B_Insulin",
 "weight11_B_Insulin",
 "topa11_B_Insulin",
 "bottom11_B_Insulin",
 "weight12_B_Insulin",
 "topa12_B_Insulin",
 "bottom12_B_Insulin",
 "weight13_B_Insulin",
 "topa13_B_Insulin",
 "bottom13_B_Insulin",
 "weight14_B_Insulin",
 "topa14_B_Insulin",
 "bottom14_B_Insulin",
 "weight15_B_Insulin",
 "topa15_B_Insulin",
 "topb_B_Insulin",
 "bottom15_B_Insulin",
 "weight16_B_Insulin",
 "topa16_B_Insulin",
 "bottom16_B_Insulin",
 "pfk_B_Insulin",
 "pfk_ms_B_Insulin",
 "r20_B_Insulin",
 "ampfactor_B_Insulin",
 "r3_B_Insulin",
 "r2_B_Insulin",
 "rm2b_B_Insulin",
 "mod_cmd_B_Insulin",
 "JIS_B_Insulin",
 0,
 "c_B_Insulin",
 "cer_B_Insulin",
 "cmd_B_Insulin",
 "g6p_B_Insulin",
 "fbp_B_Insulin",
 "ADPm_B_Insulin",
 "cam_B_Insulin",
 "Psim_B_Insulin",
 "adp_B_Insulin",
 "NADHm_B_Insulin",
 "N1_B_Insulin",
 "N2_B_Insulin",
 "N3_B_Insulin",
 "N4_B_Insulin",
 "N5_B_Insulin",
 "N6_B_Insulin",
 "NF_B_Insulin",
 "NR_B_Insulin",
 "Ins_B_Insulin",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 232, _prop);
 	/*initialize range parameters*/
 	t_ = 0;
 	dir = 0;
 	temp = 0;
 	G = 0;
 	Sst = 0;
 	vmd = 0;
 	vcell = 0;
 	alpha = 0;
 	B = 0;
 	kpmca = 0;
 	cbas = 0;
 	kserca2b = 0;
 	kserca3 = 0;
 	per = 0;
 	phigk = 0;
 	KGPDH = 0;
 	kappa = 0;
 	Jgk = 0;
 	fcyt = 0;
 	delta = 0;
 	p23 = 0;
 	p24 = 0;
 	psim = 0;
 	p21 = 0;
 	p22 = 0;
 	fer = 0;
 	sigmav = 0;
 	fmd = 0;
 	lambda = 0;
 	VmaxPFK = 0;
 	weight1 = 0;
 	topa1 = 0;
 	bottom1 = 0;
 	atot = 0;
 	k4 = 0;
 	k3 = 0;
 	f43 = 0;
 	k2 = 0;
 	f42 = 0;
 	f23 = 0;
 	amp = 0;
 	k1 = 0;
 	f41 = 0;
 	f13 = 0;
 	gamma = 0;
 	p19 = 0;
 	Amtot = 0;
 	p20 = 0;
 	FRT = 0;
 	p16 = 0;
 	p13 = 0;
 	p14 = 0;
 	p15 = 0;
 	fmito = 0;
 	p8 = 0;
 	p9 = 0;
 	p10 = 0;
 	p11 = 0;
 	p17 = 0;
 	p18 = 0;
 	Cmito = 0;
 	p1 = 0;
 	p2 = 0;
 	p3 = 0;
 	NADmtot = 0;
 	Jgpdh_bas = 0;
 	p4 = 0;
 	p5 = 0;
 	p6 = 0;
 	p7 = 0;
 	vm = 0;
 	sm = 0;
 	gCa = 0;
 	nCa = 0;
 	vCa = 0;
 	raL = 0;
 	khyd = 0;
 	JhydSS = 0;
 	taua = 0;
 	tmsb = 0;
 	u1 = 0;
 	u2 = 0;
 	u3 = 0;
 	gthresh = 0;
 	Kp2 = 0;
 	Kp = 0;
 	r30 = 0;
 	factor = 0;
 	amplify = 0;
 	bas_r3 = 0;
 	rm3 = 0;
 	rb = 0;
 	knockoutdb = 0;
 	sombarb = 0;
 	ssomb = 0;
 	r1 = 0;
 	rm1 = 0;
 	km1 = 0;
 	bas_cmd = 0;
 	max_cmd = 0;
 	cmdp = 0;
 	kcmd = 0;
 	exo_k1 = 0;
 	vc = 0;
 	fb = 0;
 	_prop->param = _p;
 	_prop->param_size = 232;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Beta_Insulin_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 232, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 B_Insulin /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/x86_64/Beta_Insulin.mod\n");
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
 static int _slist1[19], _dlist1[19];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   Dc = fcyt * ( Jmem + Jer + delta * Jmito ) ;
   Dcer = - fer * sigmav * Jer ;
   Dcmd = fmd * ( JL - B * ( cmd - c ) ) ;
   Dg6p = Jgk_ms - pfk_ms ;
   Dfbp = pfk_ms - 0.5 * Jgpdh ;
   DADPm = gamma * ( JANT - JF1F0 ) ;
   Dcam = - fmito * Jmito ;
   DPsim = ( JHres - JHatp - JANT - JHleak - JNaCa - 2.0 * Juni ) / Cmito ;
   Dadp = ( - delta * JANT + Jhyd ) / taua ;
   DNADHm = gamma * ( JPDH - JO ) ;
   DN1 = tmsb * ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) * N1 + km1 * N2 + r1 * N5 ) ;
   DN2 = tmsb * ( 3.0 * exo_k1 * mod_cmd * N1 - ( 2.0 * exo_k1 * mod_cmd + km1 ) * N2 + 2.0 * km1 * N3 ) ;
   DN3 = tmsb * ( 2.0 * exo_k1 * mod_cmd * N2 - ( 2.0 * km1 + exo_k1 * mod_cmd ) * N3 + 3.0 * km1 * N4 ) ;
   DN4 = tmsb * ( exo_k1 * mod_cmd * N3 - ( 3.0 * km1 + u1 ) * N4 ) ;
   DN5 = tmsb * ( rm1 * N1 - ( r1 + rm2b ) * N5 + r2 * N6 ) ;
   DN6 = tmsb * ( r3 + rm2b * N5 - ( rm3 + r2 ) * N6 ) ;
   DNF = tmsb * ( u1 * N4 - u2 * NF ) ;
   DNR = tmsb * ( u2 * NF - u3 * NR ) ;
   DIns = JIS / vc - fb * Ins ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 Dc = Dc  / (1. - dt*( 0.0 )) ;
 Dcer = Dcer  / (1. - dt*( 0.0 )) ;
 Dcmd = Dcmd  / (1. - dt*( ( fmd )*( ( ( - ( B )*( ( 1.0 ) ) ) ) ) )) ;
 Dg6p = Dg6p  / (1. - dt*( 0.0 )) ;
 Dfbp = Dfbp  / (1. - dt*( 0.0 )) ;
 DADPm = DADPm  / (1. - dt*( 0.0 )) ;
 Dcam = Dcam  / (1. - dt*( 0.0 )) ;
 DPsim = DPsim  / (1. - dt*( 0.0 )) ;
 Dadp = Dadp  / (1. - dt*( 0.0 )) ;
 DNADHm = DNADHm  / (1. - dt*( 0.0 )) ;
 DN1 = DN1  / (1. - dt*( ( tmsb )*( ( ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) )*( 1.0 ) ) ) )) ;
 DN2 = DN2  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * exo_k1 * mod_cmd + km1 ) )*( 1.0 ) ) ) ) )) ;
 DN3 = DN3  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * km1 + exo_k1 * mod_cmd ) )*( 1.0 ) ) ) ) )) ;
 DN4 = DN4  / (1. - dt*( ( tmsb )*( ( ( - ( ( 3.0 * km1 + u1 ) )*( 1.0 ) ) ) ) )) ;
 DN5 = DN5  / (1. - dt*( ( tmsb )*( ( ( - ( ( r1 + rm2b ) )*( 1.0 ) ) ) ) )) ;
 DN6 = DN6  / (1. - dt*( ( tmsb )*( ( ( - ( ( rm3 + r2 ) )*( 1.0 ) ) ) ) )) ;
 DNF = DNF  / (1. - dt*( ( tmsb )*( ( ( - ( u2 )*( 1.0 ) ) ) ) )) ;
 DNR = DNR  / (1. - dt*( ( tmsb )*( ( ( - ( u3 )*( 1.0 ) ) ) ) )) ;
 DIns = DIns  / (1. - dt*( ( - ( fb )*( 1.0 ) ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    c = c - dt*(- ( ( fcyt )*( ( Jmem + Jer + ( delta )*( Jmito ) ) ) ) ) ;
    cer = cer - dt*(- ( ( ( - fer )*( sigmav ) )*( Jer ) ) ) ;
    cmd = cmd + (1. - exp(dt*(( fmd )*( ( ( - ( B )*( ( 1.0 ) ) ) ) ))))*(- ( ( fmd )*( ( JL - ( B )*( ( ( - c ) ) ) ) ) ) / ( ( fmd )*( ( ( - ( B )*( ( 1.0 ) ) ) ) ) ) - cmd) ;
    g6p = g6p - dt*(- ( Jgk_ms - pfk_ms ) ) ;
    fbp = fbp - dt*(- ( pfk_ms - ( 0.5 )*( Jgpdh ) ) ) ;
    ADPm = ADPm - dt*(- ( ( gamma )*( ( JANT - JF1F0 ) ) ) ) ;
    cam = cam - dt*(- ( ( - fmito )*( Jmito ) ) ) ;
    Psim = Psim - dt*(- ( ( ( JHres - JHatp - JANT - JHleak - JNaCa - ( 2.0 )*( Juni ) ) ) / Cmito ) ) ;
    adp = adp - dt*(- ( ( ( ( - delta )*( JANT ) + Jhyd ) ) / taua ) ) ;
    NADHm = NADHm - dt*(- ( ( gamma )*( ( JPDH - JO ) ) ) ) ;
    N1 = N1 + (1. - exp(dt*(( tmsb )*( ( ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) )*( 1.0 ) ) ))))*(- ( ( tmsb )*( ( ( km1 )*( N2 ) + ( r1 )*( N5 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 3.0 )*( exo_k1 ) )*( mod_cmd ) + rm1 ) )*( 1.0 ) ) ) ) - N1) ;
    N2 = N2 + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 2.0 * exo_k1 * mod_cmd + km1 ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( ( 3.0 )*( exo_k1 ) )*( mod_cmd ) )*( N1 ) + ( ( 2.0 )*( km1 ) )*( N3 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( ( 2.0 )*( exo_k1 ) )*( mod_cmd ) + km1 ) )*( 1.0 ) ) ) ) ) - N2) ;
    N3 = N3 + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 2.0 * km1 + exo_k1 * mod_cmd ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( ( 2.0 )*( exo_k1 ) )*( mod_cmd ) )*( N2 ) + ( ( 3.0 )*( km1 ) )*( N4 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 2.0 )*( km1 ) + ( exo_k1 )*( mod_cmd ) ) )*( 1.0 ) ) ) ) ) - N3) ;
    N4 = N4 + (1. - exp(dt*(( tmsb )*( ( ( - ( ( 3.0 * km1 + u1 ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( ( exo_k1 )*( mod_cmd ) )*( N3 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( ( 3.0 )*( km1 ) + u1 ) )*( 1.0 ) ) ) ) ) - N4) ;
    N5 = N5 + (1. - exp(dt*(( tmsb )*( ( ( - ( ( r1 + rm2b ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( rm1 )*( N1 ) + ( r2 )*( N6 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( r1 + rm2b ) )*( 1.0 ) ) ) ) ) - N5) ;
    N6 = N6 + (1. - exp(dt*(( tmsb )*( ( ( - ( ( rm3 + r2 ) )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( r3 + ( rm2b )*( N5 ) ) ) ) / ( ( tmsb )*( ( ( - ( ( rm3 + r2 ) )*( 1.0 ) ) ) ) ) - N6) ;
    NF = NF + (1. - exp(dt*(( tmsb )*( ( ( - ( u2 )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( u1 )*( N4 ) ) ) ) / ( ( tmsb )*( ( ( - ( u2 )*( 1.0 ) ) ) ) ) - NF) ;
    NR = NR + (1. - exp(dt*(( tmsb )*( ( ( - ( u3 )*( 1.0 ) ) ) ))))*(- ( ( tmsb )*( ( ( u2 )*( NF ) ) ) ) / ( ( tmsb )*( ( ( - ( u3 )*( 1.0 ) ) ) ) ) - NR) ;
    Ins = Ins + (1. - exp(dt*(( - ( fb )*( 1.0 ) ))))*(- ( ( JIS ) / vc ) / ( ( - ( fb )*( 1.0 ) ) ) - Ins) ;
   }
  return 0;
}
 
static int _ode_count(int _type){ return 19;}
 
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
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 19; ++_i) {
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

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  ADPm = ADPm0;
  Ins = Ins0;
  NR = NR0;
  NF = NF0;
  N6 = N60;
  N5 = N50;
  N4 = N40;
  N3 = N30;
  N2 = N20;
  N1 = N10;
  NADHm = NADHm0;
  Psim = Psim0;
  adp = adp0;
  cam = cam0;
  cmd = cmd0;
  cer = cer0;
  c = c0;
  fbp = fbp0;
  g6p = g6p0;
 {
   t_ = 0.0 ;
   dir = 0.0 ;
   temp = 0.0 ;
   vmd = 4.2e-3 ;
   vcell = 1.15 ;
   alpha = 5.18e-6 ;
   B = 1.0 ;
   cmd = 0.4188629403487558 ;
   c = 0.0630015242008439 ;
   kpmca = 0.2 ;
   cbas = 0.05 ;
   kserca2b = 0.01 ;
   kserca3 = 0.1 ;
   per = 0.0002 ;
   cer = 81.57023672312617 ;
   phigk = 0.3 ;
   g6p = 244.936858732948 ;
   KGPDH = 0.0005 ;
   kappa = 0.001 ;
   Jgk = 0.4 ;
   fbp = 0.08283840527865462 ;
   ADPm = 13.53015038508978 ;
   fcyt = 0.01 ;
   delta = 3.9 / 53.2 ;
   p23 = 0.01 ;
   cam = 0.01102007399722167 ;
   p24 = 0.016 ;
   psim = 151.1015153147079 ;
   p21 = 0.04 ;
   p22 = 1.1 ;
   fer = 0.01 ;
   sigmav = 30.0 ;
   fmd = 0.01 ;
   lambda = 0.06 ;
   VmaxPFK = 5.0 ;
   weight1 = 1.0 ;
   topa1 = 0.0 ;
   bottom1 = 1.0 ;
   atot = 2500.0 ;
   adp = 1913.096601466651 ;
   k4 = 150.0 ;
   k3 = 50000.0 ;
   f43 = 20.0 ;
   k2 = 1.0 ;
   f42 = 20.0 ;
   f23 = 0.2 ;
   amp = 500.0 ;
   k1 = 30.0 ;
   f41 = 20.0 ;
   f13 = 0.02 ;
   gamma = 0.001 ;
   p19 = 0.35 ;
   Amtot = 15.0 ;
   p20 = 2.0 ;
   FRT = 96480.0 / ( 310.16 * 8315.0 ) ;
   p16 = 35.0 ;
   p13 = 10.0 ;
   p14 = 190.0 ;
   p15 = 8.5 ;
   fmito = 0.01 ;
   p8 = 7.0 ;
   NADHm = 0.02908310367935971 ;
   p9 = 0.1 ;
   p10 = 177.0 ;
   p11 = 5.0 ;
   p17 = 0.002 ;
   p18 = - 0.03 ;
   Cmito = 1.8 ;
   p1 = 400.0 ;
   p2 = 1.0 ;
   p3 = 0.01 ;
   NADmtot = 10.0 ;
   Jgpdh_bas = 0.0005 ;
   p4 = 0.6 ;
   p5 = 0.1 ;
   p6 = 177.0 ;
   p7 = 5.0 ;
   vm = - 6.0 ;
   sm = 10.0 ;
   vCa = 25.0 ;
   raL = 0.5 ;
   khyd = 0.00005 ;
   JhydSS = 0.00005 ;
   taua = 5.0 ;
   tmsb = 0.001 ;
   u1 = 2000.0 ;
   u2 = 3.0 ;
   u3 = 0.02 ;
   N1 = 4.627586868810905 ;
   N2 = 0.2262327588817945 ;
   N3 = 0.003661670524646639 ;
   N4 = 2.595179480355916e-06 ;
   N5 = 7.762125378310579 ;
   N6 = 274.1666227230976 ;
   NF = 0.00172689211245988 ;
   NR = 0.3002686554719045 ;
   gthresh = 40.0 ;
   Kp2 = 2.3 ;
   Kp = 2.3 ;
   r30 = 1.205 ;
   factor = 14.0 ;
   amplify = 1.0 ;
   bas_r3 = 0.032 ;
   rm3 = 0.0001 ;
   rb = 0.002 ;
   knockoutdb = 0.0 ;
   sombarb = 50.0 ;
   ssomb = 15.0 ;
   r1 = 0.6 ;
   rm1 = 1.0 ;
   km1 = 100.0 ;
   bas_cmd = 0.06935 ;
   max_cmd = 32.0 ;
   cmdp = 4.0 ;
   kcmd = 3.0 ;
   exo_k1 = 20.0 ;
   vc = 1e-13 ;
   fb = 2000.0 ;
   Ins = 48.04298494148047 ;
   v = - 71.33779976819424 ;
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
   minf = 1.0 / ( 1.0 + exp ( ( vm - v ) / sm ) ) ;
   iCa = gCa * nCa * minf * ( v - vCa ) ;
   iCaL = raL * iCa ;
   iCaR = ( 1.0 - raL ) * iCa ;
   vmdcyt = vmd / vcell ;
   JL = - alpha * iCaL / vmd ;
   JR = - alpha * iCaR / vcell ;
   Jmem = JR + vmdcyt * B * ( cmd - c ) - kpmca * ( c - cbas ) ;
   Jserca = kserca2b + kserca3 * c ;
   Jleak = per * ( cer - c ) ;
   Jer = ( Jleak - Jserca ) ;
   f6p = phigk * g6p ;
   Jgpdh = KGPDH * sqrt ( fbp ) ;
   Jgk_ms = kappa * Jgk ;
   JNaCa = ( p23 / c ) * cam * exp ( p24 * Psim ) ;
   Juni = ( p21 * psim - p22 ) * pow ( c , 2.0 ) ;
   Jmito = JNaCa - Juni ;
   ATPm = Amtot - ADPm ;
   RATm = ATPm / ADPm ;
   JANT = p19 * ( RATm / ( RATm + p20 ) ) / exp ( - 0.5 * FRT * Psim ) ;
   b2 = ( p16 * p13 ) / ( p13 + ATPm ) ;
   JF1F0 = b2 / ( 1.0 + exp ( ( p14 - Psim ) / p15 ) ) ;
   JHatp = 3.0 * JF1F0 ;
   MM2 = p8 * NADHm / ( p9 + NADHm ) ;
   JHres = MM2 / ( 1.0 + exp ( ( Psim - p10 ) / p11 ) ) ;
   JHleak = p17 * Psim + p18 ;
   NADm = NADmtot - NADHm ;
   JPDH = ( p1 / ( p2 + NADHm / NADm ) ) * ( cam / ( p3 + cam ) ) * ( Jgpdh + Jgpdh_bas ) ;
   MM1 = p4 * NADHm / ( p5 + NADHm ) ;
   JO = MM1 / ( 1.0 + exp ( ( Psim - p6 ) / p7 ) ) ;
   atp = atot - adp ;
   Jhyd = ( khyd * c + JhydSS ) * atp ;
   weight1 = 1.0 ;
   topa1 = 0.0 ;
   bottom1 = 1.0 ;
   weight2 = pow ( atp , 2.0 ) / k4 ;
   topa2 = topa1 ;
   bottom2 = bottom1 + weight2 ;
   weight3 = pow ( f6p , 2.0 ) / k3 ;
   topa3 = topa2 + weight3 ;
   bottom3 = bottom2 + weight3 ;
   weight4 = pow ( f6p * atp , 2.0 ) / ( f43 * k3 * k4 ) ;
   topa4 = topa3 + weight4 ;
   bottom4 = bottom3 + weight4 ;
   weight5 = fbp / k2 ;
   topa5 = topa4 ;
   bottom5 = bottom4 + weight5 ;
   weight6 = ( fbp * pow ( atp , 2.0 ) ) / ( k2 * k4 * f42 ) ;
   topa6 = topa5 ;
   bottom6 = bottom5 + weight6 ;
   weight7 = ( fbp * pow ( f6p , 2.0 ) ) / ( k2 * k3 * f23 ) ;
   topa7 = topa6 + weight7 ;
   bottom7 = bottom6 + weight7 ;
   weight8 = ( fbp * pow ( f6p , 2.0 ) * pow ( atp , 2.0 ) ) / ( k2 * k3 * k4 * f23 * f42 * f43 ) ;
   topa8 = topa7 + weight8 ;
   bottom8 = bottom7 + weight8 ;
   weight9 = amp / k1 ;
   topa9 = topa8 ;
   bottom9 = bottom8 + weight9 ;
   weight10 = ( amp * pow ( atp , 2.0 ) ) / ( k1 * k4 * f41 ) ;
   topa10 = topa9 ;
   bottom10 = bottom9 + weight10 ;
   weight11 = ( amp * pow ( f6p , 2.0 ) ) / ( k1 * k3 * f13 ) ;
   topa11 = topa10 + weight11 ;
   bottom11 = bottom10 + weight11 ;
   weight12 = ( amp * pow ( f6p , 2.0 ) * pow ( atp , 2.0 ) ) / ( k1 * k3 * k4 * f13 * f41 * f43 ) ;
   topa12 = topa11 + weight12 ;
   bottom12 = bottom11 + weight12 ;
   weight13 = ( amp * fbp ) / ( k1 * k2 ) ;
   topa13 = topa12 ;
   bottom13 = bottom12 + weight13 ;
   weight14 = ( amp * fbp * pow ( atp , 2.0 ) ) / ( k1 * k2 * k4 * f42 * f41 ) ;
   topa14 = topa13 ;
   bottom14 = bottom13 + weight14 ;
   weight15 = ( amp * fbp * pow ( f6p , 2.0 ) ) / ( k1 * k2 * k3 * f23 * f13 ) ;
   topa15 = topa14 ;
   topb = weight15 ;
   bottom15 = bottom14 + weight15 ;
   weight16 = ( amp * fbp * pow ( f6p , 2.0 ) * pow ( atp , 2.0 ) ) / ( k1 * k2 * k3 * k4 * f23 * f13 * f42 * f41 * f43 ) ;
   topa16 = topa15 + weight16 ;
   bottom16 = bottom15 + weight16 ;
   pfk = ( lambda * VmaxPFK * topa16 + VmaxPFK * topb ) / bottom16 ;
   pfk_ms = kappa * pfk ;
   r20 = 0.004 / ( 1.0 + exp ( - G + gthresh ) ) + 0.006 ;
   ampfactor = factor * pow ( JO , 2.0 ) ;
   r3 = bas_r3 + amplify * ampfactor * r30 * c / ( c + Kp ) ;
   r2 = r20 * c / ( c + Kp2 ) ;
   rm2b = ( 1.0 - knockoutdb ) * rb / ( 1.0 + exp ( - ( Sst - sombarb ) / ssomb ) ) + knockoutdb * 0.001 ;
   mod_cmd = bas_cmd + max_cmd * pow ( cmd , cmdp ) / ( pow ( cmd , cmdp ) + pow ( kcmd , cmdp ) ) ;
   JIS = tmsb * u3 * NR * 0.0016 ;
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(c) - _p;  _dlist1[0] = &(Dc) - _p;
 _slist1[1] = &(cer) - _p;  _dlist1[1] = &(Dcer) - _p;
 _slist1[2] = &(cmd) - _p;  _dlist1[2] = &(Dcmd) - _p;
 _slist1[3] = &(g6p) - _p;  _dlist1[3] = &(Dg6p) - _p;
 _slist1[4] = &(fbp) - _p;  _dlist1[4] = &(Dfbp) - _p;
 _slist1[5] = &(ADPm) - _p;  _dlist1[5] = &(DADPm) - _p;
 _slist1[6] = &(cam) - _p;  _dlist1[6] = &(Dcam) - _p;
 _slist1[7] = &(Psim) - _p;  _dlist1[7] = &(DPsim) - _p;
 _slist1[8] = &(adp) - _p;  _dlist1[8] = &(Dadp) - _p;
 _slist1[9] = &(NADHm) - _p;  _dlist1[9] = &(DNADHm) - _p;
 _slist1[10] = &(N1) - _p;  _dlist1[10] = &(DN1) - _p;
 _slist1[11] = &(N2) - _p;  _dlist1[11] = &(DN2) - _p;
 _slist1[12] = &(N3) - _p;  _dlist1[12] = &(DN3) - _p;
 _slist1[13] = &(N4) - _p;  _dlist1[13] = &(DN4) - _p;
 _slist1[14] = &(N5) - _p;  _dlist1[14] = &(DN5) - _p;
 _slist1[15] = &(N6) - _p;  _dlist1[15] = &(DN6) - _p;
 _slist1[16] = &(NF) - _p;  _dlist1[16] = &(DNF) - _p;
 _slist1[17] = &(NR) - _p;  _dlist1[17] = &(DNR) - _p;
 _slist1[18] = &(Ins) - _p;  _dlist1[18] = &(DIns) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/Beta_Insulin.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "SUFFIX B_Insulin\n"
  ":USEION Ca READ iCa\n"
  ":USEION Ca READ iCaL\n"
  ":USEION Ca READ iCaR\n"
  "RANGE vmd, vcell, alpha, B, kpmca, cbas, kserca2b, kserca3, per, phigk, KGPDH, kappa, Jgk, fcyt, delta, p23 \n"
  "RANGE p24, psim, p21, p22, fer, sigmav, fmd, lambda, VmaxPFK, weight1, topa1, bottom1, atot, k4, k3, f43, k2, f42 \n"
  "RANGE f23, amp, k1, f41, f13, gamma, p19, Amtot, p20, FRT, p16, p13, p14, p15, fmito, p8, p9, p10, p11, p17, p18 \n"
  "RANGE Cmito, p1, p2, p3, NADmtot, Jgpdh_bas, p4, p5, p6, p7, vm, sm, gCa, nCa, vCa, raL, khyd, JhydSS, taua, tmsb \n"
  "RANGE u1, u2, u3, gthresh, Kp2, Kp, r30, factor, amplify, bas_r3, rm3, rb, knockoutdb, sombarb, ssomb, r1, rm1, km1\n"
  "RANGE bas_cmd, max_cmd, cmdp, kcmd, exo_k1, vc, fb, Ins : End of parameters\n"
  "RANGE minf, iCa, iCaL, iCaR, vmdcyt, JL, JR, Jmem, Jserca, Jleak, Jer, f6p, Jgpdh, Jgk_ms, JNaCa, Juni, Jmito, ATPm \n"
  "RANGE RATm, JANT, b2, JF1F0, JHatp, MM2, JHres, JHleak, NADm, JPDH, MM1, JO, atp, Jhyd, weight2, topa2, bottom2, weight3 \n"
  "RANGE topa3, bottom3, weight4, topa4, bottom4, weight5, topa5, bottom5, weight6, topa6, bottom6, weight7, topa7, bottom7 \n"
  "RANGE weight8, topa8, bottom8, weight9, topa9, bottom9, weight10, topa10, bottom10, weight11, topa11, bottom11, weight12 \n"
  "RANGE topa12, bottom12, weight13, topa13, bottom13, weight14, topa14, bottom14, weight15, topa15, topb, bottom15, weight16 \n"
  "RANGE topa16, bottom16, pfk, pfk_ms, r20, ampfactor, r3, r2, rm2b, mod_cmd, JIS \n"
  "RANGE G, Sst\n"
  "RANGE t_, dir, temp\n"
  "}\n"
  "\n"
  "PARAMETER{   \n"
  ": hormone secretion variables\n"
  "t_\n"
  "dir\n"
  "temp\n"
  "G\n"
  "Sst\n"
  "vmd \n"
  "vcell \n"
  "alpha \n"
  "B \n"
  "kpmca \n"
  "cbas \n"
  "kserca2b \n"
  "kserca3 \n"
  "per \n"
  "phigk \n"
  "KGPDH \n"
  "kappa \n"
  "Jgk \n"
  "fcyt \n"
  "delta \n"
  "p23 \n"
  "p24 \n"
  "psim \n"
  "p21 \n"
  "p22 \n"
  "fer \n"
  "sigmav \n"
  "fmd \n"
  "lambda \n"
  "VmaxPFK \n"
  "weight1 \n"
  "topa1 \n"
  "bottom1 \n"
  "atot \n"
  "k4 \n"
  "k3 \n"
  "f43 \n"
  "k2 \n"
  "f42 \n"
  "f23 \n"
  "amp \n"
  "k1 \n"
  "f41 \n"
  "f13 \n"
  "gamma \n"
  "p19 \n"
  "Amtot \n"
  "p20 \n"
  "FRT\n"
  "p16 \n"
  "p13 \n"
  "p14 \n"
  "p15 \n"
  "fmito \n"
  "p8 \n"
  "p9 \n"
  "p10 \n"
  "p11 \n"
  "p17 \n"
  "p18 \n"
  "Cmito \n"
  "p1 \n"
  "p2 \n"
  "p3 \n"
  "NADmtot \n"
  "Jgpdh_bas \n"
  "p4 \n"
  "p5\n"
  "p6 \n"
  "p7 \n"
  "vm \n"
  "sm \n"
  "gCa \n"
  "nCa \n"
  "vCa \n"
  "raL \n"
  "khyd \n"
  "JhydSS \n"
  "taua \n"
  "tmsb \n"
  "u1 \n"
  "u2 \n"
  "u3 \n"
  "gthresh \n"
  "Kp2 \n"
  "Kp \n"
  "r30 \n"
  "factor\n"
  "amplify \n"
  "bas_r3 \n"
  "rm3 \n"
  "rb \n"
  "knockoutdb \n"
  "sombarb\n"
  "ssomb \n"
  "r1 \n"
  "rm1 \n"
  "km1 \n"
  "bas_cmd \n"
  "max_cmd \n"
  "cmdp  \n"
  "kcmd \n"
  "exo_k1 \n"
  "vc \n"
  "fb \n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "minf\n"
  "iCa \n"
  "iCaL \n"
  "iCaR \n"
  "vmdcyt \n"
  "JL \n"
  "JR \n"
  "Jmem \n"
  "Jserca \n"
  "Jleak\n"
  "Jer \n"
  "f6p \n"
  "Jgpdh \n"
  "Jgk_ms \n"
  "JNaCa \n"
  "Juni\n"
  "Jmito\n"
  "ATPm \n"
  "RATm\n"
  "JANT \n"
  "b2 \n"
  "JF1F0\n"
  "JHatp \n"
  "MM2 \n"
  "JHres \n"
  "JHleak \n"
  "NADm \n"
  "JPDH\n"
  "MM1 \n"
  "JO \n"
  "atp \n"
  "Jhyd \n"
  "weight2 \n"
  "topa2 \n"
  "bottom2 \n"
  "weight3 \n"
  "topa3 \n"
  "bottom3 \n"
  "weight4 \n"
  "topa4 \n"
  "bottom4 \n"
  "weight5 \n"
  "topa5 \n"
  "bottom5 \n"
  "weight6 \n"
  "topa6 \n"
  "bottom6 \n"
  "weight7 \n"
  "topa7 \n"
  "bottom7 \n"
  "weight8 \n"
  "topa8 \n"
  "bottom8 \n"
  "weight9 \n"
  "topa9 \n"
  "bottom9 \n"
  "weight10 \n"
  "topa10 \n"
  "bottom10 \n"
  "weight11 \n"
  "topa11 \n"
  "bottom11\n"
  "weight12 \n"
  "topa12 \n"
  "bottom12 \n"
  "weight13 \n"
  "topa13\n"
  "bottom13 \n"
  "weight14 \n"
  "topa14 \n"
  "bottom14 \n"
  "weight15 \n"
  "topa15 \n"
  "topb \n"
  "bottom15 \n"
  "weight16 \n"
  "topa16 \n"
  "bottom16 \n"
  "pfk \n"
  "pfk_ms \n"
  "r20 \n"
  "ampfactor \n"
  "r3 \n"
  "r2 \n"
  "rm2b \n"
  "mod_cmd \n"
  "JIS \n"
  "v : This is the voltage when I run h.initial.....\n"
  "}\n"
  "\n"
  "STATE{\n"
  "c\n"
  "cer\n"
  "cmd\n"
  "g6p\n"
  "fbp \n"
  "ADPm\n"
  "cam\n"
  "Psim\n"
  "adp\n"
  "NADHm\n"
  "N1\n"
  "N2\n"
  "N3\n"
  "N4\n"
  "N5\n"
  "N6\n"
  "NF\n"
  "NR\n"
  "Ins\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "t_ = 0\n"
  "dir = 0\n"
  "temp = 0\n"
  "vmd = 4.2e-3\n"
  "vcell = 1.15\n"
  "alpha = 5.18e-6\n"
  "B = 1\n"
  "cmd = 0.4188629403487558\n"
  "c = 0.0630015242008439\n"
  "kpmca = 0.2\n"
  "cbas = 0.05\n"
  "kserca2b = 0.01\n"
  "kserca3 = 0.1\n"
  "per = 0.0002\n"
  "cer = 81.57023672312617\n"
  "phigk = 0.3\n"
  "g6p = 244.936858732948\n"
  "KGPDH = 0.0005\n"
  "kappa = 0.001\n"
  "Jgk = 0.4\n"
  "fbp = 0.08283840527865462\n"
  "ADPm = 13.53015038508978\n"
  "fcyt = 0.01\n"
  "delta = 3.9/53.2 : There is an exclamation point before the delta in the model link. idk why\n"
  "p23 = 0.01\n"
  "cam = 0.01102007399722167\n"
  "p24 = 0.016\n"
  "psim = 151.1015153147079\n"
  "p21 = 0.04\n"
  "p22 = 1.1\n"
  "fer = 0.01\n"
  "sigmav = 30\n"
  "fmd = 0.01\n"
  "lambda = 0.06\n"
  "VmaxPFK = 5\n"
  "weight1 = 1\n"
  "topa1 = 0\n"
  "bottom1 = 1\n"
  "atot = 2500\n"
  "adp = 1913.096601466651\n"
  "k4 = 150\n"
  "k3 = 50000\n"
  "f43 = 20\n"
  "k2 = 1\n"
  "f42 = 20\n"
  "f23 = 0.2\n"
  "amp = 500\n"
  "k1 = 30\n"
  "f41 = 20\n"
  "f13 = 0.02\n"
  "gamma = 0.001\n"
  "p19 = 0.35\n"
  "Amtot = 15\n"
  "p20 = 2\n"
  "FRT = 96480/(310.16*8315)\n"
  "p16 = 35\n"
  "p13 = 10\n"
  "p14 = 190\n"
  "p15 = 8.5\n"
  "fmito = 0.01\n"
  "p8 = 7\n"
  "NADHm = 0.02908310367935971\n"
  "p9 = 0.1\n"
  "p10 = 177\n"
  "p11 = 5\n"
  "p17 = 0.002\n"
  "p18 = -0.03\n"
  "Cmito = 1.8\n"
  "p1 = 400\n"
  "p2 = 1\n"
  "p3 = 0.01\n"
  "NADmtot = 10\n"
  "Jgpdh_bas = 0.0005\n"
  "p4 = 0.6\n"
  "p5 = 0.1\n"
  "p6 = 177\n"
  "p7 = 5\n"
  "vm = -6\n"
  "sm = 10\n"
  "vCa = 25\n"
  "raL = 0.5\n"
  "khyd = 0.00005\n"
  "JhydSS = 0.00005\n"
  "taua = 5\n"
  "tmsb = 0.001\n"
  "u1 = 2000\n"
  "u2 = 3\n"
  "u3 = 0.02\n"
  "N1 = 4.627586868810905\n"
  "N2 = 0.2262327588817945\n"
  "N3 = 0.003661670524646639\n"
  "N4 = 2.595179480355916e-06\n"
  "N5 = 7.762125378310579\n"
  "N6 = 274.1666227230976\n"
  "NF = 0.00172689211245988\n"
  "NR = 0.3002686554719045\n"
  "gthresh = 40\n"
  "Kp2 = 2.3\n"
  "Kp = 2.3\n"
  "r30 = 1.205\n"
  "factor = 14\n"
  "amplify = 1\n"
  "bas_r3 = 0.032\n"
  "rm3 = 0.0001\n"
  "rb = 0.002\n"
  "knockoutdb = 0\n"
  "sombarb = 50\n"
  "ssomb = 15\n"
  "r1 = 0.6\n"
  "rm1 = 1\n"
  "km1 = 100\n"
  "bas_cmd = 0.06935\n"
  "max_cmd = 32\n"
  "cmdp = 4\n"
  "kcmd = 3\n"
  "exo_k1 = 20\n"
  "vc = 1e-13\n"
  "fb = 2000\n"
  "Ins = 48.04298494148047\n"
  "v = -71.33779976819424\n"
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
  "minf = 1/(1 + exp((vm - v)/sm))\n"
  "iCa = gCa * nCa * minf * (v - vCa)\n"
  "iCaL = raL * iCa\n"
  "iCaR = (1 - raL) * iCa\n"
  "vmdcyt = vmd/vcell\n"
  "JL = -alpha * iCaL/vmd\n"
  "JR = -alpha * iCaR/vcell\n"
  "Jmem = JR + vmdcyt * B * (cmd - c) - kpmca * (c - cbas)\n"
  "Jserca = kserca2b + kserca3 * c\n"
  "Jleak = per * (cer - c)\n"
  "Jer = (Jleak - Jserca)\n"
  "f6p = phigk * g6p\n"
  "Jgpdh = KGPDH * sqrt(fbp) \n"
  "Jgk_ms = kappa * Jgk\n"
  "JNaCa = (p23/c) * cam * exp(p24 * Psim)\n"
  "Juni=(p21 * psim - p22) * pow(c,2)\n"
  "Jmito = JNaCa - Juni\n"
  "ATPm = Amtot - ADPm\n"
  "RATm = ATPm/ADPm\n"
  "JANT = p19 * (RATm/(RATm + p20))/exp(-0.5 * FRT * Psim)\n"
  "b2 = (p16 * p13)/(p13 + ATPm)\n"
  "JF1F0 = b2/(1.0 + exp((p14 - Psim)/p15))\n"
  "JHatp = 3 * JF1F0\n"
  "MM2 = p8 * NADHm/(p9 + NADHm)\n"
  "JHres = MM2/(1 + exp((Psim - p10)/p11))\n"
  "JHleak = p17 * Psim + p18\n"
  "NADm = NADmtot - NADHm\n"
  "JPDH = (p1/(p2 + NADHm/NADm)) * (cam/(p3 + cam)) * (Jgpdh + Jgpdh_bas)\n"
  "MM1 = p4 * NADHm/(p5 + NADHm)\n"
  "JO = MM1/(1 + exp((Psim - p6)/p7))\n"
  "atp = atot - adp\n"
  "Jhyd = (khyd * c + JhydSS) * atp \n"
  "weight1 = 1\n"
  "topa1 = 0\n"
  "bottom1 = 1\n"
  "weight2 = pow(atp,2)/k4\n"
  "topa2 = topa1\n"
  "bottom2 = bottom1 + weight2\n"
  "weight3 = pow(f6p,2)/k3\n"
  "topa3 = topa2 + weight3\n"
  "bottom3 = bottom2 + weight3\n"
  "weight4 = pow(f6p * atp,2)/(f43 * k3 * k4)\n"
  "topa4 = topa3 + weight4\n"
  "bottom4 = bottom3 + weight4\n"
  "weight5 = fbp/k2\n"
  "topa5 = topa4\n"
  "bottom5 = bottom4 + weight5\n"
  "weight6 = (fbp * pow(atp,2))/(k2 * k4 * f42)\n"
  "topa6 = topa5\n"
  "bottom6 = bottom5 + weight6\n"
  "weight7 = (fbp * pow(f6p,2))/(k2 * k3 * f23)\n"
  "topa7 = topa6 + weight7\n"
  "bottom7 = bottom6 + weight7\n"
  "weight8 = (fbp * pow(f6p,2) * pow(atp,2))/(k2 * k3 * k4 * f23 * f42 * f43)\n"
  "topa8 = topa7 + weight8\n"
  "bottom8 = bottom7 + weight8\n"
  "weight9 = amp/k1\n"
  "topa9 = topa8\n"
  "bottom9 = bottom8 + weight9\n"
  "weight10 = (amp * pow(atp,2))/(k1 * k4 * f41)\n"
  "topa10 = topa9\n"
  "bottom10 = bottom9 + weight10\n"
  "weight11 = (amp * pow(f6p,2))/(k1 * k3 * f13)\n"
  "topa11 = topa10 + weight11\n"
  "bottom11 = bottom10 + weight11\n"
  "weight12 = (amp * pow(f6p,2) * pow(atp,2))/(k1 * k3 * k4 * f13 * f41 * f43)\n"
  "topa12 = topa11 + weight12\n"
  "bottom12 = bottom11 + weight12\n"
  "weight13 = (amp * fbp)/(k1 * k2)\n"
  "topa13 = topa12\n"
  "bottom13 = bottom12 + weight13\n"
  "weight14 = (amp * fbp * pow(atp,2))/(k1 * k2 * k4 * f42 * f41)\n"
  "topa14 = topa13\n"
  "bottom14 = bottom13 + weight14\n"
  "weight15 = (amp * fbp * pow(f6p,2))/(k1 * k2 * k3 * f23 * f13)\n"
  "topa15 = topa14\n"
  "topb = weight15\n"
  "bottom15 = bottom14 + weight15\n"
  "weight16 = (amp * fbp * pow(f6p,2) * pow(atp,2))/(k1 * k2 * k3 * k4 * f23 * f13 * f42 * f41 * f43)\n"
  "topa16 = topa15 + weight16\n"
  "bottom16 = bottom15 + weight16\n"
  "pfk = (lambda * VmaxPFK * topa16 + VmaxPFK * topb)/bottom16\n"
  "pfk_ms = kappa * pfk \n"
  "r20 = 0.004/(1 + exp(-G + gthresh)) + 0.006 : Alpha stimulating beta\n"
  "ampfactor = factor * pow(JO,2)\n"
  "r3 = bas_r3 + amplify * ampfactor * r30 *c/(c + Kp)\n"
  "r2 = r20 * c/(c + Kp2)\n"
  "rm2b = (1 - knockoutdb) * rb/(1 + exp(-(Sst - sombarb)/ssomb)) + knockoutdb * 0.001\n"
  "SOLVE states METHOD cnexp : Put equations that need to have ODE's solved to evaluate under here\n"
  "mod_cmd = bas_cmd + max_cmd * pow(cmd,cmdp)/(pow(cmd,cmdp) + pow(kcmd,cmdp))\n"
  "JIS = tmsb * u3 * NR * 0.0016\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "c' = fcyt * (Jmem + Jer + delta * Jmito)\n"
  "cer' = -fer * sigmav * Jer\n"
  "cmd' = fmd * (JL - B * (cmd - c)) \n"
  "g6p' = Jgk_ms - pfk_ms\n"
  "fbp' = pfk_ms - 0.5 * Jgpdh \n"
  "ADPm'= gamma * (JANT - JF1F0)\n"
  "cam' = -fmito * Jmito\n"
  "Psim'=(JHres - JHatp - JANT - JHleak - JNaCa - 2 * Juni)/Cmito\n"
  "adp' = (-delta * JANT + Jhyd)/taua\n"
  "NADHm' = gamma * (JPDH - JO)\n"
  "N1' = tmsb * (-(3 * exo_k1 * mod_cmd + rm1) * N1 + km1 * N2 + r1 * N5)\n"
  "N2' = tmsb * (3 * exo_k1 * mod_cmd * N1 - (2 * exo_k1 * mod_cmd + km1) * N2 + 2 * km1 * N3)\n"
  "N3' = tmsb * (2 * exo_k1 * mod_cmd * N2 -(2 * km1 + exo_k1 * mod_cmd) * N3 + 3 * km1 * N4)\n"
  "N4' = tmsb * (exo_k1 * mod_cmd * N3 - (3 * km1 + u1) * N4)\n"
  "N5' = tmsb * (rm1 * N1 - (r1 + rm2b) * N5 + r2 * N6)\n"
  "N6' = tmsb * (r3 + rm2b * N5 - (rm3 + r2) * N6)\n"
  "NF' = tmsb * (u1 * N4 - u2 * NF)\n"
  "NR' = tmsb * (u2 * NF - u3 * NR)\n"
  "Ins' = JIS/vc - fb * Ins\n"
  "}\n"
  "\n"
  ;
#endif

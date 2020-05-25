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
 
#define nrn_init _nrn_init__frid
#define _nrn_initial _nrn_initial__frid
#define nrn_cur _nrn_cur__frid
#define _nrn_current _nrn_current__frid
#define nrn_jacob _nrn_jacob__frid
#define nrn_state _nrn_state__frid
#define _net_receive _net_receive__frid 
#define states states__frid 
 
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
#define Cm _p[0]
#define ADPf _p[1]
#define ATP _p[2]
#define ECa _p[3]
#define EK _p[4]
#define ENa _p[5]
#define F _p[6]
#define fi _p[7]
#define gBNa _p[8]
#define gmCaL _p[9]
#define gmCaP _p[10]
#define gmCaT _p[11]
#define gmKATP _p[12]
#define gmKCa _p[13]
#define gmKCaB _p[14]
#define gmKDr _p[15]
#define gmKhe _p[16]
#define gmNa _p[17]
#define hdk _p[18]
#define kCaBK _p[19]
#define kCap _p[20]
#define kci _p[21]
#define kdCaL _p[22]
#define kdCaP _p[23]
#define kdCaT _p[24]
#define kdd _p[25]
#define kdhe _p[26]
#define kdKCaB _p[27]
#define kdkr _p[28]
#define kdNa _p[29]
#define kfCaL _p[30]
#define kfCaP _p[31]
#define kfCaT _p[32]
#define kfhe _p[33]
#define kfKCaB _p[34]
#define kfNa _p[35]
#define KiCa _p[36]
#define KKCa _p[37]
#define kNar _p[38]
#define kpi _p[39]
#define kre _p[40]
#define ksg _p[41]
#define kshift _p[42]
#define ksi _p[43]
#define ktd _p[44]
#define ktt _p[45]
#define newk _p[46]
#define Ni _p[47]
#define PmCaP _p[48]
#define RTdF _p[49]
#define tdCaP _p[50]
#define tdCaT _p[51]
#define tfKCaB _p[52]
#define tfKhe _p[53]
#define tfNa _p[54]
#define VBKo _p[55]
#define VdCaL _p[56]
#define VdCaP _p[57]
#define VdCaT _p[58]
#define Vdhe _p[59]
#define Vdkr _p[60]
#define VdNa _p[61]
#define VfCaL _p[62]
#define VfCaP _p[63]
#define VfCaT _p[64]
#define Vfhe _p[65]
#define VfKCaB _p[66]
#define VfNa _p[67]
#define Vi _p[68]
#define Vpi _p[69]
#define tdKr _p[70]
#define tdNa _p[71]
#define tf1CaL _p[72]
#define tfCaP _p[73]
#define tfCaT _p[74]
#define tf2CaL _p[75]
#define test _p[76]
#define dKCa _p[77]
#define ICaL _p[78]
#define ICaP _p[79]
#define ICaT _p[80]
#define IKATP _p[81]
#define IKCa _p[82]
#define IKCaB _p[83]
#define IKDr _p[84]
#define IKher _p[85]
#define INa _p[86]
#define INab _p[87]
#define IPCa _p[88]
#define IS _p[89]
#define MgADP _p[90]
#define OKATP _p[91]
#define tdCaL _p[92]
#define VdKCaB _p[93]
#define V_real _p[94]
#define Cac _p[95]
#define IntCa _p[96]
#define dKr _p[97]
#define Vp _p[98]
#define dCaL _p[99]
#define dCaP _p[100]
#define fCaP _p[101]
#define f1CaL _p[102]
#define f2CaL _p[103]
#define dNa _p[104]
#define fNa _p[105]
#define dCaT _p[106]
#define fCaT _p[107]
#define dKCaB _p[108]
#define fKCaB _p[109]
#define dKhe _p[110]
#define fKhe _p[111]
#define In _p[112]
#define iCaL _p[113]
#define iCaT _p[114]
#define iCaP _p[115]
#define iBK _p[116]
#define iNa _p[117]
#define iNaB _p[118]
#define iHERG _p[119]
#define iPCa _p[120]
#define iKCa _p[121]
#define iKATP _p[122]
#define iKDR _p[123]
#define Vmio _p[124]
#define DCac _p[125]
#define DIntCa _p[126]
#define DdKr _p[127]
#define DVp _p[128]
#define DdCaL _p[129]
#define DdCaP _p[130]
#define DfCaP _p[131]
#define Df1CaL _p[132]
#define Df2CaL _p[133]
#define DdNa _p[134]
#define DfNa _p[135]
#define DdCaT _p[136]
#define DfCaT _p[137]
#define DdKCaB _p[138]
#define DfKCaB _p[139]
#define DdKhe _p[140]
#define DfKhe _p[141]
#define DIn _p[142]
#define Vmi _p[143]
#define DVmi _p[144]
#define v _p[145]
#define _g _p[146]
#define _ion_Vmi	*_ppvar[0]._pval
#define _style_Vm	*((int*)_ppvar[1]._pvoid)
#define _ion_iCaL	*_ppvar[2]._pval
#define _ion_iCaT	*_ppvar[3]._pval
#define _ion_iCaP	*_ppvar[4]._pval
#define _ion_iBK	*_ppvar[5]._pval
#define _ion_iNa	*_ppvar[6]._pval
#define _ion_iNaB	*_ppvar[7]._pval
#define _ion_iHERG	*_ppvar[8]._pval
#define _ion_iPCa	*_ppvar[9]._pval
#define _ion_iKCa	*_ppvar[10]._pval
#define _ion_iKATP	*_ppvar[11]._pval
#define _ion_iKDR	*_ppvar[12]._pval
 
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
 "setdata_frid", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
 static int _thread1data_inuse = 0;
static double _thread1data[17];
#define _gth 0
#define dNai_frid _thread1data[0]
#define dNai _thread[_gth]._pval[0]
#define dKri_frid _thread1data[1]
#define dKri _thread[_gth]._pval[1]
#define dKhei_frid _thread1data[2]
#define dKhei _thread[_gth]._pval[2]
#define dKCaBi_frid _thread1data[3]
#define dKCaBi _thread[_gth]._pval[3]
#define dCaTi_frid _thread1data[4]
#define dCaTi _thread[_gth]._pval[4]
#define dCaPi_frid _thread1data[5]
#define dCaPi _thread[_gth]._pval[5]
#define dCaLi_frid _thread1data[6]
#define dCaLi _thread[_gth]._pval[6]
#define fsi_frid _thread1data[7]
#define fsi _thread[_gth]._pval[7]
#define fNai_frid _thread1data[8]
#define fNai _thread[_gth]._pval[8]
#define fKhei_frid _thread1data[9]
#define fKhei _thread[_gth]._pval[9]
#define fKCaBi_frid _thread1data[10]
#define fKCaBi _thread[_gth]._pval[10]
#define fiCa_frid _thread1data[11]
#define fiCa _thread[_gth]._pval[11]
#define fCaTi_frid _thread1data[12]
#define fCaTi _thread[_gth]._pval[12]
#define fCaPi_frid _thread1data[13]
#define fCaPi _thread[_gth]._pval[13]
#define fCaLi_frid _thread1data[14]
#define fCaLi _thread[_gth]._pval[14]
#define tdKhe_frid _thread1data[15]
#define tdKhe _thread[_gth]._pval[15]
#define tdKCaB_frid _thread1data[16]
#define tdKCaB _thread[_gth]._pval[16]
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double Cac0 = 0;
 static double In0 = 0;
 static double IntCa0 = 0;
 static double Vmi0 = 0;
 static double Vp0 = 0;
 static double delta_t = 0.01;
 static double dKhe0 = 0;
 static double dKCaB0 = 0;
 static double dCaT0 = 0;
 static double dNa0 = 0;
 static double dCaP0 = 0;
 static double dCaL0 = 0;
 static double dKr0 = 0;
 static double fKhe0 = 0;
 static double fKCaB0 = 0;
 static double fCaT0 = 0;
 static double fNa0 = 0;
 static double f2CaL0 = 0;
 static double f1CaL0 = 0;
 static double fCaP0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tdKCaB_frid", &tdKCaB_frid,
 "tdKhe_frid", &tdKhe_frid,
 "dCaLi_frid", &dCaLi_frid,
 "dCaPi_frid", &dCaPi_frid,
 "dCaTi_frid", &dCaTi_frid,
 "dKCaBi_frid", &dKCaBi_frid,
 "dKhei_frid", &dKhei_frid,
 "dKri_frid", &dKri_frid,
 "dNai_frid", &dNai_frid,
 "fCaLi_frid", &fCaLi_frid,
 "fCaPi_frid", &fCaPi_frid,
 "fCaTi_frid", &fCaTi_frid,
 "fiCa_frid", &fiCa_frid,
 "fKCaBi_frid", &fKCaBi_frid,
 "fKhei_frid", &fKhei_frid,
 "fNai_frid", &fNai_frid,
 "fsi_frid", &fsi_frid,
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
 
#define _cvode_ieq _ppvar[13]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"frid",
 "Cm_frid",
 "ADPf_frid",
 "ATP_frid",
 "ECa_frid",
 "EK_frid",
 "ENa_frid",
 "F_frid",
 "fi_frid",
 "gBNa_frid",
 "gmCaL_frid",
 "gmCaP_frid",
 "gmCaT_frid",
 "gmKATP_frid",
 "gmKCa_frid",
 "gmKCaB_frid",
 "gmKDr_frid",
 "gmKhe_frid",
 "gmNa_frid",
 "hdk_frid",
 "kCaBK_frid",
 "kCap_frid",
 "kci_frid",
 "kdCaL_frid",
 "kdCaP_frid",
 "kdCaT_frid",
 "kdd_frid",
 "kdhe_frid",
 "kdKCaB_frid",
 "kdkr_frid",
 "kdNa_frid",
 "kfCaL_frid",
 "kfCaP_frid",
 "kfCaT_frid",
 "kfhe_frid",
 "kfKCaB_frid",
 "kfNa_frid",
 "KiCa_frid",
 "KKCa_frid",
 "kNar_frid",
 "kpi_frid",
 "kre_frid",
 "ksg_frid",
 "kshift_frid",
 "ksi_frid",
 "ktd_frid",
 "ktt_frid",
 "newk_frid",
 "Ni_frid",
 "PmCaP_frid",
 "RTdF_frid",
 "tdCaP_frid",
 "tdCaT_frid",
 "tfKCaB_frid",
 "tfKhe_frid",
 "tfNa_frid",
 "VBKo_frid",
 "VdCaL_frid",
 "VdCaP_frid",
 "VdCaT_frid",
 "Vdhe_frid",
 "Vdkr_frid",
 "VdNa_frid",
 "VfCaL_frid",
 "VfCaP_frid",
 "VfCaT_frid",
 "Vfhe_frid",
 "VfKCaB_frid",
 "VfNa_frid",
 "Vi_frid",
 "Vpi_frid",
 "tdKr_frid",
 "tdNa_frid",
 "tf1CaL_frid",
 "tfCaP_frid",
 "tfCaT_frid",
 "tf2CaL_frid",
 "test_frid",
 "dKCa_frid",
 "ICaL_frid",
 "ICaP_frid",
 "ICaT_frid",
 "IKATP_frid",
 "IKCa_frid",
 "IKCaB_frid",
 "IKDr_frid",
 "IKher_frid",
 "INa_frid",
 "INab_frid",
 "IPCa_frid",
 "IS_frid",
 "MgADP_frid",
 "OKATP_frid",
 "tdCaL_frid",
 "VdKCaB_frid",
 "V_real_frid",
 0,
 0,
 "Cac_frid",
 "IntCa_frid",
 "dKr_frid",
 "Vp_frid",
 "dCaL_frid",
 "dCaP_frid",
 "fCaP_frid",
 "f1CaL_frid",
 "f2CaL_frid",
 "dNa_frid",
 "fNa_frid",
 "dCaT_frid",
 "fCaT_frid",
 "dKCaB_frid",
 "fKCaB_frid",
 "dKhe_frid",
 "fKhe_frid",
 "In_frid",
 0,
 0};
 static Symbol* _Vm_sym;
 static Symbol* _CaL_sym;
 static Symbol* _CaT_sym;
 static Symbol* _CaP_sym;
 static Symbol* _BK_sym;
 static Symbol* _Na_sym;
 static Symbol* _NaB_sym;
 static Symbol* _HERG_sym;
 static Symbol* _PCa_sym;
 static Symbol* _KCa_sym;
 static Symbol* _KATP_sym;
 static Symbol* _KDR_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 147, _prop);
 	/*initialize range parameters*/
 	Cm = 0;
 	ADPf = 0;
 	ATP = 0;
 	ECa = 0;
 	EK = 0;
 	ENa = 0;
 	F = 0;
 	fi = 0;
 	gBNa = 0;
 	gmCaL = 0;
 	gmCaP = 0;
 	gmCaT = 0;
 	gmKATP = 0;
 	gmKCa = 0;
 	gmKCaB = 0;
 	gmKDr = 0;
 	gmKhe = 0;
 	gmNa = 0;
 	hdk = 0;
 	kCaBK = 0;
 	kCap = 0;
 	kci = 0;
 	kdCaL = 0;
 	kdCaP = 0;
 	kdCaT = 0;
 	kdd = 0;
 	kdhe = 0;
 	kdKCaB = 0;
 	kdkr = 0;
 	kdNa = 0;
 	kfCaL = 0;
 	kfCaP = 0;
 	kfCaT = 0;
 	kfhe = 0;
 	kfKCaB = 0;
 	kfNa = 0;
 	KiCa = 0;
 	KKCa = 0;
 	kNar = 0;
 	kpi = 0;
 	kre = 0;
 	ksg = 0;
 	kshift = 0;
 	ksi = 0;
 	ktd = 0;
 	ktt = 0;
 	newk = 0;
 	Ni = 0;
 	PmCaP = 0;
 	RTdF = 0;
 	tdCaP = 0;
 	tdCaT = 0;
 	tfKCaB = 0;
 	tfKhe = 0;
 	tfNa = 0;
 	VBKo = 0;
 	VdCaL = 0;
 	VdCaP = 0;
 	VdCaT = 0;
 	Vdhe = 0;
 	Vdkr = 0;
 	VdNa = 0;
 	VfCaL = 0;
 	VfCaP = 0;
 	VfCaT = 0;
 	Vfhe = 0;
 	VfKCaB = 0;
 	VfNa = 0;
 	Vi = 0;
 	Vpi = 0;
 	tdKr = 0;
 	tdNa = 0;
 	tf1CaL = 0;
 	tfCaP = 0;
 	tfCaT = 0;
 	tf2CaL = 0;
 	test = 0;
 	dKCa = 0;
 	ICaL = 0;
 	ICaP = 0;
 	ICaT = 0;
 	IKATP = 0;
 	IKCa = 0;
 	IKCaB = 0;
 	IKDr = 0;
 	IKher = 0;
 	INa = 0;
 	INab = 0;
 	IPCa = 0;
 	IS = 0;
 	MgADP = 0;
 	OKATP = 0;
 	tdCaL = 0;
 	VdKCaB = 0;
 	V_real = 0;
 	_prop->param = _p;
 	_prop->param_size = 147;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 14, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_Vm_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* Vmi */
 	_ppvar[1]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for Vm */
 prop_ion = need_memb(_CaL_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* iCaL */
 prop_ion = need_memb(_CaT_sym);
 	_ppvar[3]._pval = &prop_ion->param[3]; /* iCaT */
 prop_ion = need_memb(_CaP_sym);
 	_ppvar[4]._pval = &prop_ion->param[3]; /* iCaP */
 prop_ion = need_memb(_BK_sym);
 	_ppvar[5]._pval = &prop_ion->param[3]; /* iBK */
 prop_ion = need_memb(_Na_sym);
 	_ppvar[6]._pval = &prop_ion->param[3]; /* iNa */
 prop_ion = need_memb(_NaB_sym);
 	_ppvar[7]._pval = &prop_ion->param[3]; /* iNaB */
 prop_ion = need_memb(_HERG_sym);
 	_ppvar[8]._pval = &prop_ion->param[3]; /* iHERG */
 prop_ion = need_memb(_PCa_sym);
 	_ppvar[9]._pval = &prop_ion->param[3]; /* iPCa */
 prop_ion = need_memb(_KCa_sym);
 	_ppvar[10]._pval = &prop_ion->param[3]; /* iKCa */
 prop_ion = need_memb(_KATP_sym);
 	_ppvar[11]._pval = &prop_ion->param[3]; /* iKATP */
 prop_ion = need_memb(_KDR_sym);
 	_ppvar[12]._pval = &prop_ion->param[3]; /* iKDR */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _frid_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("Vm", 1.0);
 	ion_reg("CaL", -10000.);
 	ion_reg("CaT", -10000.);
 	ion_reg("CaP", -10000.);
 	ion_reg("BK", -10000.);
 	ion_reg("Na", -10000.);
 	ion_reg("NaB", -10000.);
 	ion_reg("HERG", -10000.);
 	ion_reg("PCa", -10000.);
 	ion_reg("KCa", -10000.);
 	ion_reg("KATP", -10000.);
 	ion_reg("KDR", -10000.);
 	_Vm_sym = hoc_lookup("Vm_ion");
 	_CaL_sym = hoc_lookup("CaL_ion");
 	_CaT_sym = hoc_lookup("CaT_ion");
 	_CaP_sym = hoc_lookup("CaP_ion");
 	_BK_sym = hoc_lookup("BK_ion");
 	_Na_sym = hoc_lookup("Na_ion");
 	_NaB_sym = hoc_lookup("NaB_ion");
 	_HERG_sym = hoc_lookup("HERG_ion");
 	_PCa_sym = hoc_lookup("PCa_ion");
 	_KCa_sym = hoc_lookup("KCa_ion");
 	_KATP_sym = hoc_lookup("KATP_ion");
 	_KDR_sym = hoc_lookup("KDR_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 2);
  _extcall_thread = (Datum*)ecalloc(1, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
  _thread1data_inuse = 0;
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 147, 14);
  hoc_register_dparam_semantics(_mechtype, 0, "Vm_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "#Vm_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "CaL_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "CaT_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "CaP_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "BK_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "Na_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "NaB_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "HERG_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "PCa_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "KCa_ion");
  hoc_register_dparam_semantics(_mechtype, 11, "KATP_ion");
  hoc_register_dparam_semantics(_mechtype, 12, "KDR_ion");
  hoc_register_dparam_semantics(_mechtype, 13, "cvodeieq");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 frid /ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Temp/x86_64/frid.mod\n");
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
   DCac = ( ( fi * ( - iCaL - ICaP - ICaT - ( 2.0 * IPCa ) ) / ( 2.0 * F * Vi ) ) - ( ksg * Cac ) ) ;
   DIntCa = ( 0.001 * Cac ) ;
   DdKr = ( ( dKri - dKr ) / tdKr ) ;
   DVp = - ( ( ICaL + ICaP + ICaT + IKDr + IPCa + IKCa + IKCaB + IKATP + IKher + INab + INa ) / Cm ) ;
   DVmi = - ( ( iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa ) / Cm ) ;
   DdCaL = ( ( dCaLi - dCaL ) / tdCaL ) ;
   DdCaP = ( ( dCaPi - dCaP ) / tdCaP ) ;
   DfCaP = ( ( fCaPi - fCaP ) / tfCaP ) ;
   Df1CaL = ( ( fCaLi - f1CaL ) / tf1CaL ) ;
   Df2CaL = ( ( fCaLi - f2CaL ) / tf2CaL ) ;
   DdNa = ( ( dNai - dNa ) / tdNa ) ;
   DfNa = ( ( fNai - fNa ) / tfNa ) ;
   DdCaT = ( ( dCaTi - dCaT ) / tdCaT ) ;
   DfCaT = ( ( fCaTi - fCaT ) / tfCaT ) ;
   DdKCaB = ( ( dKCaBi - dKCaB ) / tdKCaB ) ;
   DfKCaB = ( ( fKCaBi - fKCaB ) / tfKCaB ) ;
   DdKhe = ( ( dKhei - dKhe ) / tdKhe ) ;
   DfKhe = ( ( fKhei - fKhe ) / tfKhe ) ;
   DIn = ( ( fsi * Ni / Vpi ) - ( kpi * In ) ) ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DCac = DCac  / (1. - dt*( ( ( - ( ( ksg )*( 1.0 ) ) ) ) )) ;
 DIntCa = DIntCa  / (1. - dt*( 0.0 )) ;
 DdKr = DdKr  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdKr ) )) ;
 DVp = DVp  / (1. - dt*( 0.0 )) ;
 DVmi = DVmi  / (1. - dt*( 0.0 )) ;
 DdCaL = DdCaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaL ) )) ;
 DdCaP = DdCaP  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaP ) )) ;
 DfCaP = DfCaP  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfCaP ) )) ;
 Df1CaL = Df1CaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tf1CaL ) )) ;
 Df2CaL = Df2CaL  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tf2CaL ) )) ;
 DdNa = DdNa  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdNa ) )) ;
 DfNa = DfNa  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfNa ) )) ;
 DdCaT = DdCaT  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdCaT ) )) ;
 DfCaT = DfCaT  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfCaT ) )) ;
 DdKCaB = DdKCaB  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdKCaB ) )) ;
 DfKCaB = DfKCaB  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfKCaB ) )) ;
 DdKhe = DdKhe  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tdKhe ) )) ;
 DfKhe = DfKhe  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / tfKhe ) )) ;
 DIn = DIn  / (1. - dt*( ( ( - ( ( kpi )*( 1.0 ) ) ) ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    Cac = Cac + (1. - exp(dt*(( ( - ( ( ksg )*( 1.0 ) ) ) ))))*(- ( ( ( ( ( fi )*( ( - iCaL - ICaP - ICaT - ( ( 2.0 )*( IPCa ) ) ) ) ) / ( 2.0 * F * Vi ) ) ) ) / ( ( ( - ( ( ksg )*( 1.0 ) ) ) ) ) - Cac) ;
    IntCa = IntCa - dt*(- ( ( ( 0.001 )*( Cac ) ) ) ) ;
    dKr = dKr + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdKr ))))*(- ( ( ( ( dKri ) ) / tdKr ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdKr ) ) - dKr) ;
    Vp = Vp - dt*(- ( - ( ( ( ICaL + ICaP + ICaT + IKDr + IPCa + IKCa + IKCaB + IKATP + IKher + INab + INa ) ) / Cm ) ) ) ;
    Vmi = Vmi - dt*(- ( - ( ( ( iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa ) ) / Cm ) ) ) ;
    dCaL = dCaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaL ))))*(- ( ( ( ( dCaLi ) ) / tdCaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaL ) ) - dCaL) ;
    dCaP = dCaP + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaP ))))*(- ( ( ( ( dCaPi ) ) / tdCaP ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaP ) ) - dCaP) ;
    fCaP = fCaP + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfCaP ))))*(- ( ( ( ( fCaPi ) ) / tfCaP ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfCaP ) ) - fCaP) ;
    f1CaL = f1CaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tf1CaL ))))*(- ( ( ( ( fCaLi ) ) / tf1CaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tf1CaL ) ) - f1CaL) ;
    f2CaL = f2CaL + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tf2CaL ))))*(- ( ( ( ( fCaLi ) ) / tf2CaL ) ) / ( ( ( ( ( - 1.0 ) ) ) / tf2CaL ) ) - f2CaL) ;
    dNa = dNa + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdNa ))))*(- ( ( ( ( dNai ) ) / tdNa ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdNa ) ) - dNa) ;
    fNa = fNa + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfNa ))))*(- ( ( ( ( fNai ) ) / tfNa ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfNa ) ) - fNa) ;
    dCaT = dCaT + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdCaT ))))*(- ( ( ( ( dCaTi ) ) / tdCaT ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdCaT ) ) - dCaT) ;
    fCaT = fCaT + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfCaT ))))*(- ( ( ( ( fCaTi ) ) / tfCaT ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfCaT ) ) - fCaT) ;
    dKCaB = dKCaB + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdKCaB ))))*(- ( ( ( ( dKCaBi ) ) / tdKCaB ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdKCaB ) ) - dKCaB) ;
    fKCaB = fKCaB + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfKCaB ))))*(- ( ( ( ( fKCaBi ) ) / tfKCaB ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfKCaB ) ) - fKCaB) ;
    dKhe = dKhe + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tdKhe ))))*(- ( ( ( ( dKhei ) ) / tdKhe ) ) / ( ( ( ( ( - 1.0 ) ) ) / tdKhe ) ) - dKhe) ;
    fKhe = fKhe + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / tfKhe ))))*(- ( ( ( ( fKhei ) ) / tfKhe ) ) / ( ( ( ( ( - 1.0 ) ) ) / tfKhe ) ) - fKhe) ;
    In = In + (1. - exp(dt*(( ( - ( ( kpi )*( 1.0 ) ) ) ))))*(- ( ( ( ( ( fsi )*( Ni ) ) / Vpi ) ) ) / ( ( ( - ( ( kpi )*( 1.0 ) ) ) ) ) - In) ;
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
  Vmi = _ion_Vmi;
  iCaL = _ion_iCaL;
  iCaT = _ion_iCaT;
  iCaP = _ion_iCaP;
  iBK = _ion_iBK;
  iNa = _ion_iNa;
  iNaB = _ion_iNaB;
  iHERG = _ion_iHERG;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iKATP = _ion_iKATP;
  iKDR = _ion_iKDR;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_Vmi = Vmi;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 19; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[4] = &(_ion_Vmi);
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
  Vmi = _ion_Vmi;
  iCaL = _ion_iCaL;
  iCaT = _ion_iCaT;
  iCaP = _ion_iCaP;
  iBK = _ion_iBK;
  iNa = _ion_iNa;
  iNaB = _ion_iNaB;
  iHERG = _ion_iHERG;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iKATP = _ion_iKATP;
  iKDR = _ion_iKDR;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
  if (_thread1data_inuse) {_thread[_gth]._pval = (double*)ecalloc(17, sizeof(double));
 }else{
 _thread[_gth]._pval = _thread1data; _thread1data_inuse = 1;
 }
 }
 
static void _thread_cleanup(Datum* _thread) {
  if (_thread[_gth]._pval == _thread1data) {
   _thread1data_inuse = 0;
  }else{
   free((void*)_thread[_gth]._pval);
  }
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_Vm_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_CaL_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_CaT_sym, _ppvar, 3, 3);
   nrn_update_ion_pointer(_CaP_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_BK_sym, _ppvar, 5, 3);
   nrn_update_ion_pointer(_Na_sym, _ppvar, 6, 3);
   nrn_update_ion_pointer(_NaB_sym, _ppvar, 7, 3);
   nrn_update_ion_pointer(_HERG_sym, _ppvar, 8, 3);
   nrn_update_ion_pointer(_PCa_sym, _ppvar, 9, 3);
   nrn_update_ion_pointer(_KCa_sym, _ppvar, 10, 3);
   nrn_update_ion_pointer(_KATP_sym, _ppvar, 11, 3);
   nrn_update_ion_pointer(_KDR_sym, _ppvar, 12, 3);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  Cac = Cac0;
  IntCa = IntCa0;
  In = In0;
  Vp = Vp0;
  dNa = dNa0;
  dKr = dKr0;
  dKhe = dKhe0;
  dKCaB = dKCaB0;
  dCaT = dCaT0;
  dCaP = dCaP0;
  dCaL = dCaL0;
  fNa = fNa0;
  fKhe = fKhe0;
  fKCaB = fKCaB0;
  fCaT = fCaT0;
  fCaP = fCaP0;
  f2CaL = f2CaL0;
  f1CaL = f1CaL0;
 {
   test = - 1.0 ;
   Cm = 9990.0 ;
   ADPf = 15.0 ;
   ATP = 3600.0 ;
   Cac = 0.25 ;
   dCaL = 0.001 ;
   dCaP = 0.1 ;
   dCaT = 0.1 ;
   dKCa = 0.1 ;
   dKCaB = 0.1 ;
   dKhe = 0.1 ;
   dKr = 0.0029 ;
   dNa = 0.1 ;
   ECa = 100.0 ;
   EK = - 75.0 ;
   ENa = 70.0 ;
   F = 96480.0 ;
   f1CaL = 0.1 ;
   f2CaL = 0.7 ;
   fCaP = 0.1 ;
   fCaT = 0.1 ;
   fi = 0.005 ;
   fKCaB = 0.1 ;
   fKhe = 0.1 ;
   fNa = 0.1 ;
   gBNa = 10.0 ;
   gmCaL = 2700.0 ;
   gmCaP = 1200.0 ;
   gmCaT = 250.0 ;
   gmKATP = 65000.0 ;
   gmKCa = 150.0 ;
   gmKCaB = 25000.0 ;
   gmKDr = 18000.0 ;
   gmKhe = 200.0 ;
   gmNa = 10000.0 ;
   hdk = 2.0 ;
   In = 1.0 ;
   IntCa = 0.0 ;
   kCaBK = 1.5 ;
   kCap = 0.3 ;
   kci = 2.0 ;
   kdCaL = 8.0 ;
   kdCaP = 6.0 ;
   kdCaT = 6.0 ;
   kdd = 17.0 ;
   kdhe = 10.0 ;
   kdKCaB = 30.0 ;
   kdkr = 8.0 ;
   kdNa = 10.0 ;
   kfCaL = 8.0 ;
   kfCaP = 8.0 ;
   kfCaT = 8.0 ;
   kfhe = 17.5 ;
   kfKCaB = 9.2 ;
   kfNa = 6.0 ;
   KiCa = 0.2 ;
   KKCa = 0.2 ;
   kNar = 0.0 ;
   kpi = 0.0001 ;
   kre = 0.00073 ;
   ksg = 0.00001 ;
   kshift = 18.0 ;
   ksi = 10000.0 ;
   ktd = 26.0 ;
   ktt = 50.0 ;
   newk = 0.001 ;
   Ni = 600.0 ;
   PmCaP = 5600.0 ;
   RTdF = 26.73 ;
   tdCaP = 0.41 ;
   tdCaT = 0.41 ;
   tdKCaB = 1.9 ;
   tdKhe = 100.0 ;
   tdKr = 20.0 ;
   tdNa = 0.1 ;
   tf1CaL = 6.8 ;
   tf2CaL = 65.0 ;
   tfCaP = 65.0 ;
   tfCaT = 6.8 ;
   tfKCaB = 22.6 ;
   tfKhe = 50.0 ;
   tfNa = 0.5 ;
   VBKo = 0.1 ;
   VdCaL = - 15.0 ;
   VdCaP = - 5.0 ;
   VdCaT = - 50.0 ;
   Vdhe = - 30.0 ;
   Vdkr = - 9.0 ;
   VdNa = - 30.0 ;
   VfCaL = - 25.0 ;
   VfCaP = - 25.0 ;
   VfCaT = - 64.0 ;
   Vfhe = - 42.0 ;
   VfKCaB = 30.0 ;
   VfNa = - 42.0 ;
   Vi = 0.764 ;
   Vp = - 62.0 ;
   Vmi = - 62.0 ;
   Vpi = 45000.0 ;
   tdCaL = 0.41 ;
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
  Vmi = _ion_Vmi;
  iCaL = _ion_iCaL;
  iCaT = _ion_iCaT;
  iCaP = _ion_iCaP;
  iBK = _ion_iBK;
  iNa = _ion_iNa;
  iNaB = _ion_iNaB;
  iHERG = _ion_iHERG;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iKATP = _ion_iKATP;
  iKDR = _ion_iKDR;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_Vmi = Vmi;
  nrn_wrote_conc(_Vm_sym, (&(_ion_Vmi)) - 1, _style_Vm);
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
  Vmi = _ion_Vmi;
  iCaL = _ion_iCaL;
  iCaT = _ion_iCaT;
  iCaP = _ion_iCaP;
  iBK = _ion_iBK;
  iNa = _ion_iNa;
  iNaB = _ion_iNaB;
  iHERG = _ion_iHERG;
  iPCa = _ion_iPCa;
  iKCa = _ion_iKCa;
  iKATP = _ion_iKATP;
  iKDR = _ion_iKDR;
 {   states(_p, _ppvar, _thread, _nt);
  } {
   V_real = Vmi ;
   test = test + 3.0 ;
   dCaLi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaL - Vp ) / kdCaL ) ) ) ) ;
   dCaPi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaP - Vp ) / kdCaP ) ) ) ) ;
   dCaTi = ( 1.0 / ( 1.0 + exp ( ( ( VdCaT - Vp ) / kdCaT ) ) ) ) ;
   dKCa = ( pow ( Cac , 4.0 ) / ( pow ( KKCa , 4.0 ) + pow ( Cac , 4.0 ) ) ) ;
   dKCaBi = ( 1.0 / ( 1.0 + exp ( ( ( VdKCaB - Vp ) / kdKCaB ) ) ) ) ;
   dKhei = ( 1.0 / ( 1.0 + exp ( ( ( Vdhe - Vp ) / kdhe ) ) ) ) ;
   dKri = ( 1.0 / ( 1.0 + exp ( ( ( Vdkr - Vp ) / kdkr ) ) ) ) ;
   dNai = ( 1.0 / ( 1.0 + exp ( ( ( VdNa - Vp ) / kdNa ) ) ) ) ;
   fCaLi = ( 1.0 / ( 1.0 + exp ( ( ( Vp - VfCaL ) / kfCaL ) ) ) ) ;
   fCaPi = ( 1.0 / ( 1.0 + exp ( ( ( Vp - VfCaP ) / kfCaP ) ) ) ) ;
   fCaTi = ( 1.0 / ( 1.0 + exp ( ( ( Vp - VfCaT ) / kfCaT ) ) ) ) ;
   fiCa = ( Cac * Cac / ( ( KiCa * KiCa ) + ( Cac * Cac ) ) ) ;
   fKCaBi = ( 1.0 / ( 1.0 + exp ( - ( ( VfKCaB - Vp ) / kfKCaB ) ) ) ) ;
   fKhei = ( 1.0 / ( 1.0 + exp ( ( ( Vp - Vfhe ) / kfhe ) ) ) ) ;
   fNai = ( 1.0 / ( 1.0 + exp ( - ( ( VfNa - Vp ) / kfNa ) ) ) ) ;
   fsi = ( - ( kci * fiCa * ICaP / F ) + kre ) ;
   ICaL = ( gmCaL * dCaL * f1CaL * f2CaL * ( Vp - ECa ) ) ;
   ICaP = ( gmCaP * dCaP * fCaP * ( Vp - ECa ) ) ;
   ICaT = ( gmCaT * dCaT * fCaT * ( Vp - ECa ) ) ;
   IKATP = ( gmKATP * OKATP * ( Vp - EK ) ) ;
   IKCa = ( gmKCa * dKCa * ( Vp - EK ) ) ;
   IKCaB = ( gmKCaB * pow ( dKCaB , hdk ) * fKCaB * ( Vp - EK ) ) ;
   IKDr = ( gmKDr * dKr * dKr * ( Vp - EK ) ) ;
   IKher = ( gmKhe * dKhe * fKhe * ( Vp - EK ) ) ;
   INa = ( gmNa * ( ( pow ( dNa , 3.0 ) * fNa ) + kNar ) * ( Vp - ENa ) ) ;
   INab = ( gBNa * ( Vp - ENa ) ) ;
   IPCa = ( PmCaP * Cac * Cac / ( ( Cac * Cac ) + ( kCap * kCap ) ) ) ;
   IS = ( kpi * ksi * In ) ;
   MgADP = ( 0.55 * ADPf ) ;
   OKATP = ( ( ( 0.08 * ( 1.0 + ( 2.0 * MgADP / kdd ) ) ) + ( 0.89 * MgADP * MgADP / kdd / kdd ) ) / ( ( 1.0 + ( MgADP / kdd ) ) * ( 1.0 + ( MgADP / kdd ) ) * ( 1.0 + ( 0.45 * MgADP / ktd ) + ( ATP / ktt ) ) ) ) ;
   tdCaL = ( 2.2 - ( 1.79 * exp ( - ( .00020292043084065876 * ( - 9.7 + Vp ) * ( - 9.7 + Vp ) ) ) ) ) ;
   VdKCaB = ( VBKo - ( kshift * log ( ( Cac / kCaBK ) ) ) ) ;
   }
  _ion_Vmi = Vmi;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(Cac) - _p;  _dlist1[0] = &(DCac) - _p;
 _slist1[1] = &(IntCa) - _p;  _dlist1[1] = &(DIntCa) - _p;
 _slist1[2] = &(dKr) - _p;  _dlist1[2] = &(DdKr) - _p;
 _slist1[3] = &(Vp) - _p;  _dlist1[3] = &(DVp) - _p;
 _slist1[4] = &(Vmi) - _p;  _dlist1[4] = &(DVmi) - _p;
 _slist1[5] = &(dCaL) - _p;  _dlist1[5] = &(DdCaL) - _p;
 _slist1[6] = &(dCaP) - _p;  _dlist1[6] = &(DdCaP) - _p;
 _slist1[7] = &(fCaP) - _p;  _dlist1[7] = &(DfCaP) - _p;
 _slist1[8] = &(f1CaL) - _p;  _dlist1[8] = &(Df1CaL) - _p;
 _slist1[9] = &(f2CaL) - _p;  _dlist1[9] = &(Df2CaL) - _p;
 _slist1[10] = &(dNa) - _p;  _dlist1[10] = &(DdNa) - _p;
 _slist1[11] = &(fNa) - _p;  _dlist1[11] = &(DfNa) - _p;
 _slist1[12] = &(dCaT) - _p;  _dlist1[12] = &(DdCaT) - _p;
 _slist1[13] = &(fCaT) - _p;  _dlist1[13] = &(DfCaT) - _p;
 _slist1[14] = &(dKCaB) - _p;  _dlist1[14] = &(DdKCaB) - _p;
 _slist1[15] = &(fKCaB) - _p;  _dlist1[15] = &(DfKCaB) - _p;
 _slist1[16] = &(dKhe) - _p;  _dlist1[16] = &(DdKhe) - _p;
 _slist1[17] = &(fKhe) - _p;  _dlist1[17] = &(DfKhe) - _p;
 _slist1[18] = &(In) - _p;  _dlist1[18] = &(DIn) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Build/Temp/frid.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "    SUFFIX frid\n"
  "    USEION Vm WRITE Vmi VALENCE 1\n"
  "    RANGE Cm, ADPf, ATP, Cac, dCaL, dCaP, dCaT, dKCa, dKCaB, dKhe\n"
  "    RANGE dKr, dNa, ECa, EK, ENa, F, f1CaL, f2CaL, fCaP, fCaT\n"
  "    RANGE fi, fKCaB, fKhe, fNa, gBNa, gmCaL, gmCaP, gmCaT, gmKATP, gmKCa\n"
  "    RANGE gmKCaB, gmKDr, gmKhe, gmNa, hdk, In, IntCa, kCaBK, kCap, kci\n"
  "    RANGE kdCaL, kdCaP, kdCaT, kdd, kdhe, kdKCaB, kdkr, kdNa, kfCaL\n"
  "    RANGE kfCaP, kfCaT, kfhe, kfKCaB, kfNa, KiCa, KKCa, kNar, kpi, kre\n"
  "    RANGE ksg, kshift, ksi, ktd, ktt, newk, Ni, PmCaP, RTdF, tdCaP\n"
  "    RANGE tdCaT, tfKCaB, tfKhe, tfNa, VBKo, VdCaL, VdCaP, VdCaT, Vdhe, Vdkr\n"
  "    RANGE VdNa, VfCaL, VfCaP, VfCaT, Vfhe, VfKCaB, VfNa, Vi, Vp, Vpi\n"
  "    RANGE tdKr, tdNa, tf1CaL, tfCaP, tfCaT, tf2CaL\n"
  "    RANGE tdCaL, test, Vp\n"
  "    RANGE VdKCaB\n"
  "    RANGE ICaL, ICaP, ICaT, IKATP, IKCa, IKCaB, IKDr, IKher, INa, INab, IPCa\n"
  "    RANGE IS, MgADP, OKATP, tdCaL, VdKCaB\n"
  "    RANGE V_real\n"
  "    USEION CaL READ iCaL\n"
  "    USEION CaT READ iCaT\n"
  "    USEION CaP READ iCaP\n"
  "    USEION BK READ iBK\n"
  "    USEION Na READ iNa\n"
  "    USEION NaB READ iNaB\n"
  "    USEION HERG READ iHERG\n"
  "    USEION PCa READ iPCa\n"
  "    USEION KCa READ iKCa\n"
  "    USEION KATP READ iKATP\n"
  "    USEION KDR READ iKDR\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "    iCaL\n"
  "    iCaT\n"
  "    iCaP\n"
  "    iBK\n"
  "    iNa\n"
  "    iNaB\n"
  "    iHERG\n"
  "    iPCa\n"
  "    iKCa\n"
  "    iKATP\n"
  "    iKDR\n"
  "    Cm\n"
  "    ADPf\n"
  "    ATP\n"
  "    ECa\n"
  "    EK\n"
  "    ENa\n"
  "    F\n"
  "    fi\n"
  "    gBNa\n"
  "    gmCaL\n"
  "    gmCaP\n"
  "    gmCaT\n"
  "    gmKATP\n"
  "    gmKCa\n"
  "    gmKCaB\n"
  "    gmKDr\n"
  "    gmKhe\n"
  "    gmNa\n"
  "    hdk\n"
  "    kCaBK\n"
  "    kCap\n"
  "    kci\n"
  "    kdCaL\n"
  "    kdCaP\n"
  "    kdCaT\n"
  "    kdd\n"
  "    kdhe\n"
  "    kdKCaB\n"
  "    kdkr\n"
  "    kdNa\n"
  "    kfCaL\n"
  "    kfCaP\n"
  "    kfCaT\n"
  "    kfhe\n"
  "    kfKCaB\n"
  "    kfNa\n"
  "    KiCa\n"
  "    KKCa\n"
  "    kNar\n"
  "    kpi\n"
  "    kre\n"
  "    ksg\n"
  "    kshift\n"
  "    ksi\n"
  "    ktd\n"
  "    ktt\n"
  "    newk\n"
  "    Ni\n"
  "    PmCaP\n"
  "    RTdF\n"
  "    tdCaP\n"
  "    tdCaT\n"
  "    tfKCaB\n"
  "    tfKhe\n"
  "    tfNa\n"
  "    VBKo\n"
  "    VdCaL\n"
  "    VdCaP\n"
  "    VdCaT\n"
  "    Vdhe\n"
  "    Vdkr\n"
  "    VdNa\n"
  "    VfCaL\n"
  "    VfCaP\n"
  "    VfCaT\n"
  "    Vfhe\n"
  "    VfKCaB\n"
  "    VfNa\n"
  "    Vi\n"
  "    Vpi\n"
  "\n"
  "    tdKr\n"
  "    tdNa\n"
  "    tf1CaL\n"
  "    tfCaP\n"
  "    tfCaT\n"
  "    tf2CaL\n"
  "    tdKCaB\n"
  "    tdKhe	\n"
  "\n"
  "    test	\n"
  "    	dCaLi\n"
  "    dCaPi\n"
  "    dCaTi\n"
  "    dKCa\n"
  "    dKCaBi\n"
  "    dKhei\n"
  "    dKri\n"
  "    dNai\n"
  "    fCaLi\n"
  "    fCaPi\n"
  "    fCaTi\n"
  "    fiCa\n"
  "    fKCaBi\n"
  "    fKhei\n"
  "    fNai\n"
  "    fsi\n"
  "    ICaL\n"
  "    ICaP\n"
  "    ICaT\n"
  "    IKATP\n"
  "    IKCa\n"
  "    IKCaB\n"
  "    IKDr\n"
  "    IKher\n"
  "    INa\n"
  "    INab\n"
  "    IPCa\n"
  "    IS : insulin secretion\n"
  "    MgADP\n"
  "    OKATP\n"
  "    tdCaL\n"
  "    VdKCaB\n"
  "    V_real\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "    Vmio\n"
  "}\n"
  "\n"
  "STATE{\n"
  "    Cac\n"
  "    IntCa\n"
  "    dKr\n"
  "    Vp\n"
  "    dCaL\n"
  "    dCaP\n"
  "    fCaP\n"
  "    f1CaL\n"
  "    f2CaL\n"
  "    dNa\n"
  "    fNa\n"
  "    dCaT\n"
  "    fCaT\n"
  "    dKCaB\n"
  "    fKCaB\n"
  "    dKhe\n"
  "    fKhe\n"
  "    In\n"
  "    Vmi\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "    test = -1 \n"
  "    Cm = 9990\n"
  "    ADPf = 15.0\n"
  "    ATP = 3600\n"
  "    Cac = 0.25\n"
  "    dCaL = 0.001\n"
  "    dCaP = 0.1\n"
  "    dCaT = 0.1\n"
  "    dKCa = 0.1\n"
  "    dKCaB = 0.1\n"
  "    dKhe = 0.1\n"
  "    dKr = 0.0029\n"
  "    dNa = 0.1\n"
  "    ECa = 100\n"
  "    EK = -75\n"
  "    ENa = 70\n"
  "    F = 96480\n"
  "    f1CaL = 0.1\n"
  "    f2CaL = 0.7\n"
  "    fCaP = 0.1\n"
  "    fCaT = 0.1\n"
  "    fi = 0.005\n"
  "    fKCaB = 0.1\n"
  "    fKhe = 0.1\n"
  "    fNa = 0.1\n"
  "    gBNa = 10.0\n"
  "    gmCaL = 2700\n"
  "    gmCaP = 1200\n"
  "    gmCaT = 250\n"
  "    gmKATP = 65000\n"
  "    gmKCa = 150\n"
  "    gmKCaB = 25000\n"
  "    gmKDr = 18000\n"
  "    gmKhe = 200\n"
  "    gmNa = 10000\n"
  "    hdk = 2\n"
  "    In = 1.0\n"
  "    IntCa = 0\n"
  "    kCaBK = 1.5\n"
  "    kCap = 0.3\n"
  "    kci = 2\n"
  "    kdCaL = 8\n"
  "    kdCaP = 6\n"
  "    kdCaT = 6\n"
  "    kdd = 17\n"
  "    kdhe = 10\n"
  "    kdKCaB = 30\n"
  "    kdkr = 8\n"
  "    kdNa = 10\n"
  "    kfCaL = 8\n"
  "    kfCaP = 8\n"
  "    kfCaT = 8\n"
  "    kfhe = 17.5\n"
  "    kfKCaB = 9.2\n"
  "    kfNa = 6\n"
  "    KiCa = 0.2\n"
  "    KKCa = 0.2\n"
  "    kNar = 0\n"
  "    kpi = 0.0001\n"
  "    kre = 0.00073\n"
  "    ksg = 0.00001\n"
  "    kshift = 18\n"
  "    ksi = 10000\n"
  "    ktd = 26\n"
  "    ktt = 50\n"
  "    newk = 0.001\n"
  "    Ni = 600\n"
  "    PmCaP = 5600\n"
  "    RTdF = 26.73\n"
  "    tdCaP = 0.41\n"
  "    tdCaT = 0.41\n"
  "    tdKCaB = 1.9\n"
  "    tdKhe = 100\n"
  "    tdKr = 20\n"
  "    tdNa = 0.1\n"
  "    tf1CaL = 6.8\n"
  "    tf2CaL = 65\n"
  "    tfCaP = 65\n"
  "    tfCaT = 6.8\n"
  "    tfKCaB = 22.6\n"
  "    tfKhe = 50\n"
  "    tfNa = 0.5\n"
  "    VBKo = 0.1\n"
  "    VdCaL = -15\n"
  "    VdCaP = -5\n"
  "    VdCaT = -50\n"
  "    Vdhe = -30\n"
  "    Vdkr = -9\n"
  "    VdNa = -30\n"
  "    VfCaL = -25\n"
  "    VfCaP = -25\n"
  "    VfCaT = -64\n"
  "    Vfhe = -42\n"
  "    VfKCaB = 30\n"
  "    VfNa = -42\n"
  "    Vi = 0.764\n"
  "    Vp = -62\n"
  "    Vmi = -62\n"
  "    Vpi = 45000\n"
  "    tdCaL = 0.41\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "    V_real = Vmi\n"
  "    test = test + 3\n"
  "    dCaLi = (1.0 / (1.0 + exp(((VdCaL - Vp) / kdCaL))))\n"
  "    dCaPi = (1.0 / (1.0 + exp(((VdCaP - Vp) / kdCaP))))\n"
  "    dCaTi = (1.0 / (1.0 + exp(((VdCaT - Vp) / kdCaT))))\n"
  "    dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))\n"
  "    dKCaBi = (1.0 / (1.0 + exp(((VdKCaB - Vp) / kdKCaB))))\n"
  "    dKhei =  (1.0 / (1.0 + exp(((Vdhe - Vp) / kdhe))))\n"
  "    dKri = (1.0 / (1.0 + exp(((Vdkr - Vp) / kdkr))))\n"
  "    dNai = (1.0 / (1.0 + exp(((VdNa - Vp) / kdNa))))\n"
  "    fCaLi = (1.0 / (1.0 + exp(((Vp - VfCaL) / kfCaL))))\n"
  "    fCaPi =  (1.0 / (1.0 + exp(((Vp - VfCaP) / kfCaP))))\n"
  "    fCaTi = (1.0 / (1.0 + exp(((Vp - VfCaT) / kfCaT))))\n"
  "    fiCa =  (Cac * Cac / ((KiCa * KiCa) + (Cac * Cac)))\n"
  "    fKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - Vp) / kfKCaB))))\n"
  "    fKhei = (1.0 / (1.0 + exp(((Vp - Vfhe) / kfhe))))\n"
  "    fNai = (1.0 / (1.0 + exp( - ((VfNa - Vp) / kfNa))))\n"
  "    fsi = ( - (kci * fiCa * ICaP / F) + kre)\n"
  "    ICaL = (gmCaL * dCaL * f1CaL * f2CaL * (Vp - ECa))\n"
  "    ICaP = (gmCaP * dCaP * fCaP * (Vp - ECa))\n"
  "    ICaT = (gmCaT * dCaT * fCaT * (Vp - ECa))\n"
  "    IKATP =  (gmKATP * OKATP * (Vp - EK))\n"
  "    IKCa =  (gmKCa * dKCa * (Vp - EK))\n"
  "    IKCaB =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (Vp - EK))\n"
  "    IKDr =  (gmKDr * dKr * dKr * (Vp - EK))\n"
  "    IKher =  (gmKhe * dKhe * fKhe * (Vp - EK))\n"
  "    INa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (Vp - ENa))\n"
  "    INab =  (gBNa * (Vp - ENa))\n"
  "    IPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))\n"
  "    IS =  (kpi * ksi * In)\n"
  "    MgADP =  (0.55 * ADPf)\n"
  "    OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))\n"
  "    tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + Vp) * ( - 9.7 + Vp)))))\n"
  "    VdKCaB =   (VBKo - (kshift * log((Cac / kCaBK))))\n"
  "    SOLVE states METHOD cnexp  \n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "    Cac' = ((fi * ( - iCaL - ICaP - ICaT - (2.0 * IPCa)) / (2.0 * F * Vi)) - (ksg * Cac))\n"
  "    IntCa' = (0.001 * Cac)\n"
  "    dKr' = ((dKri - dKr) / tdKr)\n"
  "    Vp' =  - ((ICaL + ICaP + ICaT + IKDr + IPCa + IKCa + IKCaB + IKATP + IKher + INab + INa) / Cm)\n"
  "    Vmi' = - ((iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa) / Cm)\n"
  "    dCaL' = ((dCaLi - dCaL) / tdCaL)\n"
  "    dCaP' = ((dCaPi - dCaP) / tdCaP)\n"
  "    fCaP' = ((fCaPi - fCaP) / tfCaP)\n"
  "    f1CaL' = ((fCaLi - f1CaL) / tf1CaL)\n"
  "    f2CaL' = ((fCaLi - f2CaL) / tf2CaL)\n"
  "    dNa' = ((dNai - dNa) / tdNa)\n"
  "    fNa' = ((fNai - fNa) / tfNa)\n"
  "    dCaT' = ((dCaTi - dCaT) / tdCaT)\n"
  "    fCaT' = ((fCaTi - fCaT) / tfCaT)\n"
  "    dKCaB' = ((dKCaBi - dKCaB) / tdKCaB)\n"
  "    fKCaB' = ((fKCaBi - fKCaB) / tfKCaB)\n"
  "    dKhe' = ((dKhei - dKhe) / tdKhe)\n"
  "    fKhe' = ((fKhei - fKhe) / tfKhe)\n"
  "    In' = ((fsi * Ni / Vpi) - (kpi * In))\n"
  "}\n"
  ;
#endif

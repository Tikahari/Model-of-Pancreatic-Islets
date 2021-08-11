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
 
#define nrn_init _nrn_init__one
#define _nrn_initial _nrn_initial__one
#define nrn_cur _nrn_cur__one
#define _nrn_current _nrn_current__one
#define nrn_jacob _nrn_jacob__one
#define nrn_state _nrn_state__one
#define _net_receive _net_receive__one 
#define states states__one 
 
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
#define gGABAbar _p[0]
#define EffId _p[1]
#define iGABA _p[2]
#define EffIa _p[3]
#define gkatpa _p[4]
#define ikatpa _p[5]
#define gGIRKbara _p[6]
#define EffSa _p[7]
#define iGIRKa _p[8]
#define rm2a _p[9]
#define r20 _p[10]
#define gGIRKbarb _p[11]
#define EffSb _p[12]
#define iGIRKb _p[13]
#define rm2b _p[14]
#define ikca _p[15]
#define minf _p[16]
#define ica _p[17]
#define ical _p[18]
#define icar _p[19]
#define ninf _p[20]
#define ik _p[21]
#define topo _p[22]
#define bottomo _p[23]
#define katpo _p[24]
#define ikatp _p[25]
#define vmdcyt _p[26]
#define JL _p[27]
#define JR _p[28]
#define Jmem _p[29]
#define Jserca _p[30]
#define Jleak _p[31]
#define Jer _p[32]
#define f6p _p[33]
#define Jgpdh _p[34]
#define Jgk_ms _p[35]
#define mod_cmd _p[36]
#define weight2 _p[37]
#define topa2 _p[38]
#define bottom2 _p[39]
#define weight3 _p[40]
#define topa3 _p[41]
#define bottom3 _p[42]
#define weight4 _p[43]
#define topa4 _p[44]
#define bottom4 _p[45]
#define weight5 _p[46]
#define topa5 _p[47]
#define bottom5 _p[48]
#define weight6 _p[49]
#define topa6 _p[50]
#define bottom6 _p[51]
#define weight7 _p[52]
#define topa7 _p[53]
#define bottom7 _p[54]
#define weight8 _p[55]
#define topa8 _p[56]
#define bottom8 _p[57]
#define weight9 _p[58]
#define topa9 _p[59]
#define bottom9 _p[60]
#define weight10 _p[61]
#define topa10 _p[62]
#define bottom10 _p[63]
#define weight11 _p[64]
#define topa11 _p[65]
#define bottom11 _p[66]
#define weight12 _p[67]
#define topa12 _p[68]
#define bottom12 _p[69]
#define weight13 _p[70]
#define topa13 _p[71]
#define bottom13 _p[72]
#define weight14 _p[73]
#define topa14 _p[74]
#define bottom14 _p[75]
#define weight15 _p[76]
#define topa15 _p[77]
#define topb _p[78]
#define bottom15 _p[79]
#define weight16 _p[80]
#define topa16 _p[81]
#define bottom16 _p[82]
#define pfk _p[83]
#define pfk_ms _p[84]
#define delta _p[85]
#define Juni _p[86]
#define JNaCa _p[87]
#define Jmito _p[88]
#define NADm _p[89]
#define ATPm _p[90]
#define RATm _p[91]
#define Jpdh _p[92]
#define JHleak _p[93]
#define MM1 _p[94]
#define JO _p[95]
#define MM2 _p[96]
#define JHres _p[97]
#define b2 _p[98]
#define JF1F0 _p[99]
#define JHatp _p[100]
#define FRT _p[101]
#define Jant _p[102]
#define atp _p[103]
#define Jhyd _p[104]
#define mgadp _p[105]
#define adp3m _p[106]
#define atp4m _p[107]
#define ampfactor _p[108]
#define r3 _p[109]
#define r2 _p[110]
#define JIS _p[111]
#define mcalinfa _p[112]
#define hcalinfa _p[113]
#define taucalma _p[114]
#define taucalha _p[115]
#define icala _p[116]
#define mcatinfa _p[117]
#define hcatinfa _p[118]
#define taucatma _p[119]
#define taucatha _p[120]
#define icata _p[121]
#define mcapqinfa _p[122]
#define hcapqinfa _p[123]
#define taucapqma _p[124]
#define taucapqha _p[125]
#define icapqa _p[126]
#define mnainfa _p[127]
#define hnainfa _p[128]
#define taunama _p[129]
#define taunaha _p[130]
#define inaa _p[131]
#define mkainfa _p[132]
#define hkainfa _p[133]
#define taukaha _p[134]
#define ikaa _p[135]
#define mkdrinfa _p[136]
#define taukdrma _p[137]
#define ikdra _p[138]
#define ila _p[139]
#define cinfa _p[140]
#define isoca _p[141]
#define JLa _p[142]
#define JPQa _p[143]
#define JTa _p[144]
#define Jmema _p[145]
#define Jsercaa _p[146]
#define Jleaka _p[147]
#define Jera _p[148]
#define r2a _p[149]
#define r3a _p[150]
#define JGS _p[151]
#define mcalinfd _p[152]
#define hcalinfd _p[153]
#define taucalmd _p[154]
#define taucalhd _p[155]
#define icald _p[156]
#define mcapqinfd _p[157]
#define hcapqinfd _p[158]
#define taucapqmd _p[159]
#define taucapqhd _p[160]
#define icapqd _p[161]
#define mnainfd _p[162]
#define hnainfd _p[163]
#define taunamd _p[164]
#define taunahd _p[165]
#define inad _p[166]
#define mkainfd _p[167]
#define hkainfd _p[168]
#define taukahd _p[169]
#define ikad _p[170]
#define mkdrinfd _p[171]
#define taukdrmd _p[172]
#define ikdrd _p[173]
#define ikatpd _p[174]
#define ild _p[175]
#define JLd _p[176]
#define JPQd _p[177]
#define Jmemd _p[178]
#define Jsercad _p[179]
#define Jleakd _p[180]
#define Jerd _p[181]
#define y _p[182]
#define Som _p[183]
#define JSS _p[184]
#define vb _p[185]
#define n _p[186]
#define c _p[187]
#define cer _p[188]
#define cmd _p[189]
#define g6p _p[190]
#define fbp _p[191]
#define adpm _p[192]
#define cam _p[193]
#define NADHm _p[194]
#define Psim _p[195]
#define adp _p[196]
#define n1 _p[197]
#define n2 _p[198]
#define n3 _p[199]
#define n4 _p[200]
#define n5 _p[201]
#define n6 _p[202]
#define nf _p[203]
#define nr _p[204]
#define I _p[205]
#define va _p[206]
#define mcala _p[207]
#define hcala _p[208]
#define mcata _p[209]
#define hcata _p[210]
#define mcapqa _p[211]
#define hcapqa _p[212]
#define mnaa _p[213]
#define hnaa _p[214]
#define mkaa _p[215]
#define hkaa _p[216]
#define mkdra _p[217]
#define ca _p[218]
#define cmdpqa _p[219]
#define cera _p[220]
#define n1a _p[221]
#define n2a _p[222]
#define n3a _p[223]
#define n4a _p[224]
#define n5a _p[225]
#define n6a _p[226]
#define nfa _p[227]
#define nra _p[228]
#define G _p[229]
#define vd _p[230]
#define mcald _p[231]
#define hcald _p[232]
#define mcapqd _p[233]
#define hcapqd _p[234]
#define mnad _p[235]
#define hnad _p[236]
#define mkad _p[237]
#define hkad _p[238]
#define mkdrd _p[239]
#define cd _p[240]
#define cmdld _p[241]
#define cmdpqd _p[242]
#define cerd _p[243]
#define S _p[244]
#define Dvb _p[245]
#define Dn _p[246]
#define Dc _p[247]
#define Dcer _p[248]
#define Dcmd _p[249]
#define Dg6p _p[250]
#define Dfbp _p[251]
#define Dadpm _p[252]
#define Dcam _p[253]
#define DNADHm _p[254]
#define DPsim _p[255]
#define Dadp _p[256]
#define Dn1 _p[257]
#define Dn2 _p[258]
#define Dn3 _p[259]
#define Dn4 _p[260]
#define Dn5 _p[261]
#define Dn6 _p[262]
#define Dnf _p[263]
#define Dnr _p[264]
#define DI _p[265]
#define Dva _p[266]
#define Dmcala _p[267]
#define Dhcala _p[268]
#define Dmcata _p[269]
#define Dhcata _p[270]
#define Dmcapqa _p[271]
#define Dhcapqa _p[272]
#define Dmnaa _p[273]
#define Dhnaa _p[274]
#define Dmkaa _p[275]
#define Dhkaa _p[276]
#define Dmkdra _p[277]
#define Dca _p[278]
#define Dcmdpqa _p[279]
#define Dcera _p[280]
#define Dn1a _p[281]
#define Dn2a _p[282]
#define Dn3a _p[283]
#define Dn4a _p[284]
#define Dn5a _p[285]
#define Dn6a _p[286]
#define Dnfa _p[287]
#define Dnra _p[288]
#define DG _p[289]
#define Dvd _p[290]
#define Dmcald _p[291]
#define Dhcald _p[292]
#define Dmcapqd _p[293]
#define Dhcapqd _p[294]
#define Dmnad _p[295]
#define Dhnad _p[296]
#define Dmkad _p[297]
#define Dhkad _p[298]
#define Dmkdrd _p[299]
#define Dcd _p[300]
#define Dcmdld _p[301]
#define Dcmdpqd _p[302]
#define Dcerd _p[303]
#define DS _p[304]
#define v _p[305]
#define _g _p[306]
 
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
 "setdata_one", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
#define Amtot Amtot_one
 double Amtot = 15;
#define Bd Bd_one
 double Bd = 1;
#define Ba Ba_one
 double Ba = 1;
#define B B_one
 double B = 1;
#define Cmito Cmito_one
 double Cmito = 1.8;
#define GlucFacta GlucFacta_one
 double GlucFacta = 0.05;
#define JhydSS JhydSS_one
 double JhydSS = 5e-05;
#define Jgpdh_bas Jgpdh_bas_one
 double Jgpdh_bas = 0.0005;
#define Jgk Jgk_one
 double Jgk = 0.4;
#define Kp2 Kp2_one
 double Kp2 = 2.3;
#define Kp Kp_one
 double Kp = 2.3;
#define KGPDH KGPDH_one
 double KGPDH = 0.0005;
#define NADmtot NADmtot_one
 double NADmtot = 10;
#define VmaxPFK VmaxPFK_one
 double VmaxPFK = 5;
#define alphad alphad_one
 double alphad = 5.18e-15;
#define alphaa alphaa_one
 double alphaa = 5.18e-15;
#define atot atot_one
 double atot = 2500;
#define amp amp_one
 double amp = 500;
#define alpha alpha_one
 double alpha = 5.18e-06;
#define amplify amplify_one
 double amplify = 1;
#define bas bas_one
 double bas = 0.0009;
#define bottom1 bottom1_one
 double bottom1 = 1;
#define bas_cmd bas_cmd_one
 double bas_cmd = 0.06935;
#define bas_r3 bas_r3_one
 double bas_r3 = 0.032;
#define con con_one
 double con = 5.94e-09;
#define caerbara caerbara_one
 double caerbara = 70;
#define cma cma_one
 double cma = 5;
#define cmdp cmdp_one
 double cmdp = 4;
#define cbas cbas_one
 double cbas = 0.05;
#define cm cm_one
 double cm = 5300;
#define exo_k1 exo_k1_one
 double exo_k1 = 20;
#define ferd ferd_one
 double ferd = 0.01;
#define fcytd fcytd_one
 double fcytd = 0.01;
#define fmdd fmdd_one
 double fmdd = 0.01;
#define fVpqd fVpqd_one
 double fVpqd = 0.00226;
#define fVld fVld_one
 double fVld = 0.0034;
#define fd fd_one
 double fd = 0.003;
#define fera fera_one
 double fera = 0.01;
#define fcyta fcyta_one
 double fcyta = 0.01;
#define fmda fmda_one
 double fmda = 0.01;
#define fVpqa fVpqa_one
 double fVpqa = 0.00226;
#define fa fa_one
 double fa = 150;
#define fmito fmito_one
 double fmito = 0.01;
#define f41 f41_one
 double f41 = 20;
#define f42 f42_one
 double f42 = 20;
#define f23 f23_one
 double f23 = 0.2;
#define f43 f43_one
 double f43 = 20;
#define f13 f13_one
 double f13 = 0.02;
#define fmd fmd_one
 double fmd = 0.01;
#define fer fer_one
 double fer = 0.01;
#define fcyt fcyt_one
 double fcyt = 0.01;
#define factor factor_one
 double factor = 14;
#define fb fb_one
 double fb = 2000;
#define gld gld_one
 double gld = 0.2;
#define gkdrd gkdrd_one
 double gkdrd = 7.5;
#define gkad gkad_one
 double gkad = 0.5;
#define gnad gnad_one
 double gnad = 5;
#define gcapqd gcapqd_one
 double gcapqd = 0.7;
#define gcald gcald_one
 double gcald = 0.7;
#define gkatpbard gkatpbard_one
 double gkatpbard = 0.29;
#define gla gla_one
 double gla = 0.2;
#define gkdra gkdra_one
 double gkdra = 4.5;
#define gkaa gkaa_one
 double gkaa = 1;
#define gnaa gnaa_one
 double gnaa = 11;
#define gcata gcata_one
 double gcata = 0.5;
#define gcapqa gcapqa_one
 double gcapqa = 0.6;
#define gcala gcala_one
 double gcala = 0.7;
#define gsocbara gsocbara_one
 double gsocbara = 0.025;
#define gamma gamma_one
 double gamma = 0.001;
#define gk gk_one
 double gk = 1800;
#define gca gca_one
 double gca = 7;
#define gkca gkca_one
 double gkca = 280;
#define gkatpb gkatpb_one
 double gkatpb = 150;
#define gthresh gthresh_one
 double gthresh = 40;
#define gGIRKko gGIRKko_one
 double gGIRKko = 0;
#define gkatpbara gkatpbara_one
 double gkatpbara = 3;
#define ksercad ksercad_one
 double ksercad = 0.4;
#define kpmcad kpmcad_one
 double kpmcad = 0.3;
#define kp2a kp2a_one
 double kp2a = 2.3;
#define kpa kpa_one
 double kpa = 2.3;
#define km1a km1a_one
 double km1a = 100;
#define k1a k1a_one
 double k1a = 20;
#define kpmcaa kpmcaa_one
 double kpmcaa = 0.3;
#define ksercaa ksercaa_one
 double ksercaa = 0.05;
#define kcmd kcmd_one
 double kcmd = 3;
#define km1 km1_one
 double km1 = 100;
#define khyd khyd_one
 double khyd = 5e-05;
#define kappa kappa_one
 double kappa = 0.001;
#define k3 k3_one
 double k3 = 50000;
#define k2 k2_one
 double k2 = 1;
#define k1 k1_one
 double k1 = 30;
#define kserca2b kserca2b_one
 double kserca2b = 0.01;
#define kserca3 kserca3_one
 double kserca3 = 0.1;
#define kpmca kpmca_one
 double kpmca = 0.2;
#define ktt ktt_one
 double ktt = 1;
#define ktd ktd_one
 double ktd = 26;
#define kdd kdd_one
 double kdd = 17;
#define kd kd_one
 double kd = 0.5;
#define k4 k4_one
 double k4 = 150;
#define ka1 ka1_one
 double ka1 = 0.1;
#define knockoutda knockoutda_one
 double knockoutda = 0;
#define knockoutdb knockoutdb_one
 double knockoutdb = 0;
#define knockoutba knockoutba_one
 double knockoutba = 0;
#define knockoutbd knockoutbd_one
 double knockoutbd = 0;
#define lambda lambda_one
 double lambda = 0.06;
#define max_cmd max_cmd_one
 double max_cmd = 32;
#define nca nca_one
 double nca = 590;
#define pleakd pleakd_one
 double pleakd = 0.0003;
#define pleaka pleaka_one
 double pleaka = 0.0003;
#define p20 p20_one
 double p20 = 2;
#define p19 p19_one
 double p19 = 0.35;
#define p16 p16_one
 double p16 = 35;
#define p15 p15_one
 double p15 = 8.5;
#define p14 p14_one
 double p14 = 190;
#define p13 p13_one
 double p13 = 10;
#define p11 p11_one
 double p11 = 5;
#define p10 p10_one
 double p10 = 177;
#define p9 p9_one
 double p9 = 0.1;
#define p8 p8_one
 double p8 = 7;
#define p7 p7_one
 double p7 = 5;
#define p6 p6_one
 double p6 = 177;
#define p5 p5_one
 double p5 = 0.1;
#define p4 p4_one
 double p4 = 0.6;
#define p18 p18_one
 double p18 = -0.03;
#define p17 p17_one
 double p17 = 0.002;
#define p3 p3_one
 double p3 = 0.01;
#define p2 p2_one
 double p2 = 1;
#define p1 p1_one
 double p1 = 400;
#define p24 p24_one
 double p24 = 0.016;
#define p23 p23_one
 double p23 = 0.01;
#define p22 p22_one
 double p22 = 1.1;
#define p21 p21_one
 double p21 = 0.04;
#define phigk phigk_one
 double phigk = 0.3;
#define per per_one
 double per = 0.0002;
#define rm3a rm3a_one
 double rm3a = 0.0001;
#define r30a r30a_one
 double r30a = 1.205;
#define r20a r20a_one
 double r20a = 0.006;
#define rm1a rm1a_one
 double rm1a = 1;
#define r1a r1a_one
 double r1a = 0.6;
#define rm3 rm3_one
 double rm3 = 0.0001;
#define r30 r30_one
 double r30 = 1.205;
#define rm1 rm1_one
 double rm1 = 1;
#define r1 r1_one
 double r1 = 0.6;
#define raL raL_one
 double raL = 0.5;
#define rb rb_one
 double rb = 0.002;
#define rako rako_one
 double rako = 0.001;
#define ra ra_one
 double ra = 4.5;
#define skdrmd skdrmd_one
 double skdrmd = 23;
#define skahd skahd_one
 double skahd = -10;
#define skamd skamd_one
 double skamd = 10;
#define snahd snahd_one
 double snahd = -8;
#define snamd snamd_one
 double snamd = 4;
#define scapqhd scapqhd_one
 double scapqhd = -5;
#define scapqmd scapqmd_one
 double scapqmd = 10;
#define scalhd scalhd_one
 double scalhd = -5;
#define scalmd scalmd_one
 double scalmd = 10;
#define sigmavd sigmavd_one
 double sigmavd = 31;
#define ssoca ssoca_one
 double ssoca = -20;
#define skdrma skdrma_one
 double skdrma = 23;
#define skaha skaha_one
 double skaha = -10;
#define skama skama_one
 double skama = 10;
#define snaha snaha_one
 double snaha = -8;
#define snama snama_one
 double snama = 4;
#define scapqha scapqha_one
 double scapqha = -5;
#define scapqma scapqma_one
 double scapqma = 10;
#define scatha scatha_one
 double scatha = -5;
#define scatma scatma_one
 double scatma = 4;
#define scalha scalha_one
 double scalha = -5;
#define scalma scalma_one
 double scalma = 10;
#define sigmava sigmava_one
 double sigmava = 31;
#define sigmav sigmav_one
 double sigmav = 30;
#define sn sn_one
 double sn = 6;
#define sm sm_one
 double sm = 10;
#define ssomb ssomb_one
 double ssomb = 15;
#define sombarb sombarb_one
 double sombarb = 50;
#define sombarb2 sombarb2_one
 double sombarb2 = 35;
#define ssom ssom_one
 double ssom = 15;
#define sombara sombara_one
 double sombara = 50;
#define ssom2 ssom2_one
 double ssom2 = 10;
#define sombara2 sombara2_one
 double sombara2 = 35;
#define tkah2d tkah2d_one
 double tkah2d = 5;
#define tkah1d tkah1d_one
 double tkah1d = 60;
#define taukamd taukamd_one
 double taukamd = 0.1;
#define tnah2d tnah2d_one
 double tnah2d = 0.5;
#define tnah1d tnah1d_one
 double tnah1d = 120;
#define tcapqh2d tcapqh2d_one
 double tcapqh2d = 51;
#define tcapqh1d tcapqh1d_one
 double tcapqh1d = 60;
#define tcalh2d tcalh2d_one
 double tcalh2d = 51;
#define tcalh1d tcalh1d_one
 double tcalh1d = 60;
#define tkah2a tkah2a_one
 double tkah2a = 5;
#define tkah1a tkah1a_one
 double tkah1a = 60;
#define taukama taukama_one
 double taukama = 0.1;
#define tnah2a tnah2a_one
 double tnah2a = 0.5;
#define tnah1a tnah1a_one
 double tnah1a = 120;
#define tcapqh2a tcapqh2a_one
 double tcapqh2a = 51;
#define tcapqh1a tcapqh1a_one
 double tcapqh1a = 60;
#define tcath2a tcath2a_one
 double tcath2a = 5;
#define tcath1a tcath1a_one
 double tcath1a = 20;
#define tcatm2a tcatm2a_one
 double tcatm2a = 0;
#define tcatm1a tcatm1a_one
 double tcatm1a = 15;
#define tcalh2a tcalh2a_one
 double tcalh2a = 51;
#define tcalh1a tcalh1a_one
 double tcalh1a = 60;
#define topa1 topa1_one
 double topa1 = 0;
#define tmsb tmsb_one
 double tmsb = 0.001;
#define taua taua_one
 double taua = 5;
#define taun taun_one
 double taun = 5;
#define tausom tausom_one
 double tausom = 2000;
#define u3a u3a_one
 double u3a = 0.025;
#define u2a u2a_one
 double u2a = 3;
#define u1a u1a_one
 double u1a = 2000;
#define u3 u3_one
 double u3 = 0.02;
#define u2 u2_one
 double u2 = 3;
#define u1 u1_one
 double u1 = 2000;
#define vkdrmd vkdrmd_one
 double vkdrmd = -25;
#define vkahd vkahd_one
 double vkahd = -68;
#define vkamd vkamd_one
 double vkamd = -45;
#define vnahd vnahd_one
 double vnahd = -52;
#define vnamd vnamd_one
 double vnamd = -30;
#define vcapqhd vcapqhd_one
 double vcapqhd = -33;
#define vcapqmd vcapqmd_one
 double vcapqmd = -15;
#define vcalhd vcalhd_one
 double vcalhd = -33;
#define vcalmd vcalmd_one
 double vcalmd = -30;
#define vmdld vmdld_one
 double vmdld = 2.12e-15;
#define vmdpqd vmdpqd_one
 double vmdpqd = 1.41e-15;
#define vld vld_one
 double vld = -20;
#define vcad vcad_one
 double vcad = 65;
#define vkd vkd_one
 double vkd = -75;
#define vnad vnad_one
 double vnad = 70;
#define vsoca vsoca_one
 double vsoca = 0;
#define vkdrma vkdrma_one
 double vkdrma = -25;
#define vkaha vkaha_one
 double vkaha = -68;
#define vkama vkama_one
 double vkama = -45;
#define vnaha vnaha_one
 double vnaha = -52;
#define vnama vnama_one
 double vnama = -30;
#define vcapqha vcapqha_one
 double vcapqha = -33;
#define vcapqma vcapqma_one
 double vcapqma = -5;
#define vcatha vcatha_one
 double vcatha = -52;
#define vcatma vcatma_one
 double vcatma = -49;
#define vcalha vcalha_one
 double vcalha = -33;
#define vcalma vcalma_one
 double vcalma = -30;
#define vmdpqa vmdpqa_one
 double vmdpqa = 1.41e-15;
#define vcella vcella_one
 double vcella = 6.24e-13;
#define vla vla_one
 double vla = -20;
#define vcaa vcaa_one
 double vcaa = 65;
#define vka vka_one
 double vka = -75;
#define vnaa vnaa_one
 double vnaa = 70;
#define vcell vcell_one
 double vcell = 1.15;
#define vmd vmd_one
 double vmd = 0.0042;
#define vn vn_one
 double vn = -16;
#define vk vk_one
 double vk = -75;
#define vm vm_one
 double vm = -6;
#define vca vca_one
 double vca = 25;
#define vGIRK vGIRK_one
 double vGIRK = -80;
#define vc vc_one
 double vc = 1e-13;
#define vGABA vGABA_one
 double vGABA = 0;
#define weight1 weight1_one
 double weight1 = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double G0 = 0;
 static double I0 = 0;
 static double NADHm0 = 0;
 static double Psim0 = 0;
 static double S0 = 0;
 static double adp0 = 0;
 static double adpm0 = 0;
 static double cerd0 = 0;
 static double cmdpqd0 = 0;
 static double cmdld0 = 0;
 static double cd0 = 0;
 static double cera0 = 0;
 static double cmdpqa0 = 0;
 static double ca0 = 0;
 static double cam0 = 0;
 static double cmd0 = 0;
 static double cer0 = 0;
 static double c0 = 0;
 static double delta_t = 0.01;
 static double fbp0 = 0;
 static double g6p0 = 0;
 static double hkad0 = 0;
 static double hnad0 = 0;
 static double hcapqd0 = 0;
 static double hcald0 = 0;
 static double hkaa0 = 0;
 static double hnaa0 = 0;
 static double hcapqa0 = 0;
 static double hcata0 = 0;
 static double hcala0 = 0;
 static double mkdrd0 = 0;
 static double mkad0 = 0;
 static double mnad0 = 0;
 static double mcapqd0 = 0;
 static double mcald0 = 0;
 static double mkdra0 = 0;
 static double mkaa0 = 0;
 static double mnaa0 = 0;
 static double mcapqa0 = 0;
 static double mcata0 = 0;
 static double mcala0 = 0;
 static double nra0 = 0;
 static double nfa0 = 0;
 static double n6a0 = 0;
 static double n5a0 = 0;
 static double n4a0 = 0;
 static double n3a0 = 0;
 static double n2a0 = 0;
 static double n1a0 = 0;
 static double nr0 = 0;
 static double nf0 = 0;
 static double n60 = 0;
 static double n50 = 0;
 static double n40 = 0;
 static double n30 = 0;
 static double n20 = 0;
 static double n10 = 0;
 static double n0 = 0;
 static double vd0 = 0;
 static double va0 = 0;
 static double vb0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "knockoutbd_one", &knockoutbd_one,
 "knockoutba_one", &knockoutba_one,
 "knockoutdb_one", &knockoutdb_one,
 "knockoutda_one", &knockoutda_one,
 "vGABA_one", &vGABA_one,
 "tausom_one", &tausom_one,
 "vc_one", &vc_one,
 "gkatpbara_one", &gkatpbara_one,
 "ka1_one", &ka1_one,
 "gGIRKko_one", &gGIRKko_one,
 "vGIRK_one", &vGIRK_one,
 "sombara2_one", &sombara2_one,
 "ssom2_one", &ssom2_one,
 "ra_one", &ra_one,
 "sombara_one", &sombara_one,
 "rako_one", &rako_one,
 "ssom_one", &ssom_one,
 "gthresh_one", &gthresh_one,
 "sombarb2_one", &sombarb2_one,
 "sombarb_one", &sombarb_one,
 "ssomb_one", &ssomb_one,
 "rb_one", &rb_one,
 "fb_one", &fb_one,
 "Jgk_one", &Jgk_one,
 "factor_one", &factor_one,
 "gkatpb_one", &gkatpb_one,
 "bas_r3_one", &bas_r3_one,
 "amplify_one", &amplify_one,
 "cm_one", &cm_one,
 "gkca_one", &gkca_one,
 "k4_one", &k4_one,
 "kd_one", &kd_one,
 "nca_one", &nca_one,
 "raL_one", &raL_one,
 "vca_one", &vca_one,
 "vm_one", &vm_one,
 "sm_one", &sm_one,
 "gca_one", &gca_one,
 "vk_one", &vk_one,
 "gk_one", &gk_one,
 "vn_one", &vn_one,
 "sn_one", &sn_one,
 "taun_one", &taun_one,
 "kdd_one", &kdd_one,
 "ktd_one", &ktd_one,
 "ktt_one", &ktt_one,
 "fcyt_one", &fcyt_one,
 "fer_one", &fer_one,
 "fmd_one", &fmd_one,
 "kpmca_one", &kpmca_one,
 "cbas_one", &cbas_one,
 "B_one", &B_one,
 "per_one", &per_one,
 "kserca3_one", &kserca3_one,
 "kserca2b_one", &kserca2b_one,
 "sigmav_one", &sigmav_one,
 "vmd_one", &vmd_one,
 "vcell_one", &vcell_one,
 "alpha_one", &alpha_one,
 "phigk_one", &phigk_one,
 "KGPDH_one", &KGPDH_one,
 "k1_one", &k1_one,
 "k2_one", &k2_one,
 "k3_one", &k3_one,
 "f13_one", &f13_one,
 "f43_one", &f43_one,
 "f23_one", &f23_one,
 "f42_one", &f42_one,
 "f41_one", &f41_one,
 "lambda_one", &lambda_one,
 "taua_one", &taua_one,
 "VmaxPFK_one", &VmaxPFK_one,
 "kappa_one", &kappa_one,
 "Jgpdh_bas_one", &Jgpdh_bas_one,
 "fmito_one", &fmito_one,
 "gamma_one", &gamma_one,
 "p21_one", &p21_one,
 "p22_one", &p22_one,
 "exo_k1_one", &exo_k1_one,
 "bas_cmd_one", &bas_cmd_one,
 "p23_one", &p23_one,
 "p24_one", &p24_one,
 "Amtot_one", &Amtot_one,
 "NADmtot_one", &NADmtot_one,
 "p1_one", &p1_one,
 "p2_one", &p2_one,
 "p3_one", &p3_one,
 "Cmito_one", &Cmito_one,
 "p17_one", &p17_one,
 "p18_one", &p18_one,
 "p4_one", &p4_one,
 "p5_one", &p5_one,
 "p6_one", &p6_one,
 "p7_one", &p7_one,
 "p8_one", &p8_one,
 "p9_one", &p9_one,
 "p10_one", &p10_one,
 "p11_one", &p11_one,
 "p13_one", &p13_one,
 "p14_one", &p14_one,
 "p15_one", &p15_one,
 "p16_one", &p16_one,
 "p19_one", &p19_one,
 "p20_one", &p20_one,
 "khyd_one", &khyd_one,
 "JhydSS_one", &JhydSS_one,
 "amp_one", &amp_one,
 "atot_one", &atot_one,
 "km1_one", &km1_one,
 "r1_one", &r1_one,
 "rm1_one", &rm1_one,
 "r30_one", &r30_one,
 "rm3_one", &rm3_one,
 "u1_one", &u1_one,
 "u2_one", &u2_one,
 "u3_one", &u3_one,
 "Kp_one", &Kp_one,
 "Kp2_one", &Kp2_one,
 "tmsb_one", &tmsb_one,
 "max_cmd_one", &max_cmd_one,
 "cmdp_one", &cmdp_one,
 "kcmd_one", &kcmd_one,
 "weight1_one", &weight1_one,
 "topa1_one", &topa1_one,
 "bottom1_one", &bottom1_one,
 "fa_one", &fa_one,
 "gsocbara_one", &gsocbara_one,
 "ksercaa_one", &ksercaa_one,
 "vnaa_one", &vnaa_one,
 "vka_one", &vka_one,
 "vcaa_one", &vcaa_one,
 "vla_one", &vla_one,
 "cma_one", &cma_one,
 "gcala_one", &gcala_one,
 "gcapqa_one", &gcapqa_one,
 "gcata_one", &gcata_one,
 "gnaa_one", &gnaa_one,
 "gkaa_one", &gkaa_one,
 "gkdra_one", &gkdra_one,
 "gla_one", &gla_one,
 "vcella_one", &vcella_one,
 "vmdpqa_one", &vmdpqa_one,
 "fVpqa_one", &fVpqa_one,
 "fmda_one", &fmda_one,
 "Ba_one", &Ba_one,
 "alphaa_one", &alphaa_one,
 "kpmcaa_one", &kpmcaa_one,
 "fcyta_one", &fcyta_one,
 "fera_one", &fera_one,
 "pleaka_one", &pleaka_one,
 "sigmava_one", &sigmava_one,
 "vcalma_one", &vcalma_one,
 "scalma_one", &scalma_one,
 "vcalha_one", &vcalha_one,
 "scalha_one", &scalha_one,
 "tcalh1a_one", &tcalh1a_one,
 "tcalh2a_one", &tcalh2a_one,
 "vcatma_one", &vcatma_one,
 "scatma_one", &scatma_one,
 "vcatha_one", &vcatha_one,
 "scatha_one", &scatha_one,
 "tcatm1a_one", &tcatm1a_one,
 "tcatm2a_one", &tcatm2a_one,
 "tcath1a_one", &tcath1a_one,
 "tcath2a_one", &tcath2a_one,
 "vcapqma_one", &vcapqma_one,
 "scapqma_one", &scapqma_one,
 "vcapqha_one", &vcapqha_one,
 "scapqha_one", &scapqha_one,
 "tcapqh1a_one", &tcapqh1a_one,
 "tcapqh2a_one", &tcapqh2a_one,
 "vnama_one", &vnama_one,
 "vnaha_one", &vnaha_one,
 "snama_one", &snama_one,
 "snaha_one", &snaha_one,
 "tnah1a_one", &tnah1a_one,
 "tnah2a_one", &tnah2a_one,
 "vkama_one", &vkama_one,
 "skama_one", &skama_one,
 "vkaha_one", &vkaha_one,
 "skaha_one", &skaha_one,
 "taukama_one", &taukama_one,
 "tkah1a_one", &tkah1a_one,
 "tkah2a_one", &tkah2a_one,
 "vkdrma_one", &vkdrma_one,
 "skdrma_one", &skdrma_one,
 "caerbara_one", &caerbara_one,
 "ssoca_one", &ssoca_one,
 "vsoca_one", &vsoca_one,
 "k1a_one", &k1a_one,
 "km1a_one", &km1a_one,
 "r1a_one", &r1a_one,
 "rm1a_one", &rm1a_one,
 "r20a_one", &r20a_one,
 "r30a_one", &r30a_one,
 "rm3a_one", &rm3a_one,
 "u1a_one", &u1a_one,
 "u2a_one", &u2a_one,
 "u3a_one", &u3a_one,
 "kpa_one", &kpa_one,
 "kp2a_one", &kp2a_one,
 "GlucFacta_one", &GlucFacta_one,
 "fd_one", &fd_one,
 "gkatpbard_one", &gkatpbard_one,
 "vnad_one", &vnad_one,
 "vkd_one", &vkd_one,
 "vcad_one", &vcad_one,
 "vld_one", &vld_one,
 "gcald_one", &gcald_one,
 "gcapqd_one", &gcapqd_one,
 "gnad_one", &gnad_one,
 "gkad_one", &gkad_one,
 "gkdrd_one", &gkdrd_one,
 "gld_one", &gld_one,
 "vmdpqd_one", &vmdpqd_one,
 "vmdld_one", &vmdld_one,
 "fVld_one", &fVld_one,
 "fVpqd_one", &fVpqd_one,
 "fmdd_one", &fmdd_one,
 "Bd_one", &Bd_one,
 "alphad_one", &alphad_one,
 "kpmcad_one", &kpmcad_one,
 "fcytd_one", &fcytd_one,
 "ferd_one", &ferd_one,
 "pleakd_one", &pleakd_one,
 "sigmavd_one", &sigmavd_one,
 "ksercad_one", &ksercad_one,
 "vcalmd_one", &vcalmd_one,
 "scalmd_one", &scalmd_one,
 "vcalhd_one", &vcalhd_one,
 "scalhd_one", &scalhd_one,
 "tcalh1d_one", &tcalh1d_one,
 "tcalh2d_one", &tcalh2d_one,
 "vcapqmd_one", &vcapqmd_one,
 "scapqmd_one", &scapqmd_one,
 "vcapqhd_one", &vcapqhd_one,
 "scapqhd_one", &scapqhd_one,
 "tcapqh1d_one", &tcapqh1d_one,
 "tcapqh2d_one", &tcapqh2d_one,
 "vnamd_one", &vnamd_one,
 "vnahd_one", &vnahd_one,
 "snamd_one", &snamd_one,
 "snahd_one", &snahd_one,
 "tnah1d_one", &tnah1d_one,
 "tnah2d_one", &tnah2d_one,
 "vkamd_one", &vkamd_one,
 "skamd_one", &skamd_one,
 "vkahd_one", &vkahd_one,
 "skahd_one", &skahd_one,
 "taukamd_one", &taukamd_one,
 "tkah1d_one", &tkah1d_one,
 "tkah2d_one", &tkah2d_one,
 "vkdrmd_one", &vkdrmd_one,
 "skdrmd_one", &skdrmd_one,
 "con_one", &con_one,
 "bas_one", &bas_one,
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
"one",
 0,
 "gGABAbar_one",
 "EffId_one",
 "iGABA_one",
 "EffIa_one",
 "gkatpa_one",
 "ikatpa_one",
 "gGIRKbara_one",
 "EffSa_one",
 "iGIRKa_one",
 "rm2a_one",
 "r20_one",
 "gGIRKbarb_one",
 "EffSb_one",
 "iGIRKb_one",
 "rm2b_one",
 "ikca_one",
 "minf_one",
 "ica_one",
 "ical_one",
 "icar_one",
 "ninf_one",
 "ik_one",
 "topo_one",
 "bottomo_one",
 "katpo_one",
 "ikatp_one",
 "vmdcyt_one",
 "JL_one",
 "JR_one",
 "Jmem_one",
 "Jserca_one",
 "Jleak_one",
 "Jer_one",
 "f6p_one",
 "Jgpdh_one",
 "Jgk_ms_one",
 "mod_cmd_one",
 "weight2_one",
 "topa2_one",
 "bottom2_one",
 "weight3_one",
 "topa3_one",
 "bottom3_one",
 "weight4_one",
 "topa4_one",
 "bottom4_one",
 "weight5_one",
 "topa5_one",
 "bottom5_one",
 "weight6_one",
 "topa6_one",
 "bottom6_one",
 "weight7_one",
 "topa7_one",
 "bottom7_one",
 "weight8_one",
 "topa8_one",
 "bottom8_one",
 "weight9_one",
 "topa9_one",
 "bottom9_one",
 "weight10_one",
 "topa10_one",
 "bottom10_one",
 "weight11_one",
 "topa11_one",
 "bottom11_one",
 "weight12_one",
 "topa12_one",
 "bottom12_one",
 "weight13_one",
 "topa13_one",
 "bottom13_one",
 "weight14_one",
 "topa14_one",
 "bottom14_one",
 "weight15_one",
 "topa15_one",
 "topb_one",
 "bottom15_one",
 "weight16_one",
 "topa16_one",
 "bottom16_one",
 "pfk_one",
 "pfk_ms_one",
 "delta_one",
 "Juni_one",
 "JNaCa_one",
 "Jmito_one",
 "NADm_one",
 "ATPm_one",
 "RATm_one",
 "Jpdh_one",
 "JHleak_one",
 "MM1_one",
 "JO_one",
 "MM2_one",
 "JHres_one",
 "b2_one",
 "JF1F0_one",
 "JHatp_one",
 "FRT_one",
 "Jant_one",
 "atp_one",
 "Jhyd_one",
 "mgadp_one",
 "adp3m_one",
 "atp4m_one",
 "ampfactor_one",
 "r3_one",
 "r2_one",
 "JIS_one",
 "mcalinfa_one",
 "hcalinfa_one",
 "taucalma_one",
 "taucalha_one",
 "icala_one",
 "mcatinfa_one",
 "hcatinfa_one",
 "taucatma_one",
 "taucatha_one",
 "icata_one",
 "mcapqinfa_one",
 "hcapqinfa_one",
 "taucapqma_one",
 "taucapqha_one",
 "icapqa_one",
 "mnainfa_one",
 "hnainfa_one",
 "taunama_one",
 "taunaha_one",
 "inaa_one",
 "mkainfa_one",
 "hkainfa_one",
 "taukaha_one",
 "ikaa_one",
 "mkdrinfa_one",
 "taukdrma_one",
 "ikdra_one",
 "ila_one",
 "cinfa_one",
 "isoca_one",
 "JLa_one",
 "JPQa_one",
 "JTa_one",
 "Jmema_one",
 "Jsercaa_one",
 "Jleaka_one",
 "Jera_one",
 "r2a_one",
 "r3a_one",
 "JGS_one",
 "mcalinfd_one",
 "hcalinfd_one",
 "taucalmd_one",
 "taucalhd_one",
 "icald_one",
 "mcapqinfd_one",
 "hcapqinfd_one",
 "taucapqmd_one",
 "taucapqhd_one",
 "icapqd_one",
 "mnainfd_one",
 "hnainfd_one",
 "taunamd_one",
 "taunahd_one",
 "inad_one",
 "mkainfd_one",
 "hkainfd_one",
 "taukahd_one",
 "ikad_one",
 "mkdrinfd_one",
 "taukdrmd_one",
 "ikdrd_one",
 "ikatpd_one",
 "ild_one",
 "JLd_one",
 "JPQd_one",
 "Jmemd_one",
 "Jsercad_one",
 "Jleakd_one",
 "Jerd_one",
 "y_one",
 "Som_one",
 "JSS_one",
 0,
 "vb_one",
 "n_one",
 "c_one",
 "cer_one",
 "cmd_one",
 "g6p_one",
 "fbp_one",
 "adpm_one",
 "cam_one",
 "NADHm_one",
 "Psim_one",
 "adp_one",
 "n1_one",
 "n2_one",
 "n3_one",
 "n4_one",
 "n5_one",
 "n6_one",
 "nf_one",
 "nr_one",
 "I_one",
 "va_one",
 "mcala_one",
 "hcala_one",
 "mcata_one",
 "hcata_one",
 "mcapqa_one",
 "hcapqa_one",
 "mnaa_one",
 "hnaa_one",
 "mkaa_one",
 "hkaa_one",
 "mkdra_one",
 "ca_one",
 "cmdpqa_one",
 "cera_one",
 "n1a_one",
 "n2a_one",
 "n3a_one",
 "n4a_one",
 "n5a_one",
 "n6a_one",
 "nfa_one",
 "nra_one",
 "G_one",
 "vd_one",
 "mcald_one",
 "hcald_one",
 "mcapqd_one",
 "hcapqd_one",
 "mnad_one",
 "hnad_one",
 "mkad_one",
 "hkad_one",
 "mkdrd_one",
 "cd_one",
 "cmdld_one",
 "cmdpqd_one",
 "cerd_one",
 "S_one",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 307, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 307;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "n_one", 1e-10,
 "n4_one", 1e-10,
 "n1a_one", 1e-10,
 "n2a_one", 1e-10,
 "n3a_one", 1e-10,
 "n4a_one", 1e-10,
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _one_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 5);
  _extcall_thread = (Datum*)ecalloc(4, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 307, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 one c:/Users/rober/OneDrive - University of Florida/Documents/Research/Pancreatic_islet_model/Model-of-Pancreatic-Islets/Test/one.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
extern void* nrn_cons_newtonspace(int);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[60];
  static int _slist1[60], _dlist1[60];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   Dvb = - ( ik + ica + ikca + ikatp + iGIRKb ) / cm ;
   Dn = ( ninf - n ) / taun ;
   Dc = fcyt * ( Jmem + Jer + delta * Jmito ) ;
   Dcer = - fer * sigmav * Jer ;
   Dcmd = fmd * ( JL - B * ( cmd - c ) ) ;
   Dg6p = Jgk_ms - pfk_ms ;
   Dfbp = pfk_ms - 0.5 * Jgpdh ;
   Dadpm = gamma * ( Jant - JF1F0 ) ;
   Dcam = - fmito * Jmito ;
   DNADHm = gamma * ( Jpdh - JO ) ;
   DPsim = ( JHres - JHatp - Jant - JHleak - JNaCa - 2.0 * Juni ) / Cmito ;
   Dadp = ( - delta * Jant + Jhyd ) / taua ;
   Dn1 = tmsb * ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) * n1 + km1 * n2 + r1 * n5 ) ;
   Dn2 = tmsb * ( 3.0 * exo_k1 * mod_cmd * n1 - ( 2.0 * exo_k1 * mod_cmd + km1 ) * n2 + 2.0 * km1 * n3 ) ;
   Dn3 = tmsb * ( 2.0 * exo_k1 * mod_cmd * n2 - ( 2.0 * km1 + exo_k1 * mod_cmd ) * n3 + 3.0 * km1 * n4 ) ;
   Dn4 = tmsb * ( exo_k1 * mod_cmd * n3 - ( 3.0 * km1 + u1 ) * n4 ) ;
   Dn5 = tmsb * ( rm1 * n1 - ( r1 + rm2b ) * n5 + r2 * n6 ) ;
   Dn6 = tmsb * ( r3 + rm2b * n5 - ( rm3 + r2 ) * n6 ) ;
   Dnf = tmsb * ( u1 * n4 - u2 * nf ) ;
   Dnr = tmsb * ( u2 * nf - u3 * nr ) ;
   DI = JIS / vc - fb * I ;
   Dva = - ( icala + icata + icapqa + inaa + ikdra + ikatpa + ikaa + ila + isoca + iGIRKa ) / cma ;
   Dmcala = ( mcalinfa - mcala ) / taucalma ;
   Dhcala = ( hcalinfa - hcala ) / taucalha ;
   Dmcata = ( mcatinfa - mcata ) / taucatma ;
   Dhcata = ( hcatinfa - hcata ) / taucatha ;
   Dmcapqa = ( mcapqinfa - mcapqa ) / taucapqma ;
   Dhcapqa = ( hcapqinfa - hcapqa ) / taucapqha ;
   Dmnaa = ( mnainfa - mnaa ) / taunama ;
   Dhnaa = ( hnainfa - hnaa ) / taunaha ;
   Dmkaa = ( mkainfa - mkaa ) / taukama ;
   Dhkaa = ( hkainfa - hkaa ) / taukaha ;
   Dmkdra = ( mkdrinfa - mkdra ) / taukdrma ;
   Dca = fcyta * ( Jmema + Jera ) ;
   Dcmdpqa = fmda * JPQa - fmda * Ba * ( cmdpqa - ca ) ;
   Dcera = - fera * sigmava * Jera ;
   Dn1a = tmsb * ( - ( 3.0 * k1a * cmdpqa + rm1a ) * n1a + km1a * n2a + r1a * n5a ) ;
   Dn2a = tmsb * ( 3.0 * k1a * cmdpqa * n1a - ( 2.0 * k1a * cmdpqa + km1a ) * n2a + 2.0 * km1a * n3a ) ;
   Dn3a = tmsb * ( 2.0 * k1a * cmdpqa * n2a - ( 2.0 * km1a + k1a * cmdpqa ) * n3a + 3.0 * km1a * n4a ) ;
   Dn4a = tmsb * ( k1a * cmdpqa * n3a - ( 3.0 * km1a + u1a ) * n4a ) ;
   Dn5a = tmsb * ( rm1a * n1a - ( r1a + rm2a ) * n5a + r2a * n6a ) ;
   Dn6a = tmsb * ( r3a + rm2a * n5a - ( rm3a + r2a ) * n6a ) ;
   Dnfa = tmsb * ( u1a * n4a - u2a * nfa ) ;
   Dnra = tmsb * ( u2a * nfa - u3a * nra ) ;
   DG = JGS / vc - fa * G ;
   Dvd = - ( icald + icapqd + inad + ikdrd + ikatpd + ikad + ild + iGABA ) / cma ;
   Dmcald = ( mcalinfd - mcald ) / taucalmd ;
   Dhcald = ( hcalinfd - hcald ) / taucalhd ;
   Dmcapqd = ( mcapqinfd - mcapqd ) / taucapqmd ;
   Dhcapqd = ( hcapqinfd - hcapqd ) / taucapqhd ;
   Dmnad = ( mnainfd - mnad ) / taunamd ;
   Dhnad = ( hnainfd - hnad ) / taunahd ;
   Dmkad = ( mkainfd - mkad ) / taukamd ;
   Dhkad = ( hkainfd - hkad ) / taukahd ;
   Dmkdrd = ( mkdrinfd - mkdrd ) / taukdrmd ;
   Dcd = fcytd * ( Jmemd + Jerd ) ;
   Dcmdld = fmdd * JLd - fmdd * Bd * ( cmdld - cd ) ;
   Dcmdpqd = fmdd * JPQd - fmdd * Bd * ( cmdpqd - cd ) ;
   Dcerd = - ferd * sigmavd * Jerd ;
   DS = JSS / vc - fd * S ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 Dvb = Dvb  / (1. - dt*( 0.0 )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taun )) ;
 Dc = Dc  / (1. - dt*( 0.0 )) ;
 Dcer = Dcer  / (1. - dt*( 0.0 )) ;
 Dcmd = Dcmd  / (1. - dt*( ( fmd )*( ( ( - ( B )*( ( 1.0 ) ) ) ) ) )) ;
 Dg6p = Dg6p  / (1. - dt*( 0.0 )) ;
 Dfbp = Dfbp  / (1. - dt*( 0.0 )) ;
 Dadpm = Dadpm  / (1. - dt*( 0.0 )) ;
 Dcam = Dcam  / (1. - dt*( 0.0 )) ;
 DNADHm = DNADHm  / (1. - dt*( 0.0 )) ;
 DPsim = DPsim  / (1. - dt*( 0.0 )) ;
 Dadp = Dadp  / (1. - dt*( 0.0 )) ;
 Dn1 = Dn1  / (1. - dt*( ( tmsb )*( ( ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) )*( 1.0 ) ) ) )) ;
 Dn2 = Dn2  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * exo_k1 * mod_cmd + km1 ) )*( 1.0 ) ) ) ) )) ;
 Dn3 = Dn3  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * km1 + exo_k1 * mod_cmd ) )*( 1.0 ) ) ) ) )) ;
 Dn4 = Dn4  / (1. - dt*( ( tmsb )*( ( ( - ( ( 3.0 * km1 + u1 ) )*( 1.0 ) ) ) ) )) ;
 Dn5 = Dn5  / (1. - dt*( ( tmsb )*( ( ( - ( ( r1 + rm2b ) )*( 1.0 ) ) ) ) )) ;
 Dn6 = Dn6  / (1. - dt*( ( tmsb )*( ( ( - ( ( rm3 + r2 ) )*( 1.0 ) ) ) ) )) ;
 Dnf = Dnf  / (1. - dt*( ( tmsb )*( ( ( - ( u2 )*( 1.0 ) ) ) ) )) ;
 Dnr = Dnr  / (1. - dt*( ( tmsb )*( ( ( - ( u3 )*( 1.0 ) ) ) ) )) ;
 DI = DI  / (1. - dt*( ( - ( fb )*( 1.0 ) ) )) ;
 Dva = Dva  / (1. - dt*( 0.0 )) ;
 Dmcala = Dmcala  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucalma )) ;
 Dhcala = Dhcala  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucalha )) ;
 Dmcata = Dmcata  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucatma )) ;
 Dhcata = Dhcata  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucatha )) ;
 Dmcapqa = Dmcapqa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucapqma )) ;
 Dhcapqa = Dhcapqa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucapqha )) ;
 Dmnaa = Dmnaa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taunama )) ;
 Dhnaa = Dhnaa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taunaha )) ;
 Dmkaa = Dmkaa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukama )) ;
 Dhkaa = Dhkaa  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukaha )) ;
 Dmkdra = Dmkdra  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukdrma )) ;
 Dca = Dca  / (1. - dt*( 0.0 )) ;
 Dcmdpqa = Dcmdpqa  / (1. - dt*( ( - ( fmda * Ba )*( ( 1.0 ) ) ) )) ;
 Dcera = Dcera  / (1. - dt*( 0.0 )) ;
 Dn1a = Dn1a  / (1. - dt*( ( tmsb )*( ( ( - ( 3.0 * k1a * cmdpqa + rm1a ) )*( 1.0 ) ) ) )) ;
 Dn2a = Dn2a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * k1a * cmdpqa + km1a ) )*( 1.0 ) ) ) ) )) ;
 Dn3a = Dn3a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 2.0 * km1a + k1a * cmdpqa ) )*( 1.0 ) ) ) ) )) ;
 Dn4a = Dn4a  / (1. - dt*( ( tmsb )*( ( ( - ( ( 3.0 * km1a + u1a ) )*( 1.0 ) ) ) ) )) ;
 Dn5a = Dn5a  / (1. - dt*( ( tmsb )*( ( ( - ( ( r1a + rm2a ) )*( 1.0 ) ) ) ) )) ;
 Dn6a = Dn6a  / (1. - dt*( ( tmsb )*( ( ( - ( ( rm3a + r2a ) )*( 1.0 ) ) ) ) )) ;
 Dnfa = Dnfa  / (1. - dt*( ( tmsb )*( ( ( - ( u2a )*( 1.0 ) ) ) ) )) ;
 Dnra = Dnra  / (1. - dt*( ( tmsb )*( ( ( - ( u3a )*( 1.0 ) ) ) ) )) ;
 DG = DG  / (1. - dt*( ( - ( fa )*( 1.0 ) ) )) ;
 Dvd = Dvd  / (1. - dt*( 0.0 )) ;
 Dmcald = Dmcald  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucalmd )) ;
 Dhcald = Dhcald  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucalhd )) ;
 Dmcapqd = Dmcapqd  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucapqmd )) ;
 Dhcapqd = Dhcapqd  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taucapqhd )) ;
 Dmnad = Dmnad  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taunamd )) ;
 Dhnad = Dhnad  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taunahd )) ;
 Dmkad = Dmkad  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukamd )) ;
 Dhkad = Dhkad  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukahd )) ;
 Dmkdrd = Dmkdrd  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taukdrmd )) ;
 Dcd = Dcd  / (1. - dt*( 0.0 )) ;
 Dcmdld = Dcmdld  / (1. - dt*( ( - ( fmdd * Bd )*( ( 1.0 ) ) ) )) ;
 Dcmdpqd = Dcmdpqd  / (1. - dt*( ( - ( fmdd * Bd )*( ( 1.0 ) ) ) )) ;
 Dcerd = Dcerd  / (1. - dt*( 0.0 )) ;
 DS = DS  / (1. - dt*( ( - ( fd )*( 1.0 ) ) )) ;
  return 0;
}
 /*END CVODE*/
 
static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 60;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 60; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 60,_slist2, _p, states, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   Dvb = - ( ik + ica + ikca + ikatp + iGIRKb ) / cm ;
   Dn = ( ninf - n ) / taun ;
   Dc = fcyt * ( Jmem + Jer + delta * Jmito ) ;
   Dcer = - fer * sigmav * Jer ;
   Dcmd = fmd * ( JL - B * ( cmd - c ) ) ;
   Dg6p = Jgk_ms - pfk_ms ;
   Dfbp = pfk_ms - 0.5 * Jgpdh ;
   Dadpm = gamma * ( Jant - JF1F0 ) ;
   Dcam = - fmito * Jmito ;
   DNADHm = gamma * ( Jpdh - JO ) ;
   DPsim = ( JHres - JHatp - Jant - JHleak - JNaCa - 2.0 * Juni ) / Cmito ;
   Dadp = ( - delta * Jant + Jhyd ) / taua ;
   Dn1 = tmsb * ( - ( 3.0 * exo_k1 * mod_cmd + rm1 ) * n1 + km1 * n2 + r1 * n5 ) ;
   Dn2 = tmsb * ( 3.0 * exo_k1 * mod_cmd * n1 - ( 2.0 * exo_k1 * mod_cmd + km1 ) * n2 + 2.0 * km1 * n3 ) ;
   Dn3 = tmsb * ( 2.0 * exo_k1 * mod_cmd * n2 - ( 2.0 * km1 + exo_k1 * mod_cmd ) * n3 + 3.0 * km1 * n4 ) ;
   Dn4 = tmsb * ( exo_k1 * mod_cmd * n3 - ( 3.0 * km1 + u1 ) * n4 ) ;
   Dn5 = tmsb * ( rm1 * n1 - ( r1 + rm2b ) * n5 + r2 * n6 ) ;
   Dn6 = tmsb * ( r3 + rm2b * n5 - ( rm3 + r2 ) * n6 ) ;
   Dnf = tmsb * ( u1 * n4 - u2 * nf ) ;
   Dnr = tmsb * ( u2 * nf - u3 * nr ) ;
   DI = JIS / vc - fb * I ;
   Dva = - ( icala + icata + icapqa + inaa + ikdra + ikatpa + ikaa + ila + isoca + iGIRKa ) / cma ;
   Dmcala = ( mcalinfa - mcala ) / taucalma ;
   Dhcala = ( hcalinfa - hcala ) / taucalha ;
   Dmcata = ( mcatinfa - mcata ) / taucatma ;
   Dhcata = ( hcatinfa - hcata ) / taucatha ;
   Dmcapqa = ( mcapqinfa - mcapqa ) / taucapqma ;
   Dhcapqa = ( hcapqinfa - hcapqa ) / taucapqha ;
   Dmnaa = ( mnainfa - mnaa ) / taunama ;
   Dhnaa = ( hnainfa - hnaa ) / taunaha ;
   Dmkaa = ( mkainfa - mkaa ) / taukama ;
   Dhkaa = ( hkainfa - hkaa ) / taukaha ;
   Dmkdra = ( mkdrinfa - mkdra ) / taukdrma ;
   Dca = fcyta * ( Jmema + Jera ) ;
   Dcmdpqa = fmda * JPQa - fmda * Ba * ( cmdpqa - ca ) ;
   Dcera = - fera * sigmava * Jera ;
   Dn1a = tmsb * ( - ( 3.0 * k1a * cmdpqa + rm1a ) * n1a + km1a * n2a + r1a * n5a ) ;
   Dn2a = tmsb * ( 3.0 * k1a * cmdpqa * n1a - ( 2.0 * k1a * cmdpqa + km1a ) * n2a + 2.0 * km1a * n3a ) ;
   Dn3a = tmsb * ( 2.0 * k1a * cmdpqa * n2a - ( 2.0 * km1a + k1a * cmdpqa ) * n3a + 3.0 * km1a * n4a ) ;
   Dn4a = tmsb * ( k1a * cmdpqa * n3a - ( 3.0 * km1a + u1a ) * n4a ) ;
   Dn5a = tmsb * ( rm1a * n1a - ( r1a + rm2a ) * n5a + r2a * n6a ) ;
   Dn6a = tmsb * ( r3a + rm2a * n5a - ( rm3a + r2a ) * n6a ) ;
   Dnfa = tmsb * ( u1a * n4a - u2a * nfa ) ;
   Dnra = tmsb * ( u2a * nfa - u3a * nra ) ;
   DG = JGS / vc - fa * G ;
   Dvd = - ( icald + icapqd + inad + ikdrd + ikatpd + ikad + ild + iGABA ) / cma ;
   Dmcald = ( mcalinfd - mcald ) / taucalmd ;
   Dhcald = ( hcalinfd - hcald ) / taucalhd ;
   Dmcapqd = ( mcapqinfd - mcapqd ) / taucapqmd ;
   Dhcapqd = ( hcapqinfd - hcapqd ) / taucapqhd ;
   Dmnad = ( mnainfd - mnad ) / taunamd ;
   Dhnad = ( hnainfd - hnad ) / taunahd ;
   Dmkad = ( mkainfd - mkad ) / taukamd ;
   Dhkad = ( hkainfd - hkad ) / taukahd ;
   Dmkdrd = ( mkdrinfd - mkdrd ) / taukdrmd ;
   Dcd = fcytd * ( Jmemd + Jerd ) ;
   Dcmdld = fmdd * JLd - fmdd * Bd * ( cmdld - cd ) ;
   Dcmdpqd = fmdd * JPQd - fmdd * Bd * ( cmdpqd - cd ) ;
   Dcerd = - ferd * sigmavd * Jerd ;
   DS = JSS / vc - fd * S ;
   {int _id; for(_id=0; _id < 60; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int _ode_count(int _type){ return 60;}
 
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
	for (_i=0; _i < 60; ++_i) {
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
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(120, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(60);
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  G = G0;
  I = I0;
  NADHm = NADHm0;
  Psim = Psim0;
  S = S0;
  adp = adp0;
  adpm = adpm0;
  cerd = cerd0;
  cmdpqd = cmdpqd0;
  cmdld = cmdld0;
  cd = cd0;
  cera = cera0;
  cmdpqa = cmdpqa0;
  ca = ca0;
  cam = cam0;
  cmd = cmd0;
  cer = cer0;
  c = c0;
  fbp = fbp0;
  g6p = g6p0;
  hkad = hkad0;
  hnad = hnad0;
  hcapqd = hcapqd0;
  hcald = hcald0;
  hkaa = hkaa0;
  hnaa = hnaa0;
  hcapqa = hcapqa0;
  hcata = hcata0;
  hcala = hcala0;
  mkdrd = mkdrd0;
  mkad = mkad0;
  mnad = mnad0;
  mcapqd = mcapqd0;
  mcald = mcald0;
  mkdra = mkdra0;
  mkaa = mkaa0;
  mnaa = mnaa0;
  mcapqa = mcapqa0;
  mcata = mcata0;
  mcala = mcala0;
  nra = nra0;
  nfa = nfa0;
  n6a = n6a0;
  n5a = n5a0;
  n4a = n4a0;
  n3a = n3a0;
  n2a = n2a0;
  n1a = n1a0;
  nr = nr0;
  nf = nf0;
  n6 = n60;
  n5 = n50;
  n4 = n40;
  n3 = n30;
  n2 = n20;
  n1 = n10;
  n = n0;
  vd = vd0;
  va = va0;
  vb = vb0;
 {
   vb = - 71.33779976819424 ;
   n = 9.875188779513991e-05 ;
   c = 0.0630015242008439 ;
   cer = 81.57023672312617 ;
   cmd = 0.4188629403487558 ;
   g6p = 244.936858732948 ;
   fbp = 0.08283840527865462 ;
   adpm = 13.53015038508978 ;
   cam = 0.01102007399722167 ;
   NADHm = 0.02908310367935971 ;
   Psim = 151.1015153147079 ;
   adp = 1913.096601466651 ;
   n1 = 4.627586868810905 ;
   n2 = 0.2262327588817945 ;
   n3 = 0.003661670524646639 ;
   n4 = 2.595179480355916e-06 ;
   n5 = 7.762125378310579 ;
   n6 = 274.1666227230976 ;
   nf = 0.00172689211245988 ;
   nr = 0.3002686554719045 ;
   va = - 49.03736299581227 ;
   mcala = 0.1293341713632475 ;
   hcala = 0.8127842536675057 ;
   mcata = 0.4633857551023612 ;
   hcata = 0.3735421388722815 ;
   mcapqa = 0.0120465460803863 ;
   hcapqa = 0.8127842536675057 ;
   mnaa = 0.007938786735335676 ;
   hnaa = 0.2498175179717122 ;
   mkaa = 0.4001652246173745 ;
   hkaa = 0.1373195977592295 ;
   mkdra = 0.2674634279865117 ;
   ca = 0.3449148387259899 ;
   cmdpqa = 11.51299890826233 ;
   cera = 58.71698724650182 ;
   n1a = 1.057203539612775e-05 ;
   n2a = 2.113947666062938e-05 ;
   n3a = 2.388848788981755e-05 ;
   n4a = 2.391806975716259e-06 ;
   n5a = 0.008850176609826538 ;
   n6a = 12.69715161782077 ;
   nfa = 0.001724142875712899 ;
   nra = 0.1927364884362762 ;
   vd = - 16.26895428994972 ;
   mcald = 0.8218051702003508 ;
   hcald = 0.6672499701175263 ;
   mcapqd = 0.5089033026581684 ;
   hcapqd = 0.6672499701175263 ;
   mnad = 0.9737137320580179 ;
   hnad = 0.006777955247303555 ;
   mkad = 0.9480884005315277 ;
   hkad = 0.02771925786328598 ;
   mkdrd = 0.5717652452166768 ;
   cd = 0.3051356309084454 ;
   cmdld = 19.82903375122306 ;
   cmdpqd = 27.93917378868966 ;
   cerd = 413.8135591677398 ;
   I = 48.04298494148047 ;
   G = 31.73727470720019 ;
   S = 18.71318922819339 ;
   taucalma = 0.3032811940166806 ;
   taucalha = 56.12989393816361 ;
   mcalinfa = 0.1296861831162709 ;
   hcalinfa = 0.9611145179788654 ;
   icala = - 1.08529313843157 ;
   mcapqinfa = 0.012083750627573104 ;
   hcapqinfa = 0.9611145179788654 ;
   taucapqma = 0.3032811940166806 ;
   taucapqha = 56.12989393816361 ;
   icapqa = - 0.6699405169228547 ;
   mcatinfa = 0.4976648297402624 ;
   hcatinfa = 0.3560551615487483 ;
   taucatma = 7.475932505911923 ;
   taucatha = 14.979442612364645 ;
   icata = - 2.1192627702105704 ;
   gGIRKbara = 0.025 ;
   EffSa = 0.16401112054523317 ;
   iGIRKa = 0.1269554197523033 ;
   rm2a = 0.49718657776876884 ;
   cinfa = 0.6374123727563218 ;
   isoca = - 0.7814255475218438 ;
   JLa = 0.009009324450441558 ;
   JPQa = 2.461199913234317 ;
   JTa = 0.017592597996299284 ;
   Jmema = - 0.051632659173903986 ;
   Jsercaa = 0.017245741936299495 ;
   Jleaka = 0.017511621722332747 ;
   Jera = 0.0002658797860332525 ;
   r2a = 0.0007824407054832726 ;
   r3a = 0.00785700875089453 ;
   JGS = 4.760591264376022e-10 ;
   mkainfa = 0.40041498568618583 ;
   hkainfa = 0.13053193445833075 ;
   taukaha = 9.00677536264756 ;
   ikaa = 1.4266606033882763 ;
   EffIa = 0.10001054147411872 ;
   gkatpa = 0.3000316244223562 ;
   ikatpa = 7.789612154654419 ;
   mkdrinfa = 0.26016661765554117 ;
   taukdrma = 15.30146142661036 ;
   ikdra = 0.5978867667431156 ;
   ila = - 5.807472599162455 ;
   mnainfa = 0.008498416028612855 ;
   hnainfa = 0.40846137482156436 ;
   taunama = 3.036153418307839 ;
   taunaha = 60.06822869326301 ;
   inaa = - 0.00016366705880007713 ;
   minf = 0.0014513916520931425 ;
   ica = - 577.4726176457064 ;
   gGIRKbarb = 10.0 ;
   EffSb = 0.16401112054523317 ;
   iGIRKb = 14.206971664056404 ;
   r20 = 0.006001031554023141 ;
   rm2b = 0.00022097181234167506 ;
   ikca = 16.025854402092854 ;
   ical = - 288.7363088228532 ;
   icar = - 288.7363088228532 ;
   topo = 309.906384691809 ;
   bottomo = 15423.383945456666 ;
   katpo = 0.020093280812288894 ;
   ikatp = 549.3300347708633 ;
   vmdcyt = 0.0036521739130434784 ;
   JL = 0.3561081142148523 ;
   JR = 0.001300568764958591 ;
   Jmem = - 6.829449607573257e-08 ;
   Jserca = 0.01630015242008439 ;
   Jleak = 0.016301447039785068 ;
   Jer = 1.2946197006785676e-06 ;
   f6p = 73.4810576198844 ;
   Jgpdh = 0.00014390830872351902 ;
   Jgk_ms = 0.0004 ;
   mod_cmd = 0.08150591626797878 ;
   weight2 = 2296.370661399967 ;
   topa2 = 0.0 ;
   bottom2 = 2297.370661399967 ;
   weight3 = 0.10798931657873541 ;
   topa3 = 0.10798931657873541 ;
   bottom3 = 2297.478650716546 ;
   weight4 = 12.399174916802055 ;
   topa4 = 12.50716423338079 ;
   bottom4 = 2309.877825633348 ;
   weight5 = 0.08283840527865462 ;
   topa5 = 12.50716423338079 ;
   bottom5 = 2309.960664038627 ;
   weight6 = 9.51138417595313 ;
   topa6 = 12.50716423338079 ;
   bottom6 = 2319.47204821458 ;
   weight7 = 0.044728313862571104 ;
   topa7 = 12.55189254724336 ;
   bottom7 = 2319.5167765284423 ;
   weight8 = 0.2567819692197443 ;
   topa8 = 12.808674516463105 ;
   bottom8 = 2319.773558497662 ;
   weight9 = 16.666666666666668 ;
   topa9 = 12.808674516463105 ;
   bottom9 = 2336.4402251643287 ;
   weight10 = 1913.642217833306 ;
   topa10 = 12.808674516463105 ;
   bottom10 = 4250.082442997635 ;
   weight11 = 89.99109714894618 ;
   topa11 = 102.79977166540928 ;
   bottom11 = 4340.073540146581 ;
   weight12 = 516.6322882000856 ;
   topa12 = 619.4320598654948 ;
   bottom12 = 4856.705828346667 ;
   weight13 = 1.380640087977577 ;
   topa13 = 619.4320598654948 ;
   bottom13 = 4858.086468434644 ;
   weight14 = 7.926153479960942 ;
   topa14 = 619.4320598654948 ;
   bottom14 = 4866.012621914605 ;
   weight15 = 37.273594885475916 ;
   topa15 = 619.4320598654948 ;
   topb = 37.273594885475916 ;
   bottom15 = 4903.286216800081 ;
   weight16 = 10.699248717489347 ;
   topa16 = 630.1313085829842 ;
   bottom16 = 4913.98546551757 ;
   pfk = 0.07639570154136274 ;
   pfk_ms = 7.639570154136274e-05 ;
   Juni = 0.01962392608626012 ;
   JNaCa = 0.019624306722058324 ;
   Jmito = 3.806357982034936e-07 ;
   NADm = 9.97091689632064 ;
   ATPm = 1.4698496149102205 ;
   RATm = 0.10863512770190598 ;
   Jpdh = 0.13463853801663372 ;
   JHleak = 0.27220303062941587 ;
   MM1 = 0.13518316270858338 ;
   JO = 0.13442638085707123 ;
   MM2 = 1.5771368982668066 ;
   JHres = 1.5683077766658313 ;
   b2 = 30.514785437554284 ;
   JF1F0 = 0.31088837377098194 ;
   JHatp = 0.9326651213129458 ;
   FRT = 0.037410133089805564 ;
   Jant = 0.304446602316938 ;
   atp = 586.903398533349 ;
   Jhyd = 0.031193960359980264 ;
   mgadp = 315.6609392419974 ;
   adp3m = 258.2680411979979 ;
   atp4m = 29.345169926667452 ;
   ampfactor = 0.25298632618462513 ;
   r3 = 0.040127765219777956 ;
   r2 = 0.0001599974146477454 ;
   JIS = 9.608596975100945e-09 ;
   ninf = 9.873556239473554e-05 ;
   ik = 0.6509685354743112 ;
   mcalinfd = 0.797881280658739 ;
   hcalinfd = 0.03401952024443635 ;
   taucalmd = 0.5229606925470396 ;
   taucalhd = 73.2304683206763 ;
   icald = - 25.635926220427873 ;
   mcapqinfd = 0.468318643634233 ;
   hcapqinfd = 0.03401952024443635 ;
   taucapqmd = 0.5229606925470396 ;
   taucapqhd = 73.2304683206763 ;
   icapqd = - 19.317305313715206 ;
   gGABAbar = 0.1 ;
   EffId = 41.56833392753747 ;
   iGABA = - 67.62733245764733 ;
   mkainfd = 0.9465007724360222 ;
   hkainfd = 0.005635014702807043 ;
   taukahd = 23.509361336319593 ;
   ikad = 0.7717349514854953 ;
   ikatpd = 17.03200325591458 ;
   mkdrinfd = 0.5937792009880476 ;
   taukdrmd = 15.72702251180529 ;
   ikdrd = 47.07604938593722 ;
   ild = 0.7462091420100564 ;
   mnainfd = 0.9687128701879236 ;
   hnainfd = 0.011358328217907197 ;
   taunamd = 0.255456748187674 ;
   taunahd = 2.2698475854851585 ;
   inad = - 2.699088467105948 ;
   JLd = 62.63872538764923 ;
   JPQd = 70.96712164896792 ;
   Jmemd = 0.037293490573121604 ;
   Jsercad = 0.12205425236337818 ;
   Jleakd = 0.1240525270610494 ;
   Jerd = 0.0019982746976712207 ;
   y = 0.19225889978869892 ;
   Som = 0.0074284530481816 ;
   JSS = 4.412501110619871e-14 ;
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
 {  _deriv1_advance = 1;
 derivimplicit_thread(60, _slist1, _dlist1, _p, states, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 60; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   gGABAbar = ( 1.0 - knockoutbd ) * 0.1 + knockoutbd * 0.0 ;
   EffId = 0.8 / ( 1.0 + exp ( - ( I - 1500.0 ) / 500.0 ) ) ;
   iGABA = gGABAbar * EffId * ( vd - vGABA ) ;
   EffIa = ( 1.0 - knockoutba ) * ( ( 0.015 / ( 1.0 + exp ( ( - I + 1500.0 ) / 200.0 ) ) ) + ka1 ) + knockoutba * ka1 ;
   gkatpa = gkatpbara * EffIa ;
   ikatpa = gkatpa * ( va - vka ) ;
   gGIRKbara = ( 1.0 - knockoutda ) * 0.025 + knockoutda * gGIRKko ;
   EffSa = 1.0 / ( 1.0 + exp ( - ( S - sombara2 ) / ssom2 ) ) ;
   iGIRKa = gGIRKbara * EffSa * ( va - vGIRK ) ;
   rm2a = ( 1.0 - knockoutda ) * ra / ( 1.0 + exp ( - ( S - sombara ) / ssom ) ) + knockoutda * rako ;
   r20 = 0.004 / ( 1.0 + exp ( - G + gthresh ) ) + 0.006 ;
   gGIRKbarb = ( 1.0 - knockoutdb ) * 10.0 + knockoutdb * 0.0 ;
   EffSb = 1.0 / ( 1.0 + exp ( - ( S - sombarb2 ) / 10.0 ) ) ;
   iGIRKb = gGIRKbarb * EffSb * ( vb - vGIRK ) ;
   rm2b = ( 1.0 - knockoutdb ) * rb / ( 1.0 + exp ( - ( S - sombarb ) / ssomb ) ) + knockoutdb * 0.001 ;
   ikca = gkca / ( 1.0 + pow( ( kd / c ) , 2.0 ) ) * ( vb - vk ) ;
   minf = 1.0 / ( 1.0 + exp ( ( vm - vb ) / sm ) ) ;
   ica = gca * nca * minf * ( vb - vca ) ;
   ical = raL * ica ;
   icar = ( 1.0 - raL ) * ica ;
   ninf = 1.0 / ( 1.0 + exp ( ( vn - vb ) / sn ) ) ;
   ik = gk * n * ( vb - vk ) ;
   topo = 0.08 * ( 1.0 + 2.0 * mgadp / kdd ) + 0.89 * pow( ( mgadp / kdd ) , 2.0 ) ;
   bottomo = pow( ( 1.0 + mgadp / kdd ) , 2.0 ) * ( 1.0 + adp3m / ktd + atp4m / ktt ) ;
   katpo = ( topo / bottomo ) ;
   ikatp = gkatpb * ( vb - vk ) ;
   vmdcyt = vmd / vcell ;
   JL = - alpha * ical / vmd ;
   JR = - alpha * icar / vcell ;
   Jmem = JR + vmdcyt * B * ( cmd - c ) - kpmca * ( c - cbas ) ;
   Jserca = kserca2b + kserca3 * c ;
   Jleak = per * ( cer - c ) ;
   Jer = ( Jleak - Jserca ) ;
   f6p = phigk * g6p ;
   Jgpdh = KGPDH * sqrt ( fbp ) ;
   Jgk_ms = kappa * Jgk ;
   mod_cmd = bas_cmd + max_cmd * pow( cmd , cmdp ) / ( pow( cmd , cmdp ) + pow( kcmd , cmdp ) ) ;
   weight2 = pow( atp , 2.0 ) / k4 ;
   topa2 = topa1 ;
   bottom2 = bottom1 + weight2 ;
   weight3 = pow( f6p , 2.0 ) / k3 ;
   topa3 = topa2 + weight3 ;
   bottom3 = bottom2 + weight3 ;
   weight4 = pow( ( f6p * atp ) , 2.0 ) / ( f43 * k3 * k4 ) ;
   topa4 = topa3 + weight4 ;
   bottom4 = bottom3 + weight4 ;
   weight5 = fbp / k2 ;
   topa5 = topa4 ;
   bottom5 = bottom4 + weight5 ;
   weight6 = ( fbp * pow( atp , 2.0 ) ) / ( k2 * k4 * f42 ) ;
   topa6 = topa5 ;
   bottom6 = bottom5 + weight6 ;
   weight7 = ( fbp * pow( f6p , 2.0 ) ) / ( k2 * k3 * f23 ) ;
   topa7 = topa6 + weight7 ;
   bottom7 = bottom6 + weight7 ;
   weight8 = ( fbp * pow( f6p , 2.0 ) * pow( atp , 2.0 ) ) / ( k2 * k3 * k4 * f23 * f42 * f43 ) ;
   topa8 = topa7 + weight8 ;
   bottom8 = bottom7 + weight8 ;
   weight9 = amp / k1 ;
   topa9 = topa8 ;
   bottom9 = bottom8 + weight9 ;
   weight10 = ( amp * pow( atp , 2.0 ) ) / ( k1 * k4 * f41 ) ;
   topa10 = topa9 ;
   bottom10 = bottom9 + weight10 ;
   weight11 = ( amp * pow( f6p , 2.0 ) ) / ( k1 * k3 * f13 ) ;
   topa11 = topa10 + weight11 ;
   bottom11 = bottom10 + weight11 ;
   weight12 = ( amp * pow( f6p , 2.0 ) * pow( atp , 2.0 ) ) / ( k1 * k3 * k4 * f13 * f41 * f43 ) ;
   topa12 = topa11 + weight12 ;
   bottom12 = bottom11 + weight12 ;
   weight13 = ( amp * fbp ) / ( k1 * k2 ) ;
   topa13 = topa12 ;
   bottom13 = bottom12 + weight13 ;
   weight14 = ( amp * fbp * pow( atp , 2.0 ) ) / ( k1 * k2 * k4 * f42 * f41 ) ;
   topa14 = topa13 ;
   bottom14 = bottom13 + weight14 ;
   weight15 = ( amp * fbp * pow( f6p , 2.0 ) ) / ( k1 * k2 * k3 * f23 * f13 ) ;
   topa15 = topa14 ;
   topb = weight15 ;
   bottom15 = bottom14 + weight15 ;
   weight16 = ( amp * fbp * pow( f6p , 2.0 ) * pow( atp , 2.0 ) ) / ( k1 * k2 * k3 * k4 * f23 * f13 * f42 * f41 * f43 ) ;
   topa16 = topa15 + weight16 ;
   bottom16 = bottom15 + weight16 ;
   pfk = ( lambda * VmaxPFK * topa16 + VmaxPFK * topb ) / bottom16 ;
   pfk_ms = kappa * pfk ;
   delta = 3.9 / 53.2 ;
   Juni = ( p21 * Psim - p22 ) * pow( c , 2.0 ) ;
   JNaCa = ( p23 / c ) * cam * exp ( p24 * Psim ) ;
   Jmito = JNaCa - Juni ;
   NADm = NADmtot - NADHm ;
   ATPm = Amtot - adpm ;
   RATm = ATPm / adpm ;
   Jpdh = ( p1 / ( p2 + NADHm / NADm ) ) * ( cam / ( p3 + cam ) ) * ( Jgpdh + Jgpdh_bas ) ;
   JHleak = p17 * Psim + p18 ;
   MM1 = p4 * NADHm / ( p5 + NADHm ) ;
   JO = MM1 / ( 1.0 + exp ( ( Psim - p6 ) / p7 ) ) ;
   MM2 = p8 * NADHm / ( p9 + NADHm ) ;
   JHres = MM2 / ( 1.0 + exp ( ( Psim - p10 ) / p11 ) ) ;
   b2 = ( p16 * p13 ) / ( p13 + ATPm ) ;
   JF1F0 = b2 / ( 1.0 + exp ( ( p14 - Psim ) / p15 ) ) ;
   JHatp = 3.0 * JF1F0 ;
   FRT = 96480.0 / ( 310.16 * 8315.0 ) ;
   Jant = p19 * ( RATm / ( RATm + p20 ) ) / exp ( - 0.5 * FRT * Psim ) ;
   atp = atot - adp ;
   Jhyd = ( khyd * c + JhydSS ) * atp ;
   mgadp = 0.165 * adp ;
   adp3m = 0.135 * adp ;
   atp4m = 0.05 * atp ;
   ampfactor = factor * pow( JO , 2.0 ) ;
   r3 = bas_r3 + amplify * ampfactor * r30 * c / ( c + Kp ) ;
   r2 = r20 * c / ( c + Kp2 ) ;
   JIS = tmsb * u3 * nr * 0.0016 ;
   mcalinfa = 1.0 / ( 1.0 + exp ( - ( va - vcalma ) / scalma ) ) ;
   hcalinfa = 1.0 / ( 1.0 + exp ( - ( va - vcalha ) / scalha ) ) ;
   taucalma = ( 1.0 / ( exp ( - ( va + 23.0 ) / 20.0 ) + exp ( ( va + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   taucalha = ( tcalh1a / ( exp ( - ( va + 0.0 ) / 20.0 ) + exp ( ( va + 0.0 ) / 20.0 ) ) ) + tcalh2a ;
   icala = gcala * pow( mcala , 2.0 ) * hcala * ( va - vcaa ) ;
   mcatinfa = 1.0 / ( 1.0 + exp ( - ( va - vcatma ) / scatma ) ) ;
   hcatinfa = 1.0 / ( 1.0 + exp ( - ( va - vcatha ) / scatha ) ) ;
   taucatma = ( tcatm1a / ( exp ( - ( va + 50.0 ) / 12.0 ) + exp ( ( va + 50.0 ) / 12.0 ) ) ) + tcatm2a ;
   taucatha = ( tcath1a / ( exp ( - ( va + 50.0 ) / 15.0 ) + exp ( ( va + 50.0 ) / 15.0 ) ) ) + tcath2a ;
   icata = gcata * pow( mcata , 3.0 ) * hcata * ( va - vcaa ) ;
   mcapqinfa = 1.0 / ( 1.0 + exp ( - ( va - vcapqma ) / scapqma ) ) ;
   hcapqinfa = 1.0 / ( 1.0 + exp ( - ( va - vcapqha ) / scapqha ) ) ;
   taucapqma = ( 1.0 / ( exp ( - ( va + 23.0 ) / 20.0 ) + exp ( ( va + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   taucapqha = ( tcapqh1a / ( exp ( - ( va + 0.0 ) / 20.0 ) + exp ( ( va + 0.0 ) / 20.0 ) ) ) + tcapqh2a ;
   icapqa = gcapqa * mcapqa * hcapqa * ( va - vcaa ) ;
   mnainfa = 1.0 / ( 1.0 + exp ( - ( va - vnama ) / snama ) ) ;
   hnainfa = 1.0 / ( 1.0 + exp ( - ( va - vnaha ) / snaha ) ) ;
   taunama = ( 6.0 / ( exp ( - ( va + 50.0 ) / 10.0 ) + exp ( ( va + 50.0 ) / 10.0 ) ) ) + 0.05 ;
   taunaha = ( tnah1a / ( exp ( - ( va + 50.0 ) / 8.0 ) + exp ( ( va + 50.0 ) / 8.0 ) ) ) + tnah2a ;
   inaa = gnaa * pow( mnaa , 3.0 ) * hnaa * ( va - vnaa ) ;
   mkainfa = 1.0 / ( 1.0 + exp ( - ( va - vkama ) / skama ) ) ;
   hkainfa = 1.0 / ( 1.0 + exp ( - ( va - vkaha ) / skaha ) ) ;
   taukaha = ( tkah1a / ( exp ( - ( va - 5.0 ) / 20.0 ) + exp ( ( va - 5.0 ) / 20.0 ) ) ) + tkah2a ;
   ikaa = gkaa * mkaa * hkaa * ( va - vka ) ;
   mkdrinfa = 1.0 / ( 1.0 + exp ( - ( va - vkdrma ) / skdrma ) ) ;
   taukdrma = ( 1.5 / ( exp ( - ( va + 10.0 ) / 25.0 ) + exp ( ( va + 10.0 ) / 25.0 ) ) ) + 15.0 ;
   ikdra = gkdra * pow( mkdra , 4.0 ) * ( va - vka ) ;
   ila = gla * ( va - vla ) ;
   cinfa = 1.0 / ( 1.0 + exp ( - ( cera - caerbara ) / ssoca ) ) ;
   isoca = gsocbara * cinfa * ( va - vsoca ) ;
   JLa = - alphaa * icala / vcella ;
   JPQa = - alphaa * icapqa / vmdpqa ;
   JTa = - alphaa * icata / vcella ;
   Jmema = JTa + JLa + fVpqa * Ba * ( cmdpqa - ca ) - kpmcaa * ca ;
   Jsercaa = ksercaa * ca ;
   Jleaka = pleaka * ( cera - ca ) ;
   Jera = Jleaka - Jsercaa ;
   r2a = r20a * ca / ( ca + kp2a ) ;
   r3a = GlucFacta * r30a * ca / ( ca + kpa ) ;
   JGS = tmsb * u3a * nra * 0.0000988 ;
   mcalinfd = 1.0 / ( 1.0 + exp ( - ( vd - vcalmd ) / scalmd ) ) ;
   hcalinfd = 1.0 / ( 1.0 + exp ( - ( vd - vcalhd ) / scalhd ) ) ;
   taucalmd = ( 1.0 / ( exp ( - ( vd + 23.0 ) / 20.0 ) + exp ( ( vd + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   taucalhd = ( tcalh1d / ( exp ( - ( vd + 0.0 ) / 20.0 ) + exp ( ( vd + 0.0 ) / 20.0 ) ) ) + tcalh2d ;
   icald = gcald * pow( mcald , 2.0 ) * hcald * ( vd - vcad ) ;
   mcapqinfd = 1.0 / ( 1.0 + exp ( - ( vd - vcapqmd ) / scapqmd ) ) ;
   hcapqinfd = 1.0 / ( 1.0 + exp ( - ( vd - vcapqhd ) / scapqhd ) ) ;
   taucapqmd = ( 1.0 / ( exp ( - ( vd + 23.0 ) / 20.0 ) + exp ( ( vd + 23.0 ) / 20.0 ) ) ) + 0.05 ;
   taucapqhd = ( tcapqh1d / ( exp ( - ( vd + 0.0 ) / 20.0 ) + exp ( ( vd + 0.0 ) / 20.0 ) ) ) + tcapqh2d ;
   icapqd = gcapqd * mcapqd * hcapqd * ( vd - vcad ) ;
   mnainfd = 1.0 / ( 1.0 + exp ( - ( vd - vnamd ) / snamd ) ) ;
   hnainfd = 1.0 / ( 1.0 + exp ( - ( vd - vnahd ) / snahd ) ) ;
   taunamd = ( 6.0 / ( exp ( - ( vd + 50.0 ) / 10.0 ) + exp ( ( vd + 50.0 ) / 10.0 ) ) ) + 0.05 ;
   taunahd = ( tnah1d / ( exp ( - ( vd + 50.0 ) / 8.0 ) + exp ( ( vd + 50.0 ) / 8.0 ) ) ) + tnah2d ;
   inad = gnad * pow( mnad , 3.0 ) * hnad * ( vd - vnad ) ;
   mkainfd = 1.0 / ( 1.0 + exp ( - ( vd - vkamd ) / skamd ) ) ;
   hkainfd = 1.0 / ( 1.0 + exp ( - ( vd - vkahd ) / skahd ) ) ;
   taukahd = ( tkah1d / ( exp ( - ( vd - 5.0 ) / 20.0 ) + exp ( ( vd - 5.0 ) / 20.0 ) ) ) + tkah2d ;
   ikad = gkad * mkad * hkad * ( vd - vkd ) ;
   mkdrinfd = 1.0 / ( 1.0 + exp ( - ( vd - vkdrmd ) / skdrmd ) ) ;
   taukdrmd = ( 1.5 / ( exp ( - ( vd + 10.0 ) / 25.0 ) + exp ( ( vd + 10.0 ) / 25.0 ) ) ) + 15.0 ;
   ikdrd = gkdrd * pow( mkdrd , 4.0 ) * ( vd - vkd ) ;
   ikatpd = gkatpbard * ( vd - vkd ) ;
   ild = gld * ( vd - vld ) ;
   JLd = - alphad * icald / vmdld ;
   JPQd = - alphad * icapqd / vmdpqd ;
   Jmemd = fVld * Bd * ( cmdld - cd ) + fVpqd * Bd * ( cmdpqd - cd ) - kpmcad * cd ;
   Jsercad = ksercad * cd ;
   Jleakd = pleakd * ( cerd - cd ) ;
   Jerd = ( Jleakd - Jsercad ) ;
   y = pow( ( cmdpqd / 200.0 ) , 4.0 ) / ( pow( 0.2 , 4.0 ) + pow( ( cmdpqd / 200.0 ) , 4.0 ) ) ;
   Som = ( 200.0 * mcapqd * hcapqd * ( y ) / tausom ) + bas ;
   JSS = tmsb * Som * con ;
   }
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(vb) - _p;  _dlist1[0] = &(Dvb) - _p;
 _slist1[1] = &(n) - _p;  _dlist1[1] = &(Dn) - _p;
 _slist1[2] = &(c) - _p;  _dlist1[2] = &(Dc) - _p;
 _slist1[3] = &(cer) - _p;  _dlist1[3] = &(Dcer) - _p;
 _slist1[4] = &(cmd) - _p;  _dlist1[4] = &(Dcmd) - _p;
 _slist1[5] = &(g6p) - _p;  _dlist1[5] = &(Dg6p) - _p;
 _slist1[6] = &(fbp) - _p;  _dlist1[6] = &(Dfbp) - _p;
 _slist1[7] = &(adpm) - _p;  _dlist1[7] = &(Dadpm) - _p;
 _slist1[8] = &(cam) - _p;  _dlist1[8] = &(Dcam) - _p;
 _slist1[9] = &(NADHm) - _p;  _dlist1[9] = &(DNADHm) - _p;
 _slist1[10] = &(Psim) - _p;  _dlist1[10] = &(DPsim) - _p;
 _slist1[11] = &(adp) - _p;  _dlist1[11] = &(Dadp) - _p;
 _slist1[12] = &(n1) - _p;  _dlist1[12] = &(Dn1) - _p;
 _slist1[13] = &(n2) - _p;  _dlist1[13] = &(Dn2) - _p;
 _slist1[14] = &(n3) - _p;  _dlist1[14] = &(Dn3) - _p;
 _slist1[15] = &(n4) - _p;  _dlist1[15] = &(Dn4) - _p;
 _slist1[16] = &(n5) - _p;  _dlist1[16] = &(Dn5) - _p;
 _slist1[17] = &(n6) - _p;  _dlist1[17] = &(Dn6) - _p;
 _slist1[18] = &(nf) - _p;  _dlist1[18] = &(Dnf) - _p;
 _slist1[19] = &(nr) - _p;  _dlist1[19] = &(Dnr) - _p;
 _slist1[20] = &(I) - _p;  _dlist1[20] = &(DI) - _p;
 _slist1[21] = &(va) - _p;  _dlist1[21] = &(Dva) - _p;
 _slist1[22] = &(mcala) - _p;  _dlist1[22] = &(Dmcala) - _p;
 _slist1[23] = &(hcala) - _p;  _dlist1[23] = &(Dhcala) - _p;
 _slist1[24] = &(mcata) - _p;  _dlist1[24] = &(Dmcata) - _p;
 _slist1[25] = &(hcata) - _p;  _dlist1[25] = &(Dhcata) - _p;
 _slist1[26] = &(mcapqa) - _p;  _dlist1[26] = &(Dmcapqa) - _p;
 _slist1[27] = &(hcapqa) - _p;  _dlist1[27] = &(Dhcapqa) - _p;
 _slist1[28] = &(mnaa) - _p;  _dlist1[28] = &(Dmnaa) - _p;
 _slist1[29] = &(hnaa) - _p;  _dlist1[29] = &(Dhnaa) - _p;
 _slist1[30] = &(mkaa) - _p;  _dlist1[30] = &(Dmkaa) - _p;
 _slist1[31] = &(hkaa) - _p;  _dlist1[31] = &(Dhkaa) - _p;
 _slist1[32] = &(mkdra) - _p;  _dlist1[32] = &(Dmkdra) - _p;
 _slist1[33] = &(ca) - _p;  _dlist1[33] = &(Dca) - _p;
 _slist1[34] = &(cmdpqa) - _p;  _dlist1[34] = &(Dcmdpqa) - _p;
 _slist1[35] = &(cera) - _p;  _dlist1[35] = &(Dcera) - _p;
 _slist1[36] = &(n1a) - _p;  _dlist1[36] = &(Dn1a) - _p;
 _slist1[37] = &(n2a) - _p;  _dlist1[37] = &(Dn2a) - _p;
 _slist1[38] = &(n3a) - _p;  _dlist1[38] = &(Dn3a) - _p;
 _slist1[39] = &(n4a) - _p;  _dlist1[39] = &(Dn4a) - _p;
 _slist1[40] = &(n5a) - _p;  _dlist1[40] = &(Dn5a) - _p;
 _slist1[41] = &(n6a) - _p;  _dlist1[41] = &(Dn6a) - _p;
 _slist1[42] = &(nfa) - _p;  _dlist1[42] = &(Dnfa) - _p;
 _slist1[43] = &(nra) - _p;  _dlist1[43] = &(Dnra) - _p;
 _slist1[44] = &(G) - _p;  _dlist1[44] = &(DG) - _p;
 _slist1[45] = &(vd) - _p;  _dlist1[45] = &(Dvd) - _p;
 _slist1[46] = &(mcald) - _p;  _dlist1[46] = &(Dmcald) - _p;
 _slist1[47] = &(hcald) - _p;  _dlist1[47] = &(Dhcald) - _p;
 _slist1[48] = &(mcapqd) - _p;  _dlist1[48] = &(Dmcapqd) - _p;
 _slist1[49] = &(hcapqd) - _p;  _dlist1[49] = &(Dhcapqd) - _p;
 _slist1[50] = &(mnad) - _p;  _dlist1[50] = &(Dmnad) - _p;
 _slist1[51] = &(hnad) - _p;  _dlist1[51] = &(Dhnad) - _p;
 _slist1[52] = &(mkad) - _p;  _dlist1[52] = &(Dmkad) - _p;
 _slist1[53] = &(hkad) - _p;  _dlist1[53] = &(Dhkad) - _p;
 _slist1[54] = &(mkdrd) - _p;  _dlist1[54] = &(Dmkdrd) - _p;
 _slist1[55] = &(cd) - _p;  _dlist1[55] = &(Dcd) - _p;
 _slist1[56] = &(cmdld) - _p;  _dlist1[56] = &(Dcmdld) - _p;
 _slist1[57] = &(cmdpqd) - _p;  _dlist1[57] = &(Dcmdpqd) - _p;
 _slist1[58] = &(cerd) - _p;  _dlist1[58] = &(Dcerd) - _p;
 _slist1[59] = &(S) - _p;  _dlist1[59] = &(DS) - _p;
 _slist2[0] = &(G) - _p;
 _slist2[1] = &(I) - _p;
 _slist2[2] = &(NADHm) - _p;
 _slist2[3] = &(Psim) - _p;
 _slist2[4] = &(S) - _p;
 _slist2[5] = &(adp) - _p;
 _slist2[6] = &(adpm) - _p;
 _slist2[7] = &(cerd) - _p;
 _slist2[8] = &(cmdpqd) - _p;
 _slist2[9] = &(cmdld) - _p;
 _slist2[10] = &(cd) - _p;
 _slist2[11] = &(cera) - _p;
 _slist2[12] = &(cmdpqa) - _p;
 _slist2[13] = &(ca) - _p;
 _slist2[14] = &(cam) - _p;
 _slist2[15] = &(cmd) - _p;
 _slist2[16] = &(cer) - _p;
 _slist2[17] = &(c) - _p;
 _slist2[18] = &(fbp) - _p;
 _slist2[19] = &(g6p) - _p;
 _slist2[20] = &(hkad) - _p;
 _slist2[21] = &(hnad) - _p;
 _slist2[22] = &(hcapqd) - _p;
 _slist2[23] = &(hcald) - _p;
 _slist2[24] = &(hkaa) - _p;
 _slist2[25] = &(hnaa) - _p;
 _slist2[26] = &(hcapqa) - _p;
 _slist2[27] = &(hcata) - _p;
 _slist2[28] = &(hcala) - _p;
 _slist2[29] = &(mkdrd) - _p;
 _slist2[30] = &(mkad) - _p;
 _slist2[31] = &(mnad) - _p;
 _slist2[32] = &(mcapqd) - _p;
 _slist2[33] = &(mcald) - _p;
 _slist2[34] = &(mkdra) - _p;
 _slist2[35] = &(mkaa) - _p;
 _slist2[36] = &(mnaa) - _p;
 _slist2[37] = &(mcapqa) - _p;
 _slist2[38] = &(mcata) - _p;
 _slist2[39] = &(mcala) - _p;
 _slist2[40] = &(nra) - _p;
 _slist2[41] = &(nfa) - _p;
 _slist2[42] = &(n6a) - _p;
 _slist2[43] = &(n5a) - _p;
 _slist2[44] = &(n4a) - _p;
 _slist2[45] = &(n3a) - _p;
 _slist2[46] = &(n2a) - _p;
 _slist2[47] = &(n1a) - _p;
 _slist2[48] = &(nr) - _p;
 _slist2[49] = &(nf) - _p;
 _slist2[50] = &(n6) - _p;
 _slist2[51] = &(n5) - _p;
 _slist2[52] = &(n4) - _p;
 _slist2[53] = &(n3) - _p;
 _slist2[54] = &(n2) - _p;
 _slist2[55] = &(n1) - _p;
 _slist2[56] = &(n) - _p;
 _slist2[57] = &(vd) - _p;
 _slist2[58] = &(va) - _p;
 _slist2[59] = &(vb) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "one.mod";
static const char* nmodl_file_text = 
  "NEURON{\n"
  "    SUFFIX one\n"
  "    : Beta stimulating delta\n"
  "    RANGE gGABAbar, EffId, iGABA \n"
  "\n"
  "    : Beta inhibiting alpha\n"
  "    RANGE EffIa, gkatpa, ikatpa\n"
  "\n"
  "    : Delta inhibiting alpha\n"
  "    RANGE gGIRKbara, EffSa, iGIRKa, rm2a\n"
  "\n"
  "    : Alpha stimulating beta\n"
  "    RANGE r20\n"
  "\n"
  "    : Delta inhibiting beta\n"
  "    RANGE gGIRKbarb, EffSb, iGIRKb, rm2b\n"
  "\n"
  "    : Equations beta cell\n"
  "    RANGE ikca, minf, ica, ical, icar, ninf, ik, topo, bottomo, katpo, ikatp, vmdcyt, JL, JR, Jmem, Jserca, Jleak, Jer, f6p, Jgpdh, Jgk_ms, mod_cmd\n"
  "    RANGE weight2, topa2, bottom2, weight3, topa3, bottom3, weight4, topa4, bottom4, weight5, topa5, bottom5, weight6, topa6, bottom6, weight7, topa7, bottom7, weight8, topa8, bottom8, weight9, topa9, bottom9, weight10, topa10, bottom10, weight11, topa11, bottom11, weight12, topa12, bottom12, weight13, topa13, bottom13, weight14, topa14, bottom14, weight15, topa15, topb, bottom15, weight16, topa16, bottom16\n"
  "    RANGE pfk, pfk_ms, delta, Juni, JNaCa, Jmito, NADm, ATPm, RATm, Jpdh, JHleak, MM1, JO, MM2, JHres, b2, JF1F0, JHatp, FRT, Jant, atp, Jhyd, mgadp, adp3m, atp4m, ampfactor, r3, r2, JIS\n"
  "\n"
  "    : Equations alpha cell\n"
  "    RANGE mcalinfa, hcalinfa, taucalma, taucalha, icala, mcatinfa, hcatinfa, taucatma, taucatha, icata, mcapqinfa, hcapqinfa, taucapqma, taucapqha, icapqa, mnainfa, hnainfa, taunama, taunaha, inaa, mkainfa, hkainfa, taukaha, ikaa, mkdrinfa, taukdrma, ikdra, ila, cinfa, isoca, JLa, JPQa, JTa, Jmema, Jsercaa, Jleaka, Jera, r2a, r3a, JGS\n"
  "\n"
  "    : Equations delta cell\n"
  "    RANGE mcalinfd, hcalinfd, taucalmd, taucalhd, icald, mcapqinfd, hcapqinfd, taucapqmd, taucapqhd, icapqd, mnainfd, hnainfd, taunamd, taunahd, inad, mkainfd, hkainfd, taukahd, ikad, mkdrinfd, taukdrmd, ikdrd, ikatpd, ild, JLd, JPQd, Jmemd, Jsercad, Jleakd, Jerd, y, Som, JSS\n"
  "}\n"
  "\n"
  "PARAMETER{\n"
  "    : Islet interactions\n"
  "    knockoutbd=0\n"
  "    knockoutba=0\n"
  "    knockoutdb=0\n"
  "    knockoutda=0\n"
  "\n"
  "    : Beta stimulating delta\n"
  "    vGABA=0\n"
  "\n"
  "    : Beta inhibiting alpha\n"
  "    tausom=2000\n"
  "    vc = 1e-13\n"
  "    : 1, 7, 11 mM glucose value respectively\n"
  "    gkatpbara=3\n"
  "    :gkatpbara=0.6\n"
  "    :gkatpbara=0.15\n"
  "    ka1=0.1\n"
  "\n"
  "    : Delta inhibiting alpha\n"
  "    gGIRKko=0\n"
  "    vGIRK=-80\n"
  "    sombara2=35\n"
  "    ssom2=10\n"
  "    ra=4.5\n"
  "    sombara=50\n"
  "    rako=0.001\n"
  "    ssom=15\n"
  "\n"
  "    : Alpha Stimulating beta\n"
  "    gthresh=40\n"
  "\n"
  "    : Delta inhibiting beta\n"
  "    sombarb2=35\n"
  "    sombarb=50\n"
  "    ssomb=15\n"
  "    rb=0.002\n"
  "\n"
  "    : Parameters beta cell\n"
  "    fb = 2000\n"
  "    Jgk=0.4\n"
  "    factor=14\n"
  "    : 1, 7, 11 mM glucose value respectively\n"
  "    gkatpb=150\n"
  "    :gkatpb=85\n"
  "    :gkatpb=25\n"
  "    bas_r3=0.032\n"
  "    amplify=1\n"
  "    cm=5300\n"
  "    gkca=280\n"
  "    k4=150\n"
  "    kd=0.5\n"
  "    nca=590\n"
  "    raL=0.5\n"
  "    vca=25\n"
  "    vm=-6\n"
  "    sm=10\n"
  "    gca=7\n"
  "    vk=-75\n"
  "    gk=1800\n"
  "    vn=-16\n"
  "    sn=6\n"
  "    taun=5\n"
  "    kdd=17\n"
  "    ktd=26\n"
  "    ktt=1\n"
  "    fcyt=0.01\n"
  "    fer=0.01\n"
  "    fmd=0.01\n"
  "    kpmca=0.2\n"
  "    cbas=0.05\n"
  "    B=1\n"
  "    per=0.0002\n"
  "    kserca3=0.1\n"
  "    kserca2b=0.01\n"
  "    sigmav=30\n"
  "    vmd=4.2e-3\n"
  "    vcell=1.15\n"
  "    alpha=5.18e-6\n"
  "    phigk=0.3\n"
  "    KGPDH=0.0005\n"
  "    k1=30\n"
  "    k2=1\n"
  "    k3=50000\n"
  "    f13=0.02\n"
  "    f43=20\n"
  "    f23=0.2\n"
  "    f42=20\n"
  "    f41=20\n"
  "    lambda=0.06\n"
  "    taua=5\n"
  "    VmaxPFK=5\n"
  "    kappa=0.001\n"
  "    Jgpdh_bas=0.0005\n"
  "    fmito=0.01\n"
  "    gamma=0.001\n"
  "    p21=0.04\n"
  "    p22=1.1\n"
  "    exo_k1=20\n"
  "    bas_cmd=0.06935\n"
  "    p23=0.01 \n"
  "    p24=0.016 \n"
  "    Amtot=15 \n"
  "    NADmtot=10 \n"
  "    p1=400\n"
  "    p2=1\n"
  "    p3=0.01\n"
  "    Cmito=1.8\n"
  "    p17=0.002\n"
  "    p18=-0.03\n"
  "    p4=0.6\n"
  "    p5=0.1\n"
  "    p6=177\n"
  "    p7=5\n"
  "    p8=7\n"
  "    p9=0.1\n"
  "    p10=177\n"
  "    p11=5\n"
  "    p13=10\n"
  "    p14=190\n"
  "    p15=8.5\n"
  "    p16=35\n"
  "    p19=0.35\n"
  "    p20=2\n"
  "    khyd=0.00005 \n"
  "    JhydSS=0.00005\n"
  "    amp=500\n"
  "    atot=2500\n"
  "    km1=100 \n"
  "    r1=0.6\n"
  "    rm1=1\n"
  "    r30=1.205\n"
  "    rm3=0.0001\n"
  "    u1=2000 \n"
  "    u2=3 \n"
  "    u3=0.02\n"
  "    Kp=2.3 \n"
  "    Kp2=2.3\n"
  "    tmsb=0.001\n"
  "    max_cmd=32 \n"
  "    cmdp=4\n"
  "    kcmd=3\n"
  "    weight1=1\n"
  "    topa1=0\n"
  "    bottom1=1\n"
  "\n"
  "    : Parameters alpha cell\n"
  "    fa= 150\n"
  "    gsocbara=0.025\n"
  "    : 1, 7, 11 mM glucose value respectively\n"
  "    ksercaa=0.05\n"
  "    :ksercaa=0.5\n"
  "    :ksercaa=0.5\n"
  "    vnaa=70\n"
  "    vka=-75\n"
  "    vcaa=65\n"
  "    vla=-20\n"
  "    cma=5\n"
  "    gcala=0.7 \n"
  "    gcapqa=0.6\n"
  "    gcata=0.5\n"
  "    gnaa=11\n"
  "    gkaa=1\n"
  "    gkdra=4.5 \n"
  "    gla=0.2\n"
  "    vcella=0.624e-12 \n"
  "    vmdpqa=1.41e-15\n"
  "    fVpqa=0.00226\n"
  "    fmda=0.01\n"
  "    Ba=1\n"
  "    alphaa=5.18e-15 \n"
  "    kpmcaa=0.3 \n"
  "    fcyta=0.01 \n"
  "    fera=0.01\n"
  "    pleaka=0.0003 \n"
  "    sigmava=31\n"
  "    vcalma=-30\n"
  "    scalma=10\n"
  "    vcalha=-33\n"
  "    scalha=-5\n"
  "    tcalh1a=60\n"
  "    tcalh2a=51\n"
  "    vcatma=-49\n"
  "    scatma=4\n"
  "    vcatha=-52\n"
  "    scatha=-5\n"
  "    tcatm1a=15\n"
  "    tcatm2a=0\n"
  "    tcath1a=20\n"
  "    tcath2a=5\n"
  "    vcapqma=-5\n"
  "    scapqma=10\n"
  "    vcapqha=-33\n"
  "    scapqha=-5\n"
  "    tcapqh1a=60\n"
  "    tcapqh2a=51\n"
  "    vnama=-30\n"
  "    vnaha=-52\n"
  "    snama=4\n"
  "    snaha=-8\n"
  "    tnah1a=120\n"
  "    tnah2a=0.5\n"
  "    vkama=-45\n"
  "    skama=10\n"
  "    vkaha=-68\n"
  "    skaha=-10\n"
  "    taukama=0.1\n"
  "    tkah1a=60\n"
  "    tkah2a=5\n"
  "    vkdrma=-25\n"
  "    skdrma=23\n"
  "    caerbara=70 \n"
  "    ssoca=-20\n"
  "    vsoca=0\n"
  "    k1a=20\n"
  "    km1a=100 \n"
  "    r1a=0.6\n"
  "    rm1a=1 \n"
  "    r20a=0.006\n"
  "    r30a=1.205 \n"
  "    rm3a=0.0001\n"
  "    u1a=2000 \n"
  "    u2a=3\n"
  "    u3a=0.025\n"
  "    kpa=2.3 \n"
  "    kp2a=2.3 \n"
  "    GlucFacta=0.05\n"
  "\n"
  "    :Parameters delta cell\n"
  "    fd= 0.003\n"
  "    : 1, 7, 11 mM glucose value respectively\n"
  "    gkatpbard=0.29\n"
  "    :gkatpbard=0.27\n"
  "    :gkatpbard=0.18\n"
  "    vnad=70 \n"
  "    vkd=-75 \n"
  "    vcad=65\n"
  "    vld=-20 \n"
  "    gcald=0.7 \n"
  "    gcapqd=0.7\n"
  "    gnad=5 \n"
  "    gkad=0.5 \n"
  "    gkdrd=7.5\n"
  "    gld=0.2\n"
  "    vmdpqd=1.41e-15\n"
  "    vmdld=2.12e-15\n"
  "    fVld=0.00340\n"
  "    fVpqd=0.00226 \n"
  "    fmdd=0.01 \n"
  "    Bd=1 \n"
  "    alphad=5.18e-15\n"
  "    kpmcad=0.3 \n"
  "    fcytd=0.01 \n"
  "    ferd=0.01\n"
  "    pleakd=0.0003 \n"
  "    sigmavd=31 \n"
  "    ksercad=0.4\n"
  "    vcalmd=-30 \n"
  "    scalmd=10\n"
  "    vcalhd=-33\n"
  "    scalhd=-5\n"
  "    tcalh1d=60\n"
  "    tcalh2d=51\n"
  "    vcapqmd=-15\n"
  "    scapqmd=10\n"
  "    vcapqhd=-33\n"
  "    scapqhd=-5\n"
  "    tcapqh1d=60\n"
  "    tcapqh2d=51\n"
  "    vnamd=-30\n"
  "    vnahd=-52\n"
  "    snamd=4\n"
  "    snahd=-8\n"
  "    tnah1d=120\n"
  "    tnah2d=0.5\n"
  "    vkamd=-45\n"
  "    skamd=10\n"
  "    vkahd=-68\n"
  "    skahd=-10\n"
  "    taukamd=0.1\n"
  "    tkah1d=60\n"
  "    tkah2d=5\n"
  "    vkdrmd=-25\n"
  "    skdrmd=23\n"
  "    con=0.00000000594\n"
  "    bas=0.0009\n"
  "}\n"
  "\n"
  "ASSIGNED{	\n"
  "    : Beta stimulating delta\n"
  "    gGABAbar\n"
  "    EffId \n"
  "    iGABA \n"
  "\n"
  "    : Beta inhibiting alpha\n"
  "    EffIa\n"
  "    gkatpa\n"
  "    ikatpa\n"
  "\n"
  "    : Delta inhibiting alpha\n"
  "    gGIRKbara\n"
  "    EffSa\n"
  "    iGIRKa\n"
  "    rm2a\n"
  "\n"
  "    : Alpha stimulating beta\n"
  "    r20\n"
  "\n"
  "    : Delta inhibiting beta\n"
  "    gGIRKbarb\n"
  "    EffSb\n"
  "    iGIRKb\n"
  "    rm2b\n"
  "\n"
  "    : Equations beta cell\n"
  "    ikca \n"
  "    minf \n"
  "    ica \n"
  "    ical \n"
  "    icar \n"
  "    ninf \n"
  "    ik \n"
  "    topo \n"
  "    bottomo \n"
  "    katpo \n"
  "    ikatp \n"
  "    vmdcyt\n"
  "    JL \n"
  "    JR \n"
  "    Jmem \n"
  "    Jserca \n"
  "    Jleak \n"
  "    Jer \n"
  "    f6p \n"
  "    Jgpdh \n"
  "    Jgk_ms\n"
  "    mod_cmd\n"
  "\n"
  "    weight2\n"
  "    topa2\n"
  "    bottom2\n"
  "    weight3\n"
  "    topa3\n"
  "    bottom3\n"
  "    weight4\n"
  "    topa4\n"
  "    bottom4\n"
  "    weight5\n"
  "    topa5\n"
  "    bottom5\n"
  "    weight6\n"
  "    topa6\n"
  "    bottom6\n"
  "    weight7\n"
  "    topa7\n"
  "    bottom7\n"
  "    weight8\n"
  "    topa8\n"
  "    bottom8\n"
  "    weight9\n"
  "    topa9\n"
  "    bottom9\n"
  "    weight10\n"
  "    topa10\n"
  "    bottom10\n"
  "    weight11\n"
  "    topa11\n"
  "    bottom11\n"
  "    weight12\n"
  "    topa12\n"
  "    bottom12\n"
  "    weight13\n"
  "    topa13\n"
  "    bottom13\n"
  "    weight14\n"
  "    topa14\n"
  "    bottom14\n"
  "    weight15\n"
  "    topa15\n"
  "    topb\n"
  "    bottom15\n"
  "    weight16\n"
  "    topa16\n"
  "    bottom16\n"
  "\n"
  "    pfk\n"
  "    pfk_ms\n"
  "    delta\n"
  "    Juni\n"
  "    JNaCa\n"
  "    Jmito\n"
  "    NADm\n"
  "    ATPm\n"
  "    RATm\n"
  "    Jpdh\n"
  "    JHleak\n"
  "    MM1\n"
  "    JO\n"
  "    MM2\n"
  "    JHres\n"
  "    b2\n"
  "    JF1F0\n"
  "    JHatp\n"
  "    FRT\n"
  "    Jant\n"
  "    atp \n"
  "    Jhyd\n"
  "    mgadp \n"
  "    adp3m \n"
  "    atp4m \n"
  "    ampfactor\n"
  "    r3 \n"
  "    r2 \n"
  "    JIS\n"
  "\n"
  "    : Equations alpha cell\n"
  "    mcalinfa\n"
  "    hcalinfa\n"
  "    taucalma\n"
  "    taucalha\n"
  "    icala\n"
  "    mcatinfa\n"
  "    hcatinfa\n"
  "    taucatma\n"
  "    taucatha\n"
  "    icata\n"
  "    mcapqinfa\n"
  "    hcapqinfa\n"
  "    taucapqma\n"
  "    taucapqha\n"
  "    icapqa\n"
  "    mnainfa\n"
  "    hnainfa\n"
  "    taunama\n"
  "    taunaha\n"
  "    inaa\n"
  "    mkainfa\n"
  "    hkainfa\n"
  "    taukaha\n"
  "    ikaa\n"
  "    mkdrinfa\n"
  "    taukdrma\n"
  "    ikdra\n"
  "    ila\n"
  "    cinfa \n"
  "    isoca \n"
  "    JLa\n"
  "    JPQa\n"
  "    JTa\n"
  "    Jmema \n"
  "    Jsercaa \n"
  "    Jleaka \n"
  "    Jera \n"
  "    r2a\n"
  "    r3a\n"
  "    JGS\n"
  "\n"
  "    : Equations delta cell\n"
  "    mcalinfd\n"
  "    hcalinfd\n"
  "    taucalmd\n"
  "    taucalhd\n"
  "    icald\n"
  "    mcapqinfd\n"
  "    hcapqinfd\n"
  "    taucapqmd\n"
  "    taucapqhd\n"
  "    icapqd\n"
  "    mnainfd\n"
  "    hnainfd\n"
  "    taunamd\n"
  "    taunahd\n"
  "    inad\n"
  "    mkainfd\n"
  "    hkainfd\n"
  "    taukahd\n"
  "    ikad\n"
  "    mkdrinfd\n"
  "    taukdrmd\n"
  "    ikdrd\n"
  "    ikatpd\n"
  "    ild\n"
  "    JLd\n"
  "    JPQd\n"
  "    Jmemd \n"
  "    Jsercad \n"
  "    Jleakd \n"
  "    Jerd \n"
  "    y\n"
  "    Som\n"
  "    JSS\n"
  "}\n"
  "\n"
  "STATE{\n"
  "    : Beta\n"
  "    vb \n"
  "    n <1e-10>\n"
  "    c \n"
  "    cer \n"
  "    cmd \n"
  "    g6p \n"
  "    fbp \n"
  "    adpm\n"
  "    cam \n"
  "    NADHm \n"
  "    Psim\n"
  "    adp \n"
  "    n1 \n"
  "    n2 \n"
  "    n3 \n"
  "    n4 <1e-10>\n"
  "    n5 \n"
  "    n6 \n"
  "    nf \n"
  "    nr \n"
  "    I\n"
  "\n"
  "    : Alpha\n"
  "    va\n"
  "    mcala \n"
  "    hcala \n"
  "    mcata \n"
  "    hcata \n"
  "    mcapqa \n"
  "    hcapqa \n"
  "    mnaa \n"
  "    hnaa \n"
  "    mkaa \n"
  "    hkaa \n"
  "    mkdra \n"
  "    ca\n"
  "    cmdpqa\n"
  "    cera\n"
  "    n1a <1e-10>\n"
  "    n2a <1e-10>\n"
  "    n3a <1e-10>\n"
  "    n4a <1e-10>\n"
  "    n5a \n"
  "    n6a \n"
  "    nfa \n"
  "    nra \n"
  "    G\n"
  "\n"
  "    : Delta\n"
  "    vd\n"
  "    mcald \n"
  "    hcald \n"
  "    mcapqd \n"
  "    hcapqd \n"
  "    mnad \n"
  "    hnad \n"
  "    mkad \n"
  "    hkad \n"
  "    mkdrd \n"
  "    cd \n"
  "    cmdld\n"
  "    cmdpqd\n"
  "    cerd \n"
  "    S\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "    : Initial conditions beta cell\n"
  "    vb=-71.33779976819424  \n"
  "    n=9.875188779513991e-05  \n"
  "    c=0.0630015242008439  \n"
  "    cer=81.57023672312617  \n"
  "    cmd=0.4188629403487558  \n"
  "    g6p=244.936858732948  \n"
  "    fbp=0.08283840527865462 \n"
  "    adpm=13.53015038508978  \n"
  "    cam=0.01102007399722167 \n"
  "    NADHm=0.02908310367935971 \n"
  "    Psim=151.1015153147079  \n"
  "    adp=1913.096601466651  \n"
  "    n1=4.627586868810905  \n"
  "    n2=0.2262327588817945  \n"
  "    n3=0.003661670524646639  \n"
  "    n4=2.595179480355916e-06  \n"
  "    n5=7.762125378310579  \n"
  "    n6=274.1666227230976  \n"
  "    nf=0.00172689211245988  \n"
  "    nr=0.3002686554719045 \n"
  "\n"
  "    : Inital conditions alpha cell\n"
  "    va=-49.03736299581227  \n"
  "    mcala=0.1293341713632475  \n"
  "    hcala=0.8127842536675057  \n"
  "    mcata=0.4633857551023612  \n"
  "    hcata=0.3735421388722815  \n"
  "    mcapqa=0.0120465460803863  \n"
  "    hcapqa=0.8127842536675057  \n"
  "    mnaa=0.007938786735335676  \n"
  "    hnaa=0.2498175179717122 \n"
  "    mkaa=0.4001652246173745\n"
  "    hkaa=0.1373195977592295  \n"
  "    mkdra=0.2674634279865117 \n"
  "    ca=0.3449148387259899  \n"
  "    cmdpqa=11.51299890826233 \n"
  "    cera=58.71698724650182\n"
  "    n1a=1.057203539612775e-05\n"
  "    n2a=2.113947666062938e-05  \n"
  "    n3a=2.388848788981755e-05  \n"
  "    n4a=2.391806975716259e-06  \n"
  "    n5a=0.008850176609826538  \n"
  "    n6a=12.69715161782077  \n"
  "    nfa=0.001724142875712899  \n"
  "    nra=0.1927364884362762  \n"
  "\n"
  "    : Inital condition delta cell  \n"
  "    vd=-16.26895428994972  \n"
  "    mcald=0.8218051702003508  \n"
  "    hcald=0.6672499701175263  \n"
  "    mcapqd=0.5089033026581684  \n"
  "    hcapqd=0.6672499701175263  \n"
  "    mnad=0.9737137320580179  \n"
  "    hnad=0.006777955247303555  \n"
  "    mkad=0.9480884005315277 \n"
  "    hkad=0.02771925786328598  \n"
  "    mkdrd=0.5717652452166768 \n"
  "    cd=0.3051356309084454  \n"
  "    cmdld=19.82903375122306  \n"
  "    cmdpqd=27.93917378868966  \n"
  "    cerd=413.8135591677398  \n"
  "\n"
  "    : Initial hormone concentrations\n"
  "\n"
  "    I=48.04298494148047  \n"
  "    G=31.73727470720019 \n"
  "    S=18.71318922819339\n"
  "\n"
  "    : Initialization variables not included in BAD model XPP file\n"
  "    : Generated from calculate.py\n"
  "    taucalma=0.3032811940166806\n"
  "    taucalha=56.12989393816361\n"
  "    mcalinfa=0.1296861831162709\n"
  "    hcalinfa=0.9611145179788654\n"
  "    icala=-1.08529313843157\n"
  "    mcapqinfa=0.012083750627573104\n"
  "    hcapqinfa=0.9611145179788654\n"
  "    taucapqma=0.3032811940166806\n"
  "    taucapqha=56.12989393816361\n"
  "    icapqa=-0.6699405169228547\n"
  "    mcatinfa=0.4976648297402624\n"
  "    hcatinfa=0.3560551615487483\n"
  "    taucatma=7.475932505911923\n"
  "    taucatha=14.979442612364645\n"
  "    icata=-2.1192627702105704\n"
  "    gGIRKbara=0.025\n"
  "    EffSa=0.16401112054523317\n"
  "    iGIRKa=0.1269554197523033\n"
  "    rm2a=0.49718657776876884\n"
  "    cinfa =0.6374123727563218\n"
  "    isoca =-0.7814255475218438\n"
  "    JLa=0.009009324450441558\n"
  "    JPQa=2.461199913234317\n"
  "    JTa=0.017592597996299284\n"
  "    Jmema =-0.051632659173903986\n"
  "    Jsercaa =0.017245741936299495\n"
  "    Jleaka =0.017511621722332747\n"
  "    Jera =0.0002658797860332525\n"
  "    r2a=0.0007824407054832726\n"
  "    r3a=0.00785700875089453\n"
  "    JGS=4.760591264376022e-10\n"
  "    mkainfa=0.40041498568618583\n"
  "    hkainfa=0.13053193445833075\n"
  "    taukaha=9.00677536264756\n"
  "    ikaa=1.4266606033882763\n"
  "    EffIa=0.10001054147411872\n"
  "    gkatpa=0.3000316244223562\n"
  "    ikatpa=7.789612154654419\n"
  "    mkdrinfa=0.26016661765554117\n"
  "    taukdrma=15.30146142661036\n"
  "    ikdra=0.5978867667431156\n"
  "    ila=-5.807472599162455\n"
  "    mnainfa=0.008498416028612855\n"
  "    hnainfa=0.40846137482156436\n"
  "    taunama=3.036153418307839\n"
  "    taunaha=60.06822869326301\n"
  "    inaa=-0.00016366705880007713\n"
  "    minf =0.0014513916520931425\n"
  "    ica =-577.4726176457064\n"
  "    gGIRKbarb=10\n"
  "    EffSb=0.16401112054523317\n"
  "    iGIRKb=14.206971664056404\n"
  "    r20=0.006001031554023141\n"
  "    rm2b=0.00022097181234167506\n"
  "    ikca =16.025854402092854\n"
  "    ical =-288.7363088228532\n"
  "    icar =-288.7363088228532\n"
  "    topo =309.906384691809\n"
  "    bottomo =15423.383945456666\n"
  "    katpo =0.020093280812288894\n"
  "    ikatp =549.3300347708633\n"
  "    vmdcyt=0.0036521739130434784\n"
  "    JL =0.3561081142148523\n"
  "    JR =0.001300568764958591\n"
  "    Jmem =-6.829449607573257e-08\n"
  "    Jserca =0.01630015242008439\n"
  "    Jleak =0.016301447039785068\n"
  "    Jer =1.2946197006785676e-06\n"
  "    f6p =73.4810576198844\n"
  "    Jgpdh =0.00014390830872351902\n"
  "    Jgk_ms=0.0004\n"
  "    mod_cmd=0.08150591626797878\n"
  "    weight2=2296.370661399967\n"
  "    topa2=0\n"
  "    bottom2=2297.370661399967\n"
  "    weight3=0.10798931657873541\n"
  "    topa3=0.10798931657873541\n"
  "    bottom3=2297.478650716546\n"
  "    weight4=12.399174916802055\n"
  "    topa4=12.50716423338079\n"
  "    bottom4=2309.877825633348\n"
  "    weight5=0.08283840527865462\n"
  "    topa5=12.50716423338079\n"
  "    bottom5=2309.960664038627\n"
  "    weight6=9.51138417595313\n"
  "    topa6=12.50716423338079\n"
  "    bottom6=2319.47204821458\n"
  "    weight7=0.044728313862571104\n"
  "    topa7=12.55189254724336\n"
  "    bottom7=2319.5167765284423\n"
  "    weight8=0.2567819692197443\n"
  "    topa8=12.808674516463105\n"
  "    bottom8=2319.773558497662\n"
  "    weight9=16.666666666666668\n"
  "    topa9=12.808674516463105\n"
  "    bottom9=2336.4402251643287\n"
  "    weight10=1913.642217833306\n"
  "    topa10=12.808674516463105\n"
  "    bottom10=4250.082442997635\n"
  "    weight11=89.99109714894618\n"
  "    topa11=102.79977166540928\n"
  "    bottom11=4340.073540146581\n"
  "    weight12=516.6322882000856\n"
  "    topa12=619.4320598654948\n"
  "    bottom12=4856.705828346667\n"
  "    weight13=1.380640087977577\n"
  "    topa13=619.4320598654948\n"
  "    bottom13=4858.086468434644\n"
  "    weight14=7.926153479960942\n"
  "    topa14=619.4320598654948\n"
  "    bottom14=4866.012621914605\n"
  "    weight15=37.273594885475916\n"
  "    topa15=619.4320598654948\n"
  "    topb=37.273594885475916\n"
  "    bottom15=4903.286216800081\n"
  "    weight16=10.699248717489347\n"
  "    topa16=630.1313085829842\n"
  "    bottom16=4913.98546551757\n"
  "\n"
  "    pfk=0.07639570154136274\n"
  "    pfk_ms=7.639570154136274e-05\n"
  "    Juni=0.01962392608626012\n"
  "    JNaCa=0.019624306722058324\n"
  "    Jmito=3.806357982034936e-07\n"
  "    NADm=9.97091689632064\n"
  "    ATPm=1.4698496149102205\n"
  "    RATm=0.10863512770190598\n"
  "    Jpdh=0.13463853801663372\n"
  "    JHleak=0.27220303062941587\n"
  "    MM1=0.13518316270858338\n"
  "    JO=0.13442638085707123\n"
  "    MM2=1.5771368982668066\n"
  "    JHres=1.5683077766658313\n"
  "    b2=30.514785437554284\n"
  "    JF1F0=0.31088837377098194\n"
  "    JHatp=0.9326651213129458\n"
  "    FRT=0.037410133089805564\n"
  "    Jant=0.304446602316938\n"
  "    atp =586.903398533349\n"
  "    Jhyd=0.031193960359980264\n"
  "    mgadp =315.6609392419974\n"
  "    adp3m =258.2680411979979\n"
  "    atp4m =29.345169926667452\n"
  "    ampfactor=0.25298632618462513\n"
  "    r3 =0.040127765219777956\n"
  "    r2 =0.0001599974146477454\n"
  "\n"
  "    JIS=9.608596975100945e-09\n"
  "    ninf =9.873556239473554e-05\n"
  "    ik =0.6509685354743112\n"
  "    mcalinfd=0.797881280658739\n"
  "    hcalinfd=0.03401952024443635\n"
  "    taucalmd=0.5229606925470396\n"
  "    taucalhd=73.2304683206763\n"
  "    icald=-25.635926220427873\n"
  "    mcapqinfd=0.468318643634233\n"
  "    hcapqinfd=0.03401952024443635\n"
  "    taucapqmd=0.5229606925470396\n"
  "    taucapqhd=73.2304683206763\n"
  "    icapqd=-19.317305313715206\n"
  "    gGABAbar=0.1\n"
  "    EffId =41.56833392753747\n"
  "    iGABA =-67.62733245764733\n"
  "    mkainfd=0.9465007724360222\n"
  "    hkainfd=0.005635014702807043\n"
  "    taukahd=23.509361336319593\n"
  "    ikad=0.7717349514854953\n"
  "    ikatpd=17.03200325591458\n"
  "    mkdrinfd=0.5937792009880476\n"
  "    taukdrmd=15.72702251180529\n"
  "    ikdrd=47.07604938593722\n"
  "    ild=0.7462091420100564\n"
  "    mnainfd=0.9687128701879236\n"
  "    hnainfd=0.011358328217907197\n"
  "    taunamd=0.255456748187674\n"
  "    taunahd=2.2698475854851585\n"
  "    inad=-2.699088467105948\n"
  "    JLd=62.63872538764923\n"
  "    JPQd=70.96712164896792\n"
  "    Jmemd =0.037293490573121604\n"
  "    Jsercad =0.12205425236337818\n"
  "    Jleakd =0.1240525270610494\n"
  "    Jerd =0.0019982746976712207\n"
  "    y=0.19225889978869892\n"
  "    Som=0.0074284530481816\n"
  "    JSS=4.412501110619871e-14\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "    SOLVE states METHOD derivimplicit\n"
  "    : Beta stimulating delta\n"
  "    gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0\n"
  "    EffId = 0.8/(1+exp(-(I-1500)/500))\n"
  "    iGABA = gGABAbar*EffId*(vd-vGABA)\n"
  "\n"
  "    : Beta inhibiting alpha\n"
  "    EffIa=(1-knockoutba)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutba*ka1\n"
  "    gkatpa=gkatpbara*EffIa\n"
  "    ikatpa=gkatpa*(va-vka)\n"
  "\n"
  "    : Delta inhibiting alpha\n"
  "    gGIRKbara=(1-knockoutda)*0.025+knockoutda*gGIRKko\n"
  "    EffSa=1/(1+exp(-(S-sombara2)/ssom2))\n"
  "    iGIRKa=gGIRKbara*EffSa*(va-vGIRK)\n"
  "    rm2a=(1-knockoutda)*ra/(1+exp(-(S-sombara)/ssom))+knockoutda*rako\n"
  "\n"
  "    : Alpha stimulating beta\n"
  "    r20=0.004/(1+exp(-G+gthresh))+0.006\n"
  "\n"
  "    : Delta inhibiting beta\n"
  "    gGIRKbarb=(1-knockoutdb)*10+knockoutdb*0\n"
  "    EffSb=1/(1+exp(-(S-sombarb2)/10))\n"
  "    iGIRKb=gGIRKbarb*EffSb*(vb-vGIRK)\n"
  "    rm2b=(1-knockoutdb)*rb/(1+exp(-(S-sombarb)/ssomb))+knockoutdb*0.001\n"
  "\n"
  "    : Equations beta cell\n"
  "    ikca = gkca/(1+(kd/c)^2)*(vb-vk)\n"
  "    minf = 1/(1+exp((vm-vb)/sm))\n"
  "    ica = gca*nca*minf*(vb-vca)\n"
  "    ical = raL*ica\n"
  "    icar = (1-raL)*ica\n"
  "    ninf = 1/(1+exp((vn-vb)/sn))\n"
  "    ik = gk*n*(vb-vk)\n"
  "    topo = 0.08*(1+2*mgadp/kdd) + 0.89*(mgadp/kdd)^2\n"
  "    bottomo = (1+mgadp/kdd)^2 * (1+adp3m/ktd+atp4m/ktt)\n"
  "    katpo = (topo/bottomo)\n"
  "    ikatp = gkatpb*(vb-vk)\n"
  "    vmdcyt=vmd/vcell\n"
  "    JL = -alpha*ical/vmd\n"
  "    JR = -alpha*icar/vcell\n"
  "    Jmem = JR+vmdcyt*B*(cmd-c)-kpmca*(c-cbas)\n"
  "    Jserca = kserca2b+kserca3*c\n"
  "    Jleak = per*(cer - c)\n"
  "    Jer = (Jleak - Jserca)\n"
  "    f6p = phigk*g6p\n"
  "    Jgpdh = KGPDH*sqrt(fbp) \n"
  "    Jgk_ms=kappa*Jgk\n"
  "    mod_cmd=bas_cmd + max_cmd*cmd^cmdp/(cmd^cmdp+kcmd^cmdp)\n"
  "\n"
  "\n"
  "    weight2=atp^2/k4\n"
  "    topa2=topa1\n"
  "    bottom2=bottom1+weight2\n"
  "    weight3=f6p^2/k3\n"
  "    topa3=topa2+weight3\n"
  "    bottom3=bottom2+weight3\n"
  "    weight4=(f6p*atp)^2/(f43*k3*k4)\n"
  "    topa4=topa3+weight4\n"
  "    bottom4=bottom3+weight4\n"
  "    weight5=fbp/k2\n"
  "    topa5=topa4\n"
  "    bottom5=bottom4+weight5\n"
  "    weight6=(fbp*atp^2)/(k2*k4*f42)\n"
  "    topa6=topa5\n"
  "    bottom6=bottom5+weight6\n"
  "    weight7=(fbp*f6p^2)/(k2*k3*f23)\n"
  "    topa7=topa6+weight7\n"
  "    bottom7=bottom6+weight7\n"
  "    weight8=(fbp*f6p^2*atp^2)/(k2*k3*k4*f23*f42*f43)\n"
  "    topa8=topa7+weight8\n"
  "    bottom8=bottom7+weight8\n"
  "    weight9=amp/k1\n"
  "    topa9=topa8\n"
  "    bottom9=bottom8+weight9\n"
  "    weight10=(amp*atp^2)/(k1*k4*f41)\n"
  "    topa10=topa9\n"
  "    bottom10=bottom9+weight10\n"
  "    weight11=(amp*f6p^2)/(k1*k3*f13)\n"
  "    topa11=topa10+weight11\n"
  "    bottom11=bottom10+weight11\n"
  "    weight12=(amp*f6p^2*atp^2)/(k1*k3*k4*f13*f41*f43)\n"
  "    topa12=topa11+weight12\n"
  "    bottom12=bottom11+weight12\n"
  "    weight13=(amp*fbp)/(k1*k2)\n"
  "    topa13=topa12\n"
  "    bottom13=bottom12+weight13\n"
  "    weight14=(amp*fbp*atp^2)/(k1*k2*k4*f42*f41)\n"
  "    topa14=topa13\n"
  "    bottom14=bottom13+weight14\n"
  "    weight15=(amp*fbp*f6p^2)/(k1*k2*k3*f23*f13)\n"
  "    topa15=topa14\n"
  "    topb=weight15\n"
  "    bottom15=bottom14+weight15\n"
  "    weight16=(amp*fbp*f6p^2*atp^2)/(k1*k2*k3*k4*f23*f13*f42*f41*f43)\n"
  "    topa16=topa15+weight16\n"
  "    bottom16=bottom15+weight16\n"
  "\n"
  "    pfk=(lambda*VmaxPFK*topa16 + VmaxPFK*topb)/bottom16\n"
  "    pfk_ms=kappa*pfk \n"
  "    delta=3.9/53.2\n"
  "    Juni=(p21*Psim-p22)*c^2\n"
  "    JNaCa=(p23/c)*cam*exp(p24*Psim)\n"
  "    Jmito=JNaCa-Juni\n"
  "    NADm=NADmtot-NADHm\n"
  "    ATPm=Amtot-adpm\n"
  "    RATm=ATPm/adpm\n"
  "    Jpdh=(p1/(p2+NADHm/NADm))*(cam/(p3+cam))*(Jgpdh+Jgpdh_bas)\n"
  "    JHleak=p17*Psim+p18\n"
  "    MM1=p4*NADHm/(p5+NADHm)\n"
  "    JO=MM1/(1+exp((Psim-p6)/p7))\n"
  "    MM2=p8*NADHm/(p9+NADHm)\n"
  "    JHres=MM2/(1+exp((Psim-p10)/p11))\n"
  "    b2=(p16*p13)/(p13+ATPm)\n"
  "    JF1F0=b2/(1.0+exp((p14-Psim)/p15))\n"
  "    JHatp=3*JF1F0\n"
  "    FRT=96480/(310.16*8315)\n"
  "    Jant=p19*(RATm/(RATm+p20))/exp(-0.5*FRT*Psim)\n"
  "    atp = atot-adp\n"
  "    Jhyd=(khyd*c+JhydSS)*atp\n"
  "    mgadp = 0.165*adp\n"
  "    adp3m = 0.135*adp\n"
  "    atp4m = 0.05*atp\n"
  "    ampfactor=factor*JO^2\n"
  "    r3 = bas_r3 + amplify*ampfactor*r30*c/(c + Kp)\n"
  "    r2 = r20*c/(c + Kp2)\n"
  "    JIS=tmsb*u3*nr*0.0016\n"
  "\n"
  "    : Equations alpha cell\n"
  "    mcalinfa=1/(1+exp(-(va-vcalma)/scalma))\n"
  "    hcalinfa=1/(1+exp(-(va-vcalha)/scalha))\n"
  "    taucalma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05\n"
  "    taucalha=(tcalh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcalh2a\n"
  "    icala=gcala*mcala^2*hcala*(va-vcaa)\n"
  "    mcatinfa=1/(1+exp(-(va-vcatma)/scatma))\n"
  "    hcatinfa=1/(1+exp(-(va-vcatha)/scatha))\n"
  "    taucatma=(tcatm1a/(exp(-(va+50)/12)+exp((va+50)/12)))+tcatm2a\n"
  "    taucatha=(tcath1a/(exp(-(va+50)/15)+exp((va+50)/15)))+tcath2a\n"
  "    icata=gcata*mcata^3*hcata*(va-vcaa)\n"
  "    mcapqinfa=1/(1+exp(-(va-vcapqma)/scapqma))\n"
  "    hcapqinfa=1/(1+exp(-(va-vcapqha)/scapqha))\n"
  "    taucapqma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05\n"
  "    taucapqha=(tcapqh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcapqh2a\n"
  "    icapqa=gcapqa*mcapqa*hcapqa*(va-vcaa)\n"
  "    mnainfa=1/(1+exp(-(va-vnama)/snama))\n"
  "    hnainfa=1/(1+exp(-(va-vnaha)/snaha))\n"
  "    taunama=(6/(exp(-(va+50)/10)+exp((va+50)/10)))+0.05\n"
  "    taunaha=(tnah1a/(exp(-(va+50)/8)+exp((va+50)/8)))+tnah2a\n"
  "    inaa=gnaa*mnaa^3*hnaa*(va-vnaa)\n"
  "    mkainfa=1/(1+exp(-(va-vkama)/skama))\n"
  "    hkainfa=1/(1+exp(-(va-vkaha)/skaha))\n"
  "    taukaha=(tkah1a/(exp(-(va-5)/20)+exp((va-5)/20)))+tkah2a\n"
  "    ikaa=gkaa*mkaa*hkaa*(va-vka)\n"
  "    mkdrinfa=1/(1+exp(-(va-vkdrma)/skdrma))\n"
  "    taukdrma=(1.5/(exp(-(va+10)/25)+exp((va+10)/25)))+15\n"
  "    ikdra=gkdra*mkdra^4*(va-vka)\n"
  "    ila=gla*(va-vla)\n"
  "    cinfa = 1/(1+exp(-(cera-caerbara)/ssoca))\n"
  "    isoca = gsocbara*cinfa*(va-vsoca)\n"
  "    JLa=-alphaa*icala/vcella\n"
  "    JPQa=-alphaa*icapqa/vmdpqa\n"
  "    JTa=-alphaa*icata/vcella\n"
  "    Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca\n"
  "    Jsercaa = ksercaa*ca\n"
  "    Jleaka = pleaka*(cera - ca)\n"
  "    Jera = Jleaka - Jsercaa\n"
  "    r2a=r20a*ca/(ca+kp2a)\n"
  "    r3a=GlucFacta*r30a*ca/(ca+kpa)\n"
  "    JGS=tmsb*u3a*nra*0.0000988\n"
  "\n"
  "    : Equations delta cell\n"
  "    mcalinfd=1/(1+exp(-(vd-vcalmd)/scalmd))\n"
  "    hcalinfd=1/(1+exp(-(vd-vcalhd)/scalhd))\n"
  "    taucalmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05\n"
  "    taucalhd=(tcalh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcalh2d\n"
  "    icald=gcald*mcald^2*hcald*(vd-vcad)\n"
  "    mcapqinfd=1/(1+exp(-(vd-vcapqmd)/scapqmd))\n"
  "    hcapqinfd=1/(1+exp(-(vd-vcapqhd)/scapqhd))\n"
  "    taucapqmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05\n"
  "    taucapqhd=(tcapqh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcapqh2d\n"
  "    icapqd=gcapqd*mcapqd*hcapqd*(vd-vcad)\n"
  "    mnainfd=1/(1+exp(-(vd-vnamd)/snamd))\n"
  "    hnainfd=1/(1+exp(-(vd-vnahd)/snahd))\n"
  "    taunamd=(6/(exp(-(vd+50)/10)+exp((vd+50)/10)))+0.05\n"
  "    taunahd=(tnah1d/(exp(-(vd+50)/8)+exp((vd+50)/8)))+tnah2d\n"
  "    inad=gnad*mnad^3*hnad*(vd-vnad)\n"
  "    mkainfd=1/(1+exp(-(vd-vkamd)/skamd))\n"
  "    hkainfd=1/(1+exp(-(vd-vkahd)/skahd))\n"
  "    taukahd=(tkah1d/(exp(-(vd-5)/20)+exp((vd-5)/20)))+tkah2d\n"
  "    ikad=gkad*mkad*hkad*(vd-vkd)\n"
  "    mkdrinfd=1/(1+exp(-(vd-vkdrmd)/skdrmd))\n"
  "    taukdrmd=(1.5/(exp(-(vd+10)/25)+exp((vd+10)/25)))+15\n"
  "    ikdrd=gkdrd*mkdrd^4*(vd-vkd)\n"
  "    ikatpd=gkatpbard*(vd-vkd)\n"
  "    ild=gld*(vd-vld)\n"
  "    JLd=-alphad*icald/vmdld\n"
  "    JPQd=-alphad*icapqd/vmdpqd\n"
  "    Jmemd = fVld*Bd*(cmdld-cd)+fVpqd*Bd*(cmdpqd-cd)-kpmcad*cd\n"
  "    Jsercad = ksercad*cd\n"
  "    Jleakd = pleakd*(cerd - cd)\n"
  "    Jerd = (Jleakd - Jsercad)\n"
  "    y=(cmdpqd/200)^4/(0.2^4+(cmdpqd/200)^4)\n"
  "    Som=(200*mcapqd*hcapqd*(y)/tausom)+bas\n"
  "    JSS=tmsb*Som*con\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "    : ODE's\n"
  "    : Beta\n"
  "    vb' = -(ik + ica + ikca + ikatp+iGIRKb)/cm \n"
  "    n' = (ninf-n)/taun\n"
  "    c' = fcyt*(Jmem + Jer + delta*Jmito)\n"
  "    cer' = -fer*sigmav*Jer\n"
  "    cmd' = fmd*(JL-B*(cmd-c)) \n"
  "    g6p' = Jgk_ms - pfk_ms\n"
  "    fbp' = pfk_ms - 0.5*Jgpdh \n"
  "    adpm'= gamma*(Jant-JF1F0)\n"
  "    cam' = -fmito*Jmito\n"
  "    NADHm' = gamma*(Jpdh-JO)\n"
  "    Psim'=(JHres-JHatp-Jant-JHleak-JNaCa-2*Juni)/Cmito\n"
  "    adp' = (-delta*Jant + Jhyd)/taua\n"
  "    n1' = tmsb*(-(3*exo_k1*mod_cmd + rm1)*n1 + km1*n2 + r1*n5)\n"
  "    n2' = tmsb*(3*exo_k1*mod_cmd*n1 -(2*exo_k1*mod_cmd + km1)*n2 + 2*km1*n3)\n"
  "    n3' = tmsb*(2*exo_k1*mod_cmd*n2 -(2*km1 + exo_k1*mod_cmd)*n3 + 3*km1*n4)\n"
  "    n4' = tmsb*(exo_k1*mod_cmd*n3 - (3*km1 + u1)*n4)\n"
  "    n5' = tmsb*(rm1*n1 - (r1 + rm2b)*n5 + r2*n6)\n"
  "    n6' = tmsb*(r3 + rm2b*n5 - (rm3 + r2)*n6)\n"
  "    nf' = tmsb*(u1*n4 - u2*nf)\n"
  "    nr' = tmsb*(u2*nf - u3*nr)\n"
  "    I'=JIS/vc-fb*I\n"
  "\n"
  "    : Alpha\n"
  "    va'=-(icala+icata+icapqa+inaa+ikdra+ikatpa+ikaa+ila+isoca+iGIRKa)/cma\n"
  "    mcala'=(mcalinfa-mcala)/taucalma\n"
  "    hcala'=(hcalinfa-hcala)/taucalha\n"
  "    mcata'=(mcatinfa-mcata)/taucatma\n"
  "    hcata'=(hcatinfa-hcata)/taucatha\n"
  "    mcapqa'=(mcapqinfa-mcapqa)/taucapqma\n"
  "    hcapqa'=(hcapqinfa-hcapqa)/taucapqha\n"
  "    mnaa'=(mnainfa-mnaa)/taunama\n"
  "    hnaa'=(hnainfa-hnaa)/taunaha\n"
  "    mkaa'=(mkainfa-mkaa)/taukama\n"
  "    hkaa'=(hkainfa-hkaa)/taukaha\n"
  "    mkdra'=(mkdrinfa-mkdra)/taukdrma\n"
  "    ca'= fcyta*(Jmema+Jera)\n"
  "    cmdpqa'=fmda*JPQa-fmda*Ba*(cmdpqa-ca)\n"
  "    cera'= -fera*sigmava*Jera\n"
  "    n1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*n1a + km1a*n2a + r1a*n5a)\n"
  "    n2a' = tmsb*(3*k1a*cmdpqa*n1a -(2*k1a*cmdpqa + km1a)*n2a + 2*km1a*n3a)\n"
  "    n3a' = tmsb*(2*k1a*cmdpqa*n2a -(2*km1a + k1a*cmdpqa)*n3a + 3*km1a*n4a)\n"
  "    n4a' = tmsb*(k1a*cmdpqa*n3a - (3*km1a + u1a)*n4a)\n"
  "    n5a' = tmsb*(rm1a*n1a - (r1a + rm2a)*n5a + r2a*n6a)\n"
  "    n6a' = tmsb*(r3a + rm2a*n5a - (rm3a + r2a)*n6a)\n"
  "    nfa' = tmsb*(u1a*n4a - u2a*nfa)\n"
  "    nra' = tmsb*(u2a*nfa - u3a*nra)\n"
  "    G'=JGS/vc-fa*G\n"
  "\n"
  "    : Delta\n"
  "    vd'=-(icald+icapqd+inad+ikdrd+ikatpd+ikad+ild+iGABA)/cma\n"
  "    mcald'=(mcalinfd-mcald)/taucalmd\n"
  "    hcald'=(hcalinfd-hcald)/taucalhd\n"
  "    mcapqd'=(mcapqinfd-mcapqd)/taucapqmd\n"
  "    hcapqd'=(hcapqinfd-hcapqd)/taucapqhd\n"
  "    mnad'=(mnainfd-mnad)/taunamd\n"
  "    hnad'=(hnainfd-hnad)/taunahd\n"
  "    mkad'=(mkainfd-mkad)/taukamd\n"
  "    hkad'=(hkainfd-hkad)/taukahd\n"
  "    mkdrd'=(mkdrinfd-mkdrd)/taukdrmd\n"
  "    cd' = fcytd*(Jmemd+Jerd) \n"
  "    cmdld'=fmdd*JLd-fmdd*Bd*(cmdld-cd)\n"
  "    cmdpqd'=fmdd*JPQd-fmdd*Bd*(cmdpqd-cd)\n"
  "    cerd' = -ferd*sigmavd*Jerd\n"
  "    S'=JSS/vc-fd*S\n"
  "}\n"
  ;
#endif

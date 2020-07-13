NEURON{
SUFFIX B_Insulin
:USEION CaL READ iCaL
:USEION CaR READ iCaR
USEION insulin READ insulini, insulino WRITE iinsulin VALENCE 0
USEION glucagon READ glucagoni
USEION sst READ ssti
RANGE vmd, vcell, alpha, B, kpmca, cbas, kserca2b, kserca3, per, phigk, KGPDH, kappa, Jgk, fcyt, delta, p23 
RANGE p24, psim, p21, p22, fer, sigmav, fmd, lambda, VmaxPFK, weight1, topa1, bottom1, atot, k4, k3, f43, k2, f42 
RANGE f23, amp, k1, f41, f13, gamma, p19, Amtot, p20, FRT, p16, p13, p14, p15, fmito, p8, p9, p10, p11, p17, p18 
RANGE Cmito, p1, p2, p3, NADmtot, Jgpdh_bas, p4, p5, p6, p7, vm, sm, gCa, nCa, vCa, raL, khyd, JhydSS, taua, tmsb 
RANGE u1, u2, u3, gthresh, Kp2, Kp, r30, factor, amplify, bas_r3, rm3, rb, knockoutdb, sombarb, ssomb, r1, rm1, km1
RANGE bas_cmd, max_cmd, cmdp, kcmd, exo_k1, vc, fb, Ins : End of parameters
RANGE minf, iCa, iCaL, iCaR, vmdcyt, JL, JR, Jmem, Jserca, Jleak, Jer, f6p, Jgpdh, Jgk_ms, JNaCa, Juni, Jmito, ATPm 
RANGE RATm, JANT, b2, JF1F0, JHatp, MM2, JHres, JHleak, NADm, JPDH, MM1, JO, atp, Jhyd, weight2, topa2, bottom2, weight3 
RANGE topa3, bottom3, weight4, topa4, bottom4, weight5, topa5, bottom5, weight6, topa6, bottom6, weight7, topa7, bottom7 
RANGE weight8, topa8, bottom8, weight9, topa9, bottom9, weight10, topa10, bottom10, weight11, topa11, bottom11, weight12 
RANGE topa12, bottom12, weight13, topa13, bottom13, weight14, topa14, bottom14, weight15, topa15, topb, bottom15, weight16 
RANGE topa16, bottom16, pfk, pfk_ms, r20, ampfactor, r3, r2, rm2b, mod_cmd, JIS 
RANGE G, Sst
RANGE inin, inout, iin
}

PARAMETER{   
inin
inout
iin
G
Sst
vmd 
vcell 
alpha 
B 
kpmca 
cbas 
kserca2b 
kserca3 
per 
phigk 
KGPDH 
kappa 
Jgk 
fcyt 
delta 
p23 
p24 
psim 
p21 
p22 
fer 
sigmav 
fmd 
lambda 
VmaxPFK 
weight1 
topa1 
bottom1 
atot 
k4 
k3 
f43 
k2 
f42 
f23 
amp 
k1 
f41 
f13 
gamma 
p19 
Amtot 
p20 
FRT
p16 
p13 
p14 
p15 
fmito 
p8 
p9 
p10 
p11 
p17 
p18 
Cmito 
p1 
p2 
p3 
NADmtot 
Jgpdh_bas 
p4 
p5
p6 
p7 
vm 
sm 
gCa 
nCa 
vCa 
raL 
khyd 
JhydSS 
taua 
tmsb 
u1 
u2 
u3 
gthresh 
Kp2 
Kp 
r30 
factor
amplify 
bas_r3 
rm3 
rb 
knockoutdb 
sombarb
ssomb 
r1 
rm1 
km1 
bas_cmd 
max_cmd 
cmdp  
kcmd 
exo_k1 
vc 
fb 
}

ASSIGNED{
iinsulin
insulini
insulino
minf
iCa 
iCaL 
iCaR 
vmdcyt 
JL 
JR 
Jmem 
Jserca 
Jleak
Jer 
f6p 
Jgpdh 
Jgk_ms 
JNaCa 
Juni
Jmito
ATPm 
RATm
JANT 
b2 
JF1F0
JHatp 
MM2 
JHres 
JHleak 
NADm 
JPDH
MM1 
JO 
atp 
Jhyd 
weight2 
topa2 
bottom2 
weight3 
topa3 
bottom3 
weight4 
topa4 
bottom4 
weight5 
topa5 
bottom5 
weight6 
topa6 
bottom6 
weight7 
topa7 
bottom7 
weight8 
topa8 
bottom8 
weight9 
topa9 
bottom9 
weight10 
topa10 
bottom10 
weight11 
topa11 
bottom11
weight12 
topa12 
bottom12 
weight13 
topa13
bottom13 
weight14 
topa14 
bottom14 
weight15 
topa15 
topb 
bottom15 
weight16 
topa16 
bottom16 
pfk 
pfk_ms 
r20 
ampfactor 
r3 
r2 
rm2b 
mod_cmd 
JIS
glucagoni
ssti
v : This is the voltage when I run h.initial.....
}

STATE{
c
cer
cmd
g6p
fbp 
ADPm
cam
Psim
adp
NADHm
N1
N2
N3
N4
N5
N6
NF
NR
Ins
}

INITIAL{
gCa = 7
nCa = 590
vmd = 4.2e-3
vcell = 1.15
alpha = 5.18e-6
B = 1
cmd = 0.4188629403487558
c = 0.0630015242008439
kpmca = 0.2
cbas = 0.05
kserca2b = 0.01
kserca3 = 0.1
per = 0.0002
cer = 81.57023672312617
phigk = 0.3
g6p = 244.936858732948
KGPDH = 0.0005
kappa = 0.001
Jgk = 0.4
fbp = 0.08283840527865462
ADPm = 13.53015038508978
fcyt = 0.01
delta = 3.9/53.2 : There is an exclamation point before the delta in the model link. idk why
p23 = 0.01
cam = 0.01102007399722167
p24 = 0.016
psim = 151.1015153147079
p21 = 0.04
p22 = 1.1
fer = 0.01
sigmav = 30
fmd = 0.01
lambda = 0.06
VmaxPFK = 5
weight1 = 1
topa1 = 0
bottom1 = 1
atot = 2500
adp = 1913.096601466651
k4 = 150
k3 = 50000
f43 = 20
k2 = 1
f42 = 20
f23 = 0.2
amp = 500
k1 = 30
f41 = 20
f13 = 0.02
gamma = 0.001
p19 = 0.35
Amtot = 15
p20 = 2
FRT = 96480/(310.16*8315)
p16 = 35
p13 = 10
p14 = 190
p15 = 8.5
fmito = 0.01
p8 = 7
NADHm = 0.02908310367935971
p9 = 0.1
p10 = 177
p11 = 5
p17 = 0.002
p18 = -0.03
Cmito = 1.8
p1 = 400
p2 = 1
p3 = 0.01
NADmtot = 10
Jgpdh_bas = 0.0005
p4 = 0.6
p5 = 0.1
p6 = 177
p7 = 5
vm = -6
sm = 10
vCa = 25
raL = 0.5
khyd = 0.00005
JhydSS = 0.00005
taua = 5
tmsb = 0.001
u1 = 2000
u2 = 3
u3 = 0.02
N1 = 4.627586868810905
N2 = 0.2262327588817945
N3 = 0.003661670524646639
N4 = 2.595179480355916e-06
N5 = 7.762125378310579
N6 = 274.1666227230976
NF = 0.00172689211245988
NR = 0.3002686554719045
gthresh = 40
Kp2 = 2.3
Kp = 2.3
r30 = 1.205
factor = 14
amplify = 1
bas_r3 = 0.032
rm3 = 0.0001
rb = 0.002
knockoutdb = 0
sombarb = 50
ssomb = 15
r1 = 0.6
rm1 = 1
km1 = 100
bas_cmd = 0.06935
max_cmd = 32
cmdp = 4
kcmd = 3
exo_k1 = 20
vc = 1e-13
fb = 2000
Ins = 48.04298494148047
v = -71.33779976819424
}

BREAKPOINT{
inin = insulini
inout = insulino
iin = iinsulin
Sst = ssti
G = glucagoni
iinsulin = - (JIS/vc - fb * Ins)
minf = 1/(1 + exp((vm - v)/sm))
iCa = gCa * nCa * minf * (v - vCa)
iCaL = raL * iCa
iCaR = (1 - raL) * iCa
vmdcyt = vmd/vcell
JL = -alpha * iCaL/vmd
JR = -alpha * iCaR/vcell
Jmem = JR + vmdcyt * B * (cmd - c) - kpmca * (c - cbas)
Jserca = kserca2b + kserca3 * c
Jleak = per * (cer - c)
Jer = (Jleak - Jserca)
f6p = phigk * g6p
Jgpdh = KGPDH * sqrt(fbp) 
Jgk_ms = kappa * Jgk
JNaCa = (p23/c) * cam * exp(p24 * Psim)
Juni=(p21 * psim - p22) * pow(c,2)
Jmito = JNaCa - Juni
ATPm = Amtot - ADPm
RATm = ATPm/ADPm
JANT = p19 * (RATm/(RATm + p20))/exp(-0.5 * FRT * Psim)
b2 = (p16 * p13)/(p13 + ATPm)
JF1F0 = b2/(1.0 + exp((p14 - Psim)/p15))
JHatp = 3 * JF1F0
MM2 = p8 * NADHm/(p9 + NADHm)
JHres = MM2/(1 + exp((Psim - p10)/p11))
JHleak = p17 * Psim + p18
NADm = NADmtot - NADHm
JPDH = (p1/(p2 + NADHm/NADm)) * (cam/(p3 + cam)) * (Jgpdh + Jgpdh_bas)
MM1 = p4 * NADHm/(p5 + NADHm)
JO = MM1/(1 + exp((Psim - p6)/p7))
atp = atot - adp
Jhyd = (khyd * c + JhydSS) * atp 
weight1 = 1
topa1 = 0
bottom1 = 1
weight2 = pow(atp,2)/k4
topa2 = topa1
bottom2 = bottom1 + weight2
weight3 = pow(f6p,2)/k3
topa3 = topa2 + weight3
bottom3 = bottom2 + weight3
weight4 = pow(f6p * atp,2)/(f43 * k3 * k4)
topa4 = topa3 + weight4
bottom4 = bottom3 + weight4
weight5 = fbp/k2
topa5 = topa4
bottom5 = bottom4 + weight5
weight6 = (fbp * pow(atp,2))/(k2 * k4 * f42)
topa6 = topa5
bottom6 = bottom5 + weight6
weight7 = (fbp * pow(f6p,2))/(k2 * k3 * f23)
topa7 = topa6 + weight7
bottom7 = bottom6 + weight7
weight8 = (fbp * pow(f6p,2) * pow(atp,2))/(k2 * k3 * k4 * f23 * f42 * f43)
topa8 = topa7 + weight8
bottom8 = bottom7 + weight8
weight9 = amp/k1
topa9 = topa8
bottom9 = bottom8 + weight9
weight10 = (amp * pow(atp,2))/(k1 * k4 * f41)
topa10 = topa9
bottom10 = bottom9 + weight10
weight11 = (amp * pow(f6p,2))/(k1 * k3 * f13)
topa11 = topa10 + weight11
bottom11 = bottom10 + weight11
weight12 = (amp * pow(f6p,2) * pow(atp,2))/(k1 * k3 * k4 * f13 * f41 * f43)
topa12 = topa11 + weight12
bottom12 = bottom11 + weight12
weight13 = (amp * fbp)/(k1 * k2)
topa13 = topa12
bottom13 = bottom12 + weight13
weight14 = (amp * fbp * pow(atp,2))/(k1 * k2 * k4 * f42 * f41)
topa14 = topa13
bottom14 = bottom13 + weight14
weight15 = (amp * fbp * pow(f6p,2))/(k1 * k2 * k3 * f23 * f13)
topa15 = topa14
topb = weight15
bottom15 = bottom14 + weight15
weight16 = (amp * fbp * pow(f6p,2) * pow(atp,2))/(k1 * k2 * k3 * k4 * f23 * f13 * f42 * f41 * f43)
topa16 = topa15 + weight16
bottom16 = bottom15 + weight16
pfk = (lambda * VmaxPFK * topa16 + VmaxPFK * topb)/bottom16
pfk_ms = kappa * pfk 
r20 = 0.004/(1 + exp(-glucagoni + gthresh)) + 0.006 : Alpha stimulating beta
ampfactor = factor * pow(JO,2)
r3 = bas_r3 + amplify * ampfactor * r30 *c/(c + Kp)
r2 = r20 * c/(c + Kp2)
rm2b = (1 - knockoutdb) * rb/(1 + exp(-(ssti - sombarb)/ssomb)) + knockoutdb * 0.001
SOLVE states METHOD cnexp : Put equations that need to have ODE's solved to evaluate under here
mod_cmd = bas_cmd + max_cmd * pow(cmd,cmdp)/(pow(cmd,cmdp) + pow(kcmd,cmdp))
JIS = tmsb * u3 * NR * 0.0016
}

DERIVATIVE states{
c' = fcyt * (Jmem + Jer + delta * Jmito)
cer' = -fer * sigmav * Jer
cmd' = fmd * (JL - B * (cmd - c)) 
g6p' = Jgk_ms - pfk_ms
fbp' = pfk_ms - 0.5 * Jgpdh 
ADPm'= gamma * (JANT - JF1F0)
cam' = -fmito * Jmito
Psim'=(JHres - JHatp - JANT - JHleak - JNaCa - 2 * Juni)/Cmito
adp' = (-delta * JANT + Jhyd)/taua
NADHm' = gamma * (JPDH - JO)
N1' = tmsb * (-(3 * exo_k1 * mod_cmd + rm1) * N1 + km1 * N2 + r1 * N5)
N2' = tmsb * (3 * exo_k1 * mod_cmd * N1 - (2 * exo_k1 * mod_cmd + km1) * N2 + 2 * km1 * N3)
N3' = tmsb * (2 * exo_k1 * mod_cmd * N2 -(2 * km1 + exo_k1 * mod_cmd) * N3 + 3 * km1 * N4)
N4' = tmsb * (exo_k1 * mod_cmd * N3 - (3 * km1 + u1) * N4)
N5' = tmsb * (rm1 * N1 - (r1 + rm2b) * N5 + r2 * N6)
N6' = tmsb * (r3 + rm2b * N5 - (rm3 + r2) * N6)
NF' = tmsb * (u1 * N4 - u2 * NF)
NR' = tmsb * (u2 * NF - u3 * NR)
Ins' = JIS/vc - fb * Ins
}


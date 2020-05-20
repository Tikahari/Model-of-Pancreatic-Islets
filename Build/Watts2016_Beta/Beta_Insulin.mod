NEURON{
SUFFIX B_Insulin
USEION 
USEION 
RANGE 
RANGE 
}

PARAMETER{   
iCaL
iCaR
v : This is the voltage when I run h.initial.....

}

ASSIGNED{

}

STATE{

}

INITIAL{
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
fbp = 0.08283840527865462 
kappa = 0.001
Jgk = 0.4
fbp = 0.08283840527865462 
adpm = 13.53015038508978 
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
atot = 2500
adp = 1913.096601466651 
}

BREAKPOINT{
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
atp = atot - adp
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
SOLVE states METHOD cnexp : Put equations that need to have ODE's solved to evaluate under here


}

DERIVATIVE states{
c' = fcyt * (Jmem + Jer + delta * Jmito)
cer' = -fer * sigmav * Jer
cmd' = fmd * (JL - B * (cmd - c)) 
g6p' = Jgk_ms - pfk_ms
fbp' = pfk_ms - 0.5 * Jgpdh 
adpm'= gamma * (JANT - JF1F0)
cam' = -fmito * Jmito
Psim'=(JHres - JHatp - JANT - JHleak - JNaCa - 2 * Juni)/Cmito
}


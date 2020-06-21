NEURON{
SUFFIX D_Somatostatin
USEION CaL READ iCaL
USEION CaPQ READ iCaPQ
RANGE iCaL, iCaPQ, tmsb, con, alpha, vmdl, vmdPQ, fVl, B, fVPQ, kpmca, kserca, pleak, vCaPQm, sCaPQm, vCaPQh, sCaPQh, tCaPQh1, tCaPQh2, tausom, bas, fcyt, fmd, fer, sigmav, vc, f, Sst_init 
RANGE JL, JPQ, Jserca, Jer, mCaPQ_inf, hCaPQ_inf, tauCaPQm, tauCaPQh, Jmem, y, Jleak, som, JSS 
RANGE Ins, G
RANGE t_, dir
}

PARAMETER{  
: hormone secretion variables
t_ 
dir
Ins
G
tmsb
con
alpha 
vmdl 
vmdPQ 
fVl 
B    
fVPQ   
kpmca 
kserca 
pleak  
vCaPQm 
sCaPQm 
vCaPQh 
sCaPQh 
tCaPQh1 
tCaPQh2 
tausom 
bas 
fcyt
fmd 
fer 
sigmav 
vc 
f 
Sst_init
}

ASSIGNED{
iCaL
iCaPQ
JL 
JPQ 
Jserca 
Jer
mCaPQ_inf 
hCaPQ_inf 
tauCaPQm 
tauCaPQh 
Jmem 
y 
Jleak 
som 
JSS 
v : This is the voltage when I run h.initial.....
}

STATE{
mCaPQ
hCaPQ
c
cmdl
cmdPQ
cer
Sst
}

INITIAL{
t_ = 0
dir = 0
}

BREAKPOINT{
if (t_ > 2){
dir = 1
}
else if (t_ == 0){
dir = 0
}
if (dir == 0){
t_ = t_ + 1
}
else{
t_ = t_ - 1
}
JL = -alpha * iCaL/vmdl
JPQ = -alpha * iCaPQ/vmdPQ
Jserca = kserca * c
Jer = (Jleak - Jserca)
mCaPQ_inf = 1/(1 + exp(-(v - vCaPQm)/sCaPQm))
hCaPQ_inf = 1/(1 + exp(-(v - vCaPQh)/sCaPQh))
tauCaPQm = (1/(exp(-(v + 23)/20) + exp((v + 23)/20))) + 0.05
tauCaPQh = (tCaPQh1/(exp(-(v + 0)/20) + exp((v + 0)/20))) + tCaPQh2
SOLVE states METHOD cnexp : Put current equation below this
Jmem = fVl * B * (cmdl - c) + fVPQ * B * (cmdPQ - c) - kpmca * c
y = pow(cmdPQ/200,4)/(pow(0.2,4) + pow(cmdPQ/200,4))
Jleak = pleak * (cer - c)
Jer = (Jleak - Jserca)
som = (200 * mCaPQ * hCaPQ * y/tausom) + bas
JSS = tmsb * som * con
}

DERIVATIVE states{
mCaPQ' = (mCaPQ_inf - mCaPQ)/tauCaPQm
hCaPQ' = (hCaPQ_inf - hCaPQ)/tauCaPQh
c' = fcyt * (Jmem + Jer) 
cmdl' = fmd * JL - fmd * B * (cmdl - c)
cmdPQ' = fmd * JPQ - fmd * B * (cmdPQ-c)
cer' = -fer * sigmav * Jer
Sst' = JSS/vc - f * Sst_init
}

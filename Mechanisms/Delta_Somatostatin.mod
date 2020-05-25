NEURON{
SUFFIX D_Somatostatin
USEION CaL READ iCaL
USEION CaPQ READ iCaPQ
RANGE iCaL, iCaPQ, tmsb, con, alpha, vmdl, vmdPQ, fVl, B, fVPQ, kpmca, kserca, pleak, vCaPQm, sCaPQm, vCaPQh, sCaPQh, tCaPQh1, tCaPQh2, tausom, bas, fcyt, fmd, fer, sigmav, vc, f 
RANGE JL, JPQ, Jserca, Jer, mCaPQ_inf, hCaPQ_inf, tauCaPQm, tauCaPQh, Jmem, y, Jleak, som, JSS 
}

PARAMETER{   
iCaL
iCaPQ
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
v : This is the voltage when I run h.initial.....
}

ASSIGNED{
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
}

STATE{
mCaPQ
hCaPQ
c
cmdl
cmdPQ
cer
S
}

INITIAL{
tmsb = 0.001
con = 0.00000000594
alpha = 5.18e-15
vmdl = 2.12e-15
vmdPQ = 1.41e-15
fVl = 0.00340
B = 1 
cmdl = 19.82903375122306 
c = 0.3051356309084454  
fVPQ = 0.00226
cmdPQ = 27.93917378868966 
kpmca = 0.3
kserca = 0.4
pleak = 0.0003
cer = 413.8135591677398 
mCaPQ = 0.5089033026581684  
hCaPQ = 0.6672499701175263 
vCaPQm = -15
sCaPQm = 10
vCaPQh = -33
sCaPQh = -5
tCaPQh1 = 60
tCaPQh2 = 51
tausom = 2000
bas = 0.0009
fcyt = 0.01
fmd = 0.01
fer = 0.01
sigmav = 31
vc = 1e-13
f = 0.003
S = 18.71318922819339 
}

BREAKPOINT{
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
S' = JSS/vc - f * S
}

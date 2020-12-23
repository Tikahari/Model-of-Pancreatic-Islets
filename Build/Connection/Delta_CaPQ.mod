NEURON{
SUFFIX D_CaPQ
USEION CaPQ WRITE iCaPQ VALENCE 2
USEION Ca READ eCa
RANGE gCaPQ, mCaPQ, hCaPQ, vCaPQm, sCaPQm, vCaPQh, sCaPQh, tCaPQh1, tCaPQh2  
RANGE mCaPQ_inf, hCaPQ_inf, tauCaPQm, tauCaPQh, iCaPQ
}

PARAMETER{
gCaPQ  
vCaPQm 
sCaPQm 
vCaPQh 
sCaPQh 
tCaPQh1 
tCaPQh2   
eCa
v : This is the voltage when I run h.initial.....

}

ASSIGNED{
mCaPQ_inf
hCaPQ_inf
tauCaPQm
tauCaPQh
iCaPQ
}

STATE{
mCaPQ
hCaPQ
}

INITIAL{
eCa = 65
gCaPQ = 0.7
mCaPQ = 0.5089033026581684  
hCaPQ = 0.6672499701175263  
vCaPQm = -15
sCaPQm = 10
vCaPQh = -33
sCaPQh = -5
tCaPQh1 = 60
tCaPQh2 = 51
}

BREAKPOINT{
mCaPQ_inf = 1/(1 + exp(-(v - vCaPQm)/sCaPQm))
hCaPQ_inf = 1/(1 + exp(-(v - vCaPQh)/sCaPQh))
tauCaPQm = (1/(exp(-(v + 23)/20) + exp((v + 23)/20))) + 0.05
tauCaPQh = (tCaPQh1/(exp(-(v + 0)/20) + exp((v + 0)/20))) + tCaPQh2
SOLVE states METHOD cnexp : Put current equation below this
iCaPQ = gCaPQ * mCaPQ * hCaPQ * (v - eCa)
}

DERIVATIVE states{
mCaPQ'= (mCaPQ_inf - mCaPQ)/tauCaPQm
hCaPQ' = (hCaPQ_inf - hCaPQ)/tauCaPQh
}


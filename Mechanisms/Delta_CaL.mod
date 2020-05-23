NEURON{
SUFFIX D_CaL
USEION CaL WRITE iCaL VALENCE 2
USEION Ca WRITE eCa VALENCE 2
RANGE sCaLm, sCaLh, vCaLm, vCaLh, tCaLh1, tCaLh2, gCaL
RANGE mCaL_inf, hCaL_inf, tauCaLm, tauCaLh, iCaL
}

PARAMETER{   
sCaLm
sCaLh
vCaLm 
vCaLh
tCaLh1
tCaLh2
gCaL
eCa
v : This is the voltage when I run h.initial.....

}

ASSIGNED{
mCaL_inf
hCaL_inf
tauCaLm
tauCaLh
iCaL
}

STATE{
mCaL
hCaL
}

INITIAL{
eCa = 65 : mV
gCaL = 0.7 : nS
mCaL = 0.8218051702003508
hCaL = 0.6672499701175263 
sCaLm = 10
sCaLh = -5
vCaLm = -30
vCaLh = -33
tCaLh1 = 60
tCaLh2 = 51
}

BREAKPOINT{
mCaL_inf = 1/(1 + exp(-(v - vCaLm)/sCaLm))
hCaL_inf = 1/(1 + exp(-(v - vCaLh)/sCaLh))    
tauCaLm = (1/(exp(-(v + 23)/20) + exp((v + 23)/20))) + 0.05
tauCaLh = (tCaLh1/(exp(-(v + 0)/20) + exp((v + 0)/20)))+tCaLh2
SOLVE states METHOD cnexp :were putting this before current variable    
iCaL = gCaL*pow(mCaL,2)*hCaL*(v-eCa)
}

DERIVATIVE states{
mCaL'= (mCaL_inf - mCaL)/tauCaLm
hCaL'=(hCaL_inf - hCaL)/tauCaLh
}


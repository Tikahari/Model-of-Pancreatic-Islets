NEURON{
SUFFIX D_CaL
USEION CaL WRITE iCaL VALENCE 2
USEION Ca WRITE eCa VALENCE 2
RANGE sCaLm, sCaLh, vCaLm, vCaLh, tCaLh1, tCaLh2, gCaL
RANGE mCaL_inf, hCaL_inf, tauCaLm, tauCaLh
}

PARAMETER{   
sCaLm
sCaLh
vCaLm 
vCaLh
tCaLh1
tCaLh2
gCaL
}

ASSIGNED{
mCaL_inf
hCaL_inf
tauCaLm
tauCaLh
v : This is the voltage when I run h.initial.....
}

STATE{
iCaL
eCa
mCaL
hCaL
}

INITIAL{
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


NEURON{
SUFFIX A_CaT
USEION CaT WRITE iCaT, eCaT VALENCE 1
:NONSPECIFIC_CURRENT i
:USEION Ca READ eCa 
RANGE mCaT_inf, hCaT_inf, tau_mCaT, tau_hCaT
RANGE gCaT
}

PARAMETER{
gCaT
}

ASSIGNED{
mCaT_inf
hCaT_inf
tau_mCaT
tau_hCaT
eCaT
v
i
}

STATE{
iCaT
mCaT
hCaT
}

INITIAL{
eCaT = 65
gCaT = 0.4
mCaT = 0.4633857551023612
hCaT = 0.3735421388722815
}

BREAKPOINT{
mCaT_inf = 1/(1 + exp((-(v + 49))/4))
hCaT_inf = 1/(1 + exp((-(v + 52))/(-5)))
tau_mCaT = (15/(exp((-(v + 50))/12) + exp((v + 50)/12))) 
tau_hCaT = (20/(exp((-(v + 50))/15) + exp((v + 50)/15))) + 5
iCaT = gCaT * pow(mCaT,3) * hCaT*(v - eCaT)
:i = -iCaT
SOLVE states METHOD cnexp
}

DERIVATIVE states{
mCaT' = (mCaT_inf - mCaT)/tau_mCaT
hCaT' = (hCaT_inf - hCaT)/tau_hCaT
}

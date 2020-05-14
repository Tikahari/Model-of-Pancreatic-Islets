NEURON{
SUFFIX A_CaT
USEION CaT WRITE iCaT VALENCE 2
USEION Ca READ eCa
RANGE iCaT, mCaT_inf, hCaT_inf, tau_mCaT, tau_hCaT
RANGE gCaT
}

PARAMETER{
gCaT
eCa
v
}

ASSIGNED{
iCaT
mCaT_inf
hCaT_inf
tau_mCaT
tau_hCaT
}

STATE{
mCaT
hCaT
}

INITIAL{
gCaT = 0.4
}

BREAKPOINT{
mCaT_inf = 1/(1 + exp((-(v + 49))/4))
hCaT_inf = 1/(1 + exp((-(v + 52))/(-5)))
tau_mCaT = (15/(exp((-(v + 50))/12) + exp((v + 50)/12))) 
tau_hCaT = (20/(exp((-(v + 50))/15) + exp((v + 50)/15))) + 5
SOLVE states METHOD cnexp
iCaT = gCaT * pow(mCaT,3) * hCaT*(v - eCa)
}

DERIVATIVE states{
mCaT' = (mCaT_inf - mCaT)/tau_mCaT
hCaT' = (hCaT_inf - hCaT)/tau_hCaT
}

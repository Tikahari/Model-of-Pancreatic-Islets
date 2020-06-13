NEURON{
SUFFIX A_CaL
USEION CaL WRITE iCaL VALENCE 2
USEION Ca WRITE eCa VALENCE 2
RANGE iCaL, mCaL_inf, hCaL_inf, tau_mCaL, tau_hCaL
RANGE gCaL
}

PARAMETER{
gCaL
}

ASSIGNED{
mCaL_inf
hCaL_inf
tau_mCaL
tau_hCaL
v
}

STATE{
eCa
iCaL
mCaL
hCaL
}

INITIAL{
eCa = [60,70]
}

BREAKPOINT{
mCaL_inf = 1/(1 + exp((-(v + 30))/10))
hCaL_inf = 1/(1 + exp((-(v + 33))/(-5)))
tau_mCaL = (1/(exp((-(v + 23))/20) + exp((v + 23)/20))) + 0.05
tau_hCaL = (60/(exp(-v/20) + exp(v/20))) + 51
SOLVE states METHOD cnexp
iCaL = gCaL * pow(mCaL,2) * hCaL*(v - eCa)
}

DERIVATIVE states{
mCaL' = (mCaL_inf - mCaL)/tau_mCaL
hCaL' = (hCaL_inf - hCaL)/tau_hCaL
}

NEURON{
SUFFIX A_Na
USEION Na WRITE iNa, eNa VALENCE 1
RANGE iNa, mNa_inf, hNa_inf, tau_mNa, tau_hNa
RANGE eNa, gNa
}

PARAMETER{
eNa
gNa
}

ASSIGNED{
iNa
mNa_inf
hNa_inf
tau_mNa
tau_hNa
}

STATE{
mNa
hNa
}

INITIAL{
eNa = 70
gNa = 11
}


BREAKPOINT{
mNa_inf = 1/(1 + exp((-(v + 30))/4)
hNa_inf = 1/(1 + exp((-(v + 52))/(-8)))
tau_mNa = (6/(exp((-(v + 50))/10) + exp((v + 50)/10))) + 0.05
tau_hNa = (120/(exp((-(v + 50))/8) + exp((v + 50)/8))) + 0.5
SOLVE states METHOD cnexp
iNa = gNa * pow(mNa,3) * hNa(v - VNa)
}

DERIVATIVE states{
mNa' = (mNa_inf - mNa)/tau_mNa
hNa' = (hNa_inf - hNa)/tau_hNa
}

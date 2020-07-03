NEURON{
SUFFIX A_Na
USEION Na WRITE iNa, eNa VALENCE 1
RANGE mNa_inf, hNa_inf, tau_mNa, tau_hNa
RANGE gNa
}

PARAMETER{
gNa
}

ASSIGNED{
mNa_inf
hNa_inf
tau_mNa
tau_hNa
v
}

STATE{
eNa
iNa
mNa
hNa
}

INITIAL{
eNa = 70
gNa = 11
mNa = 0.007938786735335676
hNa = 0.2498175179717122
}

BREAKPOINT{
mNa_inf = 1/(1 + exp((-(v + 30))/4))
hNa_inf = 1/(1 + exp((-(v + 52))/(-8)))
tau_mNa = (6/(exp((-(v + 50))/10) + exp((v + 50)/10))) + 0.05
tau_hNa = (120/(exp((-(v + 50))/8) + exp((v + 50)/8))) + 0.5
SOLVE states METHOD cnexp
iNa = gNa * pow(mNa,3) * hNa*(v - eNa)
}

DERIVATIVE states{
mNa' = (mNa_inf - mNa)/tau_mNa
hNa' = (hNa_inf - hNa)/tau_hNa
}

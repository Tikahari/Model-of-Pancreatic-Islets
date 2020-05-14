NEURON{
SUFFIX A_Ka
USEION Ka WRITE iKa VALENCE 1
USEION K READ eK
RANGE iKa, mKa_inf, hKa_inf, tau_hKa
RANGE eK, gKa
}

PARAMETER{
eK
gKa
v
}

ASSIGNED{
iKa
mKa_inf
hKa_inf
tau_hKa
tau_mKa
}

STATE{
mKa
hKa
}

INITIAL{
gKa = 1
}

BREAKPOINT{
mKa_inf = 1/(1 + exp((-(v + 45))/10))
hKa_inf = 1/(1 + exp((-(v + 68))/10))
tau_hKa = (60/(exp((-(v - 5))/20) + exp((v - 5)/20))) + 5
tau_mKa = (60/(exp((-(v - 5))/20) + exp((v - 5)/20))) + 5 : CHANGE
SOLVE states METHOD cnexp
iKa = gKa * mKa * hKa*(v - eK)
}

DERIVATIVE states{
mKa' = (mKa_inf - mKa)/tau_mKa
hKa' = (hKa_inf - hKa)/tau_hKa
}

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
}

ASSIGNED{
iKa
mKa_inf
hKa_inf
tau_hKa
}

STATE{
mKa
hKa
}

INITIAL{
gKa = 1
}

BREAKPOINT{
iKa = gKa * mKa * hKa(v - eK)
mKa_inf = 1/(1 + exp((-(v + 45))/10)
hKa_inf = 1/(1 + exp((-(v + 68))/10))
tau_hKa = (60/(exp((-(v - 5))/20) + exp((v - 5)/20))) + 5
SOLVE states METHOD cnexp
}

DERIVATIVE states{
mKa' = (mKa_inf - mKa)/tau_mKa
hKa' = (hKa_inf - hKa)/tau_hKa
}

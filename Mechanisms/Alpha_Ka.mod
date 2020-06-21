NEURON{
SUFFIX A_Ka
USEION Ka WRITE iKa VALENCE 1
USEION K WRITE eK VALENCE 1
RANGE mKa_inf, hKa_inf, tau_hKa
RANGE gKa, tau_mKa
}

PARAMETER{
gKa
tau_mKa
}

ASSIGNED{
mKa_inf
hKa_inf
tau_hKa
v
}

STATE{
iKa
eK
mKa
hKa
}

INITIAL{
}

BREAKPOINT{
mKa_inf = 1/(1 + exp((-(v + 45))/10))
hKa_inf = 1/(1 + exp((-(v + 68))/10))
tau_hKa = (60/(exp((-(v - 5))/20) + exp((v - 5)/20))) + 5
SOLVE states METHOD cnexp
iKa = gKa * mKa * hKa*(v - eK)
}

DERIVATIVE states{
mKa' = (mKa_inf - mKa)/tau_mKa
hKa' = (hKa_inf - hKa)/tau_hKa
}

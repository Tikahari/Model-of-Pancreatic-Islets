NEURON{
SUFFIX A_Ka
USEION Ka WRITE iKa, eKa VALENCE 1
:NONSPECIFIC_CURRENT i
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
i
}

STATE{
iKa
eKa
mKa
hKa
}

INITIAL{
gKa = 1
mKa = 0.4001652246173745
hKa = 0.1373195977592295
tau_mKa = 0.1
eKa = -75
}

BREAKPOINT{
mKa_inf = 1/(1 + exp((-(v + 45))/10))
hKa_inf = 1/(1 + exp((-(v + 68))/10))
tau_hKa = (60/(exp((-(v - 5))/20) + exp((v - 5)/20))) + 5
iKa = gKa * mKa * hKa*(v - eKa)
:i = -iKa
SOLVE states METHOD cnexp
}

DERIVATIVE states{
mKa' = (mKa_inf - mKa)/tau_mKa
hKa' = (hKa_inf - hKa)/tau_hKa
}

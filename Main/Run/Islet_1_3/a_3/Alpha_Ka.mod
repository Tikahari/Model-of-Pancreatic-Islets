NEURON{
SUFFIX A_Ka3
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
gKa = 1
mKa = 0.4001652246173745
hKa = 0.1373195977592295
tau_mKa = 0.1
eK = -75
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

NEURON{
SUFFIX A_K
USEION K WRITE iK, eK VALENCE 1
RANGE iK, mK_inf, tau_mK
}

PARAMETER{
eK
gK
v
}

ASSIGNED{
iK
mK_inf
tau_mK
}

STATE{
mK
}

INITIAL{
gK = 4.5
eK = -75
}

BREAKPOINT{
mK_inf = 1/(1 + exp((-(v + 25))/23))
tau_mK = (1.5/(exp((-(v + 10))/25) + exp((v + 10)/25))) + 15
SOLVE states METHOD cnexp
iK = gK * pow(mK,4)*(v - eK)
}

DERIVATIVE states{
mK' = (mK_inf - mK)/tau_mK
}

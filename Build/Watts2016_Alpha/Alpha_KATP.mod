NEURON{
SUFFIX A_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
:POINTER I
RANGE knockoutb, ka1, gKATPbar, I
RANGE EffI, gKATP, iKATP
}

PARAMETER{
knockoutb
ka1
gKATPbar
I
eK
v
}

ASSIGNED{
EffI
gKATP
iKATP
}

INITIAL{
knockoutb = 0
gKATPbar = 3  : 3 nS for G1; 0.6 nS for G7; 0.15 nS for G11
ka1 = 0.1
eK = -75
}

BREAKPOINT{
EffI =(1 - knockoutb) * ((0.015/(1 + exp((-I + 1500)/200))) + ka1) + knockoutb * ka1
gKATP = gKATPbar * EffI
iKATP = gKATP*(v - eK)
}
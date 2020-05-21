NEURON{
SUFFIX A_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
:POINTER I
RANGE iKATP, gKATP, EffI, I
}

PARAMETER{
gbarKATP
ka
I
eK
v
}

ASSIGNED{
iKATP
gKATP
EffI
}

INITIAL{
gbarKATP = 3  : 3 nS for G1; 0.6 nS for G7; 0.15 nS for G11
}

BREAKPOINT{

EffI =(1-knockoutb)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutb*ka1
gKATP = gbarKATP * EffI
iKATP = gKATP*(v - eK)
}
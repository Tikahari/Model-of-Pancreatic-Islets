NEURON{
SUFFIX A_L3
USEION L WRITE iL, eL VALENCE 1
RANGE gL
}

PARAMETER{
gL
}

ASSIGNED{
v
}

STATE{
eL
iL
}

INITIAL{
eL = -20
gL = 0.2
}

BREAKPOINT{
iL = gL*(v - eL)
}


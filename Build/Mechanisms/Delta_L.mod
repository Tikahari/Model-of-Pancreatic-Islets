NEURON{
SUFFIX D_L
USEION L WRITE iL, eL VALENCE 1
RANGE gL
}

PARAMETER{   
gL
}

ASSIGNED{
v : This is the voltage when I run h.initial.....
}

STATE{
eL
iL
}

INITIAL{
eL = -20
gL = 0
}

BREAKPOINT{
iL = gL * (v - eL)
}



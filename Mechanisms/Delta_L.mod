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
}

BREAKPOINT{
iL = gL * (v - eL)
}



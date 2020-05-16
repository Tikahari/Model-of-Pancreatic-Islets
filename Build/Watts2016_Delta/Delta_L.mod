NEURON{
SUFFIX D_L
USEION L WRITE iL, eL VALENCE 1
RANGE gL
RANGE eL, iL :For other currents we didn't include the reversal potential as a range variable but we do here
}

PARAMETER{   
gL
eL
v : This is the voltage when I run h.initial.....
}

ASSIGNED{
iL
}

INITIAL{
gL = 0
eL = -20
}

BREAKPOINT{
:SOLVE states METHOD cnexp : Put current equation below this
iL = gL * (v - eL)
}



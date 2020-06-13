NEURON{
SUFFIX D_L
USEION L WRITE iL, eL VALENCE 1
RANGE gL
RANGE eL, iL :For other currents we didn't include the reversal potential as a range variable but we do here
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
:SOLVE states METHOD cnexp : Put current equation below this
iL = gL * (v - eL)
}



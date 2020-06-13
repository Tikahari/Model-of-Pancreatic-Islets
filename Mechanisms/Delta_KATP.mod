NEURON{
SUFFIX D_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
RANGE gKATPbar
RANGE iKATP
}

PARAMETER{  
gKATPbar 
}

ASSIGNED{
eK
v : This is the voltage when I run h.initial.....
}

STATE{
iKATP
}

INITIAL{
eK = -75
}

BREAKPOINT{
:SOLVE states METHOD cnexp : Put current equation below this
iKATP = gKATPbar * (v - eK)
}
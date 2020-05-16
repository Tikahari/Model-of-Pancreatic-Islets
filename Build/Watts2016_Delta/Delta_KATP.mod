NEURON{
SUFFIX D_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
RANGE gKATPbar
RANGE iKATP
}

PARAMETER{  
gKATPbar 
eK
v : This is the voltage when I run h.initial.....
}

ASSIGNED{
iKATP
}

INITIAL{
gKATPbar = 0.29 : This is at G1, 0.27 at G7, and 0.18 at G11
eK = -75
}

BREAKPOINT{
:SOLVE states METHOD cnexp : Put current equation below this
iKATP = gKATPbar * (v - eK)
}
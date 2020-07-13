NEURON{
SUFFIX D_KATP
USEION KATP WRITE iKATP, eKATP VALENCE 1
:USEION K READ eK
RANGE gKATPbar
}

PARAMETER{  
gKATPbar 
}

ASSIGNED{
eKATP
v : This is the voltage when I run h.initial.....
}

STATE{
iKATP
}

INITIAL{
eKATP = -75
gKATPbar = 0.29
}

BREAKPOINT{
iKATP = gKATPbar * (v - eKATP)
}
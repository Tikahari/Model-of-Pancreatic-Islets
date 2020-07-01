NEURON{
SUFFIX D_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
RANGE gKATPbar
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
gKATPbar = 0.29
}

BREAKPOINT{
iKATP = gKATPbar * (v - eK)
}
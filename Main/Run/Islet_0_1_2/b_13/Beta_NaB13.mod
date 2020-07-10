NEURON{
SUFFIX B_NaB13
USEION NaB WRITE iNaB VALENCE 1
USEION Na READ eNa
RANGE gBNa, eNa
RANGE iNaB
}

PARAMETER{
gBNa
eNa
}

ASSIGNED{
iNaB
v
}

INITIAL{
gBNa = 10.0
}

BREAKPOINT{
iNaB =  (gBNa * (v - eNa))                
}

NEURON{
SUFFIX B_NaB 
USEION NaB WRITE iNaB, eNaB VALENCE 1
:USEION Na READ eNa
:USEION Vm READ Vmi
RANGE gBNa, eNa, eNaB
RANGE iNaB
}

PARAMETER{
gBNa
eNa
v
Vmi
eNaB
}

ASSIGNED{
iNaB
}

INITIAL{
gBNa = 10.0
eNaB = 70
}

BREAKPOINT{
iNaB =  (gBNa * (v - eNaB))                
}

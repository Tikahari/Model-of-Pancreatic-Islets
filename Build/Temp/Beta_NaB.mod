NEURON{
SUFFIX B_NaB 
USEION NaB WRITE iNaB VALENCE 1
:USEION Na READ eNa
:USEION Vm READ Vmi
RANGE gBNa
RANGE iNaB
}

PARAMETER{
gBNa
:Vmi
}

ASSIGNED{
iNaB
eNa
v
}

INITIAL{
gBNa = 10.0
eNa = 70
}

BREAKPOINT{
iNaB =  (gBNa * (v - eNa))                
}

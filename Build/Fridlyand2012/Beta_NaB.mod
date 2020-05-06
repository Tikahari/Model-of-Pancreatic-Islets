NEURON{
SUFFIX B_NaB 
USEION NaB WRITE iNaB VALENCE 1
USEION Na READ eNa
USEION Vm READ Vmi
RANGE gBNa, eNa
RANGE iNaB
}

PARAMETER{
gBNa
eNa
v
Vmi

iNaB
}

INITIAL{
gBNa = 10.0
}

BREAKPOINT{
iNaB =  (gBNa * (Vmi - eNa))                
}

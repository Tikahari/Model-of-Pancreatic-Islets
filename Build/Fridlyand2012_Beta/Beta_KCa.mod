NEURON{
SUFFIX B_KCa
USEION KCa WRITE iKCa, eKCa VALENCE 1
:USEION Cac READ Caci
POINTER Cac
:USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKCa, KKCa, eK, eKCa
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
eK
Caci
Cac
v
Vmi
eKCa
}

ASSIGNED{
dKCa
iKCa
}

INITIAL{
gmKCa = 150
KKCa = 0.2
dKCa = 0.1
eKCa = -75
}

BREAKPOINT{
dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))                
iKCa =  (gmKCa * dKCa * (v - eKCa))                
}

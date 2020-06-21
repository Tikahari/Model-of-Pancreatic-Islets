NEURON{
SUFFIX B_KCa
USEION KCa WRITE iKCa VALENCE 1
:USEION Cac READ Caci
POINTER Cac
USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKCa, KKCa, eK
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
eK
Caci
Cac
v

dKCa
iKCa
}

INITIAL{
}

BREAKPOINT{
dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))                
iKCa =  (gmKCa * dKCa * (v - eK))                
}

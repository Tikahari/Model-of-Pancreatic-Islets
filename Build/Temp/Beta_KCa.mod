NEURON{
SUFFIX B_KCa
USEION KCa WRITE iKCa VALENCE 1
:USEION Cac READ Caci
POINTER Cac
USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKCa, KKCa
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
Caci
Cac
:Vmi
}

ASSIGNED{
dKCa
iKCa
v
eK
}

INITIAL{
gmKCa = 150
KKCa = 0.2
dKCa = 0.1
}

BREAKPOINT{
dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))                
iKCa =  (gmKCa * dKCa * (v - eK))                
}

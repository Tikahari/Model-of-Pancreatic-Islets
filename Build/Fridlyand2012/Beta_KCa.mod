NEURON{
SUFFIX B_KCa
USEION KCa WRITE iKCa VALENCE 1
USEION Cac READ Caci
USEION K READ eK
USEION Vm READ Vmi
RANGE gmKCa, KKCa, eK
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
eK
Caci
v
Vmi

dKCa
iKCa
}

INITIAL{
gmKCa = 150
KKCa = 0.2
dKCa = 0.1
}

BREAKPOINT{
dKCa = (pow(Caci,4.0) / (pow(KKCa,4.0) + pow(Caci,4.0)))                
iKCa =  (gmKCa * dKCa * (Vmi - eK))                
}

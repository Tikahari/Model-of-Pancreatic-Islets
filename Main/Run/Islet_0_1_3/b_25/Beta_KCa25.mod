NEURON{
SUFFIX B_KCa25
USEION KCa WRITE iKCa VALENCE 1
POINTER Cac
USEION K READ eK
RANGE gmKCa, KKCa, eK
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
Cac
eK
}

ASSIGNED{
dKCa
iKCa
v
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

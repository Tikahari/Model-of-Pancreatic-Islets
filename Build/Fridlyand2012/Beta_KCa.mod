NEURON{
SUFFIX KCa
USEION Cac READ Caci
USEION KCa WRITE iKCa VALENCE 1
RANGE gmKCa, KKCa, EK
RANGE dKCa, iKCa
}

PARAMETER{
gmKCa
KKCa
EK
Caci
v
}

ASSIGNED{
dKCa
iKCa
}


INITIAL{
gmKCa = 150
KKCa = 0.2
dKCa = 0.1
EK = -75
}

BREAKPOINT{
dKCa = (pow(Caci,4.0) / (pow(KKCa,4.0) + pow(Caci,4.0)))                
iKCa =  (gmKCa * dKCa * (v - EK))                
}

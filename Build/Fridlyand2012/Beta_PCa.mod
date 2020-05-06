NEURON{
SUFFIX PCa
USEION Cac READ Caci
USEION PCa WRITE iPCa VALENCE 2
RANGE PmCaP, kCap
RANGE iPCa
}

PARAMETER{
PmCaP
kCap
Caci
v
}

ASSIGNED{
iPCa
}

INITIAL{
PmCaP = 5600
kCap = 0.3
}

BREAKPOINT{
iPCa =  (PmCaP * Caci * Caci / ((Caci * Caci) + (kCap * kCap)))                
}

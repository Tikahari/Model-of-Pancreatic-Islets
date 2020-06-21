NEURON{
SUFFIX B_PCa
:USEION Cac READ Caci
POINTER Cac
USEION PCa WRITE iPCa VALENCE 2
RANGE PmCaP, kCap
RANGE iPCa
}

PARAMETER{
PmCaP
kCap
Caci
Cac
v

iPCa
}

INITIAL{
}

BREAKPOINT{
iPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))                
}

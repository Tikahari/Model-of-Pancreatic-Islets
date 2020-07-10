NEURON{
SUFFIX B_PCa23
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
}

ASSIGNED{
iPCa
}

INITIAL{
PmCaP = 5600
kCap = 0.3
}

BREAKPOINT{
iPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))                
}

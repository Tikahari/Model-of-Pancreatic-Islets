NEURON{
SUFFIX Ins
USEION Cac READ Caci
USEION CaP READ iCaP
RANGE Vpi, kpi, Ni, In, F, kci, KiCa, kre, ksi
RANGE fsi, IS, fiCa
}

PARAMETER{
Vpi
kpi
Ni
F
kci
KiCa
kre
ksi
iCaP
Caci
}

ASSIGNED{
fsi
IS
fiCa
}

STATE{
In
}

INITIAL{
Vpi = 45000
kpi = 0.0001
Ni = 600
In = 1.0
F = 96480
kci = 2
KiCa = 0.2
kre = 0.00073
ksi = 10000
}

BREAKPOINT{
fiCa =  (Caci * Caci / ((KiCa * KiCa) + (Caci * Caci)))                
fsi = ( - (kci * fiCa * iCaP / F) + kre)                
IS =  (kpi * ksi * In) 
SOLVE states METHOD cnexp
}

DERIVATIVE states{
In' = ((fsi * Ni / Vpi) - (kpi * In)) 
}
NEURON{
SUFFIX B_Ins20
POINTER Cac
USEION CaP READ iCaP
RANGE Vpi, kpi, Ni, In, kci, KiCa, kre, ksi
RANGE fsi, IS, fiCa
}

PARAMETER{
Vpi
kpi
Ni
F_ins
kci
KiCa
kre
ksi
}

ASSIGNED{
fsi
IS
fiCa
Cac
iCaP
}

STATE{
In
}

INITIAL{
Vpi = 45000
kpi = 0.0001
Ni = 600
In = 1.0
kci = 2
KiCa = 0.2
kre = 0.00073
ksi = 10000
F_ins = 96480
}

BREAKPOINT{
fiCa =  (Cac * Cac / ((KiCa * KiCa) + (Cac * Cac)))                
fsi = ( - (kci * fiCa * iCaP / F_ins) + kre)                
IS =  (kpi * ksi * In) 
SOLVE states METHOD cnexp
}

DERIVATIVE states{
In' = ((fsi * Ni / Vpi) - (kpi * In)) 
}
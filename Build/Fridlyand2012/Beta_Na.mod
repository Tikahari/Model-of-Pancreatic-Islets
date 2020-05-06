NEURON{
SUFFIX Na 
USEION Na WRITE iNa VALENCE 1
RANGE gmNa, VdNa, kdNa, tdNa, fNa, kNar, eNa
RANGE dNai, iNa
}

PARAMETER{
gmNa
VdNa
kdNa
tdNa
fNa
kNar
ENa
v
}

ASSIGNED{
dNai
iNa
}

STATE{
dNa
}

INITIAL{
gmNa = 10000
dNa = 0.1
VdNa = -30
kdNa = 10
tdNa = 0.1
fNa = 0.1
kNar = 0
ENa = 70
}

BREAKPOINT{
dNai = (1.0 / (1.0 + exp(((VdNa - v) / kdNa))))                
iNa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (v - ENa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dNa' = ((dNai - dNa) / tdNa)                
}
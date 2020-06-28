NEURON{
SUFFIX B_Na 
USEION Na WRITE iNa, eNa VALENCE 1
:USEION Vm READ Vmi
RANGE gmNa, VdNa, kdNa, tdNa, fNa, kNar, eNa, VfNa, kfNa
RANGE dNai, iNa, fNai, tfNa
}

PARAMETER{
gmNa
VdNa
kdNa
tdNa
tfNa
kNar
VfNa
kfNa
eNa
v
Vmi
}

ASSIGNED{
fNai
dNai
iNa
}

STATE{
dNa
fNa
}

INITIAL{
gmNa = 10000
dNa = 0.1
VdNa = -30
kdNa = 10
tdNa = 0.1
tfNa = 0.5
fNa = 0.1
kNar = 0
eNa = 70
VfNa = -42
kfNa = 6
}

BREAKPOINT{
fNai = (1.0 / (1.0 + exp( - ((VfNa - v) / kfNa))))
dNai = (1.0 / (1.0 + exp(((VdNa - v) / kdNa))))                
iNa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (v - eNa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dNa' = ((dNai - dNa) / tdNa) 
fNa' = ((fNai - fNa) / tfNa)               
}
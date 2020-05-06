NEURON{
SUFFIX CaT
USEION CaT WRITE iCaT VALENCE 2
RANGE ECa, gmCaT, kdCaT, kfCaT, tdCaT, tfCaT, VdCaT, VfCaT
RANGE dCaTi, fCaTi, iCaT 
}

PARAMETER{
ECa 
gmCaT 
kdCaT 
kfCaT 
tdCaT 
tfCaT 
VdCaT
VfCaT 
v
}

ASSIGNED{
dCaTi
fCaTi 
iCaT 
}

STATE{
dCaT                
fCaT 
}

INITIAL{
ECa = 100
dCaT = 0.1
fCaT = 0.1
gmCaT = 250
kdCaT = 6
kfCaT = 8
tdCaT = 0.41
tfCaT = 6.8
VdCaT = -50
VfCaT = -64
}

BREAKPOINT{
dCaTi = (1.0 / (1.0 + exp(((VdCaT - v) / kdCaT)))) 
fCaTi = (1.0 / (1.0 + exp(((v - VfCaT) / kfCaT))))                
iCaT = (gmCaT * dCaT * fCaT * (v - ECa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dCaT' = ((dCaTi - dCaT) / tdCaT)                
fCaT' = ((fCaTi - fCaT) / tfCaT)                
}
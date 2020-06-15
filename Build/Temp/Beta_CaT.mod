NEURON{
SUFFIX B_CaT
USEION CaT WRITE iCaT VALENCE 2
:USEION Ca READ eCa
:USEION Vm READ Vmi
RANGE gmCaT, kdCaT, kfCaT, tdCaT, tfCaT, VdCaT, VfCaT
RANGE dCaTi, fCaTi, iCaT 
}

PARAMETER{
gmCaT 
kdCaT 
kfCaT 
tdCaT 
tfCaT 
VdCaT
VfCaT 
:Vmi
}

ASSIGNED{
dCaTi
fCaTi 
iCaT 
eCa
v
}

STATE{
dCaT                
fCaT 
}

INITIAL{
dCaT = 0.1
fCaT = 0.1
gmCaT = 250
kdCaT = 6
kfCaT = 8
tdCaT = 0.41
tfCaT = 6.8
VdCaT = -50
VfCaT = -64
eCa = 100
}

BREAKPOINT{
dCaTi = (1.0 / (1.0 + exp(((VdCaT - v) / kdCaT)))) 
fCaTi = (1.0 / (1.0 + exp(((v - VfCaT) / kfCaT))))                
iCaT = (gmCaT * dCaT * fCaT * (v - eCa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dCaT' = ((dCaTi - dCaT) / tdCaT)                
fCaT' = ((fCaTi - fCaT) / tfCaT)                
}
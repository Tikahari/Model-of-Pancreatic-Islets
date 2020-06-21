NEURON{
SUFFIX B_CaT
USEION CaT WRITE iCaT VALENCE 2
USEION Ca READ eCa
USEION Vm READ Vmi
RANGE eCa, gmCaT, kdCaT, kfCaT, tdCaT, tfCaT, VdCaT, VfCaT
RANGE dCaTi, fCaTi, iCaT 
}

PARAMETER{
eCa
gmCaT 
kdCaT 
kfCaT 
tdCaT 
tfCaT 
VdCaT
VfCaT 
v
Vmi

dCaTi
fCaTi 
iCaT 
}


STATE{
dCaT                
fCaT 
}

INITIAL{
}

BREAKPOINT{
dCaTi = (1.0 / (1.0 + exp(((VdCaT - Vmi) / kdCaT)))) 
fCaTi = (1.0 / (1.0 + exp(((Vmi - VfCaT) / kfCaT))))                
iCaT = (gmCaT * dCaT * fCaT * (Vmi - eCa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dCaT' = ((dCaTi - dCaT) / tdCaT)                
fCaT' = ((fCaTi - fCaT) / tfCaT)                
}
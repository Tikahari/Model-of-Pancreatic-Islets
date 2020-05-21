NEURON{
SUFFIX B_CaP
USEION CaP WRITE iCaP VALENCE 2
USEION Ca READ eCa
:USEION Vm READ Vmi
RANGE gmCaP, dCaP, fCaP, VfCaP, VdCaP, tdCaP, tfCaP, kfCaP, kdCaP, eCa
}

PARAMETER{ 
gmCaP
VfCaP
VdCaP
tdCaP
tfCaP
kfCaP
kdCaP
eCa
v

dCaPi
fCaPi
iCaP    
}


STATE{
dCaP
fCaP
}

INITIAL{
gmCaP = 1200
dCaP = 0.1
fCaP = 0.1
VfCaP = -25
VdCaP = -5
tdCaP = 0.41
tfCaP = 65
kfCaP = 8
kdCaP = 6
iCaP = 0
}

BREAKPOINT{
dCaPi = (1.0 / (1.0 + exp(((VdCaP - v) / kdCaP))))                
fCaPi =  (1.0 / (1.0 + exp(((v - VfCaP) / kfCaP))))                
iCaP = (gmCaP * dCaP * fCaP * (v - eCa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dCaP' = ((dCaPi - dCaP) / tdCaP)                
fCaP' = ((fCaPi - fCaP) / tfCaP) 
}
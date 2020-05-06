NEURON{
SUFFIX CaP
USEION CaP WRITE iCaP VALENCE 2
RANGE gmCaP, dCaP, fCaP, VfCaP, VdCaP, tdCaP, tfCaP, kfCaP, kdCaP, ECa 
}

PARAMETER{ 
gmCaP
VfCaP
VdCaP
tdCaP
tfCaP
kfCaP
kdCaP
ECa 
v
}

ASSIGNED{
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
ECa = 100
VfCaP = -25
VdCaP = -5
tdCaP = 0.41
tfCaP = 65
kfCaP = 8
kdCaP = 6
}

BREAKPOINT{
dCaPi = (1.0 / (1.0 + exp(((VdCaP - v) / kdCaP))))                
fCaPi =  (1.0 / (1.0 + exp(((v - VfCaP) / kfCaP))))                
iCaP = (gmCaP * dCaP * fCaP * (v - ECa))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dCaP' = ((dCaPi - dCaP) / tdCaP)                
fCaP' = ((fCaPi - fCaP) / tfCaP) 
}
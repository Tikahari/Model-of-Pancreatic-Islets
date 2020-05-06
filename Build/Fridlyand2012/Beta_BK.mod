NEURON{
SUFFIX BK
USEION BK WRITE iBK VALENCE 1
USEION Cac READ iCac
RANGE hdk, gmKCaB, kCaBK, kdKCaB, kfKCaB, fKCaB, tdKCaB, tfKCaB, VfKCaB,VBKo
}

PARAMETER{
v
hdk
gmKCaB
kCaBK    
kdKCaB  
kfKCaB 
tdKCaB
tfKCaB 
VfKCaB 
VBKo 
EK
kshift
iCac
}

ASSIGNED{
dKCaBi
fKCaBi 
VdKCaB 
iBK
}

STATE{
dKCaB
fKCaB
}


INITIAL{
dKCaB = 0.1
hdk = 2
gmKCaB = 25000
kCaBK = 1.5
kdKCaB = 30
kfKCaB = 9.2
fKCaB = 0.1
tdKCaB = 1.9
tfKCaB = 22.6
VfKCaB = 30
VBKo = 0.1
EK = -75
kshift = 18
}

BREAKPOINT{
fKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - v) / kfKCaB))))                
dKCaBi = (1.0 / (1.0 + exp(((VdKCaB - v) / kdKCaB)))) 
iBK =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (v - EK))                
VdKCaB =   (VBKo - (kshift * log((iCac / kCaBK))))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dKCaB' = ((dKCaBi - dKCaB) / tdKCaB)                
fKCaB' = ((fKCaBi - fKCaB) / tfKCaB) 
}
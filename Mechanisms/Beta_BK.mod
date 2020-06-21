NEURON{
SUFFIX B_BK
USEION BK WRITE iBK VALENCE 1
USEION K WRITE eK VALENCE 1
:USEION Ca READ eCa
POINTER Cac
:USEION Vm READ Vmi

RANGE hdk, gmKCaB, kCaBK, kdKCaB, kfKCaB, tdKCaB, tfKCaB, VfKCaB, VBKo, eK, kshift
RANGE dKCaBi, fKCaBi, VdKCaB, iBK
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
eK
kshift
Caci
Cac
eCa

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
}

BREAKPOINT{
VdKCaB =   (VBKo - (kshift * log((Cac / kCaBK)))) 
fKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - v) / kfKCaB))))                
dKCaBi = (1.0 / (1.0 + exp(((VdKCaB - v) / kdKCaB)))) 
iBK =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (v - eK))                          
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dKCaB' = ((dKCaBi - dKCaB) / tdKCaB)                
fKCaB' = ((fKCaBi - fKCaB) / tfKCaB) 
}
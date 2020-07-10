NEURON{
SUFFIX B_BK11
USEION BK WRITE iBK VALENCE 1
USEION Ca WRITE eCa VALENCE 2
USEION K WRITE eK VALENCE 1
POINTER Cac

RANGE hdk, gmKCaB, kCaBK, kdKCaB, kfKCaB, tdKCaB, tfKCaB, VfKCaB, VBKo, kshift, eK, eCa
RANGE dKCaBi, fKCaBi, VdKCaB, iBK
}

PARAMETER{
hdk
gmKCaB
kCaBK    
kdKCaB  
kfKCaB 
tdKCaB
tfKCaB 
VfKCaB 
VBKo 
kshift
eCa
eK
}

ASSIGNED{
dKCaBi
fKCaBi 
VdKCaB
Cac
iBK
v
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
eK = -75
kshift = 18
eCa = 100
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

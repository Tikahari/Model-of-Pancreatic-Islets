NEURON{
SUFFIX B_HERG
USEION HERG WRITE iHERG VALENCE 1
USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKhe, kdhe, kfhe, tdKhe, tfKhe, Vdhe, Vfhe, eK
RANGE dKhei, fKhei, iHERG
}

PARAMETER{
gmKhe
kdhe
kfhe
tdKhe
tfKhe
Vdhe
Vfhe
eK
v

dKhei  
fKhei  
iHERG
}

STATE{
dKhe                
fKhe
}

INITIAL{
}

BREAKPOINT{
dKhei =  (1.0 / (1.0 + exp(((Vdhe - v) / kdhe))))                
fKhei = (1.0 / (1.0 + exp(((v - Vfhe) / kfhe))))                
iHERG =  (gmKhe * dKhe * fKhe * (v - eK))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dKhe' = ((dKhei - dKhe) / tdKhe)                
fKhe' = ((fKhei - fKhe) / tfKhe)  
}
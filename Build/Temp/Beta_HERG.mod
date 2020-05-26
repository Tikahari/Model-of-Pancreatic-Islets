NEURON{
SUFFIX B_HERG
USEION HERG WRITE iHERG VALENCE 1
USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKhe, kdhe, kfhe, tdKhe, tfKhe, Vdhe, Vfhe
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
:Vmi
}

ASSIGNED{
dKhei  
fKhei  
iHERG
eK
v
}

STATE{
dKhe                
fKhe
}

INITIAL{
dKhe = 0.1
fKhe = 0.1
gmKhe = 200
kdhe = 10
kfhe = 17.5
tdKhe = 100
tfKhe = 50
Vdhe = -30
Vfhe = -42
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
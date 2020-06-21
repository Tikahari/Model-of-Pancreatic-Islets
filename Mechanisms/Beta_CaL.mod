NEURON{
SUFFIX B_CaL
USEION CaL WRITE iCaL VALENCE 2
USEION Ca READ eCa
:USEION Vm READ Vmi
RANGE dCaL, f1CaL, f2CaL , gmCaL, kdCaL , kfCaL , tf1CaL, tf2CaL, VdCaL, VfCaL, eCa
RANGE dCaLi, fCaLi, iCaL, tdCaL
}

PARAMETER{ 
gmCaL
kdCaL 
kfCaL 
tf1CaL
tf2CaL
VdCaL
VfCaL 
eCa
v
}

ASSIGNED{
dCaLi 
fCaLi 
iCaL    
tdCaL
}

STATE{
f1CaL
f2CaL
dCaL
}

INITIAL{
}

BREAKPOINT{
tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + v) * ( - 9.7 + v)))))                
fCaLi = (1.0 / (1.0 + exp(((v - VfCaL) / kfCaL))))                
dCaLi = (1.0 / (1.0 + exp(((VdCaL - v) / kdCaL))))                
iCaL = (gmCaL * dCaL * f1CaL * f2CaL * (v - eCa))    
SOLVE states METHOD cnexp
}

DERIVATIVE states{
f1CaL' = ((fCaLi - f1CaL) / tf1CaL)                
f2CaL' = ((fCaLi - f2CaL) / tf2CaL) 
dCaL' = ((dCaLi - dCaL) / tdCaL)    
}
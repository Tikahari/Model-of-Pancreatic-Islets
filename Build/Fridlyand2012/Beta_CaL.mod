NEURON{
SUFFIX B_CaL
USEION CaL WRITE iCaL VALENCE 2
USEION Ca READ eCa
USEION Vm READ Vmi
RANGE dCaL, f1CaL, f2CaL , gmCaL, kdCaL , kfCaL , tf1CaL, tf2CaL, VdCaL, VfCaL, eCa
RANGE dCaLi, fCaLi, iCaL, tdCaL
RANGE CaLCurr, vCaL
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
Vmi
}

ASSIGNED{
dCaLi 
fCaLi 
iCaL    
tdCaL 
CaLCurr
vCaL
}

STATE{
f1CaL
f2CaL
dCaL
}

INITIAL{
dCaL = 0.001
f1CaL = 0.1
f2CaL = 0.7
gmCaL = 2700
kdCaL = 8
kfCaL = 8
tf1CaL = 6.8
tf2CaL = 65
VdCaL = -15
VfCaL = -25
tdCaL = 0.41
}

BREAKPOINT{
tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + Vmi) * ( - 9.7 + Vmi)))))                
fCaLi = (1.0 / (1.0 + exp(((Vmi - VfCaL) / kfCaL))))                
dCaLi = (1.0 / (1.0 + exp(((VdCaL - Vmi) / kdCaL))))                
iCaL = (gmCaL * dCaL * f1CaL * f2CaL * (Vmi - eCa))    
CaLCurr =  (gmCaL * dCaL * f1CaL * f2CaL * (Vmi - eCa)) 
vCaL = Vmi
SOLVE states METHOD cnexp
}

DERIVATIVE states{
f1CaL' = ((fCaLi - f1CaL) / tf1CaL)                
f2CaL' = ((fCaLi - f2CaL) / tf2CaL) 
dCaL' = ((dCaLi - dCaL) / tdCaL)    
}
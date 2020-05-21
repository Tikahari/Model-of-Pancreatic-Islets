NEURON{
SUFFIX B_KDR
USEION KDR WRITE iKDR VALENCE 1
USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKDr, tdKr, Vdkr, kdkr, eK
RANGE iKDR, dKri
}

PARAMETER{
gmKDr
tdKr
Vdkr
kdkr
eK
v

iKDR
dKri
}

STATE{
dKr
}

INITIAL{
gmKDr = 18000
tdKr = 20
dKr = 0.0029
Vdkr = -9
kdkr = 8
}

BREAKPOINT{
dKri = (1.0 / (1.0 + exp(((Vdkr - v) / kdkr))))                
iKDR =  (gmKDr * dKr * dKr * (v - eK))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dKr' = ((dKri - dKr) / tdKr) 
}
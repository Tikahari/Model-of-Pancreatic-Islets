NEURON{
SUFFIX KDR
USEION KDR WRITE iKDR VALENCE 1
RANGE gmKDr, tdKr, Vdkr, kdkr, EK
RANGE iKDR, dKri
}

PARAMETER{
gmKDr
tdKr
Vdkr
kdkr
EK
v
}

ASSIGNED{
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
EK = -75
}

BREAKPOINT{
dKri = (1.0 / (1.0 + exp(((Vdkr - v) / kdkr))))                
iKDR =  (gmKDr * dKr * dKr * (v - EK))                
SOLVE states METHOD cnexp
}

DERIVATIVE states{
dKr' = ((dKri - dKr) / tdKr) 
}
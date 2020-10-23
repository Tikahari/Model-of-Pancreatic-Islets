NEURON{
SUFFIX B_Cac 
USEION CaL READ iCaL
USEION CaR READ iCaR
USEION CaT READ iCaT
USEION CaP READ iCaP
USEION PCa READ iPCa
RANGE fi, F_ca, Vi, ksg
}

PARAMETER{
fi
F_ca
Vi
ksg
}

ASSIGNED{
iCaL
iCaR
iCaT
iCaP
iPCa
}

INITIAL{
IntCa = 0
Cac = 0.25
fi = 0.005
F_ca = 96480
Vi = 0.764
ksg = 0.00001
}


STATE{
Cac
IntCa
}


BREAKPOINT{
SOLVE states METHOD cnexp
}

DERIVATIVE states{
Cac' = ((fi * ( - iCaL - iCaR - iCaP - iCaT - (2.0 * iPCa)) / (2.0 * F_ca * Vi)) - (ksg * Cac))                
IntCa' = (0.001 * Cac)                
}

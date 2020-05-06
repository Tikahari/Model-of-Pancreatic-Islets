NEURON{
SUFFIX Cac 
USEION Cac WRITE Caci VALENCE 2
USEION IntCa WRITE IntCai VALENCE 1
USEION CaL READ iCaL
USEION CaT READ iCaT
USEION CaP READ iCaP
USEION PCa READ iPCa
RANGE fi, F, Vi, ksg
}

PARAMETER{
fi
F
Vi
ksg
iCaL
iCaT
iCaP
iPCa
}

INITIAL{
fi = 0.005
F = 96480
Vi = 0.764
ksg = 0.00001
}

STATE{
Caci
IntCai
}

BREAKPOINT{
SOLVE states METHOD cnexp
}

DERIVATIVE states{
Caci' = ((fi * ( - iCaL - iCaP - iCaT - (2.0 * iPCa)) / (2.0 * F * Vi)) - (ksg * Caci))                
IntCai' = (0.001 * Caci)                
}
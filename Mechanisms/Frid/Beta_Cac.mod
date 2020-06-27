NEURON{
SUFFIX B_Cac 
:USEION Cac WRITE Caci VALENCE 2
USEION Ca WRITE eCa VALENCE 2
:USEION IntCa WRITE IntCai VALENCE 1
USEION CaL READ iCaL
USEION CaT READ iCaT
USEION CaP READ iCaP
USEION PCa READ iPCa
RANGE Cac, IntCa, fi, F_ca, Vi, ksg
}

PARAMETER{
fi
F_ca
Vi
ksg
iCaL
iCaT
iCaP
iPCa
eCa
}

INITIAL{
IntCa = 0
Cac = 0.25
fi = 0.005
F_ca = 96480
Vi = 0.764
ksg = 0.00001
eCa = 100
}


STATE{
Cac
IntCa
}

BREAKPOINT{
SOLVE states METHOD cnexp
}

DERIVATIVE states{
Cac' = ((fi * ( - iCaL - iCaP - iCaT - (2.0 * iPCa)) / (2.0 * F_ca * Vi)) - (ksg * Cac))                
IntCa' = (0.001 * Cac)                
}
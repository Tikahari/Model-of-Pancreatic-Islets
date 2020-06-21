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
NEURON{
SUFFIX B_V
USEION CaL READ iCaL
USEION CaP READ iCaP
USEION CaT READ iCaT
USEION KDR READ iKDR
USEION PCa READ iPCa
USEION KCa READ iKCa
USEION BK READ iBK
USEION KATP READ iKATP
USEION HERG READ iHERG
USEION NaB READ iNaB
USEION Na READ iNa
USEION Vm WRITE Vmi VALENCE 1
RANGE Cm, Vreal
}

PARAMETER{
Cm
Vreal
iCaL
iCaP
iCaT
iKDR
iPCa
iKCa
iBK
iKATP
iHERG
iNaB
iNa
}

STATE{
Vmi
}

INITIAL{
Vmi = -61.5
Cm = 9990
}

BREAKPOINT{
Vreal = Vmi
SOLVE states METHOD cnexp
}

DERIVATIVE states{
Vmi' =  - ((iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa) / Cm)
}

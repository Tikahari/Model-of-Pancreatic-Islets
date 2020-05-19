NEURON{
SUFFIX A_GIRK
USEION GIRK WRITE iGIRK, eGIRK VALENCE 1
:POINTER S
RANGE knockoutda, gGIRKko, sombara2, ssom2, S
RANGE gGIRKbar, gGIRK, EffS, iGIRK
}

PARAMETER{
knockoutda 
gGIRKko 
sombara2
ssom2
S
eGIRK 
v
}

ASSIGNED{
gGIRKbar
gGIRK
EffS
iGIRK
}

INITIAL{
knockoutda = 0
gGIRKko = 0
sombara2 = 35
ssom2 = 10
eGIRK = -80
}

BREAKPOINT{
gGIRKbar = (1 - knockoutda) * 0.025 + knockoutda * gGIRKko
gGIRK = gGIRKbar * EffS
EffS = 1/(1 + exp(-(S - sombara2)/ssom2))
iGIRK = gGIRKbar * EffS * (v - eGIRK)
}


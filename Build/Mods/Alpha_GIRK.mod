: Sst inhibits G secretion by reducing cAMP, which primarily reduces exocytosis but also through
: act. of G protein-coupled inward rect potass (GIRK) chans
NEURON{
SUFFIX A_GIRK
USEION GIRK WRITE iGIRK, eGIRK VALENCE 1
:NONSPECIFIC_CURRENT i
RANGE knockoutda, gGIRKko, sombara2, ssom2
RANGE gGIRKbar, gGIRK, EffS
POINTER Sst
}

PARAMETER{
knockoutda 
gGIRKko 
sombara2
ssom2
}

ASSIGNED{
gGIRKbar
gGIRK
EffS
Sst
v
i
}

STATE{
iGIRK
eGIRK 
}

INITIAL{
eGIRK = -80
knockoutda = 0
gGIRKko = 0
sombara2 = 35
ssom2 = 10
}

BREAKPOINT{
gGIRKbar = (1 - knockoutda) * 0.025 + knockoutda * gGIRKko
:EffS = 1/(1 + exp(-(Sst - sombara2)/ssom2)) : Effect of Sst 
EffS = 1/(1 + exp(-(0 - sombara2)/ssom2)) : Effect of Sst 
gGIRK = gGIRKbar * EffS 
iGIRK = gGIRKbar * EffS * (v - eGIRK)
:i = -iGIRK
}


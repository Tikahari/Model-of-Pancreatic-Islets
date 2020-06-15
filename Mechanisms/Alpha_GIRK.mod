: Sst inhibits G secretion by reducing cAMP, which primarily reduces exocytosis but also through
: act. of G protein-coupled inward rect potass (GIRK) chans
NEURON{
SUFFIX A_GIRK
USEION GIRK WRITE iGIRK, eGIRK VALENCE 1
RANGE knockoutda, gGIRKko, sombara2, ssom2, S
RANGE gGIRKbar, gGIRK, EffS, iGIRK
:POINTER Sst
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
}

STATE{
iGIRK
eGIRK 
}

INITIAL{
}

BREAKPOINT{
gGIRKbar = (1 - knockoutda) * 0.025 + knockoutda * gGIRKko
gGIRK = gGIRKbar * EffS
EffS = 1/(1 + exp(-(Sst - sombara2)/ssom2)) : Effect of Sst 
iGIRK = gGIRKbar * EffS * (v - eGIRK)
}


<<<<<<< HEAD
=======
: sst inhibits G secretion by reducing cAMP, which primarily reduces exocytosis but also through
: act. of G protein-coupled inward rect potass (GIRK) chans
>>>>>>> fe8c19b62eba9796e280755f3128019db9728811
NEURON{
SUFFIX A_GIRK
USEION GIRK WRITE iGIRK, eGIRK VALENCE 1
USEION sst READ ssti
:POINTER S
RANGE knockoutda, gGIRKko, sombara2, ssom2, ssti
RANGE gGIRKbar, gGIRK, EffS, iGIRK
}

PARAMETER{
knockoutda 
gGIRKko 
sombara2
ssom2
ssti
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
EffS = 1/(1 + exp(-(ssti - sombara2)/ssom2)) : Effect of sst 
iGIRK = gGIRKbar * EffS * (v - eGIRK)
}


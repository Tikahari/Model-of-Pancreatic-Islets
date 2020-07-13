NEURON{
SUFFIX B_Ca
USEION Ca WRITE iCa, eCa VALENCE 2
RANGE gCa, nCa, vm, sm
RANGE minf
}

PARAMETER{
gCa
nCa 
vm 
sm 
}

ASSIGNED{
minf
eCa
v
}

STATE{
iCa
}

INITIAL{
gCa = 7
nCa = 590
vm = -6
eCa = 25
sm = 10
}

BREAKPOINT{
minf = 1/(1+exp((vm-v)/sm))
iCa = gCa*nCa*minf*(v-eCa)
}


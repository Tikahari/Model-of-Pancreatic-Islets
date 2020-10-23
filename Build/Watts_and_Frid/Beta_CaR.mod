NEURON{
    SUFFIX B_CaR
    USEION CaR WRITE iCaR VALENCE 1
    RANGE vm, sm, gCa, vCa, nCa
    RANGE minf, iCaR
}

PARAMETER{
    vm
    sm
    gCa
    vCa
    nCa
}

ASSIGNED{
    minf
    iCaR
    v
}

INITIAL{
    vm=-6
    sm=10
    gCa=7
    vCa=25
    nCa=590
}

BREAKPOINT{
    minf = 1/(1+exp((vm-v)/sm))
    iCaR = gCa*nCa*minf*(v-vCa)
}
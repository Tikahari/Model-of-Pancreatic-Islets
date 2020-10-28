NEURON{
    SUFFIX B_Ca
    USEION Ca WRITE iCa VALENCE 2
    RANGE vm, sm, gca, vca, nca
    RANGE minf, iCa
}

PARAMETER{
    vm
    sm
    gca
    vca
    nca
}

ASSIGNED{
    minf
    iCa
    v
}

INITIAL{
    vm=-6
    sm=10
    gca=7
    vca=25
    nca=590
}

BREAKPOINT{
    minf = 1/(1+exp((vm-v)/sm))
    iCa = gca*nca*minf*(v-vca)
}
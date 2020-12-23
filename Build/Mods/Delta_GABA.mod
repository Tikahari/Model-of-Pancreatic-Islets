NEURON{
    SUFFIX D_GABA
    USEION GABA WRITE iGABA VALENCE 1
    RANGE knockoutbd, vGABA 
    RANGE gGABAbar, EffId, iGABA
    POINTER I
}

PARAMETER{
    knockoutbd
    vGABA
    I
}

ASSIGNED{
    gGABAbar
    EffId
    v
    iGABA
}

INITIAL{
    knockoutbd=0
    vGABA=0
}

BREAKPOINT{
    gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
    EffId = 800/(1+exp(-(I-1500)/500))
    iGABA = gGABAbar*EffId*(v-vGABA)
}
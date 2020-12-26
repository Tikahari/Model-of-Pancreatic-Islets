NEURON{
    SUFFIX B_GIRK
    USEION GIRKb WRITE iGIRKb VALENCE 1
    RANGE knockoutdb, vGIRK, S, sombarb2
    RANGE gGIRKbarb, EffSb, iGIRKb
    POINTER Sst
}

PARAMETER{
    knockoutdb
    vGIRK
    Sst
    sombarb2
}

ASSIGNED{
    gGIRKbarb
    EffSb
    iGIRKb
    v
}

INITIAL{
    knockoutdb=0
    vGIRK=-80
    sombarb2=35
}

BREAKPOINT{
    gGIRKbarb=(1-knockoutdb)*10+knockoutdb*0
    EffSb=1/(1+exp(-(Sst-sombarb2)/10))
    iGIRKb=gGIRKbarb*EffSb*(v-vGIRK)
}

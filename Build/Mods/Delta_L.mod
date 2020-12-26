NEURON{
    SUFFIX D_L
    USEION ld WRITE ild VALENCE 1
    RANGE gld, vld
    RANGE ild
}

PARAMETER{
    gld
    vld
}

ASSIGNED{
    v
    ild
}

INITIAL{
    gld=200
    vld=-20
}

BREAKPOINT{
    ild=gld*(v-vld)
}
NEURON{
    SUFFIX A_L
    USEION la WRITE ila VALENCE 1
    RANGE gla, vla, ila
}

UNITS {
    (mV) = (millivolt)
}

PARAMETER{
    gla
    vla
}

ASSIGNED{
    ila
    v
}

INITIAL{
    gla=0.2
    vla=-20
}

BREAKPOINT{
    ila=gla*(v-vla)
}
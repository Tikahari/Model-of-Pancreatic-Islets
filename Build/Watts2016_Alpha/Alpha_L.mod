NEURON{
    SUFFIX A_L
    USEION la WRITE ila VALENCE 1
    RANGE gla, vla, ila
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemen)
    (pA) = (picoamp)
}

PARAMETER{
    gla     (nS)
    vla     (mV)
}

ASSIGNED{
    ila (pA)
    v   (mV)
}

INITIAL{
    gla=0.2
    vla=-20
}

BREAKPOINT{
    ila=gla*(v-vla)
}
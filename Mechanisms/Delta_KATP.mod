NEURON{
    SUFFIX D_KATP
    USEION katpd WRITE ikatpd VALENCE 1
    RANGE gkatpbard, vkd
    RANGE ikatpd
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemens)
}

PARAMETER{
    gkatpbard (nS)
    vkd (mV)
}

ASSIGNED{
    v (mV)
    ikatpd
}

INITIAL{
    gkatpbard=180
    vkd=-75
}

BREAKPOINT{
    ikatpd=gkatpbard*(v-vkd)
}
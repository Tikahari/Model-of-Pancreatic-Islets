NEURON{
    SUFFIX B_KATP
    USEION katp WRITE ikatp VALENCE 1
    RANGE gkatpb, vk
    RANGE ikatp
}

UNITS {
    (mV) = (millivolt)
    (pS) = (picosiemens)
}

PARAMETER{
    gkatpb  (pS)
    vk  (mV)
}

ASSIGNED{
    ikatp
    v   (mV)
}

INITIAL{
    gkatpb=85
    vk=-75
}

BREAKPOINT{
    ikatp = gkatpb*(v-vk)
}
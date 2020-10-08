NEURON{
    SUFFIX D_KATP
    USEION katpd WRITE ikatpd VALENCE 1
    RANGE gkatpbard, vkd
    RANGE ikatpd
}

PARAMETER{
    gkatpbard
    vkd
}

ASSIGNED{
    v
    ikatpd
}

INITIAL{
    gkatpbard=180
    vkd=-75
}

BREAKPOINT{
    ikatpd=gkatpbard*(v-vkd)
}
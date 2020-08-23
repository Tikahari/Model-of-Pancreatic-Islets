NEURON{
    SUFFIX B_KATP
    USEION katp WRITE ikatp VALENCE 1
    RANGE gkatpb, vk
    RANGE ikatp
}

PARAMETER{
    gkatpb
    vk
}

ASSIGNED{
    ikatp
    v
}

INITIAL{
    gkatpb=85
    vk=-75
}

BREAKPOINT{
    ikatp = gkatpb*(v-vk)
}
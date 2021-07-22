NEURON{
    SUFFIX dm1
    POINTER p
    RANGE rv
}

PARAMETER{
    p
}

ASSIGNED{
    rv
}


INITIAL{
    rv=-1
}

BREAKPOINT{
    rv=p
}

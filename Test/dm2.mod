NEURON{
    SUFFIX dm2
    RANGE p
}

ASSIGNED{
    p
}

INITIAL{
    p=10
}

BREAKPOINT{
    p=p+1
}

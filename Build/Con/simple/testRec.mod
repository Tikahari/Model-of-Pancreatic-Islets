NEURON{
    SUFFIX receive
    RANGE som
}

INITIAL{
    som = 1
}

STATE{
    som
}

BREAKPOINT{
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

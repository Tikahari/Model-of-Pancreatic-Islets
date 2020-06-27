NEURON{
    SUFFIX receive
    RANGE som
}

ASSIGNED{
som
}

BREAKPOINT{
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

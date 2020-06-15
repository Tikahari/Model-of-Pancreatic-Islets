NEURON{
    SUFFIX send
    RANGE som
}

INITIAL{
    som = 1
}

STATE{
    som
}

BREAKPOINT{
som = som + 1
VERBATIM
//printf("send\n");
ENDVERBATIM
}
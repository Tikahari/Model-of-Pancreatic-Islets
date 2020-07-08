NEURON{
SUFFIX receive
RANGE som
USEION glucagon READ glucagoni, glucagono, iglucagon
RANGE glucagoni, glucagono, iglucagon, gin, gout
}

ASSIGNED{
som
glucagoni
glucagono
iglucagon
gin
gout
}

INITIAL{
glucagoni = 3
}

BREAKPOINT{
gin = glucagoni
gout = glucagono
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

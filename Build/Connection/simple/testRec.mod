NEURON{
SUFFIX receive
RANGE som
USEION glucagon READ glucagono WRITE glucagoni, iglucagon VALENCE 1
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
iglucagon = iglucagon + 1
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

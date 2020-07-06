NEURON{
SUFFIX receive
RANGE som
USEION glucagon READ glucagoni, glucagono, iglucagon VALENCE 1
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

BREAKPOINT{
gin = glucagoni
gout = glucagono
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

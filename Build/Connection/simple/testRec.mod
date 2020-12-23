NEURON{
SUFFIX receive
RANGE som
USEION glucagon READ glucagoni, glucagono, iglucagon
RANGE glucagoni, glucagono, iglucagon, gin, gout
}

PARAMETER{
Kd
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
Kd = 1
}

BREAKPOINT{
gin = glucagoni
gout = glucagono
:iglucagon = (glucagoni/(Kd + glucagoni) - glucagono/(Kd + glucagono))
VERBATIM
//printf("receive\n");
ENDVERBATIM
}

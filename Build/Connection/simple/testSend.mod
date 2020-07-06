NEURON{
SUFFIX send
RANGE som
USEION glucagon READ glucagoni, glucagono, iglucagon
RANGE glucagoni, glucagono, iglucagon, gin, gout
}

PARAMETER{
dir
glucagoni
glucagono
iglucagon 
gin 
gout
}

INITIAL{
som = 1
dir = 0
}

STATE{
som
}

BREAKPOINT{
VERBATIM
//printf("send\n");
ENDVERBATIM
if(som > 2){
dir = 1
}
else if (som < 2){
dir = 0
}
if(dir == 0){
som = som + 1
}
else if (dir == 1){
som = som - 1
}
}
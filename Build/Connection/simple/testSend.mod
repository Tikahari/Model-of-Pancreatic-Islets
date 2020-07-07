NEURON{
SUFFIX send
RANGE som
USEION glucagon READ glucagoni, glucagono, iglucagon
RANGE glucagoni, glucagono, iglucagon, gin, gout
RANGE val
}

PARAMETER{
dir
glucagoni
glucagono
iglucagon 
gin 
gout
val
}

INITIAL{
glucagoni = 1000
som = 1
dir = 0
val = 999
}

STATE{
som
}

BREAKPOINT{
gin = glucagoni
gout = glucagono
som = som * 10
val = val + 1
}
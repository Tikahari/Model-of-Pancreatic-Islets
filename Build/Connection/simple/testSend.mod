NEURON{
SUFFIX send
USEION glucagon READ glucagono WRITE glucagoni, iglucagon VALENCE 1
RANGE som
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
:iglucagon = iglucagon + 1
glucagoni = 6
som = som * 10
val = val + 1
}
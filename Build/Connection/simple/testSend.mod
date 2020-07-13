NEURON{
SUFFIX send
USEION glucagon READ glucagono WRITE glucagoni VALENCE 1
RANGE som
RANGE glucagoni, glucagono, iglucagon, gin, gout
RANGE val
}

PARAMETER{
dir
glucagoni
glucagono
:iglucagon 
gin 
gout
val
Kd = 1
}

INITIAL{
glucagoni = 100
som = 1
dir = 0
val = 999
Kd = 1
}

STATE{
som
}

BREAKPOINT{
gin = glucagoni
gout = glucagono
:iglucagon = 100
glucagoni = glucagoni + 1
som = som * 10
val = val + 1
}
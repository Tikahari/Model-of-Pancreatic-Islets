NEURON{
SUFFIX A_Glucagon
RANGE Jgs, vol, f
}

PARAMETER{
Jgs
vol
f
v
}

STATE{
G
}

INITIAL{
f = 150
}

BREAKPOINT{
SOLVE states METHOD cnexp
}

DERIVATIVE states{
G' = (Jgs / vol) - f * G
}

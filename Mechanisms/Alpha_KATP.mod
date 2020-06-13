NEURON{
SUFFIX A_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
RANGE knockoutba, ka1, gKATPbara
RANGE EffIa, gKATPa, iKATPa
POINTER Ins
}

PARAMETER{
knockoutba
ka1
gKATPbara
}

ASSIGNED{
EffI
gKATP
Ins
eK
v
}

STATE{
iKATP
}

INITIAL{
}

: B cell modifies G secretion by increasing KATPa chan activity, so conductance of gKATPa
: chans depends on concentration of I 
BREAKPOINT{
EffI = (1 - knockoutba) * ((0.015/(1 + exp((-Ins + 1500)/200))) + ka1) + knockoutba * ka1
gKATP = gKATPbara * EffI
iKATP = gKATP*(v - eK)
}

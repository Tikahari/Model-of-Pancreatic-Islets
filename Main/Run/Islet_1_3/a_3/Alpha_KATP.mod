NEURON{
SUFFIX A_KATP3
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
RANGE knockoutba, ka1, gKATPbara
RANGE EffI, gKATP
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
knockoutba = 0
ka1 = 0.1
gKATPbara = 3
}

: B cell modifies G secretion by increasing KATPa chan activity, so conductance of gKATPa
: chans depends on concentration of I 

BREAKPOINT{
EffI = (1 - knockoutba) * ((0.015/(1 + exp((-Ins + 1500)/200))) + ka1) + knockoutba * ka1
gKATP = gKATPbara * EffI
iKATP = gKATP*(v - eK)
}

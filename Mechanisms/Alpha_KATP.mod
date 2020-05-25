NEURON{
SUFFIX A_KATP
USEION KATP WRITE iKATP VALENCE 1
USEION K READ eK
:POINTER I
RANGE knockoutba, ka1, gKATPbara, I
RANGE EffIa, gKATPa, iKATPa
}

PARAMETER{
knockoutba
ka1
gKATPbara
I
eK
v
}

ASSIGNED{
EffI
gKATP
iKATP
}

INITIAL{
knockoutba = 0
gKATPbara = 3  : 3 nS for G1; 0.6 nS for G7; 0.15 nS for G11
ka1 = 0.1
eK = -75
}
: B cell modifies G secretion by increasing KATPa chan activity, so conductance of gKATPa
: chans depends on concentration of I 
BREAKPOINT{
EffI = (1 - knockoutba) * ((0.015/(1 + exp((-I + 1500)/200))) + ka1) + knockoutba * ka1
gKATP = gKATPbara * EffI
iKATP = gKATP*(v - eK)
}

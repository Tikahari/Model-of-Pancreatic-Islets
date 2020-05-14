NEURON{
SUFFIX A_KATP
USEION KATP WRITE iKATP VALENCE 1
RANGE iKATP, gKATP, EffI

}

PARAMETER{



}

ASSIGNED{
iKATP
gKATP
EffI
}

STATE{



}



INITIAL{
gbarKATP = 3  : 3 nS for G1; 0.6 nS for G7; 0.15 nS for G11
}

BREAKPOINT{
iKATP = gKATP(v - eK)
gKATP = gbarKAPT * EffI
EffI = 0.015/(1 + exp(-(I - 1500)/200)) + ka
SOLVE states METHOD cnexp
}

DERIVATIVE states{


}

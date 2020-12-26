NEURON{
    SUFFIX A_Kdr
    USEION kdra WRITE ikdra VALENCE 1
    RANGE vka, vkdrma, skdrma, gkdra
    RANGE mkdrinfa, taukdrma, ikdra
}

UNITS {
    (mV) = (millivolt)
    (pA) = (picoamp)
    (nS) = (nanosiemen)
    (ms) = (millisecond)
}

PARAMETER{
    vka (mV)
    vkdrma  (mV)
    skdrma  (mV)
    gkdra   (nS)
}

ASSIGNED{
    mkdrinfa    :dimensionless
    taukdrma    (ms)
    v   (mV)
    ikdra   (pA)
}

STATE{
    mkdra   :dimensionless
}

INITIAL{
    mkdra=0.2674634279865117 
    vka=-75
    vkdrma=-25
    skdrma=23
    gkdra=4.5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mkdrinfa=1/(1+exp(-(v-vkdrma)/skdrma))
    taukdrma=(1.5/(exp(-(v+10)/25)+exp((v+10)/25)))+15
    ikdra=gkdra*(mkdra^4)*(v-vka)
}

DERIVATIVE states{
    mkdra'=(mkdrinfa-mkdra)/taukdrma
}
NEURON{
    SUFFIX A_Kdr
    USEION kdra WRITE ikdra VALENCE 1
    RANGE vka, vkdrma, skdrma, gkdra
    RANGE mkdrinfa, taukdrma, ikdra
}

PARAMETER{
    vka
    vkdrma
    skdrma
    gkdra
}

ASSIGNED{
    mkdrinfa
    taukdrma
    v
    ikdra
}

STATE{
    mkdra
}

INITIAL{
    mkdra=0.2674634279865117 
    vka=-75
    vkdrma=-25
    skdrma=23
    gkdra=4.5

    taukdrma = 0.5
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
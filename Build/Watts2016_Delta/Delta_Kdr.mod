NEURON{
    SUFFIX D_Kdr
    USEION kdrd WRITE ikdrd VALENCE 1
    RANGE gkdrd, vkd, vkdrmd, skdrmd
    RANGE mkdrinfd, taukdrmd, ikdrd
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemens)
}

PARAMETER{
    gkdrd   (nS)
    vkd (mV)
    vkdrmd
    skdrmd
}

ASSIGNED{
    mkdrinfd
    taukdrmd
    v   (mV)
    ikdrd
}

STATE{
    mkdrd
}

INITIAL{
    mkdrd=0.5717652452166768 
    gkdrd=7500
    vkd=-75
    vkdrmd=-25
    skdrmd=23
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mkdrinfd=1/(1+exp(-(v-vkdrmd)/skdrmd))
    taukdrmd=(1.5/(exp(-(v+10)/25)+exp((v+10)/25)))+15
    ikdrd=gkdrd*mkdrd^4*(v-vkd)
}

DERIVATIVE states{
    mkdrd'=(mkdrinfd-mkdrd)/taukdrmd
}
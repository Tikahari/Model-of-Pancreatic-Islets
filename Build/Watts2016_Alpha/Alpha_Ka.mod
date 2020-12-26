NEURON{
    SUFFIX A_K
    USEION kaa WRITE ikaa VALENCE 1
    RANGE vka, gkaa, vkama, skama, vkaha, skaha, taukama, tkah1a, tkah2a
    RANGE mkainfa, hkainfa, taukaha, ikaa
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemen)
    (ms) = (millisecond)
    (pA) = (picoamp)
}

PARAMETER{
    vka (mV)
    gkaa    (nS)
    vkama (mV)
    skama   (mV)
    vkaha   (mV)
    skaha   (mV)
    taukama (ms)
    tkah1a  (ms)
    tkah2a  (ms)
}

ASSIGNED{
    mkainfa    :dimensionless
    hkainfa    :dimensionless
    taukaha    (ms)
    v   (mV)
    ikaa    (pA)
}

STATE{
    mkaa    :dimensionless
    hkaa    :dimensionless
}

INITIAL{
    mkaa=0.4001652246173745
    hkaa=0.1373195977592295  
    vka=-75
    gkaa=1
    vkama=-45
    skama=10
    vkaha=-68
    skaha=-10
    taukama=0.1
    tkah1a=60
    tkah2a=5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mkainfa=1/(1+exp(-(v-vkama)/skama))
    hkainfa=1/(1+exp(-(v-vkaha)/skaha))
    taukaha=(tkah1a/(exp(-(v-5)/20)+exp((v-5)/20)))+tkah2a
    ikaa=gkaa*mkaa*hkaa*(v-vka)
}

DERIVATIVE states{
    mkaa'=(mkainfa-mkaa)/taukama
    hkaa'=(hkainfa-hkaa)/taukaha
}
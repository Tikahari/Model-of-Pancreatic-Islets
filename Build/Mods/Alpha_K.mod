NEURON{
    SUFFIX A_K
    USEION kaa WRITE ikaa VALENCE 1
    RANGE vka, gkaa, vkama, skama, vkaha, skaha, taukama, tkah1a, tkah2a
    RANGE mkainfa, hkainfa, taukaha, ikaa
}

PARAMETER{
    vka
    gkaa
    vkama
    skama
    vkaha
    skaha
    taukama
    tkah1a
    tkah2a
}

ASSIGNED{
    mkainfa
    hkainfa
    taukaha
    v
    ikaa
}

STATE{
    mkaa
    hkaa
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

    taukaha = 0.5
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
NEURON{
    SUFFIX D_K
    USEION kad WRITE ikad VALENCE 1
    RANGE gkad, vkd, vkamd, skamd, vkahd, skahd, taukamd, tkah1d, tkah2d
    RANGE mkainfd, hkainfd, taukahd, ikad
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemens)
}

PARAMETER{
    gkad    (nS)
    vkd (mV)
    vkamd
    skamd
    vkahd
    skahd
    taukamd
    tkah1d
    tkah2d
}

ASSIGNED{
    mkainfd
    hkainfd
    taukahd
    v   (mV)
    ikad
}

STATE{
    mkad
    hkad
}

INITIAL{
    mkad=0.9480884005315277 
    hkad=0.02771925786328598  
    gkad=500
    vkd=-75
    vkamd=-45
    skamd=10
    vkahd=-68
    skahd=-10
    taukamd=0.1
    tkah1d=60
    tkah2d=5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mkainfd=1/(1+exp(-(v-vkamd)/skamd))
    hkainfd=1/(1+exp(-(v-vkahd)/skahd))
    taukahd=(tkah1d/(exp(-(v-5)/20)+exp((v-5)/20)))+tkah2d
    ikad=gkad*mkad*hkad*(v-vkd)
}

DERIVATIVE states{
    mkad'=(mkainfd-mkad)/taukamd
    hkad'=(hkainfd-hkad)/taukahd
}
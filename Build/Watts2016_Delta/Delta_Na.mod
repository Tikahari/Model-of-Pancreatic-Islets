NEURON{
    SUFFIX D_Na
    USEION nad WRITE inad VALENCE 1
    RANGE gnad, vnad, vnamd, vnahd, snamd, snahd, tnah1d, tnah2d
    RANGE mnainfd, hnainfd, taunamd, taunahd, inad
}

UNITS{
    (mV) = (millivolt)
    (nS) = (nanosiemens)
}

PARAMETER{
    gnad    (nS)
    vnad    (mV)
    vnamd
    vnahd
    snamd
    snahd
    tnah1d
    tnah2d
}

ASSIGNED{
    mnainfd
    hnainfd
    taunamd
    taunahd
    v   (mV)
    inad
}

STATE{
    mnad
    hnad
}

INITIAL{
    mnad=0.9737137320580179  
    hnad=0.006777955247303555  
    gnad=5000
    vnad=70
    vnamd=-30
    vnahd=-52
    snamd=4
    snahd=-8
    tnah1d=120
    tnah2d=0.5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mnainfd=1/(1+exp(-(v-vnamd)/snamd))
    hnainfd=1/(1+exp(-(v-vnahd)/snahd))
    taunamd=(6/(exp(-(v+50)/10)+exp((v+50)/10)))+0.05
    taunahd=(tnah1d/(exp(-(v+50)/8)+exp((v+50)/8)))+tnah2d
    inad=gnad*mnad^3*hnad*(v-vnad)
}

DERIVATIVE states{
    mnad'=(mnainfd-mnad)/taunamd
    hnad'=(hnainfd-hnad)/taunahd
}
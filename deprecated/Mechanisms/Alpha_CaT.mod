NEURON{
    SUFFIX A_CaT
    USEION cata WRITE icata VALENCE 2
    RANGE vcaa, gcata, vcatma, scatma, vcatha, scatha, tcatm1a, tcatm2a, tcath1a, tcath2a
    RANGE mcatinfa, hcatinfa, taucatma, taucatha, icata
}

PARAMETER{
    vcaa
    gcata
    vcatma
    scatma
    vcatha
    scatha
    tcatm1a
    tcatm2a
    tcath1a
    tcath2a
}

ASSIGNED{
    mcatinfa
    hcatinfa
    taucatma
    taucatha
    v
    icata
}

STATE{
    mcata
    hcata
}

INITIAL{
    mcata=0.4633857551023612  
    hcata=0.3735421388722815    
    vcaa=65
    gcata=0.5
    vcatma=-49
    scatma=4
    vcatha=-52
    scatha=-5
    tcatm1a=15
    tcatm2a=0
    tcath1a=20
    tcath2a=5
    taucatma = 0.5
    taucatha = 0.5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mcatinfa=1/(1+exp(-(v-vcatma)/scatma))
    hcatinfa=1/(1+exp(-(v-vcatha)/scatha))
    taucatma=(tcatm1a/(exp(-(v+50)/12)+exp((v+50)/12)))+tcatm2a
    taucatha=(tcath1a/(exp(-(v+50)/15)+exp((v+50)/15)))+tcath2a
    icata=gcata*(mcata^3)*hcata*(v-vcaa)
}

DERIVATIVE states{
    mcata'=(mcatinfa-mcata)/taucatma
    hcata'=(hcatinfa-hcata)/taucatha
}
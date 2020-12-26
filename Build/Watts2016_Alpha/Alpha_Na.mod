NEURON{
    SUFFIX A_Na
    USEION naa WRITE inaa VALENCE 1
    RANGE vnaa, vnama, vnaha, snama, snaha, tnah1a, tnah2a, gnaa
    RANGE mnainfa, hnainfa, taunama, taunaha, inaa
}

UNITS {
    (mV) = (millivolt)
    (pA) = (picoamp)
    (nS) = (nanosiemen)
    (ms) = (millisecond)
}

PARAMETER{
    vnaa    (mV)
    vnama   (mV)
    vnaha   (mV)
    snama   (mV)
    snaha   (mV)
    tnah1a  (ms)
    tnah2a  (ms)
    gnaa    (nS)
}

ASSIGNED{
    mnainfa :dimensionless
    hnainfa :dimensionless
    taunama (ms)    
    taunaha (ms)
    v   (mV)
    inaa    (pA)
}

STATE{
    mnaa    :dimensionless
    hnaa    :dimensionless
}

INITIAL{
    mnaa=0.007938786735335676  
    hnaa=0.2498175179717122 
    vnaa=70
    vnama=-30
    vnaha=-52
    snama=4
    snaha=-8
    tnah1a=120
    tnah2a=0.5
    gnaa=11

    taunama = 0.5
    taunaha = 0.5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mnainfa=1/(1+exp(-(v-vnama)/snama))
    hnainfa=1/(1+exp(-(v-vnaha)/snaha))
    taunama=(6/(exp(-(v+50)/10)+exp((v+50)/10)))+0.05
    taunaha=(tnah1a/(exp(-(v+50)/8)+exp((v+50)/8)))+tnah2a
    inaa=gnaa*(mnaa^3)*hnaa*(v-vnaa)
}

DERIVATIVE states{
    mnaa'=(mnainfa-mnaa)/taunama
    hnaa'=(hnainfa-hnaa)/taunaha
}
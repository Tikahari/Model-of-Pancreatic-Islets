NEURON{
    SUFFIX A_CaL
    USEION cala WRITE icala VALENCE 2
    RANGE vcaa, vcala, gcala, tcalh1a, tcalh2a, vcalma, scalma, vcalha, scalha
    RANGE taucalma, taucalha, mcalinfa, hcalinfa, icala
}

UNITS {
    (mV) = (millivolt)
    (pA) = (picoamp)
    (nS) = (nanosiemen)
    (ms) = (milliseconds)
}

PARAMETER{
    vcaa    (mV)
    vcala   (mV)
    gcala   (nS)
    tcalh1a (ms)
    tcalh2a (ms)
    vcalma  (mV)
    scalma  (mV)
    vcalha  (mV)
    scalha  (mV)
}

ASSIGNED{
    taucalma    (ms)
    taucalha    (ms)
    mcalinfa    :dimensionless
    hcalinfa    :dimensionless
    v   (mV)
    icala   (pA)
}

STATE{
    mcala   :dimensionless
    hcala   :dimensionless
}

INITIAL{
    mcala=0.1293341713632475  
    hcala=0.8127842536675057  
    vcaa=65
    gcala=0.7
    vcalma=-30
    scalma=10
    vcalha=-33
    scalha=-5
    tcalh1a=60
    tcalh2a=51
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    taucalma=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
    taucalha=(tcalh1a/(exp(-(v+0)/20)+exp((v+0)/20)))+tcalh2a
    mcalinfa=1/(1+exp(-(v-vcalma)/scalma))
    hcalinfa=1/(1+exp(-(v-vcalha)/scalha))
    icala=gcala*(mcala^2)*hcala*(v-vcaa)
}

DERIVATIVE states{
    mcala'=(mcalinfa-mcala)/taucalma
    hcala'=(hcalinfa-hcala)/taucalha
}
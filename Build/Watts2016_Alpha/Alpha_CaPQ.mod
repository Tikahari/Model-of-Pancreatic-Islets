NEURON{
    SUFFIX A_CaPQ
    USEION capqa WRITE icapqa VALENCE 2
    RANGE vcaa, tcapqh1a, tcapqh2a, vcapqma, scapqma, vcapqha, scapqha, gcapqa
    RANGE mcapqinfa, hcapqinfa, taucapqma, taucapqha, icapqa
}

UNITS {
    (mV) = (millivolt)
    (ms) = (millisecond)
    (nS) = (nanosiemen)
    (pA) = (picoamps)
}

PARAMETER{
    vcaa    (mV)
    tcapqh1a    (ms)
    tcapqh2a    (ms)
    vcapqma     (mV)
    scapqma     (mV)
    vcapqha     (mV)
    scapqha     (mV)
    gcapqa      (nS)
}

ASSIGNED{
    mcapqinfa   :dimensionless
    hcapqinfa   :dimensionless
    taucapqma   (ms)
    taucapqha   (ms)
    v   (mV)
    icapqa  (pA)
}

STATE{
    mcapqa
    hcapqa
}

INITIAL{ 
    mcapqa=0.0120465460803863  
    hcapqa=0.8127842536675057  
    vcaa=65
    vcapqma=-5
    scapqma=10
    vcapqha=-33
    scapqha=-5
    gcapqa=0.6
    tcapqh1a=60
    tcapqh2a=51
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mcapqinfa=1/(1+exp(-(v-vcapqma)/scapqma))
    hcapqinfa=1/(1+exp(-(v-vcapqha)/scapqha))
    taucapqma=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
    taucapqha=(tcapqh1a/(exp(-(v+0)/20)+exp((v+0)/20)))+tcapqh2a
    icapqa=gcapqa*mcapqa*hcapqa*(v-vcaa)
}

DERIVATIVE states{
    mcapqa'=(mcapqinfa-mcapqa)/taucapqma
    hcapqa'=(hcapqinfa-hcapqa)/taucapqha
}
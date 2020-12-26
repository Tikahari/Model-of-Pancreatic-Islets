NEURON{
    SUFFIX A_CaPQ
    USEION capqa WRITE icapqa VALENCE 2
    RANGE vcaa, tcapqh1a, tcapqh2a, vcapqma, scapqma, vcapqha, scapqha, gcapqa
    RANGE mcapqinfa, hcapqinfa, taucapqma, taucapqha, icapqa
}

PARAMETER{
    vcaa
    tcapqh1a
    tcapqh2a
    vcapqma
    scapqma
    vcapqha
    scapqha
    gcapqa
}

ASSIGNED{
    mcapqinfa
    hcapqinfa
    taucapqma
    taucapqha
    v
    icapqa
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

    taucapqma = 0.5
    taucapqha = 0.5
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
NEURON{
    SUFFIX D_CaPQ
    USEION capqd WRITE icapqd VALENCE 2
    RANGE gcapqd, vcad, scapqmd, vcapqmd, scapqhd, vcapqhd, tcapqh1d, tcapqh2d
    RANGE mcapqinfd, hcapqinfd, taucapqmd, taucapqhd, icapqd
}

PARAMETER{
    gcapqd
    vcad
    scapqmd
    vcapqmd
    scapqhd
    vcapqhd
    tcapqh1d
    tcapqh2d
}

ASSIGNED{
    mcapqinfd
    hcapqinfd
    taucapqmd
    taucapqhd
    v
    icapqd
}

STATE{
    mcapqd
    hcapqd
}

INITIAL{
    mcapqd=0.5089033026581684  
    hcapqd=0.6672499701175263  
    gcapqd=700
    vcad=65
    vcapqmd=-15
    scapqmd=10
    vcapqhd=-33
    scapqhd=-5
    tcapqh1d=60
    tcapqh2d=51
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mcapqinfd=1/(1+exp(-(v-vcapqmd)/scapqmd))
    hcapqinfd=1/(1+exp(-(v-vcapqhd)/scapqhd))
    taucapqmd=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
    taucapqhd=(tcapqh1d/(exp(-(v+0)/20)+exp((v+0)/20)))+tcapqh2d
    icapqd=gcapqd*mcapqd*hcapqd*(v-vcad)
}

DERIVATIVE states{
    mcapqd'=(mcapqinfd-mcapqd)/taucapqmd
    hcapqd'=(hcapqinfd-hcapqd)/taucapqhd
}
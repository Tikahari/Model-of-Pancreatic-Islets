NEURON{
    SUFFIX D_CaL
    USEION cald WRITE icald VALENCE 2
    RANGE gcald, vcad, vcalmd, scalmd, vcalhd, scalhd, tcalh1d, tcalh2d
    RANGE mcalinfd, hcalinfd, taucalmd, taucalhd, icald
}

PARAMETER{
    gcald
    vcad
    vcalmd
    scalmd
    vcalhd
    scalhd
    tcalh1d
    tcalh2d
}

ASSIGNED{
    mcalinfd
    hcalinfd
    taucalmd
    taucalhd
    v
    icald
}

STATE{
    mcald
    hcald
}

INITIAL{
    mcald=0.8218051702003508  
    hcald=0.6672499701175263  
    gcald=700
    vcad=65
    vcalmd=-30
    scalmd=10
    vcalhd=-33
    scalhd=-5
    tcalh1d=60
    tcalh2d=51
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    mcalinfd=1/(1+exp(-(v-vcalmd)/scalmd))
    hcalinfd=1/(1+exp(-(v-vcalhd)/scalhd))
    taucalmd=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
    taucalhd=(tcalh1d/(exp(-(v+0)/20)+exp((v+0)/20)))+tcalh2d
    icald=gcald*mcald^2*hcald*(v-vcad)
}

DERIVATIVE states{
    mcald'=(mcalinfd-mcald)/taucalmd
    hcald'=(hcalinfd-hcald)/taucalhd
}
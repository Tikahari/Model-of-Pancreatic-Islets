NEURON{
    SUFFIX B_K
    USEION K WRITE iK VALENCE 1
    RANGE taun, vk, gk, vn, sn
    RANGE ninf, ik
}

UNITS{
    (picosiemens) = (pS)
    (milliseconds) = (ms)
}

PARAMETER{
    taun    (ms)
    vk
    gk  (pS)
    vn
    sn
}

ASSIGNED{
    ninf
    iK
    v
}

STATE{
    n
}

INITIAL{
    :n=9.875188779513991e-05 
    taun=5
    vk=-75
    gk=1800
    vn=-16
    sn=6
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    ninf = 1/(1+exp((vn-v)/sn))
    iK = gk*n*(v-vk)
}

DERIVATIVE states{
    n' = (ninf-n)/taun
}
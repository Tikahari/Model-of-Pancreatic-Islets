NEURON{
    SUFFIX A_KATP
    USEION katpa WRITE ikatpa VALENCE 1
    RANGE gkatpbara, vka, ka1, knockoutba
    RANGE EffIa, gkatpa, ikatpa
    POINTER I
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemens)
}

PARAMETER{
    gkatpbara   (nS)
    vka  (mV)
    ka1
    knockoutba
    I
}

ASSIGNED{
    EffIa
    gkatpa  (mV)
    v   (mV)
    ikatpa
}

INITIAL{
    gkatpbara=0.015 
    vka=-75 
    ka1=0.1
    knockoutba=0
}

BREAKPOINT{
    EffIa=(1-knockoutba)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutba*ka1
    gkatpa=gkatpbara*EffIa
    ikatpa=gkatpa*(v-vka)
}

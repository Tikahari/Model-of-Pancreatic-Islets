NEURON{
    SUFFIX A_GIRK
    USEION GIRKa WRITE iGIRKa VALENCE 1
    RANGE knockoutda, gGIRKko, vGIRK, sombara2, ssom2
    RANGE gGIRKbara, EffSa, iGIRKa
    POINTER Sst
}

UNITS {
    (mV) = (millivolt)
    (nS) = (nanosiemen)
    (molar) = (1/liter)
    (pM) = (picomolar)
    (pA) = (picoamp)
}

PARAMETER{
    knockoutda  :dimensionless
    gGIRKko  (nS)
    vGIRK   (mV)
    S   (pM)
    sombara2
    ssom2
    Sst     (pM)
}

ASSIGNED{
    gGIRKbara   (nS)
    EffSa   :dimensionless
    v   (mV)
    iGIRKa  (pA)
}

INITIAL{
    knockoutda=0
    gGIRKko=0
    vGIRK=-80
    sombara2=35
    ssom2=10
}

BREAKPOINT{
    gGIRKbara=(1-knockoutda)*0.025+knockoutda*gGIRKko
    EffSa=1/(1+exp(-(Sst-sombara2)/ssom2))
    iGIRKa=gGIRKbara*EffSa*(v-vGIRK)
}
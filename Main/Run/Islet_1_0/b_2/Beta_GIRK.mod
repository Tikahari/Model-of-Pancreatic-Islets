NEURON{
SUFFIX B_GIRK2
USEION GIRK WRITE iGIRK, eGIRK VALENCE 1
RANGE sombarb2, knockoutdb
RANGE EffSb, gGIRKbarb
POINTER Sst
}

PARAMETER{
sombarb2
knockoutdb
Sst
}

ASSIGNED{
EffSb
gGIRKbarb
v
}

STATE{
iGIRK
eGIRK
}

INITIAL{
sombarb2 = 35
knockoutdb = 0
eGIRK = -80
}

BREAKPOINT{
EffSb = 1/(1+exp(-(Sst-sombarb2)/10)) :delta inhibiting beta
gGIRKbarb=(1-knockoutdb)*10+knockoutdb*0
iGIRK = gGIRKbarb*EffSb*(v-eGIRK)
}


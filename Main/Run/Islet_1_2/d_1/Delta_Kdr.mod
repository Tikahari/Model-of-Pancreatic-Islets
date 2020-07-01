NEURON{
SUFFIX D_Kdr1
USEION Kdr WRITE iKdr VALENCE 1
USEION K READ eK
RANGE vKdrm, sKdrm, gKdr 
RANGE mKdr_inf, tauKdrm
}

PARAMETER{   
vKdrm 
sKdrm 
gKdr  
}

ASSIGNED{
mKdr_inf
tauKdrm
eK
v : This is the voltage when I run h.initial.....
}

STATE{
iKdr
mKdr
}

INITIAL{
vKdrm = -25
sKdrm = 23
gKdr = 7.5
mKdr = 0.5717652452166768
}

BREAKPOINT{
mKdr_inf = 1/(1 + exp(-(v - vKdrm)/sKdrm))
tauKdrm = (1.5/(exp(-(v + 10)/25) + exp((v + 10)/25))) + 15
SOLVE states METHOD cnexp : Put current equation below this
iKdr = gKdr * pow(mKdr,4) * (v - eK)
}

DERIVATIVE states{
mKdr' = (mKdr_inf - mKdr)/tauKdrm
}


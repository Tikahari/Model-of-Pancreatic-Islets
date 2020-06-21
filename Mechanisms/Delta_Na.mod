NEURON{
SUFFIX D_Na
USEION Na WRITE iNa, eNa VALENCE 1
RANGE gNa, vNam, vNah, sNam, sNah, tNah1, tNah2
RANGE mNa_inf, hNa_inf, tauNam, tauNah
}

PARAMETER{   
gNa
vNam
vNah 
sNam 
sNah 
tNah1 
tNah2 
}

ASSIGNED{
mNa_inf
hNa_inf
tauNam
tauNah
v : This is the voltage when I run h.initial.....
}

STATE{
eNa 
iNa
mNa
hNa
}

INITIAL{
}

BREAKPOINT{
mNa_inf = 1/(1 + exp(-(v - vNam)/sNam))
hNa_inf = 1/(1 + exp(-(v - vNah)/sNah))
tauNam = (6/(exp(-(v + 50)/10) + exp((v + 50)/10))) + 0.05
tauNah = (tNah1/(exp(-(v + 50)/8) + exp((v + 50)/8))) + tNah2
SOLVE states METHOD cnexp : Put current equation below this
iNa = gNa * pow(mNa,3) * hNa * (v - eNa)
}

DERIVATIVE states{
mNa' = (mNa_inf - mNa)/tauNam
hNa' = (hNa_inf - hNa)/tauNah
}


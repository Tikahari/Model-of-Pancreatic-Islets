NEURON{
SUFFIX D_Na
USEION Na WRITE iNa VALENCE 1
USEION Na WRITE eNa VALENCE 1
RANGE gNa, vNam, vNah , sNam, sNah, tNah1, tNah2 
RANGE mNa_inf, hNa_inf, tauNam, tauNah, iNa
}

PARAMETER{   
gNa
vNam
vNah 
sNam 
sNah 
tNah1 
tNah2 
eNa 
v : This is the voltage when I run h.initial.....
}

ASSIGNED{
mNa_inf
hNa_inf
tauNam
tauNah
iNa
}

STATE{
mNa
hNa
}

INITIAL{
eNa = -70
gNa = 5
vNam = -30
vNah = -52
sNam = 4
sNah = -8
tNah1 = 120
tNah2 = 0.5
mNa = 0.9737137320580179  
hNa = 0.006777955247303555
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

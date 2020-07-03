NEURON{
SUFFIX D_Ka
USEION Ka WRITE iKa VALENCE 1
USEION K WRITE eK VALENCE 1
RANGE gKa, vKam, sKam, vKah, sKah, tauKam, tKah1, tKah2 
RANGE mKa_inf, hKa_inf, tauKah
}

PARAMETER{   
gKa 
vKam 
sKam 
vKah 
sKah 
tauKam 
tKah1 
tKah2 
}

ASSIGNED{
mKa_inf
hKa_inf
tauKah
v : This is the voltage when I run h.initial.....
}

STATE{
eK
iKa
mKa
hKa
}

INITIAL{
eK = -75
gKa = 0.5
vKam = -45
sKam = 10
vKah = -68
sKah = -10
tauKam = 0.1
tKah1 = 60
tKah2 = 5
mKa = 0.9480884005315277
hKa = 0.02771925786328598
}

BREAKPOINT{
mKa_inf = 1/(1 + exp(-(v - vKam)/sKam))
hKa_inf = 1/(1 + exp(-(v - vKah)/sKah))
tauKah = (tKah1/(exp(-(v - 5)/20) + exp((v - 5)/20))) + tKah2
SOLVE states METHOD cnexp : Put current equation below this
iKa = gKa * mKa * hKa * (v - eK)

}

DERIVATIVE states{
mKa' = (mKa_inf - mKa)/tauKam
hKa' = (hKa_inf - hKa)/tauKah
}


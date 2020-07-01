NEURON{
SUFFIX B_K
USEION K WRITE iK VALENCE 1
USEION k WRITE ek VALENCE 1
RANGE gK, vn, sn, taun
RANGE ninf
}

PARAMETER{
gK
vn
sn
taun
}

ASSIGNED{
ninf
v
}

STATE{
iK
ek
n
}

INITIAL{
gK = 1800
n = 9.875188779513991e-05 
ek = -75
vn = -16
sn = 6
taun = 5
}

BREAKPOINT{
ninf = 1/(1+exp((vn-v)/sn))
SOLVE states METHOD cnexp
iK = gK*n*(v-ek)
}

DERIVATIVE states{
n' = (ninf-n)/taun
}

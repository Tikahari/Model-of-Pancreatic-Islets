NEURON{
SUFFIX A_KDR
USEION Kdr WRITE iKdr, eKdr VALENCE 1
RANGE gkdr, vkdrm, skdrm
RANGE mkdrinf, taukdrm
}

PARAMETER{
gkdr
vkdrm
skdrm
}

ASSIGNED{
mkdrinf
taukdrm
eKdr
v
}

STATE{
iKdr
mkdr
}

INITIAL{
eKdr = -75
gkdr = 4.5
mkdr = 0.2674634279865117
vkdrm = -25
skdrm = 23
}

BREAKPOINT{
mkdrinf = 1/(1+exp(-(v-vkdrm)/skdrm))
taukdrm = (1.5/(exp(-(v+10)/25)+exp((v+10)/25)))+15
SOLVE states METHOD cnexp
iKdr = gkdr*pow(mkdr,4)*(v-eKdr)
}

DERIVATIVE states{
mkdr' = (mkdrinf - mkdr)/taukdrm
}
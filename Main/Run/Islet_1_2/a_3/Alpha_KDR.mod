NEURON{
SUFFIX A_KDR3
USEION KDR WRITE iKDR VALENCE 1
USEION K READ eK
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
eK
v
}

STATE{
iKDR
mkdr
}

INITIAL{
gkdr = 4.5
mkdr = 0.2674634279865117
vkdrm = -25
skdrm = 23
}

BREAKPOINT{
mkdrinf = 1/(1+exp(-(v-vkdrm)/skdrm))
taukdrm = (1.5/(exp(-(v+10)/25)+exp((v+10)/25)))+15
SOLVE states METHOD cnexp
iKDR = gkdr*pow(mkdr,4)*(v-eK)
}

DERIVATIVE states{
mkdr' = (mkdrinf - mkdr)/taukdrm
}
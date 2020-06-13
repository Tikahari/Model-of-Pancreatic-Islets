NEURON{
SUFFIX A_KDR
USEION KDR WRITE iKDR VALENCE 1
USEION K READ eK
RANGE gkdr, vkdrm, skdrm
RANGE iKDR, mkdrinf, taukdrm
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
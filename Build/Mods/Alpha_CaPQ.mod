NEURON{
SUFFIX A_CaPQ
USEION CaPQ WRITE iCaPQ, eCaPQ VALENCE 1
:NONSPECIFIC_CURRENT i
:USEION Ca READ eCa 
RANGE gcapq, vcapqm, scapqm, vcapqh, scapqh, tcapqh1, tcapqh2
RANGE mcapqinf, hcapqinf, taucapqm, taucapqh
}

PARAMETER{
gcapq
vcapqm
scapqm
vcapqh
scapqh
tcapqh1
tcapqh2
}

ASSIGNED{
eCaPQ
mcapqinf
hcapqinf
taucapqm
taucapqh
v
i
}

STATE{
iCaPQ
mcapq 
hcapq
}

INITIAL{
eCaPQ = 65
gcapq = 0.6
mcapq = 0.0120465460803863
hcapq = 0.8127842536675057
vcapqm = -5
scapqm = 10
vcapqh = -33
scapqh = -5
tcapqh1 = 60
tcapqh2 = 51
}

BREAKPOINT{
mcapqinf = 1/(1+exp(-(v-vcapqm)/scapqm))
hcapqinf = 1/(1+exp(-(v-vcapqh)/scapqh))
taucapqm = (1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
taucapqh = (tcapqh1/(exp(-(v+0)/20)+exp((v+0)/20)))+tcapqh2
iCaPQ = gcapq *mcapq *hcapq *(v-eCaPQ)
:i = -iCaPQ
SOLVE states METHOD cnexp
}

DERIVATIVE states{
mcapq' = (mcapqinf - mcapq)/taucapqm
hcapq' = (hcapqinf - hcapq)/taucapqh
}

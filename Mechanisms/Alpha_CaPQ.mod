NEURON{
SUFFIX A_CaPQ
USEION CaPQ WRITE iCaPQ VALENCE 2
USEION Ca READ eCa VALENCE 2
RANGE gcapq, vcapqm, scapqm, vcapqh, scapqh, tcapqh1, tcapqh2, eCa
RANGE iCaPQ, mcapqinf, hcapqinf, taucapqm, taucapqh
}

PARAMETER{
gcapq
vcapqm
scapqm
vcapqh
scapqh
tcapqh1
tcapqh2
eCa
v
}

ASSIGNED{
iCaPQ
mcapqinf
hcapqinf
taucapqm
taucapqh
}

STATE{
mcapq 
hcapq
}

INITIAL{
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
SOLVE states METHOD cnexp
iCaPQ = gcapq *mcapq *hcapq *(v-eca)
}

DERIVATIVE states{
mcapq' = (mcapqinf - mcapq)/taucapqm
hcapq' = (hcapqinf - hcapq)/taucapqh
}

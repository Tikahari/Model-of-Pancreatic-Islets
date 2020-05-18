NEURON{
SUFFIX A_SOC
USEION SOC WRITE iSOC, eSOC VALENCE 2
RANGE iSOC, cer_inf, gSOC
}

PARAMETER{
Cer
cbarer
gbarSOC
eSOC
v
}

ASSIGNED{
iSOC
cer_inf
gSOC
}

STATE{
Cer
}

INITIAL{
gsocbar = 0.025
eSOC = 0
caerbar = 70
ssoca = -20
fer = 0.01
sigmav = 31
}

BREAKPOINT{
cinf = 1/(1+exp(-(cer-caerbar)/ssoc))
SOLVE states METHOD cnexp
iSOC = gsocbar*cinf*(v - eSOC)
}

DERIVATIVE states{
cer' = -fer*sigmav*Jer
}

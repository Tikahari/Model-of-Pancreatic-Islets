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

BREAKPOINT{
cer_inf = 1/(1 + exp(Cer - cbarer)/20)
gSOC = gbarSOC * cer_inf
iSOC = gSOC * cer_inf(v - eSOC)
}


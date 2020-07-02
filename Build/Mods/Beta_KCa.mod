NEURON{
SUFFIX B_KCa
USEION KCa WRITE iKCa VALENCE 1
USEION K READ ek
RANGE 
RANGE 
}

PARAMETER{

}

ASSIGNED{
ek
v
}

STATE{
iKCa
}

INITIAL{
gKCa = 280
kd = 0.5
c = 0.0630015242008439  

}

BREAKPOINT{

SOLVE states METHOD cnexp
iKCa = gkca/(1+(kd/c)^2)*(v-ek)
}

DERIVATIVE states{
c' = fcyt*(Jmem + Jer + delta*Jmito)

}

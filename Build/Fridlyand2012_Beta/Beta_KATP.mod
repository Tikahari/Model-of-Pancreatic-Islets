NEURON{
SUFFIX B_KATP
USEION KATP WRITE iKATP, eKATP VALENCE 1
:USEION K READ eK
:USEION Vm READ Vmi
RANGE gmKATP, ATP, eK, ADPf, kdd, ktt, ktd, eKATP
RANGE iKATP, MgADP, OKATP
}

PARAMETER{
gmKATP   
ATP
eK
ADPf
kdd
ktt
ktd
v
Vmi
eKATP
}

ASSIGNED{
MgADP             
OKATP
iKATP 
v
Vmi
}

INITIAL{
gmKATP = 65000
ATP = 3600
ADPf = 15.0
kdd = 17
ktt = 50
ktd = 26
eK = -75
eKATP = -75
}

BREAKPOINT{             
MgADP =  (0.55 * ADPf)                
OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))                
iKATP =  (gmKATP * OKATP * (v - eKATP))   
}

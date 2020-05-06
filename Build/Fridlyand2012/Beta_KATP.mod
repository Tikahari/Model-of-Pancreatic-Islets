NEURON{
SUFFIX KATP
USEION KATP WRITE iKATP VALENCE 1
RANGE gmKATP, ATP, EK, ADPf, kdd, ktt, ktd
RANGE iKATP, MgADP, OKATP
}

PARAMETER{
gmKATP   
ATP
EK
ADPf
kdd
ktt
ktd
v
}

ASSIGNED{
iKATP 
MgADP             
OKATP 
}

INITIAL{
gmKATP = 65000
ATP = 3600
EK = -75
ADPf = 15.0
kdd = 17
ktt = 50
ktd = 26
}

BREAKPOINT{
iKATP =  (gmKATP * OKATP * (v - EK))                
MgADP =  (0.55 * ADPf)                
OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))                
}

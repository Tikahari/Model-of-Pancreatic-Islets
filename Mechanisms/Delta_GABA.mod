: iGABA declared as nonspecific because that means it will be reckoned in charge balance eqs but not to ionic concentrations. 
: In the bad model vGABA is 0 in every sim, gGABAbar only changes in one sim. 
: So iGABA is mostly a fxn of ins concentration and GABA concentration doesn't affect anything else in the model 
: but iGABA is included in the membrane voltage eqn for delta cell.
NEURON{
SUFFIX D_GABA
NONSPECIFIC_CURRENT iGABA
RANGE knockoutbd, vGABA 
RANGE gGABAbar, EffId, iGABA
POINTER Ins
}

PARAMETER{   
knockoutbd
vGABA
}

ASSIGNED{
gGABAbar
EffId
iGABA
Ins
v : This is the voltage when I run h.initial.....
}

INITIAL{
}

: B cells stim D cells. In both rat and human islets it has been shown that Sst coreleased with
: ins. So there is a GABA curr dependent on I concentration 
BREAKPOINT{
gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
EffId = 0.8/(1+exp(-(Ins-1500)/500)) : Effect of GABA on D cell
iGABA = gGABAbar*EffId*(v - vGABA)
}


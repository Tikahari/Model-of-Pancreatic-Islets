: iGABA declared as nonspecific because that means it will be reckoned in charge balance eqs but not to ionic concentrations. 
: In the bad model vGABA is 0 in every sim, gGABAbar only changes in one sim. 
: So iGABA is mostly a fxn of ins concentration and GABA concentration doesn't affect anything else in the model 
: but iGABA is included in the membrane voltage eqn for delta cell.
NEURON{
SUFFIX D_GABA
NONSPECIFIC CURRENT iGABA
RANGE knockoutbd, vGABA 
RANGE gGABAbar, EffId, iGABA
}

PARAMETER{   
knockoutbd
vGABA 
v : This is the voltage when I run h.initial.....
}

ASSIGNED{
gGABAbar
EffId
iGABA
}

INITIAL{
knockoutbd = 0
vGABA = 0 
}
: B cells stim D cells. In both rat and human islets it has been shown that Sst coreleased with
: ins. So there is a GABA curr dependent on I concentration 
BREAKPOINT{
gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
EffId = 0.8/(1+exp(-(I-1500)/500)) : Effect of GABA on D cell
iGABA = gGABAbar*EffId*(v - vGABA)
}


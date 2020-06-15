NEURON{
POINT_PROCESS A_Conn
RANGE Sst, w
}

PARAMETER{
Sst
w
}

NET_RECEIVE(weight, Som){
Sst = Sst + Som*weight
w = weight
:state_discontinuity(Som, Som + weight)
VERBATIM
printf("net receive called");
ENDVERBATIM
}
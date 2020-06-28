NEURON{
POINT_PROCESS A_Conn
RANGE w
POINTER Sst
}

PARAMETER{
w
Sst
}

INITIAL{
Sst = 4 
}

NET_RECEIVE(weight){
Sst = Sst + weight
:w = weight
:state_discontinuity(Som, Som + weight)
VERBATIM
//printf("net receive called\n");
ENDVERBATIM
}
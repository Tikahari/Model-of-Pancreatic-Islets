NEURON{
POINT_PROCESS A_Syn
POINTER Sst_receive
POINTER Sst_send
POINTER Ins_receive
POINTER Ins_send
}

PARAMETER{
Sst_receive
Sst_send
Ins_receive
Ins_send
}

INITIAL{
Sst_receive = 0
Ins_receive = 0
}

NET_RECEIVE(weight){
Sst_receive = Sst_receive + Sst_send*weight
Ins_receive = Ins_receive + Ins_send*weight
VERBATIM
//printf("alpha net receive called\n");
ENDVERBATIM
}
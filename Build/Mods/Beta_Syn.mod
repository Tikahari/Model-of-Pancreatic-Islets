NEURON{
POINT_PROCESS B_Syn
POINTER Sst_receive
POINTER Sst_send
POINTER Gluc_receive
POINTER Gluc_send
}

PARAMETER{
Sst_receive
Sst_send
Gluc_receive
Gluc_send
}

INITIAL{
Sst_receive = 0
Gluc_receive = 0
}

NET_RECEIVE(weight){
Sst_receive = Sst_receive + Sst_send*weight
Gluc_receive = Gluc_receive + Gluc_send*weight
VERBATIM
//printf("net receive called\n");
ENDVERBATIM
}
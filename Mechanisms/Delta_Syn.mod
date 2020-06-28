NEURON{
POINT_PROCESS D_Syn
POINTER Ins_send
POINTER Ins_receive
POINTER Gluc_send
POINTER Gluc_receive
}

PARAMETER{
Ins_send
Ins_receive
Gluc_send
Gluc_receive
}

INITIAL{
Ins_receive = 0
Gluc_receive = 0
}

NET_RECEIVE(weight){
Ins_receive = Ins_receive + Ins_send*weight
Gluc_receive = Gluc_receive + Gluc_send*weight
VERBATIM
//printf("delta net receive called\n");
ENDVERBATIM
}
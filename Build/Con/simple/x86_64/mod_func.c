#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _conn_reg(void);
extern void _testRec_reg(void);
extern void _testSend_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," conn.mod");
    fprintf(stderr," testRec.mod");
    fprintf(stderr," testSend.mod");
    fprintf(stderr, "\n");
  }
  _conn_reg();
  _testRec_reg();
  _testSend_reg();
}

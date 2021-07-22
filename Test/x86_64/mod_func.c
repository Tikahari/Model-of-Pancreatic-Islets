#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _dm1_reg(void);
extern void _dm2_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," dm1.mod");
    fprintf(stderr," dm2.mod");
    fprintf(stderr, "\n");
  }
  _dm1_reg();
  _dm2_reg();
}

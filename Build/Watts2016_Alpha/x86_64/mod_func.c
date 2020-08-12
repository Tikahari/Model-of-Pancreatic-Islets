#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _watts_alpha_reg(void);
extern void _watts_alpha_v_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," watts_alpha.mod");
    fprintf(stderr," watts_alpha_v.mod");
    fprintf(stderr, "\n");
  }
  _watts_alpha_reg();
  _watts_alpha_v_reg();
}

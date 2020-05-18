#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _Delta_CaL_reg(void);
extern void _Delta_CaPQ_reg(void);
extern void _Delta_Ka_reg(void);
extern void _Delta_KATP_reg(void);
extern void _Delta_Kdr_reg(void);
extern void _Delta_L_reg(void);
extern void _Delta_Na_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Delta_CaL.mod");
    fprintf(stderr," Delta_CaPQ.mod");
    fprintf(stderr," Delta_Ka.mod");
    fprintf(stderr," Delta_KATP.mod");
    fprintf(stderr," Delta_Kdr.mod");
    fprintf(stderr," Delta_L.mod");
    fprintf(stderr," Delta_Na.mod");
    fprintf(stderr, "\n");
  }
  _Delta_CaL_reg();
  _Delta_CaPQ_reg();
  _Delta_Ka_reg();
  _Delta_KATP_reg();
  _Delta_Kdr_reg();
  _Delta_L_reg();
  _Delta_Na_reg();
}

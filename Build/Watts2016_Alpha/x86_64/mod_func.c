#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _Alpha_CaL_reg(void);
extern void _Alpha_CaPQ_reg(void);
extern void _Alpha_CaT_reg(void);
extern void _Alpha_GIRK_reg(void);
extern void _Alpha_Glucagon_reg(void);
extern void _Alpha_Ka_reg(void);
extern void _Alpha_KATP_reg(void);
extern void _Alpha_KDR_reg(void);
extern void _Alpha_L_reg(void);
extern void _Alpha_Na_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Alpha_CaL.mod");
    fprintf(stderr," Alpha_CaPQ.mod");
    fprintf(stderr," Alpha_CaT.mod");
    fprintf(stderr," Alpha_GIRK.mod");
    fprintf(stderr," Alpha_Glucagon.mod");
    fprintf(stderr," Alpha_Ka.mod");
    fprintf(stderr," Alpha_KATP.mod");
    fprintf(stderr," Alpha_KDR.mod");
    fprintf(stderr," Alpha_L.mod");
    fprintf(stderr," Alpha_Na.mod");
    fprintf(stderr, "\n");
  }
  _Alpha_CaL_reg();
  _Alpha_CaPQ_reg();
  _Alpha_CaT_reg();
  _Alpha_GIRK_reg();
  _Alpha_Glucagon_reg();
  _Alpha_Ka_reg();
  _Alpha_KATP_reg();
  _Alpha_KDR_reg();
  _Alpha_L_reg();
  _Alpha_Na_reg();
}

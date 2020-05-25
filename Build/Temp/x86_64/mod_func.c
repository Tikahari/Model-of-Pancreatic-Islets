#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _Beta_BK_reg(void);
extern void _Beta_Cac_reg(void);
extern void _Beta_CaL_reg(void);
extern void _Beta_CaP_reg(void);
extern void _Beta_CaT_reg(void);
extern void _Beta_HERG_reg(void);
extern void _Beta_Ins_reg(void);
extern void _Beta_KATP_reg(void);
extern void _Beta_KCa_reg(void);
extern void _Beta_KDR_reg(void);
extern void _Beta_NaB_reg(void);
extern void _Beta_Na_reg(void);
extern void _Beta_PCa_reg(void);
extern void _frid_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Beta_BK.mod");
    fprintf(stderr," Beta_Cac.mod");
    fprintf(stderr," Beta_CaL.mod");
    fprintf(stderr," Beta_CaP.mod");
    fprintf(stderr," Beta_CaT.mod");
    fprintf(stderr," Beta_HERG.mod");
    fprintf(stderr," Beta_Ins.mod");
    fprintf(stderr," Beta_KATP.mod");
    fprintf(stderr," Beta_KCa.mod");
    fprintf(stderr," Beta_KDR.mod");
    fprintf(stderr," Beta_NaB.mod");
    fprintf(stderr," Beta_Na.mod");
    fprintf(stderr," Beta_PCa.mod");
    fprintf(stderr," frid.mod");
    fprintf(stderr, "\n");
  }
  _Beta_BK_reg();
  _Beta_Cac_reg();
  _Beta_CaL_reg();
  _Beta_CaP_reg();
  _Beta_CaT_reg();
  _Beta_HERG_reg();
  _Beta_Ins_reg();
  _Beta_KATP_reg();
  _Beta_KCa_reg();
  _Beta_KDR_reg();
  _Beta_NaB_reg();
  _Beta_Na_reg();
  _Beta_PCa_reg();
  _frid_reg();
}

#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _Alpha_Conn_reg(void);
extern void _Alpha_GIRK_reg(void);
extern void _Delta_CaL_reg(void);
extern void _Delta_CaPQ_reg(void);
extern void _Delta_Somatostatin_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," Alpha_Conn.mod");
    fprintf(stderr," Alpha_GIRK.mod");
    fprintf(stderr," Delta_CaL.mod");
    fprintf(stderr," Delta_CaPQ.mod");
    fprintf(stderr," Delta_Somatostatin.mod");
    fprintf(stderr, "\n");
  }
  _Alpha_Conn_reg();
  _Alpha_GIRK_reg();
  _Delta_CaL_reg();
  _Delta_CaPQ_reg();
  _Delta_Somatostatin_reg();
}

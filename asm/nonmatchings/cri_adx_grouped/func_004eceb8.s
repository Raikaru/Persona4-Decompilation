.section .text
.set noat
.set noreorder
glabel func_004eceb8
    /* 3ECEB8 004ECEB8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECEBC 004ECEBC 01000624 */  addiu      $6, $0, 0x1
    /* 3ECEC0 004ECEC0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECEC4 004ECEC4 05006654 */  bnel       $3, $6, .L004ECEDC
    /* 3ECEC8 004ECEC8 520085A0 */   sb        $5, 0x52($4)
    /* 3ECECC 004ECECC 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECED0 004ECED0 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECED4 004ECED4 0100605C */  bgtzl      $3, .L004ECEDC
    /* 3ECED8 004ECED8 520085A0 */   sb        $5, 0x52($4)
  .L004ECEDC:
    /* 3ECEDC 004ECEDC 0800E003 */  jr         $31
    /* 3ECEE0 004ECEE0 00000000 */   nop
    /* 3ECEE4 004ECEE4 00000000 */  nop
.size func_004eceb8, 0x30

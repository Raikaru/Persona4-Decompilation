.section .text
.set noat
.set noreorder
glabel func_0014db80
    /* 4DB80 0014DB80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4DB84 0014DB84 0000BFFF */  sd         $31, 0x0($29)
    /* 4DB88 0014DB88 3800848C */  lw         $4, 0x38($4)
    /* 4DB8C 0014DB8C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 4DB90 0014DB90 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 4DB94 0014DB94 09F84000 */  jalr       $2
    /* 4DB98 0014DB98 00000000 */   nop
    /* 4DB9C 0014DB9C 0000BFDF */  ld         $31, 0x0($29)
    /* 4DBA0 0014DBA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 4DBA4 0014DBA4 0800E003 */  jr         $31
    /* 4DBA8 0014DBA8 00000000 */   nop
    /* 4DBAC 0014DBAC 00000000 */  nop
.size func_0014db80, 0x30

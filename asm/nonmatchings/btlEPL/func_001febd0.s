.section .text
.set noat
.set noreorder
glabel func_001febd0
    /* FEBD0 001FEBD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FEBD4 001FEBD4 0000BFFF */  sd         $31, 0x0($29)
    /* FEBD8 001FEBD8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* FEBDC 001FEBDC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* FEBE0 001FEBE0 09F84000 */  jalr       $2
    /* FEBE4 001FEBE4 00000000 */   nop
    /* FEBE8 001FEBE8 0000BFDF */  ld         $31, 0x0($29)
    /* FEBEC 001FEBEC 1000BD27 */  addiu      $29, $29, 0x10
    /* FEBF0 001FEBF0 0800E003 */  jr         $31
    /* FEBF4 001FEBF4 00000000 */   nop
    /* FEBF8 001FEBF8 00000000 */  nop
    /* FEBFC 001FEBFC 00000000 */  nop
.size func_001febd0, 0x30

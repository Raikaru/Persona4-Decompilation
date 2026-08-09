.section .text
.set noat
.set noreorder
glabel func_0018f390
    /* 8F390 0018F390 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 8F394 0018F394 0000BFFF */  sd         $31, 0x0($29)
    /* 8F398 0018F398 3800848C */  lw         $4, 0x38($4)
    /* 8F39C 0018F39C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 8F3A0 0018F3A0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 8F3A4 0018F3A4 09F84000 */  jalr       $2
    /* 8F3A8 0018F3A8 00000000 */   nop
    /* 8F3AC 0018F3AC 0000BFDF */  ld         $31, 0x0($29)
    /* 8F3B0 0018F3B0 1000BD27 */  addiu      $29, $29, 0x10
    /* 8F3B4 0018F3B4 0800E003 */  jr         $31
    /* 8F3B8 0018F3B8 00000000 */   nop
    /* 8F3BC 0018F3BC 00000000 */  nop
.size func_0018f390, 0x30

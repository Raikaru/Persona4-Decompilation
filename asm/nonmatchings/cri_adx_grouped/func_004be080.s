.section .text
.set noat
.set noreorder
glabel func_004be080
    /* 3BE080 004BE080 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE084 004BE084 0600A014 */  bnez       $5, .L004BE0A0
    /* 3BE088 004BE088 0000BFFF */   sd        $31, 0x0($29)
    /* 3BE08C 004BE08C 0400848C */  lw         $4, 0x4($4)
    /* 3BE090 004BE090 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE094 004BE094 70541308 */  j          func_004d51c0
    /* 3BE098 004BE098 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE09C 004BE09C 00000000 */  nop
  .L004BE0A0:
    /* 3BE0A0 004BE0A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE0A4 004BE0A4 2D100000 */  daddu      $2, $0, $0
    /* 3BE0A8 004BE0A8 0800E003 */  jr         $31
    /* 3BE0AC 004BE0AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be080, 0x30

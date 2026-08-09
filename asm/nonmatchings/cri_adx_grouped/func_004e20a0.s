.section .text
.set noat
.set noreorder
glabel func_004e20a0
    /* 3E20A0 004E20A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E20A4 004E20A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E20A8 004E20A8 07008014 */  bnez       $4, .L004E20C8
    /* 3E20AC 004E20AC 0800BFFF */   sd        $31, 0x8($29)
    /* 3E20B0 004E20B0 7600043C */  lui        $4, %hi(D_00759F90)
    /* 3E20B4 004E20B4 6A85130C */  jal        func_004e15a8
    /* 3E20B8 004E20B8 909F8424 */   addiu     $4, $4, %lo(D_00759F90)
    /* 3E20BC 004E20BC 0E000010 */  b          .L004E20F8
    /* 3E20C0 004E20C0 2D100000 */   daddu     $2, $0, $0
    /* 3E20C4 004E20C4 00000000 */  nop
  .L004E20C8:
    /* 3E20C8 004E20C8 0000828C */  lw         $2, 0x0($4)
    /* 3E20CC 004E20CC 1C00428C */  lw         $2, 0x1C($2)
    /* 3E20D0 004E20D0 05004050 */  beql       $2, $0, .L004E20E8
    /* 3E20D4 004E20D4 7600043C */   lui       $4, %hi(D_00759FB0)
    /* 3E20D8 004E20D8 09F84000 */  jalr       $2
    /* 3E20DC 004E20DC 0400848C */   lw        $4, 0x4($4)
    /* 3E20E0 004E20E0 04000010 */  b          .L004E20F4
    /* 3E20E4 004E20E4 2D804000 */   daddu     $16, $2, $0
  .L004E20E8:
    /* 3E20E8 004E20E8 2D800000 */  daddu      $16, $0, $0
    /* 3E20EC 004E20EC 6A85130C */  jal        func_004e15a8
    /* 3E20F0 004E20F0 B09F8424 */   addiu     $4, $4, %lo(D_00759FB0)
  .L004E20F4:
    /* 3E20F4 004E20F4 2D100002 */  daddu      $2, $16, $0
  .L004E20F8:
    /* 3E20F8 004E20F8 0000B0DF */  ld         $16, 0x0($29)
    /* 3E20FC 004E20FC 0800BFDF */  ld         $31, 0x8($29)
    /* 3E2100 004E2100 0800E003 */  jr         $31
    /* 3E2104 004E2104 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e20a0, 0x68

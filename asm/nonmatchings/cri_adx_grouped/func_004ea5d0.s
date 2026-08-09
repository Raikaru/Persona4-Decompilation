.section .text
.set noat
.set noreorder
glabel func_004ea5d0
    /* 3EA5D0 004EA5D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA5D4 004EA5D4 2D108000 */  daddu      $2, $4, $0
    /* 3EA5D8 004EA5D8 07004014 */  bnez       $2, .L004EA5F8
    /* 3EA5DC 004EA5DC 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA5E0 004EA5E0 7600053C */  lui        $5, %hi(D_0075BFA8)
    /* 3EA5E4 004EA5E4 9AA7130C */  jal        func_004e9e68
    /* 3EA5E8 004EA5E8 A8BFA524 */   addiu     $5, $5, %lo(D_0075BFA8)
    /* 3EA5EC 004EA5EC 03000010 */  b          .L004EA5FC
    /* 3EA5F0 004EA5F0 2D100000 */   daddu     $2, $0, $0
    /* 3EA5F4 004EA5F4 00000000 */  nop
  .L004EA5F8:
    /* 3EA5F8 004EA5F8 1400428C */  lw         $2, 0x14($2)
  .L004EA5FC:
    /* 3EA5FC 004EA5FC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA600 004EA600 0800E003 */  jr         $31
    /* 3EA604 004EA604 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ea5d0, 0x38

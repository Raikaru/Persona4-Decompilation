.section .text
.set noat
.set noreorder
glabel func_004ea4e0
    /* 3EA4E0 004EA4E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA4E4 004EA4E4 2D108000 */  daddu      $2, $4, $0
    /* 3EA4E8 004EA4E8 07004014 */  bnez       $2, .L004EA508
    /* 3EA4EC 004EA4EC 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA4F0 004EA4F0 7600053C */  lui        $5, %hi(D_0075BFA8)
    /* 3EA4F4 004EA4F4 9AA7130C */  jal        func_004e9e68
    /* 3EA4F8 004EA4F8 A8BFA524 */   addiu     $5, $5, %lo(D_0075BFA8)
    /* 3EA4FC 004EA4FC 03000010 */  b          .L004EA50C
    /* 3EA500 004EA500 2D100000 */   daddu     $2, $0, $0
    /* 3EA504 004EA504 00000000 */  nop
  .L004EA508:
    /* 3EA508 004EA508 01004280 */  lb         $2, 0x1($2)
  .L004EA50C:
    /* 3EA50C 004EA50C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA510 004EA510 0800E003 */  jr         $31
    /* 3EA514 004EA514 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ea4e0, 0x38

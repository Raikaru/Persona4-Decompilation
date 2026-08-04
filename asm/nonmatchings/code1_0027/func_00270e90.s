.section .text
.set noat
.set noreorder
glabel func_00270e90
    /* 170E90 00270E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 170E94 00270E94 0000BFFF */  sd         $31, 0x0($29)
    /* 170E98 00270E98 A8D1090C */  jal        func_002746a0
    /* 170E9C 00270E9C 00000000 */   nop
    /* 170EA0 00270EA0 04004010 */  beqz       $2, .L00270EB4
    /* 170EA4 00270EA4 00000000 */   nop
    /* 170EA8 00270EA8 2D100000 */  daddu      $2, $0, $0
    /* 170EAC 00270EAC 0A000010 */  b          .L00270ED8
    /* 170EB0 00270EB0 00000000 */   nop
  .L00270EB4:
    /* 170EB4 00270EB4 8423040C */  jal        func_00108e10
    /* 170EB8 00270EB8 00000000 */   nop
    /* 170EBC 00270EBC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 170EC0 00270EC0 04004010 */  beqz       $2, .L00270ED4
    /* 170EC4 00270EC4 00000000 */   nop
    /* 170EC8 00270EC8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 170ECC 00270ECC 701F040C */  jal        func_00107dc0
    /* 170ED0 00270ED0 00000000 */   nop
  .L00270ED4:
    /* 170ED4 00270ED4 2D100000 */  daddu      $2, $0, $0
  .L00270ED8:
    /* 170ED8 00270ED8 0000BFDF */  ld         $31, 0x0($29)
    /* 170EDC 00270EDC 1000BD27 */  addiu      $29, $29, 0x10
    /* 170EE0 00270EE0 0800E003 */  jr         $31
    /* 170EE4 00270EE4 00000000 */   nop
    /* 170EE8 00270EE8 00000000 */  nop
    /* 170EEC 00270EEC 00000000 */  nop
.size func_00270e90, 0x60

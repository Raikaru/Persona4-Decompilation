.section .text
.set noat
.set noreorder
glabel func_0044f4d0
    /* 34F4D0 0044F4D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34F4D4 0044F4D4 0000BFFF */  sd         $31, 0x0($29)
    /* 34F4D8 0044F4D8 B849110C */  jal        func_004526e0
    /* 34F4DC 0044F4DC 00000000 */   nop
    /* 34F4E0 0044F4E0 03004010 */  beqz       $2, .L0044F4F0
    /* 34F4E4 0044F4E4 00000000 */   nop
    /* 34F4E8 0044F4E8 02000010 */  b          .L0044F4F4
    /* 34F4EC 0044F4EC 00000000 */   nop
  .L0044F4F0:
    /* 34F4F0 0044F4F0 2D100000 */  daddu      $2, $0, $0
  .L0044F4F4:
    /* 34F4F4 0044F4F4 0000BFDF */  ld         $31, 0x0($29)
    /* 34F4F8 0044F4F8 1000BD27 */  addiu      $29, $29, 0x10
    /* 34F4FC 0044F4FC 0800E003 */  jr         $31
    /* 34F500 0044F500 00000000 */   nop
    /* 34F504 0044F504 00000000 */  nop
    /* 34F508 0044F508 00000000 */  nop
    /* 34F50C 0044F50C 00000000 */  nop
.size func_0044f4d0, 0x40

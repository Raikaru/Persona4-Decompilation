.section .text
.set noat
.set noreorder
glabel func_001b5f30
    /* B5F30 001B5F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5F34 001B5F34 0000BFFF */  sd         $31, 0x0($29)
    /* B5F38 001B5F38 FCA80A0C */  jal        func_002aa3f0
    /* B5F3C 001B5F3C 00000000 */   nop
    /* B5F40 001B5F40 06004010 */  beqz       $2, .L001B5F5C
    /* B5F44 001B5F44 00000000 */   nop
    /* B5F48 001B5F48 C84A060C */  jal        func_00192b20
    /* B5F4C 001B5F4C 00000000 */   nop
    /* B5F50 001B5F50 12000224 */  addiu      $2, $0, 0x12
    /* B5F54 001B5F54 02000010 */  b          .L001B5F60
    /* B5F58 001B5F58 00000000 */   nop
  .L001B5F5C:
    /* B5F5C 001B5F5C 2D100000 */  daddu      $2, $0, $0
  .L001B5F60:
    /* B5F60 001B5F60 0000BFDF */  ld         $31, 0x0($29)
    /* B5F64 001B5F64 1000BD27 */  addiu      $29, $29, 0x10
    /* B5F68 001B5F68 0800E003 */  jr         $31
    /* B5F6C 001B5F6C 00000000 */   nop
.size func_001b5f30, 0x40

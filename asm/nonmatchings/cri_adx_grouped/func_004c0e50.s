.section .text
.set noat
.set noreorder
glabel func_004c0e50
    /* 3C0E50 004C0E50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0E54 004C0E54 2D100000 */  daddu      $2, $0, $0
    /* 3C0E58 004C0E58 04008010 */  beqz       $4, .L004C0E6C
    /* 3C0E5C 004C0E5C 0000BFFF */   sd        $31, 0x0($29)
    /* 3C0E60 004C0E60 3803130C */  jal        func_004c0ce0
    /* 3C0E64 004C0E64 00000000 */   nop
    /* 3C0E68 004C0E68 01000224 */  addiu      $2, $0, 0x1
  .L004C0E6C:
    /* 3C0E6C 004C0E6C 0000BFDF */  ld         $31, 0x0($29)
    /* 3C0E70 004C0E70 0800E003 */  jr         $31
    /* 3C0E74 004C0E74 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c0e50, 0x28

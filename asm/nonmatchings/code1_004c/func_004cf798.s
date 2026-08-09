.section .text
.set noat
.set noreorder
glabel func_004cf798
    /* 3CF798 004CF798 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF79C 004CF79C 2D108000 */  daddu      $2, $4, $0
    /* 3CF7A0 004CF7A0 07004010 */  beqz       $2, .L004CF7C0
    /* 3CF7A4 004CF7A4 0000BFFF */   sd        $31, 0x0($29)
    /* 3CF7A8 004CF7A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF7AC 004CF7AC 2D280000 */  daddu      $5, $0, $0
    /* 3CF7B0 004CF7B0 0C000624 */  addiu      $6, $0, 0xC
    /* 3CF7B4 004CF7B4 000040A0 */  sb         $0, 0x0($2)
    /* 3CF7B8 004CF7B8 72FE1008 */  j          func_0043f9c8
    /* 3CF7BC 004CF7BC 1000BD27 */   addiu     $29, $29, 0x10
  .L004CF7C0:
    /* 3CF7C0 004CF7C0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF7C4 004CF7C4 0800E003 */  jr         $31
    /* 3CF7C8 004CF7C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CF7CC 004CF7CC 00000000 */  nop
.size func_004cf798, 0x38

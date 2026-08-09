.section .text
.set noat
.set noreorder
glabel func_004eeb50
    /* 3EEB50 004EEB50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEB54 004EEB54 7400023C */  lui        $2, %hi(D_00742020)
    /* 3EEB58 004EEB58 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEB5C 004EEB5C 20205024 */  addiu      $16, $2, %lo(D_00742020)
    /* 3EEB60 004EEB60 0000028E */  lw         $2, 0x0($16)
    /* 3EEB64 004EEB64 07004014 */  bnez       $2, .L004EEB84
    /* 3EEB68 004EEB68 0800BFFF */   sd        $31, 0x8($29)
    /* 3EEB6C 004EEB6C 7400043C */  lui        $4, %hi(D_00742028)
    /* 3EEB70 004EEB70 2D280000 */  daddu      $5, $0, $0
    /* 3EEB74 004EEB74 28208424 */  addiu      $4, $4, %lo(D_00742028)
    /* 3EEB78 004EEB78 72FE100C */  jal        func_0043f9c8
    /* 3EEB7C 004EEB7C 000C0624 */   addiu     $6, $0, 0xC00
    /* 3EEB80 004EEB80 0000028E */  lw         $2, 0x0($16)
  .L004EEB84:
    /* 3EEB84 004EEB84 01004224 */  addiu      $2, $2, 0x1
    /* 3EEB88 004EEB88 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEB8C 004EEB8C 000002AE */  sw         $2, 0x0($16)
    /* 3EEB90 004EEB90 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEB94 004EEB94 0800E003 */  jr         $31
    /* 3EEB98 004EEB98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEB9C 004EEB9C 00000000 */  nop
.size func_004eeb50, 0x50

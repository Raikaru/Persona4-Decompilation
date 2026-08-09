.section .text
.set noat
.set noreorder
glabel func_004f85c0
    /* 3F85C0 004F85C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F85C4 004F85C4 01000224 */  addiu      $2, $0, 0x1
    /* 3F85C8 004F85C8 0900C210 */  beq        $6, $2, .L004F85F0
    /* 3F85CC 004F85CC 0000BFFF */   sd        $31, 0x0($29)
    /* 3F85D0 004F85D0 0700C010 */  beqz       $6, .L004F85F0
    /* 3F85D4 004F85D4 2D100000 */   daddu     $2, $0, $0
    /* 3F85D8 004F85D8 02000224 */  addiu      $2, $0, 0x2
    /* 3F85DC 004F85DC 0400C210 */  beq        $6, $2, .L004F85F0
    /* 3F85E0 004F85E0 0000BFDF */   ld        $31, 0x0($29)
    /* 3F85E4 004F85E4 33FF0224 */  addiu      $2, $0, -0xCD
    /* 3F85E8 004F85E8 0800E003 */  jr         $31
    /* 3F85EC 004F85EC 1000BD27 */   addiu     $29, $29, 0x10
  .L004F85F0:
    /* 3F85F0 004F85F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F85F4 004F85F4 2D304000 */  daddu      $6, $2, $0
    /* 3F85F8 004F85F8 28C61308 */  j          func_004f18a0
    /* 3F85FC 004F85FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f85c0, 0x40

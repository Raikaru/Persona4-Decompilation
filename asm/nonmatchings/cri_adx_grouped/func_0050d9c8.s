.section .text
.set noat
.set noreorder
glabel func_0050d9c8
    /* 40D9C8 0050D9C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D9CC 0050D9CC 2D30A000 */  daddu      $6, $5, $0
    /* 40D9D0 0050D9D0 0000BFFF */  sd         $31, 0x0($29)
    /* 40D9D4 0050D9D4 2D100000 */  daddu      $2, $0, $0
    /* 40D9D8 0050D9D8 02008010 */  beqz       $4, .L0050D9E4
    /* 40D9DC 0050D9DC 05000524 */   addiu     $5, $0, 0x5
    /* 40D9E0 0050D9E0 3C00828C */  lw         $2, 0x3C($4)
  .L0050D9E4:
    /* 40D9E4 0050D9E4 0000BFDF */  ld         $31, 0x0($29)
    /* 40D9E8 0050D9E8 2D204000 */  daddu      $4, $2, $0
    /* 40D9EC 0050D9EC 70681408 */  j          func_0051a1c0
    /* 40D9F0 0050D9F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40D9F4 0050D9F4 00000000 */  nop
.size func_0050d9c8, 0x30

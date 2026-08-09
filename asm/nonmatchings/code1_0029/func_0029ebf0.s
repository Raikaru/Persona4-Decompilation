.section .text
.set noat
.set noreorder
glabel func_0029ebf0
    /* 19EBF0 0029EBF0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 19EBF4 0029EBF4 4000BFFF */  sd         $31, 0x40($29)
    /* 19EBF8 0029EBF8 3000B37F */  sq         $19, 0x30($29)
    /* 19EBFC 0029EBFC 2000B27F */  sq         $18, 0x20($29)
    /* 19EC00 0029EC00 1000B17F */  sq         $17, 0x10($29)
    /* 19EC04 0029EC04 0000B07F */  sq         $16, 0x0($29)
    /* 19EC08 0029EC08 3800908C */  lw         $16, 0x38($4)
    /* 19EC0C 0029EC0C 0600A014 */  bnez       $5, .L0029EC28
    /* 19EC10 0029EC10 00000000 */   nop
    /* 19EC14 0029EC14 ED001324 */  addiu      $19, $0, 0xED
    /* 19EC18 0029EC18 4C001124 */  addiu      $17, $0, 0x4C
    /* 19EC1C 0029EC1C 2D902002 */  daddu      $18, $17, $0
    /* 19EC20 0029EC20 0C000010 */  b          .L0029EC54
    /* 19EC24 0029EC24 00000000 */   nop
  .L0029EC28:
    /* 19EC28 0029EC28 01000224 */  addiu      $2, $0, 0x1
    /* 19EC2C 0029EC2C 0600A214 */  bne        $5, $2, .L0029EC48
    /* 19EC30 0029EC30 00000000 */   nop
    /* 19EC34 0029EC34 ED001324 */  addiu      $19, $0, 0xED
    /* 19EC38 0029EC38 4C001224 */  addiu      $18, $0, 0x4C
    /* 19EC3C 0029EC3C 49001124 */  addiu      $17, $0, 0x49
    /* 19EC40 0029EC40 04000010 */  b          .L0029EC54
    /* 19EC44 0029EC44 00000000 */   nop
  .L0029EC48:
    /* 19EC48 0029EC48 ED001324 */  addiu      $19, $0, 0xED
    /* 19EC4C 0029EC4C 4C001124 */  addiu      $17, $0, 0x4C
    /* 19EC50 0029EC50 49001224 */  addiu      $18, $0, 0x49
  .L0029EC54:
    /* 19EC54 0029EC54 A8020426 */  addiu      $4, $16, 0x2A8
    /* 19EC58 0029EC58 E0890A0C */  jal        func_002a2780
    /* 19EC5C 0029EC5C 00000000 */   nop
    /* 19EC60 0029EC60 A8020426 */  addiu      $4, $16, 0x2A8
    /* 19EC64 0029EC64 2D286002 */  daddu      $5, $19, $0
    /* 19EC68 0029EC68 2D304002 */  daddu      $6, $18, $0
    /* 19EC6C 0029EC6C 2D386002 */  daddu      $7, $19, $0
    /* 19EC70 0029EC70 2D402002 */  daddu      $8, $17, $0
    /* 19EC74 0029EC74 04828CC7 */  lwc1       $f12, -0x7DFC($28)
    /* 19EC78 0029EC78 2D480000 */  daddu      $9, $0, $0
    /* 19EC7C 0029EC7C 2D500000 */  daddu      $10, $0, $0
    /* 19EC80 0029EC80 0A000B24 */  addiu      $11, $0, 0xA
    /* 19EC84 0029EC84 F0890A0C */  jal        func_002a27c0
    /* 19EC88 0029EC88 00000000 */   nop
    /* 19EC8C 0029EC8C 4000BFDF */  ld         $31, 0x40($29)
    /* 19EC90 0029EC90 3000B37B */  lq         $19, 0x30($29)
    /* 19EC94 0029EC94 2000B27B */  lq         $18, 0x20($29)
    /* 19EC98 0029EC98 1000B17B */  lq         $17, 0x10($29)
    /* 19EC9C 0029EC9C 0000B07B */  lq         $16, 0x0($29)
    /* 19ECA0 0029ECA0 5000BD27 */  addiu      $29, $29, 0x50
    /* 19ECA4 0029ECA4 0800E003 */  jr         $31
    /* 19ECA8 0029ECA8 00000000 */   nop
    /* 19ECAC 0029ECAC 00000000 */  nop
.size func_0029ebf0, 0xc0

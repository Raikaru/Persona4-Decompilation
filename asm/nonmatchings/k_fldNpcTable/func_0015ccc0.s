.section .text
.set noat
.set noreorder
glabel func_0015ccc0
    /* 5CCC0 0015CCC0 F0FEBD27 */  addiu      $29, $29, -0x110
    /* 5CCC4 0015CCC4 0000BFFF */  sd         $31, 0x0($29)
    /* 5CCC8 0015CCC8 B03B050C */  jal        func_0014eec0
    /* 5CCCC 0015CCCC 00000000 */   nop
    /* 5CCD0 0015CCD0 22004014 */  bnez       $2, .L0015CD5C
    /* 5CCD4 0015CCD4 00000000 */   nop
    /* 5CCD8 0015CCD8 9000A427 */  addiu      $4, $29, 0x90
    /* 5CCDC 0015CCDC 5F00053C */  lui        $5, %hi(D_005F0790)
    /* 5CCE0 0015CCE0 9007A524 */  addiu      $5, $5, %lo(D_005F0790)
    /* 5CCE4 0015CCE4 0C0A110C */  jal        func_00442830
    /* 5CCE8 0015CCE8 00000000 */   nop
    /* 5CCEC 0015CCEC B09D828F */  lw         $2, -0x6250($28)
    /* 5CCF0 0015CCF0 1000A427 */  addiu      $4, $29, 0x10
    /* 5CCF4 0015CCF4 5F00053C */  lui        $5, %hi(D_005F07F0)
    /* 5CCF8 0015CCF8 F007A524 */  addiu      $5, $5, %lo(D_005F07F0)
    /* 5CCFC 0015CCFC 0000468C */  lw         $6, 0x0($2)
    /* 5CD00 0015CD00 0400478C */  lw         $7, 0x4($2)
    /* 5CD04 0015CD04 2208110C */  jal        func_00442088
    /* 5CD08 0015CD08 00000000 */   nop
    /* 5CD0C 0015CD0C 1000A427 */  addiu      $4, $29, 0x10
    /* 5CD10 0015CD10 5C51110C */  jal        func_00454570
    /* 5CD14 0015CD14 00000000 */   nop
    /* 5CD18 0015CD18 04004014 */  bnez       $2, .L0015CD2C
    /* 5CD1C 0015CD1C 00000000 */   nop
    /* 5CD20 0015CD20 2D100000 */  daddu      $2, $0, $0
    /* 5CD24 0015CD24 0E000010 */  b          .L0015CD60
    /* 5CD28 0015CD28 00000000 */   nop
  .L0015CD2C:
    /* 5CD2C 0015CD2C 309E8427 */  addiu      $4, $28, -0x61D0
    /* 5CD30 0015CD30 5F00053C */  lui        $5, %hi(D_005F07C0)
    /* 5CD34 0015CD34 C007A524 */  addiu      $5, $5, %lo(D_005F07C0)
    /* 5CD38 0015CD38 40010624 */  addiu      $6, $0, 0x140
    /* 5CD3C 0015CD3C DA02110C */  jal        func_00440b68
    /* 5CD40 0015CD40 00000000 */   nop
    /* 5CD44 0015CD44 1000A427 */  addiu      $4, $29, 0x10
    /* 5CD48 0015CD48 2D280000 */  daddu      $5, $0, $0
    /* 5CD4C 0015CD4C 9852110C */  jal        func_00454a60
    /* 5CD50 0015CD50 00000000 */   nop
    /* 5CD54 0015CD54 02000010 */  b          .L0015CD60
    /* 5CD58 0015CD58 00000000 */   nop
  .L0015CD5C:
    /* 5CD5C 0015CD5C 01000224 */  addiu      $2, $0, 0x1
  .L0015CD60:
    /* 5CD60 0015CD60 0000BFDF */  ld         $31, 0x0($29)
    /* 5CD64 0015CD64 1001BD27 */  addiu      $29, $29, 0x110
    /* 5CD68 0015CD68 0800E003 */  jr         $31
    /* 5CD6C 0015CD6C 00000000 */   nop
.size func_0015ccc0, 0xb0

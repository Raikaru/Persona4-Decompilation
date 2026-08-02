.section .text
.set noat
.set noreorder
glabel func_0015cf70
    /* 5CF70 0015CF70 F0FEBD27 */  addiu      $29, $29, -0x110
    /* 5CF74 0015CF74 0000BFFF */  sd         $31, 0x0($29)
    /* 5CF78 0015CF78 9000A427 */  addiu      $4, $29, 0x90
    /* 5CF7C 0015CF7C 5F00053C */  lui        $5, %hi(D_005F0790)
    /* 5CF80 0015CF80 9007A524 */  addiu      $5, $5, %lo(D_005F0790)
    /* 5CF84 0015CF84 0C0A110C */  jal        func_00442830
    /* 5CF88 0015CF88 00000000 */   nop
    /* 5CF8C 0015CF8C 1000A427 */  addiu      $4, $29, 0x10
    /* 5CF90 0015CF90 5F00053C */  lui        $5, %hi(D_005F0830)
    /* 5CF94 0015CF94 3008A524 */  addiu      $5, $5, %lo(D_005F0830)
    /* 5CF98 0015CF98 2208110C */  jal        func_00442088
    /* 5CF9C 0015CF9C 00000000 */   nop
    /* 5CFA0 0015CFA0 1000A427 */  addiu      $4, $29, 0x10
    /* 5CFA4 0015CFA4 5C51110C */  jal        func_00454570
    /* 5CFA8 0015CFA8 00000000 */   nop
    /* 5CFAC 0015CFAC 04004014 */  bnez       $2, .L0015CFC0
    /* 5CFB0 0015CFB0 00000000 */   nop
    /* 5CFB4 0015CFB4 2D100000 */  daddu      $2, $0, $0
    /* 5CFB8 0015CFB8 0B000010 */  b          .L0015CFE8
    /* 5CFBC 0015CFBC 00000000 */   nop
  .L0015CFC0:
    /* 5CFC0 0015CFC0 309E8427 */  addiu      $4, $28, -0x61D0
    /* 5CFC4 0015CFC4 5F00053C */  lui        $5, %hi(D_005F07C0)
    /* 5CFC8 0015CFC8 C007A524 */  addiu      $5, $5, %lo(D_005F07C0)
    /* 5CFCC 0015CFCC A2010624 */  addiu      $6, $0, 0x1A2
    /* 5CFD0 0015CFD0 DA02110C */  jal        func_00440b68
    /* 5CFD4 0015CFD4 00000000 */   nop
    /* 5CFD8 0015CFD8 1000A427 */  addiu      $4, $29, 0x10
    /* 5CFDC 0015CFDC 2D280000 */  daddu      $5, $0, $0
    /* 5CFE0 0015CFE0 9852110C */  jal        func_00454a60
    /* 5CFE4 0015CFE4 00000000 */   nop
  .L0015CFE8:
    /* 5CFE8 0015CFE8 0000BFDF */  ld         $31, 0x0($29)
    /* 5CFEC 0015CFEC 1001BD27 */  addiu      $29, $29, 0x110
    /* 5CFF0 0015CFF0 0800E003 */  jr         $31
    /* 5CFF4 0015CFF4 00000000 */   nop
    /* 5CFF8 0015CFF8 00000000 */  nop
    /* 5CFFC 0015CFFC 00000000 */  nop
.size func_0015cf70, 0x90

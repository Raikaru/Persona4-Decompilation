.section .text
.set noat
.set noreorder
glabel func_0015ff20
    /* 5FF20 0015FF20 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 5FF24 0015FF24 2000BFFF */  sd         $31, 0x20($29)
    /* 5FF28 0015FF28 1000B17F */  sq         $17, 0x10($29)
    /* 5FF2C 0015FF2C 0000B07F */  sq         $16, 0x0($29)
    /* 5FF30 0015FF30 2D88A000 */  daddu      $17, $5, $0
    /* 5FF34 0015FF34 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* 5FF38 0015FF38 FFFF0224 */  addiu      $2, $0, -0x1
    /* 5FF3C 0015FF3C 04000216 */  bne        $16, $2, .L0015FF50
    /* 5FF40 0015FF40 00000000 */   nop
    /* 5FF44 0015FF44 2D100000 */  daddu      $2, $0, $0
    /* 5FF48 0015FF48 26000010 */  b          .L0015FFE4
    /* 5FF4C 0015FF4C 00000000 */   nop
  .L0015FF50:
    /* 5FF50 0015FF50 B03B050C */  jal        func_0014eec0
    /* 5FF54 0015FF54 00000000 */   nop
    /* 5FF58 0015FF58 21004014 */  bnez       $2, .L0015FFE0
    /* 5FF5C 0015FF5C 00000000 */   nop
    /* 5FF60 0015FF60 B000A427 */  addiu      $4, $29, 0xB0
    /* 5FF64 0015FF64 5F00053C */  lui        $5, %hi(D_005F1118)
    /* 5FF68 0015FF68 1811A524 */  addiu      $5, $5, %lo(D_005F1118)
    /* 5FF6C 0015FF6C 0C0A110C */  jal        func_00442830
    /* 5FF70 0015FF70 00000000 */   nop
    /* 5FF74 0015FF74 FFFF2732 */  andi       $7, $17, 0xFFFF
    /* 5FF78 0015FF78 3000A427 */  addiu      $4, $29, 0x30
    /* 5FF7C 0015FF7C 5F00053C */  lui        $5, %hi(D_005F1170)
    /* 5FF80 0015FF80 7011A524 */  addiu      $5, $5, %lo(D_005F1170)
    /* 5FF84 0015FF84 2D300002 */  daddu      $6, $16, $0
    /* 5FF88 0015FF88 2208110C */  jal        func_00442088
    /* 5FF8C 0015FF8C 00000000 */   nop
    /* 5FF90 0015FF90 3000A427 */  addiu      $4, $29, 0x30
    /* 5FF94 0015FF94 5C51110C */  jal        func_00454570
    /* 5FF98 0015FF98 00000000 */   nop
    /* 5FF9C 0015FF9C 04004014 */  bnez       $2, .L0015FFB0
    /* 5FFA0 0015FFA0 00000000 */   nop
    /* 5FFA4 0015FFA4 2D100000 */  daddu      $2, $0, $0
    /* 5FFA8 0015FFA8 0E000010 */  b          .L0015FFE4
    /* 5FFAC 0015FFAC 00000000 */   nop
  .L0015FFB0:
    /* 5FFB0 0015FFB0 F09E8427 */  addiu      $4, $28, -0x6110
    /* 5FFB4 0015FFB4 5F00053C */  lui        $5, %hi(D_005F1108)
    /* 5FFB8 0015FFB8 0811A524 */  addiu      $5, $5, %lo(D_005F1108)
    /* 5FFBC 0015FFBC 7D020624 */  addiu      $6, $0, 0x27D
    /* 5FFC0 0015FFC0 DA02110C */  jal        func_00440b68
    /* 5FFC4 0015FFC4 00000000 */   nop
    /* 5FFC8 0015FFC8 3000A427 */  addiu      $4, $29, 0x30
    /* 5FFCC 0015FFCC 2D280000 */  daddu      $5, $0, $0
    /* 5FFD0 0015FFD0 9852110C */  jal        func_00454a60
    /* 5FFD4 0015FFD4 00000000 */   nop
    /* 5FFD8 0015FFD8 02000010 */  b          .L0015FFE4
    /* 5FFDC 0015FFDC 00000000 */   nop
  .L0015FFE0:
    /* 5FFE0 0015FFE0 01000224 */  addiu      $2, $0, 0x1
  .L0015FFE4:
    /* 5FFE4 0015FFE4 2000BFDF */  ld         $31, 0x20($29)
    /* 5FFE8 0015FFE8 1000B17B */  lq         $17, 0x10($29)
    /* 5FFEC 0015FFEC 0000B07B */  lq         $16, 0x0($29)
    /* 5FFF0 0015FFF0 3001BD27 */  addiu      $29, $29, 0x130
    /* 5FFF4 0015FFF4 0800E003 */  jr         $31
    /* 5FFF8 0015FFF8 00000000 */   nop
    /* 5FFFC 0015FFFC 00000000 */  nop
.size func_0015ff20, 0xe0

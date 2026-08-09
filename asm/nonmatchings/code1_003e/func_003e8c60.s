.section .text
.set noat
.set noreorder
glabel func_003e8c60
    /* 2E8C60 003E8C60 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2E8C64 003E8C64 0100A230 */  andi       $2, $5, 0x1
    /* 2E8C68 003E8C68 4000BFFF */  sd         $31, 0x40($29)
    /* 2E8C6C 003E8C6C 3000B37F */  sq         $19, 0x30($29)
    /* 2E8C70 003E8C70 2000B27F */  sq         $18, 0x20($29)
    /* 2E8C74 003E8C74 2D988000 */  daddu      $19, $4, $0
    /* 2E8C78 003E8C78 1000B17F */  sq         $17, 0x10($29)
    /* 2E8C7C 003E8C7C 2D90C000 */  daddu      $18, $6, $0
    /* 2E8C80 003E8C80 0000B07F */  sq         $16, 0x0($29)
    /* 2E8C84 003E8C84 0D004010 */  beqz       $2, .L003E8CBC
    /* 2E8C88 003E8C88 2D880000 */   daddu     $17, $0, $0
    /* 2E8C8C 003E8C8C 3F00033C */  lui        $3, %hi(func_003e8790)
    /* 2E8C90 003E8C90 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2E8C94 003E8C94 90876324 */  addiu      $3, $3, %lo(func_003e8790)
    /* 2E8C98 003E8C98 2D200000 */  daddu      $4, $0, $0
    /* 2E8C9C 003E8C9C F87343AC */  sw         $3, %lo(D_008873F8)($2)
    /* 2E8CA0 003E8CA0 3F00033C */  lui        $3, %hi(func_003e8790 + 0x20)
    /* 2E8CA4 003E8CA4 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2E8CA8 003E8CA8 B0876324 */  addiu      $3, $3, %lo(func_003e8790 + 0x20)
    /* 2E8CAC 003E8CAC 08840F0C */  jal        func_003e1020
    /* 2E8CB0 003E8CB0 FC7343AC */   sw        $3, %lo(jtbl_008873FC)($2)
    /* 2E8CB4 003E8CB4 0B000010 */  b          .L003E8CE4
    /* 2E8CB8 003E8CB8 00000000 */   nop
  .L003E8CBC:
    /* 2E8CBC 003E8CBC 3E00033C */  lui        $3, %hi(func_003e13d0)
    /* 2E8CC0 003E8CC0 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2E8CC4 003E8CC4 D0136324 */  addiu      $3, $3, %lo(func_003e13d0)
    /* 2E8CC8 003E8CC8 01000424 */  addiu      $4, $0, 0x1
    /* 2E8CCC 003E8CCC F87343AC */  sw         $3, %lo(D_008873F8)($2)
    /* 2E8CD0 003E8CD0 3E00033C */  lui        $3, %hi(func_003e15a0)
    /* 2E8CD4 003E8CD4 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2E8CD8 003E8CD8 A0156324 */  addiu      $3, $3, %lo(func_003e15a0)
    /* 2E8CDC 003E8CDC 08840F0C */  jal        func_003e1020
    /* 2E8CE0 003E8CE0 FC7343AC */   sw        $3, %lo(jtbl_008873FC)($2)
  .L003E8CE4:
    /* 2E8CE4 003E8CE4 8800023C */  lui        $2, %hi(D_00887408)
    /* 2E8CE8 003E8CE8 8800103C */  lui        $16, %hi(D_00887404)
    /* 2E8CEC 003E8CEC 04741026 */  addiu      $16, $16, %lo(D_00887404)
    /* 2E8CF0 003E8CF0 087452AC */  sw         $18, %lo(D_00887408)($2)
    /* 2E8CF4 003E8CF4 0000028E */  lw         $2, 0x0($16)
    /* 2E8CF8 003E8CF8 03004010 */  beqz       $2, .L003E8D08
    /* 2E8CFC 003E8CFC 00000000 */   nop
  .L003E8D00:
    /* 2E8D00 003E8D00 25000010 */  b          .L003E8D98
    /* 2E8D04 003E8D04 2D102002 */   daddu     $2, $17, $0
  .L003E8D08:
    /* 2E8D08 003E8D08 68920F0C */  jal        func_003e49a0
    /* 2E8D0C 003E8D0C 00000000 */   nop
    /* 2E8D10 003E8D10 2D884000 */  daddu      $17, $2, $0
    /* 2E8D14 003E8D14 FAFF2012 */  beqz       $17, .L003E8D00
    /* 2E8D18 003E8D18 00000000 */   nop
    /* 2E8D1C 003E8D1C C4860F0C */  jal        func_003e1b10
    /* 2E8D20 003E8D20 2D206002 */   daddu     $4, $19, $0
    /* 2E8D24 003E8D24 2D884000 */  daddu      $17, $2, $0
    /* 2E8D28 003E8D28 17002012 */  beqz       $17, .L003E8D88
    /* 2E8D2C 003E8D2C 00000000 */   nop
    /* 2E8D30 003E8D30 8C8D0F0C */  jal        func_003e3630
    /* 2E8D34 003E8D34 00000000 */   nop
    /* 2E8D38 003E8D38 2D884000 */  daddu      $17, $2, $0
    /* 2E8D3C 003E8D3C 10002012 */  beqz       $17, .L003E8D80
    /* 2E8D40 003E8D40 00000000 */   nop
    /* 2E8D44 003E8D44 68A10F0C */  jal        func_003e85a0
    /* 2E8D48 003E8D48 00000000 */   nop
    /* 2E8D4C 003E8D4C 2D884000 */  daddu      $17, $2, $0
    /* 2E8D50 003E8D50 09002012 */  beqz       $17, .L003E8D78
    /* 2E8D54 003E8D54 00000000 */   nop
    /* 2E8D58 003E8D58 8CF90F0C */  jal        func_003fe630
    /* 2E8D5C 003E8D5C 00000000 */   nop
    /* 2E8D60 003E8D60 2D884000 */  daddu      $17, $2, $0
    /* 2E8D64 003E8D64 04002012 */  beqz       $17, .L003E8D78
    /* 2E8D68 003E8D68 00000000 */   nop
    /* 2E8D6C 003E8D6C 01000324 */  addiu      $3, $0, 0x1
    /* 2E8D70 003E8D70 09000010 */  b          .L003E8D98
    /* 2E8D74 003E8D74 000003AE */   sw        $3, 0x0($16)
  .L003E8D78:
    /* 2E8D78 003E8D78 B08D0F0C */  jal        func_003e36c0
    /* 2E8D7C 003E8D7C 00000000 */   nop
  .L003E8D80:
    /* 2E8D80 003E8D80 0C870F0C */  jal        func_003e1c30
    /* 2E8D84 003E8D84 00000000 */   nop
  .L003E8D88:
    /* 2E8D88 003E8D88 B0920F0C */  jal        func_003e4ac0
    /* 2E8D8C 003E8D8C 00000000 */   nop
    /* 2E8D90 003E8D90 DBFF0010 */  b          .L003E8D00
    /* 2E8D94 003E8D94 00000000 */   nop
  .L003E8D98:
    /* 2E8D98 003E8D98 4000BFDF */  ld         $31, 0x40($29)
    /* 2E8D9C 003E8D9C 3000B37B */  lq         $19, 0x30($29)
    /* 2E8DA0 003E8DA0 2000B27B */  lq         $18, 0x20($29)
    /* 2E8DA4 003E8DA4 1000B17B */  lq         $17, 0x10($29)
    /* 2E8DA8 003E8DA8 0000B07B */  lq         $16, 0x0($29)
    /* 2E8DAC 003E8DAC 0800E003 */  jr         $31
    /* 2E8DB0 003E8DB0 5000BD27 */   addiu     $29, $29, 0x50
    /* 2E8DB4 003E8DB4 00000000 */  nop
    /* 2E8DB8 003E8DB8 00000000 */  nop
    /* 2E8DBC 003E8DBC 00000000 */  nop
.size func_003e8c60, 0x160

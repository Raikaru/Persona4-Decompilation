.section .text
.set noat
.set noreorder
glabel func_004f8cd0
    /* 3F8CD0 004F8CD0 7400023C */  lui        $2, %hi(D_00743C30)
    /* 3F8CD4 004F8CD4 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F8CD8 004F8CD8 303C438C */  lw         $3, %lo(D_00743C30)($2)
    /* 3F8CDC 004F8CDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F8CE0 004F8CE0 2D808000 */  daddu      $16, $4, $0
    /* 3F8CE4 004F8CE4 0800B1FF */  sd         $17, 0x8($29)
    /* 3F8CE8 004F8CE8 2D88A000 */  daddu      $17, $5, $0
    /* 3F8CEC 004F8CEC 1000B2FF */  sd         $18, 0x10($29)
    /* 3F8CF0 004F8CF0 2D90C000 */  daddu      $18, $6, $0
    /* 3F8CF4 004F8CF4 03006014 */  bnez       $3, .L004F8D04
    /* 3F8CF8 004F8CF8 1800BFFF */   sd        $31, 0x18($29)
    /* 3F8CFC 004F8CFC B6E2130C */  jal        func_004f8ad8
    /* 3F8D00 004F8D00 00000000 */   nop
  .L004F8D04:
    /* 3F8D04 004F8D04 7600043C */  lui        $4, %hi(D_0075DBC0)
    /* 3F8D08 004F8D08 2D300002 */  daddu      $6, $16, $0
    /* 3F8D0C 004F8D0C 2D382002 */  daddu      $7, $17, $0
    /* 3F8D10 004F8D10 2D404002 */  daddu      $8, $18, $0
    /* 3F8D14 004F8D14 C0DB8424 */  addiu      $4, $4, %lo(D_0075DBC0)
    /* 3F8D18 004F8D18 C6E2130C */  jal        func_004f8b18
    /* 3F8D1C 004F8D1C 06000524 */   addiu     $5, $0, 0x6
    /* 3F8D20 004F8D20 2D100000 */  daddu      $2, $0, $0
    /* 3F8D24 004F8D24 0000B0DF */  ld         $16, 0x0($29)
    /* 3F8D28 004F8D28 0800B1DF */  ld         $17, 0x8($29)
    /* 3F8D2C 004F8D2C 1000B2DF */  ld         $18, 0x10($29)
    /* 3F8D30 004F8D30 1800BFDF */  ld         $31, 0x18($29)
    /* 3F8D34 004F8D34 0800E003 */  jr         $31
    /* 3F8D38 004F8D38 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F8D3C 004F8D3C 00000000 */  nop
.size func_004f8cd0, 0x70

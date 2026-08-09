.section .text
.set noat
.set noreorder
glabel func_003d4c70
    /* 2D4C70 003D4C70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2D4C74 003D4C74 3D00063C */  lui        $6, %hi(func_003d48c0)
    /* 2D4C78 003D4C78 2000BFFF */  sd         $31, 0x20($29)
    /* 2D4C7C 003D4C7C 3D00073C */  lui        $7, %hi(func_003d48d0)
    /* 2D4C80 003D4C80 1000B17F */  sq         $17, 0x10($29)
    /* 2D4C84 003D4C84 3D00083C */  lui        $8, %hi(func_003d4910)
    /* 2D4C88 003D4C88 0000B07F */  sq         $16, 0x0($29)
    /* 2D4C8C 003D4C8C 04000424 */  addiu      $4, $0, 0x4
    /* 2D4C90 003D4C90 0F050524 */  addiu      $5, $0, 0x50F
    /* 2D4C94 003D4C94 C048C624 */  addiu      $6, $6, %lo(func_003d48c0)
    /* 2D4C98 003D4C98 D048E724 */  addiu      $7, $7, %lo(func_003d48d0)
    /* 2D4C9C 003D4C9C 10490825 */  addiu      $8, $8, %lo(func_003d4910)
    /* 2D4CA0 003D4CA0 2D800000 */  daddu      $16, $0, $0
    /* 2D4CA4 003D4CA4 DC0A0F0C */  jal        func_003c2b70
    /* 2D4CA8 003D4CA8 2D880000 */   daddu     $17, $0, $0
    /* 2D4CAC 003D4CAC 3D00063C */  lui        $6, %hi(func_003d48c0)
    /* 2D4CB0 003D4CB0 3D00073C */  lui        $7, %hi(func_003d48d0)
    /* 2D4CB4 003D4CB4 3D00083C */  lui        $8, %hi(func_003d49b0)
    /* 2D4CB8 003D4CB8 30B782AF */  sw         $2, -0x48D0($28)
    /* 2D4CBC 003D4CBC 04000424 */  addiu      $4, $0, 0x4
    /* 2D4CC0 003D4CC0 0F050524 */  addiu      $5, $0, 0x50F
    /* 2D4CC4 003D4CC4 C048C624 */  addiu      $6, $6, %lo(func_003d48c0)
    /* 2D4CC8 003D4CC8 D048E724 */  addiu      $7, $7, %lo(func_003d48d0)
    /* 2D4CCC 003D4CCC AC060F0C */  jal        func_003c1ab0
    /* 2D4CD0 003D4CD0 B0490825 */   addiu     $8, $8, %lo(func_003d49b0)
    /* 2D4CD4 003D4CD4 3D00063C */  lui        $6, %hi(func_003d48c0)
    /* 2D4CD8 003D4CD8 3D00073C */  lui        $7, %hi(func_003d48d0)
    /* 2D4CDC 003D4CDC 3D00083C */  lui        $8, %hi(func_003d4a60)
    /* 2D4CE0 003D4CE0 2CB782AF */  sw         $2, -0x48D4($28)
    /* 2D4CE4 003D4CE4 04000424 */  addiu      $4, $0, 0x4
    /* 2D4CE8 003D4CE8 0F050524 */  addiu      $5, $0, 0x50F
    /* 2D4CEC 003D4CEC C048C624 */  addiu      $6, $6, %lo(func_003d48c0)
    /* 2D4CF0 003D4CF0 D048E724 */  addiu      $7, $7, %lo(func_003d48d0)
    /* 2D4CF4 003D4CF4 40230F0C */  jal        func_003c8d00
    /* 2D4CF8 003D4CF8 604A0825 */   addiu     $8, $8, %lo(func_003d4a60)
    /* 2D4CFC 003D4CFC 3D00053C */  lui        $5, %hi(func_003d4b00)
    /* 2D4D00 003D4D00 28B782AF */  sw         $2, -0x48D8($28)
    /* 2D4D04 003D4D04 0F050424 */  addiu      $4, $0, 0x50F
    /* 2D4D08 003D4D08 D0060F0C */  jal        func_003c1b40
    /* 2D4D0C 003D4D0C 004BA524 */   addiu     $5, $5, %lo(func_003d4b00)
    /* 2D4D10 003D4D10 3D00053C */  lui        $5, %hi(func_003d4bf0)
    /* 2D4D14 003D4D14 25882202 */  or         $17, $17, $2
    /* 2D4D18 003D4D18 0F050424 */  addiu      $4, $0, 0x50F
    /* 2D4D1C 003D4D1C 58230F0C */  jal        func_003c8d60
    /* 2D4D20 003D4D20 F04BA524 */   addiu     $5, $5, %lo(func_003d4bf0)
    /* 2D4D24 003D4D24 25282202 */  or         $5, $17, $2
    /* 2D4D28 003D4D28 30B7848F */  lw         $4, -0x48D0($28)
    /* 2D4D2C 003D4D2C 2CB7838F */  lw         $3, -0x48D4($28)
    /* 2D4D30 003D4D30 28B7828F */  lw         $2, -0x48D8($28)
    /* 2D4D34 003D4D34 25188300 */  or         $3, $4, $3
    /* 2D4D38 003D4D38 25104300 */  or         $2, $2, $3
    /* 2D4D3C 003D4D3C 2510A200 */  or         $2, $5, $2
    /* 2D4D40 003D4D40 02004004 */  bltz       $2, .L003D4D4C
    /* 2D4D44 003D4D44 00000000 */   nop
    /* 2D4D48 003D4D48 01001024 */  addiu      $16, $0, 0x1
  .L003D4D4C:
    /* 2D4D4C 003D4D4C 2D100002 */  daddu      $2, $16, $0
    /* 2D4D50 003D4D50 2000BFDF */  ld         $31, 0x20($29)
    /* 2D4D54 003D4D54 1000B17B */  lq         $17, 0x10($29)
    /* 2D4D58 003D4D58 0000B07B */  lq         $16, 0x0($29)
    /* 2D4D5C 003D4D5C 0800E003 */  jr         $31
    /* 2D4D60 003D4D60 3000BD27 */   addiu     $29, $29, 0x30
    /* 2D4D64 003D4D64 00000000 */  nop
    /* 2D4D68 003D4D68 00000000 */  nop
    /* 2D4D6C 003D4D6C 00000000 */  nop
.size func_003d4c70, 0x100

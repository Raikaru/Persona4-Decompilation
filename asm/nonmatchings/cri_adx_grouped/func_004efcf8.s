.section .text
.set noat
.set noreorder
glabel func_004efcf8
    /* 3EFCF8 004EFCF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFCFC 004EFCFC 9200053C */  lui        $5, %hi(D_009259C0)
    /* 3EFD00 004EFD00 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFD04 004EFD04 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFD08 004EFD08 C059A524 */  addiu      $5, $5, %lo(D_009259C0)
    /* 3EFD0C 004EFD0C C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFD10 004EFD10 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFD14 004EFD14 2D380002 */  daddu      $7, $16, $0
    /* 3EFD18 004EFD18 0000A4AC */  sw         $4, 0x0($5)
    /* 3EFD1C 004EFD1C 24000424 */  addiu      $4, $0, 0x24
    /* 3EFD20 004EFD20 01000624 */  addiu      $6, $0, 0x1
    /* 3EFD24 004EFD24 2896130C */  jal        func_004e58a0
    /* 3EFD28 004EFD28 04000824 */   addiu     $8, $0, 0x4
    /* 3EFD2C 004EFD2C 9200033C */  lui        $3, %hi(D_00925980)
    /* 3EFD30 004EFD30 0C00078E */  lw         $7, 0xC($16)
    /* 3EFD34 004EFD34 80596324 */  addiu      $3, $3, %lo(D_00925980)
    /* 3EFD38 004EFD38 0000068E */  lw         $6, 0x0($16)
    /* 3EFD3C 004EFD3C 2D106000 */  daddu      $2, $3, $0
    /* 3EFD40 004EFD40 0400048E */  lw         $4, 0x4($16)
    /* 3EFD44 004EFD44 0800058E */  lw         $5, 0x8($16)
    /* 3EFD48 004EFD48 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFD4C 004EFD4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFD50 004EFD50 000066AC */  sw         $6, 0x0($3)
    /* 3EFD54 004EFD54 040064AC */  sw         $4, 0x4($3)
    /* 3EFD58 004EFD58 080065AC */  sw         $5, 0x8($3)
    /* 3EFD5C 004EFD5C 0C0067AC */  sw         $7, 0xC($3)
    /* 3EFD60 004EFD60 0800E003 */  jr         $31
    /* 3EFD64 004EFD64 1000BD27 */   addiu     $29, $29, 0x10
.size func_004efcf8, 0x70

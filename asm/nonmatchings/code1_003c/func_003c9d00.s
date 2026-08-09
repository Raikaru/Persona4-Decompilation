.section .text
.set noat
.set noreorder
glabel func_003c9d00
    /* 2C9D00 003C9D00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C9D04 003C9D04 3D00053C */  lui        $5, %hi(func_003c8dd0)
    /* 2C9D08 003C9D08 1000BFFF */  sd         $31, 0x10($29)
    /* 2C9D0C 003C9D0C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2C9D10 003C9D10 0000B07F */  sq         $16, 0x0($29)
    /* 2C9D14 003C9D14 D08DA524 */  addiu      $5, $5, %lo(func_003c8dd0)
    /* 2C9D18 003C9D18 2D808000 */  daddu      $16, $4, $0
    /* 2C9D1C 003C9D1C E072448C */  lw         $4, %lo(D_008872E0)($2)
    /* 2C9D20 003C9D20 782F0F0C */  jal        func_003cbde0
    /* 2C9D24 003C9D24 2D300002 */   daddu     $6, $16, $0
    /* 2C9D28 003C9D28 2D100002 */  daddu      $2, $16, $0
    /* 2C9D2C 003C9D2C 1000BFDF */  ld         $31, 0x10($29)
    /* 2C9D30 003C9D30 0000B07B */  lq         $16, 0x0($29)
    /* 2C9D34 003C9D34 0800E003 */  jr         $31
    /* 2C9D38 003C9D38 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C9D3C 003C9D3C 00000000 */  nop
.size func_003c9d00, 0x40

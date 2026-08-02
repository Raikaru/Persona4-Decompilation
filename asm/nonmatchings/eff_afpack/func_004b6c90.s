.section .text
.set noat
.set noreorder
glabel func_004b6c90
    /* 3B6C90 004B6C90 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3B6C94 004B6C94 3000BFFF */  sd         $31, 0x30($29)
    /* 3B6C98 004B6C98 2000B27F */  sq         $18, 0x20($29)
    /* 3B6C9C 004B6C9C 1000B17F */  sq         $17, 0x10($29)
    /* 3B6CA0 004B6CA0 0000B07F */  sq         $16, 0x0($29)
    /* 3B6CA4 004B6CA4 2D808000 */  daddu      $16, $4, $0
    /* 3B6CA8 004B6CA8 2D90A000 */  daddu      $18, $5, $0
    /* 3B6CAC 004B6CAC 20B18427 */  addiu      $4, $28, -0x4EE0
    /* 3B6CB0 004B6CB0 7100053C */  lui        $5, %hi(D_007146B0)
    /* 3B6CB4 004B6CB4 B046A524 */  addiu      $5, $5, %lo(D_007146B0)
    /* 3B6CB8 004B6CB8 DA020624 */  addiu      $6, $0, 0x2DA
    /* 3B6CBC 004B6CBC DA02110C */  jal        func_00440b68
    /* 3B6CC0 004B6CC0 00000000 */   nop
    /* 3B6CC4 004B6CC4 7100043C */  lui        $4, %hi(D_007146C0)
    /* 3B6CC8 004B6CC8 C0468424 */  addiu      $4, $4, %lo(D_007146C0)
    /* 3B6CCC 004B6CCC 2D280000 */  daddu      $5, $0, $0
    /* 3B6CD0 004B6CD0 9852110C */  jal        func_00454a60
    /* 3B6CD4 004B6CD4 00000000 */   nop
    /* 3B6CD8 004B6CD8 2D884000 */  daddu      $17, $2, $0
    /* 3B6CDC 004B6CDC 2D202002 */  daddu      $4, $17, $0
    /* 3B6CE0 004B6CE0 5458110C */  jal        func_00456150
    /* 3B6CE4 004B6CE4 00000000 */   nop
    /* 3B6CE8 004B6CE8 7100043C */  lui        $4, %hi(D_007146C0)
    /* 3B6CEC 004B6CEC C0468424 */  addiu      $4, $4, %lo(D_007146C0)
    /* 3B6CF0 004B6CF0 2D280000 */  daddu      $5, $0, $0
    /* 3B6CF4 004B6CF4 D0BD0F0C */  jal        func_003ef740
    /* 3B6CF8 004B6CF8 00000000 */   nop
    /* 3B6CFC 004B6CFC B8BB82AF */  sw         $2, -0x4448($28)
    /* 3B6D00 004B6D00 2D202002 */  daddu      $4, $17, $0
    /* 3B6D04 004B6D04 F452110C */  jal        func_00454bd0
    /* 3B6D08 004B6D08 00000000 */   nop
    /* 3B6D0C 004B6D0C B0BB80AF */  sw         $0, -0x4450($28)
    /* 3B6D10 004B6D10 ACBB80AF */  sw         $0, -0x4454($28)
    /* 3B6D14 004B6D14 7100043C */  lui        $4, %hi(D_007146D0)
    /* 3B6D18 004B6D18 D0468424 */  addiu      $4, $4, %lo(D_007146D0)
    /* 3B6D1C 004B6D1C 2D284002 */  daddu      $5, $18, $0
    /* 3B6D20 004B6D20 2D300000 */  daddu      $6, $0, $0
    /* 3B6D24 004B6D24 2D380000 */  daddu      $7, $0, $0
    /* 3B6D28 004B6D28 4B00083C */  lui        $8, %hi(func_004b6e40)
    /* 3B6D2C 004B6D2C 406E0825 */  addiu      $8, $8, %lo(func_004b6e40)
    /* 3B6D30 004B6D30 2D480000 */  daddu      $9, $0, $0
    /* 3B6D34 004B6D34 2D500000 */  daddu      $10, $0, $0
    /* 3B6D38 004B6D38 7847110C */  jal        func_00451de0
    /* 3B6D3C 004B6D3C 00000000 */   nop
    /* 3B6D40 004B6D40 B4BB82AF */  sw         $2, -0x444C($28)
    /* 3B6D44 004B6D44 9200043C */  lui        $4, %hi(D_00922DB0)
    /* 3B6D48 004B6D48 B02D8424 */  addiu      $4, $4, %lo(D_00922DB0)
    /* 3B6D4C 004B6D4C 2D280000 */  daddu      $5, $0, $0
    /* 3B6D50 004B6D50 30000624 */  addiu      $6, $0, 0x30
    /* 3B6D54 004B6D54 72FE100C */  jal        func_0043f9c8
    /* 3B6D58 004B6D58 00000000 */   nop
    /* 3B6D5C 004B6D5C 4B00043C */  lui        $4, %hi(func_004b6e80)
    /* 3B6D60 004B6D60 806E8424 */  addiu      $4, $4, %lo(func_004b6e80)
    /* 3B6D64 004B6D64 9200033C */  lui        $3, %hi(D_00922DB8)
    /* 3B6D68 004B6D68 B82D64AC */  sw         $4, %lo(D_00922DB8)($3)
    /* 3B6D6C 004B6D6C 9200033C */  lui        $3, %hi(D_00922DC0)
    /* 3B6D70 004B6D70 C02D60AC */  sw         $0, %lo(D_00922DC0)($3)
    /* 3B6D74 004B6D74 A8BB90AF */  sw         $16, -0x4458($28)
    /* 3B6D78 004B6D78 3000BFDF */  ld         $31, 0x30($29)
    /* 3B6D7C 004B6D7C 2000B27B */  lq         $18, 0x20($29)
    /* 3B6D80 004B6D80 1000B17B */  lq         $17, 0x10($29)
    /* 3B6D84 004B6D84 0000B07B */  lq         $16, 0x0($29)
    /* 3B6D88 004B6D88 4000BD27 */  addiu      $29, $29, 0x40
    /* 3B6D8C 004B6D8C 0800E003 */  jr         $31
    /* 3B6D90 004B6D90 00000000 */   nop
    /* 3B6D94 004B6D94 00000000 */  nop
    /* 3B6D98 004B6D98 00000000 */  nop
    /* 3B6D9C 004B6D9C 00000000 */  nop
.size func_004b6c90, 0x110

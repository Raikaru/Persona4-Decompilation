.section .text
.set noat
.set noreorder
glabel func_003d6c50
    /* 2D6C50 003D6C50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2D6C54 003D6C54 7100023C */  lui        $2, %hi(D_0070B5E8)
    /* 2D6C58 003D6C58 2000BFFF */  sd         $31, 0x20($29)
    /* 2D6C5C 003D6C5C 1000B17F */  sq         $17, 0x10($29)
    /* 2D6C60 003D6C60 0000B07F */  sq         $16, 0x0($29)
    /* 2D6C64 003D6C64 0800B124 */  addiu      $17, $5, 0x8
    /* 2D6C68 003D6C68 E8B542C4 */  lwc1       $f2, %lo(D_0070B5E8)($2)
    /* 2D6C6C 003D6C6C 2D808000 */  daddu      $16, $4, $0
    /* 2D6C70 003D6C70 7100023C */  lui        $2, %hi(D_0070B5EC)
    /* 2D6C74 003D6C74 ECB541C4 */  lwc1       $f1, %lo(D_0070B5EC)($2)
    /* 2D6C78 003D6C78 3000A2E7 */  swc1       $f2, 0x30($29)
    /* 2D6C7C 003D6C7C 7100023C */  lui        $2, %hi(D_0070B5F0)
    /* 2D6C80 003D6C80 F0B540C4 */  lwc1       $f0, %lo(D_0070B5F0)($2)
    /* 2D6C84 003D6C84 3400A1E7 */  swc1       $f1, 0x34($29)
    /* 2D6C88 003D6C88 3800A0E7 */  swc1       $f0, 0x38($29)
    /* 2D6C8C 003D6C8C 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 2D6C90 003D6C90 000080E4 */  swc1       $f0, 0x0($4)
    /* 2D6C94 003D6C94 1400A0C4 */  lwc1       $f0, 0x14($5)
    /* 2D6C98 003D6C98 040080E4 */  swc1       $f0, 0x4($4)
    /* 2D6C9C 003D6C9C 080080AC */  sw         $0, 0x8($4)
    /* 2D6CA0 003D6CA0 100080AC */  sw         $0, 0x10($4)
    /* 2D6CA4 003D6CA4 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2D6CA8 003D6CA8 140080E4 */  swc1       $f0, 0x14($4)
    /* 2D6CAC 003D6CAC 180080AC */  sw         $0, 0x18($4)
    /* 2D6CB0 003D6CB0 200080AC */  sw         $0, 0x20($4)
    /* 2D6CB4 003D6CB4 240080AC */  sw         $0, 0x24($4)
    /* 2D6CB8 003D6CB8 280080AC */  sw         $0, 0x28($4)
    /* 2D6CBC 003D6CBC 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* 2D6CC0 003D6CC0 300080E4 */  swc1       $f0, 0x30($4)
    /* 2D6CC4 003D6CC4 1C00A0C4 */  lwc1       $f0, 0x1C($5)
    /* 2D6CC8 003D6CC8 340080E4 */  swc1       $f0, 0x34($4)
    /* 2D6CCC 003D6CCC 74810F0C */  jal        func_003e05d0
    /* 2D6CD0 003D6CD0 380080AC */   sw        $0, 0x38($4)
    /* 2D6CD4 003D6CD4 7500053C */  lui        $5, %hi(D_00752F88)
    /* 2D6CD8 003D6CD8 2D200002 */  daddu      $4, $16, $0
    /* 2D6CDC 003D6CDC 882FA524 */  addiu      $5, $5, %lo(D_00752F88)
    /* 2D6CE0 003D6CE0 24830F0C */  jal        func_003e0c90
    /* 2D6CE4 003D6CE4 02000624 */   addiu     $6, $0, 0x2
    /* 2D6CE8 003D6CE8 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2D6CEC 003D6CEC 4940023C */  lui        $2, (0x40490FDB >> 16)
    /* 2D6CF0 003D6CF0 DB0F4334 */  ori        $3, $2, (0x40490FDB & 0xFFFF)
    /* 2D6CF4 003D6CF4 2D200002 */  daddu      $4, $16, $0
    /* 2D6CF8 003D6CF8 00108344 */  mtc1       $3, $f2
    /* 2D6CFC 003D6CFC 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 2D6D00 003D6D00 00008244 */  mtc1       $2, $f0
    /* 2D6D04 003D6D04 3000A527 */  addiu      $5, $29, 0x30
    /* 2D6D08 003D6D08 02000624 */  addiu      $6, $0, 0x2
    /* 2D6D0C 003D6D0C 43080246 */  div.s      $f1, $f1, $f2
    /* 2D6D10 003D6D10 00000000 */  nop
    /* 2D6D14 003D6D14 00000000 */  nop
    /* 2D6D18 003D6D18 1C820F0C */  jal        func_003e0870
    /* 2D6D1C 003D6D1C 02030146 */   mul.s     $f12, $f0, $f1
    /* 2D6D20 003D6D20 7500053C */  lui        $5, %hi(D_00752F98)
    /* 2D6D24 003D6D24 2D200002 */  daddu      $4, $16, $0
    /* 2D6D28 003D6D28 982FA524 */  addiu      $5, $5, %lo(D_00752F98)
    /* 2D6D2C 003D6D2C 24830F0C */  jal        func_003e0c90
    /* 2D6D30 003D6D30 02000624 */   addiu     $6, $0, 0x2
    /* 2D6D34 003D6D34 2000BFDF */  ld         $31, 0x20($29)
    /* 2D6D38 003D6D38 1000B17B */  lq         $17, 0x10($29)
    /* 2D6D3C 003D6D3C 0000B07B */  lq         $16, 0x0($29)
    /* 2D6D40 003D6D40 0800E003 */  jr         $31
    /* 2D6D44 003D6D44 4000BD27 */   addiu     $29, $29, 0x40
    /* 2D6D48 003D6D48 00000000 */  nop
    /* 2D6D4C 003D6D4C 00000000 */  nop
.size func_003d6c50, 0x100

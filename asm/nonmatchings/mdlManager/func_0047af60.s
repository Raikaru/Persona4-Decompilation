.section .text
.set noat
.set noreorder
glabel func_0047af60
    /* 37AF60 0047AF60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 37AF64 0047AF64 1000BFFF */  sd         $31, 0x10($29)
    /* 37AF68 0047AF68 0000B07F */  sq         $16, 0x0($29)
    /* 37AF6C 0047AF6C 2D808000 */  daddu      $16, $4, $0
    /* 37AF70 0047AF70 7100043C */  lui        $4, %hi(D_00713138)
    /* 37AF74 0047AF74 38318424 */  addiu      $4, $4, %lo(D_00713138)
    /* 37AF78 0047AF78 69170524 */  addiu      $5, $0, 0x1769
    /* 37AF7C 0047AF7C A43A110C */  jal        func_0044ea90
    /* 37AF80 0047AF80 00000000 */   nop
    /* 37AF84 0047AF84 48000424 */  addiu      $4, $0, 0x48
    /* 37AF88 0047AF88 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37AF8C 0047AF8C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 37AF90 0047AF90 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 37AF94 0047AF94 09F84000 */  jalr       $2
    /* 37AF98 0047AF98 00000000 */   nop
    /* 37AF9C 0047AF9C 0C0302AE */  sw         $2, 0x30C($16)
    /* 37AFA0 0047AFA0 2D204000 */  daddu      $4, $2, $0
    /* 37AFA4 0047AFA4 2D280000 */  daddu      $5, $0, $0
    /* 37AFA8 0047AFA8 48000624 */  addiu      $6, $0, 0x48
    /* 37AFAC 0047AFAC 72FE100C */  jal        func_0043f9c8
    /* 37AFB0 0047AFB0 00000000 */   nop
    /* 37AFB4 0047AFB4 1000BFDF */  ld         $31, 0x10($29)
    /* 37AFB8 0047AFB8 0000B07B */  lq         $16, 0x0($29)
    /* 37AFBC 0047AFBC 2000BD27 */  addiu      $29, $29, 0x20
    /* 37AFC0 0047AFC0 0800E003 */  jr         $31
    /* 37AFC4 0047AFC4 00000000 */   nop
    /* 37AFC8 0047AFC8 00000000 */  nop
    /* 37AFCC 0047AFCC 00000000 */  nop
.size func_0047af60, 0x70

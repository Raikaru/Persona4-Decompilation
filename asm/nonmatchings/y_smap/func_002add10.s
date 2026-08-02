.section .text
.set noat
.set noreorder
glabel func_002add10
    /* 1ADD10 002ADD10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1ADD14 002ADD14 0000BFFF */  sd         $31, 0x0($29)
    /* 1ADD18 002ADD18 0E000424 */  addiu      $4, $0, 0xE
    /* 1ADD1C 002ADD1C B400A524 */  addiu      $5, $5, 0xB4
    /* 1ADD20 002ADD20 8800023C */  lui        $2, %hi(D_00887304)
    /* 1ADD24 002ADD24 0473428C */  lw         $2, %lo(D_00887304)($2)
    /* 1ADD28 002ADD28 09F84000 */  jalr       $2
    /* 1ADD2C 002ADD2C 00000000 */   nop
    /* 1ADD30 002ADD30 0E000424 */  addiu      $4, $0, 0xE
    /* 1ADD34 002ADD34 2D280000 */  daddu      $5, $0, $0
    /* 1ADD38 002ADD38 8800023C */  lui        $2, %hi(D_00887300)
    /* 1ADD3C 002ADD3C 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 1ADD40 002ADD40 09F84000 */  jalr       $2
    /* 1ADD44 002ADD44 00000000 */   nop
    /* 1ADD48 002ADD48 0000BFDF */  ld         $31, 0x0($29)
    /* 1ADD4C 002ADD4C 1000BD27 */  addiu      $29, $29, 0x10
    /* 1ADD50 002ADD50 0800E003 */  jr         $31
    /* 1ADD54 002ADD54 00000000 */   nop
    /* 1ADD58 002ADD58 00000000 */  nop
    /* 1ADD5C 002ADD5C 00000000 */  nop
.size func_002add10, 0x50

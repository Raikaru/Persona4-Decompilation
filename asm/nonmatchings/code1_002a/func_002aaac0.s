.section .text
.set noat
.set noreorder
glabel func_002aaac0
    /* 1AAAC0 002AAAC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1AAAC4 002AAAC4 1000BFFF */  sd         $31, 0x10($29)
    /* 1AAAC8 002AAAC8 0000B07F */  sq         $16, 0x0($29)
    /* 1AAACC 002AAACC 8800103C */  lui        $16, %hi(D_00887300)
    /* 1AAAD0 002AAAD0 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 1AAAD4 002AAAD4 0A000424 */  addiu      $4, $0, 0xA
    /* 1AAAD8 002AAAD8 05000524 */  addiu      $5, $0, 0x5
    /* 1AAADC 002AAADC 0000028E */  lw         $2, 0x0($16)
    /* 1AAAE0 002AAAE0 09F84000 */  jalr       $2
    /* 1AAAE4 002AAAE4 00000000 */   nop
    /* 1AAAE8 002AAAE8 0B000424 */  addiu      $4, $0, 0xB
    /* 1AAAEC 002AAAEC 06000524 */  addiu      $5, $0, 0x6
    /* 1AAAF0 002AAAF0 0000028E */  lw         $2, 0x0($16)
    /* 1AAAF4 002AAAF4 09F84000 */  jalr       $2
    /* 1AAAF8 002AAAF8 00000000 */   nop
    /* 1AAAFC 002AAAFC 0E000424 */  addiu      $4, $0, 0xE
    /* 1AAB00 002AAB00 2D280000 */  daddu      $5, $0, $0
    /* 1AAB04 002AAB04 0000028E */  lw         $2, 0x0($16)
    /* 1AAB08 002AAB08 09F84000 */  jalr       $2
    /* 1AAB0C 002AAB0C 00000000 */   nop
    /* 1AAB10 002AAB10 0C000424 */  addiu      $4, $0, 0xC
    /* 1AAB14 002AAB14 01000524 */  addiu      $5, $0, 0x1
    /* 1AAB18 002AAB18 0000028E */  lw         $2, 0x0($16)
    /* 1AAB1C 002AAB1C 09F84000 */  jalr       $2
    /* 1AAB20 002AAB20 00000000 */   nop
    /* 1AAB24 002AAB24 07000424 */  addiu      $4, $0, 0x7
    /* 1AAB28 002AAB28 02000524 */  addiu      $5, $0, 0x2
    /* 1AAB2C 002AAB2C 0000028E */  lw         $2, 0x0($16)
    /* 1AAB30 002AAB30 09F84000 */  jalr       $2
    /* 1AAB34 002AAB34 00000000 */   nop
    /* 1AAB38 002AAB38 09000424 */  addiu      $4, $0, 0x9
    /* 1AAB3C 002AAB3C 02000524 */  addiu      $5, $0, 0x2
    /* 1AAB40 002AAB40 0000028E */  lw         $2, 0x0($16)
    /* 1AAB44 002AAB44 09F84000 */  jalr       $2
    /* 1AAB48 002AAB48 00000000 */   nop
    /* 1AAB4C 002AAB4C 02000424 */  addiu      $4, $0, 0x2
    /* 1AAB50 002AAB50 04000524 */  addiu      $5, $0, 0x4
    /* 1AAB54 002AAB54 0000028E */  lw         $2, 0x0($16)
    /* 1AAB58 002AAB58 09F84000 */  jalr       $2
    /* 1AAB5C 002AAB5C 00000000 */   nop
    /* 1AAB60 002AAB60 14000424 */  addiu      $4, $0, 0x14
    /* 1AAB64 002AAB64 01000524 */  addiu      $5, $0, 0x1
    /* 1AAB68 002AAB68 0000028E */  lw         $2, 0x0($16)
    /* 1AAB6C 002AAB6C 09F84000 */  jalr       $2
    /* 1AAB70 002AAB70 00000000 */   nop
    /* 1AAB74 002AAB74 06000424 */  addiu      $4, $0, 0x6
    /* 1AAB78 002AAB78 2D280000 */  daddu      $5, $0, $0
    /* 1AAB7C 002AAB7C 0000028E */  lw         $2, 0x0($16)
    /* 1AAB80 002AAB80 09F84000 */  jalr       $2
    /* 1AAB84 002AAB84 00000000 */   nop
    /* 1AAB88 002AAB88 08000424 */  addiu      $4, $0, 0x8
    /* 1AAB8C 002AAB8C 2D280000 */  daddu      $5, $0, $0
    /* 1AAB90 002AAB90 0000028E */  lw         $2, 0x0($16)
    /* 1AAB94 002AAB94 09F84000 */  jalr       $2
    /* 1AAB98 002AAB98 00000000 */   nop
    /* 1AAB9C 002AAB9C 03000424 */  addiu      $4, $0, 0x3
    /* 1AABA0 002AABA0 0500023C */  lui        $2, (0x50003 >> 16)
    /* 1AABA4 002AABA4 03004534 */  ori        $5, $2, (0x50003 & 0xFFFF)
    /* 1AABA8 002AABA8 10D90F0C */  jal        func_003f6440
    /* 1AABAC 002AABAC 00000000 */   nop
    /* 1AABB0 002AABB0 02000424 */  addiu      $4, $0, 0x2
    /* 1AABB4 002AABB4 44000524 */  addiu      $5, $0, 0x44
    /* 1AABB8 002AABB8 10D90F0C */  jal        func_003f6440
    /* 1AABBC 002AABBC 00000000 */   nop
    /* 1AABC0 002AABC0 01000424 */  addiu      $4, $0, 0x1
    /* 1AABC4 002AABC4 2D280000 */  daddu      $5, $0, $0
    /* 1AABC8 002AABC8 0000028E */  lw         $2, 0x0($16)
    /* 1AABCC 002AABCC 09F84000 */  jalr       $2
    /* 1AABD0 002AABD0 00000000 */   nop
    /* 1AABD4 002AABD4 1000BFDF */  ld         $31, 0x10($29)
    /* 1AABD8 002AABD8 0000B07B */  lq         $16, 0x0($29)
    /* 1AABDC 002AABDC 2000BD27 */  addiu      $29, $29, 0x20
    /* 1AABE0 002AABE0 0800E003 */  jr         $31
    /* 1AABE4 002AABE4 00000000 */   nop
    /* 1AABE8 002AABE8 00000000 */  nop
    /* 1AABEC 002AABEC 00000000 */  nop
.size func_002aaac0, 0x130

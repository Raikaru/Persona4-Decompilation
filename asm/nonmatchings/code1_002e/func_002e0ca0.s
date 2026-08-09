.section .text
.set noat
.set noreorder
glabel func_002e0ca0
    /* 1E0CA0 002E0CA0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 1E0CA4 002E0CA4 6000BFFF */  sd         $31, 0x60($29)
    /* 1E0CA8 002E0CA8 5000B47F */  sq         $20, 0x50($29)
    /* 1E0CAC 002E0CAC 4000B37F */  sq         $19, 0x40($29)
    /* 1E0CB0 002E0CB0 3000B27F */  sq         $18, 0x30($29)
    /* 1E0CB4 002E0CB4 2000B17F */  sq         $17, 0x20($29)
    /* 1E0CB8 002E0CB8 1000B07F */  sq         $16, 0x10($29)
    /* 1E0CBC 002E0CBC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1E0CC0 002E0CC0 2DA08000 */  daddu      $20, $4, $0
    /* 1E0CC4 002E0CC4 7800A5FF */  sd         $5, 0x78($29)
    /* 1E0CC8 002E0CC8 06650046 */  mov.s      $f20, $f12
    /* 1E0CCC 002E0CCC 2D98C000 */  daddu      $19, $6, $0
    /* 1E0CD0 002E0CD0 2D90E000 */  daddu      $18, $7, $0
    /* 1E0CD4 002E0CD4 2D880001 */  daddu      $17, $8, $0
    /* 1E0CD8 002E0CD8 2D802001 */  daddu      $16, $9, $0
    /* 1E0CDC 002E0CDC 6400043C */  lui        $4, %hi(D_0063FB90)
    /* 1E0CE0 002E0CE0 90FB8424 */  addiu      $4, $4, %lo(D_0063FB90)
    /* 1E0CE4 002E0CE4 DCA9110C */  jal        func_0046a770
    /* 1E0CE8 002E0CE8 00000000 */   nop
    /* 1E0CEC 002E0CEC FFFF8632 */  andi       $6, $20, 0xFFFF
    /* 1E0CF0 002E0CF0 00788044 */  mtc1       $0, $f15
    /* 1E0CF4 002E0CF4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1E0CF8 002E0CF8 00808344 */  mtc1       $3, $f16
    /* 1E0CFC 002E0CFC 7800ACC7 */  lwc1       $f12, 0x78($29)
    /* 1E0D00 002E0D00 7C00ADC7 */  lwc1       $f13, 0x7C($29)
    /* 1E0D04 002E0D04 86A30046 */  mov.s      $f14, $f20
    /* 1E0D08 002E0D08 2D206002 */  daddu      $4, $19, $0
    /* 1E0D0C 002E0D0C 2D284002 */  daddu      $5, $18, $0
    /* 1E0D10 002E0D10 2D384000 */  daddu      $7, $2, $0
    /* 1E0D14 002E0D14 2D402002 */  daddu      $8, $17, $0
    /* 1E0D18 002E0D18 2D480000 */  daddu      $9, $0, $0
    /* 1E0D1C 002E0D1C 2D500000 */  daddu      $10, $0, $0
    /* 1E0D20 002E0D20 46840046 */  mov.s      $f17, $f16
    /* 1E0D24 002E0D24 2D580002 */  daddu      $11, $16, $0
    /* 1E0D28 002E0D28 347B090C */  jal        func_0025ecd0
    /* 1E0D2C 002E0D2C 00000000 */   nop
    /* 1E0D30 002E0D30 6000BFDF */  ld         $31, 0x60($29)
    /* 1E0D34 002E0D34 5000B47B */  lq         $20, 0x50($29)
    /* 1E0D38 002E0D38 4000B37B */  lq         $19, 0x40($29)
    /* 1E0D3C 002E0D3C 3000B27B */  lq         $18, 0x30($29)
    /* 1E0D40 002E0D40 2000B17B */  lq         $17, 0x20($29)
    /* 1E0D44 002E0D44 1000B07B */  lq         $16, 0x10($29)
    /* 1E0D48 002E0D48 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1E0D4C 002E0D4C 8000BD27 */  addiu      $29, $29, 0x80
    /* 1E0D50 002E0D50 0800E003 */  jr         $31
    /* 1E0D54 002E0D54 00000000 */   nop
    /* 1E0D58 002E0D58 00000000 */  nop
    /* 1E0D5C 002E0D5C 00000000 */  nop
.size func_002e0ca0, 0xc0

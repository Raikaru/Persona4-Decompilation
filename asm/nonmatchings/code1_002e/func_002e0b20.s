.section .text
.set noat
.set noreorder
glabel func_002e0b20
    /* 1E0B20 002E0B20 80FFBD27 */  addiu      $29, $29, -0x80
    /* 1E0B24 002E0B24 6000BFFF */  sd         $31, 0x60($29)
    /* 1E0B28 002E0B28 5000B47F */  sq         $20, 0x50($29)
    /* 1E0B2C 002E0B2C 4000B37F */  sq         $19, 0x40($29)
    /* 1E0B30 002E0B30 3000B27F */  sq         $18, 0x30($29)
    /* 1E0B34 002E0B34 2000B17F */  sq         $17, 0x20($29)
    /* 1E0B38 002E0B38 1000B07F */  sq         $16, 0x10($29)
    /* 1E0B3C 002E0B3C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1E0B40 002E0B40 2DA08000 */  daddu      $20, $4, $0
    /* 1E0B44 002E0B44 7800A5FF */  sd         $5, 0x78($29)
    /* 1E0B48 002E0B48 06650046 */  mov.s      $f20, $f12
    /* 1E0B4C 002E0B4C 2D98C000 */  daddu      $19, $6, $0
    /* 1E0B50 002E0B50 2D90E000 */  daddu      $18, $7, $0
    /* 1E0B54 002E0B54 2D880001 */  daddu      $17, $8, $0
    /* 1E0B58 002E0B58 2D802001 */  daddu      $16, $9, $0
    /* 1E0B5C 002E0B5C 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1E0B60 002E0B60 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1E0B64 002E0B64 DCA9110C */  jal        func_0046a770
    /* 1E0B68 002E0B68 00000000 */   nop
    /* 1E0B6C 002E0B6C FFFF8632 */  andi       $6, $20, 0xFFFF
    /* 1E0B70 002E0B70 00788044 */  mtc1       $0, $f15
    /* 1E0B74 002E0B74 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1E0B78 002E0B78 00808344 */  mtc1       $3, $f16
    /* 1E0B7C 002E0B7C 7800ACC7 */  lwc1       $f12, 0x78($29)
    /* 1E0B80 002E0B80 7C00ADC7 */  lwc1       $f13, 0x7C($29)
    /* 1E0B84 002E0B84 86A30046 */  mov.s      $f14, $f20
    /* 1E0B88 002E0B88 2D206002 */  daddu      $4, $19, $0
    /* 1E0B8C 002E0B8C 2D284002 */  daddu      $5, $18, $0
    /* 1E0B90 002E0B90 2D384000 */  daddu      $7, $2, $0
    /* 1E0B94 002E0B94 2D402002 */  daddu      $8, $17, $0
    /* 1E0B98 002E0B98 2D480000 */  daddu      $9, $0, $0
    /* 1E0B9C 002E0B9C 2D500000 */  daddu      $10, $0, $0
    /* 1E0BA0 002E0BA0 46840046 */  mov.s      $f17, $f16
    /* 1E0BA4 002E0BA4 2D580002 */  daddu      $11, $16, $0
    /* 1E0BA8 002E0BA8 347B090C */  jal        func_0025ecd0
    /* 1E0BAC 002E0BAC 00000000 */   nop
    /* 1E0BB0 002E0BB0 6000BFDF */  ld         $31, 0x60($29)
    /* 1E0BB4 002E0BB4 5000B47B */  lq         $20, 0x50($29)
    /* 1E0BB8 002E0BB8 4000B37B */  lq         $19, 0x40($29)
    /* 1E0BBC 002E0BBC 3000B27B */  lq         $18, 0x30($29)
    /* 1E0BC0 002E0BC0 2000B17B */  lq         $17, 0x20($29)
    /* 1E0BC4 002E0BC4 1000B07B */  lq         $16, 0x10($29)
    /* 1E0BC8 002E0BC8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1E0BCC 002E0BCC 8000BD27 */  addiu      $29, $29, 0x80
    /* 1E0BD0 002E0BD0 0800E003 */  jr         $31
    /* 1E0BD4 002E0BD4 00000000 */   nop
    /* 1E0BD8 002E0BD8 00000000 */  nop
    /* 1E0BDC 002E0BDC 00000000 */  nop
.size func_002e0b20, 0xc0

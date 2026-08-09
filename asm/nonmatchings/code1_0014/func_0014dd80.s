.section .text
.set noat
.set noreorder
glabel func_0014dd80
    /* 4DD80 0014DD80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4DD84 0014DD84 2000BFFF */  sd         $31, 0x20($29)
    /* 4DD88 0014DD88 1000B17F */  sq         $17, 0x10($29)
    /* 4DD8C 0014DD8C 0000B07F */  sq         $16, 0x0($29)
    /* 4DD90 0014DD90 2D88A000 */  daddu      $17, $5, $0
    /* 4DD94 0014DD94 8800103C */  lui        $16, %hi(D_00887300)
    /* 4DD98 0014DD98 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 4DD9C 0014DD9C 06000424 */  addiu      $4, $0, 0x6
    /* 4DDA0 0014DDA0 01000524 */  addiu      $5, $0, 0x1
    /* 4DDA4 0014DDA4 0000028E */  lw         $2, 0x0($16)
    /* 4DDA8 0014DDA8 09F84000 */  jalr       $2
    /* 4DDAC 0014DDAC 00000000 */   nop
    /* 4DDB0 0014DDB0 08000424 */  addiu      $4, $0, 0x8
    /* 4DDB4 0014DDB4 2D280000 */  daddu      $5, $0, $0
    /* 4DDB8 0014DDB8 0000028E */  lw         $2, 0x0($16)
    /* 4DDBC 0014DDBC 09F84000 */  jalr       $2
    /* 4DDC0 0014DDC0 00000000 */   nop
    /* 4DDC4 0014DDC4 07000424 */  addiu      $4, $0, 0x7
    /* 4DDC8 0014DDC8 02000524 */  addiu      $5, $0, 0x2
    /* 4DDCC 0014DDCC 0000028E */  lw         $2, 0x0($16)
    /* 4DDD0 0014DDD0 09F84000 */  jalr       $2
    /* 4DDD4 0014DDD4 00000000 */   nop
    /* 4DDD8 0014DDD8 09000424 */  addiu      $4, $0, 0x9
    /* 4DDDC 0014DDDC 02000524 */  addiu      $5, $0, 0x2
    /* 4DDE0 0014DDE0 0000028E */  lw         $2, 0x0($16)
    /* 4DDE4 0014DDE4 09F84000 */  jalr       $2
    /* 4DDE8 0014DDE8 00000000 */   nop
    /* 4DDEC 0014DDEC 0C000424 */  addiu      $4, $0, 0xC
    /* 4DDF0 0014DDF0 01000524 */  addiu      $5, $0, 0x1
    /* 4DDF4 0014DDF4 0000028E */  lw         $2, 0x0($16)
    /* 4DDF8 0014DDF8 09F84000 */  jalr       $2
    /* 4DDFC 0014DDFC 00000000 */   nop
    /* 4DE00 0014DE00 02000424 */  addiu      $4, $0, 0x2
    /* 4DE04 0014DE04 03000524 */  addiu      $5, $0, 0x3
    /* 4DE08 0014DE08 0000028E */  lw         $2, 0x0($16)
    /* 4DE0C 0014DE0C 09F84000 */  jalr       $2
    /* 4DE10 0014DE10 00000000 */   nop
    /* 4DE14 0014DE14 0C000424 */  addiu      $4, $0, 0xC
    /* 4DE18 0014DE18 01000524 */  addiu      $5, $0, 0x1
    /* 4DE1C 0014DE1C 0000028E */  lw         $2, 0x0($16)
    /* 4DE20 0014DE20 09F84000 */  jalr       $2
    /* 4DE24 0014DE24 00000000 */   nop
    /* 4DE28 0014DE28 02000424 */  addiu      $4, $0, 0x2
    /* 4DE2C 0014DE2C 44000524 */  addiu      $5, $0, 0x44
    /* 4DE30 0014DE30 10D90F0C */  jal        func_003f6440
    /* 4DE34 0014DE34 00000000 */   nop
    /* 4DE38 0014DE38 03000424 */  addiu      $4, $0, 0x3
    /* 4DE3C 0014DE3C 0700023C */  lui        $2, (0x717FB >> 16)
    /* 4DE40 0014DE40 FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* 4DE44 0014DE44 10D90F0C */  jal        func_003f6440
    /* 4DE48 0014DE48 00000000 */   nop
    /* 4DE4C 0014DE4C 0001228E */  lw         $2, 0x100($17)
    /* 4DE50 0014DE50 19004010 */  beqz       $2, .L0014DEB8
    /* 4DE54 0014DE54 00000000 */   nop
    /* 4DE58 0014DE58 080120C6 */  lwc1       $f0, 0x108($17)
    /* 4DE5C 0014DE5C 100020E6 */  swc1       $f0, 0x10($17)
    /* 4DE60 0014DE60 0C0120C6 */  lwc1       $f0, 0x10C($17)
    /* 4DE64 0014DE64 140020E6 */  swc1       $f0, 0x14($17)
    /* 4DE68 0014DE68 100120C6 */  lwc1       $f0, 0x110($17)
    /* 4DE6C 0014DE6C 500020E6 */  swc1       $f0, 0x50($17)
    /* 4DE70 0014DE70 0C0120C6 */  lwc1       $f0, 0x10C($17)
    /* 4DE74 0014DE74 540020E6 */  swc1       $f0, 0x54($17)
    /* 4DE78 0014DE78 080120C6 */  lwc1       $f0, 0x108($17)
    /* 4DE7C 0014DE7C 900020E6 */  swc1       $f0, 0x90($17)
    /* 4DE80 0014DE80 140120C6 */  lwc1       $f0, 0x114($17)
    /* 4DE84 0014DE84 940020E6 */  swc1       $f0, 0x94($17)
    /* 4DE88 0014DE88 100120C6 */  lwc1       $f0, 0x110($17)
    /* 4DE8C 0014DE8C D00020E6 */  swc1       $f0, 0xD0($17)
    /* 4DE90 0014DE90 140120C6 */  lwc1       $f0, 0x114($17)
    /* 4DE94 0014DE94 D40020E6 */  swc1       $f0, 0xD4($17)
    /* 4DE98 0014DE98 0001228E */  lw         $2, 0x100($17)
    /* 4DE9C 0014DE9C 01000424 */  addiu      $4, $0, 0x1
    /* 4DEA0 0014DEA0 0000458C */  lw         $5, 0x0($2)
    /* 4DEA4 0014DEA4 0000028E */  lw         $2, 0x0($16)
    /* 4DEA8 0014DEA8 09F84000 */  jalr       $2
    /* 4DEAC 0014DEAC 00000000 */   nop
    /* 4DEB0 0014DEB0 06000010 */  b          .L0014DECC
    /* 4DEB4 0014DEB4 00000000 */   nop
  .L0014DEB8:
    /* 4DEB8 0014DEB8 01000424 */  addiu      $4, $0, 0x1
    /* 4DEBC 0014DEBC 2D280000 */  daddu      $5, $0, $0
    /* 4DEC0 0014DEC0 0000028E */  lw         $2, 0x0($16)
    /* 4DEC4 0014DEC4 09F84000 */  jalr       $2
    /* 4DEC8 0014DEC8 00000000 */   nop
  .L0014DECC:
    /* 4DECC 0014DECC 2000BFDF */  ld         $31, 0x20($29)
    /* 4DED0 0014DED0 1000B17B */  lq         $17, 0x10($29)
    /* 4DED4 0014DED4 0000B07B */  lq         $16, 0x0($29)
    /* 4DED8 0014DED8 3000BD27 */  addiu      $29, $29, 0x30
    /* 4DEDC 0014DEDC 0800E003 */  jr         $31
    /* 4DEE0 0014DEE0 00000000 */   nop
    /* 4DEE4 0014DEE4 00000000 */  nop
    /* 4DEE8 0014DEE8 00000000 */  nop
    /* 4DEEC 0014DEEC 00000000 */  nop
.size func_0014dd80, 0x170

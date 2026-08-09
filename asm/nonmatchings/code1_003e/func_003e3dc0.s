.section .text
.set noat
.set noreorder
glabel func_003e3dc0
    /* 2E3DC0 003E3DC0 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2E3DC4 003E3DC4 2D108000 */  daddu      $2, $4, $0
    /* 2E3DC8 003E3DC8 0400C2C4 */  lwc1       $f2, 0x4($6)
    /* 2E3DCC 003E3DCC 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2E3DD0 003E3DD0 0000C4C4 */  lwc1       $f4, 0x0($6)
    /* 2E3DD4 003E3DD4 0400A6C4 */  lwc1       $f6, 0x4($5)
    /* 2E3DD8 003E3DD8 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2E3DDC 003E3DDC 00408044 */  mtc1       $0, $f8
    /* 2E3DE0 003E3DE0 82280246 */  mul.s      $f2, $f5, $f2
    /* 2E3DE4 003E3DE4 1A280446 */  mula.s     $f5, $f4
    /* 2E3DE8 003E3DE8 822A0146 */  mul.s      $f10, $f5, $f1
    /* 2E3DEC 003E3DEC 5C320046 */  madd.s     $f9, $f6, $f0
    /* 2E3DF0 003E3DF0 18400246 */  adda.s     $f8, $f2
    /* 2E3DF4 003E3DF4 1400C5C4 */  lwc1       $f5, 0x14($6)
    /* 2E3DF8 003E3DF8 1800C4C4 */  lwc1       $f4, 0x18($6)
    /* 2E3DFC 003E3DFC 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2E3E00 003E3E00 2000C2C4 */  lwc1       $f2, 0x20($6)
    /* 2E3E04 003E3E04 2400C1C4 */  lwc1       $f1, 0x24($6)
    /* 2E3E08 003E3E08 2800C0C4 */  lwc1       $f0, 0x28($6)
    /* 2E3E0C 003E3E0C DC310546 */  madd.s     $f7, $f6, $f5
    /* 2E3E10 003E3E10 18400A46 */  adda.s     $f8, $f10
    /* 2E3E14 003E3E14 9C310446 */  madd.s     $f6, $f6, $f4
    /* 2E3E18 003E3E18 18400946 */  adda.s     $f8, $f9
    /* 2E3E1C 003E3E1C 5C190246 */  madd.s     $f5, $f3, $f2
    /* 2E3E20 003E3E20 18400746 */  adda.s     $f8, $f7
    /* 2E3E24 003E3E24 1C190146 */  madd.s     $f4, $f3, $f1
    /* 2E3E28 003E3E28 18400646 */  adda.s     $f8, $f6
    /* 2E3E2C 003E3E2C 3000C2C4 */  lwc1       $f2, 0x30($6)
    /* 2E3E30 003E3E30 DC180046 */  madd.s     $f3, $f3, $f0
    /* 2E3E34 003E3E34 3400C1C4 */  lwc1       $f1, 0x34($6)
    /* 2E3E38 003E3E38 3800C0C4 */  lwc1       $f0, 0x38($6)
    /* 2E3E3C 003E3E3C 80280246 */  add.s      $f2, $f5, $f2
    /* 2E3E40 003E3E40 40200146 */  add.s      $f1, $f4, $f1
    /* 2E3E44 003E3E44 000082E4 */  swc1       $f2, 0x0($4)
    /* 2E3E48 003E3E48 00180046 */  add.s      $f0, $f3, $f0
    /* 2E3E4C 003E3E4C 040081E4 */  swc1       $f1, 0x4($4)
    /* 2E3E50 003E3E50 0800E003 */  jr         $31
    /* 2E3E54 003E3E54 080080E4 */   swc1      $f0, 0x8($4)
    /* 2E3E58 003E3E58 00000000 */  nop
    /* 2E3E5C 003E3E5C 00000000 */  nop
.size func_003e3dc0, 0xa0

.section .text
.set noat
.set noreorder
glabel func_003b4ab0
    /* 2B4AB0 003B4AB0 700005C5 */  lwc1       $f5, 0x70($8)
    /* 2B4AB4 003B4AB4 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2B4AB8 003B4AB8 00308344 */  mtc1       $3, $f6
    /* 2B4ABC 003B4ABC 04000B8D */  lw         $11, 0x4($8)
    /* 2B4AC0 003B4AC0 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2B4AC4 003B4AC4 0800098D */  lw         $9, 0x8($8)
    /* 2B4AC8 003B4AC8 740001C5 */  lwc1       $f1, 0x74($8)
    /* 2B4ACC 003B4ACC 00008A8C */  lw         $10, 0x0($4)
    /* 2B4AD0 003B4AD0 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2B4AD4 003B4AD4 2A080700 */  slt        $1, $0, $7
    /* 2B4AD8 003B4AD8 0000A4C4 */  lwc1       $f4, 0x0($5)
    /* 2B4ADC 003B4ADC 2D600000 */  daddu      $12, $0, $0
    /* 2B4AE0 003B4AE0 42310546 */  mul.s      $f5, $f6, $f5
    /* 2B4AE4 003B4AE4 0400888C */  lw         $8, 0x4($4)
    /* 2B4AE8 003B4AE8 02130546 */  mul.s      $f12, $f2, $f5
    /* 2B4AEC 003B4AEC C2190546 */  mul.s      $f7, $f3, $f5
    /* 2B4AF0 003B4AF0 0000C0C4 */  lwc1       $f0, 0x0($6)
    /* 2B4AF4 003B4AF4 82310146 */  mul.s      $f6, $f6, $f1
    /* 2B4AF8 003B4AF8 42230546 */  mul.s      $f13, $f4, $f5
    /* 2B4AFC 003B4AFC 0800C2C4 */  lwc1       $f2, 0x8($6)
    /* 2B4B00 003B4B00 0400C3C4 */  lwc1       $f3, 0x4($6)
    /* 2B4B04 003B4B04 02010646 */  mul.s      $f4, $f0, $f6
    /* 2B4B08 003B4B08 47680046 */  neg.s      $f1, $f13
    /* 2B4B0C 003B4B0C 02120646 */  mul.s      $f8, $f2, $f6
    /* 2B4B10 003B4B10 42190646 */  mul.s      $f5, $f3, $f6
    /* 2B4B14 003B4B14 87380046 */  neg.s      $f2, $f7
    /* 2B4B18 003B4B18 C7600046 */  neg.s      $f3, $f12
    /* 2B4B1C 003B4B1C 01080446 */  sub.s      $f0, $f1, $f4
    /* 2B4B20 003B4B20 400A0446 */  add.s      $f9, $f1, $f4
    /* 2B4B24 003B4B24 41100546 */  sub.s      $f1, $f2, $f5
    /* 2B4B28 003B4B28 80120546 */  add.s      $f10, $f2, $f5
    /* 2B4B2C 003B4B2C 81180846 */  sub.s      $f2, $f3, $f8
    /* 2B4B30 003B4B30 C01A0846 */  add.s      $f11, $f3, $f8
    /* 2B4B34 003B4B34 C1680446 */  sub.s      $f3, $f13, $f4
    /* 2B4B38 003B4B38 80690446 */  add.s      $f6, $f13, $f4
    /* 2B4B3C 003B4B3C 01390546 */  sub.s      $f4, $f7, $f5
    /* 2B4B40 003B4B40 C0390546 */  add.s      $f7, $f7, $f5
    /* 2B4B44 003B4B44 41610846 */  sub.s      $f5, $f12, $f8
    /* 2B4B48 003B4B48 2D002010 */  beqz       $1, .L003B4C00
    /* 2B4B4C 003B4B4C 00620846 */   add.s     $f8, $f12, $f8
  .L003B4B50:
    /* 2B4B50 003B4B50 00006CC5 */  lwc1       $f12, 0x0($11)
    /* 2B4B54 003B4B54 21304801 */  addu       $6, $10, $8
    /* 2B4B58 003B4B58 2128C800 */  addu       $5, $6, $8
    /* 2B4B5C 003B4B5C 01008C25 */  addiu      $12, $12, 0x1
    /* 2B4B60 003B4B60 2120A800 */  addu       $4, $5, $8
    /* 2B4B64 003B4B64 2A188701 */  slt        $3, $12, $7
    /* 2B4B68 003B4B68 00630046 */  add.s      $f12, $f12, $f0
    /* 2B4B6C 003B4B6C 00004CE5 */  swc1       $f12, 0x0($10)
    /* 2B4B70 003B4B70 04006CC5 */  lwc1       $f12, 0x4($11)
    /* 2B4B74 003B4B74 00630146 */  add.s      $f12, $f12, $f1
    /* 2B4B78 003B4B78 04004CE5 */  swc1       $f12, 0x4($10)
    /* 2B4B7C 003B4B7C 08006CC5 */  lwc1       $f12, 0x8($11)
    /* 2B4B80 003B4B80 00630246 */  add.s      $f12, $f12, $f2
    /* 2B4B84 003B4B84 08004CE5 */  swc1       $f12, 0x8($10)
    /* 2B4B88 003B4B88 00006CC5 */  lwc1       $f12, 0x0($11)
    /* 2B4B8C 003B4B8C 21508800 */  addu       $10, $4, $8
    /* 2B4B90 003B4B90 00630346 */  add.s      $f12, $f12, $f3
    /* 2B4B94 003B4B94 0000CCE4 */  swc1       $f12, 0x0($6)
    /* 2B4B98 003B4B98 04006CC5 */  lwc1       $f12, 0x4($11)
    /* 2B4B9C 003B4B9C 00630446 */  add.s      $f12, $f12, $f4
    /* 2B4BA0 003B4BA0 0400CCE4 */  swc1       $f12, 0x4($6)
    /* 2B4BA4 003B4BA4 08006CC5 */  lwc1       $f12, 0x8($11)
    /* 2B4BA8 003B4BA8 00630546 */  add.s      $f12, $f12, $f5
    /* 2B4BAC 003B4BAC 0800CCE4 */  swc1       $f12, 0x8($6)
    /* 2B4BB0 003B4BB0 00006CC5 */  lwc1       $f12, 0x0($11)
    /* 2B4BB4 003B4BB4 00630646 */  add.s      $f12, $f12, $f6
    /* 2B4BB8 003B4BB8 0000ACE4 */  swc1       $f12, 0x0($5)
    /* 2B4BBC 003B4BBC 04006CC5 */  lwc1       $f12, 0x4($11)
    /* 2B4BC0 003B4BC0 00630746 */  add.s      $f12, $f12, $f7
    /* 2B4BC4 003B4BC4 0400ACE4 */  swc1       $f12, 0x4($5)
    /* 2B4BC8 003B4BC8 08006CC5 */  lwc1       $f12, 0x8($11)
    /* 2B4BCC 003B4BCC 00630846 */  add.s      $f12, $f12, $f8
    /* 2B4BD0 003B4BD0 0800ACE4 */  swc1       $f12, 0x8($5)
    /* 2B4BD4 003B4BD4 00006CC5 */  lwc1       $f12, 0x0($11)
    /* 2B4BD8 003B4BD8 00630946 */  add.s      $f12, $f12, $f9
    /* 2B4BDC 003B4BDC 00008CE4 */  swc1       $f12, 0x0($4)
    /* 2B4BE0 003B4BE0 04006CC5 */  lwc1       $f12, 0x4($11)
    /* 2B4BE4 003B4BE4 00630A46 */  add.s      $f12, $f12, $f10
    /* 2B4BE8 003B4BE8 04008CE4 */  swc1       $f12, 0x4($4)
    /* 2B4BEC 003B4BEC 08006CC5 */  lwc1       $f12, 0x8($11)
    /* 2B4BF0 003B4BF0 00630B46 */  add.s      $f12, $f12, $f11
    /* 2B4BF4 003B4BF4 21586901 */  addu       $11, $11, $9
    /* 2B4BF8 003B4BF8 D5FF6014 */  bnez       $3, .L003B4B50
    /* 2B4BFC 003B4BFC 08008CE4 */   swc1      $f12, 0x8($4)
  .L003B4C00:
    /* 2B4C00 003B4C00 0800E003 */  jr         $31
    /* 2B4C04 003B4C04 00000000 */   nop
    /* 2B4C08 003B4C08 00000000 */  nop
    /* 2B4C0C 003B4C0C 00000000 */  nop
.size func_003b4ab0, 0x160

.section .text
.set noat
.set noreorder
glabel func_003b5bf0
    /* 2B5BF0 003B5BF0 680002C5 */  lwc1       $f2, 0x68($8)
    /* 2B5BF4 003B5BF4 0C000A8D */  lw         $10, 0xC($8)
    /* 2B5BF8 003B5BF8 6C0001C5 */  lwc1       $f1, 0x6C($8)
    /* 2B5BFC 003B5BFC 00008B8C */  lw         $11, 0x0($4)
    /* 2B5C00 003B5C00 0400898C */  lw         $9, 0x4($4)
    /* 2B5C04 003B5C04 2A080700 */  slt        $1, $0, $7
    /* 2B5C08 003B5C08 1000088D */  lw         $8, 0x10($8)
    /* 2B5C0C 003B5C0C 42002010 */  beqz       $1, .L003B5D18
    /* 2B5C10 003B5C10 2D600000 */   daddu     $12, $0, $0
    /* 2B5C14 003B5C14 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2B5C18 003B5C18 00008344 */  mtc1       $3, $f0
    /* 2B5C1C 003B5C1C 00608044 */  mtc1       $0, $f12
  .L003B5C20:
    /* 2B5C20 003B5C20 300043C5 */  lwc1       $f3, 0x30($10)
    /* 2B5C24 003B5C24 21306901 */  addu       $6, $11, $9
    /* 2B5C28 003B5C28 100046C5 */  lwc1       $f6, 0x10($10)
    /* 2B5C2C 003B5C2C 2128C900 */  addu       $5, $6, $9
    /* 2B5C30 003B5C30 000045C5 */  lwc1       $f5, 0x0($10)
    /* 2B5C34 003B5C34 01008C25 */  addiu      $12, $12, 0x1
    /* 2B5C38 003B5C38 140050C5 */  lwc1       $f16, 0x14($10)
    /* 2B5C3C 003B5C3C 2120A900 */  addu       $4, $5, $9
    /* 2B5C40 003B5C40 04004AC5 */  lwc1       $f10, 0x4($10)
    /* 2B5C44 003B5C44 2A188701 */  slt        $3, $12, $7
    /* 2B5C48 003B5C48 18004EC5 */  lwc1       $f14, 0x18($10)
    /* 2B5C4C 003B5C4C 18600346 */  adda.s     $f12, $f3
    /* 2B5C50 003B5C50 080049C5 */  lwc1       $f9, 0x8($10)
    /* 2B5C54 003B5C54 C1280646 */  sub.s      $f3, $f5, $f6
    /* 2B5C58 003B5C58 02020346 */  mul.s      $f8, $f0, $f3
    /* 2B5C5C 003B5C5C C0501046 */  add.s      $f3, $f10, $f16
    /* 2B5C60 003B5C60 C2030346 */  mul.s      $f15, $f0, $f3
    /* 2B5C64 003B5C64 C0480E46 */  add.s      $f3, $f9, $f14
    /* 2B5C68 003B5C68 42030346 */  mul.s      $f13, $f0, $f3
    /* 2B5C6C 003B5C6C C1501046 */  sub.s      $f3, $f10, $f16
    /* 2B5C70 003B5C70 C2010346 */  mul.s      $f7, $f0, $f3
    /* 2B5C74 003B5C74 00290646 */  add.s      $f4, $f5, $f6
    /* 2B5C78 003B5C78 1E280246 */  madda.s    $f5, $f2
    /* 2B5C7C 003B5C7C 42040446 */  mul.s      $f17, $f0, $f4
    /* 2B5C80 003B5C80 C1480E46 */  sub.s      $f3, $f9, $f14
    /* 2B5C84 003B5C84 DC320146 */  madd.s     $f11, $f6, $f1
    /* 2B5C88 003B5C88 82010346 */  mul.s      $f6, $f0, $f3
    /* 2B5C8C 003B5C8C 340045C5 */  lwc1       $f5, 0x34($10)
    /* 2B5C90 003B5C90 380044C5 */  lwc1       $f4, 0x38($10)
    /* 2B5C94 003B5C94 C0580846 */  add.s      $f3, $f11, $f8
    /* 2B5C98 003B5C98 18600546 */  adda.s     $f12, $f5
    /* 2B5C9C 003B5C9C 1E500246 */  madda.s    $f10, $f2
    /* 2B5CA0 003B5CA0 21504801 */  addu       $10, $10, $8
    /* 2B5CA4 003B5CA4 9C820146 */  madd.s     $f10, $f16, $f1
    /* 2B5CA8 003B5CA8 18600446 */  adda.s     $f12, $f4
    /* 2B5CAC 003B5CAC 000063E5 */  swc1       $f3, 0x0($11)
    /* 2B5CB0 003B5CB0 C0500746 */  add.s      $f3, $f10, $f7
    /* 2B5CB4 003B5CB4 1E480246 */  madda.s    $f9, $f2
    /* 2B5CB8 003B5CB8 5C720146 */  madd.s     $f9, $f14, $f1
    /* 2B5CBC 003B5CBC 040063E5 */  swc1       $f3, 0x4($11)
    /* 2B5CC0 003B5CC0 C0480646 */  add.s      $f3, $f9, $f6
    /* 2B5CC4 003B5CC4 080063E5 */  swc1       $f3, 0x8($11)
    /* 2B5CC8 003B5CC8 C1581146 */  sub.s      $f3, $f11, $f17
    /* 2B5CCC 003B5CCC 21588900 */  addu       $11, $4, $9
    /* 2B5CD0 003B5CD0 0000C3E4 */  swc1       $f3, 0x0($6)
    /* 2B5CD4 003B5CD4 C1500F46 */  sub.s      $f3, $f10, $f15
    /* 2B5CD8 003B5CD8 0400C3E4 */  swc1       $f3, 0x4($6)
    /* 2B5CDC 003B5CDC C1480D46 */  sub.s      $f3, $f9, $f13
    /* 2B5CE0 003B5CE0 0800C3E4 */  swc1       $f3, 0x8($6)
    /* 2B5CE4 003B5CE4 015A0846 */  sub.s      $f8, $f11, $f8
    /* 2B5CE8 003B5CE8 C1510746 */  sub.s      $f7, $f10, $f7
    /* 2B5CEC 003B5CEC 0000A8E4 */  swc1       $f8, 0x0($5)
    /* 2B5CF0 003B5CF0 81490646 */  sub.s      $f6, $f9, $f6
    /* 2B5CF4 003B5CF4 0400A7E4 */  swc1       $f7, 0x4($5)
    /* 2B5CF8 003B5CF8 40591146 */  add.s      $f5, $f11, $f17
    /* 2B5CFC 003B5CFC 0800A6E4 */  swc1       $f6, 0x8($5)
    /* 2B5D00 003B5D00 00510F46 */  add.s      $f4, $f10, $f15
    /* 2B5D04 003B5D04 000085E4 */  swc1       $f5, 0x0($4)
    /* 2B5D08 003B5D08 C0480D46 */  add.s      $f3, $f9, $f13
    /* 2B5D0C 003B5D0C 040084E4 */  swc1       $f4, 0x4($4)
    /* 2B5D10 003B5D10 C3FF6014 */  bnez       $3, .L003B5C20
    /* 2B5D14 003B5D14 080083E4 */   swc1      $f3, 0x8($4)
  .L003B5D18:
    /* 2B5D18 003B5D18 0800E003 */  jr         $31
    /* 2B5D1C 003B5D1C 00000000 */   nop
.size func_003b5bf0, 0x130

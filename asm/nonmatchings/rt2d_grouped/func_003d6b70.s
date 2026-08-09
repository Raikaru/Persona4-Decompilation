.section .text
.set noat
.set noreorder
glabel func_003d6b70
    /* 2D6B70 003D6B70 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2D6B74 003D6B74 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2D6B78 003D6B78 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2D6B7C 003D6B7C 0800C2C4 */  lwc1       $f2, 0x8($6)
    /* 2D6B80 003D6B80 1A080046 */  mula.s     $f1, $f0
    /* 2D6B84 003D6B84 1C180246 */  madd.s     $f0, $f3, $f2
    /* 2D6B88 003D6B88 080080E4 */  swc1       $f0, 0x8($4)
    /* 2D6B8C 003D6B8C 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2D6B90 003D6B90 1400C0C4 */  lwc1       $f0, 0x14($6)
    /* 2D6B94 003D6B94 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2D6B98 003D6B98 0C00C2C4 */  lwc1       $f2, 0xC($6)
    /* 2D6B9C 003D6B9C 1A080046 */  mula.s     $f1, $f0
    /* 2D6BA0 003D6BA0 1C180246 */  madd.s     $f0, $f3, $f2
    /* 2D6BA4 003D6BA4 0C0080E4 */  swc1       $f0, 0xC($4)
    /* 2D6BA8 003D6BA8 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* 2D6BAC 003D6BAC 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2D6BB0 003D6BB0 1000A3C4 */  lwc1       $f3, 0x10($5)
    /* 2D6BB4 003D6BB4 0800C2C4 */  lwc1       $f2, 0x8($6)
    /* 2D6BB8 003D6BB8 1A080046 */  mula.s     $f1, $f0
    /* 2D6BBC 003D6BBC 1C180246 */  madd.s     $f0, $f3, $f2
    /* 2D6BC0 003D6BC0 100080E4 */  swc1       $f0, 0x10($4)
    /* 2D6BC4 003D6BC4 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* 2D6BC8 003D6BC8 1400C0C4 */  lwc1       $f0, 0x14($6)
    /* 2D6BCC 003D6BCC 1000A3C4 */  lwc1       $f3, 0x10($5)
    /* 2D6BD0 003D6BD0 0C00C2C4 */  lwc1       $f2, 0xC($6)
    /* 2D6BD4 003D6BD4 1A080046 */  mula.s     $f1, $f0
    /* 2D6BD8 003D6BD8 1C180246 */  madd.s     $f0, $f3, $f2
    /* 2D6BDC 003D6BDC 140080E4 */  swc1       $f0, 0x14($4)
    /* 2D6BE0 003D6BE0 1800A1C4 */  lwc1       $f1, 0x18($5)
    /* 2D6BE4 003D6BE4 1800C0C4 */  lwc1       $f0, 0x18($6)
    /* 2D6BE8 003D6BE8 00080046 */  add.s      $f0, $f1, $f0
    /* 2D6BEC 003D6BEC 180080E4 */  swc1       $f0, 0x18($4)
    /* 2D6BF0 003D6BF0 1C00A1C4 */  lwc1       $f1, 0x1C($5)
    /* 2D6BF4 003D6BF4 1C00C0C4 */  lwc1       $f0, 0x1C($6)
    /* 2D6BF8 003D6BF8 00080046 */  add.s      $f0, $f1, $f0
    /* 2D6BFC 003D6BFC 0800E003 */  jr         $31
    /* 2D6C00 003D6C00 1C0080E4 */   swc1      $f0, 0x1C($4)
    /* 2D6C04 003D6C04 00000000 */  nop
    /* 2D6C08 003D6C08 00000000 */  nop
    /* 2D6C0C 003D6C0C 00000000 */  nop
.size func_003d6b70, 0xa0

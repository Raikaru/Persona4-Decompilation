.section .text
.set noat
.set noreorder
glabel func_003d6a00
    /* 2D6A00 003D6A00 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2D6A04 003D6A04 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2D6A08 003D6A08 00108044 */  mtc1       $0, $f2
    /* 2D6A0C 003D6A0C 00000000 */  nop
    /* 2D6A10 003D6A10 18100146 */  adda.s     $f2, $f1
    /* 2D6A14 003D6A14 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A18 003D6A18 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A1C 003D6A1C 080080E4 */  swc1       $f0, 0x8($4)
    /* 2D6A20 003D6A20 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2D6A24 003D6A24 0C00C0C4 */  lwc1       $f0, 0xC($6)
    /* 2D6A28 003D6A28 18100146 */  adda.s     $f2, $f1
    /* 2D6A2C 003D6A2C 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A30 003D6A30 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A34 003D6A34 0C0080E4 */  swc1       $f0, 0xC($4)
    /* 2D6A38 003D6A38 1000A1C4 */  lwc1       $f1, 0x10($5)
    /* 2D6A3C 003D6A3C 1000C0C4 */  lwc1       $f0, 0x10($6)
    /* 2D6A40 003D6A40 18100146 */  adda.s     $f2, $f1
    /* 2D6A44 003D6A44 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A48 003D6A48 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A4C 003D6A4C 100080E4 */  swc1       $f0, 0x10($4)
    /* 2D6A50 003D6A50 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* 2D6A54 003D6A54 1400C0C4 */  lwc1       $f0, 0x14($6)
    /* 2D6A58 003D6A58 18100146 */  adda.s     $f2, $f1
    /* 2D6A5C 003D6A5C 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A60 003D6A60 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A64 003D6A64 140080E4 */  swc1       $f0, 0x14($4)
    /* 2D6A68 003D6A68 1800A1C4 */  lwc1       $f1, 0x18($5)
    /* 2D6A6C 003D6A6C 1800C0C4 */  lwc1       $f0, 0x18($6)
    /* 2D6A70 003D6A70 18100146 */  adda.s     $f2, $f1
    /* 2D6A74 003D6A74 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A78 003D6A78 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A7C 003D6A7C 180080E4 */  swc1       $f0, 0x18($4)
    /* 2D6A80 003D6A80 1C00A1C4 */  lwc1       $f1, 0x1C($5)
    /* 2D6A84 003D6A84 1C00C0C4 */  lwc1       $f0, 0x1C($6)
    /* 2D6A88 003D6A88 18100146 */  adda.s     $f2, $f1
    /* 2D6A8C 003D6A8C 01000146 */  sub.s      $f0, $f0, $f1
    /* 2D6A90 003D6A90 1C600046 */  madd.s     $f0, $f12, $f0
    /* 2D6A94 003D6A94 0800E003 */  jr         $31
    /* 2D6A98 003D6A98 1C0080E4 */   swc1      $f0, 0x1C($4)
    /* 2D6A9C 003D6A9C 00000000 */  nop
.size func_003d6a00, 0xa0

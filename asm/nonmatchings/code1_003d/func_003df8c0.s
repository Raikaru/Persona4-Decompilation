.section .text
.set noat
.set noreorder
glabel func_003df8c0
    /* 2DF8C0 003DF8C0 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2DF8C4 003DF8C4 1000D0C4 */  lwc1       $f16, 0x10($6)
    /* 2DF8C8 003DF8C8 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2DF8CC 003DF8CC 0000D1C4 */  lwc1       $f17, 0x0($6)
    /* 2DF8D0 003DF8D0 0800A6C4 */  lwc1       $f6, 0x8($5)
    /* 2DF8D4 003DF8D4 2000D2C4 */  lwc1       $f18, 0x20($6)
    /* 2DF8D8 003DF8D8 1400CDC4 */  lwc1       $f13, 0x14($6)
    /* 2DF8DC 003DF8DC 1A201046 */  mula.s     $f4, $f16
    /* 2DF8E0 003DF8E0 0400CEC4 */  lwc1       $f14, 0x4($6)
    /* 2DF8E4 003DF8E4 1E281146 */  madda.s    $f5, $f17
    /* 2DF8E8 003DF8E8 2400CFC4 */  lwc1       $f15, 0x24($6)
    /* 2DF8EC 003DF8EC 1C301246 */  madd.s     $f0, $f6, $f18
    /* 2DF8F0 003DF8F0 1A200D46 */  mula.s     $f4, $f13
    /* 2DF8F4 003DF8F4 1800CAC4 */  lwc1       $f10, 0x18($6)
    /* 2DF8F8 003DF8F8 0800CBC4 */  lwc1       $f11, 0x8($6)
    /* 2DF8FC 003DF8FC 2800CCC4 */  lwc1       $f12, 0x28($6)
    /* 2DF900 003DF900 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* 2DF904 003DF904 000080E4 */  swc1       $f0, 0x0($4)
    /* 2DF908 003DF908 1E280E46 */  madda.s    $f5, $f14
    /* 2DF90C 003DF90C 1C300F46 */  madd.s     $f0, $f6, $f15
    /* 2DF910 003DF910 1A200A46 */  mula.s     $f4, $f10
    /* 2DF914 003DF914 1E280B46 */  madda.s    $f5, $f11
    /* 2DF918 003DF918 040080E4 */  swc1       $f0, 0x4($4)
    /* 2DF91C 003DF91C 1C300C46 */  madd.s     $f0, $f6, $f12
    /* 2DF920 003DF920 1000A2C4 */  lwc1       $f2, 0x10($5)
    /* 2DF924 003DF924 1A081046 */  mula.s     $f1, $f16
    /* 2DF928 003DF928 1800A3C4 */  lwc1       $f3, 0x18($5)
    /* 2DF92C 003DF92C 080080E4 */  swc1       $f0, 0x8($4)
    /* 2DF930 003DF930 2400A7C4 */  lwc1       $f7, 0x24($5)
    /* 2DF934 003DF934 2000A8C4 */  lwc1       $f8, 0x20($5)
    /* 2DF938 003DF938 1E101146 */  madda.s    $f2, $f17
    /* 2DF93C 003DF93C 2800A9C4 */  lwc1       $f9, 0x28($5)
    /* 2DF940 003DF940 1C181246 */  madd.s     $f0, $f3, $f18
    /* 2DF944 003DF944 1A080D46 */  mula.s     $f1, $f13
    /* 2DF948 003DF948 100080E4 */  swc1       $f0, 0x10($4)
    /* 2DF94C 003DF94C 1E100E46 */  madda.s    $f2, $f14
    /* 2DF950 003DF950 1C180F46 */  madd.s     $f0, $f3, $f15
    /* 2DF954 003DF954 1A080A46 */  mula.s     $f1, $f10
    /* 2DF958 003DF958 1E100B46 */  madda.s    $f2, $f11
    /* 2DF95C 003DF95C 140080E4 */  swc1       $f0, 0x14($4)
    /* 2DF960 003DF960 1C180C46 */  madd.s     $f0, $f3, $f12
    /* 2DF964 003DF964 1A381046 */  mula.s     $f7, $f16
    /* 2DF968 003DF968 1E401146 */  madda.s    $f8, $f17
    /* 2DF96C 003DF96C DC481246 */  madd.s     $f3, $f9, $f18
    /* 2DF970 003DF970 180080E4 */  swc1       $f0, 0x18($4)
    /* 2DF974 003DF974 1A380D46 */  mula.s     $f7, $f13
    /* 2DF978 003DF978 3400A4C4 */  lwc1       $f4, 0x34($5)
    /* 2DF97C 003DF97C 3000A5C4 */  lwc1       $f5, 0x30($5)
    /* 2DF980 003DF980 200083E4 */  swc1       $f3, 0x20($4)
    /* 2DF984 003DF984 1E400E46 */  madda.s    $f8, $f14
    /* 2DF988 003DF988 DC480F46 */  madd.s     $f3, $f9, $f15
    /* 2DF98C 003DF98C 1A380A46 */  mula.s     $f7, $f10
    /* 2DF990 003DF990 3800A6C4 */  lwc1       $f6, 0x38($5)
    /* 2DF994 003DF994 3000C2C4 */  lwc1       $f2, 0x30($6)
    /* 2DF998 003DF998 240083E4 */  swc1       $f3, 0x24($4)
    /* 2DF99C 003DF99C 1E400B46 */  madda.s    $f8, $f11
    /* 2DF9A0 003DF9A0 DC480C46 */  madd.s     $f3, $f9, $f12
    /* 2DF9A4 003DF9A4 1A201046 */  mula.s     $f4, $f16
    /* 2DF9A8 003DF9A8 280083E4 */  swc1       $f3, 0x28($4)
    /* 2DF9AC 003DF9AC 1E281146 */  madda.s    $f5, $f17
    /* 2DF9B0 003DF9B0 DC301246 */  madd.s     $f3, $f6, $f18
    /* 2DF9B4 003DF9B4 80100346 */  add.s      $f2, $f2, $f3
    /* 2DF9B8 003DF9B8 1A200D46 */  mula.s     $f4, $f13
    /* 2DF9BC 003DF9BC 3400C1C4 */  lwc1       $f1, 0x34($6)
    /* 2DF9C0 003DF9C0 300082E4 */  swc1       $f2, 0x30($4)
    /* 2DF9C4 003DF9C4 1E280E46 */  madda.s    $f5, $f14
    /* 2DF9C8 003DF9C8 9C300F46 */  madd.s     $f2, $f6, $f15
    /* 2DF9CC 003DF9CC 1A200A46 */  mula.s     $f4, $f10
    /* 2DF9D0 003DF9D0 3800C0C4 */  lwc1       $f0, 0x38($6)
    /* 2DF9D4 003DF9D4 80080246 */  add.s      $f2, $f1, $f2
    /* 2DF9D8 003DF9D8 1E280B46 */  madda.s    $f5, $f11
    /* 2DF9DC 003DF9DC 5C300C46 */  madd.s     $f1, $f6, $f12
    /* 2DF9E0 003DF9E0 00000146 */  add.s      $f0, $f0, $f1
    /* 2DF9E4 003DF9E4 340082E4 */  swc1       $f2, 0x34($4)
    /* 2DF9E8 003DF9E8 0800E003 */  jr         $31
    /* 2DF9EC 003DF9EC 380080E4 */   swc1      $f0, 0x38($4)
.size func_003df8c0, 0x130

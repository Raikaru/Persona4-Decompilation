.section .text
.set noat
.set noreorder
glabel func_0036deb0
    /* 26DEB0 0036DEB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26DEB4 0036DEB4 0000BFFF */  sd         $31, 0x0($29)
    /* 26DEB8 0036DEB8 1000A527 */  addiu      $5, $29, 0x10
    /* 26DEBC 0036DEBC 78AD0D0C */  jal        func_0036b5e0
    /* 26DEC0 0036DEC0 00000000 */   nop
    /* 26DEC4 0036DEC4 BC8381C7 */  lwc1       $f1, -0x7C44($28)
    /* 26DEC8 0036DEC8 1400A0C7 */  lwc1       $f0, 0x14($29)
    /* 26DECC 0036DECC 02080046 */  mul.s      $f0, $f1, $f0
    /* 26DED0 0036DED0 0000BFDF */  ld         $31, 0x0($29)
    /* 26DED4 0036DED4 2000BD27 */  addiu      $29, $29, 0x20
    /* 26DED8 0036DED8 0800E003 */  jr         $31
    /* 26DEDC 0036DEDC 00000000 */   nop
.size func_0036deb0, 0x30

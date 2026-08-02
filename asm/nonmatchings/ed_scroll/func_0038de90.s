.section .text
.set noat
.set noreorder
glabel func_0038de90
    /* 28DE90 0038DE90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28DE94 0038DE94 1000BFFF */  sd         $31, 0x10($29)
    /* 28DE98 0038DE98 0000B07F */  sq         $16, 0x0($29)
    /* 28DE9C 0038DE9C B0B5828F */  lw         $2, -0x4A50($28)
    /* 28DEA0 0038DEA0 06004014 */  bnez       $2, .L0038DEBC
    /* 28DEA4 0038DEA4 00000000 */   nop
    /* 28DEA8 0038DEA8 6500043C */  lui        $4, %hi(D_0064F220)
    /* 28DEAC 0038DEAC 20F28424 */  addiu      $4, $4, %lo(D_0064F220)
    /* 28DEB0 0038DEB0 6B000524 */  addiu      $5, $0, 0x6B
    /* 28DEB4 0038DEB4 CCB5110C */  jal        func_0046d730
    /* 28DEB8 0038DEB8 00000000 */   nop
  .L0038DEBC:
    /* 28DEBC 0038DEBC B0B5908F */  lw         $16, -0x4A50($28)
    /* 28DEC0 0038DEC0 101200AE */  sw         $0, 0x1210($16)
    /* 28DEC4 0038DEC4 141200AE */  sw         $0, 0x1214($16)
    /* 28DEC8 0038DEC8 E043023C */  lui        $2, (0x43E00000 >> 16)
    /* 28DECC 0038DECC 181202AE */  sw         $2, 0x1218($16)
    /* 28DED0 0038DED0 1C1202AE */  sw         $2, 0x121C($16)
    /* 28DED4 0038DED4 041200AE */  sw         $0, 0x1204($16)
    /* 28DED8 0038DED8 081200AE */  sw         $0, 0x1208($16)
    /* 28DEDC 0038DEDC 0C1200AE */  sw         $0, 0x120C($16)
    /* 28DEE0 0038DEE0 D0390E0C */  jal        func_0038e740
    /* 28DEE4 0038DEE4 00000000 */   nop
    /* 28DEE8 0038DEE8 0000038E */  lw         $3, 0x0($16)
    /* 28DEEC 0038DEEC 01006334 */  ori        $3, $3, 0x1
    /* 28DEF0 0038DEF0 000003AE */  sw         $3, 0x0($16)
    /* 28DEF4 0038DEF4 241200AE */  sw         $0, 0x1224($16)
    /* 28DEF8 0038DEF8 1000BFDF */  ld         $31, 0x10($29)
    /* 28DEFC 0038DEFC 0000B07B */  lq         $16, 0x0($29)
    /* 28DF00 0038DF00 2000BD27 */  addiu      $29, $29, 0x20
    /* 28DF04 0038DF04 0800E003 */  jr         $31
    /* 28DF08 0038DF08 00000000 */   nop
    /* 28DF0C 0038DF0C 00000000 */  nop
.size func_0038de90, 0x80

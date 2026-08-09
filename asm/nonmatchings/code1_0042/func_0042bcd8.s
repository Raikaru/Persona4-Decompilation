.section .text
.set noat
.set noreorder
glabel func_0042bcd8
    /* 32BCD8 0042BCD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32BCDC 0042BCDC 0000BFFF */  sd         $31, 0x0($29)
    /* 32BCE0 0042BCE0 A2AE100C */  jal        func_0042ba88
    /* 32BCE4 0042BCE4 00000000 */   nop
    /* 32BCE8 0042BCE8 F2AE100C */  jal        func_0042bbc8
    /* 32BCEC 0042BCEC 00000000 */   nop
    /* 32BCF0 0042BCF0 6EB0100C */  jal        func_0042c1b8
    /* 32BCF4 0042BCF4 00000000 */   nop
    /* 32BCF8 0042BCF8 CCB0100C */  jal        func_0042c330
    /* 32BCFC 0042BCFC 02000424 */   addiu     $4, $0, 0x2
    /* 32BD00 0042BD00 5CB1100C */  jal        func_0042c570
    /* 32BD04 0042BD04 00000000 */   nop
    /* 32BD08 0042BD08 6E89100C */  jal        func_004225b8
    /* 32BD0C 0042BD0C 00000000 */   nop
    /* 32BD10 0042BD10 80AF100C */  jal        func_0042be00
    /* 32BD14 0042BD14 00000000 */   nop
    /* 32BD18 0042BD18 BEAC100C */  jal        func_0042b2f8
    /* 32BD1C 0042BD1C 00000000 */   nop
    /* 32BD20 0042BD20 0000BFDF */  ld         $31, 0x0($29)
    /* 32BD24 0042BD24 94B61008 */  j          func_0042da50
    /* 32BD28 0042BD28 1000BD27 */   addiu     $29, $29, 0x10
    /* 32BD2C 0042BD2C 00000000 */  nop
.size func_0042bcd8, 0x58

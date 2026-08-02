.section .text
.set noat
.set noreorder
glabel func_0049ef00
    /* 39EF00 0049EF00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 39EF04 0049EF04 1000BFFF */  sd         $31, 0x10($29)
    /* 39EF08 0049EF08 0000B07F */  sq         $16, 0x0($29)
    /* 39EF0C 0049EF0C 2D808000 */  daddu      $16, $4, $0
    /* 39EF10 0049EF10 0400848C */  lw         $4, 0x4($4)
    /* 39EF14 0049EF14 FC0C120C */  jal        func_004833f0
    /* 39EF18 0049EF18 00000000 */   nop
    /* 39EF1C 0049EF1C 0800048E */  lw         $4, 0x8($16)
    /* 39EF20 0049EF20 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 39EF24 0049EF24 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 39EF28 0049EF28 09F84000 */  jalr       $2
    /* 39EF2C 0049EF2C 00000000 */   nop
    /* 39EF30 0049EF30 1000BFDF */  ld         $31, 0x10($29)
    /* 39EF34 0049EF34 0000B07B */  lq         $16, 0x0($29)
    /* 39EF38 0049EF38 2000BD27 */  addiu      $29, $29, 0x20
    /* 39EF3C 0049EF3C 0800E003 */  jr         $31
    /* 39EF40 0049EF40 00000000 */   nop
    /* 39EF44 0049EF44 00000000 */  nop
    /* 39EF48 0049EF48 00000000 */  nop
    /* 39EF4C 0049EF4C 00000000 */  nop
.size func_0049ef00, 0x50

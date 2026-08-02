.section .text
.set noat
.set noreorder
glabel func_0033cbc0
    /* 23CBC0 0033CBC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 23CBC4 0033CBC4 2000BFFF */  sd         $31, 0x20($29)
    /* 23CBC8 0033CBC8 1000B17F */  sq         $17, 0x10($29)
    /* 23CBCC 0033CBCC 0000B07F */  sq         $16, 0x0($29)
    /* 23CBD0 0033CBD0 2D80A000 */  daddu      $16, $5, $0
    /* 23CBD4 0033CBD4 3800918C */  lw         $17, 0x38($4)
    /* 23CBD8 0033CBD8 3C241000 */  dsll32     $4, $16, 16
    /* 23CBDC 0033CBDC 3F240400 */  dsra32     $4, $4, 16
    /* 23CBE0 0033CBE0 A41A040C */  jal        func_00106a90
    /* 23CBE4 0033CBE4 00000000 */   nop
    /* 23CBE8 0033CBE8 09002382 */  lb         $3, 0x9($17)
    /* 23CBEC 0033CBEC 18186200 */  mult       $3, $3, $2
    /* 23CBF0 0033CBF0 80100300 */  sll        $2, $3, 2
    /* 23CBF4 0033CBF4 21104300 */  addu       $2, $2, $3
    /* 23CBF8 0033CBF8 80180200 */  sll        $3, $2, 2
    /* 23CBFC 0033CBFC 64000224 */  addiu      $2, $0, 0x64
    /* 23CC00 0033CC00 1B006200 */  divu       $0, $3, $2
    /* 23CC04 0033CC04 12880000 */  mflo       $17
    /* 23CC08 0033CC08 3C241000 */  dsll32     $4, $16, 16
    /* 23CC0C 0033CC0C 3F240400 */  dsra32     $4, $4, 16
    /* 23CC10 0033CC10 A41A040C */  jal        func_00106a90
    /* 23CC14 0033CC14 00000000 */   nop
    /* 23CC18 0033CC18 23105100 */  subu       $2, $2, $17
    /* 23CC1C 0033CC1C 2000BFDF */  ld         $31, 0x20($29)
    /* 23CC20 0033CC20 1000B17B */  lq         $17, 0x10($29)
    /* 23CC24 0033CC24 0000B07B */  lq         $16, 0x0($29)
    /* 23CC28 0033CC28 3000BD27 */  addiu      $29, $29, 0x30
    /* 23CC2C 0033CC2C 0800E003 */  jr         $31
    /* 23CC30 0033CC30 00000000 */   nop
    /* 23CC34 0033CC34 00000000 */  nop
    /* 23CC38 0033CC38 00000000 */  nop
    /* 23CC3C 0033CC3C 00000000 */  nop
.size func_0033cbc0, 0x80

.section .text
.set noat
.set noreorder
glabel func_001da5f0
    /* DA5F0 001DA5F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DA5F4 001DA5F4 1000BFFF */  sd         $31, 0x10($29)
    /* DA5F8 001DA5F8 0000B07F */  sq         $16, 0x0($29)
    /* DA5FC 001DA5FC 2D188000 */  daddu      $3, $4, $0
    /* DA600 001DA600 2D80A000 */  daddu      $16, $5, $0
    /* DA604 001DA604 3000828C */  lw         $2, 0x30($4)
    /* DA608 001DA608 640A448C */  lw         $4, 0xA64($2)
    /* DA60C 001DA60C 7E006594 */  lhu        $5, 0x7E($3)
    /* DA610 001DA610 38F6080C */  jal        func_0023d8e0
    /* DA614 001DA614 00000000 */   nop
    /* DA618 001DA618 3C140200 */  dsll32     $2, $2, 16
    /* DA61C 001DA61C 3F140200 */  dsra32     $2, $2, 16
    /* DA620 001DA620 26105000 */  xor        $2, $2, $16
    /* DA624 001DA624 0100422C */  sltiu      $2, $2, 0x1
    /* DA628 001DA628 1000BFDF */  ld         $31, 0x10($29)
    /* DA62C 001DA62C 0000B07B */  lq         $16, 0x0($29)
    /* DA630 001DA630 2000BD27 */  addiu      $29, $29, 0x20
    /* DA634 001DA634 0800E003 */  jr         $31
    /* DA638 001DA638 00000000 */   nop
    /* DA63C 001DA63C 00000000 */  nop
.size func_001da5f0, 0x50

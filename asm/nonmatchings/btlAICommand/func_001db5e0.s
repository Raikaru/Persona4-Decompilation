.section .text
.set noat
.set noreorder
glabel func_001db5e0
    /* DB5E0 001DB5E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB5E4 001DB5E4 0000BFFF */  sd         $31, 0x0($29)
    /* DB5E8 001DB5E8 3000828C */  lw         $2, 0x30($4)
    /* DB5EC 001DB5EC 3C2C0500 */  dsll32     $5, $5, 16
    /* DB5F0 001DB5F0 3F2C0500 */  dsra32     $5, $5, 16
    /* DB5F4 001DB5F4 640A448C */  lw         $4, 0xA64($2)
    /* DB5F8 001DB5F8 000A090C */  jal        func_00242800
    /* DB5FC 001DB5FC 00000000 */   nop
    /* DB600 001DB600 0007033C */  lui        $3, (0x7000000 >> 16)
    /* DB604 001DB604 24104300 */  and        $2, $2, $3
    /* DB608 001DB608 2B100200 */  sltu       $2, $0, $2
    /* DB60C 001DB60C 01004238 */  xori       $2, $2, 0x1
    /* DB610 001DB610 0000BFDF */  ld         $31, 0x0($29)
    /* DB614 001DB614 1000BD27 */  addiu      $29, $29, 0x10
    /* DB618 001DB618 0800E003 */  jr         $31
    /* DB61C 001DB61C 00000000 */   nop
.size func_001db5e0, 0x40

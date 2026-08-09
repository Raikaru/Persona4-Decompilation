.section .text
.set noat
.set noreorder
glabel func_001b6990
    /* B6990 001B6990 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B6994 001B6994 0000BFFF */  sd         $31, 0x0($29)
    /* B6998 001B6998 ACB3828F */  lw         $2, -0x4C54($28)
    /* B699C 001B699C 6C024494 */  lhu        $4, 0x26C($2)
    /* B69A0 001B69A0 6E024594 */  lhu        $5, 0x26E($2)
    /* B69A4 001B69A4 2413050C */  jal        func_00144c90
    /* B69A8 001B69A8 00000000 */   nop
    /* B69AC 001B69AC 0000BFDF */  ld         $31, 0x0($29)
    /* B69B0 001B69B0 1000BD27 */  addiu      $29, $29, 0x10
    /* B69B4 001B69B4 0800E003 */  jr         $31
    /* B69B8 001B69B8 00000000 */   nop
    /* B69BC 001B69BC 00000000 */  nop
.size func_001b6990, 0x30

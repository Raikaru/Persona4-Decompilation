.section .text
.set noat
.set noreorder
glabel func_001f8690
    /* F8690 001F8690 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F8694 001F8694 0000BFFF */  sd         $31, 0x0($29)
    /* F8698 001F8698 ACB3828F */  lw         $2, -0x4C54($28)
    /* F869C 001F869C 300B4294 */  lhu        $2, 0xB30($2)
    /* F86A0 001F86A0 FFFF8630 */  andi       $6, $4, 0xFFFF
    /* F86A4 001F86A4 2D204000 */  daddu      $4, $2, $0
    /* F86A8 001F86A8 03000524 */  addiu      $5, $0, 0x3
    /* F86AC 001F86AC 846B110C */  jal        func_0045ae10
    /* F86B0 001F86B0 00000000 */   nop
    /* F86B4 001F86B4 0000BFDF */  ld         $31, 0x0($29)
    /* F86B8 001F86B8 1000BD27 */  addiu      $29, $29, 0x10
    /* F86BC 001F86BC 0800E003 */  jr         $31
    /* F86C0 001F86C0 00000000 */   nop
    /* F86C4 001F86C4 00000000 */  nop
    /* F86C8 001F86C8 00000000 */  nop
    /* F86CC 001F86CC 00000000 */  nop
.size func_001f8690, 0x40

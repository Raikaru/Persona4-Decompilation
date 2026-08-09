.section .text
.set noat
.set noreorder
glabel func_001d99a0
    /* D99A0 001D99A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D99A4 001D99A4 1000BFFF */  sd         $31, 0x10($29)
    /* D99A8 001D99A8 0000B07F */  sq         $16, 0x0($29)
    /* D99AC 001D99AC 2D80A000 */  daddu      $16, $5, $0
    /* D99B0 001D99B0 3000828C */  lw         $2, 0x30($4)
    /* D99B4 001D99B4 640A448C */  lw         $4, 0xA64($2)
    /* D99B8 001D99B8 88C7080C */  jal        func_00231e20
    /* D99BC 001D99BC 00000000 */   nop
    /* D99C0 001D99C0 FF004230 */  andi       $2, $2, 0xFF
    /* D99C4 001D99C4 2B105000 */  sltu       $2, $2, $16
    /* D99C8 001D99C8 01004238 */  xori       $2, $2, 0x1
    /* D99CC 001D99CC 1000BFDF */  ld         $31, 0x10($29)
    /* D99D0 001D99D0 0000B07B */  lq         $16, 0x0($29)
    /* D99D4 001D99D4 2000BD27 */  addiu      $29, $29, 0x20
    /* D99D8 001D99D8 0800E003 */  jr         $31
    /* D99DC 001D99DC 00000000 */   nop
.size func_001d99a0, 0x40

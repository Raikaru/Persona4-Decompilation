.section .text
.set noat
.set noreorder
glabel func_001e65b0
    /* E65B0 001E65B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E65B4 001E65B4 0000BFFF */  sd         $31, 0x0($29)
    /* E65B8 001E65B8 14740A0C */  jal        func_0029d050
    /* E65BC 001E65BC 00000000 */   nop
    /* E65C0 001E65C0 3000428C */  lw         $2, 0x30($2)
    /* E65C4 001E65C4 640A448C */  lw         $4, 0xA64($2)
    /* E65C8 001E65C8 B4C7080C */  jal        func_00231ed0
    /* E65CC 001E65CC 00000000 */   nop
    /* E65D0 001E65D0 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E65D4 001E65D4 D4730A0C */  jal        func_0029cf50
    /* E65D8 001E65D8 00000000 */   nop
    /* E65DC 001E65DC FFFF0224 */  addiu      $2, $0, -0x1
    /* E65E0 001E65E0 0000BFDF */  ld         $31, 0x0($29)
    /* E65E4 001E65E4 1000BD27 */  addiu      $29, $29, 0x10
    /* E65E8 001E65E8 0800E003 */  jr         $31
    /* E65EC 001E65EC 00000000 */   nop
.size func_001e65b0, 0x40

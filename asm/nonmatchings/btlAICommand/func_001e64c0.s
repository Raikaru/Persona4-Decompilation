.section .text
.set noat
.set noreorder
glabel func_001e64c0
    /* E64C0 001E64C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E64C4 001E64C4 1000BFFF */  sd         $31, 0x10($29)
    /* E64C8 001E64C8 0000B07F */  sq         $16, 0x0($29)
    /* E64CC 001E64CC 14740A0C */  jal        func_0029d050
    /* E64D0 001E64D0 00000000 */   nop
    /* E64D4 001E64D4 2D804000 */  daddu      $16, $2, $0
    /* E64D8 001E64D8 2D200000 */  daddu      $4, $0, $0
    /* E64DC 001E64DC 00730A0C */  jal        func_0029cc00
    /* E64E0 001E64E0 00000000 */   nop
    /* E64E4 001E64E4 3C1C0200 */  dsll32     $3, $2, 16
    /* E64E8 001E64E8 3F1C0300 */  dsra32     $3, $3, 16
    /* E64EC 001E64EC 3000028E */  lw         $2, 0x30($16)
    /* E64F0 001E64F0 FFFF6530 */  andi       $5, $3, 0xFFFF
    /* E64F4 001E64F4 640A448C */  lw         $4, 0xA64($2)
    /* E64F8 001E64F8 38F6080C */  jal        func_0023d8e0
    /* E64FC 001E64FC 00000000 */   nop
    /* E6500 001E6500 3C240200 */  dsll32     $4, $2, 16
    /* E6504 001E6504 3F240400 */  dsra32     $4, $4, 16
    /* E6508 001E6508 D4730A0C */  jal        func_0029cf50
    /* E650C 001E650C 00000000 */   nop
    /* E6510 001E6510 FFFF0224 */  addiu      $2, $0, -0x1
    /* E6514 001E6514 1000BFDF */  ld         $31, 0x10($29)
    /* E6518 001E6518 0000B07B */  lq         $16, 0x0($29)
    /* E651C 001E651C 2000BD27 */  addiu      $29, $29, 0x20
    /* E6520 001E6520 0800E003 */  jr         $31
    /* E6524 001E6524 00000000 */   nop
    /* E6528 001E6528 00000000 */  nop
    /* E652C 001E652C 00000000 */  nop
.size func_001e64c0, 0x70

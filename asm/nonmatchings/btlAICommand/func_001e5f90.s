.section .text
.set noat
.set noreorder
glabel func_001e5f90
    /* E5F90 001E5F90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E5F94 001E5F94 0000BFFF */  sd         $31, 0x0($29)
    /* E5F98 001E5F98 14740A0C */  jal        func_0029d050
    /* E5F9C 001E5F9C 00000000 */   nop
    /* E5FA0 001E5FA0 3000428C */  lw         $2, 0x30($2)
    /* E5FA4 001E5FA4 640A428C */  lw         $2, 0xA64($2)
    /* E5FA8 001E5FA8 04004494 */  lhu        $4, 0x4($2)
    /* E5FAC 001E5FAC D4730A0C */  jal        func_0029cf50
    /* E5FB0 001E5FB0 00000000 */   nop
    /* E5FB4 001E5FB4 01000224 */  addiu      $2, $0, 0x1
    /* E5FB8 001E5FB8 0000BFDF */  ld         $31, 0x0($29)
    /* E5FBC 001E5FBC 1000BD27 */  addiu      $29, $29, 0x10
    /* E5FC0 001E5FC0 0800E003 */  jr         $31
    /* E5FC4 001E5FC4 00000000 */   nop
    /* E5FC8 001E5FC8 00000000 */  nop
    /* E5FCC 001E5FCC 00000000 */  nop
.size func_001e5f90, 0x40

.section .text
.set noat
.set noreorder
glabel func_001e7d30
    /* E7D30 001E7D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E7D34 001E7D34 0000BFFF */  sd         $31, 0x0($29)
    /* E7D38 001E7D38 14740A0C */  jal        func_0029d050
    /* E7D3C 001E7D3C 00000000 */   nop
    /* E7D40 001E7D40 0800438C */  lw         $3, 0x8($2)
    /* E7D44 001E7D44 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E7D48 001E7D48 25206200 */  or         $4, $3, $2
    /* E7D4C 001E7D4C D4730A0C */  jal        func_0029cf50
    /* E7D50 001E7D50 00000000 */   nop
    /* E7D54 001E7D54 01000224 */  addiu      $2, $0, 0x1
    /* E7D58 001E7D58 0000BFDF */  ld         $31, 0x0($29)
    /* E7D5C 001E7D5C 1000BD27 */  addiu      $29, $29, 0x10
    /* E7D60 001E7D60 0800E003 */  jr         $31
    /* E7D64 001E7D64 00000000 */   nop
    /* E7D68 001E7D68 00000000 */  nop
    /* E7D6C 001E7D6C 00000000 */  nop
.size func_001e7d30, 0x40

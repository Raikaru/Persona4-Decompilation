.section .text
.set noat
.set noreorder
glabel func_001e7e30
    /* E7E30 001E7E30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E7E34 001E7E34 0000BFFF */  sd         $31, 0x0($29)
    /* E7E38 001E7E38 58C5060C */  jal        func_001b1560
    /* E7E3C 001E7E3C 00000000 */   nop
    /* E7E40 001E7E40 0800438C */  lw         $3, 0x8($2)
    /* E7E44 001E7E44 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E7E48 001E7E48 25206200 */  or         $4, $3, $2
    /* E7E4C 001E7E4C D4730A0C */  jal        func_0029cf50
    /* E7E50 001E7E50 00000000 */   nop
    /* E7E54 001E7E54 01000224 */  addiu      $2, $0, 0x1
    /* E7E58 001E7E58 0000BFDF */  ld         $31, 0x0($29)
    /* E7E5C 001E7E5C 1000BD27 */  addiu      $29, $29, 0x10
    /* E7E60 001E7E60 0800E003 */  jr         $31
    /* E7E64 001E7E64 00000000 */   nop
    /* E7E68 001E7E68 00000000 */  nop
    /* E7E6C 001E7E6C 00000000 */  nop
.size func_001e7e30, 0x40

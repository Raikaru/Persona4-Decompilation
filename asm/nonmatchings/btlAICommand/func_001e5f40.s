.section .text
.set noat
.set noreorder
glabel func_001e5f40
    /* E5F40 001E5F40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5F44 001E5F44 1000BFFF */  sd         $31, 0x10($29)
    /* E5F48 001E5F48 0000B07F */  sq         $16, 0x0($29)
    /* E5F4C 001E5F4C 14740A0C */  jal        func_0029d050
    /* E5F50 001E5F50 00000000 */   nop
    /* E5F54 001E5F54 2D804000 */  daddu      $16, $2, $0
    /* E5F58 001E5F58 2D200000 */  daddu      $4, $0, $0
    /* E5F5C 001E5F5C 00730A0C */  jal        func_0029cc00
    /* E5F60 001E5F60 00000000 */   nop
    /* E5F64 001E5F64 800002A6 */  sh         $2, 0x80($16)
    /* E5F68 001E5F68 01000424 */  addiu      $4, $0, 0x1
    /* E5F6C 001E5F6C 00730A0C */  jal        func_0029cc00
    /* E5F70 001E5F70 00000000 */   nop
    /* E5F74 001E5F74 820002A2 */  sb         $2, 0x82($16)
    /* E5F78 001E5F78 01000224 */  addiu      $2, $0, 0x1
    /* E5F7C 001E5F7C 1000BFDF */  ld         $31, 0x10($29)
    /* E5F80 001E5F80 0000B07B */  lq         $16, 0x0($29)
    /* E5F84 001E5F84 2000BD27 */  addiu      $29, $29, 0x20
    /* E5F88 001E5F88 0800E003 */  jr         $31
    /* E5F8C 001E5F8C 00000000 */   nop
.size func_001e5f40, 0x50

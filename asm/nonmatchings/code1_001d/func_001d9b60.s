.section .text
.set noat
.set noreorder
glabel func_001d9b60
    /* D9B60 001D9B60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D9B64 001D9B64 0000BFFF */  sd         $31, 0x0($29)
    /* D9B68 001D9B68 3000828C */  lw         $2, 0x30($4)
    /* D9B6C 001D9B6C 640A448C */  lw         $4, 0xA64($2)
    /* D9B70 001D9B70 C4C9080C */  jal        func_00232710
    /* D9B74 001D9B74 00000000 */   nop
    /* D9B78 001D9B78 0000BFDF */  ld         $31, 0x0($29)
    /* D9B7C 001D9B7C 1000BD27 */  addiu      $29, $29, 0x10
    /* D9B80 001D9B80 0800E003 */  jr         $31
    /* D9B84 001D9B84 00000000 */   nop
    /* D9B88 001D9B88 00000000 */  nop
    /* D9B8C 001D9B8C 00000000 */  nop
.size func_001d9b60, 0x30

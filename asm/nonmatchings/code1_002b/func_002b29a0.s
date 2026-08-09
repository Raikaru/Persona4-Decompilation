.section .text
.set noat
.set noreorder
glabel func_002b29a0
    /* 1B29A0 002B29A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B29A4 002B29A4 0000ACE7 */  swc1       $f12, 0x0($29)
    /* 1B29A8 002B29A8 0400ADE7 */  swc1       $f13, 0x4($29)
    /* 1B29AC 002B29AC 0800AEE7 */  swc1       $f14, 0x8($29)
    /* 1B29B0 002B29B0 0000A2C7 */  lwc1       $f2, 0x0($29)
    /* 1B29B4 002B29B4 0400A1C7 */  lwc1       $f1, 0x4($29)
    /* 1B29B8 002B29B8 0800A0C7 */  lwc1       $f0, 0x8($29)
    /* 1B29BC 002B29BC 000082E4 */  swc1       $f2, 0x0($4)
    /* 1B29C0 002B29C0 040081E4 */  swc1       $f1, 0x4($4)
    /* 1B29C4 002B29C4 080080E4 */  swc1       $f0, 0x8($4)
    /* 1B29C8 002B29C8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B29CC 002B29CC 0800E003 */  jr         $31
    /* 1B29D0 002B29D0 00000000 */   nop
    /* 1B29D4 002B29D4 00000000 */  nop
    /* 1B29D8 002B29D8 00000000 */  nop
    /* 1B29DC 002B29DC 00000000 */  nop
.size func_002b29a0, 0x40

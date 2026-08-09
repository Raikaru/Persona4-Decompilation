.section .text
.set noat
.set noreorder
glabel func_001ea470
    /* EA470 001EA470 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA474 001EA474 0000BFFF */  sd         $31, 0x0($29)
    /* EA478 001EA478 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA47C 001EA47C 340C4484 */  lh         $4, 0xC34($2)
    /* EA480 001EA480 D4730A0C */  jal        func_0029cf50
    /* EA484 001EA484 00000000 */   nop
    /* EA488 001EA488 01000224 */  addiu      $2, $0, 0x1
    /* EA48C 001EA48C 0000BFDF */  ld         $31, 0x0($29)
    /* EA490 001EA490 1000BD27 */  addiu      $29, $29, 0x10
    /* EA494 001EA494 0800E003 */  jr         $31
    /* EA498 001EA498 00000000 */   nop
    /* EA49C 001EA49C 00000000 */  nop
.size func_001ea470, 0x30

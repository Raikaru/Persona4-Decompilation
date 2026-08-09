.section .text
.set noat
.set noreorder
glabel func_001ea360
    /* EA360 001EA360 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA364 001EA364 0000BFFF */  sd         $31, 0x0($29)
    /* EA368 001EA368 14740A0C */  jal        func_0029d050
    /* EA36C 001EA36C 00000000 */   nop
    /* EA370 001EA370 05000324 */  addiu      $3, $0, 0x5
    /* EA374 001EA374 6C0043A4 */  sh         $3, 0x6C($2)
    /* EA378 001EA378 01000224 */  addiu      $2, $0, 0x1
    /* EA37C 001EA37C 0000BFDF */  ld         $31, 0x0($29)
    /* EA380 001EA380 1000BD27 */  addiu      $29, $29, 0x10
    /* EA384 001EA384 0800E003 */  jr         $31
    /* EA388 001EA388 00000000 */   nop
    /* EA38C 001EA38C 00000000 */  nop
.size func_001ea360, 0x30

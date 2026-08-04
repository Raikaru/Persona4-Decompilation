.section .text
.set noat
.set noreorder
glabel func_001ea420
    /* EA420 001EA420 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA424 001EA424 0000BFFF */  sd         $31, 0x0($29)
    /* EA428 001EA428 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA42C 001EA42C 680C428C */  lw         $2, 0xC68($2)
    /* EA430 001EA430 08004394 */  lhu        $3, 0x8($2)
    /* EA434 001EA434 40100300 */  sll        $2, $3, 1
    /* EA438 001EA438 21104300 */  addu       $2, $2, $3
    /* EA43C 001EA43C C0180200 */  sll        $3, $2, 3
    /* EA440 001EA440 14B4828F */  lw         $2, -0x4BEC($28)
    /* EA444 001EA444 21104300 */  addu       $2, $2, $3
    /* EA448 001EA448 0000428C */  lw         $2, 0x0($2)
    /* EA44C 001EA44C 20004230 */  andi       $2, $2, 0x20
    /* EA450 001EA450 2B200200 */  sltu       $4, $0, $2
    /* EA454 001EA454 D4730A0C */  jal        func_0029cf50
    /* EA458 001EA458 00000000 */   nop
    /* EA45C 001EA45C 01000224 */  addiu      $2, $0, 0x1
    /* EA460 001EA460 0000BFDF */  ld         $31, 0x0($29)
    /* EA464 001EA464 1000BD27 */  addiu      $29, $29, 0x10
    /* EA468 001EA468 0800E003 */  jr         $31
    /* EA46C 001EA46C 00000000 */   nop
.size func_001ea420, 0x50

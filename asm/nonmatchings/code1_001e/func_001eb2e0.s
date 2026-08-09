.section .text
.set noat
.set noreorder
glabel func_001eb2e0
    /* EB2E0 001EB2E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB2E4 001EB2E4 0000BFFF */  sd         $31, 0x0($29)
    /* EB2E8 001EB2E8 2D200000 */  daddu      $4, $0, $0
    /* EB2EC 001EB2EC 00730A0C */  jal        func_0029cc00
    /* EB2F0 001EB2F0 00000000 */   nop
    /* EB2F4 001EB2F4 ACB3838F */  lw         $3, -0x4C54($28)
    /* EB2F8 001EB2F8 80100200 */  sll        $2, $2, 2
    /* EB2FC 001EB2FC 21104300 */  addu       $2, $2, $3
    /* EB300 001EB300 D80D448C */  lw         $4, 0xDD8($2)
    /* EB304 001EB304 D4730A0C */  jal        func_0029cf50
    /* EB308 001EB308 00000000 */   nop
    /* EB30C 001EB30C 01000224 */  addiu      $2, $0, 0x1
    /* EB310 001EB310 0000BFDF */  ld         $31, 0x0($29)
    /* EB314 001EB314 1000BD27 */  addiu      $29, $29, 0x10
    /* EB318 001EB318 0800E003 */  jr         $31
    /* EB31C 001EB31C 00000000 */   nop
.size func_001eb2e0, 0x40

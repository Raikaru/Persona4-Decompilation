.section .text
.set noat
.set noreorder
glabel func_001eb320
    /* EB320 001EB320 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EB324 001EB324 1000BFFF */  sd         $31, 0x10($29)
    /* EB328 001EB328 0000B07F */  sq         $16, 0x0($29)
    /* EB32C 001EB32C 2D200000 */  daddu      $4, $0, $0
    /* EB330 001EB330 00730A0C */  jal        func_0029cc00
    /* EB334 001EB334 00000000 */   nop
    /* EB338 001EB338 2D804000 */  daddu      $16, $2, $0
    /* EB33C 001EB33C 01000424 */  addiu      $4, $0, 0x1
    /* EB340 001EB340 00730A0C */  jal        func_0029cc00
    /* EB344 001EB344 00000000 */   nop
    /* EB348 001EB348 ACB3848F */  lw         $4, -0x4C54($28)
    /* EB34C 001EB34C 80181000 */  sll        $3, $16, 2
    /* EB350 001EB350 21186400 */  addu       $3, $3, $4
    /* EB354 001EB354 D80D62AC */  sw         $2, 0xDD8($3)
    /* EB358 001EB358 01000224 */  addiu      $2, $0, 0x1
    /* EB35C 001EB35C 1000BFDF */  ld         $31, 0x10($29)
    /* EB360 001EB360 0000B07B */  lq         $16, 0x0($29)
    /* EB364 001EB364 2000BD27 */  addiu      $29, $29, 0x20
    /* EB368 001EB368 0800E003 */  jr         $31
    /* EB36C 001EB36C 00000000 */   nop
.size func_001eb320, 0x50

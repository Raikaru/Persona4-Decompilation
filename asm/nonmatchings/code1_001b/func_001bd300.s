.section .text
.set noat
.set noreorder
glabel func_001bd300
    /* BD300 001BD300 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BD304 001BD304 2000BFFF */  sd         $31, 0x20($29)
    /* BD308 001BD308 1000B17F */  sq         $17, 0x10($29)
    /* BD30C 001BD30C 0000B07F */  sq         $16, 0x0($29)
    /* BD310 001BD310 2D800000 */  daddu      $16, $0, $0
    /* BD314 001BD314 12000010 */  b          .L001BD360
    /* BD318 001BD318 00000000 */   nop
  .L001BD31C:
    /* BD31C 001BD31C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* BD320 001BD320 C0200300 */  sll        $4, $3, 3
    /* BD324 001BD324 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD328 001BD328 21186400 */  addu       $3, $3, $4
    /* BD32C 001BD32C 7801718C */  lw         $17, 0x178($3)
    /* BD330 001BD330 06000010 */  b          .L001BD34C
    /* BD334 001BD334 00000000 */   nop
  .L001BD338:
    /* BD338 001BD338 2D202002 */  daddu      $4, $17, $0
    /* BD33C 001BD33C 0F000524 */  addiu      $5, $0, 0xF
    /* BD340 001BD340 F053060C */  jal        func_00194fc0
    /* BD344 001BD344 00000000 */   nop
    /* BD348 001BD348 6C0A318E */  lw         $17, 0xA6C($17)
  .L001BD34C:
    /* BD34C 001BD34C 00000000 */  nop
    /* BD350 001BD350 F9FF2016 */  bnez       $17, .L001BD338
    /* BD354 001BD354 00000000 */   nop
    /* BD358 001BD358 01000326 */  addiu      $3, $16, 0x1
    /* BD35C 001BD35C FFFF7030 */  andi       $16, $3, 0xFFFF
  .L001BD360:
    /* BD360 001BD360 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* BD364 001BD364 02006328 */  slti       $3, $3, 0x2
    /* BD368 001BD368 ECFF6014 */  bnez       $3, .L001BD31C
    /* BD36C 001BD36C 00000000 */   nop
    /* BD370 001BD370 2000BFDF */  ld         $31, 0x20($29)
    /* BD374 001BD374 1000B17B */  lq         $17, 0x10($29)
    /* BD378 001BD378 0000B07B */  lq         $16, 0x0($29)
    /* BD37C 001BD37C 3000BD27 */  addiu      $29, $29, 0x30
    /* BD380 001BD380 0800E003 */  jr         $31
    /* BD384 001BD384 00000000 */   nop
    /* BD388 001BD388 00000000 */  nop
    /* BD38C 001BD38C 00000000 */  nop
.size func_001bd300, 0x90

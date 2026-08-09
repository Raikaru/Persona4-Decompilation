.section .text
.set noat
.set noreorder
glabel func_002bd580
    /* 1BD580 002BD580 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1BD584 002BD584 3000BFFF */  sd         $31, 0x30($29)
    /* 1BD588 002BD588 2000B27F */  sq         $18, 0x20($29)
    /* 1BD58C 002BD58C 1000B17F */  sq         $17, 0x10($29)
    /* 1BD590 002BD590 0000B07F */  sq         $16, 0x0($29)
    /* 1BD594 002BD594 2D908000 */  daddu      $18, $4, $0
    /* 1BD598 002BD598 2D88A000 */  daddu      $17, $5, $0
    /* 1BD59C 002BD59C 2D80C000 */  daddu      $16, $6, $0
    /* 1BD5A0 002BD5A0 0000848C */  lw         $4, 0x0($4)
    /* 1BD5A4 002BD5A4 04008104 */  bgez       $4, .L002BD5B8
    /* 1BD5A8 002BD5A8 00000000 */   nop
    /* 1BD5AC 002BD5AC 2D100000 */  daddu      $2, $0, $0
    /* 1BD5B0 002BD5B0 10000010 */  b          .L002BD5F4
    /* 1BD5B4 002BD5B4 00000000 */   nop
  .L002BD5B8:
    /* 1BD5B8 002BD5B8 2000053C */  lui        $5, (0x200000 >> 16)
    /* 1BD5BC 002BD5BC 5CE0090C */  jal        func_00278170
    /* 1BD5C0 002BD5C0 00000000 */   nop
    /* 1BD5C4 002BD5C4 0000448E */  lw         $4, 0x0($18)
    /* 1BD5C8 002BD5C8 2D280002 */  daddu      $5, $16, $0
    /* 1BD5CC 002BD5CC 2D300000 */  daddu      $6, $0, $0
    /* 1BD5D0 002BD5D0 30DE090C */  jal        func_002778c0
    /* 1BD5D4 002BD5D4 00000000 */   nop
    /* 1BD5D8 002BD5D8 0000448E */  lw         $4, 0x0($18)
    /* 1BD5DC 002BD5DC 2D282002 */  daddu      $5, $17, $0
    /* 1BD5E0 002BD5E0 28060A0C */  jal        func_002818a0
    /* 1BD5E4 002BD5E4 00000000 */   nop
    /* 1BD5E8 002BD5E8 01000224 */  addiu      $2, $0, 0x1
    /* 1BD5EC 002BD5EC 040042A2 */  sb         $2, 0x4($18)
    /* 1BD5F0 002BD5F0 2D100000 */  daddu      $2, $0, $0
  .L002BD5F4:
    /* 1BD5F4 002BD5F4 3000BFDF */  ld         $31, 0x30($29)
    /* 1BD5F8 002BD5F8 2000B27B */  lq         $18, 0x20($29)
    /* 1BD5FC 002BD5FC 1000B17B */  lq         $17, 0x10($29)
    /* 1BD600 002BD600 0000B07B */  lq         $16, 0x0($29)
    /* 1BD604 002BD604 4000BD27 */  addiu      $29, $29, 0x40
    /* 1BD608 002BD608 0800E003 */  jr         $31
    /* 1BD60C 002BD60C 00000000 */   nop
.size func_002bd580, 0x90

.section .text
.set noat
.set noreorder
glabel func_001ea4a0
    /* EA4A0 001EA4A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA4A4 001EA4A4 0000BFFF */  sd         $31, 0x0($29)
    /* EA4A8 001EA4A8 68BE070C */  jal        func_001ef9a0
    /* EA4AC 001EA4AC 00000000 */   nop
    /* EA4B0 001EA4B0 0B020324 */  addiu      $3, $0, 0x20B
    /* EA4B4 001EA4B4 07004314 */  bne        $2, $3, .L001EA4D4
    /* EA4B8 001EA4B8 00000000 */   nop
    /* EA4BC 001EA4BC FF150424 */  addiu      $4, $0, 0x15FF
    /* EA4C0 001EA4C0 CC18040C */  jal        func_00106330
    /* EA4C4 001EA4C4 00000000 */   nop
    /* EA4C8 001EA4C8 01000424 */  addiu      $4, $0, 0x1
    /* EA4CC 001EA4CC 08004414 */  bne        $2, $4, .L001EA4F0
    /* EA4D0 001EA4D0 00000000 */   nop
  .L001EA4D4:
    /* EA4D4 001EA4D4 ACB3848F */  lw         $4, -0x4C54($28)
    /* EA4D8 001EA4D8 1000838C */  lw         $3, 0x10($4)
    /* EA4DC 001EA4DC 0010023C */  lui        $2, (0x10000000 >> 16)
    /* EA4E0 001EA4E0 25106200 */  or         $2, $3, $2
    /* EA4E4 001EA4E4 100082AC */  sw         $2, 0x10($4)
    /* EA4E8 001EA4E8 1D000010 */  b          .L001EA560
    /* EA4EC 001EA4EC 00000000 */   nop
  .L001EA4F0:
    /* EA4F0 001EA4F0 ACB3858F */  lw         $5, -0x4C54($28)
    /* EA4F4 001EA4F4 400BA38C */  lw         $3, 0xB40($5)
    /* EA4F8 001EA4F8 2300023C */  lui        $2, %hi(func_0022b120)
    /* EA4FC 001EA4FC 20B14224 */  addiu      $2, $2, %lo(func_0022b120)
    /* EA500 001EA500 17006210 */  beq        $3, $2, .L001EA560
    /* EA504 001EA504 00000000 */   nop
    /* EA508 001EA508 440BA38C */  lw         $3, 0xB44($5)
    /* EA50C 001EA50C 2300023C */  lui        $2, %hi(func_0022b870)
    /* EA510 001EA510 70B84224 */  addiu      $2, $2, %lo(func_0022b870)
    /* EA514 001EA514 12006210 */  beq        $3, $2, .L001EA560
    /* EA518 001EA518 00000000 */   nop
    /* EA51C 001EA51C 0B010524 */  addiu      $5, $0, 0x10B
    /* EA520 001EA520 E47B060C */  jal        func_0019ef90
    /* EA524 001EA524 00000000 */   nop
    /* EA528 001EA528 0D004010 */  beqz       $2, .L001EA560
    /* EA52C 001EA52C 00000000 */   nop
    /* EA530 001EA530 2D204000 */  daddu      $4, $2, $0
    /* EA534 001EA534 20C3060C */  jal        func_001b0c80
    /* EA538 001EA538 00000000 */   nop
    /* EA53C 001EA53C 08004010 */  beqz       $2, .L001EA560
    /* EA540 001EA540 00000000 */   nop
    /* EA544 001EA544 2300043C */  lui        $4, %hi(func_0022b120)
    /* EA548 001EA548 20B18424 */  addiu      $4, $4, %lo(func_0022b120)
    /* EA54C 001EA54C 2300053C */  lui        $5, %hi(func_0022b870)
    /* EA550 001EA550 70B8A524 */  addiu      $5, $5, %lo(func_0022b870)
    /* EA554 001EA554 2D304000 */  daddu      $6, $2, $0
    /* EA558 001EA558 98EB070C */  jal        func_001fae60
    /* EA55C 001EA55C 00000000 */   nop
  .L001EA560:
    /* EA560 001EA560 01000224 */  addiu      $2, $0, 0x1
    /* EA564 001EA564 0000BFDF */  ld         $31, 0x0($29)
    /* EA568 001EA568 1000BD27 */  addiu      $29, $29, 0x10
    /* EA56C 001EA56C 0800E003 */  jr         $31
    /* EA570 001EA570 00000000 */   nop
    /* EA574 001EA574 00000000 */  nop
    /* EA578 001EA578 00000000 */  nop
    /* EA57C 001EA57C 00000000 */  nop
.size func_001ea4a0, 0xe0

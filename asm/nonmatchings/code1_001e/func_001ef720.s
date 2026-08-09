.section .text
.set noat
.set noreorder
glabel func_001ef720
    /* EF720 001EF720 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EF724 001EF724 4000BFFF */  sd         $31, 0x40($29)
    /* EF728 001EF728 3000B37F */  sq         $19, 0x30($29)
    /* EF72C 001EF72C 2000B27F */  sq         $18, 0x20($29)
    /* EF730 001EF730 1000B17F */  sq         $17, 0x10($29)
    /* EF734 001EF734 0000B07F */  sq         $16, 0x0($29)
    /* EF738 001EF738 2D98A000 */  daddu      $19, $5, $0
    /* EF73C 001EF73C 2D880000 */  daddu      $17, $0, $0
    /* EF740 001EF740 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF744 001EF744 7401528C */  lw         $18, 0x174($2)
    /* EF748 001EF748 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* EF74C 001EF74C 18000010 */  b          .L001EF7B0
    /* EF750 001EF750 00000000 */   nop
  .L001EF754:
    /* EF754 001EF754 1A004396 */  lhu        $3, 0x1A($18)
    /* EF758 001EF758 01006230 */  andi       $2, $3, 0x1
    /* EF75C 001EF75C 13004010 */  beqz       $2, .L001EF7AC
    /* EF760 001EF760 00000000 */   nop
    /* EF764 001EF764 08006230 */  andi       $2, $3, 0x8
    /* EF768 001EF768 10004010 */  beqz       $2, .L001EF7AC
    /* EF76C 001EF76C 00000000 */   nop
    /* EF770 001EF770 3000448E */  lw         $4, 0x30($18)
    /* EF774 001EF774 A2008390 */  lbu        $3, 0xA2($4)
    /* EF778 001EF778 01000224 */  addiu      $2, $0, 0x1
    /* EF77C 001EF77C 04106200 */  sllv       $2, $2, $3
    /* EF780 001EF780 24100202 */  and        $2, $16, $2
    /* EF784 001EF784 09004010 */  beqz       $2, .L001EF7AC
    /* EF788 001EF788 00000000 */   nop
    /* EF78C 001EF78C 640A848C */  lw         $4, 0xA64($4)
    /* EF790 001EF790 2D286002 */  daddu      $5, $19, $0
    /* EF794 001EF794 C4C9080C */  jal        func_00232710
    /* EF798 001EF798 00000000 */   nop
    /* EF79C 001EF79C 03004014 */  bnez       $2, .L001EF7AC
    /* EF7A0 001EF7A0 00000000 */   nop
    /* EF7A4 001EF7A4 01002226 */  addiu      $2, $17, 0x1
    /* EF7A8 001EF7A8 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001EF7AC:
    /* EF7AC 001EF7AC 5004528E */  lw         $18, 0x450($18)
  .L001EF7B0:
    /* EF7B0 001EF7B0 E8FF4016 */  bnez       $18, .L001EF754
    /* EF7B4 001EF7B4 00000000 */   nop
    /* EF7B8 001EF7B8 2D102002 */  daddu      $2, $17, $0
    /* EF7BC 001EF7BC 4000BFDF */  ld         $31, 0x40($29)
    /* EF7C0 001EF7C0 3000B37B */  lq         $19, 0x30($29)
    /* EF7C4 001EF7C4 2000B27B */  lq         $18, 0x20($29)
    /* EF7C8 001EF7C8 1000B17B */  lq         $17, 0x10($29)
    /* EF7CC 001EF7CC 0000B07B */  lq         $16, 0x0($29)
    /* EF7D0 001EF7D0 5000BD27 */  addiu      $29, $29, 0x50
    /* EF7D4 001EF7D4 0800E003 */  jr         $31
    /* EF7D8 001EF7D8 00000000 */   nop
    /* EF7DC 001EF7DC 00000000 */  nop
.size func_001ef720, 0xc0

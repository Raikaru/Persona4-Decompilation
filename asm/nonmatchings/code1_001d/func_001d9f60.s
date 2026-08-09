.section .text
.set noat
.set noreorder
glabel func_001d9f60
    /* D9F60 001D9F60 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D9F64 001D9F64 4000BFFF */  sd         $31, 0x40($29)
    /* D9F68 001D9F68 3000B37F */  sq         $19, 0x30($29)
    /* D9F6C 001D9F6C 2000B27F */  sq         $18, 0x20($29)
    /* D9F70 001D9F70 1000B17F */  sq         $17, 0x10($29)
    /* D9F74 001D9F74 0000B07F */  sq         $16, 0x0($29)
    /* D9F78 001D9F78 2D988000 */  daddu      $19, $4, $0
    /* D9F7C 001D9F7C 2D90A000 */  daddu      $18, $5, $0
    /* D9F80 001D9F80 ACB3828F */  lw         $2, -0x4C54($28)
    /* D9F84 001D9F84 7401518C */  lw         $17, 0x174($2)
    /* D9F88 001D9F88 20000010 */  b          .L001DA00C
    /* D9F8C 001D9F8C 00000000 */   nop
  .L001D9F90:
    /* D9F90 001D9F90 1D007112 */  beq        $19, $17, .L001DA008
    /* D9F94 001D9F94 00000000 */   nop
    /* D9F98 001D9F98 1A002396 */  lhu        $3, 0x1A($17)
    /* D9F9C 001D9F9C 01006230 */  andi       $2, $3, 0x1
    /* D9FA0 001D9FA0 19004010 */  beqz       $2, .L001DA008
    /* D9FA4 001D9FA4 00000000 */   nop
    /* D9FA8 001D9FA8 08006230 */  andi       $2, $3, 0x8
    /* D9FAC 001D9FAC 16004010 */  beqz       $2, .L001DA008
    /* D9FB0 001D9FB0 00000000 */   nop
    /* D9FB4 001D9FB4 3000308E */  lw         $16, 0x30($17)
    /* D9FB8 001D9FB8 3000628E */  lw         $2, 0x30($19)
    /* D9FBC 001D9FBC A2004390 */  lbu        $3, 0xA2($2)
    /* D9FC0 001D9FC0 A2000292 */  lbu        $2, 0xA2($16)
    /* D9FC4 001D9FC4 10006214 */  bne        $3, $2, .L001DA008
    /* D9FC8 001D9FC8 00000000 */   nop
    /* D9FCC 001D9FCC 640A048E */  lw         $4, 0xA64($16)
    /* D9FD0 001D9FD0 0800053C */  lui        $5, (0x80000 >> 16)
    /* D9FD4 001D9FD4 C4C9080C */  jal        func_00232710
    /* D9FD8 001D9FD8 00000000 */   nop
    /* D9FDC 001D9FDC 0A004014 */  bnez       $2, .L001DA008
    /* D9FE0 001D9FE0 00000000 */   nop
    /* D9FE4 001D9FE4 640A048E */  lw         $4, 0xA64($16)
    /* D9FE8 001D9FE8 2D284002 */  daddu      $5, $18, $0
    /* D9FEC 001D9FEC 30D0080C */  jal        func_002340c0
    /* D9FF0 001D9FF0 00000000 */   nop
    /* D9FF4 001D9FF4 04004010 */  beqz       $2, .L001DA008
    /* D9FF8 001D9FF8 00000000 */   nop
    /* D9FFC 001D9FFC 01000224 */  addiu      $2, $0, 0x1
    /* DA000 001DA000 05000010 */  b          .L001DA018
    /* DA004 001DA004 00000000 */   nop
  .L001DA008:
    /* DA008 001DA008 5004318E */  lw         $17, 0x450($17)
  .L001DA00C:
    /* DA00C 001DA00C E0FF2016 */  bnez       $17, .L001D9F90
    /* DA010 001DA010 00000000 */   nop
    /* DA014 001DA014 2D100000 */  daddu      $2, $0, $0
  .L001DA018:
    /* DA018 001DA018 4000BFDF */  ld         $31, 0x40($29)
    /* DA01C 001DA01C 3000B37B */  lq         $19, 0x30($29)
    /* DA020 001DA020 2000B27B */  lq         $18, 0x20($29)
    /* DA024 001DA024 1000B17B */  lq         $17, 0x10($29)
    /* DA028 001DA028 0000B07B */  lq         $16, 0x0($29)
    /* DA02C 001DA02C 5000BD27 */  addiu      $29, $29, 0x50
    /* DA030 001DA030 0800E003 */  jr         $31
    /* DA034 001DA034 00000000 */   nop
    /* DA038 001DA038 00000000 */  nop
    /* DA03C 001DA03C 00000000 */  nop
.size func_001d9f60, 0xe0

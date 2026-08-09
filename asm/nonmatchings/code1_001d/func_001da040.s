.section .text
.set noat
.set noreorder
glabel func_001da040
    /* DA040 001DA040 B0FFBD27 */  addiu      $29, $29, -0x50
    /* DA044 001DA044 4000BFFF */  sd         $31, 0x40($29)
    /* DA048 001DA048 3000B37F */  sq         $19, 0x30($29)
    /* DA04C 001DA04C 2000B27F */  sq         $18, 0x20($29)
    /* DA050 001DA050 1000B17F */  sq         $17, 0x10($29)
    /* DA054 001DA054 0000B07F */  sq         $16, 0x0($29)
    /* DA058 001DA058 2D90A000 */  daddu      $18, $5, $0
    /* DA05C 001DA05C 3000828C */  lw         $2, 0x30($4)
    /* DA060 001DA060 A2004290 */  lbu        $2, 0xA2($2)
    /* DA064 001DA064 04004014 */  bnez       $2, .L001DA078
    /* DA068 001DA068 00000000 */   nop
    /* DA06C 001DA06C 01000224 */  addiu      $2, $0, 0x1
    /* DA070 001DA070 02000010 */  b          .L001DA07C
    /* DA074 001DA074 00000000 */   nop
  .L001DA078:
    /* DA078 001DA078 2D100000 */  daddu      $2, $0, $0
  .L001DA07C:
    /* DA07C 001DA07C FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DA080 001DA080 ACB3828F */  lw         $2, -0x4C54($28)
    /* DA084 001DA084 7401518C */  lw         $17, 0x174($2)
    /* DA088 001DA088 1C000010 */  b          .L001DA0FC
    /* DA08C 001DA08C 00000000 */   nop
  .L001DA090:
    /* DA090 001DA090 1A002396 */  lhu        $3, 0x1A($17)
    /* DA094 001DA094 01006230 */  andi       $2, $3, 0x1
    /* DA098 001DA098 17004010 */  beqz       $2, .L001DA0F8
    /* DA09C 001DA09C 00000000 */   nop
    /* DA0A0 001DA0A0 08006230 */  andi       $2, $3, 0x8
    /* DA0A4 001DA0A4 14004010 */  beqz       $2, .L001DA0F8
    /* DA0A8 001DA0A8 00000000 */   nop
    /* DA0AC 001DA0AC 3000338E */  lw         $19, 0x30($17)
    /* DA0B0 001DA0B0 A2006292 */  lbu        $2, 0xA2($19)
    /* DA0B4 001DA0B4 10005014 */  bne        $2, $16, .L001DA0F8
    /* DA0B8 001DA0B8 00000000 */   nop
    /* DA0BC 001DA0BC 640A648E */  lw         $4, 0xA64($19)
    /* DA0C0 001DA0C0 0800053C */  lui        $5, (0x80000 >> 16)
    /* DA0C4 001DA0C4 C4C9080C */  jal        func_00232710
    /* DA0C8 001DA0C8 00000000 */   nop
    /* DA0CC 001DA0CC 0A004014 */  bnez       $2, .L001DA0F8
    /* DA0D0 001DA0D0 00000000 */   nop
    /* DA0D4 001DA0D4 640A648E */  lw         $4, 0xA64($19)
    /* DA0D8 001DA0D8 2D284002 */  daddu      $5, $18, $0
    /* DA0DC 001DA0DC 30D0080C */  jal        func_002340c0
    /* DA0E0 001DA0E0 00000000 */   nop
    /* DA0E4 001DA0E4 04004010 */  beqz       $2, .L001DA0F8
    /* DA0E8 001DA0E8 00000000 */   nop
    /* DA0EC 001DA0EC 01000224 */  addiu      $2, $0, 0x1
    /* DA0F0 001DA0F0 05000010 */  b          .L001DA108
    /* DA0F4 001DA0F4 00000000 */   nop
  .L001DA0F8:
    /* DA0F8 001DA0F8 5004318E */  lw         $17, 0x450($17)
  .L001DA0FC:
    /* DA0FC 001DA0FC E4FF2016 */  bnez       $17, .L001DA090
    /* DA100 001DA100 00000000 */   nop
    /* DA104 001DA104 2D100000 */  daddu      $2, $0, $0
  .L001DA108:
    /* DA108 001DA108 4000BFDF */  ld         $31, 0x40($29)
    /* DA10C 001DA10C 3000B37B */  lq         $19, 0x30($29)
    /* DA110 001DA110 2000B27B */  lq         $18, 0x20($29)
    /* DA114 001DA114 1000B17B */  lq         $17, 0x10($29)
    /* DA118 001DA118 0000B07B */  lq         $16, 0x0($29)
    /* DA11C 001DA11C 5000BD27 */  addiu      $29, $29, 0x50
    /* DA120 001DA120 0800E003 */  jr         $31
    /* DA124 001DA124 00000000 */   nop
    /* DA128 001DA128 00000000 */  nop
    /* DA12C 001DA12C 00000000 */  nop
.size func_001da040, 0xf0

.section .text
.set noat
.set noreorder
glabel func_001d9ca0
    /* D9CA0 001D9CA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D9CA4 001D9CA4 4000BFFF */  sd         $31, 0x40($29)
    /* D9CA8 001D9CA8 3000B37F */  sq         $19, 0x30($29)
    /* D9CAC 001D9CAC 2000B27F */  sq         $18, 0x20($29)
    /* D9CB0 001D9CB0 1000B17F */  sq         $17, 0x10($29)
    /* D9CB4 001D9CB4 0000B07F */  sq         $16, 0x0($29)
    /* D9CB8 001D9CB8 2D98A000 */  daddu      $19, $5, $0
    /* D9CBC 001D9CBC 3000828C */  lw         $2, 0x30($4)
    /* D9CC0 001D9CC0 A2004290 */  lbu        $2, 0xA2($2)
    /* D9CC4 001D9CC4 04004014 */  bnez       $2, .L001D9CD8
    /* D9CC8 001D9CC8 00000000 */   nop
    /* D9CCC 001D9CCC 01000224 */  addiu      $2, $0, 0x1
    /* D9CD0 001D9CD0 02000010 */  b          .L001D9CDC
    /* D9CD4 001D9CD4 00000000 */   nop
  .L001D9CD8:
    /* D9CD8 001D9CD8 2D100000 */  daddu      $2, $0, $0
  .L001D9CDC:
    /* D9CDC 001D9CDC FFFF4330 */  andi       $3, $2, 0xFFFF
    /* D9CE0 001D9CE0 01000224 */  addiu      $2, $0, 0x1
    /* D9CE4 001D9CE4 04106200 */  sllv       $2, $2, $3
    /* D9CE8 001D9CE8 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* D9CEC 001D9CEC ACB3828F */  lw         $2, -0x4C54($28)
    /* D9CF0 001D9CF0 7401528C */  lw         $18, 0x174($2)
    /* D9CF4 001D9CF4 1C000010 */  b          .L001D9D68
    /* D9CF8 001D9CF8 00000000 */   nop
  .L001D9CFC:
    /* D9CFC 001D9CFC 1A004396 */  lhu        $3, 0x1A($18)
    /* D9D00 001D9D00 01006230 */  andi       $2, $3, 0x1
    /* D9D04 001D9D04 17004010 */  beqz       $2, .L001D9D64
    /* D9D08 001D9D08 00000000 */   nop
    /* D9D0C 001D9D0C 08006230 */  andi       $2, $3, 0x8
    /* D9D10 001D9D10 14004010 */  beqz       $2, .L001D9D64
    /* D9D14 001D9D14 00000000 */   nop
    /* D9D18 001D9D18 3000508E */  lw         $16, 0x30($18)
    /* D9D1C 001D9D1C A2000392 */  lbu        $3, 0xA2($16)
    /* D9D20 001D9D20 01000224 */  addiu      $2, $0, 0x1
    /* D9D24 001D9D24 04106200 */  sllv       $2, $2, $3
    /* D9D28 001D9D28 24102202 */  and        $2, $17, $2
    /* D9D2C 001D9D2C 0D004010 */  beqz       $2, .L001D9D64
    /* D9D30 001D9D30 00000000 */   nop
    /* D9D34 001D9D34 640A048E */  lw         $4, 0xA64($16)
    /* D9D38 001D9D38 2D280000 */  daddu      $5, $0, $0
    /* D9D3C 001D9D3C 3C0A090C */  jal        func_002428f0
    /* D9D40 001D9D40 00000000 */   nop
    /* D9D44 001D9D44 07004014 */  bnez       $2, .L001D9D64
    /* D9D48 001D9D48 00000000 */   nop
    /* D9D4C 001D9D4C 640A048E */  lw         $4, 0xA64($16)
    /* D9D50 001D9D50 2D286002 */  daddu      $5, $19, $0
    /* D9D54 001D9D54 C4C9080C */  jal        func_00232710
    /* D9D58 001D9D58 00000000 */   nop
    /* D9D5C 001D9D5C 04004010 */  beqz       $2, .L001D9D70
    /* D9D60 001D9D60 00000000 */   nop
  .L001D9D64:
    /* D9D64 001D9D64 5004528E */  lw         $18, 0x450($18)
  .L001D9D68:
    /* D9D68 001D9D68 E4FF4016 */  bnez       $18, .L001D9CFC
    /* D9D6C 001D9D6C 00000000 */   nop
  .L001D9D70:
    /* D9D70 001D9D70 04004016 */  bnez       $18, .L001D9D84
    /* D9D74 001D9D74 00000000 */   nop
    /* D9D78 001D9D78 01000224 */  addiu      $2, $0, 0x1
    /* D9D7C 001D9D7C 02000010 */  b          .L001D9D88
    /* D9D80 001D9D80 00000000 */   nop
  .L001D9D84:
    /* D9D84 001D9D84 2D100000 */  daddu      $2, $0, $0
  .L001D9D88:
    /* D9D88 001D9D88 4000BFDF */  ld         $31, 0x40($29)
    /* D9D8C 001D9D8C 3000B37B */  lq         $19, 0x30($29)
    /* D9D90 001D9D90 2000B27B */  lq         $18, 0x20($29)
    /* D9D94 001D9D94 1000B17B */  lq         $17, 0x10($29)
    /* D9D98 001D9D98 0000B07B */  lq         $16, 0x0($29)
    /* D9D9C 001D9D9C 5000BD27 */  addiu      $29, $29, 0x50
    /* D9DA0 001D9DA0 0800E003 */  jr         $31
    /* D9DA4 001D9DA4 00000000 */   nop
    /* D9DA8 001D9DA8 00000000 */  nop
    /* D9DAC 001D9DAC 00000000 */  nop
.size func_001d9ca0, 0x110

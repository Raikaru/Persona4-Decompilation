.section .text
.set noat
.set noreorder
glabel func_001e8dd0
    /* E8DD0 001E8DD0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* E8DD4 001E8DD4 3000BFFF */  sd         $31, 0x30($29)
    /* E8DD8 001E8DD8 2000B27F */  sq         $18, 0x20($29)
    /* E8DDC 001E8DDC 1000B17F */  sq         $17, 0x10($29)
    /* E8DE0 001E8DE0 0000B07F */  sq         $16, 0x0($29)
    /* E8DE4 001E8DE4 2D880000 */  daddu      $17, $0, $0
    /* E8DE8 001E8DE8 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* E8DEC 001E8DEC FFFF5034 */  ori        $16, $2, (0xFFFFFFF & 0xFFFF)
    /* E8DF0 001E8DF0 ACB3828F */  lw         $2, -0x4C54($28)
    /* E8DF4 001E8DF4 7401528C */  lw         $18, 0x174($2)
    /* E8DF8 001E8DF8 1D000010 */  b          .L001E8E70
    /* E8DFC 001E8DFC 00000000 */   nop
  .L001E8E00:
    /* E8E00 001E8E00 1A004396 */  lhu        $3, 0x1A($18)
    /* E8E04 001E8E04 01006230 */  andi       $2, $3, 0x1
    /* E8E08 001E8E08 18004010 */  beqz       $2, .L001E8E6C
    /* E8E0C 001E8E0C 00000000 */   nop
    /* E8E10 001E8E10 08006230 */  andi       $2, $3, 0x8
    /* E8E14 001E8E14 15004010 */  beqz       $2, .L001E8E6C
    /* E8E18 001E8E18 00000000 */   nop
    /* E8E1C 001E8E1C 3000438E */  lw         $3, 0x30($18)
    /* E8E20 001E8E20 A2006290 */  lbu        $2, 0xA2($3)
    /* E8E24 001E8E24 11004014 */  bnez       $2, .L001E8E6C
    /* E8E28 001E8E28 00000000 */   nop
    /* E8E2C 001E8E2C 640A648C */  lw         $4, 0xA64($3)
    /* E8E30 001E8E30 2D280000 */  daddu      $5, $0, $0
    /* E8E34 001E8E34 3C0A090C */  jal        func_002428f0
    /* E8E38 001E8E38 00000000 */   nop
    /* E8E3C 001E8E3C 0B004014 */  bnez       $2, .L001E8E6C
    /* E8E40 001E8E40 00000000 */   nop
    /* E8E44 001E8E44 3000428E */  lw         $2, 0x30($18)
    /* E8E48 001E8E48 640A448C */  lw         $4, 0xA64($2)
    /* E8E4C 001E8E4C B4C7080C */  jal        func_00231ed0
    /* E8E50 001E8E50 00000000 */   nop
    /* E8E54 001E8E54 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E8E58 001E8E58 2B085000 */  sltu       $1, $2, $16
    /* E8E5C 001E8E5C 03002010 */  beqz       $1, .L001E8E6C
    /* E8E60 001E8E60 00000000 */   nop
    /* E8E64 001E8E64 2D884002 */  daddu      $17, $18, $0
    /* E8E68 001E8E68 2D804000 */  daddu      $16, $2, $0
  .L001E8E6C:
    /* E8E6C 001E8E6C 5004528E */  lw         $18, 0x450($18)
  .L001E8E70:
    /* E8E70 001E8E70 E3FF4016 */  bnez       $18, .L001E8E00
    /* E8E74 001E8E74 00000000 */   nop
    /* E8E78 001E8E78 0800238E */  lw         $3, 0x8($17)
    /* E8E7C 001E8E7C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E8E80 001E8E80 25206200 */  or         $4, $3, $2
    /* E8E84 001E8E84 D4730A0C */  jal        func_0029cf50
    /* E8E88 001E8E88 00000000 */   nop
    /* E8E8C 001E8E8C 01000224 */  addiu      $2, $0, 0x1
    /* E8E90 001E8E90 3000BFDF */  ld         $31, 0x30($29)
    /* E8E94 001E8E94 2000B27B */  lq         $18, 0x20($29)
    /* E8E98 001E8E98 1000B17B */  lq         $17, 0x10($29)
    /* E8E9C 001E8E9C 0000B07B */  lq         $16, 0x0($29)
    /* E8EA0 001E8EA0 4000BD27 */  addiu      $29, $29, 0x40
    /* E8EA4 001E8EA4 0800E003 */  jr         $31
    /* E8EA8 001E8EA8 00000000 */   nop
    /* E8EAC 001E8EAC 00000000 */  nop
.size func_001e8dd0, 0xe0

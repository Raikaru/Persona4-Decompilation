.section .text
.set noat
.set noreorder
glabel func_001e6dc0
    /* E6DC0 001E6DC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* E6DC4 001E6DC4 3000BFFF */  sd         $31, 0x30($29)
    /* E6DC8 001E6DC8 2000B27F */  sq         $18, 0x20($29)
    /* E6DCC 001E6DCC 1000B17F */  sq         $17, 0x10($29)
    /* E6DD0 001E6DD0 0000B07F */  sq         $16, 0x0($29)
    /* E6DD4 001E6DD4 2D880000 */  daddu      $17, $0, $0
    /* E6DD8 001E6DD8 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* E6DDC 001E6DDC FFFF5034 */  ori        $16, $2, (0xFFFFFFF & 0xFFFF)
    /* E6DE0 001E6DE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* E6DE4 001E6DE4 7401528C */  lw         $18, 0x174($2)
    /* E6DE8 001E6DE8 1E000010 */  b          .L001E6E64
    /* E6DEC 001E6DEC 00000000 */   nop
  .L001E6DF0:
    /* E6DF0 001E6DF0 1A004396 */  lhu        $3, 0x1A($18)
    /* E6DF4 001E6DF4 01006230 */  andi       $2, $3, 0x1
    /* E6DF8 001E6DF8 19004010 */  beqz       $2, .L001E6E60
    /* E6DFC 001E6DFC 00000000 */   nop
    /* E6E00 001E6E00 08006230 */  andi       $2, $3, 0x8
    /* E6E04 001E6E04 16004010 */  beqz       $2, .L001E6E60
    /* E6E08 001E6E08 00000000 */   nop
    /* E6E0C 001E6E0C 3000448E */  lw         $4, 0x30($18)
    /* E6E10 001E6E10 A2008390 */  lbu        $3, 0xA2($4)
    /* E6E14 001E6E14 01000224 */  addiu      $2, $0, 0x1
    /* E6E18 001E6E18 11006214 */  bne        $3, $2, .L001E6E60
    /* E6E1C 001E6E1C 00000000 */   nop
    /* E6E20 001E6E20 640A848C */  lw         $4, 0xA64($4)
    /* E6E24 001E6E24 2D280000 */  daddu      $5, $0, $0
    /* E6E28 001E6E28 3C0A090C */  jal        func_002428f0
    /* E6E2C 001E6E2C 00000000 */   nop
    /* E6E30 001E6E30 0B004014 */  bnez       $2, .L001E6E60
    /* E6E34 001E6E34 00000000 */   nop
    /* E6E38 001E6E38 3000428E */  lw         $2, 0x30($18)
    /* E6E3C 001E6E3C 640A448C */  lw         $4, 0xA64($2)
    /* E6E40 001E6E40 B4C7080C */  jal        func_00231ed0
    /* E6E44 001E6E44 00000000 */   nop
    /* E6E48 001E6E48 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E6E4C 001E6E4C 2B085000 */  sltu       $1, $2, $16
    /* E6E50 001E6E50 03002010 */  beqz       $1, .L001E6E60
    /* E6E54 001E6E54 00000000 */   nop
    /* E6E58 001E6E58 2D884002 */  daddu      $17, $18, $0
    /* E6E5C 001E6E5C 2D804000 */  daddu      $16, $2, $0
  .L001E6E60:
    /* E6E60 001E6E60 5004528E */  lw         $18, 0x450($18)
  .L001E6E64:
    /* E6E64 001E6E64 E2FF4016 */  bnez       $18, .L001E6DF0
    /* E6E68 001E6E68 00000000 */   nop
    /* E6E6C 001E6E6C 0800238E */  lw         $3, 0x8($17)
    /* E6E70 001E6E70 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E6E74 001E6E74 25206200 */  or         $4, $3, $2
    /* E6E78 001E6E78 D4730A0C */  jal        func_0029cf50
    /* E6E7C 001E6E7C 00000000 */   nop
    /* E6E80 001E6E80 01000224 */  addiu      $2, $0, 0x1
    /* E6E84 001E6E84 3000BFDF */  ld         $31, 0x30($29)
    /* E6E88 001E6E88 2000B27B */  lq         $18, 0x20($29)
    /* E6E8C 001E6E8C 1000B17B */  lq         $17, 0x10($29)
    /* E6E90 001E6E90 0000B07B */  lq         $16, 0x0($29)
    /* E6E94 001E6E94 4000BD27 */  addiu      $29, $29, 0x40
    /* E6E98 001E6E98 0800E003 */  jr         $31
    /* E6E9C 001E6E9C 00000000 */   nop
.size func_001e6dc0, 0xe0

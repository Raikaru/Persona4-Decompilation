.section .text
.set noat
.set noreorder
glabel func_001d9db0
    /* D9DB0 001D9DB0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D9DB4 001D9DB4 4000BFFF */  sd         $31, 0x40($29)
    /* D9DB8 001D9DB8 3000B37F */  sq         $19, 0x30($29)
    /* D9DBC 001D9DBC 2000B27F */  sq         $18, 0x20($29)
    /* D9DC0 001D9DC0 1000B17F */  sq         $17, 0x10($29)
    /* D9DC4 001D9DC4 0000B07F */  sq         $16, 0x0($29)
    /* D9DC8 001D9DC8 2D988000 */  daddu      $19, $4, $0
    /* D9DCC 001D9DCC 2D90A000 */  daddu      $18, $5, $0
    /* D9DD0 001D9DD0 ACB3828F */  lw         $2, -0x4C54($28)
    /* D9DD4 001D9DD4 7401518C */  lw         $17, 0x174($2)
    /* D9DD8 001D9DD8 1D000010 */  b          .L001D9E50
    /* D9DDC 001D9DDC 00000000 */   nop
  .L001D9DE0:
    /* D9DE0 001D9DE0 1A007112 */  beq        $19, $17, .L001D9E4C
    /* D9DE4 001D9DE4 00000000 */   nop
    /* D9DE8 001D9DE8 1A002396 */  lhu        $3, 0x1A($17)
    /* D9DEC 001D9DEC 01006230 */  andi       $2, $3, 0x1
    /* D9DF0 001D9DF0 16004010 */  beqz       $2, .L001D9E4C
    /* D9DF4 001D9DF4 00000000 */   nop
    /* D9DF8 001D9DF8 08006230 */  andi       $2, $3, 0x8
    /* D9DFC 001D9DFC 13004010 */  beqz       $2, .L001D9E4C
    /* D9E00 001D9E00 00000000 */   nop
    /* D9E04 001D9E04 3000308E */  lw         $16, 0x30($17)
    /* D9E08 001D9E08 3000628E */  lw         $2, 0x30($19)
    /* D9E0C 001D9E0C A2004390 */  lbu        $3, 0xA2($2)
    /* D9E10 001D9E10 A2000292 */  lbu        $2, 0xA2($16)
    /* D9E14 001D9E14 0D006214 */  bne        $3, $2, .L001D9E4C
    /* D9E18 001D9E18 00000000 */   nop
    /* D9E1C 001D9E1C 640A048E */  lw         $4, 0xA64($16)
    /* D9E20 001D9E20 0800053C */  lui        $5, (0x80000 >> 16)
    /* D9E24 001D9E24 C4C9080C */  jal        func_00232710
    /* D9E28 001D9E28 00000000 */   nop
    /* D9E2C 001D9E2C 07004014 */  bnez       $2, .L001D9E4C
    /* D9E30 001D9E30 00000000 */   nop
    /* D9E34 001D9E34 A4000296 */  lhu        $2, 0xA4($16)
    /* D9E38 001D9E38 04005214 */  bne        $2, $18, .L001D9E4C
    /* D9E3C 001D9E3C 00000000 */   nop
    /* D9E40 001D9E40 01000224 */  addiu      $2, $0, 0x1
    /* D9E44 001D9E44 05000010 */  b          .L001D9E5C
    /* D9E48 001D9E48 00000000 */   nop
  .L001D9E4C:
    /* D9E4C 001D9E4C 5004318E */  lw         $17, 0x450($17)
  .L001D9E50:
    /* D9E50 001D9E50 E3FF2016 */  bnez       $17, .L001D9DE0
    /* D9E54 001D9E54 00000000 */   nop
    /* D9E58 001D9E58 2D100000 */  daddu      $2, $0, $0
  .L001D9E5C:
    /* D9E5C 001D9E5C 4000BFDF */  ld         $31, 0x40($29)
    /* D9E60 001D9E60 3000B37B */  lq         $19, 0x30($29)
    /* D9E64 001D9E64 2000B27B */  lq         $18, 0x20($29)
    /* D9E68 001D9E68 1000B17B */  lq         $17, 0x10($29)
    /* D9E6C 001D9E6C 0000B07B */  lq         $16, 0x0($29)
    /* D9E70 001D9E70 5000BD27 */  addiu      $29, $29, 0x50
    /* D9E74 001D9E74 0800E003 */  jr         $31
    /* D9E78 001D9E78 00000000 */   nop
    /* D9E7C 001D9E7C 00000000 */  nop
.size func_001d9db0, 0xd0

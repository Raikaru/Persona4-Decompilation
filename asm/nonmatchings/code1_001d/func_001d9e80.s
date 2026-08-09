.section .text
.set noat
.set noreorder
glabel func_001d9e80
    /* D9E80 001D9E80 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D9E84 001D9E84 4000BFFF */  sd         $31, 0x40($29)
    /* D9E88 001D9E88 3000B37F */  sq         $19, 0x30($29)
    /* D9E8C 001D9E8C 2000B27F */  sq         $18, 0x20($29)
    /* D9E90 001D9E90 1000B17F */  sq         $17, 0x10($29)
    /* D9E94 001D9E94 0000B07F */  sq         $16, 0x0($29)
    /* D9E98 001D9E98 2D90A000 */  daddu      $18, $5, $0
    /* D9E9C 001D9E9C 3000828C */  lw         $2, 0x30($4)
    /* D9EA0 001D9EA0 A2004290 */  lbu        $2, 0xA2($2)
    /* D9EA4 001D9EA4 04004014 */  bnez       $2, .L001D9EB8
    /* D9EA8 001D9EA8 00000000 */   nop
    /* D9EAC 001D9EAC 01000224 */  addiu      $2, $0, 0x1
    /* D9EB0 001D9EB0 02000010 */  b          .L001D9EBC
    /* D9EB4 001D9EB4 00000000 */   nop
  .L001D9EB8:
    /* D9EB8 001D9EB8 2D100000 */  daddu      $2, $0, $0
  .L001D9EBC:
    /* D9EBC 001D9EBC FFFF5030 */  andi       $16, $2, 0xFFFF
    /* D9EC0 001D9EC0 ACB3828F */  lw         $2, -0x4C54($28)
    /* D9EC4 001D9EC4 7401518C */  lw         $17, 0x174($2)
    /* D9EC8 001D9EC8 19000010 */  b          .L001D9F30
    /* D9ECC 001D9ECC 00000000 */   nop
  .L001D9ED0:
    /* D9ED0 001D9ED0 1A002396 */  lhu        $3, 0x1A($17)
    /* D9ED4 001D9ED4 01006230 */  andi       $2, $3, 0x1
    /* D9ED8 001D9ED8 14004010 */  beqz       $2, .L001D9F2C
    /* D9EDC 001D9EDC 00000000 */   nop
    /* D9EE0 001D9EE0 08006230 */  andi       $2, $3, 0x8
    /* D9EE4 001D9EE4 11004010 */  beqz       $2, .L001D9F2C
    /* D9EE8 001D9EE8 00000000 */   nop
    /* D9EEC 001D9EEC 3000338E */  lw         $19, 0x30($17)
    /* D9EF0 001D9EF0 A2006292 */  lbu        $2, 0xA2($19)
    /* D9EF4 001D9EF4 0D005014 */  bne        $2, $16, .L001D9F2C
    /* D9EF8 001D9EF8 00000000 */   nop
    /* D9EFC 001D9EFC 640A648E */  lw         $4, 0xA64($19)
    /* D9F00 001D9F00 0800053C */  lui        $5, (0x80000 >> 16)
    /* D9F04 001D9F04 C4C9080C */  jal        func_00232710
    /* D9F08 001D9F08 00000000 */   nop
    /* D9F0C 001D9F0C 07004014 */  bnez       $2, .L001D9F2C
    /* D9F10 001D9F10 00000000 */   nop
    /* D9F14 001D9F14 A4006296 */  lhu        $2, 0xA4($19)
    /* D9F18 001D9F18 04005214 */  bne        $2, $18, .L001D9F2C
    /* D9F1C 001D9F1C 00000000 */   nop
    /* D9F20 001D9F20 01000224 */  addiu      $2, $0, 0x1
    /* D9F24 001D9F24 05000010 */  b          .L001D9F3C
    /* D9F28 001D9F28 00000000 */   nop
  .L001D9F2C:
    /* D9F2C 001D9F2C 5004318E */  lw         $17, 0x450($17)
  .L001D9F30:
    /* D9F30 001D9F30 E7FF2016 */  bnez       $17, .L001D9ED0
    /* D9F34 001D9F34 00000000 */   nop
    /* D9F38 001D9F38 2D100000 */  daddu      $2, $0, $0
  .L001D9F3C:
    /* D9F3C 001D9F3C 4000BFDF */  ld         $31, 0x40($29)
    /* D9F40 001D9F40 3000B37B */  lq         $19, 0x30($29)
    /* D9F44 001D9F44 2000B27B */  lq         $18, 0x20($29)
    /* D9F48 001D9F48 1000B17B */  lq         $17, 0x10($29)
    /* D9F4C 001D9F4C 0000B07B */  lq         $16, 0x0($29)
    /* D9F50 001D9F50 5000BD27 */  addiu      $29, $29, 0x50
    /* D9F54 001D9F54 0800E003 */  jr         $31
    /* D9F58 001D9F58 00000000 */   nop
    /* D9F5C 001D9F5C 00000000 */  nop
.size func_001d9e80, 0xe0

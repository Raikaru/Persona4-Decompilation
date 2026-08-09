.section .text
.set noat
.set noreorder
glabel func_001b0e90
    /* B0E90 001B0E90 28008290 */  lbu        $2, 0x28($4)
    /* B0E94 001B0E94 04004014 */  bnez       $2, .L001B0EA8
    /* B0E98 001B0E98 00000000 */   nop
    /* B0E9C 001B0E9C 29008290 */  lbu        $2, 0x29($4)
    /* B0EA0 001B0EA0 04004010 */  beqz       $2, .L001B0EB4
    /* B0EA4 001B0EA4 00000000 */   nop
  .L001B0EA8:
    /* B0EA8 001B0EA8 01000224 */  addiu      $2, $0, 0x1
    /* B0EAC 001B0EAC 18000010 */  b          .L001B0F10
    /* B0EB0 001B0EB0 00000000 */   nop
  .L001B0EB4:
    /* B0EB4 001B0EB4 ACB3838F */  lw         $3, -0x4C54($28)
    /* B0EB8 001B0EB8 0C00628C */  lw         $2, 0xC($3)
    /* B0EBC 001B0EBC 08004230 */  andi       $2, $2, 0x8
    /* B0EC0 001B0EC0 04004014 */  bnez       $2, .L001B0ED4
    /* B0EC4 001B0EC4 00000000 */   nop
    /* B0EC8 001B0EC8 01000224 */  addiu      $2, $0, 0x1
    /* B0ECC 001B0ECC 10000010 */  b          .L001B0F10
    /* B0ED0 001B0ED0 00000000 */   nop
  .L001B0ED4:
    /* B0ED4 001B0ED4 18008294 */  lhu        $2, 0x18($4)
    /* B0ED8 001B0ED8 04004230 */  andi       $2, $2, 0x4
    /* B0EDC 001B0EDC 09004014 */  bnez       $2, .L001B0F04
    /* B0EE0 001B0EE0 00000000 */   nop
    /* B0EE4 001B0EE4 CC02628C */  lw         $2, 0x2CC($3)
    /* B0EE8 001B0EE8 06004010 */  beqz       $2, .L001B0F04
    /* B0EEC 001B0EEC 00000000 */   nop
    /* B0EF0 001B0EF0 04004414 */  bne        $2, $4, .L001B0F04
    /* B0EF4 001B0EF4 00000000 */   nop
    /* B0EF8 001B0EF8 01000224 */  addiu      $2, $0, 0x1
    /* B0EFC 001B0EFC 04000010 */  b          .L001B0F10
    /* B0F00 001B0F00 00000000 */   nop
  .L001B0F04:
    /* B0F04 001B0F04 A002628C */  lw         $2, 0x2A0($3)
    /* B0F08 001B0F08 26104400 */  xor        $2, $2, $4
    /* B0F0C 001B0F0C 0100422C */  sltiu      $2, $2, 0x1
  .L001B0F10:
    /* B0F10 001B0F10 0800E003 */  jr         $31
    /* B0F14 001B0F14 00000000 */   nop
    /* B0F18 001B0F18 00000000 */  nop
    /* B0F1C 001B0F1C 00000000 */  nop
.size func_001b0e90, 0x90

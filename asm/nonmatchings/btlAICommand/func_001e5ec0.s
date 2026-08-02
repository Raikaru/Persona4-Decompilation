.section .text
.set noat
.set noreorder
glabel func_001e5ec0
    /* E5EC0 001E5EC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5EC4 001E5EC4 1000BFFF */  sd         $31, 0x10($29)
    /* E5EC8 001E5EC8 0000B07F */  sq         $16, 0x0($29)
    /* E5ECC 001E5ECC 14740A0C */  jal        func_0029d050
    /* E5ED0 001E5ED0 00000000 */   nop
    /* E5ED4 001E5ED4 2D804000 */  daddu      $16, $2, $0
    /* E5ED8 001E5ED8 2D200000 */  daddu      $4, $0, $0
    /* E5EDC 001E5EDC 00730A0C */  jal        func_0029cc00
    /* E5EE0 001E5EE0 00000000 */   nop
    /* E5EE4 001E5EE4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E5EE8 001E5EE8 08004014 */  bnez       $2, .L001E5F0C
    /* E5EEC 001E5EEC 00000000 */   nop
    /* E5EF0 001E5EF0 3000028E */  lw         $2, 0x30($16)
    /* E5EF4 001E5EF4 640A438C */  lw         $3, 0xA64($2)
    /* E5EF8 001E5EF8 00006294 */  lhu        $2, 0x0($3)
    /* E5EFC 001E5EFC 10004234 */  ori        $2, $2, 0x10
    /* E5F00 001E5F00 000062A4 */  sh         $2, 0x0($3)
    /* E5F04 001E5F04 06000010 */  b          .L001E5F20
    /* E5F08 001E5F08 00000000 */   nop
  .L001E5F0C:
    /* E5F0C 001E5F0C 3000028E */  lw         $2, 0x30($16)
    /* E5F10 001E5F10 640A438C */  lw         $3, 0xA64($2)
    /* E5F14 001E5F14 00006294 */  lhu        $2, 0x0($3)
    /* E5F18 001E5F18 EFFF4230 */  andi       $2, $2, 0xFFEF
    /* E5F1C 001E5F1C 000062A4 */  sh         $2, 0x0($3)
  .L001E5F20:
    /* E5F20 001E5F20 01000224 */  addiu      $2, $0, 0x1
    /* E5F24 001E5F24 1000BFDF */  ld         $31, 0x10($29)
    /* E5F28 001E5F28 0000B07B */  lq         $16, 0x0($29)
    /* E5F2C 001E5F2C 2000BD27 */  addiu      $29, $29, 0x20
    /* E5F30 001E5F30 0800E003 */  jr         $31
    /* E5F34 001E5F34 00000000 */   nop
    /* E5F38 001E5F38 00000000 */  nop
    /* E5F3C 001E5F3C 00000000 */  nop
.size func_001e5ec0, 0x80

.section .text
.set noat
.set noreorder
glabel func_001f5ed0
    /* F5ED0 001F5ED0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F5ED4 001F5ED4 1000BFFF */  sd         $31, 0x10($29)
    /* F5ED8 001F5ED8 0000B07F */  sq         $16, 0x0($29)
    /* F5EDC 001F5EDC 2D808000 */  daddu      $16, $4, $0
    /* F5EE0 001F5EE0 1400828C */  lw         $2, 0x14($4)
    /* F5EE4 001F5EE4 09004014 */  bnez       $2, .L001F5F0C
    /* F5EE8 001F5EE8 00000000 */   nop
    /* F5EEC 001F5EEC 0000048E */  lw         $4, 0x0($16)
    /* F5EF0 001F5EF0 04000596 */  lhu        $5, 0x4($16)
    /* F5EF4 001F5EF4 0800068E */  lw         $6, 0x8($16)
    /* F5EF8 001F5EF8 0C00078E */  lw         $7, 0xC($16)
    /* F5EFC 001F5EFC 1000088E */  lw         $8, 0x10($16)
    /* F5F00 001F5F00 B4D5070C */  jal        func_001f56d0
    /* F5F04 001F5F04 00000000 */   nop
    /* F5F08 001F5F08 140002AE */  sw         $2, 0x14($16)
  .L001F5F0C:
    /* F5F0C 001F5F0C 1400028E */  lw         $2, 0x14($16)
    /* F5F10 001F5F10 01000324 */  addiu      $3, $0, 0x1
    /* F5F14 001F5F14 0E004314 */  bne        $2, $3, .L001F5F50
    /* F5F18 001F5F18 00000000 */   nop
    /* F5F1C 001F5F1C 1000038E */  lw         $3, 0x10($16)
    /* F5F20 001F5F20 01006330 */  andi       $3, $3, 0x1
    /* F5F24 001F5F24 0A006010 */  beqz       $3, .L001F5F50
    /* F5F28 001F5F28 00000000 */   nop
    /* F5F2C 001F5F2C ACB3848F */  lw         $4, -0x4C54($28)
    /* F5F30 001F5F30 4E0A8394 */  lhu        $3, 0xA4E($4)
    /* F5F34 001F5F34 01006330 */  andi       $3, $3, 0x1
    /* F5F38 001F5F38 04006014 */  bnez       $3, .L001F5F4C
    /* F5F3C 001F5F3C 00000000 */   nop
    /* F5F40 001F5F40 500A8394 */  lhu        $3, 0xA50($4)
    /* F5F44 001F5F44 02006010 */  beqz       $3, .L001F5F50
    /* F5F48 001F5F48 00000000 */   nop
  .L001F5F4C:
    /* F5F4C 001F5F4C 2D100000 */  daddu      $2, $0, $0
  .L001F5F50:
    /* F5F50 001F5F50 1000BFDF */  ld         $31, 0x10($29)
    /* F5F54 001F5F54 0000B07B */  lq         $16, 0x0($29)
    /* F5F58 001F5F58 2000BD27 */  addiu      $29, $29, 0x20
    /* F5F5C 001F5F5C 0800E003 */  jr         $31
    /* F5F60 001F5F60 00000000 */   nop
    /* F5F64 001F5F64 00000000 */  nop
    /* F5F68 001F5F68 00000000 */  nop
    /* F5F6C 001F5F6C 00000000 */  nop
.size func_001f5ed0, 0xa0

.section .text
.set noat
.set noreorder
glabel func_001c3eb0
    /* C3EB0 001C3EB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* C3EB4 001C3EB4 1000BFFF */  sd         $31, 0x10($29)
    /* C3EB8 001C3EB8 0000B07F */  sq         $16, 0x0($29)
    /* C3EBC 001C3EBC 2D808000 */  daddu      $16, $4, $0
    /* C3EC0 001C3EC0 E000848C */  lw         $4, 0xE0($4)
    /* C3EC4 001C3EC4 22008010 */  beqz       $4, .L001C3F50
    /* C3EC8 001C3EC8 00000000 */   nop
    /* C3ECC 001C3ECC 1A008394 */  lhu        $3, 0x1A($4)
    /* C3ED0 001C3ED0 01006330 */  andi       $3, $3, 0x1
    /* C3ED4 001C3ED4 1E006010 */  beqz       $3, .L001C3F50
    /* C3ED8 001C3ED8 00000000 */   nop
    /* C3EDC 001C3EDC DC00028E */  lw         $2, 0xDC($16)
    /* C3EE0 001C3EE0 11004014 */  bnez       $2, .L001C3F28
    /* C3EE4 001C3EE4 00000000 */   nop
    /* C3EE8 001C3EE8 0900A014 */  bnez       $5, .L001C3F10
    /* C3EEC 001C3EEC 00000000 */   nop
    /* C3EF0 001C3EF0 00608044 */  mtc1       $0, $f12
    /* C3EF4 001C3EF4 2D280000 */  daddu      $5, $0, $0
    /* C3EF8 001C3EF8 2D300000 */  daddu      $6, $0, $0
    /* C3EFC 001C3EFC 03000724 */  addiu      $7, $0, 0x3
    /* C3F00 001C3F00 50F3060C */  jal        func_001bcd40
    /* C3F04 001C3F04 00000000 */   nop
    /* C3F08 001C3F08 07000010 */  b          .L001C3F28
    /* C3F0C 001C3F0C 00000000 */   nop
  .L001C3F10:
    /* C3F10 001C3F10 00608044 */  mtc1       $0, $f12
    /* C3F14 001C3F14 2D280000 */  daddu      $5, $0, $0
    /* C3F18 001C3F18 2D300000 */  daddu      $6, $0, $0
    /* C3F1C 001C3F1C 11000724 */  addiu      $7, $0, 0x11
    /* C3F20 001C3F20 50F3060C */  jal        func_001bcd40
    /* C3F24 001C3F24 00000000 */   nop
  .L001C3F28:
    /* C3F28 001C3F28 2D200002 */  daddu      $4, $16, $0
    /* C3F2C 001C3F2C 2C01058E */  lw         $5, 0x12C($16)
    /* C3F30 001C3F30 58F1060C */  jal        func_001bc560
    /* C3F34 001C3F34 00000000 */   nop
    /* C3F38 001C3F38 05004010 */  beqz       $2, .L001C3F50
    /* C3F3C 001C3F3C 00000000 */   nop
    /* C3F40 001C3F40 2C01048E */  lw         $4, 0x12C($16)
    /* C3F44 001C3F44 30010596 */  lhu        $5, 0x130($16)
    /* C3F48 001C3F48 9C77060C */  jal        func_0019de70
    /* C3F4C 001C3F4C 00000000 */   nop
  .L001C3F50:
    /* C3F50 001C3F50 1000BFDF */  ld         $31, 0x10($29)
    /* C3F54 001C3F54 0000B07B */  lq         $16, 0x0($29)
    /* C3F58 001C3F58 2000BD27 */  addiu      $29, $29, 0x20
    /* C3F5C 001C3F5C 0800E003 */  jr         $31
    /* C3F60 001C3F60 00000000 */   nop
    /* C3F64 001C3F64 00000000 */  nop
    /* C3F68 001C3F68 00000000 */  nop
    /* C3F6C 001C3F6C 00000000 */  nop
.size func_001c3eb0, 0xc0

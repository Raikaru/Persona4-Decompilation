.section .text
.set noat
.set noreorder
glabel func_0022ba40
    /* 12BA40 0022BA40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12BA44 0022BA44 0000BFFF */  sd         $31, 0x0($29)
    /* 12BA48 0022BA48 ACB3838F */  lw         $3, -0x4C54($28)
    /* 12BA4C 0022BA4C 8001648C */  lw         $4, 0x180($3)
    /* 12BA50 0022BA50 0E010324 */  addiu      $3, $0, 0x10E
    /* 12BA54 0022BA54 05000010 */  b          .L0022BA6C
    /* 12BA58 0022BA58 00000000 */   nop
  .L0022BA5C:
    /* 12BA5C 0022BA5C A4008594 */  lhu        $5, 0xA4($4)
    /* 12BA60 0022BA60 0600A310 */  beq        $5, $3, .L0022BA7C
    /* 12BA64 0022BA64 00000000 */   nop
    /* 12BA68 0022BA68 6C0A848C */  lw         $4, 0xA6C($4)
  .L0022BA6C:
    /* 12BA6C 0022BA6C 00000000 */  nop
    /* 12BA70 0022BA70 00000000 */  nop
    /* 12BA74 0022BA74 F9FF8014 */  bnez       $4, .L0022BA5C
    /* 12BA78 0022BA78 00000000 */   nop
  .L0022BA7C:
    /* 12BA7C 0022BA7C 0B008010 */  beqz       $4, .L0022BAAC
    /* 12BA80 0022BA80 00000000 */   nop
    /* 12BA84 0022BA84 20C3060C */  jal        func_001b0c80
    /* 12BA88 0022BA88 00000000 */   nop
    /* 12BA8C 0022BA8C 2D204000 */  daddu      $4, $2, $0
    /* 12BA90 0022BA90 06008010 */  beqz       $4, .L0022BAAC
    /* 12BA94 0022BA94 00000000 */   nop
    /* 12BA98 0022BA98 2D280000 */  daddu      $5, $0, $0
    /* 12BA9C 0022BA9C ACCB070C */  jal        func_001f2eb0
    /* 12BAA0 0022BAA0 00000000 */   nop
    /* 12BAA4 0022BAA4 4CDD070C */  jal        func_001f7530
    /* 12BAA8 0022BAA8 00000000 */   nop
  .L0022BAAC:
    /* 12BAAC 0022BAAC 0000BFDF */  ld         $31, 0x0($29)
    /* 12BAB0 0022BAB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 12BAB4 0022BAB4 0800E003 */  jr         $31
    /* 12BAB8 0022BAB8 00000000 */   nop
    /* 12BABC 0022BABC 00000000 */  nop
.size func_0022ba40, 0x80

.section .text
.set noat
.set noreorder
glabel func_0022bc80
    /* 12BC80 0022BC80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12BC84 0022BC84 0000BFFF */  sd         $31, 0x0($29)
    /* 12BC88 0022BC88 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12BC8C 0022BC8C A00B458C */  lw         $5, 0xBA0($2)
    /* 12BC90 0022BC90 0400A014 */  bnez       $5, .L0022BCA4
    /* 12BC94 0022BC94 00000000 */   nop
    /* 12BC98 0022BC98 2D100000 */  daddu      $2, $0, $0
    /* 12BC9C 0022BC9C 13000010 */  b          .L0022BCEC
    /* 12BCA0 0022BCA0 00000000 */   nop
  .L0022BCA4:
    /* 12BCA4 0022BCA4 A40B4394 */  lhu        $3, 0xBA4($2)
    /* 12BCA8 0022BCA8 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* 12BCAC 0022BCAC 04006210 */  beq        $3, $2, .L0022BCC0
    /* 12BCB0 0022BCB0 00000000 */   nop
    /* 12BCB4 0022BCB4 2D100000 */  daddu      $2, $0, $0
    /* 12BCB8 0022BCB8 0C000010 */  b          .L0022BCEC
    /* 12BCBC 0022BCBC 00000000 */   nop
  .L0022BCC0:
    /* 12BCC0 0022BCC0 2D20A000 */  daddu      $4, $5, $0
    /* 12BCC4 0022BCC4 2449110C */  jal        func_00452490
    /* 12BCC8 0022BCC8 00000000 */   nop
    /* 12BCCC 0022BCCC 06004014 */  bnez       $2, .L0022BCE8
    /* 12BCD0 0022BCD0 00000000 */   nop
    /* 12BCD4 0022BCD4 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12BCD8 0022BCD8 A00B40AC */  sw         $0, 0xBA0($2)
    /* 12BCDC 0022BCDC 2D100000 */  daddu      $2, $0, $0
    /* 12BCE0 0022BCE0 02000010 */  b          .L0022BCEC
    /* 12BCE4 0022BCE4 00000000 */   nop
  .L0022BCE8:
    /* 12BCE8 0022BCE8 01000224 */  addiu      $2, $0, 0x1
  .L0022BCEC:
    /* 12BCEC 0022BCEC 0000BFDF */  ld         $31, 0x0($29)
    /* 12BCF0 0022BCF0 1000BD27 */  addiu      $29, $29, 0x10
    /* 12BCF4 0022BCF4 0800E003 */  jr         $31
    /* 12BCF8 0022BCF8 00000000 */   nop
    /* 12BCFC 0022BCFC 00000000 */  nop
.size func_0022bc80, 0x80

.section .text
.set noat
.set noreorder
glabel func_001f0d30
    /* F0D30 001F0D30 2D480000 */  daddu      $9, $0, $0
    /* F0D34 001F0D34 6A008794 */  lhu        $7, 0x6A($4)
    /* F0D38 001F0D38 0800033C */  lui        $3, (0x80000 >> 16)
    /* F0D3C 001F0D3C 1B000010 */  b          .L001F0DAC
    /* F0D40 001F0D40 00000000 */   nop
  .L001F0D44:
    /* F0D44 001F0D44 FFFF2231 */  andi       $2, $9, 0xFFFF
    /* F0D48 001F0D48 80100200 */  sll        $2, $2, 2
    /* F0D4C 001F0D4C 21108200 */  addu       $2, $4, $2
    /* F0D50 001F0D50 3800468C */  lw         $6, 0x38($2)
    /* F0D54 001F0D54 2D400000 */  daddu      $8, $0, $0
    /* F0D58 001F0D58 D900C590 */  lbu        $5, 0xD9($6)
    /* F0D5C 001F0D5C 0D000010 */  b          .L001F0D94
    /* F0D60 001F0D60 00000000 */   nop
  .L001F0D64:
    /* F0D64 001F0D64 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0D68 001F0D68 40110200 */  sll        $2, $2, 5
    /* F0D6C 001F0D6C 2110C200 */  addu       $2, $6, $2
    /* F0D70 001F0D70 FC00428C */  lw         $2, 0xFC($2)
    /* F0D74 001F0D74 24104300 */  and        $2, $2, $3
    /* F0D78 001F0D78 04004010 */  beqz       $2, .L001F0D8C
    /* F0D7C 001F0D7C 00000000 */   nop
    /* F0D80 001F0D80 01000224 */  addiu      $2, $0, 0x1
    /* F0D84 001F0D84 0E000010 */  b          .L001F0DC0
    /* F0D88 001F0D88 00000000 */   nop
  .L001F0D8C:
    /* F0D8C 001F0D8C 01000225 */  addiu      $2, $8, 0x1
    /* F0D90 001F0D90 FFFF4830 */  andi       $8, $2, 0xFFFF
  .L001F0D94:
    /* F0D94 001F0D94 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0D98 001F0D98 2A104500 */  slt        $2, $2, $5
    /* F0D9C 001F0D9C F1FF4014 */  bnez       $2, .L001F0D64
    /* F0DA0 001F0DA0 00000000 */   nop
    /* F0DA4 001F0DA4 01002225 */  addiu      $2, $9, 0x1
    /* F0DA8 001F0DA8 FFFF4930 */  andi       $9, $2, 0xFFFF
  .L001F0DAC:
    /* F0DAC 001F0DAC FFFF2231 */  andi       $2, $9, 0xFFFF
    /* F0DB0 001F0DB0 2A104700 */  slt        $2, $2, $7
    /* F0DB4 001F0DB4 E3FF4014 */  bnez       $2, .L001F0D44
    /* F0DB8 001F0DB8 00000000 */   nop
    /* F0DBC 001F0DBC 2D100000 */  daddu      $2, $0, $0
  .L001F0DC0:
    /* F0DC0 001F0DC0 0800E003 */  jr         $31
    /* F0DC4 001F0DC4 00000000 */   nop
    /* F0DC8 001F0DC8 00000000 */  nop
    /* F0DCC 001F0DCC 00000000 */  nop
.size func_001f0d30, 0xa0

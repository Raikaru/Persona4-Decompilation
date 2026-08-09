.section .text
.set noat
.set noreorder
glabel func_001f0af0
    /* F0AF0 001F0AF0 2D480000 */  daddu      $9, $0, $0
    /* F0AF4 001F0AF4 6A008794 */  lhu        $7, 0x6A($4)
    /* F0AF8 001F0AF8 1000033C */  lui        $3, (0x100000 >> 16)
    /* F0AFC 001F0AFC 1B000010 */  b          .L001F0B6C
    /* F0B00 001F0B00 00000000 */   nop
  .L001F0B04:
    /* F0B04 001F0B04 FFFF2231 */  andi       $2, $9, 0xFFFF
    /* F0B08 001F0B08 80100200 */  sll        $2, $2, 2
    /* F0B0C 001F0B0C 21108200 */  addu       $2, $4, $2
    /* F0B10 001F0B10 3800468C */  lw         $6, 0x38($2)
    /* F0B14 001F0B14 2D400000 */  daddu      $8, $0, $0
    /* F0B18 001F0B18 D900C590 */  lbu        $5, 0xD9($6)
    /* F0B1C 001F0B1C 0D000010 */  b          .L001F0B54
    /* F0B20 001F0B20 00000000 */   nop
  .L001F0B24:
    /* F0B24 001F0B24 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0B28 001F0B28 40110200 */  sll        $2, $2, 5
    /* F0B2C 001F0B2C 2110C200 */  addu       $2, $6, $2
    /* F0B30 001F0B30 F800428C */  lw         $2, 0xF8($2)
    /* F0B34 001F0B34 24104300 */  and        $2, $2, $3
    /* F0B38 001F0B38 04004010 */  beqz       $2, .L001F0B4C
    /* F0B3C 001F0B3C 00000000 */   nop
    /* F0B40 001F0B40 01000224 */  addiu      $2, $0, 0x1
    /* F0B44 001F0B44 0E000010 */  b          .L001F0B80
    /* F0B48 001F0B48 00000000 */   nop
  .L001F0B4C:
    /* F0B4C 001F0B4C 01000225 */  addiu      $2, $8, 0x1
    /* F0B50 001F0B50 FFFF4830 */  andi       $8, $2, 0xFFFF
  .L001F0B54:
    /* F0B54 001F0B54 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0B58 001F0B58 2A104500 */  slt        $2, $2, $5
    /* F0B5C 001F0B5C F1FF4014 */  bnez       $2, .L001F0B24
    /* F0B60 001F0B60 00000000 */   nop
    /* F0B64 001F0B64 01002225 */  addiu      $2, $9, 0x1
    /* F0B68 001F0B68 FFFF4930 */  andi       $9, $2, 0xFFFF
  .L001F0B6C:
    /* F0B6C 001F0B6C FFFF2231 */  andi       $2, $9, 0xFFFF
    /* F0B70 001F0B70 2A104700 */  slt        $2, $2, $7
    /* F0B74 001F0B74 E3FF4014 */  bnez       $2, .L001F0B04
    /* F0B78 001F0B78 00000000 */   nop
    /* F0B7C 001F0B7C 2D100000 */  daddu      $2, $0, $0
  .L001F0B80:
    /* F0B80 001F0B80 0800E003 */  jr         $31
    /* F0B84 001F0B84 00000000 */   nop
    /* F0B88 001F0B88 00000000 */  nop
    /* F0B8C 001F0B8C 00000000 */  nop
.size func_001f0af0, 0xa0

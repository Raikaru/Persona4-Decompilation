.section .text
.set noat
.set noreorder
glabel func_001f0a50
    /* F0A50 001F0A50 2D400000 */  daddu      $8, $0, $0
    /* F0A54 001F0A54 6A008694 */  lhu        $6, 0x6A($4)
    /* F0A58 001F0A58 1B000010 */  b          .L001F0AC8
    /* F0A5C 001F0A5C 00000000 */   nop
  .L001F0A60:
    /* F0A60 001F0A60 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0A64 001F0A64 80100200 */  sll        $2, $2, 2
    /* F0A68 001F0A68 21108200 */  addu       $2, $4, $2
    /* F0A6C 001F0A6C 3800458C */  lw         $5, 0x38($2)
    /* F0A70 001F0A70 2D380000 */  daddu      $7, $0, $0
    /* F0A74 001F0A74 D900A390 */  lbu        $3, 0xD9($5)
    /* F0A78 001F0A78 0D000010 */  b          .L001F0AB0
    /* F0A7C 001F0A7C 00000000 */   nop
  .L001F0A80:
    /* F0A80 001F0A80 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* F0A84 001F0A84 40110200 */  sll        $2, $2, 5
    /* F0A88 001F0A88 2110A200 */  addu       $2, $5, $2
    /* F0A8C 001F0A8C 0E014294 */  lhu        $2, 0x10E($2)
    /* F0A90 001F0A90 04004230 */  andi       $2, $2, 0x4
    /* F0A94 001F0A94 04004010 */  beqz       $2, .L001F0AA8
    /* F0A98 001F0A98 00000000 */   nop
    /* F0A9C 001F0A9C 01000224 */  addiu      $2, $0, 0x1
    /* F0AA0 001F0AA0 0E000010 */  b          .L001F0ADC
    /* F0AA4 001F0AA4 00000000 */   nop
  .L001F0AA8:
    /* F0AA8 001F0AA8 0100E224 */  addiu      $2, $7, 0x1
    /* F0AAC 001F0AAC FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001F0AB0:
    /* F0AB0 001F0AB0 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* F0AB4 001F0AB4 2A104300 */  slt        $2, $2, $3
    /* F0AB8 001F0AB8 F1FF4014 */  bnez       $2, .L001F0A80
    /* F0ABC 001F0ABC 00000000 */   nop
    /* F0AC0 001F0AC0 01000225 */  addiu      $2, $8, 0x1
    /* F0AC4 001F0AC4 FFFF4830 */  andi       $8, $2, 0xFFFF
  .L001F0AC8:
    /* F0AC8 001F0AC8 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* F0ACC 001F0ACC 2A104600 */  slt        $2, $2, $6
    /* F0AD0 001F0AD0 E3FF4014 */  bnez       $2, .L001F0A60
    /* F0AD4 001F0AD4 00000000 */   nop
    /* F0AD8 001F0AD8 2D100000 */  daddu      $2, $0, $0
  .L001F0ADC:
    /* F0ADC 001F0ADC 0800E003 */  jr         $31
    /* F0AE0 001F0AE0 00000000 */   nop
    /* F0AE4 001F0AE4 00000000 */  nop
    /* F0AE8 001F0AE8 00000000 */  nop
    /* F0AEC 001F0AEC 00000000 */  nop
.size func_001f0a50, 0xa0

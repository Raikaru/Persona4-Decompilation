.section .text
.set noat
.set noreorder
glabel func_001f0c50
    /* F0C50 001F0C50 2D100000 */  daddu      $2, $0, $0
    /* F0C54 001F0C54 2D280000 */  daddu      $5, $0, $0
    /* F0C58 001F0C58 6A008394 */  lhu        $3, 0x6A($4)
    /* F0C5C 001F0C5C 01000724 */  addiu      $7, $0, 0x1
    /* F0C60 001F0C60 2D000010 */  b          .L001F0D18
    /* F0C64 001F0C64 00000000 */   nop
  .L001F0C68:
    /* F0C68 001F0C68 FFFFA630 */  andi       $6, $5, 0xFFFF
    /* F0C6C 001F0C6C 80300600 */  sll        $6, $6, 2
    /* F0C70 001F0C70 21308600 */  addu       $6, $4, $6
    /* F0C74 001F0C74 3800CA8C */  lw         $10, 0x38($6)
    /* F0C78 001F0C78 25004411 */  beq        $10, $4, .L001F0D10
    /* F0C7C 001F0C7C 00000000 */   nop
    /* F0C80 001F0C80 3000868C */  lw         $6, 0x30($4)
    /* F0C84 001F0C84 A200C890 */  lbu        $8, 0xA2($6)
    /* F0C88 001F0C88 3000468D */  lw         $6, 0x30($10)
    /* F0C8C 001F0C8C A200C690 */  lbu        $6, 0xA2($6)
    /* F0C90 001F0C90 04000611 */  beq        $8, $6, .L001F0CA4
    /* F0C94 001F0C94 00000000 */   nop
    /* F0C98 001F0C98 2D100000 */  daddu      $2, $0, $0
    /* F0C9C 001F0C9C 22000010 */  b          .L001F0D28
    /* F0CA0 001F0CA0 00000000 */   nop
  .L001F0CA4:
    /* F0CA4 001F0CA4 1A004014 */  bnez       $2, .L001F0D10
    /* F0CA8 001F0CA8 00000000 */   nop
    /* F0CAC 001F0CAC 2D580000 */  daddu      $11, $0, $0
    /* F0CB0 001F0CB0 D9004991 */  lbu        $9, 0xD9($10)
    /* F0CB4 001F0CB4 12000010 */  b          .L001F0D00
    /* F0CB8 001F0CB8 00000000 */   nop
  .L001F0CBC:
    /* F0CBC 001F0CBC FFFF6631 */  andi       $6, $11, 0xFFFF
    /* F0CC0 001F0CC0 40310600 */  sll        $6, $6, 5
    /* F0CC4 001F0CC4 21404601 */  addu       $8, $10, $6
    /* F0CC8 001F0CC8 F000068D */  lw         $6, 0xF0($8)
    /* F0CCC 001F0CCC 0200C018 */  blez       $6, .L001F0CD8
    /* F0CD0 001F0CD0 00000000 */   nop
    /* F0CD4 001F0CD4 2D10E000 */  daddu      $2, $7, $0
  .L001F0CD8:
    /* F0CD8 001F0CD8 F400068D */  lw         $6, 0xF4($8)
    /* F0CDC 001F0CDC 0200C018 */  blez       $6, .L001F0CE8
    /* F0CE0 001F0CE0 00000000 */   nop
    /* F0CE4 001F0CE4 2D10E000 */  daddu      $2, $7, $0
  .L001F0CE8:
    /* F0CE8 001F0CE8 FC00068D */  lw         $6, 0xFC($8)
    /* F0CEC 001F0CEC 0200C010 */  beqz       $6, .L001F0CF8
    /* F0CF0 001F0CF0 00000000 */   nop
    /* F0CF4 001F0CF4 2D10E000 */  daddu      $2, $7, $0
  .L001F0CF8:
    /* F0CF8 001F0CF8 01006625 */  addiu      $6, $11, 0x1
    /* F0CFC 001F0CFC FFFFCB30 */  andi       $11, $6, 0xFFFF
  .L001F0D00:
    /* F0D00 001F0D00 FFFF6631 */  andi       $6, $11, 0xFFFF
    /* F0D04 001F0D04 2A30C900 */  slt        $6, $6, $9
    /* F0D08 001F0D08 ECFFC014 */  bnez       $6, .L001F0CBC
    /* F0D0C 001F0D0C 00000000 */   nop
  .L001F0D10:
    /* F0D10 001F0D10 0100A524 */  addiu      $5, $5, 0x1
    /* F0D14 001F0D14 FFFFA530 */  andi       $5, $5, 0xFFFF
  .L001F0D18:
    /* F0D18 001F0D18 FFFFA630 */  andi       $6, $5, 0xFFFF
    /* F0D1C 001F0D1C 2A30C300 */  slt        $6, $6, $3
    /* F0D20 001F0D20 D1FFC014 */  bnez       $6, .L001F0C68
    /* F0D24 001F0D24 00000000 */   nop
  .L001F0D28:
    /* F0D28 001F0D28 0800E003 */  jr         $31
    /* F0D2C 001F0D2C 00000000 */   nop
.size func_001f0c50, 0xe0

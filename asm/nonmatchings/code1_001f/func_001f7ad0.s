.section .text
.set noat
.set noreorder
glabel func_001f7ad0
    /* F7AD0 001F7AD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F7AD4 001F7AD4 0000BFFF */  sd         $31, 0x0($29)
    /* F7AD8 001F7AD8 00008794 */  lhu        $7, 0x0($4)
    /* F7ADC 001F7ADC 40180700 */  sll        $3, $7, 1
    /* F7AE0 001F7AE0 21186700 */  addu       $3, $3, $7
    /* F7AE4 001F7AE4 40280300 */  sll        $5, $3, 1
    /* F7AE8 001F7AE8 ACB3838F */  lw         $3, -0x4C54($28)
    /* F7AEC 001F7AEC 2130A300 */  addu       $6, $5, $3
    /* F7AF0 001F7AF0 CC0AC584 */  lh         $5, 0xACC($6)
    /* F7AF4 001F7AF4 02008394 */  lhu        $3, 0x2($4)
    /* F7AF8 001F7AF8 0500A314 */  bne        $5, $3, .L001F7B10
    /* F7AFC 001F7AFC 00000000 */   nop
    /* F7B00 001F7B00 CE0AC584 */  lh         $5, 0xACE($6)
    /* F7B04 001F7B04 04008394 */  lhu        $3, 0x4($4)
    /* F7B08 001F7B08 0600A310 */  beq        $5, $3, .L001F7B24
    /* F7B0C 001F7B0C 00000000 */   nop
  .L001F7B10:
    /* F7B10 001F7B10 3C2C0700 */  dsll32     $5, $7, 16
    /* F7B14 001F7B14 3F2C0500 */  dsra32     $5, $5, 16
    /* F7B18 001F7B18 01000424 */  addiu      $4, $0, 0x1
    /* F7B1C 001F7B1C A46A110C */  jal        func_0045aa90
    /* F7B20 001F7B20 00000000 */   nop
  .L001F7B24:
    /* F7B24 001F7B24 0000BFDF */  ld         $31, 0x0($29)
    /* F7B28 001F7B28 1000BD27 */  addiu      $29, $29, 0x10
    /* F7B2C 001F7B2C 0800E003 */  jr         $31
    /* F7B30 001F7B30 00000000 */   nop
    /* F7B34 001F7B34 00000000 */  nop
    /* F7B38 001F7B38 00000000 */  nop
    /* F7B3C 001F7B3C 00000000 */  nop
.size func_001f7ad0, 0x70

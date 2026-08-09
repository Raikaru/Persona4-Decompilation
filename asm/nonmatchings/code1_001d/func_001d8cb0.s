.section .text
.set noat
.set noreorder
glabel func_001d8cb0
    /* D8CB0 001D8CB0 90FFBD27 */  addiu      $29, $29, -0x70
    /* D8CB4 001D8CB4 4000BFFF */  sd         $31, 0x40($29)
    /* D8CB8 001D8CB8 3000B27F */  sq         $18, 0x30($29)
    /* D8CBC 001D8CBC 2000B17F */  sq         $17, 0x20($29)
    /* D8CC0 001D8CC0 1000B07F */  sq         $16, 0x10($29)
    /* D8CC4 001D8CC4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* D8CC8 001D8CC8 2D90A000 */  daddu      $18, $5, $0
    /* D8CCC 001D8CCC 3A00A0A4 */  sh         $0, 0x3A($5)
    /* D8CD0 001D8CD0 3000A5DC */  ld         $5, 0x30($5)
    /* D8CD4 001D8CD4 1600A010 */  beqz       $5, .L001D8D30
    /* D8CD8 001D8CD8 00000000 */   nop
    /* D8CDC 001D8CDC 2D300000 */  daddu      $6, $0, $0
    /* D8CE0 001D8CE0 38004396 */  lhu        $3, 0x38($18)
    /* D8CE4 001D8CE4 0E000010 */  b          .L001D8D20
    /* D8CE8 001D8CE8 00000000 */   nop
  .L001D8CEC:
    /* D8CEC 001D8CEC FFFFC230 */  andi       $2, $6, 0xFFFF
    /* D8CF0 001D8CF0 80100200 */  sll        $2, $2, 2
    /* D8CF4 001D8CF4 21104202 */  addu       $2, $18, $2
    /* D8CF8 001D8CF8 0000428C */  lw         $2, 0x0($2)
    /* D8CFC 001D8CFC 000042DC */  ld         $2, 0x0($2)
    /* D8D00 001D8D00 0500A214 */  bne        $5, $2, .L001D8D18
    /* D8D04 001D8D04 00000000 */   nop
    /* D8D08 001D8D08 3A0046A6 */  sh         $6, 0x3A($18)
    /* D8D0C 001D8D0C 01000224 */  addiu      $2, $0, 0x1
    /* D8D10 001D8D10 2D000010 */  b          .L001D8DC8
    /* D8D14 001D8D14 00000000 */   nop
  .L001D8D18:
    /* D8D18 001D8D18 0100C224 */  addiu      $2, $6, 0x1
    /* D8D1C 001D8D1C FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001D8D20:
    /* D8D20 001D8D20 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* D8D24 001D8D24 2A104300 */  slt        $2, $2, $3
    /* D8D28 001D8D28 F0FF4014 */  bnez       $2, .L001D8CEC
    /* D8D2C 001D8D2C 00000000 */   nop
  .L001D8D30:
    /* D8D30 001D8D30 24008010 */  beqz       $4, .L001D8DC4
    /* D8D34 001D8D34 00000000 */   nop
    /* D8D38 001D8D38 01001124 */  addiu      $17, $0, 0x1
    /* D8D3C 001D8D3C 3000848C */  lw         $4, 0x30($4)
    /* D8D40 001D8D40 6000A527 */  addiu      $5, $29, 0x60
    /* D8D44 001D8D44 3C56060C */  jal        func_001958f0
    /* D8D48 001D8D48 00000000 */   nop
    /* D8D4C 001D8D4C 2D800000 */  daddu      $16, $0, $0
    /* D8D50 001D8D50 17000010 */  b          .L001D8DB0
    /* D8D54 001D8D54 00000000 */   nop
  .L001D8D58:
    /* D8D58 001D8D58 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* D8D5C 001D8D5C 80100200 */  sll        $2, $2, 2
    /* D8D60 001D8D60 21104202 */  addu       $2, $18, $2
    /* D8D64 001D8D64 0000428C */  lw         $2, 0x0($2)
    /* D8D68 001D8D68 3000448C */  lw         $4, 0x30($2)
    /* D8D6C 001D8D6C 5000A527 */  addiu      $5, $29, 0x50
    /* D8D70 001D8D70 3C56060C */  jal        func_001958f0
    /* D8D74 001D8D74 00000000 */   nop
    /* D8D78 001D8D78 6000A427 */  addiu      $4, $29, 0x60
    /* D8D7C 001D8D7C 5000A527 */  addiu      $5, $29, 0x50
    /* D8D80 001D8D80 94B0070C */  jal        func_001ec250
    /* D8D84 001D8D84 00000000 */   nop
    /* D8D88 001D8D88 34001446 */  c.lt.s     $f0, $f20
    /* D8D8C 001D8D8C 03000145 */  bc1t       .L001D8D9C
    /* D8D90 001D8D90 00000000 */   nop
    /* D8D94 001D8D94 04002012 */  beqz       $17, .L001D8DA8
    /* D8D98 001D8D98 00000000 */   nop
  .L001D8D9C:
    /* D8D9C 001D8D9C 3A0050A6 */  sh         $16, 0x3A($18)
    /* D8DA0 001D8DA0 06050046 */  mov.s      $f20, $f0
    /* D8DA4 001D8DA4 2D880000 */  daddu      $17, $0, $0
  .L001D8DA8:
    /* D8DA8 001D8DA8 01000226 */  addiu      $2, $16, 0x1
    /* D8DAC 001D8DAC FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001D8DB0:
    /* D8DB0 001D8DB0 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* D8DB4 001D8DB4 38004296 */  lhu        $2, 0x38($18)
    /* D8DB8 001D8DB8 2A106200 */  slt        $2, $3, $2
    /* D8DBC 001D8DBC E6FF4014 */  bnez       $2, .L001D8D58
    /* D8DC0 001D8DC0 00000000 */   nop
  .L001D8DC4:
    /* D8DC4 001D8DC4 01000224 */  addiu      $2, $0, 0x1
  .L001D8DC8:
    /* D8DC8 001D8DC8 4000BFDF */  ld         $31, 0x40($29)
    /* D8DCC 001D8DCC 3000B27B */  lq         $18, 0x30($29)
    /* D8DD0 001D8DD0 2000B17B */  lq         $17, 0x20($29)
    /* D8DD4 001D8DD4 1000B07B */  lq         $16, 0x10($29)
    /* D8DD8 001D8DD8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* D8DDC 001D8DDC 7000BD27 */  addiu      $29, $29, 0x70
    /* D8DE0 001D8DE0 0800E003 */  jr         $31
    /* D8DE4 001D8DE4 00000000 */   nop
    /* D8DE8 001D8DE8 00000000 */  nop
    /* D8DEC 001D8DEC 00000000 */  nop
.size func_001d8cb0, 0x140

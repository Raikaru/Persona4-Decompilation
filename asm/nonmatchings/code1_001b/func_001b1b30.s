.section .text
.set noat
.set noreorder
glabel func_001b1b30
    /* B1B30 001B1B30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* B1B34 001B1B34 2000BFFF */  sd         $31, 0x20($29)
    /* B1B38 001B1B38 1000B17F */  sq         $17, 0x10($29)
    /* B1B3C 001B1B3C 0000B07F */  sq         $16, 0x0($29)
    /* B1B40 001B1B40 01001024 */  addiu      $16, $0, 0x1
    /* B1B44 001B1B44 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1B48 001B1B48 7401518C */  lw         $17, 0x174($2)
    /* B1B4C 001B1B4C 17000010 */  b          .L001B1BAC
    /* B1B50 001B1B50 00000000 */   nop
  .L001B1B54:
    /* B1B54 001B1B54 1A002296 */  lhu        $2, 0x1A($17)
    /* B1B58 001B1B58 01004230 */  andi       $2, $2, 0x1
    /* B1B5C 001B1B5C 12004010 */  beqz       $2, .L001B1BA8
    /* B1B60 001B1B60 00000000 */   nop
    /* B1B64 001B1B64 3000228E */  lw         $2, 0x30($17)
    /* B1B68 001B1B68 A2004290 */  lbu        $2, 0xA2($2)
    /* B1B6C 001B1B6C 01000524 */  addiu      $5, $0, 0x1
    /* B1B70 001B1B70 04004514 */  bne        $2, $5, .L001B1B84
    /* B1B74 001B1B74 00000000 */   nop
    /* B1B78 001B1B78 2D800000 */  daddu      $16, $0, $0
    /* B1B7C 001B1B7C 0A000010 */  b          .L001B1BA8
    /* B1B80 001B1B80 00000000 */   nop
  .L001B1B84:
    /* B1B84 001B1B84 2D202002 */  daddu      $4, $17, $0
    /* B1B88 001B1B88 00C2060C */  jal        func_001b0800
    /* B1B8C 001B1B8C 00000000 */   nop
    /* B1B90 001B1B90 18002296 */  lhu        $2, 0x18($17)
    /* B1B94 001B1B94 FF7F4230 */  andi       $2, $2, 0x7FFF
    /* B1B98 001B1B98 180022A6 */  sh         $2, 0x18($17)
    /* B1B9C 001B1B9C 18002296 */  lhu        $2, 0x18($17)
    /* B1BA0 001B1BA0 FBFF4230 */  andi       $2, $2, 0xFFFB
    /* B1BA4 001B1BA4 180022A6 */  sh         $2, 0x18($17)
  .L001B1BA8:
    /* B1BA8 001B1BA8 5004318E */  lw         $17, 0x450($17)
  .L001B1BAC:
    /* B1BAC 001B1BAC E9FF2016 */  bnez       $17, .L001B1B54
    /* B1BB0 001B1BB0 00000000 */   nop
    /* B1BB4 001B1BB4 ACB3848F */  lw         $4, -0x4C54($28)
    /* B1BB8 001B1BB8 0C00838C */  lw         $3, 0xC($4)
    /* B1BBC 001B1BBC 7FFF0224 */  addiu      $2, $0, -0x81
    /* B1BC0 001B1BC0 24106200 */  and        $2, $3, $2
    /* B1BC4 001B1BC4 0C0082AC */  sw         $2, 0xC($4)
    /* B1BC8 001B1BC8 ACB3848F */  lw         $4, -0x4C54($28)
    /* B1BCC 001B1BCC 0C00838C */  lw         $3, 0xC($4)
    /* B1BD0 001B1BD0 F7FF023C */  lui        $2, (0xFFF7FFFF >> 16)
    /* B1BD4 001B1BD4 FFFF4234 */  ori        $2, $2, (0xFFF7FFFF & 0xFFFF)
    /* B1BD8 001B1BD8 24106200 */  and        $2, $3, $2
    /* B1BDC 001B1BDC 0C0082AC */  sw         $2, 0xC($4)
    /* B1BE0 001B1BE0 59000012 */  beqz       $16, .L001B1D48
    /* B1BE4 001B1BE4 00000000 */   nop
    /* B1BE8 001B1BE8 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1BEC 001B1BEC 1C0040A4 */  sh         $0, 0x1C($2)
    /* B1BF0 001B1BF0 ACB3838F */  lw         $3, -0x4C54($28)
    /* B1BF4 001B1BF4 6C0C6294 */  lhu        $2, 0xC6C($3)
    /* B1BF8 001B1BF8 80100200 */  sll        $2, $2, 2
    /* B1BFC 001B1BFC 21104300 */  addu       $2, $2, $3
    /* B1C00 001B1C00 840C428C */  lw         $2, 0xC84($2)
    /* B1C04 001B1C04 680C62AC */  sw         $2, 0xC68($3)
    /* B1C08 001B1C08 ACB3838F */  lw         $3, -0x4C54($28)
    /* B1C0C 001B1C0C 6C0C6294 */  lhu        $2, 0xC6C($3)
    /* B1C10 001B1C10 01004224 */  addiu      $2, $2, 0x1
    /* B1C14 001B1C14 6C0C62A4 */  sh         $2, 0xC6C($3)
    /* B1C18 001B1C18 20C6060C */  jal        func_001b1880
    /* B1C1C 001B1C1C 00000000 */   nop
    /* B1C20 001B1C20 ACB3848F */  lw         $4, -0x4C54($28)
    /* B1C24 001B1C24 0C00838C */  lw         $3, 0xC($4)
    /* B1C28 001B1C28 FEFF023C */  lui        $2, (0xFFFEFFFF >> 16)
    /* B1C2C 001B1C2C FFFF4234 */  ori        $2, $2, (0xFFFEFFFF & 0xFFFF)
    /* B1C30 001B1C30 24106200 */  and        $2, $3, $2
    /* B1C34 001B1C34 0C0082AC */  sw         $2, 0xC($4)
    /* B1C38 001B1C38 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1C3C 001B1C3C D40D448C */  lw         $4, 0xDD4($2)
    /* B1C40 001B1C40 E42F080C */  jal        func_0020bf90
    /* B1C44 001B1C44 00000000 */   nop
    /* B1C48 001B1C48 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1C4C 001B1C4C 7001448C */  lw         $4, 0x170($2)
    /* B1C50 001B1C50 1F000524 */  addiu      $5, $0, 0x1F
    /* B1C54 001B1C54 2D300000 */  daddu      $6, $0, $0
    /* B1C58 001B1C58 2D380000 */  daddu      $7, $0, $0
    /* B1C5C 001B1C5C 2D400000 */  daddu      $8, $0, $0
    /* B1C60 001B1C60 DCD7070C */  jal        func_001f5f70
    /* B1C64 001B1C64 00000000 */   nop
    /* B1C68 001B1C68 2D204000 */  daddu      $4, $2, $0
    /* B1C6C 001B1C6C 01000524 */  addiu      $5, $0, 0x1
    /* B1C70 001B1C70 6451060C */  jal        func_00194590
    /* B1C74 001B1C74 00000000 */   nop
    /* B1C78 001B1C78 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1C7C 001B1C7C 7401508C */  lw         $16, 0x174($2)
    /* B1C80 001B1C80 15000010 */  b          .L001B1CD8
    /* B1C84 001B1C84 00000000 */   nop
  .L001B1C88:
    /* B1C88 001B1C88 1A000296 */  lhu        $2, 0x1A($16)
    /* B1C8C 001B1C8C 01004230 */  andi       $2, $2, 0x1
    /* B1C90 001B1C90 10004010 */  beqz       $2, .L001B1CD4
    /* B1C94 001B1C94 00000000 */   nop
    /* B1C98 001B1C98 3000038E */  lw         $3, 0x30($16)
    /* B1C9C 001B1C9C A2006290 */  lbu        $2, 0xA2($3)
    /* B1CA0 001B1CA0 0C004014 */  bnez       $2, .L001B1CD4
    /* B1CA4 001B1CA4 00000000 */   nop
    /* B1CA8 001B1CA8 640A628C */  lw         $2, 0xA64($3)
    /* B1CAC 001B1CAC 09004010 */  beqz       $2, .L001B1CD4
    /* B1CB0 001B1CB0 00000000 */   nop
    /* B1CB4 001B1CB4 2D200002 */  daddu      $4, $16, $0
    /* B1CB8 001B1CB8 02000524 */  addiu      $5, $0, 0x2
    /* B1CBC 001B1CBC 1CCE070C */  jal        func_001f3870
    /* B1CC0 001B1CC0 00000000 */   nop
    /* B1CC4 001B1CC4 2D204000 */  daddu      $4, $2, $0
    /* B1CC8 001B1CC8 01000524 */  addiu      $5, $0, 0x1
    /* B1CCC 001B1CCC 6451060C */  jal        func_00194590
    /* B1CD0 001B1CD0 00000000 */   nop
  .L001B1CD4:
    /* B1CD4 001B1CD4 5004108E */  lw         $16, 0x450($16)
  .L001B1CD8:
    /* B1CD8 001B1CD8 EBFF0016 */  bnez       $16, .L001B1C88
    /* B1CDC 001B1CDC 00000000 */   nop
    /* B1CE0 001B1CE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1CE4 001B1CE4 D40D448C */  lw         $4, 0xDD4($2)
    /* B1CE8 001B1CE8 104F080C */  jal        func_00213c40
    /* B1CEC 001B1CEC 00000000 */   nop
    /* B1CF0 001B1CF0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1CF4 001B1CF4 D40D448C */  lw         $4, 0xDD4($2)
    /* B1CF8 001B1CF8 D44E080C */  jal        func_00213b50
    /* B1CFC 001B1CFC 00000000 */   nop
    /* B1D00 001B1D00 18AE070C */  jal        func_001eb860
    /* B1D04 001B1D04 00000000 */   nop
    /* B1D08 001B1D08 01000524 */  addiu      $5, $0, 0x1
    /* B1D0C 001B1D0C 0B004514 */  bne        $2, $5, .L001B1D3C
    /* B1D10 001B1D10 00000000 */   nop
    /* B1D14 001B1D14 ACB3838F */  lw         $3, -0x4C54($28)
    /* B1D18 001B1D18 0C00628C */  lw         $2, 0xC($3)
    /* B1D1C 001B1D1C 00204234 */  ori        $2, $2, 0x2000
    /* B1D20 001B1D20 0C0062AC */  sw         $2, 0xC($3)
    /* B1D24 001B1D24 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1D28 001B1D28 D40D448C */  lw         $4, 0xDD4($2)
    /* B1D2C 001B1D2C 9048080C */  jal        func_00212240
    /* B1D30 001B1D30 00000000 */   nop
    /* B1D34 001B1D34 FCAD070C */  jal        func_001eb7f0
    /* B1D38 001B1D38 00000000 */   nop
  .L001B1D3C:
    /* B1D3C 001B1D3C 05000224 */  addiu      $2, $0, 0x5
    /* B1D40 001B1D40 02000010 */  b          .L001B1D4C
    /* B1D44 001B1D44 00000000 */   nop
  .L001B1D48:
    /* B1D48 001B1D48 2D100000 */  daddu      $2, $0, $0
  .L001B1D4C:
    /* B1D4C 001B1D4C 2000BFDF */  ld         $31, 0x20($29)
    /* B1D50 001B1D50 1000B17B */  lq         $17, 0x10($29)
    /* B1D54 001B1D54 0000B07B */  lq         $16, 0x0($29)
    /* B1D58 001B1D58 3000BD27 */  addiu      $29, $29, 0x30
    /* B1D5C 001B1D5C 0800E003 */  jr         $31
    /* B1D60 001B1D60 00000000 */   nop
    /* B1D64 001B1D64 00000000 */  nop
    /* B1D68 001B1D68 00000000 */  nop
    /* B1D6C 001B1D6C 00000000 */  nop
.size func_001b1b30, 0x240

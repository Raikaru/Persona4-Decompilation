.section .text
.set noat
.set noreorder
glabel func_001eabc0
    /* EABC0 001EABC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* EABC4 001EABC4 2000BFFF */  sd         $31, 0x20($29)
    /* EABC8 001EABC8 1000B17F */  sq         $17, 0x10($29)
    /* EABCC 001EABCC 0000B07F */  sq         $16, 0x0($29)
    /* EABD0 001EABD0 44C5060C */  jal        func_001b1510
    /* EABD4 001EABD4 00000000 */   nop
    /* EABD8 001EABD8 2D804000 */  daddu      $16, $2, $0
    /* EABDC 001EABDC 2D200000 */  daddu      $4, $0, $0
    /* EABE0 001EABE0 00730A0C */  jal        func_0029cc00
    /* EABE4 001EABE4 00000000 */   nop
    /* EABE8 001EABE8 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* EABEC 001EABEC 01000424 */  addiu      $4, $0, 0x1
    /* EABF0 001EABF0 00730A0C */  jal        func_0029cc00
    /* EABF4 001EABF4 00000000 */   nop
    /* EABF8 001EABF8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EABFC 001EABFC 01000524 */  addiu      $5, $0, 0x1
    /* EAC00 001EAC00 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* EAC04 001EAC04 0C004510 */  beq        $2, $5, .L001EAC38
    /* EAC08 001EAC08 00000000 */   nop
    /* EAC0C 001EAC0C 03004010 */  beqz       $2, .L001EAC1C
    /* EAC10 001EAC10 00000000 */   nop
    /* EAC14 001EAC14 0D000010 */  b          .L001EAC4C
    /* EAC18 001EAC18 00000000 */   nop
  .L001EAC1C:
    /* EAC1C 001EAC1C 3000028E */  lw         $2, 0x30($16)
    /* EAC20 001EAC20 A2004290 */  lbu        $2, 0xA2($2)
    /* EAC24 001EAC24 09004010 */  beqz       $2, .L001EAC4C
    /* EAC28 001EAC28 00000000 */   nop
    /* EAC2C 001EAC2C 2D280000 */  daddu      $5, $0, $0
    /* EAC30 001EAC30 06000010 */  b          .L001EAC4C
    /* EAC34 001EAC34 00000000 */   nop
  .L001EAC38:
    /* EAC38 001EAC38 3000028E */  lw         $2, 0x30($16)
    /* EAC3C 001EAC3C A2004290 */  lbu        $2, 0xA2($2)
    /* EAC40 001EAC40 02004510 */  beq        $2, $5, .L001EAC4C
    /* EAC44 001EAC44 00000000 */   nop
    /* EAC48 001EAC48 2D280000 */  daddu      $5, $0, $0
  .L001EAC4C:
    /* EAC4C 001EAC4C 01000224 */  addiu      $2, $0, 0x1
    /* EAC50 001EAC50 0700A214 */  bne        $5, $2, .L001EAC70
    /* EAC54 001EAC54 00000000 */   nop
    /* EAC58 001EAC58 3000028E */  lw         $2, 0x30($16)
    /* EAC5C 001EAC5C A4004394 */  lhu        $3, 0xA4($2)
    /* EAC60 001EAC60 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* EAC64 001EAC64 02006210 */  beq        $3, $2, .L001EAC70
    /* EAC68 001EAC68 00000000 */   nop
    /* EAC6C 001EAC6C 2D280000 */  daddu      $5, $0, $0
  .L001EAC70:
    /* EAC70 001EAC70 2B200500 */  sltu       $4, $0, $5
    /* EAC74 001EAC74 D4730A0C */  jal        func_0029cf50
    /* EAC78 001EAC78 00000000 */   nop
    /* EAC7C 001EAC7C 01000224 */  addiu      $2, $0, 0x1
    /* EAC80 001EAC80 2000BFDF */  ld         $31, 0x20($29)
    /* EAC84 001EAC84 1000B17B */  lq         $17, 0x10($29)
    /* EAC88 001EAC88 0000B07B */  lq         $16, 0x0($29)
    /* EAC8C 001EAC8C 3000BD27 */  addiu      $29, $29, 0x30
    /* EAC90 001EAC90 0800E003 */  jr         $31
    /* EAC94 001EAC94 00000000 */   nop
    /* EAC98 001EAC98 00000000 */  nop
    /* EAC9C 001EAC9C 00000000 */  nop
.size func_001eabc0, 0xe0

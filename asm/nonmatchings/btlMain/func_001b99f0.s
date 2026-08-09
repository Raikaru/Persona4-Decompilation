.section .text
.set noat
.set noreorder
glabel func_001b99f0
    /* B99F0 001B99F0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* B99F4 001B99F4 8000BFFF */  sd         $31, 0x80($29)
    /* B99F8 001B99F8 7000B77F */  sq         $23, 0x70($29)
    /* B99FC 001B99FC 6000B67F */  sq         $22, 0x60($29)
    /* B9A00 001B9A00 5000B57F */  sq         $21, 0x50($29)
    /* B9A04 001B9A04 4000B47F */  sq         $20, 0x40($29)
    /* B9A08 001B9A08 3000B37F */  sq         $19, 0x30($29)
    /* B9A0C 001B9A0C 2000B27F */  sq         $18, 0x20($29)
    /* B9A10 001B9A10 1000B17F */  sq         $17, 0x10($29)
    /* B9A14 001B9A14 0000B07F */  sq         $16, 0x0($29)
    /* B9A18 001B9A18 2DA08000 */  daddu      $20, $4, $0
    /* B9A1C 001B9A1C 01001224 */  addiu      $18, $0, 0x1
    /* B9A20 001B9A20 0000938C */  lw         $19, 0x0($4)
    /* B9A24 001B9A24 0C008394 */  lhu        $3, 0xC($4)
    /* B9A28 001B9A28 ACB3828F */  lw         $2, -0x4C54($28)
    /* B9A2C 001B9A2C 1000428C */  lw         $2, 0x10($2)
    /* B9A30 001B9A30 08004230 */  andi       $2, $2, 0x8
    /* B9A34 001B9A34 04004010 */  beqz       $2, .L001B9A48
    /* B9A38 001B9A38 00000000 */   nop
    /* B9A3C 001B9A3C 2D104002 */  daddu      $2, $18, $0
    /* B9A40 001B9A40 DB000010 */  b          .L001B9DB0
    /* B9A44 001B9A44 00000000 */   nop
  .L001B9A48:
    /* B9A48 001B9A48 B8B3848F */  lw         $4, -0x4C48($28)
    /* B9A4C 001B9A4C FFFF6330 */  andi       $3, $3, 0xFFFF
    /* B9A50 001B9A50 80100300 */  sll        $2, $3, 2
    /* B9A54 001B9A54 21104300 */  addu       $2, $2, $3
    /* B9A58 001B9A58 C0100200 */  sll        $2, $2, 3
    /* B9A5C 001B9A5C 21104400 */  addu       $2, $2, $4
    /* B9A60 001B9A60 11004390 */  lbu        $3, 0x11($2)
    /* B9A64 001B9A64 10000224 */  addiu      $2, $0, 0x10
    /* B9A68 001B9A68 04006214 */  bne        $3, $2, .L001B9A7C
    /* B9A6C 001B9A6C 00000000 */   nop
    /* B9A70 001B9A70 2D104002 */  daddu      $2, $18, $0
    /* B9A74 001B9A74 CE000010 */  b          .L001B9DB0
    /* B9A78 001B9A78 00000000 */   nop
  .L001B9A7C:
    /* B9A7C 001B9A7C 6A006296 */  lhu        $2, 0x6A($19)
    /* B9A80 001B9A80 02004128 */  slti       $1, $2, 0x2
    /* B9A84 001B9A84 08002010 */  beqz       $1, .L001B9AA8
    /* B9A88 001B9A88 00000000 */   nop
    /* B9A8C 001B9A8C 3000628E */  lw         $2, 0x30($19)
    /* B9A90 001B9A90 A2004290 */  lbu        $2, 0xA2($2)
    /* B9A94 001B9A94 04004010 */  beqz       $2, .L001B9AA8
    /* B9A98 001B9A98 00000000 */   nop
    /* B9A9C 001B9A9C 2D104002 */  daddu      $2, $18, $0
    /* B9AA0 001B9AA0 C3000010 */  b          .L001B9DB0
    /* B9AA4 001B9AA4 00000000 */   nop
  .L001B9AA8:
    /* B9AA8 001B9AA8 2D206002 */  daddu      $4, $19, $0
    /* B9AAC 001B9AAC FCC3070C */  jal        func_001f0ff0
    /* B9AB0 001B9AB0 00000000 */   nop
    /* B9AB4 001B9AB4 09004010 */  beqz       $2, .L001B9ADC
    /* B9AB8 001B9AB8 00000000 */   nop
    /* B9ABC 001B9ABC 3000628E */  lw         $2, 0x30($19)
    /* B9AC0 001B9AC0 A2004390 */  lbu        $3, 0xA2($2)
    /* B9AC4 001B9AC4 01000224 */  addiu      $2, $0, 0x1
    /* B9AC8 001B9AC8 04106200 */  sllv       $2, $2, $3
    /* B9ACC 001B9ACC FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B9AD0 001B9AD0 2D100000 */  daddu      $2, $0, $0
    /* B9AD4 001B9AD4 18000010 */  b          .L001B9B38
    /* B9AD8 001B9AD8 00000000 */   nop
  .L001B9ADC:
    /* B9ADC 001B9ADC 03000364 */  daddiu     $3, $0, 0x3
    /* B9AE0 001B9AE0 2D100000 */  daddu      $2, $0, $0
    /* B9AE4 001B9AE4 2D380000 */  daddu      $7, $0, $0
    /* B9AE8 001B9AE8 6A006696 */  lhu        $6, 0x6A($19)
    /* B9AEC 001B9AEC 01000524 */  addiu      $5, $0, 0x1
    /* B9AF0 001B9AF0 0D000010 */  b          .L001B9B28
    /* B9AF4 001B9AF4 00000000 */   nop
  .L001B9AF8:
    /* B9AF8 001B9AF8 FFFFE430 */  andi       $4, $7, 0xFFFF
    /* B9AFC 001B9AFC 80200400 */  sll        $4, $4, 2
    /* B9B00 001B9B00 21206402 */  addu       $4, $19, $4
    /* B9B04 001B9B04 3800848C */  lw         $4, 0x38($4)
    /* B9B08 001B9B08 3000848C */  lw         $4, 0x30($4)
    /* B9B0C 001B9B0C A2008490 */  lbu        $4, 0xA2($4)
    /* B9B10 001B9B10 04208500 */  sllv       $4, $5, $4
    /* B9B14 001B9B14 FFFF8430 */  andi       $4, $4, 0xFFFF
    /* B9B18 001B9B18 25104400 */  or         $2, $2, $4
    /* B9B1C 001B9B1C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* B9B20 001B9B20 0100E424 */  addiu      $4, $7, 0x1
    /* B9B24 001B9B24 FFFF8730 */  andi       $7, $4, 0xFFFF
  .L001B9B28:
    /* B9B28 001B9B28 FFFFE430 */  andi       $4, $7, 0xFFFF
    /* B9B2C 001B9B2C 2A208600 */  slt        $4, $4, $6
    /* B9B30 001B9B30 F1FF8014 */  bnez       $4, .L001B9AF8
    /* B9B34 001B9B34 00000000 */   nop
  .L001B9B38:
    /* B9B38 001B9B38 3000648E */  lw         $4, 0x30($19)
    /* B9B3C 001B9B3C A2008490 */  lbu        $4, 0xA2($4)
    /* B9B40 001B9B40 1C008014 */  bnez       $4, .L001B9BB4
    /* B9B44 001B9B44 00000000 */   nop
    /* B9B48 001B9B48 01000724 */  addiu      $7, $0, 0x1
    /* B9B4C 001B9B4C 2D300000 */  daddu      $6, $0, $0
    /* B9B50 001B9B50 6A006596 */  lhu        $5, 0x6A($19)
    /* B9B54 001B9B54 0E000010 */  b          .L001B9B90
    /* B9B58 001B9B58 00000000 */   nop
  .L001B9B5C:
    /* B9B5C 001B9B5C FFFFC430 */  andi       $4, $6, 0xFFFF
    /* B9B60 001B9B60 80200400 */  sll        $4, $4, 2
    /* B9B64 001B9B64 21206402 */  addu       $4, $19, $4
    /* B9B68 001B9B68 3800848C */  lw         $4, 0x38($4)
    /* B9B6C 001B9B6C 3000848C */  lw         $4, 0x30($4)
    /* B9B70 001B9B70 A2008490 */  lbu        $4, 0xA2($4)
    /* B9B74 001B9B74 04008010 */  beqz       $4, .L001B9B88
    /* B9B78 001B9B78 00000000 */   nop
    /* B9B7C 001B9B7C 2D380000 */  daddu      $7, $0, $0
    /* B9B80 001B9B80 07000010 */  b          .L001B9BA0
    /* B9B84 001B9B84 00000000 */   nop
  .L001B9B88:
    /* B9B88 001B9B88 0100C424 */  addiu      $4, $6, 0x1
    /* B9B8C 001B9B8C FFFF8630 */  andi       $6, $4, 0xFFFF
  .L001B9B90:
    /* B9B90 001B9B90 FFFFC430 */  andi       $4, $6, 0xFFFF
    /* B9B94 001B9B94 2A208500 */  slt        $4, $4, $5
    /* B9B98 001B9B98 F0FF8014 */  bnez       $4, .L001B9B5C
    /* B9B9C 001B9B9C 00000000 */   nop
  .L001B9BA0:
    /* B9BA0 001B9BA0 0400E010 */  beqz       $7, .L001B9BB4
    /* B9BA4 001B9BA4 00000000 */   nop
    /* B9BA8 001B9BA8 01000224 */  addiu      $2, $0, 0x1
    /* B9BAC 001B9BAC 80000010 */  b          .L001B9DB0
    /* B9BB0 001B9BB0 00000000 */   nop
  .L001B9BB4:
    /* B9BB4 001B9BB4 0400868E */  lw         $6, 0x4($20)
    /* B9BB8 001B9BB8 0800848E */  lw         $4, 0x8($20)
    /* B9BBC 001B9BBC 2B088600 */  sltu       $1, $4, $6
    /* B9BC0 001B9BC0 3E002010 */  beqz       $1, .L001B9CBC
    /* B9BC4 001B9BC4 00000000 */   nop
    /* B9BC8 001B9BC8 06008004 */  bltz       $4, .L001B9BE4
    /* B9BCC 001B9BCC 00000000 */   nop
    /* B9BD0 001B9BD0 00008444 */  mtc1       $4, $f0
    /* B9BD4 001B9BD4 00000000 */  nop
    /* B9BD8 001B9BD8 60008046 */  cvt.s.w    $f1, $f0
    /* B9BDC 001B9BDC 08000010 */  b          .L001B9C00
    /* B9BE0 001B9BE0 00000000 */   nop
  .L001B9BE4:
    /* B9BE4 001B9BE4 42280400 */  srl        $5, $4, 1
    /* B9BE8 001B9BE8 01008430 */  andi       $4, $4, 0x1
    /* B9BEC 001B9BEC 2528A400 */  or         $5, $5, $4
    /* B9BF0 001B9BF0 00008544 */  mtc1       $5, $f0
    /* B9BF4 001B9BF4 00000000 */  nop
    /* B9BF8 001B9BF8 60008046 */  cvt.s.w    $f1, $f0
    /* B9BFC 001B9BFC 40080146 */  add.s      $f1, $f1, $f1
  .L001B9C00:
    /* B9C00 001B9C00 0600C004 */  bltz       $6, .L001B9C1C
    /* B9C04 001B9C04 00000000 */   nop
    /* B9C08 001B9C08 00008644 */  mtc1       $6, $f0
    /* B9C0C 001B9C0C 00000000 */  nop
    /* B9C10 001B9C10 20008046 */  cvt.s.w    $f0, $f0
    /* B9C14 001B9C14 08000010 */  b          .L001B9C38
    /* B9C18 001B9C18 00000000 */   nop
  .L001B9C1C:
    /* B9C1C 001B9C1C 42280600 */  srl        $5, $6, 1
    /* B9C20 001B9C20 0100C430 */  andi       $4, $6, 0x1
    /* B9C24 001B9C24 2528A400 */  or         $5, $5, $4
    /* B9C28 001B9C28 00008544 */  mtc1       $5, $f0
    /* B9C2C 001B9C2C 00000000 */  nop
    /* B9C30 001B9C30 20008046 */  cvt.s.w    $f0, $f0
    /* B9C34 001B9C34 00000046 */  add.s      $f0, $f0, $f0
  .L001B9C38:
    /* B9C38 001B9C38 00000000 */  nop
    /* B9C3C 001B9C3C 00000000 */  nop
    /* B9C40 001B9C40 43080046 */  div.s      $f1, $f1, $f0
    /* B9C44 001B9C44 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* B9C48 001B9C48 00008444 */  mtc1       $4, $f0
    /* B9C4C 001B9C4C 00000000 */  nop
    /* B9C50 001B9C50 41000146 */  sub.s      $f1, $f0, $f1
    /* B9C54 001B9C54 7F43043C */  lui        $4, (0x437F0000 >> 16)
    /* B9C58 001B9C58 00008444 */  mtc1       $4, $f0
    /* B9C5C 001B9C5C 00000000 */  nop
    /* B9C60 001B9C60 42000146 */  mul.s      $f1, $f0, $f1
    /* B9C64 001B9C64 004F043C */  lui        $4, (0x4F000000 >> 16)
    /* B9C68 001B9C68 00008444 */  mtc1       $4, $f0
    /* B9C6C 001B9C6C 00000000 */  nop
    /* B9C70 001B9C70 36000146 */  c.le.s     $f0, $f1
    /* B9C74 001B9C74 07000145 */  bc1t       .L001B9C94
    /* B9C78 001B9C78 00000000 */   nop
    /* B9C7C 001B9C7C 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* B9C80 001B9C80 00000544 */  mfc1       $5, $f0
    /* B9C84 001B9C84 00000000 */  nop
    /* B9C88 001B9C88 FF00A530 */  andi       $5, $5, 0xFF
    /* B9C8C 001B9C8C 07000010 */  b          .L001B9CAC
    /* B9C90 001B9C90 00000000 */   nop
  .L001B9C94:
    /* B9C94 001B9C94 01080046 */  sub.s      $f0, $f1, $f0
    /* B9C98 001B9C98 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* B9C9C 001B9C9C 00000544 */  mfc1       $5, $f0
    /* B9CA0 001B9CA0 0080043C */  lui        $4, (0x80000000 >> 16)
    /* B9CA4 001B9CA4 2528A400 */  or         $5, $5, $4
    /* B9CA8 001B9CA8 FF00A530 */  andi       $5, $5, 0xFF
  .L001B9CAC:
    /* B9CAC 001B9CAC FF00B530 */  andi       $21, $5, 0xFF
    /* B9CB0 001B9CB0 2D900000 */  daddu      $18, $0, $0
    /* B9CB4 001B9CB4 02000010 */  b          .L001B9CC0
    /* B9CB8 001B9CB8 00000000 */   nop
  .L001B9CBC:
    /* B9CBC 001B9CBC 2DA80000 */  daddu      $21, $0, $0
  .L001B9CC0:
    /* B9CC0 001B9CC0 2D880000 */  daddu      $17, $0, $0
    /* B9CC4 001B9CC4 FFFF7630 */  andi       $22, $3, 0xFFFF
    /* B9CC8 001B9CC8 FFFF5730 */  andi       $23, $2, 0xFFFF
    /* B9CCC 001B9CCC 30000010 */  b          .L001B9D90
    /* B9CD0 001B9CD0 00000000 */   nop
  .L001B9CD4:
    /* B9CD4 001B9CD4 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* B9CD8 001B9CD8 C0180200 */  sll        $3, $2, 3
    /* B9CDC 001B9CDC ACB3828F */  lw         $2, -0x4C54($28)
    /* B9CE0 001B9CE0 21104300 */  addu       $2, $2, $3
    /* B9CE4 001B9CE4 7801508C */  lw         $16, 0x178($2)
    /* B9CE8 001B9CE8 25000010 */  b          .L001B9D80
    /* B9CEC 001B9CEC 00000000 */   nop
  .L001B9CF0:
    /* B9CF0 001B9CF0 FE090296 */  lhu        $2, 0x9FE($16)
    /* B9CF4 001B9CF4 21004010 */  beqz       $2, .L001B9D7C
    /* B9CF8 001B9CF8 00000000 */   nop
    /* B9CFC 001B9CFC A2000392 */  lbu        $3, 0xA2($16)
    /* B9D00 001B9D00 01000224 */  addiu      $2, $0, 0x1
    /* B9D04 001B9D04 04106200 */  sllv       $2, $2, $3
    /* B9D08 001B9D08 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* B9D0C 001B9D0C 2410C302 */  and        $2, $22, $3
    /* B9D10 001B9D10 1A004010 */  beqz       $2, .L001B9D7C
    /* B9D14 001B9D14 00000000 */   nop
    /* B9D18 001B9D18 9C00028E */  lw         $2, 0x9C($16)
    /* B9D1C 001B9D1C 01004230 */  andi       $2, $2, 0x1
    /* B9D20 001B9D20 16004014 */  bnez       $2, .L001B9D7C
    /* B9D24 001B9D24 00000000 */   nop
    /* B9D28 001B9D28 30000292 */  lbu        $2, 0x30($16)
    /* B9D2C 001B9D2C 9C00A2A3 */  sb         $2, 0x9C($29)
    /* B9D30 001B9D30 31000292 */  lbu        $2, 0x31($16)
    /* B9D34 001B9D34 9D00A2A3 */  sb         $2, 0x9D($29)
    /* B9D38 001B9D38 32000292 */  lbu        $2, 0x32($16)
    /* B9D3C 001B9D3C 9E00A2A3 */  sb         $2, 0x9E($29)
    /* B9D40 001B9D40 3000628E */  lw         $2, 0x30($19)
    /* B9D44 001B9D44 07000212 */  beq        $16, $2, .L001B9D64
    /* B9D48 001B9D48 00000000 */   nop
    /* B9D4C 001B9D4C 2410E302 */  and        $2, $23, $3
    /* B9D50 001B9D50 04004014 */  bnez       $2, .L001B9D64
    /* B9D54 001B9D54 00000000 */   nop
    /* B9D58 001B9D58 9F00B5A3 */  sb         $21, 0x9F($29)
    /* B9D5C 001B9D5C 03000010 */  b          .L001B9D6C
    /* B9D60 001B9D60 00000000 */   nop
  .L001B9D64:
    /* B9D64 001B9D64 FF000224 */  addiu      $2, $0, 0xFF
    /* B9D68 001B9D68 9F00A2A3 */  sb         $2, 0x9F($29)
  .L001B9D6C:
    /* B9D6C 001B9D6C 2D200002 */  daddu      $4, $16, $0
    /* B9D70 001B9D70 9C00A58F */  lw         $5, 0x9C($29)
    /* B9D74 001B9D74 D853060C */  jal        func_00194f60
    /* B9D78 001B9D78 00000000 */   nop
  .L001B9D7C:
    /* B9D7C 001B9D7C 6C0A108E */  lw         $16, 0xA6C($16)
  .L001B9D80:
    /* B9D80 001B9D80 DBFF0016 */  bnez       $16, .L001B9CF0
    /* B9D84 001B9D84 00000000 */   nop
    /* B9D88 001B9D88 01002226 */  addiu      $2, $17, 0x1
    /* B9D8C 001B9D8C FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001B9D90:
    /* B9D90 001B9D90 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* B9D94 001B9D94 02004228 */  slti       $2, $2, 0x2
    /* B9D98 001B9D98 CEFF4014 */  bnez       $2, .L001B9CD4
    /* B9D9C 001B9D9C 00000000 */   nop
    /* B9DA0 001B9DA0 0800828E */  lw         $2, 0x8($20)
    /* B9DA4 001B9DA4 01004224 */  addiu      $2, $2, 0x1
    /* B9DA8 001B9DA8 080082AE */  sw         $2, 0x8($20)
    /* B9DAC 001B9DAC 2D104002 */  daddu      $2, $18, $0
  .L001B9DB0:
    /* B9DB0 001B9DB0 8000BFDF */  ld         $31, 0x80($29)
    /* B9DB4 001B9DB4 7000B77B */  lq         $23, 0x70($29)
    /* B9DB8 001B9DB8 6000B67B */  lq         $22, 0x60($29)
    /* B9DBC 001B9DBC 5000B57B */  lq         $21, 0x50($29)
    /* B9DC0 001B9DC0 4000B47B */  lq         $20, 0x40($29)
    /* B9DC4 001B9DC4 3000B37B */  lq         $19, 0x30($29)
    /* B9DC8 001B9DC8 2000B27B */  lq         $18, 0x20($29)
    /* B9DCC 001B9DCC 1000B17B */  lq         $17, 0x10($29)
    /* B9DD0 001B9DD0 0000B07B */  lq         $16, 0x0($29)
    /* B9DD4 001B9DD4 A000BD27 */  addiu      $29, $29, 0xA0
    /* B9DD8 001B9DD8 0800E003 */  jr         $31
    /* B9DDC 001B9DDC 00000000 */   nop
.size func_001b99f0, 0x3f0

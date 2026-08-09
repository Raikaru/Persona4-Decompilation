.section .text
.set noat
.set noreorder
glabel func_001f5a00
    /* F5A00 001F5A00 C0FFBD27 */  addiu      $29, $29, -0x40
    /* F5A04 001F5A04 3000BFFF */  sd         $31, 0x30($29)
    /* F5A08 001F5A08 2000B27F */  sq         $18, 0x20($29)
    /* F5A0C 001F5A0C 1000B17F */  sq         $17, 0x10($29)
    /* F5A10 001F5A10 0000B07F */  sq         $16, 0x0($29)
    /* F5A14 001F5A14 2D908000 */  daddu      $18, $4, $0
    /* F5A18 001F5A18 2D800000 */  daddu      $16, $0, $0
    /* F5A1C 001F5A1C 2D880000 */  daddu      $17, $0, $0
    /* F5A20 001F5A20 5C000010 */  b          .L001F5B94
    /* F5A24 001F5A24 00000000 */   nop
  .L001F5A28:
    /* F5A28 001F5A28 01000524 */  addiu      $5, $0, 0x1
    /* F5A2C 001F5A2C 04186500 */  sllv       $3, $5, $3
    /* F5A30 001F5A30 FFFF6430 */  andi       $4, $3, 0xFFFF
    /* F5A34 001F5A34 ACB3838F */  lw         $3, -0x4C54($28)
    /* F5A38 001F5A38 480A6394 */  lhu        $3, 0xA48($3)
    /* F5A3C 001F5A3C 24186400 */  and        $3, $3, $4
    /* F5A40 001F5A40 52006010 */  beqz       $3, .L001F5B8C
    /* F5A44 001F5A44 00000000 */   nop
    /* F5A48 001F5A48 03008510 */  beq        $4, $5, .L001F5A58
    /* F5A4C 001F5A4C 00000000 */   nop
    /* F5A50 001F5A50 4E000010 */  b          .L001F5B8C
    /* F5A54 001F5A54 00000000 */   nop
  .L001F5A58:
    /* F5A58 001F5A58 50C5060C */  jal        func_001b1540
    /* F5A5C 001F5A5C 00000000 */   nop
    /* F5A60 001F5A60 4A004010 */  beqz       $2, .L001F5B8C
    /* F5A64 001F5A64 00000000 */   nop
    /* F5A68 001F5A68 1A004394 */  lhu        $3, 0x1A($2)
    /* F5A6C 001F5A6C 01006330 */  andi       $3, $3, 0x1
    /* F5A70 001F5A70 46006010 */  beqz       $3, .L001F5B8C
    /* F5A74 001F5A74 00000000 */   nop
    /* F5A78 001F5A78 44004012 */  beqz       $18, .L001F5B8C
    /* F5A7C 001F5A7C 00000000 */   nop
    /* F5A80 001F5A80 3000438C */  lw         $3, 0x30($2)
    /* F5A84 001F5A84 A2006390 */  lbu        $3, 0xA2($3)
    /* F5A88 001F5A88 40006014 */  bnez       $3, .L001F5B8C
    /* F5A8C 001F5A8C 00000000 */   nop
    /* F5A90 001F5A90 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* F5A94 001F5A94 80280300 */  sll        $5, $3, 2
    /* F5A98 001F5A98 ACB3838F */  lw         $3, -0x4C54($28)
    /* F5A9C 001F5A9C 21206500 */  addu       $4, $3, $5
    /* F5AA0 001F5AA0 440A8394 */  lhu        $3, 0xA44($4)
    /* F5AA4 001F5AA4 01006324 */  addiu      $3, $3, 0x1
    /* F5AA8 001F5AA8 440A83A4 */  sh         $3, 0xA44($4)
    /* F5AAC 001F5AAC 14004012 */  beqz       $18, .L001F5B00
    /* F5AB0 001F5AB0 00000000 */   nop
    /* F5AB4 001F5AB4 ACB3868F */  lw         $6, -0x4C54($28)
    /* F5AB8 001F5AB8 2120C500 */  addu       $4, $6, $5
    /* F5ABC 001F5ABC 460A8594 */  lhu        $5, 0xA46($4)
    /* F5AC0 001F5AC0 0400A328 */  slti       $3, $5, 0x4
    /* F5AC4 001F5AC4 0E006014 */  bnez       $3, .L001F5B00
    /* F5AC8 001F5AC8 00000000 */   nop
    /* F5ACC 001F5ACC 440A8494 */  lhu        $4, 0xA44($4)
    /* F5AD0 001F5AD0 43180500 */  sra        $3, $5, 1
    /* F5AD4 001F5AD4 0A008314 */  bne        $4, $3, .L001F5B00
    /* F5AD8 001F5AD8 00000000 */   nop
    /* F5ADC 001F5ADC 7001C48C */  lw         $4, 0x170($6)
    /* F5AE0 001F5AE0 04000524 */  addiu      $5, $0, 0x4
    /* F5AE4 001F5AE4 2D300000 */  daddu      $6, $0, $0
    /* F5AE8 001F5AE8 2D380000 */  daddu      $7, $0, $0
    /* F5AEC 001F5AEC 2D40A000 */  daddu      $8, $5, $0
    /* F5AF0 001F5AF0 B4D5070C */  jal        func_001f56d0
    /* F5AF4 001F5AF4 00000000 */   nop
    /* F5AF8 001F5AF8 24000010 */  b          .L001F5B8C
    /* F5AFC 001F5AFC 00000000 */   nop
  .L001F5B00:
    /* F5B00 001F5B00 ACB3858F */  lw         $5, -0x4C54($28)
    /* F5B04 001F5B04 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* F5B08 001F5B08 80180300 */  sll        $3, $3, 2
    /* F5B0C 001F5B0C 2118A300 */  addu       $3, $5, $3
    /* F5B10 001F5B10 440A6494 */  lhu        $4, 0xA44($3)
    /* F5B14 001F5B14 460A6394 */  lhu        $3, 0xA46($3)
    /* F5B18 001F5B18 2A188300 */  slt        $3, $4, $3
    /* F5B1C 001F5B1C 1B006014 */  bnez       $3, .L001F5B8C
    /* F5B20 001F5B20 00000000 */   nop
    /* F5B24 001F5B24 7001A28C */  lw         $2, 0x170($5)
    /* F5B28 001F5B28 3000428C */  lw         $2, 0x30($2)
    /* F5B2C 001F5B2C 640A448C */  lw         $4, 0xA64($2)
    /* F5B30 001F5B30 1800023C */  lui        $2, (0x180010 >> 16)
    /* F5B34 001F5B34 10004534 */  ori        $5, $2, (0x180010 & 0xFFFF)
    /* F5B38 001F5B38 C4C9080C */  jal        func_00232710
    /* F5B3C 001F5B3C 00000000 */   nop
    /* F5B40 001F5B40 12004014 */  bnez       $2, .L001F5B8C
    /* F5B44 001F5B44 00000000 */   nop
    /* F5B48 001F5B48 54C5060C */  jal        func_001b1550
    /* F5B4C 001F5B4C 00000000 */   nop
    /* F5B50 001F5B50 0E004014 */  bnez       $2, .L001F5B8C
    /* F5B54 001F5B54 00000000 */   nop
    /* F5B58 001F5B58 1C000324 */  addiu      $3, $0, 0x1C
    /* F5B5C 001F5B5C ACB3828F */  lw         $2, -0x4C54($28)
    /* F5B60 001F5B60 7001428C */  lw         $2, 0x170($2)
    /* F5B64 001F5B64 160043A4 */  sh         $3, 0x16($2)
    /* F5B68 001F5B68 ACB3828F */  lw         $2, -0x4C54($28)
    /* F5B6C 001F5B6C 7001448C */  lw         $4, 0x170($2)
    /* F5B70 001F5B70 8CC3060C */  jal        func_001b0e30
    /* F5B74 001F5B74 00000000 */   nop
    /* F5B78 001F5B78 01001024 */  addiu      $16, $0, 0x1
    /* F5B7C 001F5B7C ACB3848F */  lw         $4, -0x4C54($28)
    /* F5B80 001F5B80 480A8394 */  lhu        $3, 0xA48($4)
    /* F5B84 001F5B84 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* F5B88 001F5B88 480A83A4 */  sh         $3, 0xA48($4)
  .L001F5B8C:
    /* F5B8C 001F5B8C 01002326 */  addiu      $3, $17, 0x1
    /* F5B90 001F5B90 FFFF7130 */  andi       $17, $3, 0xFFFF
  .L001F5B94:
    /* F5B94 001F5B94 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* F5B98 001F5B98 0300601C */  bgtz       $3, .L001F5BA8
    /* F5B9C 001F5B9C 00000000 */   nop
    /* F5BA0 001F5BA0 A1FF0012 */  beqz       $16, .L001F5A28
    /* F5BA4 001F5BA4 00000000 */   nop
  .L001F5BA8:
    /* F5BA8 001F5BA8 3000BFDF */  ld         $31, 0x30($29)
    /* F5BAC 001F5BAC 2000B27B */  lq         $18, 0x20($29)
    /* F5BB0 001F5BB0 1000B17B */  lq         $17, 0x10($29)
    /* F5BB4 001F5BB4 0000B07B */  lq         $16, 0x0($29)
    /* F5BB8 001F5BB8 4000BD27 */  addiu      $29, $29, 0x40
    /* F5BBC 001F5BBC 0800E003 */  jr         $31
    /* F5BC0 001F5BC0 00000000 */   nop
    /* F5BC4 001F5BC4 00000000 */  nop
    /* F5BC8 001F5BC8 00000000 */  nop
    /* F5BCC 001F5BCC 00000000 */  nop
.size func_001f5a00, 0x1d0

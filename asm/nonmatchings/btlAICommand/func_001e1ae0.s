.section .text
.set noat
.set noreorder
glabel func_001e1ae0
    /* E1AE0 001E1AE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1AE4 001E1AE4 1000BFFF */  sd         $31, 0x10($29)
    /* E1AE8 001E1AE8 0000B07F */  sq         $16, 0x0($29)
    /* E1AEC 001E1AEC 14740A0C */  jal        func_0029d050
    /* E1AF0 001E1AF0 00000000 */   nop
    /* E1AF4 001E1AF4 2D804000 */  daddu      $16, $2, $0
    /* E1AF8 001E1AF8 2D200000 */  daddu      $4, $0, $0
    /* E1AFC 001E1AFC 00730A0C */  jal        func_0029cc00
    /* E1B00 001E1B00 00000000 */   nop
    /* E1B04 001E1B04 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1B08 001E1B08 3000028E */  lw         $2, 0x30($16)
    /* E1B0C 001E1B0C A2004390 */  lbu        $3, 0xA2($2)
    /* E1B10 001E1B10 01000224 */  addiu      $2, $0, 0x1
    /* E1B14 001E1B14 04106200 */  sllv       $2, $2, $3
    /* E1B18 001E1B18 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1B1C 001E1B1C 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1B20 001E1B20 A064070C */  jal        func_001d9280
    /* E1B24 001E1B24 00000000 */   nop
    /* E1B28 001E1B28 2D804000 */  daddu      $16, $2, $0
    /* E1B2C 001E1B2C 1E000012 */  beqz       $16, .L001E1BA8
    /* E1B30 001E1B30 00000000 */   nop
    /* E1B34 001E1B34 01000424 */  addiu      $4, $0, 0x1
    /* E1B38 001E1B38 00730A0C */  jal        func_0029cc00
    /* E1B3C 001E1B3C 00000000 */   nop
    /* E1B40 001E1B40 3C1A0200 */  dsll32     $3, $2, 8
    /* E1B44 001E1B44 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1B48 001E1B48 0017023C */  lui        $2, (0x17000000 >> 16)
    /* E1B4C 001E1B4C 25206200 */  or         $4, $3, $2
    /* E1B50 001E1B50 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1B54 001E1B54 24108200 */  and        $2, $4, $2
    /* E1B58 001E1B58 021E0200 */  srl        $3, $2, 24
    /* E1B5C 001E1B5C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1B60 001E1B60 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1B64 001E1B64 04006014 */  bnez       $3, .L001E1B78
    /* E1B68 001E1B68 00000000 */   nop
    /* E1B6C 001E1B6C 2D100000 */  daddu      $2, $0, $0
    /* E1B70 001E1B70 0B000010 */  b          .L001E1BA0
    /* E1B74 001E1B74 00000000 */   nop
  .L001E1B78:
    /* E1B78 001E1B78 2D200002 */  daddu      $4, $16, $0
    /* E1B7C 001E1B7C 40100300 */  sll        $2, $3, 1
    /* E1B80 001E1B80 21104300 */  addu       $2, $2, $3
    /* E1B84 001E1B84 80180200 */  sll        $3, $2, 2
    /* E1B88 001E1B88 6100023C */  lui        $2, %hi(D_00609850)
    /* E1B8C 001E1B8C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1B90 001E1B90 21104300 */  addu       $2, $2, $3
    /* E1B94 001E1B94 0000428C */  lw         $2, 0x0($2)
    /* E1B98 001E1B98 09F84000 */  jalr       $2
    /* E1B9C 001E1B9C 00000000 */   nop
  .L001E1BA0:
    /* E1BA0 001E1BA0 02000010 */  b          .L001E1BAC
    /* E1BA4 001E1BA4 00000000 */   nop
  .L001E1BA8:
    /* E1BA8 001E1BA8 2D100000 */  daddu      $2, $0, $0
  .L001E1BAC:
    /* E1BAC 001E1BAC 2B200200 */  sltu       $4, $0, $2
    /* E1BB0 001E1BB0 D4730A0C */  jal        func_0029cf50
    /* E1BB4 001E1BB4 00000000 */   nop
    /* E1BB8 001E1BB8 01000224 */  addiu      $2, $0, 0x1
    /* E1BBC 001E1BBC 1000BFDF */  ld         $31, 0x10($29)
    /* E1BC0 001E1BC0 0000B07B */  lq         $16, 0x0($29)
    /* E1BC4 001E1BC4 2000BD27 */  addiu      $29, $29, 0x20
    /* E1BC8 001E1BC8 0800E003 */  jr         $31
    /* E1BCC 001E1BCC 00000000 */   nop
.size func_001e1ae0, 0xf0

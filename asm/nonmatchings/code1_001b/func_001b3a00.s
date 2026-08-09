.section .text
.set noat
.set noreorder
glabel func_001b3a00
    /* B3A00 001B3A00 A0FFBD27 */  addiu      $29, $29, -0x60
    /* B3A04 001B3A04 5000BFFF */  sd         $31, 0x50($29)
    /* B3A08 001B3A08 4000B47F */  sq         $20, 0x40($29)
    /* B3A0C 001B3A0C 3000B37F */  sq         $19, 0x30($29)
    /* B3A10 001B3A10 2000B27F */  sq         $18, 0x20($29)
    /* B3A14 001B3A14 1000B17F */  sq         $17, 0x10($29)
    /* B3A18 001B3A18 0000B07F */  sq         $16, 0x0($29)
    /* B3A1C 001B3A1C ACB3828F */  lw         $2, -0x4C54($28)
    /* B3A20 001B3A20 0C00428C */  lw         $2, 0xC($2)
    /* B3A24 001B3A24 80004230 */  andi       $2, $2, 0x80
    /* B3A28 001B3A28 28014010 */  beqz       $2, .L001B3ECC
    /* B3A2C 001B3A2C 00000000 */   nop
    /* B3A30 001B3A30 0CC6060C */  jal        func_001b1830
    /* B3A34 001B3A34 00000000 */   nop
    /* B3A38 001B3A38 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3A3C 001B3A3C D40D448C */  lw         $4, 0xDD4($2)
    /* B3A40 001B3A40 E04E080C */  jal        func_00213b80
    /* B3A44 001B3A44 00000000 */   nop
    /* B3A48 001B3A48 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3A4C 001B3A4C D40D448C */  lw         $4, 0xDD4($2)
    /* B3A50 001B3A50 2D280000 */  daddu      $5, $0, $0
    /* B3A54 001B3A54 9048080C */  jal        func_00212240
    /* B3A58 001B3A58 00000000 */   nop
    /* B3A5C 001B3A5C ACB3848F */  lw         $4, -0x4C54($28)
    /* B3A60 001B3A60 1C008394 */  lhu        $3, 0x1C($4)
    /* B3A64 001B3A64 02000224 */  addiu      $2, $0, 0x2
    /* B3A68 001B3A68 00016210 */  beq        $3, $2, .L001B3E6C
    /* B3A6C 001B3A6C 00000000 */   nop
    /* B3A70 001B3A70 03000224 */  addiu      $2, $0, 0x3
    /* B3A74 001B3A74 06006210 */  beq        $3, $2, .L001B3A90
    /* B3A78 001B3A78 00000000 */   nop
    /* B3A7C 001B3A7C 01000224 */  addiu      $2, $0, 0x1
    /* B3A80 001B3A80 03006210 */  beq        $3, $2, .L001B3A90
    /* B3A84 001B3A84 00000000 */   nop
    /* B3A88 001B3A88 10010010 */  b          .L001B3ECC
    /* B3A8C 001B3A8C 00000000 */   nop
  .L001B3A90:
    /* B3A90 001B3A90 03000224 */  addiu      $2, $0, 0x3
    /* B3A94 001B3A94 0E006214 */  bne        $3, $2, .L001B3AD0
    /* B3A98 001B3A98 00000000 */   nop
    /* B3A9C 001B3A9C AC0C8424 */  addiu      $4, $4, 0xCAC
    /* B3AA0 001B3AA0 2D280000 */  daddu      $5, $0, $0
    /* B3AA4 001B3AA4 58000624 */  addiu      $6, $0, 0x58
    /* B3AA8 001B3AA8 72FE100C */  jal        func_0043f9c8
    /* B3AAC 001B3AAC 00000000 */   nop
    /* B3AB0 001B3AB0 ACB3848F */  lw         $4, -0x4C54($28)
    /* B3AB4 001B3AB4 0C00838C */  lw         $3, 0xC($4)
    /* B3AB8 001B3AB8 FFDF023C */  lui        $2, (0xDFFFFFFF >> 16)
    /* B3ABC 001B3ABC FFFF4234 */  ori        $2, $2, (0xDFFFFFFF & 0xFFFF)
    /* B3AC0 001B3AC0 24106200 */  and        $2, $3, $2
    /* B3AC4 001B3AC4 0C0082AC */  sw         $2, 0xC($4)
    /* B3AC8 001B3AC8 17000010 */  b          .L001B3B28
    /* B3ACC 001B3ACC 00000000 */   nop
  .L001B3AD0:
    /* B3AD0 001B3AD0 6C0C8294 */  lhu        $2, 0xC6C($4)
    /* B3AD4 001B3AD4 03004128 */  slti       $1, $2, 0x3
    /* B3AD8 001B3AD8 0E002010 */  beqz       $1, .L001B3B14
    /* B3ADC 001B3ADC 00000000 */   nop
    /* B3AE0 001B3AE0 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3AE4 001B3AE4 80100200 */  sll        $2, $2, 2
    /* B3AE8 001B3AE8 21104300 */  addu       $2, $2, $3
    /* B3AEC 001B3AEC 840C428C */  lw         $2, 0xC84($2)
    /* B3AF0 001B3AF0 08004010 */  beqz       $2, .L001B3B14
    /* B3AF4 001B3AF4 00000000 */   nop
    /* B3AF8 001B3AF8 0C00838C */  lw         $3, 0xC($4)
    /* B3AFC 001B3AFC 0020023C */  lui        $2, (0x20000000 >> 16)
    /* B3B00 001B3B00 25106200 */  or         $2, $3, $2
    /* B3B04 001B3B04 0C0082AC */  sw         $2, 0xC($4)
    /* B3B08 001B3B08 0B000224 */  addiu      $2, $0, 0xB
    /* B3B0C 001B3B0C F0000010 */  b          .L001B3ED0
    /* B3B10 001B3B10 00000000 */   nop
  .L001B3B14:
    /* B3B14 001B3B14 0C00838C */  lw         $3, 0xC($4)
    /* B3B18 001B3B18 FFDF023C */  lui        $2, (0xDFFFFFFF >> 16)
    /* B3B1C 001B3B1C FFFF4234 */  ori        $2, $2, (0xDFFFFFFF & 0xFFFF)
    /* B3B20 001B3B20 24106200 */  and        $2, $3, $2
    /* B3B24 001B3B24 0C0082AC */  sw         $2, 0xC($4)
  .L001B3B28:
    /* B3B28 001B3B28 44C5060C */  jal        func_001b1510
    /* B3B2C 001B3B2C 00000000 */   nop
    /* B3B30 001B3B30 2DA04000 */  daddu      $20, $2, $0
    /* B3B34 001B3B34 2D800000 */  daddu      $16, $0, $0
    /* B3B38 001B3B38 12008012 */  beqz       $20, .L001B3B84
    /* B3B3C 001B3B3C 00000000 */   nop
    /* B3B40 001B3B40 6E008396 */  lhu        $3, 0x6E($20)
    /* B3B44 001B3B44 02010224 */  addiu      $2, $0, 0x102
    /* B3B48 001B3B48 09006210 */  beq        $3, $2, .L001B3B70
    /* B3B4C 001B3B4C 00000000 */   nop
    /* B3B50 001B3B50 01010224 */  addiu      $2, $0, 0x101
    /* B3B54 001B3B54 06006210 */  beq        $3, $2, .L001B3B70
    /* B3B58 001B3B58 00000000 */   nop
    /* B3B5C 001B3B5C 00010224 */  addiu      $2, $0, 0x100
    /* B3B60 001B3B60 03006210 */  beq        $3, $2, .L001B3B70
    /* B3B64 001B3B64 00000000 */   nop
    /* B3B68 001B3B68 06000010 */  b          .L001B3B84
    /* B3B6C 001B3B6C 00000000 */   nop
  .L001B3B70:
    /* B3B70 001B3B70 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3B74 001B3B74 AC0C6294 */  lhu        $2, 0xCAC($3)
    /* B3B78 001B3B78 02004234 */  ori        $2, $2, 0x2
    /* B3B7C 001B3B7C AC0C62A4 */  sh         $2, 0xCAC($3)
    /* B3B80 001B3B80 01001024 */  addiu      $16, $0, 0x1
  .L001B3B84:
    /* B3B84 001B3B84 2D880000 */  daddu      $17, $0, $0
    /* B3B88 001B3B88 2D900000 */  daddu      $18, $0, $0
    /* B3B8C 001B3B8C ACB3828F */  lw         $2, -0x4C54($28)
    /* B3B90 001B3B90 7C01538C */  lw         $19, 0x17C($2)
    /* B3B94 001B3B94 17000010 */  b          .L001B3BF4
    /* B3B98 001B3B98 00000000 */   nop
  .L001B3B9C:
    /* B3B9C 001B3B9C 640A648E */  lw         $4, 0xA64($19)
    /* B3BA0 001B3BA0 2D280000 */  daddu      $5, $0, $0
    /* B3BA4 001B3BA4 3C0A090C */  jal        func_002428f0
    /* B3BA8 001B3BA8 00000000 */   nop
    /* B3BAC 001B3BAC 05004010 */  beqz       $2, .L001B3BC4
    /* B3BB0 001B3BB0 00000000 */   nop
    /* B3BB4 001B3BB4 01002226 */  addiu      $2, $17, 0x1
    /* B3BB8 001B3BB8 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* B3BBC 001B3BBC 0C000010 */  b          .L001B3BF0
    /* B3BC0 001B3BC0 00000000 */   nop
  .L001B3BC4:
    /* B3BC4 001B3BC4 640A628E */  lw         $2, 0xA64($19)
    /* B3BC8 001B3BC8 02004494 */  lhu        $4, 0x2($2)
    /* B3BCC 001B3BCC FFFF4232 */  andi       $2, $18, 0xFFFF
    /* B3BD0 001B3BD0 40180200 */  sll        $3, $2, 1
    /* B3BD4 001B3BD4 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3BD8 001B3BD8 21104300 */  addu       $2, $2, $3
    /* B3BDC 001B3BDC BE0C44A4 */  sh         $4, 0xCBE($2)
    /* B3BE0 001B3BE0 01004226 */  addiu      $2, $18, 0x1
    /* B3BE4 001B3BE4 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* B3BE8 001B3BE8 01002226 */  addiu      $2, $17, 0x1
    /* B3BEC 001B3BEC FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001B3BF0:
    /* B3BF0 001B3BF0 680A738E */  lw         $19, 0xA68($19)
  .L001B3BF4:
    /* B3BF4 001B3BF4 E9FF6016 */  bnez       $19, .L001B3B9C
    /* B3BF8 001B3BF8 00000000 */   nop
    /* B3BFC 001B3BFC FFFF2332 */  andi       $3, $17, 0xFFFF
    /* B3C00 001B3C00 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3C04 001B3C04 CC0C43AC */  sw         $3, 0xCCC($2)
    /* B3C08 001B3C08 FFFF4332 */  andi       $3, $18, 0xFFFF
    /* B3C0C 001B3C0C ACB3828F */  lw         $2, -0x4C54($28)
    /* B3C10 001B3C10 C80C43AC */  sw         $3, 0xCC8($2)
    /* B3C14 001B3C14 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3C18 001B3C18 5A0C6294 */  lhu        $2, 0xC5A($3)
    /* B3C1C 001B3C1C E80C62AC */  sw         $2, 0xCE8($3)
    /* B3C20 001B3C20 ACB3848F */  lw         $4, -0x4C54($28)
    /* B3C24 001B3C24 5A0C8394 */  lhu        $3, 0xC5A($4)
    /* B3C28 001B3C28 05006018 */  blez       $3, .L001B3C40
    /* B3C2C 001B3C2C 00000000 */   nop
    /* B3C30 001B3C30 E40C828C */  lw         $2, 0xCE4($4)
    /* B3C34 001B3C34 1A004300 */  div        $0, $2, $3
    /* B3C38 001B3C38 12100000 */  mflo       $2
    /* B3C3C 001B3C3C E40C82AC */  sw         $2, 0xCE4($4)
  .L001B3C40:
    /* B3C40 001B3C40 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3C44 001B3C44 1C004394 */  lhu        $3, 0x1C($2)
    /* B3C48 001B3C48 03000224 */  addiu      $2, $0, 0x3
    /* B3C4C 001B3C4C 12006210 */  beq        $3, $2, .L001B3C98
    /* B3C50 001B3C50 00000000 */   nop
    /* B3C54 001B3C54 2D208002 */  daddu      $4, $20, $0
    /* B3C58 001B3C58 F8BD070C */  jal        func_001ef7e0
    /* B3C5C 001B3C5C 00000000 */   nop
    /* B3C60 001B3C60 0D004010 */  beqz       $2, .L001B3C98
    /* B3C64 001B3C64 00000000 */   nop
    /* B3C68 001B3C68 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3C6C 001B3C6C E40C4584 */  lh         $5, 0xCE4($2)
    /* B3C70 001B3C70 EC0C4424 */  addiu      $4, $2, 0xCEC
    /* B3C74 001B3C74 2D300002 */  daddu      $6, $16, $0
    /* B3C78 001B3C78 98BB0D0C */  jal        func_0036ee60
    /* B3C7C 001B3C7C 00000000 */   nop
    /* B3C80 001B3C80 05004010 */  beqz       $2, .L001B3C98
    /* B3C84 001B3C84 00000000 */   nop
    /* B3C88 001B3C88 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3C8C 001B3C8C AC0C6294 */  lhu        $2, 0xCAC($3)
    /* B3C90 001B3C90 01004234 */  ori        $2, $2, 0x1
    /* B3C94 001B3C94 AC0C62A4 */  sh         $2, 0xCAC($3)
  .L001B3C98:
    /* B3C98 001B3C98 48AF080C */  jal        func_0022bd20
    /* B3C9C 001B3C9C 00000000 */   nop
    /* B3CA0 001B3CA0 05004010 */  beqz       $2, .L001B3CB8
    /* B3CA4 001B3CA4 00000000 */   nop
    /* B3CA8 001B3CA8 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3CAC 001B3CAC AC0C6294 */  lhu        $2, 0xCAC($3)
    /* B3CB0 001B3CB0 08004234 */  ori        $2, $2, 0x8
    /* B3CB4 001B3CB4 AC0C62A4 */  sh         $2, 0xCAC($3)
  .L001B3CB8:
    /* B3CB8 001B3CB8 68BE070C */  jal        func_001ef9a0
    /* B3CBC 001B3CBC 00000000 */   nop
    /* B3CC0 001B3CC0 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3CC4 001B3CC4 B80C62AC */  sw         $2, 0xCB8($3)
    /* B3CC8 001B3CC8 68BE070C */  jal        func_001ef9a0
    /* B3CCC 001B3CCC 00000000 */   nop
    /* B3CD0 001B3CD0 40180200 */  sll        $3, $2, 1
    /* B3CD4 001B3CD4 21106200 */  addu       $2, $3, $2
    /* B3CD8 001B3CD8 C0180200 */  sll        $3, $2, 3
    /* B3CDC 001B3CDC 14B4828F */  lw         $2, -0x4BEC($28)
    /* B3CE0 001B3CE0 21104300 */  addu       $2, $2, $3
    /* B3CE4 001B3CE4 0000428C */  lw         $2, 0x0($2)
    /* B3CE8 001B3CE8 00204230 */  andi       $2, $2, 0x2000
    /* B3CEC 001B3CEC 1E004010 */  beqz       $2, .L001B3D68
    /* B3CF0 001B3CF0 00000000 */   nop
    /* B3CF4 001B3CF4 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3CF8 001B3CF8 7001428C */  lw         $2, 0x170($2)
    /* B3CFC 001B3CFC 3000428C */  lw         $2, 0x30($2)
    /* B3D00 001B3D00 640A448C */  lw         $4, 0xA64($2)
    /* B3D04 001B3D04 88C7080C */  jal        func_00231e20
    /* B3D08 001B3D08 00000000 */   nop
    /* B3D0C 001B3D0C FF004230 */  andi       $2, $2, 0xFF
    /* B3D10 001B3D10 3C1C0200 */  dsll32     $3, $2, 16
    /* B3D14 001B3D14 3F1C0300 */  dsra32     $3, $3, 16
    /* B3D18 001B3D18 ACB3848F */  lw         $4, -0x4C54($28)
    /* B3D1C 001B3D1C E00C8284 */  lh         $2, 0xCE0($4)
    /* B3D20 001B3D20 23104300 */  subu       $2, $2, $3
    /* B3D24 001B3D24 3C140200 */  dsll32     $2, $2, 16
    /* B3D28 001B3D28 3F140200 */  dsra32     $2, $2, 16
    /* B3D2C 001B3D2C 04004104 */  bgez       $2, .L001B3D40
    /* B3D30 001B3D30 00000000 */   nop
    /* B3D34 001B3D34 2D100000 */  daddu      $2, $0, $0
    /* B3D38 001B3D38 05000010 */  b          .L001B3D50
    /* B3D3C 001B3D3C 00000000 */   nop
  .L001B3D40:
    /* B3D40 001B3D40 06004128 */  slti       $1, $2, 0x6
    /* B3D44 001B3D44 02002014 */  bnez       $1, .L001B3D50
    /* B3D48 001B3D48 00000000 */   nop
    /* B3D4C 001B3D4C 05000224 */  addiu      $2, $0, 0x5
  .L001B3D50:
    /* B3D50 001B3D50 3C1C0200 */  dsll32     $3, $2, 16
    /* B3D54 001B3D54 3F1C0300 */  dsra32     $3, $3, 16
    /* B3D58 001B3D58 10B4828F */  lw         $2, -0x4BF0($28)
    /* B3D5C 001B3D5C 21104300 */  addu       $2, $2, $3
    /* B3D60 001B3D60 00004290 */  lbu        $2, 0x0($2)
    /* B3D64 001B3D64 BC0C82A4 */  sh         $2, 0xCBC($4)
  .L001B3D68:
    /* B3D68 001B3D68 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3D6C 001B3D6C 7C01518C */  lw         $17, 0x17C($2)
    /* B3D70 001B3D70 15000010 */  b          .L001B3DC8
    /* B3D74 001B3D74 00000000 */   nop
  .L001B3D78:
    /* B3D78 001B3D78 640A248E */  lw         $4, 0xA64($17)
    /* B3D7C 001B3D7C 11008010 */  beqz       $4, .L001B3DC4
    /* B3D80 001B3D80 00000000 */   nop
    /* B3D84 001B3D84 B8C9080C */  jal        func_002326e0
    /* B3D88 001B3D88 00000000 */   nop
    /* B3D8C 001B3D8C 2D804000 */  daddu      $16, $2, $0
    /* B3D90 001B3D90 640A248E */  lw         $4, 0xA64($17)
    /* B3D94 001B3D94 F7FF023C */  lui        $2, (0xFFF7FFFF >> 16)
    /* B3D98 001B3D98 FFFF4534 */  ori        $5, $2, (0xFFF7FFFF & 0xFFFF)
    /* B3D9C 001B3D9C BCC9080C */  jal        func_002326f0
    /* B3DA0 001B3DA0 00000000 */   nop
    /* B3DA4 001B3DA4 1000023C */  lui        $2, (0x100000 >> 16)
    /* B3DA8 001B3DA8 24100202 */  and        $2, $16, $2
    /* B3DAC 001B3DAC 05004014 */  bnez       $2, .L001B3DC4
    /* B3DB0 001B3DB0 00000000 */   nop
    /* B3DB4 001B3DB4 2D202002 */  daddu      $4, $17, $0
    /* B3DB8 001B3DB8 06000524 */  addiu      $5, $0, 0x6
    /* B3DBC 001B3DBC 7463060C */  jal        func_00198dd0
    /* B3DC0 001B3DC0 00000000 */   nop
  .L001B3DC4:
    /* B3DC4 001B3DC4 680A318E */  lw         $17, 0xA68($17)
  .L001B3DC8:
    /* B3DC8 001B3DC8 EBFF2016 */  bnez       $17, .L001B3D78
    /* B3DCC 001B3DCC 00000000 */   nop
    /* B3DD0 001B3DD0 ACB3848F */  lw         $4, -0x4C54($28)
    /* B3DD4 001B3DD4 AC0C8294 */  lhu        $2, 0xCAC($4)
    /* B3DD8 001B3DD8 01004230 */  andi       $2, $2, 0x1
    /* B3DDC 001B3DDC 09004010 */  beqz       $2, .L001B3E04
    /* B3DE0 001B3DE0 00000000 */   nop
    /* B3DE4 001B3DE4 0C00838C */  lw         $3, 0xC($4)
    /* B3DE8 001B3DE8 0020023C */  lui        $2, (0x20000000 >> 16)
    /* B3DEC 001B3DEC 24106200 */  and        $2, $3, $2
    /* B3DF0 001B3DF0 04004014 */  bnez       $2, .L001B3E04
    /* B3DF4 001B3DF4 00000000 */   nop
    /* B3DF8 001B3DF8 D40D848C */  lw         $4, 0xDD4($4)
    /* B3DFC 001B3DFC 284E080C */  jal        func_002138a0
    /* B3E00 001B3E00 00000000 */   nop
  .L001B3E04:
    /* B3E04 001B3E04 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3E08 001B3E08 C80D448C */  lw         $4, 0xDC8($2)
    /* B3E0C 001B3E0C AC0C4524 */  addiu      $5, $2, 0xCAC
    /* B3E10 001B3E10 6076080C */  jal        func_0021d980
    /* B3E14 001B3E14 00000000 */   nop
    /* B3E18 001B3E18 ACB3838F */  lw         $3, -0x4C54($28)
    /* B3E1C 001B3E1C D00D62AC */  sw         $2, 0xDD0($3)
    /* B3E20 001B3E20 ACB3828F */  lw         $2, -0x4C54($28)
    /* B3E24 001B3E24 D00D448C */  lw         $4, 0xDD0($2)
    /* B3E28 001B3E28 AC76080C */  jal        func_0021dab0
    /* B3E2C 001B3E2C 00000000 */   nop
    /* B3E30 001B3E30 ACB3848F */  lw         $4, -0x4C54($28)
    /* B3E34 001B3E34 1C008394 */  lhu        $3, 0x1C($4)
    /* B3E38 001B3E38 01000224 */  addiu      $2, $0, 0x1
    /* B3E3C 001B3E3C 0B006214 */  bne        $3, $2, .L001B3E6C
    /* B3E40 001B3E40 00000000 */   nop
    /* B3E44 001B3E44 1000828C */  lw         $2, 0x10($4)
    /* B3E48 001B3E48 02004230 */  andi       $2, $2, 0x2
    /* B3E4C 001B3E4C 04004010 */  beqz       $2, .L001B3E60
    /* B3E50 001B3E50 00000000 */   nop
    /* B3E54 001B3E54 0C000224 */  addiu      $2, $0, 0xC
    /* B3E58 001B3E58 02000010 */  b          .L001B3E64
    /* B3E5C 001B3E5C 00000000 */   nop
  .L001B3E60:
    /* B3E60 001B3E60 0B000224 */  addiu      $2, $0, 0xB
  .L001B3E64:
    /* B3E64 001B3E64 1A000010 */  b          .L001B3ED0
    /* B3E68 001B3E68 00000000 */   nop
  .L001B3E6C:
    /* B3E6C 001B3E6C 02000224 */  addiu      $2, $0, 0x2
    /* B3E70 001B3E70 13006214 */  bne        $3, $2, .L001B3EC0
    /* B3E74 001B3E74 00000000 */   nop
    /* B3E78 001B3E78 1000838C */  lw         $3, 0x10($4)
    /* B3E7C 001B3E7C 0020023C */  lui        $2, (0x20000000 >> 16)
    /* B3E80 001B3E80 24106200 */  and        $2, $3, $2
    /* B3E84 001B3E84 04004010 */  beqz       $2, .L001B3E98
    /* B3E88 001B3E88 00000000 */   nop
    /* B3E8C 001B3E8C 0C000224 */  addiu      $2, $0, 0xC
    /* B3E90 001B3E90 0F000010 */  b          .L001B3ED0
    /* B3E94 001B3E94 00000000 */   nop
  .L001B3E98:
    /* B3E98 001B3E98 984C060C */  jal        func_00193260
    /* B3E9C 001B3E9C 00000000 */   nop
    /* B3EA0 001B3EA0 04004010 */  beqz       $2, .L001B3EB4
    /* B3EA4 001B3EA4 00000000 */   nop
    /* B3EA8 001B3EA8 09000224 */  addiu      $2, $0, 0x9
    /* B3EAC 001B3EAC 02000010 */  b          .L001B3EB8
    /* B3EB0 001B3EB0 00000000 */   nop
  .L001B3EB4:
    /* B3EB4 001B3EB4 0D000224 */  addiu      $2, $0, 0xD
  .L001B3EB8:
    /* B3EB8 001B3EB8 05000010 */  b          .L001B3ED0
    /* B3EBC 001B3EBC 00000000 */   nop
  .L001B3EC0:
    /* B3EC0 001B3EC0 0E000224 */  addiu      $2, $0, 0xE
    /* B3EC4 001B3EC4 02000010 */  b          .L001B3ED0
    /* B3EC8 001B3EC8 00000000 */   nop
  .L001B3ECC:
    /* B3ECC 001B3ECC 2D100000 */  daddu      $2, $0, $0
  .L001B3ED0:
    /* B3ED0 001B3ED0 5000BFDF */  ld         $31, 0x50($29)
    /* B3ED4 001B3ED4 4000B47B */  lq         $20, 0x40($29)
    /* B3ED8 001B3ED8 3000B37B */  lq         $19, 0x30($29)
    /* B3EDC 001B3EDC 2000B27B */  lq         $18, 0x20($29)
    /* B3EE0 001B3EE0 1000B17B */  lq         $17, 0x10($29)
    /* B3EE4 001B3EE4 0000B07B */  lq         $16, 0x0($29)
    /* B3EE8 001B3EE8 6000BD27 */  addiu      $29, $29, 0x60
    /* B3EEC 001B3EEC 0800E003 */  jr         $31
    /* B3EF0 001B3EF0 00000000 */   nop
    /* B3EF4 001B3EF4 00000000 */  nop
    /* B3EF8 001B3EF8 00000000 */  nop
    /* B3EFC 001B3EFC 00000000 */  nop
.size func_001b3a00, 0x500

.section .text
.set noat
.set noreorder
glabel func_003c0960
    /* 2C0960 003C0960 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 2C0964 003C0964 18000224 */  addiu      $2, $0, 0x18
    /* 2C0968 003C0968 9000BFFF */  sd         $31, 0x90($29)
    /* 2C096C 003C096C 8000BE7F */  sq         $30, 0x80($29)
    /* 2C0970 003C0970 7000B77F */  sq         $23, 0x70($29)
    /* 2C0974 003C0974 6000B67F */  sq         $22, 0x60($29)
    /* 2C0978 003C0978 2DB8A000 */  daddu      $23, $5, $0
    /* 2C097C 003C097C 5000B57F */  sq         $21, 0x50($29)
    /* 2C0980 003C0980 4000B47F */  sq         $20, 0x40($29)
    /* 2C0984 003C0984 3000B37F */  sq         $19, 0x30($29)
    /* 2C0988 003C0988 2DA08000 */  daddu      $20, $4, $0
    /* 2C098C 003C098C 2000B27F */  sq         $18, 0x20($29)
    /* 2C0990 003C0990 C000A427 */  addiu      $4, $29, 0xC0
    /* 2C0994 003C0994 1000B17F */  sq         $17, 0x10($29)
    /* 2C0998 003C0998 0000B07F */  sq         $16, 0x0($29)
    /* 2C099C 003C099C EC00A2AF */  sw         $2, 0xEC($29)
    /* 2C09A0 003C09A0 0400858E */  lw         $5, 0x4($20)
    /* 2C09A4 003C09A4 0C960F0C */  jal        func_003e5830
    /* 2C09A8 003C09A8 04009526 */   addiu     $21, $20, 0x4
    /* 2C09AC 003C09AC 0C004014 */  bnez       $2, .L003C09E0
    /* 2C09B0 003C09B0 00000000 */   nop
    /* 2C09B4 003C09B4 2D300000 */  daddu      $6, $0, $0
  .L003C09B8:
    /* 2C09B8 003C09B8 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2C09BC 003C09BC 2D20E002 */  daddu      $4, $23, $0
    /* 2C09C0 003C09C0 10000524 */  addiu      $5, $0, 0x10
    /* 2C09C4 003C09C4 37000824 */  addiu      $8, $0, 0x37
    /* 2C09C8 003C09C8 FC7B0F0C */  jal        func_003deff0
    /* 2C09CC 003C09CC 02704734 */   ori       $7, $2, (0x37002 & 0xFFFF)
    /* 2C09D0 003C09D0 43004014 */  bnez       $2, .L003C0AE0
    /* 2C09D4 003C09D4 00000000 */   nop
    /* 2C09D8 003C09D8 42010010 */  b          .L003C0EE4
    /* 2C09DC 003C09DC 2D100000 */   daddu     $2, $0, $0
  .L003C09E0:
    /* 2C09E0 003C09E0 8C960F0C */  jal        func_003e5a30
    /* 2C09E4 003C09E4 C000A427 */   addiu     $4, $29, 0xC0
    /* 2C09E8 003C09E8 0C004324 */  addiu      $3, $2, 0xC
    /* 2C09EC 003C09EC C000A427 */  addiu      $4, $29, 0xC0
    /* 2C09F0 003C09F0 EC00A28F */  lw         $2, 0xEC($29)
    /* 2C09F4 003C09F4 21104300 */  addu       $2, $2, $3
    /* 2C09F8 003C09F8 78960F0C */  jal        func_003e59e0
    /* 2C09FC 003C09FC EC00A2AF */   sw        $2, 0xEC($29)
    /* 2C0A00 003C0A00 B800A427 */  addiu      $4, $29, 0xB8
    /* 2C0A04 003C0A04 2D288002 */  daddu      $5, $20, $0
    /* 2C0A08 003C0A08 ECFA0E0C */  jal        func_003bebb0
    /* 2C0A0C 003C0A0C BC00A0AF */   sw        $0, 0xBC($29)
    /* 2C0A10 003C0A10 03004014 */  bnez       $2, .L003C0A20
    /* 2C0A14 003C0A14 00000000 */   nop
    /* 2C0A18 003C0A18 E7FF0010 */  b          .L003C09B8
    /* 2C0A1C 003C0A1C 2D300000 */   daddu     $6, $0, $0
  .L003C0A20:
    /* 2C0A20 003C0A20 BC00A28F */  lw         $2, 0xBC($29)
    /* 2C0A24 003C0A24 10001224 */  addiu      $18, $0, 0x10
    /* 2C0A28 003C0A28 2A080200 */  slt        $1, $0, $2
    /* 2C0A2C 003C0A2C 0E002010 */  beqz       $1, .L003C0A68
    /* 2C0A30 003C0A30 2D880000 */   daddu     $17, $0, $0
    /* 2C0A34 003C0A34 2D800000 */  daddu      $16, $0, $0
    /* 2C0A38 003C0A38 BC00B327 */  addiu      $19, $29, 0xBC
  .L003C0A3C:
    /* 2C0A3C 003C0A3C B800A28F */  lw         $2, 0xB8($29)
    /* 2C0A40 003C0A40 21105000 */  addu       $2, $2, $16
    /* 2C0A44 003C0A44 240B0F0C */  jal        func_003c2c90
    /* 2C0A48 003C0A48 0000448C */   lw        $4, 0x0($2)
    /* 2C0A4C 003C0A4C 0C004224 */  addiu      $2, $2, 0xC
    /* 2C0A50 003C0A50 01003126 */  addiu      $17, $17, 0x1
    /* 2C0A54 003C0A54 21904202 */  addu       $18, $18, $2
    /* 2C0A58 003C0A58 0000628E */  lw         $2, 0x0($19)
    /* 2C0A5C 003C0A5C 2A102202 */  slt        $2, $17, $2
    /* 2C0A60 003C0A60 F6FF4014 */  bnez       $2, .L003C0A3C
    /* 2C0A64 003C0A64 04001026 */   addiu     $16, $16, 0x4
  .L003C0A68:
    /* 2C0A68 003C0A68 EC00A28F */  lw         $2, 0xEC($29)
    /* 2C0A6C 003C0A6C 0C004326 */  addiu      $3, $18, 0xC
    /* 2C0A70 003C0A70 B800A427 */  addiu      $4, $29, 0xB8
    /* 2C0A74 003C0A74 21104300 */  addu       $2, $2, $3
    /* 2C0A78 003C0A78 C4FA0E0C */  jal        func_003beb10
    /* 2C0A7C 003C0A7C EC00A2AF */   sw        $2, 0xEC($29)
    /* 2C0A80 003C0A80 3C00053C */  lui        $5, %hi(func_003bf360)
    /* 2C0A84 003C0A84 2D208002 */  daddu      $4, $20, $0
    /* 2C0A88 003C0A88 60F3A524 */  addiu      $5, $5, %lo(func_003bf360)
    /* 2C0A8C 003C0A8C CCFF0E0C */  jal        func_003bff30
    /* 2C0A90 003C0A90 EC00A627 */   addiu     $6, $29, 0xEC
    /* 2C0A94 003C0A94 3C00053C */  lui        $5, %hi(func_003bf280)
    /* 2C0A98 003C0A98 2D208002 */  daddu      $4, $20, $0
    /* 2C0A9C 003C0A9C 80F2A524 */  addiu      $5, $5, %lo(func_003bf280)
    /* 2C0AA0 003C0AA0 14000F0C */  jal        func_003c0050
    /* 2C0AA4 003C0AA4 EC00A627 */   addiu     $6, $29, 0xEC
    /* 2C0AA8 003C0AA8 3C00053C */  lui        $5, %hi(func_003bf2d0)
    /* 2C0AAC 003C0AAC 2D208002 */  daddu      $4, $20, $0
    /* 2C0AB0 003C0AB0 D0F2A524 */  addiu      $5, $5, %lo(func_003bf2d0)
    /* 2C0AB4 003C0AB4 F0FF0E0C */  jal        func_003bffc0
    /* 2C0AB8 003C0AB8 EC00A627 */   addiu     $6, $29, 0xEC
    /* 2C0ABC 003C0ABC 7100043C */  lui        $4, %hi(D_0070AF90)
    /* 2C0AC0 003C0AC0 2D288002 */  daddu      $5, $20, $0
    /* 2C0AC4 003C0AC4 DC8C0F0C */  jal        func_003e3370
    /* 2C0AC8 003C0AC8 90AF8424 */   addiu     $4, $4, %lo(D_0070AF90)
    /* 2C0ACC 003C0ACC 0C004324 */  addiu      $3, $2, 0xC
    /* 2C0AD0 003C0AD0 EC00A28F */  lw         $2, 0xEC($29)
    /* 2C0AD4 003C0AD4 21304300 */  addu       $6, $2, $3
    /* 2C0AD8 003C0AD8 B7FF0010 */  b          .L003C09B8
    /* 2C0ADC 003C0ADC EC00A6AF */   sw        $6, 0xEC($29)
  .L003C0AE0:
    /* 2C0AE0 003C0AE0 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2C0AE4 003C0AE4 2D20E002 */  daddu      $4, $23, $0
    /* 2C0AE8 003C0AE8 01000524 */  addiu      $5, $0, 0x1
    /* 2C0AEC 003C0AEC 0C000624 */  addiu      $6, $0, 0xC
    /* 2C0AF0 003C0AF0 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2C0AF4 003C0AF4 FC7B0F0C */  jal        func_003deff0
    /* 2C0AF8 003C0AF8 37000824 */   addiu     $8, $0, 0x37
    /* 2C0AFC 003C0AFC 03004014 */  bnez       $2, .L003C0B0C
    /* 2C0B00 003C0B00 00000000 */   nop
    /* 2C0B04 003C0B04 F7000010 */  b          .L003C0EE4
    /* 2C0B08 003C0B08 2D100000 */   daddu     $2, $0, $0
  .L003C0B0C:
    /* 2C0B0C 003C0B0C 3C00053C */  lui        $5, %hi(func_003be940)
    /* 2C0B10 003C0B10 2D208002 */  daddu      $4, $20, $0
    /* 2C0B14 003C0B14 40E9A524 */  addiu      $5, $5, %lo(func_003be940)
    /* 2C0B18 003C0B18 E800A627 */  addiu      $6, $29, 0xE8
    /* 2C0B1C 003C0B1C CCFF0E0C */  jal        func_003bff30
    /* 2C0B20 003C0B20 E800A0AF */   sw        $0, 0xE8($29)
    /* 2C0B24 003C0B24 E800A28F */  lw         $2, 0xE8($29)
    /* 2C0B28 003C0B28 3C00053C */  lui        $5, %hi(func_003be960)
    /* 2C0B2C 003C0B2C 2D208002 */  daddu      $4, $20, $0
    /* 2C0B30 003C0B30 60E9A524 */  addiu      $5, $5, %lo(func_003be960)
    /* 2C0B34 003C0B34 E400A627 */  addiu      $6, $29, 0xE4
    /* 2C0B38 003C0B38 E400A0AF */  sw         $0, 0xE4($29)
    /* 2C0B3C 003C0B3C 14000F0C */  jal        func_003c0050
    /* 2C0B40 003C0B40 C800A2AF */   sw        $2, 0xC8($29)
    /* 2C0B44 003C0B44 E400A28F */  lw         $2, 0xE4($29)
    /* 2C0B48 003C0B48 CC00B327 */  addiu      $19, $29, 0xCC
    /* 2C0B4C 003C0B4C 3C00053C */  lui        $5, %hi(func_003be980)
    /* 2C0B50 003C0B50 2D208002 */  daddu      $4, $20, $0
    /* 2C0B54 003C0B54 80E9A524 */  addiu      $5, $5, %lo(func_003be980)
    /* 2C0B58 003C0B58 E000A627 */  addiu      $6, $29, 0xE0
    /* 2C0B5C 003C0B5C E000A0AF */  sw         $0, 0xE0($29)
    /* 2C0B60 003C0B60 F0FF0E0C */  jal        func_003bffc0
    /* 2C0B64 003C0B64 000062AE */   sw        $2, 0x0($19)
    /* 2C0B68 003C0B68 E000A28F */  lw         $2, 0xE0($29)
    /* 2C0B6C 003C0B6C D000BE27 */  addiu      $30, $29, 0xD0
    /* 2C0B70 003C0B70 2D20E002 */  daddu      $4, $23, $0
    /* 2C0B74 003C0B74 C800A527 */  addiu      $5, $29, 0xC8
    /* 2C0B78 003C0B78 0C000624 */  addiu      $6, $0, 0xC
    /* 2C0B7C 003C0B7C AC8A0F0C */  jal        func_003e2ab0
    /* 2C0B80 003C0B80 0000C2AF */   sw        $2, 0x0($30)
    /* 2C0B84 003C0B84 03004014 */  bnez       $2, .L003C0B94
    /* 2C0B88 003C0B88 00000000 */   nop
    /* 2C0B8C 003C0B8C D5000010 */  b          .L003C0EE4
    /* 2C0B90 003C0B90 2D100000 */   daddu     $2, $0, $0
  .L003C0B94:
    /* 2C0B94 003C0B94 0000A58E */  lw         $5, 0x0($21)
    /* 2C0B98 003C0B98 0C960F0C */  jal        func_003e5830
    /* 2C0B9C 003C0B9C A400A427 */   addiu     $4, $29, 0xA4
    /* 2C0BA0 003C0BA0 03004014 */  bnez       $2, .L003C0BB0
    /* 2C0BA4 003C0BA4 00000000 */   nop
    /* 2C0BA8 003C0BA8 CE000010 */  b          .L003C0EE4
    /* 2C0BAC 003C0BAC 2D100000 */   daddu     $2, $0, $0
  .L003C0BB0:
    /* 2C0BB0 003C0BB0 A400A427 */  addiu      $4, $29, 0xA4
    /* 2C0BB4 003C0BB4 B8960F0C */  jal        func_003e5ae0
    /* 2C0BB8 003C0BB8 2D28E002 */   daddu     $5, $23, $0
    /* 2C0BBC 003C0BBC 0B004010 */  beqz       $2, .L003C0BEC
    /* 2C0BC0 003C0BC0 00000000 */   nop
    /* 2C0BC4 003C0BC4 AC00B627 */  addiu      $22, $29, 0xAC
    /* 2C0BC8 003C0BC8 B000B027 */  addiu      $16, $29, 0xB0
    /* 2C0BCC 003C0BCC 2D20C002 */  daddu      $4, $22, $0
    /* 2C0BD0 003C0BD0 2D288002 */  daddu      $5, $20, $0
    /* 2C0BD4 003C0BD4 ECFA0E0C */  jal        func_003bebb0
    /* 2C0BD8 003C0BD8 000000AE */   sw        $0, 0x0($16)
    /* 2C0BDC 003C0BDC 07004014 */  bnez       $2, .L003C0BFC
    /* 2C0BE0 003C0BE0 00000000 */   nop
    /* 2C0BE4 003C0BE4 BF000010 */  b          .L003C0EE4
    /* 2C0BE8 003C0BE8 2D100000 */   daddu     $2, $0, $0
  .L003C0BEC:
    /* 2C0BEC 003C0BEC 78960F0C */  jal        func_003e59e0
    /* 2C0BF0 003C0BF0 A400A427 */   addiu     $4, $29, 0xA4
    /* 2C0BF4 003C0BF4 BB000010 */  b          .L003C0EE4
    /* 2C0BF8 003C0BF8 2D100000 */   daddu     $2, $0, $0
  .L003C0BFC:
    /* 2C0BFC 003C0BFC 2D20C002 */  daddu      $4, $22, $0
    /* 2C0C00 003C0C00 44FB0E0C */  jal        func_003bed10
    /* 2C0C04 003C0C04 2D28E002 */   daddu     $5, $23, $0
    /* 2C0C08 003C0C08 1B004014 */  bnez       $2, .L003C0C78
    /* 2C0C0C 003C0C0C 00000000 */   nop
    /* 2C0C10 003C0C10 0000028E */  lw         $2, 0x0($16)
    /* 2C0C14 003C0C14 2A100200 */  slt        $2, $0, $2
    /* 2C0C18 003C0C18 0B004014 */  bnez       $2, .L003C0C48
    /* 2C0C1C 003C0C1C 2D900000 */   daddu     $18, $0, $0
    /* 2C0C20 003C0C20 0000C48E */  lw         $4, 0x0($22)
  .L003C0C24:
    /* 2C0C24 003C0C24 06008010 */  beqz       $4, .L003C0C40
    /* 2C0C28 003C0C28 00000000 */   nop
    /* 2C0C2C 003C0C2C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C0C30 003C0C30 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C0C34 003C0C34 09F84000 */  jalr       $2
    /* 2C0C38 003C0C38 00000000 */   nop
    /* 2C0C3C 003C0C3C 0000C0AE */  sw         $0, 0x0($22)
  .L003C0C40:
    /* 2C0C40 003C0C40 A8000010 */  b          .L003C0EE4
    /* 2C0C44 003C0C44 2D100000 */   daddu     $2, $0, $0
  .L003C0C48:
    /* 2C0C48 003C0C48 2D880000 */  daddu      $17, $0, $0
  .L003C0C4C:
    /* 2C0C4C 003C0C4C 0000C28E */  lw         $2, 0x0($22)
    /* 2C0C50 003C0C50 21105100 */  addu       $2, $2, $17
    /* 2C0C54 003C0C54 A00A0F0C */  jal        func_003c2a80
    /* 2C0C58 003C0C58 0000448C */   lw        $4, 0x0($2)
    /* 2C0C5C 003C0C5C 0000028E */  lw         $2, 0x0($16)
    /* 2C0C60 003C0C60 01005226 */  addiu      $18, $18, 0x1
    /* 2C0C64 003C0C64 2A104202 */  slt        $2, $18, $2
    /* 2C0C68 003C0C68 F8FF4014 */  bnez       $2, .L003C0C4C
    /* 2C0C6C 003C0C6C 04003126 */   addiu     $17, $17, 0x4
    /* 2C0C70 003C0C70 ECFF0010 */  b          .L003C0C24
    /* 2C0C74 003C0C74 0000C48E */   lw        $4, 0x0($22)
  .L003C0C78:
    /* 2C0C78 003C0C78 01000324 */  addiu      $3, $0, 0x1
    /* 2C0C7C 003C0C7C B400A227 */  addiu      $2, $29, 0xB4
    /* 2C0C80 003C0C80 A000B7AF */  sw         $23, 0xA0($29)
    /* 2C0C84 003C0C84 08009226 */  addiu      $18, $20, 0x8
    /* 2C0C88 003C0C88 000043AC */  sw         $3, 0x0($2)
    /* 2C0C8C 003C0C8C 0800828E */  lw         $2, 0x8($20)
    /* 2C0C90 003C0C90 09005210 */  beq        $2, $18, .L003C0CB8
    /* 2C0C94 003C0C94 00000000 */   nop
  .L003C0C98:
    /* 2C0C98 003C0C98 0000518C */  lw         $17, 0x0($2)
    /* 2C0C9C 003C0C9C C0FF4424 */  addiu      $4, $2, -0x40
    /* 2C0CA0 003C0CA0 F4FC0E0C */  jal        func_003bf3d0
    /* 2C0CA4 003C0CA4 A000A527 */   addiu     $5, $29, 0xA0
    /* 2C0CA8 003C0CA8 03004010 */  beqz       $2, .L003C0CB8
    /* 2C0CAC 003C0CAC 00000000 */   nop
    /* 2C0CB0 003C0CB0 F9FF3216 */  bne        $17, $18, .L003C0C98
    /* 2C0CB4 003C0CB4 2D102002 */   daddu     $2, $17, $0
  .L003C0CB8:
    /* 2C0CB8 003C0CB8 0000628E */  lw         $2, 0x0($19)
    /* 2C0CBC 003C0CBC 1A004018 */  blez       $2, .L003C0D28
    /* 2C0CC0 003C0CC0 00000000 */   nop
    /* 2C0CC4 003C0CC4 B400A227 */  addiu      $2, $29, 0xB4
    /* 2C0CC8 003C0CC8 0000428C */  lw         $2, 0x0($2)
    /* 2C0CCC 003C0CCC 16004010 */  beqz       $2, .L003C0D28
    /* 2C0CD0 003C0CD0 00000000 */   nop
    /* 2C0CD4 003C0CD4 1000938E */  lw         $19, 0x10($20)
    /* 2C0CD8 003C0CD8 10009526 */  addiu      $21, $20, 0x10
    /* 2C0CDC 003C0CDC 12007512 */  beq        $19, $21, .L003C0D28
    /* 2C0CE0 003C0CE0 00000000 */   nop
  .L003C0CE4:
    /* 2C0CE4 003C0CE4 B4B6828F */  lw         $2, -0x494C($28)
    /* 2C0CE8 003C0CE8 FCFF6326 */  addiu      $3, $19, -0x4
    /* 2C0CEC 003C0CEC A000B127 */  addiu      $17, $29, 0xA0
    /* 2C0CF0 003C0CF0 0000738E */  lw         $19, 0x0($19)
    /* 2C0CF4 003C0CF4 04002426 */  addiu      $4, $17, 0x4
    /* 2C0CF8 003C0CF8 23906200 */  subu       $18, $3, $2
    /* 2C0CFC 003C0CFC 0400458E */  lw         $5, 0x4($18)
    /* 2C0D00 003C0D00 64960F0C */  jal        func_003e5990
    /* 2C0D04 003C0D04 DC00A627 */   addiu     $6, $29, 0xDC
    /* 2C0D08 003C0D08 37004014 */  bnez       $2, .L003C0DE8
    /* 2C0D0C 003C0D0C 00000000 */   nop
  .L003C0D10:
    /* 2C0D10 003C0D10 140020AE */  sw         $0, 0x14($17)
    /* 2C0D14 003C0D14 2D900000 */  daddu      $18, $0, $0
  .L003C0D18:
    /* 2C0D18 003C0D18 03004012 */  beqz       $18, .L003C0D28
    /* 2C0D1C 003C0D1C 00000000 */   nop
    /* 2C0D20 003C0D20 F0FF7516 */  bne        $19, $21, .L003C0CE4
    /* 2C0D24 003C0D24 00000000 */   nop
  .L003C0D28:
    /* 2C0D28 003C0D28 0000C28F */  lw         $2, 0x0($30)
    /* 2C0D2C 003C0D2C 1A004018 */  blez       $2, .L003C0D98
    /* 2C0D30 003C0D30 00000000 */   nop
    /* 2C0D34 003C0D34 B400A227 */  addiu      $2, $29, 0xB4
    /* 2C0D38 003C0D38 0000428C */  lw         $2, 0x0($2)
    /* 2C0D3C 003C0D3C 16004010 */  beqz       $2, .L003C0D98
    /* 2C0D40 003C0D40 00000000 */   nop
    /* 2C0D44 003C0D44 1800938E */  lw         $19, 0x18($20)
    /* 2C0D48 003C0D48 18009526 */  addiu      $21, $20, 0x18
    /* 2C0D4C 003C0D4C 12007512 */  beq        $19, $21, .L003C0D98
    /* 2C0D50 003C0D50 00000000 */   nop
  .L003C0D54:
    /* 2C0D54 003C0D54 B0B6828F */  lw         $2, -0x4950($28)
    /* 2C0D58 003C0D58 FCFF6326 */  addiu      $3, $19, -0x4
    /* 2C0D5C 003C0D5C A000B127 */  addiu      $17, $29, 0xA0
    /* 2C0D60 003C0D60 0000738E */  lw         $19, 0x0($19)
    /* 2C0D64 003C0D64 04002426 */  addiu      $4, $17, 0x4
    /* 2C0D68 003C0D68 23906200 */  subu       $18, $3, $2
    /* 2C0D6C 003C0D6C 0400458E */  lw         $5, 0x4($18)
    /* 2C0D70 003C0D70 64960F0C */  jal        func_003e5990
    /* 2C0D74 003C0D74 D800A627 */   addiu     $6, $29, 0xD8
    /* 2C0D78 003C0D78 31004014 */  bnez       $2, .L003C0E40
    /* 2C0D7C 003C0D7C 00000000 */   nop
  .L003C0D80:
    /* 2C0D80 003C0D80 140020AE */  sw         $0, 0x14($17)
    /* 2C0D84 003C0D84 2D900000 */  daddu      $18, $0, $0
  .L003C0D88:
    /* 2C0D88 003C0D88 03004012 */  beqz       $18, .L003C0D98
    /* 2C0D8C 003C0D8C 00000000 */   nop
    /* 2C0D90 003C0D90 F0FF7516 */  bne        $19, $21, .L003C0D54
    /* 2C0D94 003C0D94 00000000 */   nop
  .L003C0D98:
    /* 2C0D98 003C0D98 0000028E */  lw         $2, 0x0($16)
    /* 2C0D9C 003C0D9C 2A100200 */  slt        $2, $0, $2
    /* 2C0DA0 003C0DA0 3D004014 */  bnez       $2, .L003C0E98
    /* 2C0DA4 003C0DA4 2D900000 */   daddu     $18, $0, $0
    /* 2C0DA8 003C0DA8 0000C48E */  lw         $4, 0x0($22)
  .L003C0DAC:
    /* 2C0DAC 003C0DAC 06008010 */  beqz       $4, .L003C0DC8
    /* 2C0DB0 003C0DB0 00000000 */   nop
    /* 2C0DB4 003C0DB4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C0DB8 003C0DB8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C0DBC 003C0DBC 09F84000 */  jalr       $2
    /* 2C0DC0 003C0DC0 00000000 */   nop
    /* 2C0DC4 003C0DC4 0000C0AE */  sw         $0, 0x0($22)
  .L003C0DC8:
    /* 2C0DC8 003C0DC8 78960F0C */  jal        func_003e59e0
    /* 2C0DCC 003C0DCC A400A427 */   addiu     $4, $29, 0xA4
    /* 2C0DD0 003C0DD0 B400A227 */  addiu      $2, $29, 0xB4
    /* 2C0DD4 003C0DD4 0000428C */  lw         $2, 0x0($2)
    /* 2C0DD8 003C0DD8 3B004014 */  bnez       $2, .L003C0EC8
    /* 2C0DDC 003C0DDC 00000000 */   nop
    /* 2C0DE0 003C0DE0 40000010 */  b          .L003C0EE4
    /* 2C0DE4 003C0DE4 2D100000 */   daddu     $2, $0, $0
  .L003C0DE8:
    /* 2C0DE8 003C0DE8 0000248E */  lw         $4, 0x0($17)
    /* 2C0DEC 003C0DEC 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2C0DF0 003C0DF0 01000524 */  addiu      $5, $0, 0x1
    /* 2C0DF4 003C0DF4 04000624 */  addiu      $6, $0, 0x4
    /* 2C0DF8 003C0DF8 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2C0DFC 003C0DFC FC7B0F0C */  jal        func_003deff0
    /* 2C0E00 003C0E00 37000824 */   addiu     $8, $0, 0x37
    /* 2C0E04 003C0E04 C2FF4010 */  beqz       $2, .L003C0D10
    /* 2C0E08 003C0E08 00000000 */   nop
    /* 2C0E0C 003C0E0C 0000248E */  lw         $4, 0x0($17)
    /* 2C0E10 003C0E10 DC00A527 */  addiu      $5, $29, 0xDC
    /* 2C0E14 003C0E14 907C0F0C */  jal        func_003df240
    /* 2C0E18 003C0E18 04000624 */   addiu     $6, $0, 0x4
    /* 2C0E1C 003C0E1C BCFF4010 */  beqz       $2, .L003C0D10
    /* 2C0E20 003C0E20 00000000 */   nop
    /* 2C0E24 003C0E24 0000258E */  lw         $5, 0x0($17)
    /* 2C0E28 003C0E28 700E0F0C */  jal        func_003c39c0
    /* 2C0E2C 003C0E2C 2D204002 */   daddu     $4, $18, $0
    /* 2C0E30 003C0E30 B7FF4010 */  beqz       $2, .L003C0D10
    /* 2C0E34 003C0E34 00000000 */   nop
    /* 2C0E38 003C0E38 B7FF0010 */  b          .L003C0D18
    /* 2C0E3C 003C0E3C 00000000 */   nop
  .L003C0E40:
    /* 2C0E40 003C0E40 0000248E */  lw         $4, 0x0($17)
    /* 2C0E44 003C0E44 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2C0E48 003C0E48 01000524 */  addiu      $5, $0, 0x1
    /* 2C0E4C 003C0E4C 04000624 */  addiu      $6, $0, 0x4
    /* 2C0E50 003C0E50 37000824 */  addiu      $8, $0, 0x37
    /* 2C0E54 003C0E54 FC7B0F0C */  jal        func_003deff0
    /* 2C0E58 003C0E58 02704734 */   ori       $7, $2, (0x37002 & 0xFFFF)
    /* 2C0E5C 003C0E5C C8FF4010 */  beqz       $2, .L003C0D80
    /* 2C0E60 003C0E60 00000000 */   nop
    /* 2C0E64 003C0E64 0000248E */  lw         $4, 0x0($17)
    /* 2C0E68 003C0E68 D800A527 */  addiu      $5, $29, 0xD8
    /* 2C0E6C 003C0E6C 907C0F0C */  jal        func_003df240
    /* 2C0E70 003C0E70 04000624 */   addiu     $6, $0, 0x4
    /* 2C0E74 003C0E74 C2FF4010 */  beqz       $2, .L003C0D80
    /* 2C0E78 003C0E78 00000000 */   nop
    /* 2C0E7C 003C0E7C 0000258E */  lw         $5, 0x0($17)
    /* 2C0E80 003C0E80 A4940F0C */  jal        func_003e5290
    /* 2C0E84 003C0E84 2D204002 */   daddu     $4, $18, $0
    /* 2C0E88 003C0E88 BDFF4010 */  beqz       $2, .L003C0D80
    /* 2C0E8C 003C0E8C 00000000 */   nop
    /* 2C0E90 003C0E90 BDFF0010 */  b          .L003C0D88
    /* 2C0E94 003C0E94 00000000 */   nop
  .L003C0E98:
    /* 2C0E98 003C0E98 2D880000 */  daddu      $17, $0, $0
  .L003C0E9C:
    /* 2C0E9C 003C0E9C 0000C28E */  lw         $2, 0x0($22)
    /* 2C0EA0 003C0EA0 21105100 */  addu       $2, $2, $17
    /* 2C0EA4 003C0EA4 A00A0F0C */  jal        func_003c2a80
    /* 2C0EA8 003C0EA8 0000448C */   lw        $4, 0x0($2)
    /* 2C0EAC 003C0EAC 0000028E */  lw         $2, 0x0($16)
    /* 2C0EB0 003C0EB0 01005226 */  addiu      $18, $18, 0x1
    /* 2C0EB4 003C0EB4 2A104202 */  slt        $2, $18, $2
    /* 2C0EB8 003C0EB8 F8FF4014 */  bnez       $2, .L003C0E9C
    /* 2C0EBC 003C0EBC 04003126 */   addiu     $17, $17, 0x4
    /* 2C0EC0 003C0EC0 BAFF0010 */  b          .L003C0DAC
    /* 2C0EC4 003C0EC4 0000C48E */   lw        $4, 0x0($22)
  .L003C0EC8:
    /* 2C0EC8 003C0EC8 7100043C */  lui        $4, %hi(D_0070AF90)
    /* 2C0ECC 003C0ECC 2D28E002 */  daddu      $5, $23, $0
    /* 2C0ED0 003C0ED0 90AF8424 */  addiu      $4, $4, %lo(D_0070AF90)
    /* 2C0ED4 003C0ED4 FC8C0F0C */  jal        func_003e33f0
    /* 2C0ED8 003C0ED8 2D308002 */   daddu     $6, $20, $0
    /* 2C0EDC 003C0EDC 0AA00200 */  movz       $20, $0, $2
    /* 2C0EE0 003C0EE0 2D108002 */  daddu      $2, $20, $0
  .L003C0EE4:
    /* 2C0EE4 003C0EE4 9000BFDF */  ld         $31, 0x90($29)
    /* 2C0EE8 003C0EE8 8000BE7B */  lq         $30, 0x80($29)
    /* 2C0EEC 003C0EEC 7000B77B */  lq         $23, 0x70($29)
    /* 2C0EF0 003C0EF0 6000B67B */  lq         $22, 0x60($29)
    /* 2C0EF4 003C0EF4 5000B57B */  lq         $21, 0x50($29)
    /* 2C0EF8 003C0EF8 4000B47B */  lq         $20, 0x40($29)
    /* 2C0EFC 003C0EFC 3000B37B */  lq         $19, 0x30($29)
    /* 2C0F00 003C0F00 2000B27B */  lq         $18, 0x20($29)
    /* 2C0F04 003C0F04 1000B17B */  lq         $17, 0x10($29)
    /* 2C0F08 003C0F08 0000B07B */  lq         $16, 0x0($29)
    /* 2C0F0C 003C0F0C 0800E003 */  jr         $31
    /* 2C0F10 003C0F10 F000BD27 */   addiu     $29, $29, 0xF0
    /* 2C0F14 003C0F14 00000000 */  nop
    /* 2C0F18 003C0F18 00000000 */  nop
    /* 2C0F1C 003C0F1C 00000000 */  nop
.size func_003c0960, 0x5c0

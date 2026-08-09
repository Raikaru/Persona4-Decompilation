.section .text
.set noat
.set noreorder
glabel func_001e9950
    /* E9950 001E9950 60FEBD27 */  addiu      $29, $29, -0x1A0
    /* E9954 001E9954 A000BFFF */  sd         $31, 0xA0($29)
    /* E9958 001E9958 9000BE7F */  sq         $30, 0x90($29)
    /* E995C 001E995C 8000B77F */  sq         $23, 0x80($29)
    /* E9960 001E9960 7000B67F */  sq         $22, 0x70($29)
    /* E9964 001E9964 6000B57F */  sq         $21, 0x60($29)
    /* E9968 001E9968 5000B47F */  sq         $20, 0x50($29)
    /* E996C 001E996C 4000B37F */  sq         $19, 0x40($29)
    /* E9970 001E9970 3000B27F */  sq         $18, 0x30($29)
    /* E9974 001E9974 2000B17F */  sq         $17, 0x20($29)
    /* E9978 001E9978 1000B07F */  sq         $16, 0x10($29)
    /* E997C 001E997C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* E9980 001E9980 0000B4E7 */  swc1       $f20, 0x0($29)
    /* E9984 001E9984 14740A0C */  jal        func_0029d050
    /* E9988 001E9988 00000000 */   nop
    /* E998C 001E998C 2DA84000 */  daddu      $21, $2, $0
    /* E9990 001E9990 2D200000 */  daddu      $4, $0, $0
    /* E9994 001E9994 00730A0C */  jal        func_0029cc00
    /* E9998 001E9998 00000000 */   nop
    /* E999C 001E999C 0001A27F */  sq         $2, 0x100($29)
    /* E99A0 001E99A0 3000B18E */  lw         $17, 0x30($21)
    /* E99A4 001E99A4 2DB80000 */  daddu      $23, $0, $0
    /* E99A8 001E99A8 FFFF1424 */  addiu      $20, $0, -0x1
    /* E99AC 001E99AC E7030224 */  addiu      $2, $0, 0x3E7
    /* E99B0 001E99B0 5001A2AF */  sw         $2, 0x150($29)
    /* E99B4 001E99B4 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* E99B8 001E99B8 00A08244 */  mtc1       $2, $f20
    /* E99BC 001E99BC 640A248E */  lw         $4, 0xA64($17)
    /* E99C0 001E99C0 4CF8080C */  jal        func_0023e130
    /* E99C4 001E99C4 00000000 */   nop
    /* E99C8 001E99C8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E99CC 001E99CC 01004224 */  addiu      $2, $2, 0x1
    /* E99D0 001E99D0 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* E99D4 001E99D4 640A248E */  lw         $4, 0xA64($17)
    /* E99D8 001E99D8 50F8080C */  jal        func_0023e140
    /* E99DC 001E99DC 00000000 */   nop
    /* E99E0 001E99E0 F000A27F */  sq         $2, 0xF0($29)
    /* E99E4 001E99E4 4001A0A7 */  sh         $0, 0x140($29)
    /* E99E8 001E99E8 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* E99EC 001E99EC E000A27F */  sq         $2, 0xE0($29)
    /* E99F0 001E99F0 13010010 */  b          .L001E9E40
    /* E99F4 001E99F4 00000000 */   nop
  .L001E99F8:
    /* E99F8 001E99F8 07006014 */  bnez       $3, .L001E9A18
    /* E99FC 001E99FC 00000000 */   nop
    /* E9A00 001E9A00 640A248E */  lw         $4, 0xA64($17)
    /* E9A04 001E9A04 F8F7080C */  jal        func_0023dfe0
    /* E9A08 001E9A08 00000000 */   nop
    /* E9A0C 001E9A0C FFFF5230 */  andi       $18, $2, 0xFFFF
    /* E9A10 001E9A10 07000010 */  b          .L001E9A30
    /* E9A14 001E9A14 00000000 */   nop
  .L001E9A18:
    /* E9A18 001E9A18 40180300 */  sll        $3, $3, 1
    /* E9A1C 001E9A1C F000A27B */  lq         $2, 0xF0($29)
    /* E9A20 001E9A20 21104300 */  addu       $2, $2, $3
    /* E9A24 001E9A24 FEFF5294 */  lhu        $18, -0x2($2)
    /* E9A28 001E9A28 02014012 */  beqz       $18, .L001E9E34
    /* E9A2C 001E9A2C 00000000 */   nop
  .L001E9A30:
    /* E9A30 001E9A30 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* E9A34 001E9A34 1001A2AF */  sw         $2, 0x110($29)
    /* E9A38 001E9A38 B8014128 */  slti       $1, $2, 0x1B8
    /* E9A3C 001E9A3C FD002010 */  beqz       $1, .L001E9E34
    /* E9A40 001E9A40 00000000 */   nop
    /* E9A44 001E9A44 640A248E */  lw         $4, 0xA64($17)
    /* E9A48 001E9A48 2D284002 */  daddu      $5, $18, $0
    /* E9A4C 001E9A4C 38F6080C */  jal        func_0023d8e0
    /* E9A50 001E9A50 00000000 */   nop
    /* E9A54 001E9A54 3C9C0200 */  dsll32     $19, $2, 16
    /* E9A58 001E9A58 3F9C1300 */  dsra32     $19, $19, 16
    /* E9A5C 001E9A5C 2D206002 */  daddu      $4, $19, $0
    /* E9A60 001E9A60 B8F5080C */  jal        func_0023d6e0
    /* E9A64 001E9A64 00000000 */   nop
    /* E9A68 001E9A68 7E004230 */  andi       $2, $2, 0x7E
    /* E9A6C 001E9A6C F1004010 */  beqz       $2, .L001E9E34
    /* E9A70 001E9A70 00000000 */   nop
    /* E9A74 001E9A74 3C141300 */  dsll32     $2, $19, 16
    /* E9A78 001E9A78 3F140200 */  dsra32     $2, $2, 16
    /* E9A7C 001E9A7C 07004014 */  bnez       $2, .L001E9A9C
    /* E9A80 001E9A80 00000000 */   nop
    /* E9A84 001E9A84 01000324 */  addiu      $3, $0, 0x1
    /* E9A88 001E9A88 0001A27B */  lq         $2, 0x100($29)
    /* E9A8C 001E9A8C 07004314 */  bne        $2, $3, .L001E9AAC
    /* E9A90 001E9A90 00000000 */   nop
    /* E9A94 001E9A94 E7000010 */  b          .L001E9E34
    /* E9A98 001E9A98 00000000 */   nop
  .L001E9A9C:
    /* E9A9C 001E9A9C 02000324 */  addiu      $3, $0, 0x2
    /* E9AA0 001E9AA0 0001A27B */  lq         $2, 0x100($29)
    /* E9AA4 001E9AA4 E3004310 */  beq        $2, $3, .L001E9E34
    /* E9AA8 001E9AA8 00000000 */   nop
  .L001E9AAC:
    /* E9AAC 001E9AAC 2D204002 */  daddu      $4, $18, $0
    /* E9AB0 001E9AB0 DCF7080C */  jal        func_0023df70
    /* E9AB4 001E9AB4 00000000 */   nop
    /* E9AB8 001E9AB8 0E004014 */  bnez       $2, .L001E9AF4
    /* E9ABC 001E9ABC 00000000 */   nop
    /* E9AC0 001E9AC0 640A248E */  lw         $4, 0xA64($17)
    /* E9AC4 001E9AC4 0800023C */  lui        $2, (0x80008 >> 16)
    /* E9AC8 001E9AC8 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* E9ACC 001E9ACC C4C9080C */  jal        func_00232710
    /* E9AD0 001E9AD0 00000000 */   nop
    /* E9AD4 001E9AD4 D7004014 */  bnez       $2, .L001E9E34
    /* E9AD8 001E9AD8 00000000 */   nop
    /* E9ADC 001E9ADC 640A248E */  lw         $4, 0xA64($17)
    /* E9AE0 001E9AE0 2D284002 */  daddu      $5, $18, $0
    /* E9AE4 001E9AE4 70F7080C */  jal        func_0023ddc0
    /* E9AE8 001E9AE8 00000000 */   nop
    /* E9AEC 001E9AEC D1004014 */  bnez       $2, .L001E9E34
    /* E9AF0 001E9AF0 00000000 */   nop
  .L001E9AF4:
    /* E9AF4 001E9AF4 2D20A002 */  daddu      $4, $21, $0
    /* E9AF8 001E9AF8 6001A527 */  addiu      $5, $29, 0x160
    /* E9AFC 001E9AFC 2D304002 */  daddu      $6, $18, $0
    /* E9B00 001E9B00 2D380000 */  daddu      $7, $0, $0
    /* E9B04 001E9B04 C45F070C */  jal        func_001d7f10
    /* E9B08 001E9B08 00000000 */   nop
    /* E9B0C 001E9B0C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E9B10 001E9B10 2DF00000 */  daddu      $30, $0, $0
    /* E9B14 001E9B14 50004014 */  bnez       $2, .L001E9C58
    /* E9B18 001E9B18 00000000 */   nop
    /* E9B1C 001E9B1C 00A88044 */  mtc1       $0, $f21
    /* E9B20 001E9B20 2D800000 */  daddu      $16, $0, $0
    /* E9B24 001E9B24 3C141300 */  dsll32     $2, $19, 16
    /* E9B28 001E9B28 3F140200 */  dsra32     $2, $2, 16
    /* E9B2C 001E9B2C 2001A2AF */  sw         $2, 0x120($29)
    /* E9B30 001E9B30 42000010 */  b          .L001E9C3C
    /* E9B34 001E9B34 00000000 */   nop
  .L001E9B38:
    /* E9B38 001E9B38 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* E9B3C 001E9B3C 80100200 */  sll        $2, $2, 2
    /* E9B40 001E9B40 21105D00 */  addu       $2, $2, $29
    /* E9B44 001E9B44 6001538C */  lw         $19, 0x160($2)
    /* E9B48 001E9B48 2D206002 */  daddu      $4, $19, $0
    /* E9B4C 001E9B4C 2001A58F */  lw         $5, 0x120($29)
    /* E9B50 001E9B50 01000624 */  addiu      $6, $0, 0x1
    /* E9B54 001E9B54 D86C070C */  jal        func_001db360
    /* E9B58 001E9B58 00000000 */   nop
    /* E9B5C 001E9B5C 35004010 */  beqz       $2, .L001E9C34
    /* E9B60 001E9B60 00000000 */   nop
    /* E9B64 001E9B64 3000628E */  lw         $2, 0x30($19)
    /* E9B68 001E9B68 2D204002 */  daddu      $4, $18, $0
    /* E9B6C 001E9B6C 640A258E */  lw         $5, 0xA64($17)
    /* E9B70 001E9B70 640A468C */  lw         $6, 0xA64($2)
    /* E9B74 001E9B74 01000724 */  addiu      $7, $0, 0x1
    /* E9B78 001E9B78 2D40E000 */  daddu      $8, $7, $0
    /* E9B7C 001E9B7C 2D48E000 */  daddu      $9, $7, $0
    /* E9B80 001E9B80 2D500000 */  daddu      $10, $0, $0
    /* E9B84 001E9B84 2D58E000 */  daddu      $11, $7, $0
    /* E9B88 001E9B88 48D5080C */  jal        func_00235520
    /* E9B8C 001E9B8C 00000000 */   nop
    /* E9B90 001E9B90 D000A27F */  sq         $2, 0xD0($29)
    /* E9B94 001E9B94 3000628E */  lw         $2, 0x30($19)
    /* E9B98 001E9B98 640A448C */  lw         $4, 0xA64($2)
    /* E9B9C 001E9B9C B4C7080C */  jal        func_00231ed0
    /* E9BA0 001E9BA0 00000000 */   nop
    /* E9BA4 001E9BA4 FFFF5630 */  andi       $22, $2, 0xFFFF
    /* E9BA8 001E9BA8 3000628E */  lw         $2, 0x30($19)
    /* E9BAC 001E9BAC 640A448C */  lw         $4, 0xA64($2)
    /* E9BB0 001E9BB0 E0C7080C */  jal        func_00231f80
    /* E9BB4 001E9BB4 00000000 */   nop
    /* E9BB8 001E9BB8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* E9BBC 001E9BBC D000A27B */  lq         $2, 0xD0($29)
    /* E9BC0 001E9BC0 23100200 */  negu       $2, $2
    /* E9BC4 001E9BC4 2A08C202 */  slt        $1, $22, $2
    /* E9BC8 001E9BC8 0E002010 */  beqz       $1, .L001E9C04
    /* E9BCC 001E9BCC 00000000 */   nop
    /* E9BD0 001E9BD0 00009644 */  mtc1       $22, $f0
    /* E9BD4 001E9BD4 00000000 */  nop
    /* E9BD8 001E9BD8 60008046 */  cvt.s.w    $f1, $f0
    /* E9BDC 001E9BDC 00008344 */  mtc1       $3, $f0
    /* E9BE0 001E9BE0 00000000 */  nop
    /* E9BE4 001E9BE4 20008046 */  cvt.s.w    $f0, $f0
    /* E9BE8 001E9BE8 43080046 */  div.s      $f1, $f1, $f0
    /* E9BEC 001E9BEC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* E9BF0 001E9BF0 00008244 */  mtc1       $2, $f0
    /* E9BF4 001E9BF4 00000000 */  nop
    /* E9BF8 001E9BF8 00080046 */  add.s      $f0, $f1, $f0
    /* E9BFC 001E9BFC 08000010 */  b          .L001E9C20
    /* E9C00 001E9C00 00000000 */   nop
  .L001E9C04:
    /* E9C04 001E9C04 00008244 */  mtc1       $2, $f0
    /* E9C08 001E9C08 00000000 */  nop
    /* E9C0C 001E9C0C 60008046 */  cvt.s.w    $f1, $f0
    /* E9C10 001E9C10 00008344 */  mtc1       $3, $f0
    /* E9C14 001E9C14 00000000 */  nop
    /* E9C18 001E9C18 20008046 */  cvt.s.w    $f0, $f0
    /* E9C1C 001E9C1C 03080046 */  div.s      $f0, $f1, $f0
  .L001E9C20:
    /* E9C20 001E9C20 34A80046 */  c.lt.s     $f21, $f0
    /* E9C24 001E9C24 03000045 */  bc1f       .L001E9C34
    /* E9C28 001E9C28 00000000 */   nop
    /* E9C2C 001E9C2C 08007E8E */  lw         $30, 0x8($19)
    /* E9C30 001E9C30 46050046 */  mov.s      $f21, $f0
  .L001E9C34:
    /* E9C34 001E9C34 01000226 */  addiu      $2, $16, 0x1
    /* E9C38 001E9C38 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001E9C3C:
    /* E9C3C 001E9C3C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* E9C40 001E9C40 9801A297 */  lhu        $2, 0x198($29)
    /* E9C44 001E9C44 2A106200 */  slt        $2, $3, $2
    /* E9C48 001E9C48 BBFF4014 */  bnez       $2, .L001E9B38
    /* E9C4C 001E9C4C 00000000 */   nop
    /* E9C50 001E9C50 59000010 */  b          .L001E9DB8
    /* E9C54 001E9C54 00000000 */   nop
  .L001E9C58:
    /* E9C58 001E9C58 00A88044 */  mtc1       $0, $f21
    /* E9C5C 001E9C5C 2DB00000 */  daddu      $22, $0, $0
    /* E9C60 001E9C60 3C141300 */  dsll32     $2, $19, 16
    /* E9C64 001E9C64 3F140200 */  dsra32     $2, $2, 16
    /* E9C68 001E9C68 3001A2AF */  sw         $2, 0x130($29)
    /* E9C6C 001E9C6C 4D000010 */  b          .L001E9DA4
    /* E9C70 001E9C70 00000000 */   nop
  .L001E9C74:
    /* E9C74 001E9C74 FFFFC232 */  andi       $2, $22, 0xFFFF
    /* E9C78 001E9C78 80100200 */  sll        $2, $2, 2
    /* E9C7C 001E9C7C 21105D00 */  addu       $2, $2, $29
    /* E9C80 001E9C80 6001508C */  lw         $16, 0x160($2)
    /* E9C84 001E9C84 2D200002 */  daddu      $4, $16, $0
    /* E9C88 001E9C88 3001A58F */  lw         $5, 0x130($29)
    /* E9C8C 001E9C8C 01000624 */  addiu      $6, $0, 0x1
    /* E9C90 001E9C90 D86C070C */  jal        func_001db360
    /* E9C94 001E9C94 00000000 */   nop
    /* E9C98 001E9C98 0D004014 */  bnez       $2, .L001E9CD0
    /* E9C9C 001E9C9C 00000000 */   nop
    /* E9CA0 001E9CA0 3000028E */  lw         $2, 0x30($16)
    /* E9CA4 001E9CA4 640A448C */  lw         $4, 0xA64($2)
    /* E9CA8 001E9CA8 2D286002 */  daddu      $5, $19, $0
    /* E9CAC 001E9CAC 000A090C */  jal        func_00242800
    /* E9CB0 001E9CB0 00000000 */   nop
    /* E9CB4 001E9CB4 0001033C */  lui        $3, (0x1000000 >> 16)
    /* E9CB8 001E9CB8 24104300 */  and        $2, $2, $3
    /* E9CBC 001E9CBC 37004014 */  bnez       $2, .L001E9D9C
    /* E9CC0 001E9CC0 00000000 */   nop
    /* E9CC4 001E9CC4 00A88044 */  mtc1       $0, $f21
    /* E9CC8 001E9CC8 3B000010 */  b          .L001E9DB8
    /* E9CCC 001E9CCC 00000000 */   nop
  .L001E9CD0:
    /* E9CD0 001E9CD0 3000028E */  lw         $2, 0x30($16)
    /* E9CD4 001E9CD4 2D204002 */  daddu      $4, $18, $0
    /* E9CD8 001E9CD8 640A258E */  lw         $5, 0xA64($17)
    /* E9CDC 001E9CDC 640A468C */  lw         $6, 0xA64($2)
    /* E9CE0 001E9CE0 01000724 */  addiu      $7, $0, 0x1
    /* E9CE4 001E9CE4 2D40E000 */  daddu      $8, $7, $0
    /* E9CE8 001E9CE8 2D48E000 */  daddu      $9, $7, $0
    /* E9CEC 001E9CEC 2D500000 */  daddu      $10, $0, $0
    /* E9CF0 001E9CF0 2D58E000 */  daddu      $11, $7, $0
    /* E9CF4 001E9CF4 48D5080C */  jal        func_00235520
    /* E9CF8 001E9CF8 00000000 */   nop
    /* E9CFC 001E9CFC C000A27F */  sq         $2, 0xC0($29)
    /* E9D00 001E9D00 3000028E */  lw         $2, 0x30($16)
    /* E9D04 001E9D04 640A448C */  lw         $4, 0xA64($2)
    /* E9D08 001E9D08 B4C7080C */  jal        func_00231ed0
    /* E9D0C 001E9D0C 00000000 */   nop
    /* E9D10 001E9D10 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E9D14 001E9D14 B000A27F */  sq         $2, 0xB0($29)
    /* E9D18 001E9D18 3000028E */  lw         $2, 0x30($16)
    /* E9D1C 001E9D1C 640A448C */  lw         $4, 0xA64($2)
    /* E9D20 001E9D20 E0C7080C */  jal        func_00231f80
    /* E9D24 001E9D24 00000000 */   nop
    /* E9D28 001E9D28 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E9D2C 001E9D2C C000A27B */  lq         $2, 0xC0($29)
    /* E9D30 001E9D30 23180200 */  negu       $3, $2
    /* E9D34 001E9D34 B000A27B */  lq         $2, 0xB0($29)
    /* E9D38 001E9D38 2A084300 */  slt        $1, $2, $3
    /* E9D3C 001E9D3C 0F002010 */  beqz       $1, .L001E9D7C
    /* E9D40 001E9D40 00000000 */   nop
    /* E9D44 001E9D44 00008244 */  mtc1       $2, $f0
    /* E9D48 001E9D48 00000000 */  nop
    /* E9D4C 001E9D4C 60008046 */  cvt.s.w    $f1, $f0
    /* E9D50 001E9D50 00008444 */  mtc1       $4, $f0
    /* E9D54 001E9D54 00000000 */  nop
    /* E9D58 001E9D58 20008046 */  cvt.s.w    $f0, $f0
    /* E9D5C 001E9D5C 03080046 */  div.s      $f0, $f1, $f0
    /* E9D60 001E9D60 40A80046 */  add.s      $f1, $f21, $f0
    /* E9D64 001E9D64 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* E9D68 001E9D68 00008244 */  mtc1       $2, $f0
    /* E9D6C 001E9D6C 00000000 */  nop
    /* E9D70 001E9D70 400D0046 */  add.s      $f21, $f1, $f0
    /* E9D74 001E9D74 09000010 */  b          .L001E9D9C
    /* E9D78 001E9D78 00000000 */   nop
  .L001E9D7C:
    /* E9D7C 001E9D7C 00008344 */  mtc1       $3, $f0
    /* E9D80 001E9D80 00000000 */  nop
    /* E9D84 001E9D84 60008046 */  cvt.s.w    $f1, $f0
    /* E9D88 001E9D88 00008444 */  mtc1       $4, $f0
    /* E9D8C 001E9D8C 00000000 */  nop
    /* E9D90 001E9D90 20008046 */  cvt.s.w    $f0, $f0
    /* E9D94 001E9D94 03080046 */  div.s      $f0, $f1, $f0
    /* E9D98 001E9D98 40AD0046 */  add.s      $f21, $f21, $f0
  .L001E9D9C:
    /* E9D9C 001E9D9C 0100C226 */  addiu      $2, $22, 0x1
    /* E9DA0 001E9DA0 FFFF5630 */  andi       $22, $2, 0xFFFF
  .L001E9DA4:
    /* E9DA4 001E9DA4 FFFFC332 */  andi       $3, $22, 0xFFFF
    /* E9DA8 001E9DA8 9801A297 */  lhu        $2, 0x198($29)
    /* E9DAC 001E9DAC 2A106200 */  slt        $2, $3, $2
    /* E9DB0 001E9DB0 B0FF4014 */  bnez       $2, .L001E9C74
    /* E9DB4 001E9DB4 00000000 */   nop
  .L001E9DB8:
    /* E9DB8 001E9DB8 36A01546 */  c.le.s     $f20, $f21
    /* E9DBC 001E9DBC 1D000045 */  bc1f       .L001E9E34
    /* E9DC0 001E9DC0 00000000 */   nop
    /* E9DC4 001E9DC4 32A01546 */  c.eq.s     $f20, $f21
    /* E9DC8 001E9DC8 17000045 */  bc1f       .L001E9E28
    /* E9DCC 001E9DCC 00000000 */   nop
    /* E9DD0 001E9DD0 640A248E */  lw         $4, 0xA64($17)
    /* E9DD4 001E9DD4 2D284002 */  daddu      $5, $18, $0
    /* E9DD8 001E9DD8 64F7080C */  jal        func_0023dd90
    /* E9DDC 001E9DDC 00000000 */   nop
    /* E9DE0 001E9DE0 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* E9DE4 001E9DE4 02000224 */  addiu      $2, $0, 0x2
    /* E9DE8 001E9DE8 12006214 */  bne        $3, $2, .L001E9E34
    /* E9DEC 001E9DEC 00000000 */   nop
    /* E9DF0 001E9DF0 640A248E */  lw         $4, 0xA64($17)
    /* E9DF4 001E9DF4 2D284002 */  daddu      $5, $18, $0
    /* E9DF8 001E9DF8 6CF6080C */  jal        func_0023d9b0
    /* E9DFC 001E9DFC 00000000 */   nop
    /* E9E00 001E9E00 5001A38F */  lw         $3, 0x150($29)
    /* E9E04 001E9E04 2A084300 */  slt        $1, $2, $3
    /* E9E08 001E9E08 0A002010 */  beqz       $1, .L001E9E34
    /* E9E0C 001E9E0C 00000000 */   nop
    /* E9E10 001E9E10 1001B48F */  lw         $20, 0x110($29)
    /* E9E14 001E9E14 2DB8C003 */  daddu      $23, $30, $0
    /* E9E18 001E9E18 06AD0046 */  mov.s      $f20, $f21
    /* E9E1C 001E9E1C 5001A2AF */  sw         $2, 0x150($29)
    /* E9E20 001E9E20 04000010 */  b          .L001E9E34
    /* E9E24 001E9E24 00000000 */   nop
  .L001E9E28:
    /* E9E28 001E9E28 1001B48F */  lw         $20, 0x110($29)
    /* E9E2C 001E9E2C 2DB8C003 */  daddu      $23, $30, $0
    /* E9E30 001E9E30 06AD0046 */  mov.s      $f20, $f21
  .L001E9E34:
    /* E9E34 001E9E34 4001A297 */  lhu        $2, 0x140($29)
    /* E9E38 001E9E38 01004224 */  addiu      $2, $2, 0x1
    /* E9E3C 001E9E3C 4001A2A7 */  sh         $2, 0x140($29)
  .L001E9E40:
    /* E9E40 001E9E40 4001A297 */  lhu        $2, 0x140($29)
    /* E9E44 001E9E44 2D184000 */  daddu      $3, $2, $0
    /* E9E48 001E9E48 E000A27B */  lq         $2, 0xE0($29)
    /* E9E4C 001E9E4C 2A106200 */  slt        $2, $3, $2
    /* E9E50 001E9E50 E9FE4014 */  bnez       $2, .L001E99F8
    /* E9E54 001E9E54 00000000 */   nop
    /* E9E58 001E9E58 FFFF0224 */  addiu      $2, $0, -0x1
    /* E9E5C 001E9E5C 1D008212 */  beq        $20, $2, .L001E9ED4
    /* E9E60 001E9E60 00000000 */   nop
    /* E9E64 001E9E64 08008016 */  bnez       $20, .L001E9E88
    /* E9E68 001E9E68 00000000 */   nop
    /* E9E6C 001E9E6C 2D20A002 */  daddu      $4, $21, $0
    /* E9E70 001E9E70 3800A526 */  addiu      $5, $21, 0x38
    /* E9E74 001E9E74 00800634 */  ori        $6, $0, 0x8000
    /* E9E78 001E9E78 9079070C */  jal        func_001de640
    /* E9E7C 001E9E7C 00000000 */   nop
    /* E9E80 001E9E80 06000010 */  b          .L001E9E9C
    /* E9E84 001E9E84 00000000 */   nop
  .L001E9E88:
    /* E9E88 001E9E88 FFFF8632 */  andi       $6, $20, 0xFFFF
    /* E9E8C 001E9E8C 2D20A002 */  daddu      $4, $21, $0
    /* E9E90 001E9E90 3800A526 */  addiu      $5, $21, 0x38
    /* E9E94 001E9E94 9079070C */  jal        func_001de640
    /* E9E98 001E9E98 00000000 */   nop
  .L001E9E9C:
    /* E9E9C 001E9E9C 0900E012 */  beqz       $23, .L001E9EC4
    /* E9EA0 001E9EA0 00000000 */   nop
    /* E9EA4 001E9EA4 2D20E002 */  daddu      $4, $23, $0
    /* E9EA8 001E9EA8 30C3060C */  jal        func_001b0cc0
    /* E9EAC 001E9EAC 00000000 */   nop
    /* E9EB0 001E9EB0 3800A2AE */  sw         $2, 0x38($21)
    /* E9EB4 001E9EB4 01000224 */  addiu      $2, $0, 0x1
    /* E9EB8 001E9EB8 6A00A2A6 */  sh         $2, 0x6A($21)
    /* E9EBC 001E9EBC 05000010 */  b          .L001E9ED4
    /* E9EC0 001E9EC0 00000000 */   nop
  .L001E9EC4:
    /* E9EC4 001E9EC4 2D20A002 */  daddu      $4, $21, $0
    /* E9EC8 001E9EC8 2D280000 */  daddu      $5, $0, $0
    /* E9ECC 001E9ECC C86F070C */  jal        func_001dbf20
    /* E9ED0 001E9ED0 00000000 */   nop
  .L001E9ED4:
    /* E9ED4 001E9ED4 2D208002 */  daddu      $4, $20, $0
    /* E9ED8 001E9ED8 D4730A0C */  jal        func_0029cf50
    /* E9EDC 001E9EDC 00000000 */   nop
    /* E9EE0 001E9EE0 01000224 */  addiu      $2, $0, 0x1
    /* E9EE4 001E9EE4 A000BFDF */  ld         $31, 0xA0($29)
    /* E9EE8 001E9EE8 9000BE7B */  lq         $30, 0x90($29)
    /* E9EEC 001E9EEC 8000B77B */  lq         $23, 0x80($29)
    /* E9EF0 001E9EF0 7000B67B */  lq         $22, 0x70($29)
    /* E9EF4 001E9EF4 6000B57B */  lq         $21, 0x60($29)
    /* E9EF8 001E9EF8 5000B47B */  lq         $20, 0x50($29)
    /* E9EFC 001E9EFC 4000B37B */  lq         $19, 0x40($29)
    /* E9F00 001E9F00 3000B27B */  lq         $18, 0x30($29)
    /* E9F04 001E9F04 2000B17B */  lq         $17, 0x20($29)
    /* E9F08 001E9F08 1000B07B */  lq         $16, 0x10($29)
    /* E9F0C 001E9F0C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* E9F10 001E9F10 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* E9F14 001E9F14 A001BD27 */  addiu      $29, $29, 0x1A0
    /* E9F18 001E9F18 0800E003 */  jr         $31
    /* E9F1C 001E9F1C 00000000 */   nop
.size func_001e9950, 0x5d0

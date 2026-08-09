.section .text
.set noat
.set noreorder
glabel func_001f3bb0
    /* F3BB0 001F3BB0 90FFBD27 */  addiu      $29, $29, -0x70
    /* F3BB4 001F3BB4 6000BFFF */  sd         $31, 0x60($29)
    /* F3BB8 001F3BB8 5000B57F */  sq         $21, 0x50($29)
    /* F3BBC 001F3BBC 4000B47F */  sq         $20, 0x40($29)
    /* F3BC0 001F3BC0 3000B37F */  sq         $19, 0x30($29)
    /* F3BC4 001F3BC4 2000B27F */  sq         $18, 0x20($29)
    /* F3BC8 001F3BC8 1000B17F */  sq         $17, 0x10($29)
    /* F3BCC 001F3BCC 0000B07F */  sq         $16, 0x0($29)
    /* F3BD0 001F3BD0 02000424 */  addiu      $4, $0, 0x2
    /* F3BD4 001F3BD4 0800053C */  lui        $5, (0x80000 >> 16)
    /* F3BD8 001F3BD8 C8BD070C */  jal        func_001ef720
    /* F3BDC 001F3BDC 00000000 */   nop
    /* F3BE0 001F3BE0 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* F3BE4 001F3BE4 0600412A */  slti       $1, $18, 0x6
    /* F3BE8 001F3BE8 04002014 */  bnez       $1, .L001F3BFC
    /* F3BEC 001F3BEC 00000000 */   nop
    /* F3BF0 001F3BF0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F3BF4 001F3BF4 CD000010 */  b          .L001F3F2C
    /* F3BF8 001F3BF8 00000000 */   nop
  .L001F3BFC:
    /* F3BFC 001F3BFC 38000424 */  addiu      $4, $0, 0x38
    /* F3C00 001F3C00 CC18040C */  jal        func_00106330
    /* F3C04 001F3C04 00000000 */   nop
    /* F3C08 001F3C08 04004010 */  beqz       $2, .L001F3C1C
    /* F3C0C 001F3C0C 00000000 */   nop
    /* F3C10 001F3C10 05000224 */  addiu      $2, $0, 0x5
    /* F3C14 001F3C14 02000010 */  b          .L001F3C20
    /* F3C18 001F3C18 00000000 */   nop
  .L001F3C1C:
    /* F3C1C 001F3C1C 08000224 */  addiu      $2, $0, 0x8
  .L001F3C20:
    /* F3C20 001F3C20 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* F3C24 001F3C24 402A040C */  jal        func_0010a900
    /* F3C28 001F3C28 00000000 */   nop
    /* F3C2C 001F3C2C 2D204000 */  daddu      $4, $2, $0
    /* F3C30 001F3C30 0D010524 */  addiu      $5, $0, 0x10D
    /* F3C34 001F3C34 8433040C */  jal        func_0010ce10
    /* F3C38 001F3C38 00000000 */   nop
    /* F3C3C 001F3C3C 27104000 */  not        $2, $2
    /* F3C40 001F3C40 2B880200 */  sltu       $17, $0, $2
    /* F3C44 001F3C44 02000424 */  addiu      $4, $0, 0x2
    /* F3C48 001F3C48 0800053C */  lui        $5, (0x80000 >> 16)
    /* F3C4C 001F3C4C 34BD070C */  jal        func_001ef4d0
    /* F3C50 001F3C50 00000000 */   nop
    /* F3C54 001F3C54 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* F3C58 001F3C58 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3C5C 001F3C5C 7001428C */  lw         $2, 0x170($2)
    /* F3C60 001F3C60 3000428C */  lw         $2, 0x30($2)
    /* F3C64 001F3C64 640A448C */  lw         $4, 0xA64($2)
    /* F3C68 001F3C68 88C7080C */  jal        func_00231e20
    /* F3C6C 001F3C6C 00000000 */   nop
    /* F3C70 001F3C70 FF004230 */  andi       $2, $2, 0xFF
    /* F3C74 001F3C74 23100202 */  subu       $2, $16, $2
    /* F3C78 001F3C78 04004228 */  slti       $2, $2, 0x4
    /* F3C7C 001F3C7C 01005538 */  xori       $21, $2, 0x1
    /* F3C80 001F3C80 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3C84 001F3C84 8001538C */  lw         $19, 0x180($2)
    /* F3C88 001F3C88 2D286002 */  daddu      $5, $19, $0
    /* F3C8C 001F3C8C C4B3848F */  lw         $4, -0x4C3C($28)
    /* F3C90 001F3C90 14000010 */  b          .L001F3CE4
    /* F3C94 001F3C94 00000000 */   nop
  .L001F3C98:
    /* F3C98 001F3C98 A400A394 */  lhu        $3, 0xA4($5)
    /* F3C9C 001F3C9C 00110300 */  sll        $2, $3, 4
    /* F3CA0 001F3CA0 23104300 */  subu       $2, $2, $3
    /* F3CA4 001F3CA4 80100200 */  sll        $2, $2, 2
    /* F3CA8 001F3CA8 21108200 */  addu       $2, $4, $2
    /* F3CAC 001F3CAC 00004394 */  lhu        $3, 0x0($2)
    /* F3CB0 001F3CB0 40006230 */  andi       $2, $3, 0x40
    /* F3CB4 001F3CB4 04004010 */  beqz       $2, .L001F3CC8
    /* F3CB8 001F3CB8 00000000 */   nop
    /* F3CBC 001F3CBC 01000224 */  addiu      $2, $0, 0x1
    /* F3CC0 001F3CC0 9A000010 */  b          .L001F3F2C
    /* F3CC4 001F3CC4 00000000 */   nop
  .L001F3CC8:
    /* F3CC8 001F3CC8 80006230 */  andi       $2, $3, 0x80
    /* F3CCC 001F3CCC 04004010 */  beqz       $2, .L001F3CE0
    /* F3CD0 001F3CD0 00000000 */   nop
    /* F3CD4 001F3CD4 2D100000 */  daddu      $2, $0, $0
    /* F3CD8 001F3CD8 94000010 */  b          .L001F3F2C
    /* F3CDC 001F3CDC 00000000 */   nop
  .L001F3CE0:
    /* F3CE0 001F3CE0 6C0AA58C */  lw         $5, 0xA6C($5)
  .L001F3CE4:
    /* F3CE4 001F3CE4 ECFFA014 */  bnez       $5, .L001F3C98
    /* F3CE8 001F3CE8 00000000 */   nop
    /* F3CEC 001F3CEC 74002012 */  beqz       $17, .L001F3EC0
    /* F3CF0 001F3CF0 00000000 */   nop
    /* F3CF4 001F3CF4 FFFF1124 */  addiu      $17, $0, -0x1
    /* F3CF8 001F3CF8 2D802002 */  daddu      $16, $17, $0
    /* F3CFC 001F3CFC 2F000010 */  b          .L001F3DBC
    /* F3D00 001F3D00 00000000 */   nop
  .L001F3D04:
    /* F3D04 001F3D04 2DA00000 */  daddu      $20, $0, $0
    /* F3D08 001F3D08 28000010 */  b          .L001F3DAC
    /* F3D0C 001F3D0C 00000000 */   nop
  .L001F3D10:
    /* F3D10 001F3D10 3C2C1400 */  dsll32     $5, $20, 16
    /* F3D14 001F3D14 3F2C0500 */  dsra32     $5, $5, 16
    /* F3D18 001F3D18 640A648E */  lw         $4, 0xA64($19)
    /* F3D1C 001F3D1C 000A090C */  jal        func_00242800
    /* F3D20 001F3D20 00000000 */   nop
    /* F3D24 001F3D24 0007033C */  lui        $3, (0x7000000 >> 16)
    /* F3D28 001F3D28 24104300 */  and        $2, $2, $3
    /* F3D2C 001F3D2C 1E004010 */  beqz       $2, .L001F3DA8
    /* F3D30 001F3D30 00000000 */   nop
    /* F3D34 001F3D34 0800812E */  sltiu      $1, $20, 0x8
    /* F3D38 001F3D38 1B002010 */  beqz       $1, .L001F3DA8
    /* F3D3C 001F3D3C 00000000 */   nop
    /* F3D40 001F3D40 7400033C */  lui        $3, %hi(jtbl_00747210)
    /* F3D44 001F3D44 10726324 */  addiu      $3, $3, %lo(jtbl_00747210)
    /* F3D48 001F3D48 80101400 */  sll        $2, $20, 2
    /* F3D4C 001F3D4C 21104300 */  addu       $2, $2, $3
    /* F3D50 001F3D50 0000428C */  lw         $2, 0x0($2)
    /* F3D54 001F3D54 08004000 */  jr         $2
    /* F3D58 001F3D58 00000000 */   nop
    /* F3D5C 001F3D5C 17001024 */  addiu      $16, $0, 0x17
    /* F3D60 001F3D60 11000010 */  b          .L001F3DA8
    /* F3D64 001F3D64 00000000 */   nop
    /* F3D68 001F3D68 18001024 */  addiu      $16, $0, 0x18
    /* F3D6C 001F3D6C 0E000010 */  b          .L001F3DA8
    /* F3D70 001F3D70 00000000 */   nop
    /* F3D74 001F3D74 19001024 */  addiu      $16, $0, 0x19
    /* F3D78 001F3D78 0B000010 */  b          .L001F3DA8
    /* F3D7C 001F3D7C 00000000 */   nop
    /* F3D80 001F3D80 1B001024 */  addiu      $16, $0, 0x1B
    /* F3D84 001F3D84 08000010 */  b          .L001F3DA8
    /* F3D88 001F3D88 00000000 */   nop
    /* F3D8C 001F3D8C 1A001024 */  addiu      $16, $0, 0x1A
    /* F3D90 001F3D90 05000010 */  b          .L001F3DA8
    /* F3D94 001F3D94 00000000 */   nop
    /* F3D98 001F3D98 1C001024 */  addiu      $16, $0, 0x1C
    /* F3D9C 001F3D9C 02000010 */  b          .L001F3DA8
    /* F3DA0 001F3DA0 00000000 */   nop
    /* F3DA4 001F3DA4 1D001024 */  addiu      $16, $0, 0x1D
  .L001F3DA8:
    /* F3DA8 001F3DA8 01009426 */  addiu      $20, $20, 0x1
  .L001F3DAC:
    /* F3DAC 001F3DAC 0800822A */  slti       $2, $20, 0x8
    /* F3DB0 001F3DB0 D7FF4014 */  bnez       $2, .L001F3D10
    /* F3DB4 001F3DB4 00000000 */   nop
    /* F3DB8 001F3DB8 6C0A738E */  lw         $19, 0xA6C($19)
  .L001F3DBC:
    /* F3DBC 001F3DBC D1FF6016 */  bnez       $19, .L001F3D04
    /* F3DC0 001F3DC0 00000000 */   nop
    /* F3DC4 001F3DC4 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3DC8 001F3DC8 8001548C */  lw         $20, 0x180($2)
    /* F3DCC 001F3DCC 2F000010 */  b          .L001F3E8C
    /* F3DD0 001F3DD0 00000000 */   nop
  .L001F3DD4:
    /* F3DD4 001F3DD4 2D980000 */  daddu      $19, $0, $0
    /* F3DD8 001F3DD8 28000010 */  b          .L001F3E7C
    /* F3DDC 001F3DDC 00000000 */   nop
  .L001F3DE0:
    /* F3DE0 001F3DE0 3C2C1300 */  dsll32     $5, $19, 16
    /* F3DE4 001F3DE4 3F2C0500 */  dsra32     $5, $5, 16
    /* F3DE8 001F3DE8 640A848E */  lw         $4, 0xA64($20)
    /* F3DEC 001F3DEC 000A090C */  jal        func_00242800
    /* F3DF0 001F3DF0 00000000 */   nop
    /* F3DF4 001F3DF4 0008033C */  lui        $3, (0x8000000 >> 16)
    /* F3DF8 001F3DF8 24104300 */  and        $2, $2, $3
    /* F3DFC 001F3DFC 1E004010 */  beqz       $2, .L001F3E78
    /* F3E00 001F3E00 00000000 */   nop
    /* F3E04 001F3E04 0800612E */  sltiu      $1, $19, 0x8
    /* F3E08 001F3E08 1B002010 */  beqz       $1, .L001F3E78
    /* F3E0C 001F3E0C 00000000 */   nop
    /* F3E10 001F3E10 7400033C */  lui        $3, %hi(jtbl_007471F0)
    /* F3E14 001F3E14 F0716324 */  addiu      $3, $3, %lo(jtbl_007471F0)
    /* F3E18 001F3E18 80101300 */  sll        $2, $19, 2
    /* F3E1C 001F3E1C 21104300 */  addu       $2, $2, $3
    /* F3E20 001F3E20 0000428C */  lw         $2, 0x0($2)
    /* F3E24 001F3E24 08004000 */  jr         $2
    /* F3E28 001F3E28 00000000 */   nop
    /* F3E2C 001F3E2C 1E001124 */  addiu      $17, $0, 0x1E
    /* F3E30 001F3E30 11000010 */  b          .L001F3E78
    /* F3E34 001F3E34 00000000 */   nop
    /* F3E38 001F3E38 1F001124 */  addiu      $17, $0, 0x1F
    /* F3E3C 001F3E3C 0E000010 */  b          .L001F3E78
    /* F3E40 001F3E40 00000000 */   nop
    /* F3E44 001F3E44 20001124 */  addiu      $17, $0, 0x20
    /* F3E48 001F3E48 0B000010 */  b          .L001F3E78
    /* F3E4C 001F3E4C 00000000 */   nop
    /* F3E50 001F3E50 22001124 */  addiu      $17, $0, 0x22
    /* F3E54 001F3E54 08000010 */  b          .L001F3E78
    /* F3E58 001F3E58 00000000 */   nop
    /* F3E5C 001F3E5C 21001124 */  addiu      $17, $0, 0x21
    /* F3E60 001F3E60 05000010 */  b          .L001F3E78
    /* F3E64 001F3E64 00000000 */   nop
    /* F3E68 001F3E68 23001124 */  addiu      $17, $0, 0x23
    /* F3E6C 001F3E6C 02000010 */  b          .L001F3E78
    /* F3E70 001F3E70 00000000 */   nop
    /* F3E74 001F3E74 24001124 */  addiu      $17, $0, 0x24
  .L001F3E78:
    /* F3E78 001F3E78 01007326 */  addiu      $19, $19, 0x1
  .L001F3E7C:
    /* F3E7C 001F3E7C 0800622A */  slti       $2, $19, 0x8
    /* F3E80 001F3E80 D7FF4014 */  bnez       $2, .L001F3DE0
    /* F3E84 001F3E84 00000000 */   nop
    /* F3E88 001F3E88 6C0A948E */  lw         $20, 0xA6C($20)
  .L001F3E8C:
    /* F3E8C 001F3E8C D1FF8016 */  bnez       $20, .L001F3DD4
    /* F3E90 001F3E90 00000000 */   nop
    /* F3E94 001F3E94 FFFF0224 */  addiu      $2, $0, -0x1
    /* F3E98 001F3E98 04000212 */  beq        $16, $2, .L001F3EAC
    /* F3E9C 001F3E9C 00000000 */   nop
    /* F3EA0 001F3EA0 2D100002 */  daddu      $2, $16, $0
    /* F3EA4 001F3EA4 21000010 */  b          .L001F3F2C
    /* F3EA8 001F3EA8 00000000 */   nop
  .L001F3EAC:
    /* F3EAC 001F3EAC 04002212 */  beq        $17, $2, .L001F3EC0
    /* F3EB0 001F3EB0 00000000 */   nop
    /* F3EB4 001F3EB4 2D102002 */  daddu      $2, $17, $0
    /* F3EB8 001F3EB8 1C000010 */  b          .L001F3F2C
    /* F3EBC 001F3EBC 00000000 */   nop
  .L001F3EC0:
    /* F3EC0 001F3EC0 0400A012 */  beqz       $21, .L001F3ED4
    /* F3EC4 001F3EC4 00000000 */   nop
    /* F3EC8 001F3EC8 02000224 */  addiu      $2, $0, 0x2
    /* F3ECC 001F3ECC 17000010 */  b          .L001F3F2C
    /* F3ED0 001F3ED0 00000000 */   nop
  .L001F3ED4:
    /* F3ED4 001F3ED4 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3ED8 001F3ED8 1A004394 */  lhu        $3, 0x1A($2)
    /* F3EDC 001F3EDC 02000224 */  addiu      $2, $0, 0x2
    /* F3EE0 001F3EE0 0E006210 */  beq        $3, $2, .L001F3F1C
    /* F3EE4 001F3EE4 00000000 */   nop
    /* F3EE8 001F3EE8 01000224 */  addiu      $2, $0, 0x1
    /* F3EEC 001F3EEC 08006210 */  beq        $3, $2, .L001F3F10
    /* F3EF0 001F3EF0 00000000 */   nop
    /* F3EF4 001F3EF4 03006010 */  beqz       $3, .L001F3F04
    /* F3EF8 001F3EF8 00000000 */   nop
    /* F3EFC 001F3EFC 0A000010 */  b          .L001F3F28
    /* F3F00 001F3F00 00000000 */   nop
  .L001F3F04:
    /* F3F04 001F3F04 02004226 */  addiu      $2, $18, 0x2
    /* F3F08 001F3F08 08000010 */  b          .L001F3F2C
    /* F3F0C 001F3F0C 00000000 */   nop
  .L001F3F10:
    /* F3F10 001F3F10 07004226 */  addiu      $2, $18, 0x7
    /* F3F14 001F3F14 05000010 */  b          .L001F3F2C
    /* F3F18 001F3F18 00000000 */   nop
  .L001F3F1C:
    /* F3F1C 001F3F1C 0C004226 */  addiu      $2, $18, 0xC
    /* F3F20 001F3F20 02000010 */  b          .L001F3F2C
    /* F3F24 001F3F24 00000000 */   nop
  .L001F3F28:
    /* F3F28 001F3F28 FFFF0224 */  addiu      $2, $0, -0x1
  .L001F3F2C:
    /* F3F2C 001F3F2C 6000BFDF */  ld         $31, 0x60($29)
    /* F3F30 001F3F30 5000B57B */  lq         $21, 0x50($29)
    /* F3F34 001F3F34 4000B47B */  lq         $20, 0x40($29)
    /* F3F38 001F3F38 3000B37B */  lq         $19, 0x30($29)
    /* F3F3C 001F3F3C 2000B27B */  lq         $18, 0x20($29)
    /* F3F40 001F3F40 1000B17B */  lq         $17, 0x10($29)
    /* F3F44 001F3F44 0000B07B */  lq         $16, 0x0($29)
    /* F3F48 001F3F48 7000BD27 */  addiu      $29, $29, 0x70
    /* F3F4C 001F3F4C 0800E003 */  jr         $31
    /* F3F50 001F3F50 00000000 */   nop
    /* F3F54 001F3F54 00000000 */  nop
    /* F3F58 001F3F58 00000000 */  nop
    /* F3F5C 001F3F5C 00000000 */  nop
.size func_001f3bb0, 0x3b0

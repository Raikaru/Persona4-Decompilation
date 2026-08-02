.section .text
.set noat
.set noreorder
glabel func_004b0ce0
    /* 3B0CE0 004B0CE0 00FFBD27 */  addiu      $29, $29, -0x100
    /* 3B0CE4 004B0CE4 6000BFFF */  sd         $31, 0x60($29)
    /* 3B0CE8 004B0CE8 5000B57F */  sq         $21, 0x50($29)
    /* 3B0CEC 004B0CEC 4000B47F */  sq         $20, 0x40($29)
    /* 3B0CF0 004B0CF0 3000B37F */  sq         $19, 0x30($29)
    /* 3B0CF4 004B0CF4 2000B27F */  sq         $18, 0x20($29)
    /* 3B0CF8 004B0CF8 1000B17F */  sq         $17, 0x10($29)
    /* 3B0CFC 004B0CFC 0000B07F */  sq         $16, 0x0($29)
    /* 3B0D00 004B0D00 2DA08000 */  daddu      $20, $4, $0
    /* 3B0D04 004B0D04 2D98A000 */  daddu      $19, $5, $0
    /* 3B0D08 004B0D08 5C00838C */  lw         $3, 0x5C($4)
    /* 3B0D0C 004B0D0C 0800708C */  lw         $16, 0x8($3)
    /* 3B0D10 004B0D10 8D000012 */  beqz       $16, .L004B0F48
    /* 3B0D14 004B0D14 00000000 */   nop
    /* 3B0D18 004B0D18 1000638C */  lw         $3, 0x10($3)
    /* 3B0D1C 004B0D1C 8A006010 */  beqz       $3, .L004B0F48
    /* 3B0D20 004B0D20 00000000 */   nop
    /* 3B0D24 004B0D24 6000828E */  lw         $2, 0x60($20)
    /* 3B0D28 004B0D28 06004014 */  bnez       $2, .L004B0D44
    /* 3B0D2C 004B0D2C 00000000 */   nop
    /* 3B0D30 004B0D30 7100043C */  lui        $4, %hi(D_00714550)
    /* 3B0D34 004B0D34 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3B0D38 004B0D38 65020524 */  addiu      $5, $0, 0x265
    /* 3B0D3C 004B0D3C CCB5110C */  jal        func_0046d730
    /* 3B0D40 004B0D40 00000000 */   nop
  .L004B0D44:
    /* 3B0D44 004B0D44 5C00828E */  lw         $2, 0x5C($20)
    /* 3B0D48 004B0D48 1800528C */  lw         $18, 0x18($2)
    /* 3B0D4C 004B0D4C 6400918E */  lw         $17, 0x64($20)
    /* 3B0D50 004B0D50 15000424 */  addiu      $4, $0, 0x15
    /* 3B0D54 004B0D54 C004120C */  jal        func_00481300
    /* 3B0D58 004B0D58 00000000 */   nop
    /* 3B0D5C 004B0D5C 0000558C */  lw         $21, 0x0($2)
    /* 3B0D60 004B0D60 FF006232 */  andi       $2, $19, 0xFF
    /* 3B0D64 004B0D64 01000424 */  addiu      $4, $0, 0x1
    /* 3B0D68 004B0D68 06004414 */  bne        $2, $4, .L004B0D84
    /* 3B0D6C 004B0D6C 00000000 */   nop
    /* 3B0D70 004B0D70 2D28A002 */  daddu      $5, $21, $0
    /* 3B0D74 004B0D74 8800023C */  lui        $2, %hi(D_00887300)
    /* 3B0D78 004B0D78 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 3B0D7C 004B0D7C 09F84000 */  jalr       $2
    /* 3B0D80 004B0D80 00000000 */   nop
  .L004B0D84:
    /* 3B0D84 004B0D84 0C00A0C6 */  lwc1       $f0, 0xC($21)
    /* 3B0D88 004B0D88 20008046 */  cvt.s.w    $f0, $f0
    /* 3B0D8C 004B0D8C F000A0E7 */  swc1       $f0, 0xF0($29)
    /* 3B0D90 004B0D90 1000A0C6 */  lwc1       $f0, 0x10($21)
    /* 3B0D94 004B0D94 20008046 */  cvt.s.w    $f0, $f0
    /* 3B0D98 004B0D98 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* 3B0D9C 004B0D9C 0400828E */  lw         $2, 0x4($20)
    /* 3B0DA0 004B0DA0 FC00A2AF */  sw         $2, 0xFC($29)
    /* 3B0DA4 004B0DA4 FC00A227 */  addiu      $2, $29, 0xFC
    /* 3B0DA8 004B0DA8 F481838F */  lw         $3, -0x7E0C($28)
    /* 3B0DAC 004B0DAC 0000428C */  lw         $2, 0x0($2)
    /* 3B0DB0 004B0DB0 88160270 */  pextlb     $2, $0, $2
    /* 3B0DB4 004B0DB4 88150270 */  pextlh     $2, $0, $2
    /* 3B0DB8 004B0DB8 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3B0DBC 004B0DBC 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3B0DC0 004B0DC0 00000000 */  nop
    /* 3B0DC4 004B0DC4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3B0DC8 004B0DC8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3B0DCC 004B0DCC E000A227 */  addiu      $2, $29, 0xE0
    /* 3B0DD0 004B0DD0 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3B0DD4 004B0DD4 5C00848E */  lw         $4, 0x5C($20)
    /* 3B0DD8 004B0DD8 0C00828C */  lw         $2, 0xC($4)
    /* 3B0DDC 004B0DDC 01004230 */  andi       $2, $2, 0x1
    /* 3B0DE0 004B0DE0 1C004014 */  bnez       $2, .L004B0E54
    /* 3B0DE4 004B0DE4 00000000 */   nop
    /* 3B0DE8 004B0DE8 2DA80000 */  daddu      $21, $0, $0
    /* 3B0DEC 004B0DEC 14000010 */  b          .L004B0E40
    /* 3B0DF0 004B0DF0 00000000 */   nop
  .L004B0DF4:
    /* 3B0DF4 004B0DF4 1000428E */  lw         $2, 0x10($18)
    /* 3B0DF8 004B0DF8 0E004004 */  bltz       $2, .L004B0E34
    /* 3B0DFC 004B0DFC 00000000 */   nop
    /* 3B0E00 004B0E00 2D200000 */  daddu      $4, $0, $0
    /* 3B0E04 004B0E04 14F4120C */  jal        func_004bd050
    /* 3B0E08 004B0E08 00000000 */   nop
    /* 3B0E0C 004B0E0C 03004B30 */  andi       $11, $2, 0x3
    /* 3B0E10 004B0E10 2D208002 */  daddu      $4, $20, $0
    /* 3B0E14 004B0E14 2D282002 */  daddu      $5, $17, $0
    /* 3B0E18 004B0E18 2D304002 */  daddu      $6, $18, $0
    /* 3B0E1C 004B0E1C 2D384002 */  daddu      $7, $18, $0
    /* 3B0E20 004B0E20 E000A827 */  addiu      $8, $29, 0xE0
    /* 3B0E24 004B0E24 F000A927 */  addiu      $9, $29, 0xF0
    /* 3B0E28 004B0E28 2D506002 */  daddu      $10, $19, $0
    /* 3B0E2C 004B0E2C 88BF120C */  jal        func_004afe20
    /* 3B0E30 004B0E30 00000000 */   nop
  .L004B0E34:
    /* 3B0E34 004B0E34 0100B526 */  addiu      $21, $21, 0x1
    /* 3B0E38 004B0E38 20005226 */  addiu      $18, $18, 0x20
    /* 3B0E3C 004B0E3C 1C003126 */  addiu      $17, $17, 0x1C
  .L004B0E40:
    /* 3B0E40 004B0E40 2A10B002 */  slt        $2, $21, $16
    /* 3B0E44 004B0E44 EBFF4014 */  bnez       $2, .L004B0DF4
    /* 3B0E48 004B0E48 00000000 */   nop
    /* 3B0E4C 004B0E4C 38000010 */  b          .L004B0F30
    /* 3B0E50 004B0E50 00000000 */   nop
  .L004B0E54:
    /* 3B0E54 004B0E54 B000A527 */  addiu      $5, $29, 0xB0
    /* 3B0E58 004B0E58 7C4B120C */  jal        func_00492df0
    /* 3B0E5C 004B0E5C 00000000 */   nop
    /* 3B0E60 004B0E60 5C00848E */  lw         $4, 0x5C($20)
    /* 3B0E64 004B0E64 C000A527 */  addiu      $5, $29, 0xC0
    /* 3B0E68 004B0E68 6C4B120C */  jal        func_00492db0
    /* 3B0E6C 004B0E6C 00000000 */   nop
    /* 3B0E70 004B0E70 B000A227 */  addiu      $2, $29, 0xB0
    /* 3B0E74 004B0E74 00004AD8 */  lqc2       $vf10, 0x0($2)
    /* 3B0E78 004B0E78 ACF3120C */  jal        func_004bceb0
    /* 3B0E7C 004B0E7C 00000000 */   nop
    /* 3B0E80 004B0E80 C000A227 */  addiu      $2, $29, 0xC0
    /* 3B0E84 004B0E84 00005FD8 */  lqc2       $vf31, 0x0($2)
    /* 3B0E88 004B0E88 7000A227 */  addiu      $2, $29, 0x70
    /* 3B0E8C 004B0E8C 00005CF8 */  sqc2       $vf28, 0x0($2)
    /* 3B0E90 004B0E90 10005DF8 */  sqc2       $vf29, 0x10($2)
    /* 3B0E94 004B0E94 20005EF8 */  sqc2       $vf30, 0x20($2)
    /* 3B0E98 004B0E98 30005FF8 */  sqc2       $vf31, 0x30($2)
    /* 3B0E9C 004B0E9C 2DA80000 */  daddu      $21, $0, $0
    /* 3B0EA0 004B0EA0 20000010 */  b          .L004B0F24
    /* 3B0EA4 004B0EA4 00000000 */   nop
  .L004B0EA8:
    /* 3B0EA8 004B0EA8 1000428E */  lw         $2, 0x10($18)
    /* 3B0EAC 004B0EAC 1A004004 */  bltz       $2, .L004B0F18
    /* 3B0EB0 004B0EB0 00000000 */   nop
    /* 3B0EB4 004B0EB4 7000A227 */  addiu      $2, $29, 0x70
    /* 3B0EB8 004B0EB8 00005CD8 */  lqc2       $vf28, 0x0($2)
    /* 3B0EBC 004B0EBC 10005DD8 */  lqc2       $vf29, 0x10($2)
    /* 3B0EC0 004B0EC0 20005ED8 */  lqc2       $vf30, 0x20($2)
    /* 3B0EC4 004B0EC4 30005FD8 */  lqc2       $vf31, 0x30($2)
    /* 3B0EC8 004B0EC8 00004ADA */  lqc2       $vf10, 0x0($18)
    /* 3B0ECC 004B0ECC BCE1EA4B */  vmulax.xyzw $ACC, $vf28, $vf10x
    /* 3B0ED0 004B0ED0 BDE8EA4B */  vmadday.xyzw $ACC, $vf29, $vf10y
    /* 3B0ED4 004B0ED4 BEF0EA4B */  vmaddaz.xyzw $ACC, $vf30, $vf10z
    /* 3B0ED8 004B0ED8 8BFAE04B */  vmaddw.xyzw $vf10, $vf31, $vf0w
    /* 3B0EDC 004B0EDC D000A227 */  addiu      $2, $29, 0xD0
    /* 3B0EE0 004B0EE0 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3B0EE4 004B0EE4 2D200000 */  daddu      $4, $0, $0
    /* 3B0EE8 004B0EE8 14F4120C */  jal        func_004bd050
    /* 3B0EEC 004B0EEC 00000000 */   nop
    /* 3B0EF0 004B0EF0 03004B30 */  andi       $11, $2, 0x3
    /* 3B0EF4 004B0EF4 2D208002 */  daddu      $4, $20, $0
    /* 3B0EF8 004B0EF8 2D282002 */  daddu      $5, $17, $0
    /* 3B0EFC 004B0EFC 2D304002 */  daddu      $6, $18, $0
    /* 3B0F00 004B0F00 D000A727 */  addiu      $7, $29, 0xD0
    /* 3B0F04 004B0F04 E000A827 */  addiu      $8, $29, 0xE0
    /* 3B0F08 004B0F08 F000A927 */  addiu      $9, $29, 0xF0
    /* 3B0F0C 004B0F0C 2D506002 */  daddu      $10, $19, $0
    /* 3B0F10 004B0F10 88BF120C */  jal        func_004afe20
    /* 3B0F14 004B0F14 00000000 */   nop
  .L004B0F18:
    /* 3B0F18 004B0F18 0100B526 */  addiu      $21, $21, 0x1
    /* 3B0F1C 004B0F1C 20005226 */  addiu      $18, $18, 0x20
    /* 3B0F20 004B0F20 1C003126 */  addiu      $17, $17, 0x1C
  .L004B0F24:
    /* 3B0F24 004B0F24 2A10B002 */  slt        $2, $21, $16
    /* 3B0F28 004B0F28 DFFF4014 */  bnez       $2, .L004B0EA8
    /* 3B0F2C 004B0F2C 00000000 */   nop
  .L004B0F30:
    /* 3B0F30 004B0F30 01000424 */  addiu      $4, $0, 0x1
    /* 3B0F34 004B0F34 2D280000 */  daddu      $5, $0, $0
    /* 3B0F38 004B0F38 8800023C */  lui        $2, %hi(D_00887300)
    /* 3B0F3C 004B0F3C 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 3B0F40 004B0F40 09F84000 */  jalr       $2
    /* 3B0F44 004B0F44 00000000 */   nop
  .L004B0F48:
    /* 3B0F48 004B0F48 6000BFDF */  ld         $31, 0x60($29)
    /* 3B0F4C 004B0F4C 5000B57B */  lq         $21, 0x50($29)
    /* 3B0F50 004B0F50 4000B47B */  lq         $20, 0x40($29)
    /* 3B0F54 004B0F54 3000B37B */  lq         $19, 0x30($29)
    /* 3B0F58 004B0F58 2000B27B */  lq         $18, 0x20($29)
    /* 3B0F5C 004B0F5C 1000B17B */  lq         $17, 0x10($29)
    /* 3B0F60 004B0F60 0000B07B */  lq         $16, 0x0($29)
    /* 3B0F64 004B0F64 0001BD27 */  addiu      $29, $29, 0x100
    /* 3B0F68 004B0F68 0800E003 */  jr         $31
    /* 3B0F6C 004B0F6C 00000000 */   nop
.size func_004b0ce0, 0x290

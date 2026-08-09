.section .text
.set noat
.set noreorder
glabel func_001d4cf0
    /* D4CF0 001D4CF0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D4CF4 001D4CF4 2000BFFF */  sd         $31, 0x20($29)
    /* D4CF8 001D4CF8 1000B17F */  sq         $17, 0x10($29)
    /* D4CFC 001D4CFC 0000B07F */  sq         $16, 0x0($29)
    /* D4D00 001D4D00 2D80E000 */  daddu      $16, $7, $0
    /* D4D04 001D4D04 A200A290 */  lbu        $2, 0xA2($5)
    /* D4D08 001D4D08 04004014 */  bnez       $2, .L001D4D1C
    /* D4D0C 001D4D0C 00000000 */   nop
    /* D4D10 001D4D10 01000224 */  addiu      $2, $0, 0x1
    /* D4D14 001D4D14 02000010 */  b          .L001D4D20
    /* D4D18 001D4D18 00000000 */   nop
  .L001D4D1C:
    /* D4D1C 001D4D1C 02000224 */  addiu      $2, $0, 0x2
  .L001D4D20:
    /* D4D20 001D4D20 0800D124 */  addiu      $17, $6, 0x8
    /* D4D24 001D4D24 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* D4D28 001D4D28 2D280000 */  daddu      $5, $0, $0
    /* D4D2C 001D4D2C 4000A627 */  addiu      $6, $29, 0x40
    /* D4D30 001D4D30 4C00A727 */  addiu      $7, $29, 0x4C
    /* D4D34 001D4D34 2D400000 */  daddu      $8, $0, $0
    /* D4D38 001D4D38 2D480000 */  daddu      $9, $0, $0
    /* D4D3C 001D4D3C 1058060C */  jal        func_00196040
    /* D4D40 001D4D40 00000000 */   nop
    /* D4D44 001D4D44 04002296 */  lhu        $2, 0x4($17)
    /* D4D48 001D4D48 03004014 */  bnez       $2, .L001D4D58
    /* D4D4C 001D4D4C 00000000 */   nop
    /* D4D50 001D4D50 04000010 */  b          .L001D4D64
    /* D4D54 001D4D54 00000000 */   nop
  .L001D4D58:
    /* D4D58 001D4D58 00008244 */  mtc1       $2, $f0
    /* D4D5C 001D4D5C 00000000 */  nop
    /* D4D60 001D4D60 20008046 */  cvt.s.w    $f0, $f0
  .L001D4D64:
    /* D4D64 001D4D64 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* D4D68 001D4D68 3C00A2AF */  sw         $2, 0x3C($29)
    /* D4D6C 001D4D6C 3000A0AF */  sw         $0, 0x30($29)
    /* D4D70 001D4D70 3400A0AF */  sw         $0, 0x34($29)
    /* D4D74 001D4D74 3800A0AF */  sw         $0, 0x38($29)
    /* D4D78 001D4D78 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* D4D7C 001D4D7C 00108244 */  mtc1       $2, $f2
    /* D4D80 001D4D80 4C00A1C7 */  lwc1       $f1, 0x4C($29)
    /* D4D84 001D4D84 42130146 */  mul.s      $f13, $f2, $f1
    /* D4D88 001D4D88 06030046 */  mov.s      $f12, $f0
    /* D4D8C 001D4D8C 4000A427 */  addiu      $4, $29, 0x40
    /* D4D90 001D4D90 3000A527 */  addiu      $5, $29, 0x30
    /* D4D94 001D4D94 2D302002 */  daddu      $6, $17, $0
    /* D4D98 001D4D98 2D380002 */  daddu      $7, $16, $0
    /* D4D9C 001D4D9C 2851070C */  jal        func_001d44a0
    /* D4DA0 001D4DA0 00000000 */   nop
    /* D4DA4 001D4DA4 2000BFDF */  ld         $31, 0x20($29)
    /* D4DA8 001D4DA8 1000B17B */  lq         $17, 0x10($29)
    /* D4DAC 001D4DAC 0000B07B */  lq         $16, 0x0($29)
    /* D4DB0 001D4DB0 5000BD27 */  addiu      $29, $29, 0x50
    /* D4DB4 001D4DB4 0800E003 */  jr         $31
    /* D4DB8 001D4DB8 00000000 */   nop
    /* D4DBC 001D4DBC 00000000 */  nop
.size func_001d4cf0, 0xd0

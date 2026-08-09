.section .text
.set noat
.set noreorder
glabel func_001d4dc0
    /* D4DC0 001D4DC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D4DC4 001D4DC4 2000BFFF */  sd         $31, 0x20($29)
    /* D4DC8 001D4DC8 1000B17F */  sq         $17, 0x10($29)
    /* D4DCC 001D4DCC 0000B07F */  sq         $16, 0x0($29)
    /* D4DD0 001D4DD0 2D80E000 */  daddu      $16, $7, $0
    /* D4DD4 001D4DD4 A200A290 */  lbu        $2, 0xA2($5)
    /* D4DD8 001D4DD8 04004014 */  bnez       $2, .L001D4DEC
    /* D4DDC 001D4DDC 00000000 */   nop
    /* D4DE0 001D4DE0 02000224 */  addiu      $2, $0, 0x2
    /* D4DE4 001D4DE4 02000010 */  b          .L001D4DF0
    /* D4DE8 001D4DE8 00000000 */   nop
  .L001D4DEC:
    /* D4DEC 001D4DEC 01000224 */  addiu      $2, $0, 0x1
  .L001D4DF0:
    /* D4DF0 001D4DF0 0800D124 */  addiu      $17, $6, 0x8
    /* D4DF4 001D4DF4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* D4DF8 001D4DF8 2D280000 */  daddu      $5, $0, $0
    /* D4DFC 001D4DFC 4000A627 */  addiu      $6, $29, 0x40
    /* D4E00 001D4E00 4C00A727 */  addiu      $7, $29, 0x4C
    /* D4E04 001D4E04 2D400000 */  daddu      $8, $0, $0
    /* D4E08 001D4E08 2D480000 */  daddu      $9, $0, $0
    /* D4E0C 001D4E0C 1058060C */  jal        func_00196040
    /* D4E10 001D4E10 00000000 */   nop
    /* D4E14 001D4E14 04002296 */  lhu        $2, 0x4($17)
    /* D4E18 001D4E18 03004014 */  bnez       $2, .L001D4E28
    /* D4E1C 001D4E1C 00000000 */   nop
    /* D4E20 001D4E20 04000010 */  b          .L001D4E34
    /* D4E24 001D4E24 00000000 */   nop
  .L001D4E28:
    /* D4E28 001D4E28 00008244 */  mtc1       $2, $f0
    /* D4E2C 001D4E2C 00000000 */  nop
    /* D4E30 001D4E30 20008046 */  cvt.s.w    $f0, $f0
  .L001D4E34:
    /* D4E34 001D4E34 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* D4E38 001D4E38 3C00A2AF */  sw         $2, 0x3C($29)
    /* D4E3C 001D4E3C 3000A0AF */  sw         $0, 0x30($29)
    /* D4E40 001D4E40 3400A0AF */  sw         $0, 0x34($29)
    /* D4E44 001D4E44 3800A0AF */  sw         $0, 0x38($29)
    /* D4E48 001D4E48 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* D4E4C 001D4E4C 00108244 */  mtc1       $2, $f2
    /* D4E50 001D4E50 4C00A1C7 */  lwc1       $f1, 0x4C($29)
    /* D4E54 001D4E54 42130146 */  mul.s      $f13, $f2, $f1
    /* D4E58 001D4E58 06030046 */  mov.s      $f12, $f0
    /* D4E5C 001D4E5C 4000A427 */  addiu      $4, $29, 0x40
    /* D4E60 001D4E60 3000A527 */  addiu      $5, $29, 0x30
    /* D4E64 001D4E64 2D302002 */  daddu      $6, $17, $0
    /* D4E68 001D4E68 2D380002 */  daddu      $7, $16, $0
    /* D4E6C 001D4E6C 2851070C */  jal        func_001d44a0
    /* D4E70 001D4E70 00000000 */   nop
    /* D4E74 001D4E74 2000BFDF */  ld         $31, 0x20($29)
    /* D4E78 001D4E78 1000B17B */  lq         $17, 0x10($29)
    /* D4E7C 001D4E7C 0000B07B */  lq         $16, 0x0($29)
    /* D4E80 001D4E80 5000BD27 */  addiu      $29, $29, 0x50
    /* D4E84 001D4E84 0800E003 */  jr         $31
    /* D4E88 001D4E88 00000000 */   nop
    /* D4E8C 001D4E8C 00000000 */  nop
.size func_001d4dc0, 0xd0

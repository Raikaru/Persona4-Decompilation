.section .text
.set noat
.set noreorder
glabel func_003e0e20
    /* 2E0E20 003E0E20 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 2E0E24 003E0E24 02000224 */  addiu      $2, $0, 0x2
    /* 2E0E28 003E0E28 1000BFFF */  sd         $31, 0x10($29)
    /* 2E0E2C 003E0E2C 0000B07F */  sq         $16, 0x0($29)
    /* 2E0E30 003E0E30 2400C210 */  beq        $6, $2, .L003E0EC4
    /* 2E0E34 003E0E34 2D808000 */   daddu     $16, $4, $0
    /* 2E0E38 003E0E38 01000224 */  addiu      $2, $0, 0x1
    /* 2E0E3C 003E0E3C 1100C210 */  beq        $6, $2, .L003E0E84
    /* 2E0E40 003E0E40 00000000 */   nop
    /* 2E0E44 003E0E44 0300C010 */  beqz       $6, .L003E0E54
    /* 2E0E48 003E0E48 00000000 */   nop
    /* 2E0E4C 003E0E4C 2E000010 */  b          .L003E0F08
    /* 2E0E50 003E0E50 A800A2AF */   sw        $2, 0xA8($29)
  .L003E0E54:
    /* 2E0E54 003E0E54 08000424 */  addiu      $4, $0, 0x8
    /* 2E0E58 003E0E58 2D300002 */  daddu      $6, $16, $0
  .L003E0E5C:
    /* 2E0E5C 003E0E5C 0000A38C */  lw         $3, 0x0($5)
    /* 2E0E60 003E0E60 FFFF8424 */  addiu      $4, $4, -0x1
    /* 2E0E64 003E0E64 0400A28C */  lw         $2, 0x4($5)
    /* 2E0E68 003E0E68 0000C3AC */  sw         $3, 0x0($6)
    /* 2E0E6C 003E0E6C 0400C2AC */  sw         $2, 0x4($6)
    /* 2E0E70 003E0E70 0800A524 */  addiu      $5, $5, 0x8
    /* 2E0E74 003E0E74 F9FF801C */  bgtz       $4, .L003E0E5C
    /* 2E0E78 003E0E78 0800C624 */   addiu     $6, $6, 0x8
    /* 2E0E7C 003E0E7C 2C000010 */  b          .L003E0F30
    /* 2E0E80 003E0E80 2D100002 */   daddu     $2, $16, $0
  .L003E0E84:
    /* 2E0E84 003E0E84 6000A427 */  addiu      $4, $29, 0x60
    /* 2E0E88 003E0E88 7C810F0C */  jal        func_003e05f0
    /* 2E0E8C 003E0E8C 2D300002 */   daddu     $6, $16, $0
    /* 2E0E90 003E0E90 6000A627 */  addiu      $6, $29, 0x60
    /* 2E0E94 003E0E94 08000424 */  addiu      $4, $0, 0x8
    /* 2E0E98 003E0E98 2D280002 */  daddu      $5, $16, $0
  .L003E0E9C:
    /* 2E0E9C 003E0E9C 0000C38C */  lw         $3, 0x0($6)
    /* 2E0EA0 003E0EA0 FFFF8424 */  addiu      $4, $4, -0x1
    /* 2E0EA4 003E0EA4 0400C28C */  lw         $2, 0x4($6)
    /* 2E0EA8 003E0EA8 0000A3AC */  sw         $3, 0x0($5)
    /* 2E0EAC 003E0EAC 0800C624 */  addiu      $6, $6, 0x8
    /* 2E0EB0 003E0EB0 0400A2AC */  sw         $2, 0x4($5)
    /* 2E0EB4 003E0EB4 F9FF801C */  bgtz       $4, .L003E0E9C
    /* 2E0EB8 003E0EB8 0800A524 */   addiu     $5, $5, 0x8
    /* 2E0EBC 003E0EBC 1B000010 */  b          .L003E0F2C
    /* 2E0EC0 003E0EC0 00000000 */   nop
  .L003E0EC4:
    /* 2E0EC4 003E0EC4 2D30A000 */  daddu      $6, $5, $0
    /* 2E0EC8 003E0EC8 2000A427 */  addiu      $4, $29, 0x20
    /* 2E0ECC 003E0ECC 7C810F0C */  jal        func_003e05f0
    /* 2E0ED0 003E0ED0 2D280002 */   daddu     $5, $16, $0
    /* 2E0ED4 003E0ED4 2000A627 */  addiu      $6, $29, 0x20
    /* 2E0ED8 003E0ED8 08000424 */  addiu      $4, $0, 0x8
    /* 2E0EDC 003E0EDC 2D280002 */  daddu      $5, $16, $0
  .L003E0EE0:
    /* 2E0EE0 003E0EE0 0000C38C */  lw         $3, 0x0($6)
    /* 2E0EE4 003E0EE4 FFFF8424 */  addiu      $4, $4, -0x1
    /* 2E0EE8 003E0EE8 0400C28C */  lw         $2, 0x4($6)
    /* 2E0EEC 003E0EEC 0000A3AC */  sw         $3, 0x0($5)
    /* 2E0EF0 003E0EF0 0800C624 */  addiu      $6, $6, 0x8
    /* 2E0EF4 003E0EF4 0400A2AC */  sw         $2, 0x4($5)
    /* 2E0EF8 003E0EF8 F9FF801C */  bgtz       $4, .L003E0EE0
    /* 2E0EFC 003E0EFC 0800A524 */   addiu     $5, $5, 0x8
    /* 2E0F00 003E0F00 0A000010 */  b          .L003E0F2C
    /* 2E0F04 003E0F04 00000000 */   nop
  .L003E0F08:
    /* 2E0F08 003E0F08 7100053C */  lui        $5, %hi(D_0070B6F0)
    /* 2E0F0C 003E0F0C 0080023C */  lui        $2, (0x80000003 >> 16)
    /* 2E0F10 003E0F10 F0B6A524 */  addiu      $5, $5, %lo(D_0070B6F0)
    /* 2E0F14 003E0F14 647D0F0C */  jal        func_003df590
    /* 2E0F18 003E0F18 03004434 */   ori       $4, $2, (0x80000003 & 0xFFFF)
    /* 2E0F1C 003E0F1C AC00A2AF */  sw         $2, 0xAC($29)
    /* 2E0F20 003E0F20 347D0F0C */  jal        func_003df4d0
    /* 2E0F24 003E0F24 A800A427 */   addiu     $4, $29, 0xA8
    /* 2E0F28 003E0F28 2D800000 */  daddu      $16, $0, $0
  .L003E0F2C:
    /* 2E0F2C 003E0F2C 2D100002 */  daddu      $2, $16, $0
  .L003E0F30:
    /* 2E0F30 003E0F30 1000BFDF */  ld         $31, 0x10($29)
    /* 2E0F34 003E0F34 0000B07B */  lq         $16, 0x0($29)
    /* 2E0F38 003E0F38 0800E003 */  jr         $31
    /* 2E0F3C 003E0F3C B000BD27 */   addiu     $29, $29, 0xB0
.size func_003e0e20, 0x120

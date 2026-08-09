.section .text
.set noat
.set noreorder
glabel func_004e4dd0
    /* 3E4DD0 004E4DD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E4DD4 004E4DD4 7300023C */  lui        $2, %hi(D_00731C88)
    /* 3E4DD8 004E4DD8 1800BFFF */  sd         $31, 0x18($29)
    /* 3E4DDC 004E4DDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E4DE0 004E4DE0 881C5024 */  addiu      $16, $2, %lo(D_00731C88)
    /* 3E4DE4 004E4DE4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E4DE8 004E4DE8 2D880000 */  daddu      $17, $0, $0
    /* 3E4DEC 004E4DEC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E4DF0 004E4DF0 01001224 */  addiu      $18, $0, 0x1
    /* 3E4DF4 004E4DF4 00000000 */  nop
  .L004E4DF8:
    /* 3E4DF8 004E4DF8 01000382 */  lb         $3, 0x1($16)
    /* 3E4DFC 004E4DFC 09007254 */  bnel       $3, $18, .L004E4E24
    /* 3E4E00 004E4E00 01003126 */   addiu     $17, $17, 0x1
    /* 3E4E04 004E4E04 02000282 */  lb         $2, 0x2($16)
    /* 3E4E08 004E4E08 06004354 */  bnel       $2, $3, .L004E4E24
    /* 3E4E0C 004E4E0C 01003126 */   addiu     $17, $17, 0x1
    /* 3E4E10 004E4E10 E086100C */  jal        func_00421b80
    /* 3E4E14 004E4E14 2C00048E */   lw        $4, 0x2C($16)
    /* 3E4E18 004E4E18 17004304 */  bgezl      $2, .L004E4E78
    /* 3E4E1C 004E4E1C 0000B0DF */   ld        $16, 0x0($29)
    /* 3E4E20 004E4E20 01003126 */  addiu      $17, $17, 0x1
  .L004E4E24:
    /* 3E4E24 004E4E24 2000222A */  slti       $2, $17, 0x20
    /* 3E4E28 004E4E28 F3FF4014 */  bnez       $2, .L004E4DF8
    /* 3E4E2C 004E4E2C 40001026 */   addiu     $16, $16, 0x40
    /* 3E4E30 004E4E30 7300023C */  lui        $2, %hi(D_00731C88)
    /* 3E4E34 004E4E34 01001224 */  addiu      $18, $0, 0x1
    /* 3E4E38 004E4E38 881C5024 */  addiu      $16, $2, %lo(D_00731C88)
    /* 3E4E3C 004E4E3C 1F001124 */  addiu      $17, $0, 0x1F
  .L004E4E40:
    /* 3E4E40 004E4E40 00000282 */  lb         $2, 0x0($16)
    /* 3E4E44 004E4E44 04005254 */  bnel       $2, $18, .L004E4E58
    /* 3E4E48 004E4E48 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3E4E4C 004E4E4C 9892130C */  jal        func_004e4a60
    /* 3E4E50 004E4E50 2D200002 */   daddu     $4, $16, $0
    /* 3E4E54 004E4E54 FFFF3126 */  addiu      $17, $17, -0x1
  .L004E4E58:
    /* 3E4E58 004E4E58 F9FF2106 */  bgez       $17, .L004E4E40
    /* 3E4E5C 004E4E5C 40001026 */   addiu     $16, $16, 0x40
    /* 3E4E60 004E4E60 0000B0DF */  ld         $16, 0x0($29)
    /* 3E4E64 004E4E64 0800B1DF */  ld         $17, 0x8($29)
    /* 3E4E68 004E4E68 1000B2DF */  ld         $18, 0x10($29)
    /* 3E4E6C 004E4E6C 1800BFDF */  ld         $31, 0x18($29)
    /* 3E4E70 004E4E70 6A961308 */  j          func_004e59a8
    /* 3E4E74 004E4E74 2000BD27 */   addiu     $29, $29, 0x20
  .L004E4E78:
    /* 3E4E78 004E4E78 0800B1DF */  ld         $17, 0x8($29)
    /* 3E4E7C 004E4E7C 1000B2DF */  ld         $18, 0x10($29)
    /* 3E4E80 004E4E80 1800BFDF */  ld         $31, 0x18($29)
    /* 3E4E84 004E4E84 0800E003 */  jr         $31
    /* 3E4E88 004E4E88 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E4E8C 004E4E8C 00000000 */  nop
.size func_004e4dd0, 0xc0

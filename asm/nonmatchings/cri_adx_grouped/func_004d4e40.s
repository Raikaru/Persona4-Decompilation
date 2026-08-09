.section .text
.set noat
.set noreorder
glabel func_004d4e40
    /* 3D4E40 004D4E40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D4E44 004D4E44 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4E48 004D4E48 2D808000 */  daddu      $16, $4, $0
    /* 3D4E4C 004D4E4C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D4E50 004D4E50 2D90A000 */  daddu      $18, $5, $0
    /* 3D4E54 004D4E54 1800B3FF */  sd         $19, 0x18($29)
    /* 3D4E58 004D4E58 2D98C000 */  daddu      $19, $6, $0
    /* 3D4E5C 004D4E5C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D4E60 004D4E60 0B000016 */  bnez       $16, .L004D4E90
    /* 3D4E64 004D4E64 2000BFFF */   sd        $31, 0x20($29)
    /* 3D4E68 004D4E68 7600043C */  lui        $4, %hi(D_00758D98)
    /* 3D4E6C 004D4E6C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4E70 004D4E70 0800B1DF */  ld         $17, 0x8($29)
    /* 3D4E74 004D4E74 988D8424 */  addiu      $4, $4, %lo(D_00758D98)
    /* 3D4E78 004D4E78 1000B2DF */  ld         $18, 0x10($29)
    /* 3D4E7C 004D4E7C 1800B3DF */  ld         $19, 0x18($29)
    /* 3D4E80 004D4E80 2000BFDF */  ld         $31, 0x20($29)
    /* 3D4E84 004D4E84 A61A1308 */  j          func_004c6a98
    /* 3D4E88 004D4E88 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D4E8C 004D4E8C 00000000 */  nop
  .L004D4E90:
    /* 3D4E90 004D4E90 AD000382 */  lb         $3, 0xAD($16)
    /* 3D4E94 004D4E94 01000224 */  addiu      $2, $0, 0x1
    /* 3D4E98 004D4E98 08006214 */  bne        $3, $2, .L004D4EBC
    /* 3D4E9C 004D4E9C 2D880000 */   daddu     $17, $0, $0
    /* 3D4EA0 004D4EA0 D43B130C */  jal        func_004cef50
    /* 3D4EA4 004D4EA4 0400048E */   lw        $4, 0x4($16)
    /* 3D4EA8 004D4EA8 2D884000 */  daddu      $17, $2, $0
    /* 3D4EAC 004D4EAC 80FF0224 */  addiu      $2, $0, -0x80
    /* 3D4EB0 004D4EB0 03002216 */  bne        $17, $2, .L004D4EC0
    /* 3D4EB4 004D4EB4 7200033C */   lui       $3, %hi(D_007188B0)
    /* 3D4EB8 004D4EB8 2D880000 */  daddu      $17, $0, $0
  .L004D4EBC:
    /* 3D4EBC 004D4EBC 7200033C */  lui        $3, %hi(D_007188B0)
  .L004D4EC0:
    /* 3D4EC0 004D4EC0 B088628C */  lw         $2, %lo(D_007188B0)($3)
    /* 3D4EC4 004D4EC4 0D004014 */  bnez       $2, .L004D4EFC
    /* 3D4EC8 004D4EC8 2D300000 */   daddu     $6, $0, $0
    /* 3D4ECC 004D4ECC 80FF0224 */  addiu      $2, $0, -0x80
    /* 3D4ED0 004D4ED0 0A006256 */  bnel       $19, $2, .L004D4EFC
    /* 3D4ED4 004D4ED4 21307102 */   addu      $6, $19, $17
    /* 3D4ED8 004D4ED8 6A3B130C */  jal        func_004ceda8
    /* 3D4EDC 004D4EDC 0400048E */   lw        $4, 0x4($16)
    /* 3D4EE0 004D4EE0 02000324 */  addiu      $3, $0, 0x2
    /* 3D4EE4 004D4EE4 04004354 */  bnel       $2, $3, .L004D4EF8
    /* 3D4EE8 004D4EE8 2D300000 */   daddu     $6, $0, $0
    /* 3D4EEC 004D4EEC 0F000224 */  addiu      $2, $0, 0xF
    /* 3D4EF0 004D4EF0 F1FF0624 */  addiu      $6, $0, -0xF
    /* 3D4EF4 004D4EF4 0B305200 */  movn       $6, $2, $18
  .L004D4EF8:
    /* 3D4EF8 004D4EF8 2130D100 */  addu       $6, $6, $17
  .L004D4EFC:
    /* 3D4EFC 004D4EFC 40101200 */  sll        $2, $18, 1
    /* 3D4F00 004D4F00 21105000 */  addu       $2, $2, $16
    /* 3D4F04 004D4F04 420053A4 */  sh         $19, 0x42($2)
    /* 3D4F08 004D4F08 03000382 */  lb         $3, 0x3($16)
    /* 3D4F0C 004D4F0C 2A184302 */  slt        $3, $18, $3
    /* 3D4F10 004D4F10 07006010 */  beqz       $3, .L004D4F30
    /* 3D4F14 004D4F14 7600043C */   lui       $4, %hi(D_00758DC8)
    /* 3D4F18 004D4F18 0C00048E */  lw         $4, 0xC($16)
    /* 3D4F1C 004D4F1C 0C36130C */  jal        func_004cd830
    /* 3D4F20 004D4F20 2D284002 */   daddu     $5, $18, $0
    /* 3D4F24 004D4F24 05000010 */  b          .L004D4F3C
    /* 3D4F28 004D4F28 0000B0DF */   ld        $16, 0x0($29)
    /* 3D4F2C 004D4F2C 00000000 */  nop
  .L004D4F30:
    /* 3D4F30 004D4F30 A61A130C */  jal        func_004c6a98
    /* 3D4F34 004D4F34 C88D8424 */   addiu     $4, $4, %lo(D_00758DC8)
    /* 3D4F38 004D4F38 0000B0DF */  ld         $16, 0x0($29)
  .L004D4F3C:
    /* 3D4F3C 004D4F3C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D4F40 004D4F40 1000B2DF */  ld         $18, 0x10($29)
    /* 3D4F44 004D4F44 1800B3DF */  ld         $19, 0x18($29)
    /* 3D4F48 004D4F48 2000BFDF */  ld         $31, 0x20($29)
    /* 3D4F4C 004D4F4C 0800E003 */  jr         $31
    /* 3D4F50 004D4F50 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D4F54 004D4F54 00000000 */  nop
.size func_004d4e40, 0x118

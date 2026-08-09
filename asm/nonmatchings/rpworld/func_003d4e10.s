.section .text
.set noat
.set noreorder
glabel func_003d4e10
    /* 2D4E10 003D4E10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4E14 003D4E14 0000BFFF */  sd         $31, 0x0($29)
    /* 2D4E18 003D4E18 B86D0E0C */  jal        func_0039b6e0
    /* 2D4E1C 003D4E1C 03100424 */   addiu     $4, $0, 0x1003
    /* 2D4E20 003D4E20 B8B9848F */  lw         $4, -0x4648($28)
    /* 2D4E24 003D4E24 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2D4E28 003D4E28 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2D4E2C 003D4E2C 21186400 */  addu       $3, $3, $4
    /* 2D4E30 003D4E30 05004010 */  beqz       $2, .L003D4E48
    /* 2D4E34 003D4E34 580062AC */   sw        $2, 0x58($3)
    /* 2D4E38 003D4E38 04300F0C */  jal        func_003cc010
    /* 2D4E3C 003D4E3C 2D204000 */   daddu     $4, $2, $0
    /* 2D4E40 003D4E40 0E000010 */  b          .L003D4E7C
    /* 2D4E44 003D4E44 01000224 */   addiu     $2, $0, 0x1
  .L003D4E48:
    /* 2D4E48 003D4E48 04300F0C */  jal        func_003cc010
    /* 2D4E4C 003D4E4C 2D200000 */   daddu     $4, $0, $0
    /* 2D4E50 003D4E50 02000324 */  addiu      $3, $0, 0x2
    /* 2D4E54 003D4E54 0080023C */  lui        $2, (0x80000006 >> 16)
    /* 2D4E58 003D4E58 7100053C */  lui        $5, %hi(D_0070B5B0)
    /* 2D4E5C 003D4E5C 1800A3AF */  sw         $3, 0x18($29)
    /* 2D4E60 003D4E60 06004434 */  ori        $4, $2, (0x80000006 & 0xFFFF)
    /* 2D4E64 003D4E64 647D0F0C */  jal        func_003df590
    /* 2D4E68 003D4E68 B0B5A524 */   addiu     $5, $5, %lo(D_0070B5B0)
    /* 2D4E6C 003D4E6C 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2D4E70 003D4E70 347D0F0C */  jal        func_003df4d0
    /* 2D4E74 003D4E74 1800A427 */   addiu     $4, $29, 0x18
    /* 2D4E78 003D4E78 01000224 */  addiu      $2, $0, 0x1
  .L003D4E7C:
    /* 2D4E7C 003D4E7C 0000BFDF */  ld         $31, 0x0($29)
    /* 2D4E80 003D4E80 0800E003 */  jr         $31
    /* 2D4E84 003D4E84 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4E88 003D4E88 00000000 */  nop
    /* 2D4E8C 003D4E8C 00000000 */  nop
.size func_003d4e10, 0x80

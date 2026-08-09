.section .text
.set noat
.set noreorder
glabel func_003d4ea0
    /* 2D4EA0 003D4EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4EA4 003D4EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 2D4EA8 003D4EA8 B86D0E0C */  jal        func_0039b6e0
    /* 2D4EAC 003D4EAC 02100424 */   addiu     $4, $0, 0x1002
    /* 2D4EB0 003D4EB0 B8B9848F */  lw         $4, -0x4648($28)
    /* 2D4EB4 003D4EB4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2D4EB8 003D4EB8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2D4EBC 003D4EBC 21186400 */  addu       $3, $3, $4
    /* 2D4EC0 003D4EC0 05004010 */  beqz       $2, .L003D4ED8
    /* 2D4EC4 003D4EC4 540062AC */   sw        $2, 0x54($3)
    /* 2D4EC8 003D4EC8 1C300F0C */  jal        func_003cc070
    /* 2D4ECC 003D4ECC 2D204000 */   daddu     $4, $2, $0
    /* 2D4ED0 003D4ED0 0E000010 */  b          .L003D4F0C
    /* 2D4ED4 003D4ED4 01000224 */   addiu     $2, $0, 0x1
  .L003D4ED8:
    /* 2D4ED8 003D4ED8 1C300F0C */  jal        func_003cc070
    /* 2D4EDC 003D4EDC 2D200000 */   daddu     $4, $0, $0
    /* 2D4EE0 003D4EE0 02000324 */  addiu      $3, $0, 0x2
    /* 2D4EE4 003D4EE4 0080023C */  lui        $2, (0x80000006 >> 16)
    /* 2D4EE8 003D4EE8 7100053C */  lui        $5, %hi(D_0070B5D0)
    /* 2D4EEC 003D4EEC 1800A3AF */  sw         $3, 0x18($29)
    /* 2D4EF0 003D4EF0 06004434 */  ori        $4, $2, (0x80000006 & 0xFFFF)
    /* 2D4EF4 003D4EF4 647D0F0C */  jal        func_003df590
    /* 2D4EF8 003D4EF8 D0B5A524 */   addiu     $5, $5, %lo(D_0070B5D0)
    /* 2D4EFC 003D4EFC 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2D4F00 003D4F00 347D0F0C */  jal        func_003df4d0
    /* 2D4F04 003D4F04 1800A427 */   addiu     $4, $29, 0x18
    /* 2D4F08 003D4F08 01000224 */  addiu      $2, $0, 0x1
  .L003D4F0C:
    /* 2D4F0C 003D4F0C 0000BFDF */  ld         $31, 0x0($29)
    /* 2D4F10 003D4F10 0800E003 */  jr         $31
    /* 2D4F14 003D4F14 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4F18 003D4F18 00000000 */  nop
    /* 2D4F1C 003D4F1C 00000000 */  nop
.size func_003d4ea0, 0x80

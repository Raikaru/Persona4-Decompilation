.section .text
.set noat
.set noreorder
glabel func_002a6b10
    /* 1A6B10 002A6B10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1A6B14 002A6B14 0000BFFF */  sd         $31, 0x0($29)
    /* 1A6B18 002A6B18 2C00A427 */  addiu      $4, $29, 0x2C
    /* 1A6B1C 002A6B1C 20A880C7 */  lwc1       $f0, -0x57E0($28)
    /* 1A6B20 002A6B20 2C00A0E7 */  swc1       $f0, 0x2C($29)
    /* 1A6B24 002A6B24 2F00A6A3 */  sb         $6, 0x2F($29)
    /* 1A6B28 002A6B28 1000A527 */  addiu      $5, $29, 0x10
    /* 1A6B2C 002A6B2C 6400033C */  lui        $3, %hi(D_0063ED70)
    /* 1A6B30 002A6B30 70ED6378 */  lq         $3, %lo(D_0063ED70)($3)
    /* 1A6B34 002A6B34 1000A37F */  sq         $3, 0x10($29)
    /* 1A6B38 002A6B38 0500C010 */  beqz       $6, .L002A6B50
    /* 1A6B3C 002A6B3C 00000000 */   nop
    /* 1A6B40 002A6B40 00608044 */  mtc1       $0, $f12
    /* 1A6B44 002A6B44 01000624 */  addiu      $6, $0, 0x1
    /* 1A6B48 002A6B48 B875110C */  jal        func_0045d6e0
    /* 1A6B4C 002A6B4C 00000000 */   nop
  .L002A6B50:
    /* 1A6B50 002A6B50 0000BFDF */  ld         $31, 0x0($29)
    /* 1A6B54 002A6B54 3000BD27 */  addiu      $29, $29, 0x30
    /* 1A6B58 002A6B58 0800E003 */  jr         $31
    /* 1A6B5C 002A6B5C 00000000 */   nop
.size func_002a6b10, 0x50

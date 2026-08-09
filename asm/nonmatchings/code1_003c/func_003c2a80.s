.section .text
.set noat
.set noreorder
glabel func_003c2a80
    /* 2C2A80 003C2A80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C2A84 003C2A84 01000224 */  addiu      $2, $0, 0x1
    /* 2C2A88 003C2A88 1000BFFF */  sd         $31, 0x10($29)
    /* 2C2A8C 003C2A8C 0000B07F */  sq         $16, 0x0($29)
    /* 2C2A90 003C2A90 0E008384 */  lh         $3, 0xE($4)
    /* 2C2A94 003C2A94 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2C2A98 003C2A98 06006018 */  blez       $3, .L003C2AB4
    /* 2C2A9C 003C2A9C 2D808000 */   daddu     $16, $4, $0
    /* 2C2AA0 003C2AA0 0E000386 */  lh         $3, 0xE($16)
    /* 2C2AA4 003C2AA4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2C2AA8 003C2AA8 0E0003A6 */  sh         $3, 0xE($16)
  .L003C2AAC:
    /* 2C2AAC 003C2AAC 2C000010 */  b          .L003C2B60
    /* 2C2AB0 003C2AB0 1000BFDF */   ld        $31, 0x10($29)
  .L003C2AB4:
    /* 2C2AB4 003C2AB4 5800048E */  lw         $4, 0x58($16)
    /* 2C2AB8 003C2AB8 03008010 */  beqz       $4, .L003C2AC8
    /* 2C2ABC 003C2ABC 00000000 */   nop
    /* 2C2AC0 003C2AC0 A8870F0C */  jal        func_003e1ea0
    /* 2C2AC4 003C2AC4 00000000 */   nop
  .L003C2AC8:
    /* 2C2AC8 003C2AC8 0E000286 */  lh         $2, 0xE($16)
    /* 2C2ACC 003C2ACC FFFF4224 */  addiu      $2, $2, -0x1
    /* 2C2AD0 003C2AD0 0E0002A6 */  sh         $2, 0xE($16)
    /* 2C2AD4 003C2AD4 0E000286 */  lh         $2, 0xE($16)
    /* 2C2AD8 003C2AD8 01004224 */  addiu      $2, $2, 0x1
    /* 2C2ADC 003C2ADC 0E0002A6 */  sh         $2, 0xE($16)
    /* 2C2AE0 003C2AE0 0C000296 */  lhu        $2, 0xC($16)
    /* 2C2AE4 003C2AE4 FF0F4234 */  ori        $2, $2, 0xFFF
    /* 2C2AE8 003C2AE8 0C0002A6 */  sh         $2, 0xC($16)
    /* 2C2AEC 003C2AEC 5400048E */  lw         $4, 0x54($16)
    /* 2C2AF0 003C2AF0 04008010 */  beqz       $4, .L003C2B04
    /* 2C2AF4 003C2AF4 00000000 */   nop
    /* 2C2AF8 003C2AF8 D8150F0C */  jal        func_003c5760
    /* 2C2AFC 003C2AFC 00000000 */   nop
    /* 2C2B00 003C2B00 540000AE */  sw         $0, 0x54($16)
  .L003C2B04:
    /* 2C2B04 003C2B04 7100043C */  lui        $4, %hi(D_0070AFB0)
    /* 2C2B08 003C2B08 2D280002 */  daddu      $5, $16, $0
    /* 2C2B0C 003C2B0C 088F0F0C */  jal        func_003e3c20
    /* 2C2B10 003C2B10 B0AF8424 */   addiu     $4, $4, %lo(D_0070AFB0)
    /* 2C2B14 003C2B14 5C00048E */  lw         $4, 0x5C($16)
    /* 2C2B18 003C2B18 06008010 */  beqz       $4, .L003C2B34
    /* 2C2B1C 003C2B1C 00000000 */   nop
    /* 2C2B20 003C2B20 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C2B24 003C2B24 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C2B28 003C2B28 09F84000 */  jalr       $2
    /* 2C2B2C 003C2B2C 00000000 */   nop
    /* 2C2B30 003C2B30 5C0000AE */  sw         $0, 0x5C($16)
  .L003C2B34:
    /* 2C2B34 003C2B34 68120F0C */  jal        func_003c49a0
    /* 2C2B38 003C2B38 20000426 */   addiu     $4, $16, 0x20
    /* 2C2B3C 003C2B3C 0E000386 */  lh         $3, 0xE($16)
    /* 2C2B40 003C2B40 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C2B44 003C2B44 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2C2B48 003C2B48 0E0003A6 */  sh         $3, 0xE($16)
    /* 2C2B4C 003C2B4C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C2B50 003C2B50 09F84000 */  jalr       $2
    /* 2C2B54 003C2B54 2D200002 */   daddu     $4, $16, $0
    /* 2C2B58 003C2B58 D4FF0010 */  b          .L003C2AAC
    /* 2C2B5C 003C2B5C 01000224 */   addiu     $2, $0, 0x1
  .L003C2B60:
    /* 2C2B60 003C2B60 0000B07B */  lq         $16, 0x0($29)
    /* 2C2B64 003C2B64 0800E003 */  jr         $31
    /* 2C2B68 003C2B68 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C2B6C 003C2B6C 00000000 */  nop
.size func_003c2a80, 0xf0

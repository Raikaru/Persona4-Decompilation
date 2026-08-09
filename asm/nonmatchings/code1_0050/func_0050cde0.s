.section .text
.set noat
.set noreorder
glabel func_0050cde0
    /* 40CDE0 0050CDE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40CDE4 0050CDE4 0000B0FF */  sd         $16, 0x0($29)
    /* 40CDE8 0050CDE8 2D80A000 */  daddu      $16, $5, $0
    /* 40CDEC 0050CDEC 0800B1FF */  sd         $17, 0x8($29)
    /* 40CDF0 0050CDF0 1000BFFF */  sd         $31, 0x10($29)
    /* 40CDF4 0050CDF4 0A35140C */  jal        func_0050d428
    /* 40CDF8 0050CDF8 2D888000 */   daddu     $17, $4, $0
    /* 40CDFC 0050CDFC 7600043C */  lui        $4, %hi(D_0075F038)
    /* 40CE00 0050CE00 01000324 */  addiu      $3, $0, 0x1
    /* 40CE04 0050CE04 38F08424 */  addiu      $4, $4, %lo(D_0075F038)
    /* 40CE08 0050CE08 2D300002 */  daddu      $6, $16, $0
    /* 40CE0C 0050CE0C 06004310 */  beq        $2, $3, .L0050CE28
    /* 40CE10 0050CE10 06000524 */   addiu     $5, $0, 0x6
    /* 40CE14 0050CE14 0000B0DF */  ld         $16, 0x0($29)
    /* 40CE18 0050CE18 0800B1DF */  ld         $17, 0x8($29)
    /* 40CE1C 0050CE1C 1000BFDF */  ld         $31, 0x10($29)
    /* 40CE20 0050CE20 88441408 */  j          func_00511220
    /* 40CE24 0050CE24 2000BD27 */   addiu     $29, $29, 0x20
  .L0050CE28:
    /* 40CE28 0050CE28 3C00248E */  lw         $4, 0x3C($17)
    /* 40CE2C 0050CE2C 0000B0DF */  ld         $16, 0x0($29)
    /* 40CE30 0050CE30 0800B1DF */  ld         $17, 0x8($29)
    /* 40CE34 0050CE34 1000BFDF */  ld         $31, 0x10($29)
    /* 40CE38 0050CE38 64931408 */  j          func_00524d90
    /* 40CE3C 0050CE3C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050cde0, 0x60

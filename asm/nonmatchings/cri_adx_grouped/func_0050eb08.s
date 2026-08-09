.section .text
.set noat
.set noreorder
glabel func_0050eb08
    /* 40EB08 0050EB08 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 40EB0C 0050EB0C A800B1FF */  sd         $17, 0xA8($29)
    /* 40EB10 0050EB10 2D888000 */  daddu      $17, $4, $0
    /* 40EB14 0050EB14 B000B2FF */  sd         $18, 0xB0($29)
    /* 40EB18 0050EB18 2D90A000 */  daddu      $18, $5, $0
    /* 40EB1C 0050EB1C B800B3FF */  sd         $19, 0xB8($29)
    /* 40EB20 0050EB20 A000B0FF */  sd         $16, 0xA0($29)
    /* 40EB24 0050EB24 C000BFFF */  sd         $31, 0xC0($29)
    /* 40EB28 0050EB28 0A35140C */  jal        func_0050d428
    /* 40EB2C 0050EB2C 2D98C000 */   daddu     $19, $6, $0
    /* 40EB30 0050EB30 7600043C */  lui        $4, %hi(D_0075F7A0)
    /* 40EB34 0050EB34 01000324 */  addiu      $3, $0, 0x1
    /* 40EB38 0050EB38 05004310 */  beq        $2, $3, .L0050EB50
    /* 40EB3C 0050EB3C A0F78424 */   addiu     $4, $4, %lo(D_0075F7A0)
    /* 40EB40 0050EB40 8844140C */  jal        func_00511220
    /* 40EB44 0050EB44 00000000 */   nop
    /* 40EB48 0050EB48 15000010 */  b          .L0050EBA0
    /* 40EB4C 0050EB4C A000B0DF */   ld        $16, 0xA0($29)
  .L0050EB50:
    /* 40EB50 0050EB50 0000428E */  lw         $2, 0x0($18)
    /* 40EB54 0050EB54 06004014 */  bnez       $2, .L0050EB70
    /* 40EB58 0050EB58 7600043C */   lui       $4, %hi(D_0075F7D0)
    /* 40EB5C 0050EB5C 8844140C */  jal        func_00511220
    /* 40EB60 0050EB60 D0F78424 */   addiu     $4, $4, %lo(D_0075F7D0)
    /* 40EB64 0050EB64 0E000010 */  b          .L0050EBA0
    /* 40EB68 0050EB68 A000B0DF */   ld        $16, 0xA0($29)
    /* 40EB6C 0050EB6C 00000000 */  nop
  .L0050EB70:
    /* 40EB70 0050EB70 2E39140C */  jal        func_0050e4b8
    /* 40EB74 0050EB74 2D202002 */   daddu     $4, $17, $0
    /* 40EB78 0050EB78 2D202002 */  daddu      $4, $17, $0
    /* 40EB7C 0050EB7C 2D284002 */  daddu      $5, $18, $0
    /* 40EB80 0050EB80 2D30A003 */  daddu      $6, $29, $0
    /* 40EB84 0050EB84 3839140C */  jal        func_0050e4e0
    /* 40EB88 0050EB88 2D804000 */   daddu     $16, $2, $0
    /* 40EB8C 0050EB8C 2D28A003 */  daddu      $5, $29, $0
    /* 40EB90 0050EB90 2D200002 */  daddu      $4, $16, $0
    /* 40EB94 0050EB94 4CB2140C */  jal        func_0052c930
    /* 40EB98 0050EB98 2D306002 */   daddu     $6, $19, $0
    /* 40EB9C 0050EB9C A000B0DF */  ld         $16, 0xA0($29)
  .L0050EBA0:
    /* 40EBA0 0050EBA0 A800B1DF */  ld         $17, 0xA8($29)
    /* 40EBA4 0050EBA4 B000B2DF */  ld         $18, 0xB0($29)
    /* 40EBA8 0050EBA8 B800B3DF */  ld         $19, 0xB8($29)
    /* 40EBAC 0050EBAC C000BFDF */  ld         $31, 0xC0($29)
    /* 40EBB0 0050EBB0 0800E003 */  jr         $31
    /* 40EBB4 0050EBB4 D000BD27 */   addiu     $29, $29, 0xD0
.size func_0050eb08, 0xb0

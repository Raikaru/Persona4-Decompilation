.section .text
.set noat
.set noreorder
glabel func_0050ea58
    /* 40EA58 0050EA58 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 40EA5C 0050EA5C A800B1FF */  sd         $17, 0xA8($29)
    /* 40EA60 0050EA60 2D888000 */  daddu      $17, $4, $0
    /* 40EA64 0050EA64 B000B2FF */  sd         $18, 0xB0($29)
    /* 40EA68 0050EA68 2D90A000 */  daddu      $18, $5, $0
    /* 40EA6C 0050EA6C B800B3FF */  sd         $19, 0xB8($29)
    /* 40EA70 0050EA70 A000B0FF */  sd         $16, 0xA0($29)
    /* 40EA74 0050EA74 C000BFFF */  sd         $31, 0xC0($29)
    /* 40EA78 0050EA78 0A35140C */  jal        func_0050d428
    /* 40EA7C 0050EA7C 2D98C000 */   daddu     $19, $6, $0
    /* 40EA80 0050EA80 7600043C */  lui        $4, %hi(D_0075F740)
    /* 40EA84 0050EA84 01000324 */  addiu      $3, $0, 0x1
    /* 40EA88 0050EA88 05004310 */  beq        $2, $3, .L0050EAA0
    /* 40EA8C 0050EA8C 40F78424 */   addiu     $4, $4, %lo(D_0075F740)
    /* 40EA90 0050EA90 8844140C */  jal        func_00511220
    /* 40EA94 0050EA94 00000000 */   nop
    /* 40EA98 0050EA98 15000010 */  b          .L0050EAF0
    /* 40EA9C 0050EA9C A000B0DF */   ld        $16, 0xA0($29)
  .L0050EAA0:
    /* 40EAA0 0050EAA0 0000428E */  lw         $2, 0x0($18)
    /* 40EAA4 0050EAA4 06004014 */  bnez       $2, .L0050EAC0
    /* 40EAA8 0050EAA8 7600043C */   lui       $4, %hi(D_0075F770)
    /* 40EAAC 0050EAAC 8844140C */  jal        func_00511220
    /* 40EAB0 0050EAB0 70F78424 */   addiu     $4, $4, %lo(D_0075F770)
    /* 40EAB4 0050EAB4 0E000010 */  b          .L0050EAF0
    /* 40EAB8 0050EAB8 A000B0DF */   ld        $16, 0xA0($29)
    /* 40EABC 0050EABC 00000000 */  nop
  .L0050EAC0:
    /* 40EAC0 0050EAC0 2E39140C */  jal        func_0050e4b8
    /* 40EAC4 0050EAC4 2D202002 */   daddu     $4, $17, $0
    /* 40EAC8 0050EAC8 2D202002 */  daddu      $4, $17, $0
    /* 40EACC 0050EACC 2D284002 */  daddu      $5, $18, $0
    /* 40EAD0 0050EAD0 2D30A003 */  daddu      $6, $29, $0
    /* 40EAD4 0050EAD4 3839140C */  jal        func_0050e4e0
    /* 40EAD8 0050EAD8 2D804000 */   daddu     $16, $2, $0
    /* 40EADC 0050EADC 2D28A003 */  daddu      $5, $29, $0
    /* 40EAE0 0050EAE0 2D200002 */  daddu      $4, $16, $0
    /* 40EAE4 0050EAE4 24B2140C */  jal        func_0052c890
    /* 40EAE8 0050EAE8 2D306002 */   daddu     $6, $19, $0
    /* 40EAEC 0050EAEC A000B0DF */  ld         $16, 0xA0($29)
  .L0050EAF0:
    /* 40EAF0 0050EAF0 A800B1DF */  ld         $17, 0xA8($29)
    /* 40EAF4 0050EAF4 B000B2DF */  ld         $18, 0xB0($29)
    /* 40EAF8 0050EAF8 B800B3DF */  ld         $19, 0xB8($29)
    /* 40EAFC 0050EAFC C000BFDF */  ld         $31, 0xC0($29)
    /* 40EB00 0050EB00 0800E003 */  jr         $31
    /* 40EB04 0050EB04 D000BD27 */   addiu     $29, $29, 0xD0
.size func_0050ea58, 0xb0

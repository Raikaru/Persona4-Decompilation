.section .text
.set noat
.set noreorder
glabel func_004bfb28
    /* 3BFB28 004BFB28 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BFB2C 004BFB2C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BFB30 004BFB30 2D888000 */  daddu      $17, $4, $0
    /* 3BFB34 004BFB34 1000B2FF */  sd         $18, 0x10($29)
    /* 3BFB38 004BFB38 2D900000 */  daddu      $18, $0, $0
    /* 3BFB3C 004BFB3C 1800B3FF */  sd         $19, 0x18($29)
    /* 3BFB40 004BFB40 0000B0FF */  sd         $16, 0x0($29)
    /* 3BFB44 004BFB44 2000BFFF */  sd         $31, 0x20($29)
    /* 3BFB48 004BFB48 A000228E */  lw         $2, 0xA0($17)
    /* 3BFB4C 004BFB4C 0C004018 */  blez       $2, .L004BFB80
    /* 3BFB50 004BFB50 2D98A000 */   daddu     $19, $5, $0
    /* 3BFB54 004BFB54 20003026 */  addiu      $16, $17, 0x20
    /* 3BFB58 004BFB58 0000048E */  lw         $4, 0x0($16)
    /* 3BFB5C 004BFB5C 00000000 */  nop
  .L004BFB60:
    /* 3BFB60 004BFB60 0C001026 */  addiu      $16, $16, 0xC
    /* 3BFB64 004BFB64 2D286002 */  daddu      $5, $19, $0
    /* 3BFB68 004BFB68 74F6120C */  jal        func_004bd9d0
    /* 3BFB6C 004BFB6C 01005226 */   addiu     $18, $18, 0x1
    /* 3BFB70 004BFB70 A000228E */  lw         $2, 0xA0($17)
    /* 3BFB74 004BFB74 2A104202 */  slt        $2, $18, $2
    /* 3BFB78 004BFB78 F9FF4054 */  bnel       $2, $0, .L004BFB60
    /* 3BFB7C 004BFB7C 0000048E */   lw        $4, 0x0($16)
  .L004BFB80:
    /* 3BFB80 004BFB80 0000B0DF */  ld         $16, 0x0($29)
    /* 3BFB84 004BFB84 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFB88 004BFB88 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFB8C 004BFB8C 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFB90 004BFB90 2000BFDF */  ld         $31, 0x20($29)
    /* 3BFB94 004BFB94 0800E003 */  jr         $31
    /* 3BFB98 004BFB98 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BFB9C 004BFB9C 00000000 */  nop
.size func_004bfb28, 0x78

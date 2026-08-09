.section .text
.set noat
.set noreorder
glabel func_004bfba0
    /* 3BFBA0 004BFBA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BFBA4 004BFBA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BFBA8 004BFBA8 2D808000 */  daddu      $16, $4, $0
    /* 3BFBAC 004BFBAC 0800B1FF */  sd         $17, 0x8($29)
    /* 3BFBB0 004BFBB0 2D880002 */  daddu      $17, $16, $0
    /* 3BFBB4 004BFBB4 1000B2FF */  sd         $18, 0x10($29)
    /* 3BFBB8 004BFBB8 18001226 */  addiu      $18, $16, 0x18
    /* 3BFBBC 004BFBBC 1800B3FF */  sd         $19, 0x18($29)
    /* 3BFBC0 004BFBC0 01001324 */  addiu      $19, $0, 0x1
    /* 3BFBC4 004BFBC4 2000BFFF */  sd         $31, 0x20($29)
    /* 3BFBC8 004BFBC8 080000AE */  sw         $0, 0x8($16)
    /* 3BFBCC 004BFBCC 0C0000AE */  sw         $0, 0xC($16)
    /* 3BFBD0 004BFBD0 100000AE */  sw         $0, 0x10($16)
    /* 3BFBD4 004BFBD4 140000AE */  sw         $0, 0x14($16)
    /* 3BFBD8 004BFBD8 000020AE */  sw         $0, 0x0($17)
    /* 3BFBDC 004BFBDC 00000000 */  nop
  .L004BFBE0:
    /* 3BFBE0 004BFBE0 04003126 */  addiu      $17, $17, 0x4
    /* 3BFBE4 004BFBE4 2D204002 */  daddu      $4, $18, $0
    /* 3BFBE8 004BFBE8 0C005226 */  addiu      $18, $18, 0xC
    /* 3BFBEC 004BFBEC FFFF7326 */  addiu      $19, $19, -0x1
    /* 3BFBF0 004BFBF0 2D280000 */  daddu      $5, $0, $0
    /* 3BFBF4 004BFBF4 72FE100C */  jal        func_0043f9c8
    /* 3BFBF8 004BFBF8 0C000624 */   addiu     $6, $0, 0xC
    /* 3BFBFC 004BFBFC F8FF6306 */  bgezl      $19, .L004BFBE0
    /* 3BFC00 004BFC00 000020AE */   sw        $0, 0x0($17)
    /* 3BFC04 004BFC04 30000426 */  addiu      $4, $16, 0x30
    /* 3BFC08 004BFC08 2D280000 */  daddu      $5, $0, $0
    /* 3BFC0C 004BFC0C 72FE100C */  jal        func_0043f9c8
    /* 3BFC10 004BFC10 20000624 */   addiu     $6, $0, 0x20
    /* 3BFC14 004BFC14 500000AE */  sw         $0, 0x50($16)
    /* 3BFC18 004BFC18 540000AE */  sw         $0, 0x54($16)
    /* 3BFC1C 004BFC1C 78000426 */  addiu      $4, $16, 0x78
    /* 3BFC20 004BFC20 580000AE */  sw         $0, 0x58($16)
    /* 3BFC24 004BFC24 2D280000 */  daddu      $5, $0, $0
    /* 3BFC28 004BFC28 5C0000AE */  sw         $0, 0x5C($16)
    /* 3BFC2C 004BFC2C 28000624 */  addiu      $6, $0, 0x28
    /* 3BFC30 004BFC30 600000AE */  sw         $0, 0x60($16)
    /* 3BFC34 004BFC34 640000AE */  sw         $0, 0x64($16)
    /* 3BFC38 004BFC38 680000AE */  sw         $0, 0x68($16)
    /* 3BFC3C 004BFC3C 6C0000AE */  sw         $0, 0x6C($16)
    /* 3BFC40 004BFC40 700000AE */  sw         $0, 0x70($16)
    /* 3BFC44 004BFC44 72FE100C */  jal        func_0043f9c8
    /* 3BFC48 004BFC48 740000AE */   sw        $0, 0x74($16)
    /* 3BFC4C 004BFC4C A00000AE */  sw         $0, 0xA0($16)
    /* 3BFC50 004BFC50 1E000224 */  addiu      $2, $0, 0x1E
    /* 3BFC54 004BFC54 3C000324 */  addiu      $3, $0, 0x3C
    /* 3BFC58 004BFC58 A80002AE */  sw         $2, 0xA8($16)
    /* 3BFC5C 004BFC5C B80003AE */  sw         $3, 0xB8($16)
    /* 3BFC60 004BFC60 CC0000AE */  sw         $0, 0xCC($16)
    /* 3BFC64 004BFC64 A40000A2 */  sb         $0, 0xA4($16)
    /* 3BFC68 004BFC68 AC0000AE */  sw         $0, 0xAC($16)
    /* 3BFC6C 004BFC6C B00000AE */  sw         $0, 0xB0($16)
    /* 3BFC70 004BFC70 B40000AE */  sw         $0, 0xB4($16)
    /* 3BFC74 004BFC74 BC0000AE */  sw         $0, 0xBC($16)
    /* 3BFC78 004BFC78 C00000AE */  sw         $0, 0xC0($16)
    /* 3BFC7C 004BFC7C C40000AE */  sw         $0, 0xC4($16)
    /* 3BFC80 004BFC80 C80000AE */  sw         $0, 0xC8($16)
    /* 3BFC84 004BFC84 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFC88 004BFC88 0000B0DF */  ld         $16, 0x0($29)
    /* 3BFC8C 004BFC8C 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFC90 004BFC90 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFC94 004BFC94 2000BFDF */  ld         $31, 0x20($29)
    /* 3BFC98 004BFC98 0800E003 */  jr         $31
    /* 3BFC9C 004BFC9C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004bfba0, 0x100

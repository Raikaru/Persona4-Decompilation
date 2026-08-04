.section .text
.set noat
.set noreorder
glabel func_002baf40
    /* 1BAF40 002BAF40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BAF44 002BAF44 2000BFFF */  sd         $31, 0x20($29)
    /* 1BAF48 002BAF48 1000B17F */  sq         $17, 0x10($29)
    /* 1BAF4C 002BAF4C 0000B07F */  sq         $16, 0x0($29)
    /* 1BAF50 002BAF50 2D888000 */  daddu      $17, $4, $0
    /* 1BAF54 002BAF54 DCEF0A0C */  jal        func_002bbf70
    /* 1BAF58 002BAF58 00000000 */   nop
    /* 1BAF5C 002BAF5C 2D804000 */  daddu      $16, $2, $0
    /* 1BAF60 002BAF60 04000016 */  bnez       $16, .L002BAF74
    /* 1BAF64 002BAF64 00000000 */   nop
    /* 1BAF68 002BAF68 2D100000 */  daddu      $2, $0, $0
    /* 1BAF6C 002BAF6C 0D000010 */  b          .L002BAFA4
    /* 1BAF70 002BAF70 00000000 */   nop
  .L002BAF74:
    /* 1BAF74 002BAF74 0000028E */  lw         $2, 0x0($16)
    /* 1BAF78 002BAF78 04004104 */  bgez       $2, .L002BAF8C
    /* 1BAF7C 002BAF7C 00000000 */   nop
    /* 1BAF80 002BAF80 2D100000 */  daddu      $2, $0, $0
    /* 1BAF84 002BAF84 07000010 */  b          .L002BAFA4
    /* 1BAF88 002BAF88 00000000 */   nop
  .L002BAF8C:
    /* 1BAF8C 002BAF8C 080011AE */  sw         $17, 0x8($16)
    /* 1BAF90 002BAF90 38EC0A0C */  jal        func_002bb0e0
    /* 1BAF94 002BAF94 00000000 */   nop
    /* 1BAF98 002BAF98 0D0002A2 */  sb         $2, 0xD($16)
    /* 1BAF9C 002BAF9C 78B580A3 */  sb         $0, -0x4A88($28)
    /* 1BAFA0 002BAFA0 01000224 */  addiu      $2, $0, 0x1
  .L002BAFA4:
    /* 1BAFA4 002BAFA4 2000BFDF */  ld         $31, 0x20($29)
    /* 1BAFA8 002BAFA8 1000B17B */  lq         $17, 0x10($29)
    /* 1BAFAC 002BAFAC 0000B07B */  lq         $16, 0x0($29)
    /* 1BAFB0 002BAFB0 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BAFB4 002BAFB4 0800E003 */  jr         $31
    /* 1BAFB8 002BAFB8 00000000 */   nop
    /* 1BAFBC 002BAFBC 00000000 */  nop
.size func_002baf40, 0x80

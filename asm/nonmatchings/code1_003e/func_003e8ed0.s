.section .text
.set noat
.set noreorder
glabel func_003e8ed0
    /* 2E8ED0 003E8ED0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2E8ED4 003E8ED4 4000BFFF */  sd         $31, 0x40($29)
    /* 2E8ED8 003E8ED8 3000B37F */  sq         $19, 0x30($29)
    /* 2E8EDC 003E8EDC 2000B27F */  sq         $18, 0x20($29)
    /* 2E8EE0 003E8EE0 1000B17F */  sq         $17, 0x10($29)
    /* 2E8EE4 003E8EE4 2D90A000 */  daddu      $18, $5, $0
    /* 2E8EE8 003E8EE8 0000B07F */  sq         $16, 0x0($29)
    /* 2E8EEC 003E8EEC A00092AC */  sw         $18, 0xA0($4)
    /* 2E8EF0 003E8EF0 9800938C */  lw         $19, 0x98($4)
    /* 2E8EF4 003E8EF4 1A006012 */  beqz       $19, .L003E8F60
    /* 2E8EF8 003E8EF8 00000000 */   nop
  .L003E8EFC:
    /* 2E8EFC 003E8EFC A00072AE */  sw         $18, 0xA0($19)
    /* 2E8F00 003E8F00 9800718E */  lw         $17, 0x98($19)
    /* 2E8F04 003E8F04 12002012 */  beqz       $17, .L003E8F50
    /* 2E8F08 003E8F08 00000000 */   nop
    /* 2E8F0C 003E8F0C 00000000 */  nop
  .L003E8F10:
    /* 2E8F10 003E8F10 A00032AE */  sw         $18, 0xA0($17)
    /* 2E8F14 003E8F14 9800308E */  lw         $16, 0x98($17)
    /* 2E8F18 003E8F18 09000012 */  beqz       $16, .L003E8F40
    /* 2E8F1C 003E8F1C 00000000 */   nop
  .L003E8F20:
    /* 2E8F20 003E8F20 2D200002 */  daddu      $4, $16, $0
    /* 2E8F24 003E8F24 B4A30F0C */  jal        func_003e8ed0
    /* 2E8F28 003E8F28 2D284002 */   daddu     $5, $18, $0
    /* 2E8F2C 003E8F2C 9C00108E */  lw         $16, 0x9C($16)
    /* 2E8F30 003E8F30 00000000 */  nop
    /* 2E8F34 003E8F34 FAFF0016 */  bnez       $16, .L003E8F20
    /* 2E8F38 003E8F38 00000000 */   nop
    /* 2E8F3C 003E8F3C 00000000 */  nop
  .L003E8F40:
    /* 2E8F40 003E8F40 9C00318E */  lw         $17, 0x9C($17)
    /* 2E8F44 003E8F44 F2FF2016 */  bnez       $17, .L003E8F10
    /* 2E8F48 003E8F48 00000000 */   nop
    /* 2E8F4C 003E8F4C 00000000 */  nop
  .L003E8F50:
    /* 2E8F50 003E8F50 9C00738E */  lw         $19, 0x9C($19)
    /* 2E8F54 003E8F54 E9FF6016 */  bnez       $19, .L003E8EFC
    /* 2E8F58 003E8F58 00000000 */   nop
    /* 2E8F5C 003E8F5C 00000000 */  nop
  .L003E8F60:
    /* 2E8F60 003E8F60 4000BFDF */  ld         $31, 0x40($29)
    /* 2E8F64 003E8F64 3000B37B */  lq         $19, 0x30($29)
    /* 2E8F68 003E8F68 2000B27B */  lq         $18, 0x20($29)
    /* 2E8F6C 003E8F6C 1000B17B */  lq         $17, 0x10($29)
    /* 2E8F70 003E8F70 0000B07B */  lq         $16, 0x0($29)
    /* 2E8F74 003E8F74 0800E003 */  jr         $31
    /* 2E8F78 003E8F78 5000BD27 */   addiu     $29, $29, 0x50
    /* 2E8F7C 003E8F7C 00000000 */  nop
.size func_003e8ed0, 0xb0

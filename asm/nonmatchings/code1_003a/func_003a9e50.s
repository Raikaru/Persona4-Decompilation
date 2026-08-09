.section .text
.set noat
.set noreorder
glabel func_003a9e50
    /* 2A9E50 003A9E50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2A9E54 003A9E54 2D280000 */  daddu      $5, $0, $0
    /* 2A9E58 003A9E58 3000BFFF */  sd         $31, 0x30($29)
    /* 2A9E5C 003A9E5C 2D300000 */  daddu      $6, $0, $0
    /* 2A9E60 003A9E60 2000B27F */  sq         $18, 0x20($29)
    /* 2A9E64 003A9E64 1000B17F */  sq         $17, 0x10($29)
    /* 2A9E68 003A9E68 0000B07F */  sq         $16, 0x0($29)
    /* 2A9E6C 003A9E6C 2D808000 */  daddu      $16, $4, $0
    /* 2A9E70 003A9E70 8C090F0C */  jal        func_003c2630
    /* 2A9E74 003A9E74 2D200000 */   daddu     $4, $0, $0
    /* 2A9E78 003A9E78 2D904000 */  daddu      $18, $2, $0
    /* 2A9E7C 003A9E7C 0D004012 */  beqz       $18, .L003A9EB4
    /* 2A9E80 003A9E80 00000000 */   nop
    /* 2A9E84 003A9E84 5C00438E */  lw         $3, 0x5C($18)
    /* 2A9E88 003A9E88 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2A9E8C 003A9E8C 2D204002 */  daddu      $4, $18, $0
    /* 2A9E90 003A9E90 040060AC */  sw         $0, 0x4($3)
    /* 2A9E94 003A9E94 080060AC */  sw         $0, 0x8($3)
    /* 2A9E98 003A9E98 0C0060AC */  sw         $0, 0xC($3)
    /* 2A9E9C 003A9E9C BC080F0C */  jal        func_003c22f0
    /* 2A9EA0 003A9EA0 100062AC */   sw        $2, 0x10($3)
    /* 2A9EA4 003A9EA4 05004014 */  bnez       $2, .L003A9EBC
    /* 2A9EA8 003A9EA8 00000000 */   nop
    /* 2A9EAC 003A9EAC 1B000010 */  b          .L003A9F1C
    /* 2A9EB0 003A9EB0 2D100000 */   daddu     $2, $0, $0
  .L003A9EB4:
    /* 2A9EB4 003A9EB4 19000010 */  b          .L003A9F1C
    /* 2A9EB8 003A9EB8 2D100000 */   daddu     $2, $0, $0
  .L003A9EBC:
    /* 2A9EBC 003A9EBC 2D200002 */  daddu      $4, $16, $0
    /* 2A9EC0 003A9EC0 2D284002 */  daddu      $5, $18, $0
    /* 2A9EC4 003A9EC4 84000F0C */  jal        func_003c0210
    /* 2A9EC8 003A9EC8 2D300000 */   daddu     $6, $0, $0
    /* 2A9ECC 003A9ECC A00A0F0C */  jal        func_003c2a80
    /* 2A9ED0 003A9ED0 2D204002 */   daddu     $4, $18, $0
    /* 2A9ED4 003A9ED4 50100F0C */  jal        func_003c4140
    /* 2A9ED8 003A9ED8 00000000 */   nop
    /* 2A9EDC 003A9EDC 2D884000 */  daddu      $17, $2, $0
    /* 2A9EE0 003A9EE0 20004426 */  addiu      $4, $18, 0x20
    /* 2A9EE4 003A9EE4 A0120F0C */  jal        func_003c4a80
    /* 2A9EE8 003A9EE8 2D282002 */   daddu     $5, $17, $0
    /* 2A9EEC 003A9EEC 88100F0C */  jal        func_003c4220
    /* 2A9EF0 003A9EF0 2D202002 */   daddu     $4, $17, $0
    /* 2A9EF4 003A9EF4 10B6838F */  lw         $3, -0x49F0($28)
    /* 2A9EF8 003A9EF8 01000224 */  addiu      $2, $0, 0x1
    /* 2A9EFC 003A9EFC 21180302 */  addu       $3, $16, $3
    /* 2A9F00 003A9F00 0000638C */  lw         $3, 0x0($3)
    /* 2A9F04 003A9F04 240060AC */  sw         $0, 0x24($3)
    /* 2A9F08 003A9F08 280060AC */  sw         $0, 0x28($3)
    /* 2A9F0C 003A9F0C 2C0060AC */  sw         $0, 0x2C($3)
    /* 2A9F10 003A9F10 300060AC */  sw         $0, 0x30($3)
    /* 2A9F14 003A9F14 340060AC */  sw         $0, 0x34($3)
    /* 2A9F18 003A9F18 380060AC */  sw         $0, 0x38($3)
  .L003A9F1C:
    /* 2A9F1C 003A9F1C 3000BFDF */  ld         $31, 0x30($29)
    /* 2A9F20 003A9F20 2000B27B */  lq         $18, 0x20($29)
    /* 2A9F24 003A9F24 1000B17B */  lq         $17, 0x10($29)
    /* 2A9F28 003A9F28 0000B07B */  lq         $16, 0x0($29)
    /* 2A9F2C 003A9F2C 0800E003 */  jr         $31
    /* 2A9F30 003A9F30 4000BD27 */   addiu     $29, $29, 0x40
    /* 2A9F34 003A9F34 00000000 */  nop
    /* 2A9F38 003A9F38 00000000 */  nop
    /* 2A9F3C 003A9F3C 00000000 */  nop
.size func_003a9e50, 0xf0

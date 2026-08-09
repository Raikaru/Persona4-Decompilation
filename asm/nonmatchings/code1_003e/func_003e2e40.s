.section .text
.set noat
.set noreorder
glabel func_003e2e40
    /* 2E2E40 003E2E40 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2E2E44 003E2E44 04000224 */  addiu      $2, $0, 0x4
    /* 2E2E48 003E2E48 2000BFFF */  sd         $31, 0x20($29)
    /* 2E2E4C 003E2E4C 1000B17F */  sq         $17, 0x10($29)
    /* 2E2E50 003E2E50 0000B07F */  sq         $16, 0x0($29)
    /* 2E2E54 003E2E54 0000838C */  lw         $3, 0x0($4)
    /* 2E2E58 003E2E58 1D006210 */  beq        $3, $2, .L003E2ED0
    /* 2E2E5C 003E2E5C 2D888000 */   daddu     $17, $4, $0
    /* 2E2E60 003E2E60 03000224 */  addiu      $2, $0, 0x3
    /* 2E2E64 003E2E64 0E006210 */  beq        $3, $2, .L003E2EA0
    /* 2E2E68 003E2E68 00000000 */   nop
    /* 2E2E6C 003E2E6C 02000224 */  addiu      $2, $0, 0x2
    /* 2E2E70 003E2E70 06006210 */  beq        $3, $2, .L003E2E8C
    /* 2E2E74 003E2E74 00000000 */   nop
    /* 2E2E78 003E2E78 01001024 */  addiu      $16, $0, 0x1
    /* 2E2E7C 003E2E7C 1A007010 */  beq        $3, $16, .L003E2EE8
    /* 2E2E80 003E2E80 00000000 */   nop
    /* 2E2E84 003E2E84 1E000010 */  b          .L003E2F00
    /* 2E2E88 003E2E88 0E000424 */   addiu     $4, $0, 0xE
  .L003E2E8C:
    /* 2E2E8C 003E2E8C C8770F0C */  jal        func_003ddf20
    /* 2E2E90 003E2E90 0C00248E */   lw        $4, 0xC($17)
    /* 2E2E94 003E2E94 26804000 */  xor        $16, $2, $0
    /* 2E2E98 003E2E98 13000010 */  b          .L003E2EE8
    /* 2E2E9C 003E2E9C 0100102E */   sltiu     $16, $16, 0x1
  .L003E2EA0:
    /* 2E2EA0 003E2EA0 0400238E */  lw         $3, 0x4($17)
    /* 2E2EA4 003E2EA4 01000224 */  addiu      $2, $0, 0x1
    /* 2E2EA8 003E2EA8 07006210 */  beq        $3, $2, .L003E2EC8
    /* 2E2EAC 003E2EAC 00000000 */   nop
    /* 2E2EB0 003E2EB0 0500A010 */  beqz       $5, .L003E2EC8
    /* 2E2EB4 003E2EB4 00000000 */   nop
    /* 2E2EB8 003E2EB8 1400228E */  lw         $2, 0x14($17)
    /* 2E2EBC 003E2EBC 0000A2AC */  sw         $2, 0x0($5)
    /* 2E2EC0 003E2EC0 0C00228E */  lw         $2, 0xC($17)
    /* 2E2EC4 003E2EC4 0400A2AC */  sw         $2, 0x4($5)
  .L003E2EC8:
    /* 2E2EC8 003E2EC8 07000010 */  b          .L003E2EE8
    /* 2E2ECC 003E2ECC 01001024 */   addiu     $16, $0, 0x1
  .L003E2ED0:
    /* 2E2ED0 003E2ED0 0C00228E */  lw         $2, 0xC($17)
    /* 2E2ED4 003E2ED4 03004010 */  beqz       $2, .L003E2EE4
    /* 2E2ED8 003E2ED8 00000000 */   nop
    /* 2E2EDC 003E2EDC 09F84000 */  jalr       $2
    /* 2E2EE0 003E2EE0 1C00248E */   lw        $4, 0x1C($17)
  .L003E2EE4:
    /* 2E2EE4 003E2EE4 01001024 */  addiu      $16, $0, 0x1
  .L003E2EE8:
    /* 2E2EE8 003E2EE8 2000228E */  lw         $2, 0x20($17)
    /* 2E2EEC 003E2EEC 0B004014 */  bnez       $2, .L003E2F1C
    /* 2E2EF0 003E2EF0 00000000 */   nop
  .L003E2EF4:
    /* 2E2EF4 003E2EF4 14000010 */  b          .L003E2F48
    /* 2E2EF8 003E2EF8 2D100002 */   daddu     $2, $16, $0
    /* 2E2EFC 003E2EFC 0E000424 */  addiu      $4, $0, 0xE
  .L003E2F00:
    /* 2E2F00 003E2F00 647D0F0C */  jal        func_003df590
    /* 2E2F04 003E2F04 3800B0AF */   sw        $16, 0x38($29)
    /* 2E2F08 003E2F08 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2E2F0C 003E2F0C 347D0F0C */  jal        func_003df4d0
    /* 2E2F10 003E2F10 3800A427 */   addiu     $4, $29, 0x38
    /* 2E2F14 003E2F14 0C000010 */  b          .L003E2F48
    /* 2E2F18 003E2F18 2D100000 */   daddu     $2, $0, $0
  .L003E2F1C:
    /* 2E2F1C 003E2F1C 88B7848F */  lw         $4, -0x4878($28)
    /* 2E2F20 003E2F20 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E2F24 003E2F24 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E2F28 003E2F28 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2E2F2C 003E2F2C FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2E2F30 003E2F30 21186400 */  addu       $3, $3, $4
    /* 2E2F34 003E2F34 0000648C */  lw         $4, 0x0($3)
    /* 2E2F38 003E2F38 09F84000 */  jalr       $2
    /* 2E2F3C 003E2F3C 2D282002 */   daddu     $5, $17, $0
    /* 2E2F40 003E2F40 ECFF0010 */  b          .L003E2EF4
    /* 2E2F44 003E2F44 00000000 */   nop
  .L003E2F48:
    /* 2E2F48 003E2F48 2000BFDF */  ld         $31, 0x20($29)
    /* 2E2F4C 003E2F4C 1000B17B */  lq         $17, 0x10($29)
    /* 2E2F50 003E2F50 0000B07B */  lq         $16, 0x0($29)
    /* 2E2F54 003E2F54 0800E003 */  jr         $31
    /* 2E2F58 003E2F58 4000BD27 */   addiu     $29, $29, 0x40
    /* 2E2F5C 003E2F5C 00000000 */  nop
.size func_003e2e40, 0x120

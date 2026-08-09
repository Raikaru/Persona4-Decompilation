.section .text
.set noat
.set noreorder
glabel func_001eba20
    /* EBA20 001EBA20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EBA24 001EBA24 1000BFFF */  sd         $31, 0x10($29)
    /* EBA28 001EBA28 0000B07F */  sq         $16, 0x0($29)
    /* EBA2C 001EBA2C 2D808000 */  daddu      $16, $4, $0
    /* EBA30 001EBA30 0800828C */  lw         $2, 0x8($4)
    /* EBA34 001EBA34 0D004014 */  bnez       $2, .L001EBA6C
    /* EBA38 001EBA38 00000000 */   nop
    /* EBA3C 001EBA3C 0000048E */  lw         $4, 0x0($16)
    /* EBA40 001EBA40 38008524 */  addiu      $5, $4, 0x38
    /* EBA44 001EBA44 0C00068E */  lw         $6, 0xC($16)
    /* EBA48 001EBA48 0400078E */  lw         $7, 0x4($16)
    /* EBA4C 001EBA4C EC7A070C */  jal        func_001debb0
    /* EBA50 001EBA50 00000000 */   nop
    /* EBA54 001EBA54 01000324 */  addiu      $3, $0, 0x1
    /* EBA58 001EBA58 0000028E */  lw         $2, 0x0($16)
    /* EBA5C 001EBA5C 680043A0 */  sb         $3, 0x68($2)
    /* EBA60 001EBA60 080003AE */  sw         $3, 0x8($16)
    /* EBA64 001EBA64 1E000010 */  b          .L001EBAE0
    /* EBA68 001EBA68 00000000 */   nop
  .L001EBA6C:
    /* EBA6C 001EBA6C 0000028E */  lw         $2, 0x0($16)
    /* EBA70 001EBA70 38005024 */  addiu      $16, $2, 0x38
    /* EBA74 001EBA74 68004290 */  lbu        $2, 0x68($2)
    /* EBA78 001EBA78 04004014 */  bnez       $2, .L001EBA8C
    /* EBA7C 001EBA7C 00000000 */   nop
    /* EBA80 001EBA80 01000224 */  addiu      $2, $0, 0x1
    /* EBA84 001EBA84 11000010 */  b          .L001EBACC
    /* EBA88 001EBA88 00000000 */   nop
  .L001EBA8C:
    /* EBA8C 001EBA8C 4C00048E */  lw         $4, 0x4C($16)
    /* EBA90 001EBA90 04008014 */  bnez       $4, .L001EBAA4
    /* EBA94 001EBA94 00000000 */   nop
    /* EBA98 001EBA98 01000224 */  addiu      $2, $0, 0x1
    /* EBA9C 001EBA9C 0B000010 */  b          .L001EBACC
    /* EBAA0 001EBAA0 00000000 */   nop
  .L001EBAA4:
    /* EBAA4 001EBAA4 2449110C */  jal        func_00452490
    /* EBAA8 001EBAA8 00000000 */   nop
    /* EBAAC 001EBAAC 06004014 */  bnez       $2, .L001EBAC8
    /* EBAB0 001EBAB0 00000000 */   nop
    /* EBAB4 001EBAB4 300000A2 */  sb         $0, 0x30($16)
    /* EBAB8 001EBAB8 4C0000AE */  sw         $0, 0x4C($16)
    /* EBABC 001EBABC 01000224 */  addiu      $2, $0, 0x1
    /* EBAC0 001EBAC0 02000010 */  b          .L001EBACC
    /* EBAC4 001EBAC4 00000000 */   nop
  .L001EBAC8:
    /* EBAC8 001EBAC8 2D100000 */  daddu      $2, $0, $0
  .L001EBACC:
    /* EBACC 001EBACC 04004010 */  beqz       $2, .L001EBAE0
    /* EBAD0 001EBAD0 00000000 */   nop
    /* EBAD4 001EBAD4 01000224 */  addiu      $2, $0, 0x1
    /* EBAD8 001EBAD8 02000010 */  b          .L001EBAE4
    /* EBADC 001EBADC 00000000 */   nop
  .L001EBAE0:
    /* EBAE0 001EBAE0 2D100000 */  daddu      $2, $0, $0
  .L001EBAE4:
    /* EBAE4 001EBAE4 1000BFDF */  ld         $31, 0x10($29)
    /* EBAE8 001EBAE8 0000B07B */  lq         $16, 0x0($29)
    /* EBAEC 001EBAEC 2000BD27 */  addiu      $29, $29, 0x20
    /* EBAF0 001EBAF0 0800E003 */  jr         $31
    /* EBAF4 001EBAF4 00000000 */   nop
    /* EBAF8 001EBAF8 00000000 */  nop
    /* EBAFC 001EBAFC 00000000 */  nop
.size func_001eba20, 0xe0

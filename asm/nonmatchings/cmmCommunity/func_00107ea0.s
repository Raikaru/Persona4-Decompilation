.section .text
.set noat
.set noreorder
glabel func_00107ea0
    /* 7EA0 00107EA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 7EA4 00107EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 7EA8 00107EA8 381C040C */  jal        func_001070e0
    /* 7EAC 00107EAC 00000000 */   nop
    /* 7EB0 00107EB0 04004014 */  bnez       $2, .L00107EC4
    /* 7EB4 00107EB4 00000000 */   nop
    /* 7EB8 00107EB8 2D100000 */  daddu      $2, $0, $0
    /* 7EBC 00107EBC 03000010 */  b          .L00107ECC
    /* 7EC0 00107EC0 00000000 */   nop
  .L00107EC4:
    /* 7EC4 00107EC4 0000428C */  lw         $2, 0x0($2)
    /* 7EC8 00107EC8 02004230 */  andi       $2, $2, 0x2
  .L00107ECC:
    /* 7ECC 00107ECC 04004010 */  beqz       $2, .L00107EE0
    /* 7ED0 00107ED0 00000000 */   nop
    /* 7ED4 00107ED4 01000224 */  addiu      $2, $0, 0x1
    /* 7ED8 00107ED8 02000010 */  b          .L00107EE4
    /* 7EDC 00107EDC 00000000 */   nop
  .L00107EE0:
    /* 7EE0 00107EE0 2D100000 */  daddu      $2, $0, $0
  .L00107EE4:
    /* 7EE4 00107EE4 0000BFDF */  ld         $31, 0x0($29)
    /* 7EE8 00107EE8 1000BD27 */  addiu      $29, $29, 0x10
    /* 7EEC 00107EEC 0800E003 */  jr         $31
    /* 7EF0 00107EF0 00000000 */   nop
    /* 7EF4 00107EF4 00000000 */  nop
    /* 7EF8 00107EF8 00000000 */  nop
    /* 7EFC 00107EFC 00000000 */  nop
.size func_00107ea0, 0x60

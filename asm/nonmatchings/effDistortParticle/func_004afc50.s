.section .text
.set noat
.set noreorder
glabel func_004afc50
    /* 3AFC50 004AFC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AFC54 004AFC54 0000BFFF */  sd         $31, 0x0($29)
    /* 3AFC58 004AFC58 5C00848C */  lw         $4, 0x5C($4)
    /* 3AFC5C 004AFC5C 03008010 */  beqz       $4, .L004AFC6C
    /* 3AFC60 004AFC60 00000000 */   nop
    /* 3AFC64 004AFC64 404B120C */  jal        func_00492d00
    /* 3AFC68 004AFC68 00000000 */   nop
  .L004AFC6C:
    /* 3AFC6C 004AFC6C 0000BFDF */  ld         $31, 0x0($29)
    /* 3AFC70 004AFC70 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AFC74 004AFC74 0800E003 */  jr         $31
    /* 3AFC78 004AFC78 00000000 */   nop
    /* 3AFC7C 004AFC7C 00000000 */  nop
.size func_004afc50, 0x30

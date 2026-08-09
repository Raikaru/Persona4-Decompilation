.section .text
.set noat
.set noreorder
glabel func_004c7e90
    /* 3C7E90 004C7E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7E94 004C7E94 7100023C */  lui        $2, %hi(D_00716720)
    /* 3C7E98 004C7E98 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7E9C 004C7E9C 20675024 */  addiu      $16, $2, %lo(D_00716720)
    /* 3C7EA0 004C7EA0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7EA4 004C7EA4 0000048E */  lw         $4, 0x0($16)
    /* 3C7EA8 004C7EA8 0F008010 */  beqz       $4, .L004C7EE8
    /* 3C7EAC 004C7EAC 7100023C */   lui       $2, %hi(D_00716724)
    /* 3C7EB0 004C7EB0 2467438C */  lw         $3, %lo(D_00716724)($2)
    /* 3C7EB4 004C7EB4 0D006204 */  bltzl      $3, .L004C7EEC
    /* 3C7EB8 004C7EB8 0000B0DF */   ld        $16, 0x0($29)
    /* 3C7EBC 004C7EBC 1626130C */  jal        func_004c9858
    /* 3C7EC0 004C7EC0 00000000 */   nop
    /* 3C7EC4 004C7EC4 01000324 */  addiu      $3, $0, 0x1
    /* 3C7EC8 004C7EC8 04004350 */  beql       $2, $3, .L004C7EDC
    /* 3C7ECC 004C7ECC 0000B0DF */   ld        $16, 0x0($29)
    /* 3C7ED0 004C7ED0 3824130C */  jal        func_004c90e0
    /* 3C7ED4 004C7ED4 0000048E */   lw        $4, 0x0($16)
    /* 3C7ED8 004C7ED8 0000B0DF */  ld         $16, 0x0($29)
  .L004C7EDC:
    /* 3C7EDC 004C7EDC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7EE0 004C7EE0 8A1F1308 */  j          func_004c7e28
    /* 3C7EE4 004C7EE4 1000BD27 */   addiu     $29, $29, 0x10
  .L004C7EE8:
    /* 3C7EE8 004C7EE8 0000B0DF */  ld         $16, 0x0($29)
  .L004C7EEC:
    /* 3C7EEC 004C7EEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7EF0 004C7EF0 0800E003 */  jr         $31
    /* 3C7EF4 004C7EF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7e90, 0x68

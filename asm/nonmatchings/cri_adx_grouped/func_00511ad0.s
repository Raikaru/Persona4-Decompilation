.section .text
.set noat
.set noreorder
glabel func_00511ad0
    /* 411AD0 00511AD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411AD4 00511AD4 0000BFFF */  sd         $31, 0x0($29)
    /* 411AD8 00511AD8 F42C140C */  jal        func_0050b3d0
    /* 411ADC 00511ADC 00000000 */   nop
    /* 411AE0 00511AE0 5000438C */  lw         $3, 0x50($2)
    /* 411AE4 00511AE4 03006010 */  beqz       $3, .L00511AF4
    /* 411AE8 00511AE8 5400448C */   lw        $4, 0x54($2)
    /* 411AEC 00511AEC 09F86000 */  jalr       $3
    /* 411AF0 00511AF0 00000000 */   nop
  .L00511AF4:
    /* 411AF4 00511AF4 0000BFDF */  ld         $31, 0x0($29)
    /* 411AF8 00511AF8 0800E003 */  jr         $31
    /* 411AFC 00511AFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511ad0, 0x30

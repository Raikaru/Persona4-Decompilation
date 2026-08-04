.section .text
.set noat
.set noreorder
glabel func_003e4ad0
    /* 2E4AD0 003E4AD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2E4AD4 003E4AD4 09008010 */  beqz       $4, .L003E4AFC
    /* 2E4AD8 003E4AD8 0000BFFF */   sd        $31, 0x0($29)
  .L003E4ADC:
    /* 2E4ADC 003E4ADC 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2E4AE0 003E4AE0 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2E4AE4 003E4AE4 09F84000 */  jalr       $2
    /* 2E4AE8 003E4AE8 00000000 */   nop
    /* 2E4AEC 003E4AEC 04004324 */  addiu      $3, $2, 0x4
    /* 2E4AF0 003E4AF0 FCFF0224 */  addiu      $2, $0, -0x4
    /* 2E4AF4 003E4AF4 04000010 */  b          .L003E4B08
    /* 2E4AF8 003E4AF8 24106200 */   and       $2, $3, $2
  .L003E4AFC:
    /* 2E4AFC 003E4AFC 7500043C */  lui        $4, %hi(D_00752FA8)
    /* 2E4B00 003E4B00 F6FF0010 */  b          .L003E4ADC
    /* 2E4B04 003E4B04 A82F8424 */   addiu     $4, $4, %lo(D_00752FA8)
  .L003E4B08:
    /* 2E4B08 003E4B08 0000BFDF */  ld         $31, 0x0($29)
    /* 2E4B0C 003E4B0C 0800E003 */  jr         $31
    /* 2E4B10 003E4B10 1000BD27 */   addiu     $29, $29, 0x10
    /* 2E4B14 003E4B14 00000000 */  nop
    /* 2E4B18 003E4B18 00000000 */  nop
    /* 2E4B1C 003E4B1C 00000000 */  nop
.size func_003e4ad0, 0x50

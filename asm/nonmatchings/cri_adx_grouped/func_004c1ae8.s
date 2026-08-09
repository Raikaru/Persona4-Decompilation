.section .text
.set noat
.set noreorder
glabel func_004c1ae8
    /* 3C1AE8 004C1AE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1AEC 004C1AEC 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1AF0 004C1AF0 C000828C */  lw         $2, 0xC0($4)
    /* 3C1AF4 004C1AF4 04004010 */  beqz       $2, .L004C1B08
    /* 3C1AF8 004C1AF8 7100023C */   lui       $2, %hi(D_00714A00)
    /* 3C1AFC 004C1AFC 004A438C */  lw         $3, %lo(D_00714A00)($2)
    /* 3C1B00 004C1B00 09F86000 */  jalr       $3
    /* 3C1B04 004C1B04 00000000 */   nop
  .L004C1B08:
    /* 3C1B08 004C1B08 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1B0C 004C1B0C 0800E003 */  jr         $31
    /* 3C1B10 004C1B10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C1B14 004C1B14 00000000 */  nop
.size func_004c1ae8, 0x30

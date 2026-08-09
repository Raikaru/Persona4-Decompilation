.section .text
.set noat
.set noreorder
glabel func_004cd1a0
    /* 3CD1A0 004CD1A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD1A4 004CD1A4 9200023C */  lui        $2, %hi(D_00922E28)
    /* 3CD1A8 004CD1A8 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD1AC 004CD1AC 282E4224 */  addiu      $2, $2, %lo(D_00922E28)
    /* 3CD1B0 004CD1B0 0000438C */  lw         $3, 0x0($2)
    /* 3CD1B4 004CD1B4 04006050 */  beql       $3, $0, .L004CD1C8
    /* 3CD1B8 004CD1B8 0000BFDF */   ld        $31, 0x0($29)
    /* 3CD1BC 004CD1BC 09F86000 */  jalr       $3
    /* 3CD1C0 004CD1C0 0400448C */   lw        $4, 0x4($2)
    /* 3CD1C4 004CD1C4 0000BFDF */  ld         $31, 0x0($29)
  .L004CD1C8:
    /* 3CD1C8 004CD1C8 0800E003 */  jr         $31
    /* 3CD1CC 004CD1CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd1a0, 0x30

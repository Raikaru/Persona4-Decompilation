.section .text
.set noat
.set noreorder
glabel func_004cf088
    /* 3CF088 004CF088 7200023C */  lui        $2, %hi(D_00721D6C)
    /* 3CF08C 004CF08C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF090 004CF090 6C1D438C */  lw         $3, %lo(D_00721D6C)($2)
    /* 3CF094 004CF094 2D288000 */  daddu      $5, $4, $0
    /* 3CF098 004CF098 04006010 */  beqz       $3, .L004CF0AC
    /* 3CF09C 004CF09C 0000BFFF */   sd        $31, 0x0($29)
    /* 3CF0A0 004CF0A0 7200023C */  lui        $2, %hi(D_00721D70)
    /* 3CF0A4 004CF0A4 09F86000 */  jalr       $3
    /* 3CF0A8 004CF0A8 701D448C */   lw        $4, %lo(D_00721D70)($2)
  .L004CF0AC:
    /* 3CF0AC 004CF0AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF0B0 004CF0B0 2D100000 */  daddu      $2, $0, $0
    /* 3CF0B4 004CF0B4 0800E003 */  jr         $31
    /* 3CF0B8 004CF0B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CF0BC 004CF0BC 00000000 */  nop
.size func_004cf088, 0x38

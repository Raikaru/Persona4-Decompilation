.section .text
.set noat
.set noreorder
glabel func_004ea798
    /* 3EA798 004EA798 7400023C */  lui        $2, %hi(D_0073978C)
    /* 3EA79C 004EA79C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA7A0 004EA7A0 8C97438C */  lw         $3, %lo(D_0073978C)($2)
    /* 3EA7A4 004EA7A4 2D288000 */  daddu      $5, $4, $0
    /* 3EA7A8 004EA7A8 04006010 */  beqz       $3, .L004EA7BC
    /* 3EA7AC 004EA7AC 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA7B0 004EA7B0 7400023C */  lui        $2, %hi(D_00739790)
    /* 3EA7B4 004EA7B4 09F86000 */  jalr       $3
    /* 3EA7B8 004EA7B8 9097448C */   lw        $4, %lo(D_00739790)($2)
  .L004EA7BC:
    /* 3EA7BC 004EA7BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA7C0 004EA7C0 0800E003 */  jr         $31
    /* 3EA7C4 004EA7C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ea798, 0x30

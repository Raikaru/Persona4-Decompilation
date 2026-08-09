.section .text
.set noat
.set noreorder
glabel func_003c4370
    /* 2C4370 003C4370 2D108000 */  daddu      $2, $4, $0
    /* 2C4374 003C4374 2D30A000 */  daddu      $6, $5, $0
    /* 2C4378 003C4378 7100043C */  lui        $4, %hi(D_0070AFF0)
    /* 2C437C 003C437C 2D284000 */  daddu      $5, $2, $0
    /* 2C4380 003C4380 308C0F08 */  j          func_003e30c0
    /* 2C4384 003C4384 F0AF8424 */   addiu     $4, $4, %lo(D_0070AFF0)
    /* 2C4388 003C4388 00000000 */  nop
    /* 2C438C 003C438C 00000000 */  nop
.size func_003c4370, 0x20

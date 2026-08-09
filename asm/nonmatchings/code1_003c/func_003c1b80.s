.section .text
.set noat
.set noreorder
glabel func_003c1b80
    /* 2C1B80 003C1B80 2D288000 */  daddu      $5, $4, $0
    /* 2C1B84 003C1B84 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2C1B88 003C1B88 0C8E0F08 */  j          func_003e3830
    /* 2C1B8C 003C1B8C 70AF8424 */   addiu     $4, $4, %lo(D_0070AF70)
.size func_003c1b80, 0x10

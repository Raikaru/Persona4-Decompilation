.section .text
.set noat
.set noreorder
glabel func_004ddd10
    /* 3DDD10 004DDD10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DDD14 004DDD14 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDD18 004DDD18 2D808000 */  daddu      $16, $4, $0
    /* 3DDD1C 004DDD1C 0800BFFF */  sd         $31, 0x8($29)
    /* 3DDD20 004DDD20 D467130C */  jal        func_004d9f50
    /* 3DDD24 004DDD24 0000048E */   lw        $4, 0x0($16)
    /* 3DDD28 004DDD28 050000A2 */  sb         $0, 0x5($16)
    /* 3DDD2C 004DDD2C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DDD30 004DDD30 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDD34 004DDD34 0800E003 */  jr         $31
    /* 3DDD38 004DDD38 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DDD3C 004DDD3C 00000000 */  nop
.size func_004ddd10, 0x30

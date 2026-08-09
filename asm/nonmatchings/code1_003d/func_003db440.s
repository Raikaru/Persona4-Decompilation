.section .text
.set noat
.set noreorder
glabel func_003db440
    /* 2DB440 003DB440 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DB444 003DB444 3E00023C */  lui        $2, %hi(func_003db480)
    /* 2DB448 003DB448 1000BFFF */  sd         $31, 0x10($29)
    /* 2DB44C 003DB44C 80B44224 */  addiu      $2, $2, %lo(func_003db480)
    /* 2DB450 003DB450 0000B07F */  sq         $16, 0x0($29)
    /* 2DB454 003DB454 2D808000 */  daddu      $16, $4, $0
    /* 2DB458 003DB458 D86C0F0C */  jal        func_003db360
    /* 2DB45C 003DB45C 1800A2AC */   sw        $2, 0x18($5)
    /* 2DB460 003DB460 2D100002 */  daddu      $2, $16, $0
    /* 2DB464 003DB464 1000BFDF */  ld         $31, 0x10($29)
    /* 2DB468 003DB468 0000B07B */  lq         $16, 0x0($29)
    /* 2DB46C 003DB46C 0800E003 */  jr         $31
    /* 2DB470 003DB470 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DB474 003DB474 00000000 */  nop
    /* 2DB478 003DB478 00000000 */  nop
    /* 2DB47C 003DB47C 00000000 */  nop
.size func_003db440, 0x40

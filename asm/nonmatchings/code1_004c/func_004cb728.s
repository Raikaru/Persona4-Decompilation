.section .text
.set noat
.set noreorder
glabel func_004cb728
    /* 3CB728 004CB728 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB72C 004CB72C 7200023C */  lui        $2, %hi(D_00719A3C)
    /* 3CB730 004CB730 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB734 004CB734 7200033C */  lui        $3, %hi(D_007199B8)
    /* 3CB738 004CB738 3C9A4224 */  addiu      $2, $2, %lo(D_00719A3C)
    /* 3CB73C 004CB73C B899658C */  lw         $5, %lo(D_007199B8)($3)
    /* 3CB740 004CB740 0000448C */  lw         $4, 0x0($2)
    /* 3CB744 004CB744 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB748 004CB748 902D1308 */  j          func_004cb640
    /* 3CB74C 004CB74C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb728, 0x28

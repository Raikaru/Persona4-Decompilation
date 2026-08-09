.section .text
.set noat
.set noreorder
glabel func_0043ed08
    /* 33ED08 0043ED08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33ED0C 0043ED0C 2D288000 */  daddu      $5, $4, $0
    /* 33ED10 0043ED10 0000BFFF */  sd         $31, 0x0($29)
    /* 33ED14 0043ED14 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33ED18 0043ED18 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33ED1C 0043ED1C 0000BFDF */  ld         $31, 0x0($29)
    /* 33ED20 0043ED20 5CF81008 */  j          func_0043e170
    /* 33ED24 0043ED24 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043ed08, 0x20

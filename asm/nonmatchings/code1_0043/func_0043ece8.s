.section .text
.set noat
.set noreorder
glabel func_0043ece8
    /* 33ECE8 0043ECE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33ECEC 0043ECEC 2D288000 */  daddu      $5, $4, $0
    /* 33ECF0 0043ECF0 0000BFFF */  sd         $31, 0x0($29)
    /* 33ECF4 0043ECF4 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33ECF8 0043ECF8 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33ECFC 0043ECFC 0000BFDF */  ld         $31, 0x0($29)
    /* 33ED00 0043ED00 E0FB1008 */  j          func_0043ef80
    /* 33ED04 0043ED04 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043ece8, 0x20

.section .text
.set noat
.set noreorder
glabel func_0044cdd0
    /* 34CDD0 0044CDD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34CDD4 0044CDD4 2D300000 */  daddu      $6, $0, $0
    /* 34CDD8 0044CDD8 0000BFFF */  sd         $31, 0x0($29)
    /* 34CDDC 0044CDDC 0000BFDF */  ld         $31, 0x0($29)
    /* 34CDE0 0044CDE0 7A331108 */  j          func_0044cde8
    /* 34CDE4 0044CDE4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0044cdd0, 0x18

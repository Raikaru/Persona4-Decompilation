.section .text
.set noat
.set noreorder
glabel func_004ca890
    /* 3CA890 004CA890 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA894 004CA894 7200023C */  lui        $2, %hi(D_007188A0)
    /* 3CA898 004CA898 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA89C 004CA89C A08840AC */  sw         $0, %lo(D_007188A0)($2)
    /* 3CA8A0 004CA8A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA8A4 004CA8A4 C8291308 */  j          func_004ca720
    /* 3CA8A8 004CA8A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CA8AC 004CA8AC 00000000 */  nop
.size func_004ca890, 0x20

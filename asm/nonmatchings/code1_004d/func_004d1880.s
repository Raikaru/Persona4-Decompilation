.section .text
.set noat
.set noreorder
glabel func_004d1880
    /* 3D1880 004D1880 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1884 004D1884 0000BFFF */  sd         $31, 0x0($29)
    /* 3D1888 004D1888 0000BFDF */  ld         $31, 0x0($29)
    /* 3D188C 004D188C 82C11308 */  j          func_004f0608
    /* 3D1890 004D1890 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1894 004D1894 00000000 */  nop
.size func_004d1880, 0x18

.section .text
.set noat
.set noreorder
glabel func_004d9050
    /* 3D9050 004D9050 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9054 004D9054 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9058 004D9058 0000BFDF */  ld         $31, 0x0($29)
    /* 3D905C 004D905C 64FD1208 */  j          func_004bf590
    /* 3D9060 004D9060 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9064 004D9064 00000000 */  nop
.size func_004d9050, 0x18

.section .text
.set noat
.set noreorder
glabel func_004f6888
    /* 3F6888 004F6888 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F688C 004F688C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6890 004F6890 0000BFDF */  ld         $31, 0x0($29)
    /* 3F6894 004F6894 78E61308 */  j          func_004f99e0
    /* 3F6898 004F6898 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F689C 004F689C 00000000 */  nop
.size func_004f6888, 0x18

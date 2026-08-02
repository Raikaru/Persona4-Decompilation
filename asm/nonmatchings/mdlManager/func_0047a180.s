.section .text
.set noat
.set noreorder
glabel func_0047a180
    /* 37A180 0047A180 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37A184 0047A184 0000BFFF */  sd         $31, 0x0($29)
    /* 37A188 0047A188 24830F0C */  jal        func_003e0c90
    /* 37A18C 0047A18C 00000000 */   nop
    /* 37A190 0047A190 0000BFDF */  ld         $31, 0x0($29)
    /* 37A194 0047A194 1000BD27 */  addiu      $29, $29, 0x10
    /* 37A198 0047A198 0800E003 */  jr         $31
    /* 37A19C 0047A19C 00000000 */   nop
.size func_0047a180, 0x20

.section .text
.set noat
.set noreorder
glabel func_004f0638
    /* 3F0638 004F0638 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F063C 004F063C 02000424 */  addiu      $4, $0, 0x2
    /* 3F0640 004F0640 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0644 004F0644 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0648 004F0648 46C11308 */  j          func_004f0518
    /* 3F064C 004F064C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0638, 0x18

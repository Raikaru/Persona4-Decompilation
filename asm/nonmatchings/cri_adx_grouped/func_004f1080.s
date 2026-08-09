.section .text
.set noat
.set noreorder
glabel func_004f1080
    /* 3F1080 004F1080 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1084 004F1084 02000424 */  addiu      $4, $0, 0x2
    /* 3F1088 004F1088 0000BFFF */  sd         $31, 0x0($29)
    /* 3F108C 004F108C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1090 004F1090 BCC31308 */  j          func_004f0ef0
    /* 3F1094 004F1094 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1080, 0x18

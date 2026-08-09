.section .text
.set noat
.set noreorder
glabel func_004f1050
    /* 3F1050 004F1050 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1054 004F1054 2D200000 */  daddu      $4, $0, $0
    /* 3F1058 004F1058 0000BFFF */  sd         $31, 0x0($29)
    /* 3F105C 004F105C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1060 004F1060 BCC31308 */  j          func_004f0ef0
    /* 3F1064 004F1064 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1050, 0x18

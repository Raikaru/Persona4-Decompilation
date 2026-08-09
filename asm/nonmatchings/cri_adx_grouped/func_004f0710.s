.section .text
.set noat
.set noreorder
glabel func_004f0710
    /* 3F0710 004F0710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0714 004F0714 E8030424 */  addiu      $4, $0, 0x3E8
    /* 3F0718 004F0718 0000BFFF */  sd         $31, 0x0($29)
    /* 3F071C 004F071C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0720 004F0720 5EC11308 */  j          func_004f0578
    /* 3F0724 004F0724 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0710, 0x18

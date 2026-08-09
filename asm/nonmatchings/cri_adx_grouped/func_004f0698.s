.section .text
.set noat
.set noreorder
glabel func_004f0698
    /* 3F0698 004F0698 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F069C 004F069C E8030424 */  addiu      $4, $0, 0x3E8
    /* 3F06A0 004F06A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3F06A4 004F06A4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F06A8 004F06A8 46C11308 */  j          func_004f0518
    /* 3F06AC 004F06AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0698, 0x18

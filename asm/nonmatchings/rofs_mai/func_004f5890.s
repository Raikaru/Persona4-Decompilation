.section .text
.set noat
.set noreorder
glabel func_004f5890
    /* 3F5890 004F5890 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F5894 004F5894 24008824 */  addiu      $8, $4, 0x24
    /* 3F5898 004F5898 0000BFFF */  sd         $31, 0x0($29)
    /* 3F589C 004F589C 08000924 */  addiu      $9, $0, 0x8
    /* 3F58A0 004F58A0 2D20A000 */  daddu      $4, $5, $0
    /* 3F58A4 004F58A4 C02A0600 */  sll        $5, $6, 11
    /* 3F58A8 004F58A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F58AC 004F58AC 00080624 */  addiu      $6, $0, 0x800
    /* 3F58B0 004F58B0 64E51308 */  j          func_004f9590
    /* 3F58B4 004F58B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f5890, 0x28

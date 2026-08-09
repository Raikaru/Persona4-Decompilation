.section .text
.set noat
.set noreorder
glabel func_004c76f8
    /* 3C76F8 004C76F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C76FC 004C76FC 7100083C */  lui        $8, %hi(D_007167C8)
    /* 3C7700 004C7700 0000BFFF */  sd         $31, 0x0($29)
    /* 3C7704 004C7704 C0FF0224 */  addiu      $2, $0, -0x40
    /* 3C7708 004C7708 C8670825 */  addiu      $8, $8, %lo(D_007167C8)
    /* 3C770C 004C770C 00080924 */  addiu      $9, $0, 0x800
    /* 3C7710 004C7710 0000BFDF */  ld         $31, 0x0($29)
    /* 3C7714 004C7714 24400201 */  and        $8, $8, $2
    /* 3C7718 004C7718 681E1308 */  j          func_004c79a0
    /* 3C771C 004C771C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c76f8, 0x28

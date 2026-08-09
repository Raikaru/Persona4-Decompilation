.section .text
.set noat
.set noreorder
glabel func_004c7818
    /* 3C7818 004C7818 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C781C 004C781C 7100083C */  lui        $8, %hi(D_007167C8)
    /* 3C7820 004C7820 0000BFFF */  sd         $31, 0x0($29)
    /* 3C7824 004C7824 C0FF0224 */  addiu      $2, $0, -0x40
    /* 3C7828 004C7828 C8670825 */  addiu      $8, $8, %lo(D_007167C8)
    /* 3C782C 004C782C 00080924 */  addiu      $9, $0, 0x800
    /* 3C7830 004C7830 0000BFDF */  ld         $31, 0x0($29)
    /* 3C7834 004C7834 24400201 */  and        $8, $8, $2
    /* 3C7838 004C7838 D01E1308 */  j          func_004c7b40
    /* 3C783C 004C783C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7818, 0x28

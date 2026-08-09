.section .text
.set noat
.set noreorder
glabel func_004c7560
    /* 3C7560 004C7560 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7564 004C7564 7100083C */  lui        $8, %hi(D_007167C8)
    /* 3C7568 004C7568 0000BFFF */  sd         $31, 0x0($29)
    /* 3C756C 004C756C C0FF0224 */  addiu      $2, $0, -0x40
    /* 3C7570 004C7570 C8670825 */  addiu      $8, $8, %lo(D_007167C8)
    /* 3C7574 004C7574 00080924 */  addiu      $9, $0, 0x800
    /* 3C7578 004C7578 0000BFDF */  ld         $31, 0x0($29)
    /* 3C757C 004C757C 24400201 */  and        $8, $8, $2
    /* 3C7580 004C7580 321E1308 */  j          func_004c78c8
    /* 3C7584 004C7584 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7560, 0x28

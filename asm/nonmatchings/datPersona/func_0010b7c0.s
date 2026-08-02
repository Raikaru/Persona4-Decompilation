.section .text
.set noat
.set noreorder
glabel func_0010b7c0
    /* B7C0 0010B7C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B7C4 0010B7C4 0000BFFF */  sd         $31, 0x0($29)
    /* B7C8 0010B7C8 7900043C */  lui        $4, %hi(D_00797F8C)
    /* B7CC 0010B7CC 8C7F8424 */  addiu      $4, $4, %lo(D_00797F8C)
    /* B7D0 0010B7D0 2D280000 */  daddu      $5, $0, $0
    /* B7D4 0010B7D4 40020624 */  addiu      $6, $0, 0x240
    /* B7D8 0010B7D8 72FE100C */  jal        func_0043f9c8
    /* B7DC 0010B7DC 00000000 */   nop
    /* B7E0 0010B7E0 0000BFDF */  ld         $31, 0x0($29)
    /* B7E4 0010B7E4 1000BD27 */  addiu      $29, $29, 0x10
    /* B7E8 0010B7E8 0800E003 */  jr         $31
    /* B7EC 0010B7EC 00000000 */   nop
.size func_0010b7c0, 0x30

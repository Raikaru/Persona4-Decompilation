.section .text
.set noat
.set noreorder
glabel func_001d79e0
    /* D79E0 001D79E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D79E4 001D79E4 0000BFFF */  sd         $31, 0x0($29)
    /* D79E8 001D79E8 00008494 */  lhu        $4, 0x0($4)
    /* D79EC 001D79EC 44CC120C */  jal        func_004b3110
    /* D79F0 001D79F0 00000000 */   nop
    /* D79F4 001D79F4 01000224 */  addiu      $2, $0, 0x1
    /* D79F8 001D79F8 0000BFDF */  ld         $31, 0x0($29)
    /* D79FC 001D79FC 1000BD27 */  addiu      $29, $29, 0x10
    /* D7A00 001D7A00 0800E003 */  jr         $31
    /* D7A04 001D7A04 00000000 */   nop
    /* D7A08 001D7A08 00000000 */  nop
    /* D7A0C 001D7A0C 00000000 */  nop
.size func_001d79e0, 0x30

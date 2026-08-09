.section .text
.set noat
.set noreorder
glabel func_001d7b30
    /* D7B30 001D7B30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D7B34 001D7B34 0000BFFF */  sd         $31, 0x0($29)
    /* D7B38 001D7B38 00008594 */  lhu        $5, 0x0($4)
    /* D7B3C 001D7B3C 01000424 */  addiu      $4, $0, 0x1
    /* D7B40 001D7B40 9089040C */  jal        func_00122640
    /* D7B44 001D7B44 00000000 */   nop
    /* D7B48 001D7B48 01000224 */  addiu      $2, $0, 0x1
    /* D7B4C 001D7B4C 0000BFDF */  ld         $31, 0x0($29)
    /* D7B50 001D7B50 1000BD27 */  addiu      $29, $29, 0x10
    /* D7B54 001D7B54 0800E003 */  jr         $31
    /* D7B58 001D7B58 00000000 */   nop
    /* D7B5C 001D7B5C 00000000 */  nop
.size func_001d7b30, 0x30

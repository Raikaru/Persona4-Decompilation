.section .text
.set noat
.set noreorder
glabel func_001d7a60
    /* D7A60 001D7A60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D7A64 001D7A64 1000BFFF */  sd         $31, 0x10($29)
    /* D7A68 001D7A68 0000B07F */  sq         $16, 0x0($29)
    /* D7A6C 001D7A6C 2D808000 */  daddu      $16, $4, $0
    /* D7A70 001D7A70 04008594 */  lhu        $5, 0x4($4)
    /* D7A74 001D7A74 01000424 */  addiu      $4, $0, 0x1
    /* D7A78 001D7A78 4889040C */  jal        func_00122520
    /* D7A7C 001D7A7C 00000000 */   nop
    /* D7A80 001D7A80 00000492 */  lbu        $4, 0x0($16)
    /* D7A84 001D7A84 01000592 */  lbu        $5, 0x1($16)
    /* D7A88 001D7A88 02000692 */  lbu        $6, 0x2($16)
    /* D7A8C 001D7A8C 288A040C */  jal        func_001228a0
    /* D7A90 001D7A90 00000000 */   nop
    /* D7A94 001D7A94 01000224 */  addiu      $2, $0, 0x1
    /* D7A98 001D7A98 1000BFDF */  ld         $31, 0x10($29)
    /* D7A9C 001D7A9C 0000B07B */  lq         $16, 0x0($29)
    /* D7AA0 001D7AA0 2000BD27 */  addiu      $29, $29, 0x20
    /* D7AA4 001D7AA4 0800E003 */  jr         $31
    /* D7AA8 001D7AA8 00000000 */   nop
    /* D7AAC 001D7AAC 00000000 */  nop
.size func_001d7a60, 0x50

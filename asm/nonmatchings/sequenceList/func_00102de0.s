.section .text
.set noat
.set noreorder
glabel func_00102de0
    /* 2DE0 00102DE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DE4 00102DE4 0000BFFF */  sd         $31, 0x0($29)
    /* 2DE8 00102DE8 C0858427 */  addiu      $4, $28, -0x7A40
    /* 2DEC 00102DEC E048110C */  jal        func_00452380
    /* 2DF0 00102DF0 00000000 */   nop
    /* 2DF4 00102DF4 2B100200 */  sltu       $2, $0, $2
    /* 2DF8 00102DF8 0000BFDF */  ld         $31, 0x0($29)
    /* 2DFC 00102DFC 1000BD27 */  addiu      $29, $29, 0x10
    /* 2E00 00102E00 0800E003 */  jr         $31
    /* 2E04 00102E04 00000000 */   nop
    /* 2E08 00102E08 00000000 */  nop
    /* 2E0C 00102E0C 00000000 */  nop
.size func_00102de0, 0x30

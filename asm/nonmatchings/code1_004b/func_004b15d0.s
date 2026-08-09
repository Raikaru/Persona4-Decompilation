.section .text
.set noat
.set noreorder
glabel func_004b15d0
    /* 3B15D0 004B15D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B15D4 004B15D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3B15D8 004B15D8 949E120C */  jal        func_004a7a50
    /* 3B15DC 004B15DC 00000000 */   nop
    /* 3B15E0 004B15E0 98BB80AF */  sw         $0, -0x4468($28)
    /* 3B15E4 004B15E4 0000BFDF */  ld         $31, 0x0($29)
    /* 3B15E8 004B15E8 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B15EC 004B15EC 0800E003 */  jr         $31
    /* 3B15F0 004B15F0 00000000 */   nop
    /* 3B15F4 004B15F4 00000000 */  nop
    /* 3B15F8 004B15F8 00000000 */  nop
    /* 3B15FC 004B15FC 00000000 */  nop
.size func_004b15d0, 0x30

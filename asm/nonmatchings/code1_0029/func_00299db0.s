.section .text
.set noat
.set noreorder
glabel func_00299db0
    /* 199DB0 00299DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 199DB4 00299DB4 0000BFFF */  sd         $31, 0x0($29)
    /* 199DB8 00299DB8 2D200000 */  daddu      $4, $0, $0
    /* 199DBC 00299DBC 00730A0C */  jal        func_0029cc00
    /* 199DC0 00299DC0 00000000 */   nop
    /* 199DC4 00299DC4 3C240200 */  dsll32     $4, $2, 16
    /* 199DC8 00299DC8 3F240400 */  dsra32     $4, $4, 16
    /* 199DCC 00299DCC 8C13040C */  jal        func_00104e30
    /* 199DD0 00299DD0 00000000 */   nop
    /* 199DD4 00299DD4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 199DD8 00299DD8 D4730A0C */  jal        func_0029cf50
    /* 199DDC 00299DDC 00000000 */   nop
    /* 199DE0 00299DE0 01000224 */  addiu      $2, $0, 0x1
    /* 199DE4 00299DE4 0000BFDF */  ld         $31, 0x0($29)
    /* 199DE8 00299DE8 1000BD27 */  addiu      $29, $29, 0x10
    /* 199DEC 00299DEC 0800E003 */  jr         $31
    /* 199DF0 00299DF0 00000000 */   nop
    /* 199DF4 00299DF4 00000000 */  nop
    /* 199DF8 00299DF8 00000000 */  nop
    /* 199DFC 00299DFC 00000000 */  nop
.size func_00299db0, 0x50

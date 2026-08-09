.section .text
.set noat
.set noreorder
glabel func_0022b0e0
    /* 12B0E0 0022B0E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12B0E4 0022B0E4 0000BFFF */  sd         $31, 0x0($29)
    /* 12B0E8 0022B0E8 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12B0EC 0022B0EC 0C00428C */  lw         $2, 0xC($2)
    /* 12B0F0 0022B0F0 40004230 */  andi       $2, $2, 0x40
    /* 12B0F4 0022B0F4 05004010 */  beqz       $2, .L0022B10C
    /* 12B0F8 0022B0F8 00000000 */   nop
    /* 12B0FC 0022B0FC 06000424 */  addiu      $4, $0, 0x6
    /* 12B100 0022B100 01000524 */  addiu      $5, $0, 0x1
    /* 12B104 0022B104 F868110C */  jal        func_0045a3e0
    /* 12B108 0022B108 00000000 */   nop
  .L0022B10C:
    /* 12B10C 0022B10C 01000224 */  addiu      $2, $0, 0x1
    /* 12B110 0022B110 0000BFDF */  ld         $31, 0x0($29)
    /* 12B114 0022B114 1000BD27 */  addiu      $29, $29, 0x10
    /* 12B118 0022B118 0800E003 */  jr         $31
    /* 12B11C 0022B11C 00000000 */   nop
.size func_0022b0e0, 0x40

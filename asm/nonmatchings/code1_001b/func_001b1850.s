.section .text
.set noat
.set noreorder
glabel func_001b1850
    /* B1850 001B1850 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B1854 001B1854 0000BFFF */  sd         $31, 0x0($29)
    /* B1858 001B1858 ACB3828F */  lw         $2, -0x4C54($28)
    /* B185C 001B185C 90024424 */  addiu      $4, $2, 0x290
    /* B1860 001B1860 2D280000 */  daddu      $5, $0, $0
    /* B1864 001B1864 6C000624 */  addiu      $6, $0, 0x6C
    /* B1868 001B1868 72FE100C */  jal        func_0043f9c8
    /* B186C 001B186C 00000000 */   nop
    /* B1870 001B1870 0000BFDF */  ld         $31, 0x0($29)
    /* B1874 001B1874 1000BD27 */  addiu      $29, $29, 0x10
    /* B1878 001B1878 0800E003 */  jr         $31
    /* B187C 001B187C 00000000 */   nop
.size func_001b1850, 0x30

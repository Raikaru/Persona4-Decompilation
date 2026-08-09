.section .text
.set noat
.set noreorder
glabel func_001b1880
    /* B1880 001B1880 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B1884 001B1884 0000BFFF */  sd         $31, 0x0($29)
    /* B1888 001B1888 ACB3828F */  lw         $2, -0x4C54($28)
    /* B188C 001B188C 900240A4 */  sh         $0, 0x290($2)
    /* B1890 001B1890 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1894 001B1894 980240AC */  sw         $0, 0x298($2)
    /* B1898 001B1898 ACB3828F */  lw         $2, -0x4C54($28)
    /* B189C 001B189C CC024424 */  addiu      $4, $2, 0x2CC
    /* B18A0 001B18A0 2D280000 */  daddu      $5, $0, $0
    /* B18A4 001B18A4 30000624 */  addiu      $6, $0, 0x30
    /* B18A8 001B18A8 72FE100C */  jal        func_0043f9c8
    /* B18AC 001B18AC 00000000 */   nop
    /* B18B0 001B18B0 0000BFDF */  ld         $31, 0x0($29)
    /* B18B4 001B18B4 1000BD27 */  addiu      $29, $29, 0x10
    /* B18B8 001B18B8 0800E003 */  jr         $31
    /* B18BC 001B18BC 00000000 */   nop
.size func_001b1880, 0x40

.section .text
.set noat
.set noreorder
glabel func_001fe010
    /* FE010 001FE010 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FE014 001FE014 0000BFFF */  sd         $31, 0x0($29)
    /* FE018 001FE018 6200043C */  lui        $4, %hi(D_00625230)
    /* FE01C 001FE01C 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FE020 001FE020 DF020524 */  addiu      $5, $0, 0x2DF
    /* FE024 001FE024 A43A110C */  jal        func_0044ea90
    /* FE028 001FE028 00000000 */   nop
    /* FE02C 001FE02C 20000424 */  addiu      $4, $0, 0x20
    /* FE030 001FE030 0400053C */  lui        $5, (0x40000 >> 16)
    /* FE034 001FE034 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FE038 001FE038 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FE03C 001FE03C 09F84000 */  jalr       $2
    /* FE040 001FE040 00000000 */   nop
    /* FE044 001FE044 0000BFDF */  ld         $31, 0x0($29)
    /* FE048 001FE048 1000BD27 */  addiu      $29, $29, 0x10
    /* FE04C 001FE04C 0800E003 */  jr         $31
    /* FE050 001FE050 00000000 */   nop
    /* FE054 001FE054 00000000 */  nop
    /* FE058 001FE058 00000000 */  nop
    /* FE05C 001FE05C 00000000 */  nop
.size func_001fe010, 0x50

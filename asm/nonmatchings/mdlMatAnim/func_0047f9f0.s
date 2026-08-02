.section .text
.set noat
.set noreorder
glabel func_0047f9f0
    /* 37F9F0 0047F9F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 37F9F4 0047F9F4 1000BFFF */  sd         $31, 0x10($29)
    /* 37F9F8 0047F9F8 0000B07F */  sq         $16, 0x0($29)
    /* 37F9FC 0047F9FC 7100043C */  lui        $4, %hi(D_00713260)
    /* 37FA00 0047FA00 60328424 */  addiu      $4, $4, %lo(D_00713260)
    /* 37FA04 0047FA04 2C020524 */  addiu      $5, $0, 0x22C
    /* 37FA08 0047FA08 A43A110C */  jal        func_0044ea90
    /* 37FA0C 0047FA0C 00000000 */   nop
    /* 37FA10 0047FA10 04000424 */  addiu      $4, $0, 0x4
    /* 37FA14 0047FA14 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37FA18 0047FA18 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 37FA1C 0047FA1C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 37FA20 0047FA20 09F84000 */  jalr       $2
    /* 37FA24 0047FA24 00000000 */   nop
    /* 37FA28 0047FA28 2D804000 */  daddu      $16, $2, $0
    /* 37FA2C 0047FA2C 2D200002 */  daddu      $4, $16, $0
    /* 37FA30 0047FA30 2D280000 */  daddu      $5, $0, $0
    /* 37FA34 0047FA34 04000624 */  addiu      $6, $0, 0x4
    /* 37FA38 0047FA38 72FE100C */  jal        func_0043f9c8
    /* 37FA3C 0047FA3C 00000000 */   nop
    /* 37FA40 0047FA40 000000AE */  sw         $0, 0x0($16)
    /* 37FA44 0047FA44 2D100002 */  daddu      $2, $16, $0
    /* 37FA48 0047FA48 1000BFDF */  ld         $31, 0x10($29)
    /* 37FA4C 0047FA4C 0000B07B */  lq         $16, 0x0($29)
    /* 37FA50 0047FA50 2000BD27 */  addiu      $29, $29, 0x20
    /* 37FA54 0047FA54 0800E003 */  jr         $31
    /* 37FA58 0047FA58 00000000 */   nop
    /* 37FA5C 0047FA5C 00000000 */  nop
.size func_0047f9f0, 0x70

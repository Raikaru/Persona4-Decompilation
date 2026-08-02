.section .text
.set noat
.set noreorder
glabel func_0047d1a0
    /* 37D1A0 0047D1A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 37D1A4 0047D1A4 1000BFFF */  sd         $31, 0x10($29)
    /* 37D1A8 0047D1A8 0000B07F */  sq         $16, 0x0($29)
    /* 37D1AC 0047D1AC 7100043C */  lui        $4, %hi(D_007131E8)
    /* 37D1B0 0047D1B0 E8318424 */  addiu      $4, $4, %lo(D_007131E8)
    /* 37D1B4 0047D1B4 2D000524 */  addiu      $5, $0, 0x2D
    /* 37D1B8 0047D1B8 A43A110C */  jal        func_0044ea90
    /* 37D1BC 0047D1BC 00000000 */   nop
    /* 37D1C0 0047D1C0 04000424 */  addiu      $4, $0, 0x4
    /* 37D1C4 0047D1C4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37D1C8 0047D1C8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 37D1CC 0047D1CC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 37D1D0 0047D1D0 09F84000 */  jalr       $2
    /* 37D1D4 0047D1D4 00000000 */   nop
    /* 37D1D8 0047D1D8 2D804000 */  daddu      $16, $2, $0
    /* 37D1DC 0047D1DC 2D200002 */  daddu      $4, $16, $0
    /* 37D1E0 0047D1E0 C4F4110C */  jal        func_0047d310
    /* 37D1E4 0047D1E4 00000000 */   nop
    /* 37D1E8 0047D1E8 2D100002 */  daddu      $2, $16, $0
    /* 37D1EC 0047D1EC 1000BFDF */  ld         $31, 0x10($29)
    /* 37D1F0 0047D1F0 0000B07B */  lq         $16, 0x0($29)
    /* 37D1F4 0047D1F4 2000BD27 */  addiu      $29, $29, 0x20
    /* 37D1F8 0047D1F8 0800E003 */  jr         $31
    /* 37D1FC 0047D1FC 00000000 */   nop
.size func_0047d1a0, 0x60

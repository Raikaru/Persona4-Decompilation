.section .text
.set noat
.set noreorder
glabel func_0047dc30
    /* 37DC30 0047DC30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 37DC34 0047DC34 2000BFFF */  sd         $31, 0x20($29)
    /* 37DC38 0047DC38 1000B17F */  sq         $17, 0x10($29)
    /* 37DC3C 0047DC3C 0000B07F */  sq         $16, 0x0($29)
    /* 37DC40 0047DC40 2D888000 */  daddu      $17, $4, $0
    /* 37DC44 0047DC44 7100043C */  lui        $4, %hi(D_007131E8)
    /* 37DC48 0047DC48 E8318424 */  addiu      $4, $4, %lo(D_007131E8)
    /* 37DC4C 0047DC4C 7C010524 */  addiu      $5, $0, 0x17C
    /* 37DC50 0047DC50 A43A110C */  jal        func_0044ea90
    /* 37DC54 0047DC54 00000000 */   nop
    /* 37DC58 0047DC58 08000424 */  addiu      $4, $0, 0x8
    /* 37DC5C 0047DC5C 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37DC60 0047DC60 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 37DC64 0047DC64 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 37DC68 0047DC68 09F84000 */  jalr       $2
    /* 37DC6C 0047DC6C 00000000 */   nop
    /* 37DC70 0047DC70 2D804000 */  daddu      $16, $2, $0
    /* 37DC74 0047DC74 2D200002 */  daddu      $4, $16, $0
    /* 37DC78 0047DC78 2D280000 */  daddu      $5, $0, $0
    /* 37DC7C 0047DC7C 08000624 */  addiu      $6, $0, 0x8
    /* 37DC80 0047DC80 72FE100C */  jal        func_0043f9c8
    /* 37DC84 0047DC84 00000000 */   nop
    /* 37DC88 0047DC88 0000238E */  lw         $3, 0x0($17)
    /* 37DC8C 0047DC8C 000003AE */  sw         $3, 0x0($16)
    /* 37DC90 0047DC90 0400628C */  lw         $2, 0x4($3)
    /* 37DC94 0047DC94 01004224 */  addiu      $2, $2, 0x1
    /* 37DC98 0047DC98 040062AC */  sw         $2, 0x4($3)
    /* 37DC9C 0047DC9C 2D100002 */  daddu      $2, $16, $0
    /* 37DCA0 0047DCA0 2000BFDF */  ld         $31, 0x20($29)
    /* 37DCA4 0047DCA4 1000B17B */  lq         $17, 0x10($29)
    /* 37DCA8 0047DCA8 0000B07B */  lq         $16, 0x0($29)
    /* 37DCAC 0047DCAC 3000BD27 */  addiu      $29, $29, 0x30
    /* 37DCB0 0047DCB0 0800E003 */  jr         $31
    /* 37DCB4 0047DCB4 00000000 */   nop
    /* 37DCB8 0047DCB8 00000000 */  nop
    /* 37DCBC 0047DCBC 00000000 */  nop
.size func_0047dc30, 0x90

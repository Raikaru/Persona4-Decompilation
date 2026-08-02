.section .text
.set noat
.set noreorder
glabel func_004af680
    /* 3AF680 004AF680 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AF684 004AF684 2000BFFF */  sd         $31, 0x20($29)
    /* 3AF688 004AF688 1000B17F */  sq         $17, 0x10($29)
    /* 3AF68C 004AF68C 0000B07F */  sq         $16, 0x0($29)
    /* 3AF690 004AF690 2D888000 */  daddu      $17, $4, $0
    /* 3AF694 004AF694 7100043C */  lui        $4, %hi(D_00714538)
    /* 3AF698 004AF698 38458424 */  addiu      $4, $4, %lo(D_00714538)
    /* 3AF69C 004AF69C 71010524 */  addiu      $5, $0, 0x171
    /* 3AF6A0 004AF6A0 A43A110C */  jal        func_0044ea90
    /* 3AF6A4 004AF6A4 00000000 */   nop
    /* 3AF6A8 004AF6A8 9C000424 */  addiu      $4, $0, 0x9C
    /* 3AF6AC 004AF6AC 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AF6B0 004AF6B0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AF6B4 004AF6B4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AF6B8 004AF6B8 09F84000 */  jalr       $2
    /* 3AF6BC 004AF6BC 00000000 */   nop
    /* 3AF6C0 004AF6C0 2D804000 */  daddu      $16, $2, $0
    /* 3AF6C4 004AF6C4 2D200002 */  daddu      $4, $16, $0
    /* 3AF6C8 004AF6C8 2D280000 */  daddu      $5, $0, $0
    /* 3AF6CC 004AF6CC 9C000624 */  addiu      $6, $0, 0x9C
    /* 3AF6D0 004AF6D0 72FE100C */  jal        func_0043f9c8
    /* 3AF6D4 004AF6D4 00000000 */   nop
    /* 3AF6D8 004AF6D8 06000016 */  bnez       $16, .L004AF6F4
    /* 3AF6DC 004AF6DC 00000000 */   nop
    /* 3AF6E0 004AF6E0 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AF6E4 004AF6E4 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AF6E8 004AF6E8 2F000524 */  addiu      $5, $0, 0x2F
    /* 3AF6EC 004AF6EC CCB5110C */  jal        func_0046d730
    /* 3AF6F0 004AF6F0 00000000 */   nop
  .L004AF6F4:
    /* 3AF6F4 004AF6F4 000011AE */  sw         $17, 0x0($16)
    /* 3AF6F8 004AF6F8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3AF6FC 004AF6FC 040002AE */  sw         $2, 0x4($16)
    /* 3AF700 004AF700 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AF704 004AF704 080002AE */  sw         $2, 0x8($16)
    /* 3AF708 004AF708 540000AE */  sw         $0, 0x54($16)
    /* 3AF70C 004AF70C 580000AE */  sw         $0, 0x58($16)
    /* 3AF710 004AF710 1A000224 */  addiu      $2, $0, 0x1A
    /* 3AF714 004AF714 840002A6 */  sh         $2, 0x84($16)
    /* 3AF718 004AF718 880010AE */  sw         $16, 0x88($16)
    /* 3AF71C 004AF71C 2D100002 */  daddu      $2, $16, $0
    /* 3AF720 004AF720 2000BFDF */  ld         $31, 0x20($29)
    /* 3AF724 004AF724 1000B17B */  lq         $17, 0x10($29)
    /* 3AF728 004AF728 0000B07B */  lq         $16, 0x0($29)
    /* 3AF72C 004AF72C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AF730 004AF730 0800E003 */  jr         $31
    /* 3AF734 004AF734 00000000 */   nop
    /* 3AF738 004AF738 00000000 */  nop
    /* 3AF73C 004AF73C 00000000 */  nop
.size func_004af680, 0xc0

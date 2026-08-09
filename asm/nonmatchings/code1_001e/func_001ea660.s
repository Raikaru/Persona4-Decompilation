.section .text
.set noat
.set noreorder
glabel func_001ea660
    /* EA660 001EA660 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EA664 001EA664 0000BFFF */  sd         $31, 0x0($29)
    /* EA668 001EA668 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA66C 001EA66C 7001448C */  lw         $4, 0x170($2)
    /* EA670 001EA670 EC80060C */  jal        func_001a03b0
    /* EA674 001EA674 00000000 */   nop
    /* EA678 001EA678 03000424 */  addiu      $4, $0, 0x3
    /* EA67C 001EA67C FF0F0524 */  addiu      $5, $0, 0xFFF
    /* EA680 001EA680 C04D070C */  jal        func_001d3700
    /* EA684 001EA684 00000000 */   nop
    /* EA688 001EA688 2D204000 */  daddu      $4, $2, $0
    /* EA68C 001EA68C 2D280000 */  daddu      $5, $0, $0
    /* EA690 001EA690 6451060C */  jal        func_00194590
    /* EA694 001EA694 00000000 */   nop
    /* EA698 001EA698 2D200000 */  daddu      $4, $0, $0
    /* EA69C 001EA69C 54730A0C */  jal        func_0029cd50
    /* EA6A0 001EA6A0 00000000 */   nop
    /* EA6A4 001EA6A4 4000A0E7 */  swc1       $f0, 0x40($29)
    /* EA6A8 001EA6A8 01000424 */  addiu      $4, $0, 0x1
    /* EA6AC 001EA6AC 54730A0C */  jal        func_0029cd50
    /* EA6B0 001EA6B0 00000000 */   nop
    /* EA6B4 001EA6B4 4400A0E7 */  swc1       $f0, 0x44($29)
    /* EA6B8 001EA6B8 02000424 */  addiu      $4, $0, 0x2
    /* EA6BC 001EA6BC 54730A0C */  jal        func_0029cd50
    /* EA6C0 001EA6C0 00000000 */   nop
    /* EA6C4 001EA6C4 4800A0E7 */  swc1       $f0, 0x48($29)
    /* EA6C8 001EA6C8 03000424 */  addiu      $4, $0, 0x3
    /* EA6CC 001EA6CC 54730A0C */  jal        func_0029cd50
    /* EA6D0 001EA6D0 00000000 */   nop
    /* EA6D4 001EA6D4 2000A0E7 */  swc1       $f0, 0x20($29)
    /* EA6D8 001EA6D8 04000424 */  addiu      $4, $0, 0x4
    /* EA6DC 001EA6DC 54730A0C */  jal        func_0029cd50
    /* EA6E0 001EA6E0 00000000 */   nop
    /* EA6E4 001EA6E4 2400A0E7 */  swc1       $f0, 0x24($29)
    /* EA6E8 001EA6E8 05000424 */  addiu      $4, $0, 0x5
    /* EA6EC 001EA6EC 54730A0C */  jal        func_0029cd50
    /* EA6F0 001EA6F0 00000000 */   nop
    /* EA6F4 001EA6F4 2800A0E7 */  swc1       $f0, 0x28($29)
    /* EA6F8 001EA6F8 06000424 */  addiu      $4, $0, 0x6
    /* EA6FC 001EA6FC 54730A0C */  jal        func_0029cd50
    /* EA700 001EA700 00000000 */   nop
    /* EA704 001EA704 4000A527 */  addiu      $5, $29, 0x40
    /* EA708 001EA708 3000A727 */  addiu      $7, $29, 0x30
    /* EA70C 001EA70C 4000A2DF */  ld         $2, 0x40($29)
    /* EA710 001EA710 4800A1C7 */  lwc1       $f1, 0x48($29)
    /* EA714 001EA714 3000A2FF */  sd         $2, 0x30($29)
    /* EA718 001EA718 3800A1E7 */  swc1       $f1, 0x38($29)
    /* EA71C 001EA71C 2000A627 */  addiu      $6, $29, 0x20
    /* EA720 001EA720 1000A827 */  addiu      $8, $29, 0x10
    /* EA724 001EA724 2000A2DF */  ld         $2, 0x20($29)
    /* EA728 001EA728 2800A1C7 */  lwc1       $f1, 0x28($29)
    /* EA72C 001EA72C 1000A2FF */  sd         $2, 0x10($29)
    /* EA730 001EA730 1800A1E7 */  swc1       $f1, 0x18($29)
    /* EA734 001EA734 ACB3838F */  lw         $3, -0x4C54($28)
    /* EA738 001EA738 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* EA73C 001EA73C 00708244 */  mtc1       $2, $f14
    /* EA740 001EA740 7001648C */  lw         $4, 0x170($3)
    /* EA744 001EA744 06030046 */  mov.s      $f12, $f0
    /* EA748 001EA748 46030046 */  mov.s      $f13, $f0
    /* EA74C 001EA74C D4F2060C */  jal        func_001bcb50
    /* EA750 001EA750 00000000 */   nop
    /* EA754 001EA754 2D204000 */  daddu      $4, $2, $0
    /* EA758 001EA758 2D280000 */  daddu      $5, $0, $0
    /* EA75C 001EA75C 6451060C */  jal        func_00194590
    /* EA760 001EA760 00000000 */   nop
    /* EA764 001EA764 01000224 */  addiu      $2, $0, 0x1
    /* EA768 001EA768 0000BFDF */  ld         $31, 0x0($29)
    /* EA76C 001EA76C 5000BD27 */  addiu      $29, $29, 0x50
    /* EA770 001EA770 0800E003 */  jr         $31
    /* EA774 001EA774 00000000 */   nop
    /* EA778 001EA778 00000000 */  nop
    /* EA77C 001EA77C 00000000 */  nop
.size func_001ea660, 0x120

.section .text
.set noat
.set noreorder
glabel func_004eb6d0
    /* 3EB6D0 004EB6D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EB6D4 004EB6D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3EB6D8 004EB6D8 7400123C */  lui        $18, %hi(D_0073A740)
    /* 3EB6DC 004EB6DC 40A7428E */  lw         $2, %lo(D_0073A740)($18)
    /* 3EB6E0 004EB6E0 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB6E4 004EB6E4 2D880000 */  daddu      $17, $0, $0
    /* 3EB6E8 004EB6E8 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB6EC 004EB6EC 1E004018 */  blez       $2, .L004EB768
    /* 3EB6F0 004EB6F0 1800BFFF */   sd        $31, 0x18($29)
    /* 3EB6F4 004EB6F4 7400023C */  lui        $2, %hi(D_0073A7A0)
    /* 3EB6F8 004EB6F8 A0A75024 */  addiu      $16, $2, %lo(D_0073A7A0)
    /* 3EB6FC 004EB6FC 0400028E */  lw         $2, 0x4($16)
  .L004EB700:
    /* 3EB700 004EB700 03004010 */  beqz       $2, .L004EB710
    /* 3EB704 004EB704 2D204000 */   daddu     $4, $2, $0
    /* 3EB708 004EB708 32BF130C */  jal        func_004efcc8
    /* 3EB70C 004EB70C 00000000 */   nop
  .L004EB710:
    /* 3EB710 004EB710 0800028E */  lw         $2, 0x8($16)
    /* 3EB714 004EB714 05004010 */  beqz       $2, .L004EB72C
    /* 3EB718 004EB718 2D204000 */   daddu     $4, $2, $0
    /* 3EB71C 004EB71C 0000428C */  lw         $2, 0x0($2)
    /* 3EB720 004EB720 0C00438C */  lw         $3, 0xC($2)
    /* 3EB724 004EB724 09F86000 */  jalr       $3
    /* 3EB728 004EB728 00000000 */   nop
  .L004EB72C:
    /* 3EB72C 004EB72C 0C00048E */  lw         $4, 0xC($16)
    /* 3EB730 004EB730 04008050 */  beql       $4, $0, .L004EB744
    /* 3EB734 004EB734 2D200002 */   daddu     $4, $16, $0
    /* 3EB738 004EB738 30C1130C */  jal        func_004f04c0
    /* 3EB73C 004EB73C 00000000 */   nop
    /* 3EB740 004EB740 2D200002 */  daddu      $4, $16, $0
  .L004EB744:
    /* 3EB744 004EB744 18001026 */  addiu      $16, $16, 0x18
    /* 3EB748 004EB748 2D280000 */  daddu      $5, $0, $0
    /* 3EB74C 004EB74C 72FE100C */  jal        func_0043f9c8
    /* 3EB750 004EB750 18000624 */   addiu     $6, $0, 0x18
    /* 3EB754 004EB754 40A7438E */  lw         $3, %lo(D_0073A740)($18)
    /* 3EB758 004EB758 01003126 */  addiu      $17, $17, 0x1
    /* 3EB75C 004EB75C 2A182302 */  slt        $3, $17, $3
    /* 3EB760 004EB760 E7FF6054 */  bnel       $3, $0, .L004EB700
    /* 3EB764 004EB764 0400028E */   lw        $2, 0x4($16)
  .L004EB768:
    /* 3EB768 004EB768 7400023C */  lui        $2, %hi(D_0073A754)
    /* 3EB76C 004EB76C 01000424 */  addiu      $4, $0, 0x1
    /* 3EB770 004EB770 54A75124 */  addiu      $17, $2, %lo(D_0073A754)
    /* 3EB774 004EB774 00002382 */  lb         $3, 0x0($17)
    /* 3EB778 004EB778 08006414 */  bne        $3, $4, .L004EB79C
    /* 3EB77C 004EB77C 0000B0DF */   ld        $16, 0x0($29)
    /* 3EB780 004EB780 7400103C */  lui        $16, %hi(D_0073A74C)
    /* 3EB784 004EB784 4CA71026 */  addiu      $16, $16, %lo(D_0073A74C)
    /* 3EB788 004EB788 82A7100C */  jal        func_00429e08
    /* 3EB78C 004EB78C 0000048E */   lw        $4, 0x0($16)
    /* 3EB790 004EB790 000000AE */  sw         $0, 0x0($16)
    /* 3EB794 004EB794 000020A2 */  sb         $0, 0x0($17)
    /* 3EB798 004EB798 0000B0DF */  ld         $16, 0x0($29)
  .L004EB79C:
    /* 3EB79C 004EB79C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB7A0 004EB7A0 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB7A4 004EB7A4 1800BFDF */  ld         $31, 0x18($29)
    /* 3EB7A8 004EB7A8 0800E003 */  jr         $31
    /* 3EB7AC 004EB7AC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004eb6d0, 0xe0

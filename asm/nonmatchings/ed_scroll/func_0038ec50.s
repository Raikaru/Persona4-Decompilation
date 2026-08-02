.section .text
.set noat
.set noreorder
glabel func_0038ec50
    /* 28EC50 0038EC50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28EC54 0038EC54 1000BFFF */  sd         $31, 0x10($29)
    /* 28EC58 0038EC58 0000B07F */  sq         $16, 0x0($29)
    /* 28EC5C 0038EC5C B0B5828F */  lw         $2, -0x4A50($28)
    /* 28EC60 0038EC60 06004014 */  bnez       $2, .L0038EC7C
    /* 28EC64 0038EC64 00000000 */   nop
    /* 28EC68 0038EC68 6500043C */  lui        $4, %hi(D_0064F220)
    /* 28EC6C 0038EC6C 20F28424 */  addiu      $4, $4, %lo(D_0064F220)
    /* 28EC70 0038EC70 6B000524 */  addiu      $5, $0, 0x6B
    /* 28EC74 0038EC74 CCB5110C */  jal        func_0046d730
    /* 28EC78 0038EC78 00000000 */   nop
  .L0038EC7C:
    /* 28EC7C 0038EC7C B0B5908F */  lw         $16, -0x4A50($28)
    /* 28EC80 0038EC80 543E0E0C */  jal        func_0038f950
    /* 28EC84 0038EC84 00000000 */   nop
    /* 28EC88 0038EC88 2D204000 */  daddu      $4, $2, $0
    /* 28EC8C 0038EC8C 783D0E0C */  jal        func_0038f5e0
    /* 28EC90 0038EC90 00000000 */   nop
    /* 28EC94 0038EC94 0C12038E */  lw         $3, 0x120C($16)
    /* 28EC98 0038EC98 21104300 */  addu       $2, $2, $3
    /* 28EC9C 0038EC9C 00004290 */  lbu        $2, 0x0($2)
    /* 28ECA0 0038ECA0 1000BFDF */  ld         $31, 0x10($29)
    /* 28ECA4 0038ECA4 0000B07B */  lq         $16, 0x0($29)
    /* 28ECA8 0038ECA8 2000BD27 */  addiu      $29, $29, 0x20
    /* 28ECAC 0038ECAC 0800E003 */  jr         $31
    /* 28ECB0 0038ECB0 00000000 */   nop
    /* 28ECB4 0038ECB4 00000000 */  nop
    /* 28ECB8 0038ECB8 00000000 */  nop
    /* 28ECBC 0038ECBC 00000000 */  nop
.size func_0038ec50, 0x70

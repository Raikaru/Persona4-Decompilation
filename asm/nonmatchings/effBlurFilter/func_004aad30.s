.section .text
.set noat
.set noreorder
glabel func_004aad30
    /* 3AAD30 004AAD30 B0FDBD27 */  addiu      $29, $29, -0x250
    /* 3AAD34 004AAD34 3000BFFF */  sd         $31, 0x30($29)
    /* 3AAD38 004AAD38 2000B27F */  sq         $18, 0x20($29)
    /* 3AAD3C 004AAD3C 1000B17F */  sq         $17, 0x10($29)
    /* 3AAD40 004AAD40 0000B07F */  sq         $16, 0x0($29)
    /* 3AAD44 004AAD44 2400838C */  lw         $3, 0x24($4)
    /* 3AAD48 004AAD48 C0007224 */  addiu      $18, $3, 0xC0
    /* 3AAD4C 004AAD4C CF006390 */  lbu        $3, 0xCF($3)
    /* 3AAD50 004AAD50 5B006018 */  blez       $3, .L004AAEC0
    /* 3AAD54 004AAD54 00000000 */   nop
    /* 3AAD58 004AAD58 2800828C */  lw         $2, 0x28($4)
    /* 3AAD5C 004AAD5C 0800508C */  lw         $16, 0x8($2)
    /* 3AAD60 004AAD60 02000424 */  addiu      $4, $0, 0x2
    /* 3AAD64 004AAD64 4C02A527 */  addiu      $5, $29, 0x24C
    /* 3AAD68 004AAD68 A4D90F0C */  jal        func_003f6690
    /* 3AAD6C 004AAD6C 00000000 */   nop
    /* 3AAD70 004AAD70 03000424 */  addiu      $4, $0, 0x3
    /* 3AAD74 004AAD74 4802A527 */  addiu      $5, $29, 0x248
    /* 3AAD78 004AAD78 A4D90F0C */  jal        func_003f6690
    /* 3AAD7C 004AAD7C 00000000 */   nop
    /* 3AAD80 004AAD80 8800113C */  lui        $17, %hi(D_00887300)
    /* 3AAD84 004AAD84 00733126 */  addiu      $17, $17, %lo(D_00887300)
    /* 3AAD88 004AAD88 01000424 */  addiu      $4, $0, 0x1
    /* 3AAD8C 004AAD8C 0000058E */  lw         $5, 0x0($16)
    /* 3AAD90 004AAD90 0000228E */  lw         $2, 0x0($17)
    /* 3AAD94 004AAD94 09F84000 */  jalr       $2
    /* 3AAD98 004AAD98 00000000 */   nop
    /* 3AAD9C 004AAD9C E027120C */  jal        func_00489f80
    /* 3AADA0 004AADA0 00000000 */   nop
    /* 3AADA4 004AADA4 02000424 */  addiu      $4, $0, 0x2
    /* 3AADA8 004AADA8 44000524 */  addiu      $5, $0, 0x44
    /* 3AADAC 004AADAC 10D90F0C */  jal        func_003f6440
    /* 3AADB0 004AADB0 00000000 */   nop
    /* 3AADB4 004AADB4 03000424 */  addiu      $4, $0, 0x3
    /* 3AADB8 004AADB8 0300023C */  lui        $2, (0x31001 >> 16)
    /* 3AADBC 004AADBC 01104534 */  ori        $5, $2, (0x31001 & 0xFFFF)
    /* 3AADC0 004AADC0 10D90F0C */  jal        func_003f6440
    /* 3AADC4 004AADC4 00000000 */   nop
    /* 3AADC8 004AADC8 0C004426 */  addiu      $4, $18, 0xC
    /* 3AADCC 004AADCC 4001A527 */  addiu      $5, $29, 0x140
    /* 3AADD0 004AADD0 B0A1120C */  jal        func_004a86c0
    /* 3AADD4 004AADD4 00000000 */   nop
    /* 3AADD8 004AADD8 5001A0AF */  sw         $0, 0x150($29)
    /* 3AADDC 004AADDC 5401A0AF */  sw         $0, 0x154($29)
    /* 3AADE0 004AADE0 9001A0AF */  sw         $0, 0x190($29)
    /* 3AADE4 004AADE4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AADE8 004AADE8 9401A2AF */  sw         $2, 0x194($29)
    /* 3AADEC 004AADEC D001A2AF */  sw         $2, 0x1D0($29)
    /* 3AADF0 004AADF0 D401A2AF */  sw         $2, 0x1D4($29)
    /* 3AADF4 004AADF4 1002A2AF */  sw         $2, 0x210($29)
    /* 3AADF8 004AADF8 1402A0AF */  sw         $0, 0x214($29)
    /* 3AADFC 004AADFC 8800103C */  lui        $16, %hi(D_00887314)
    /* 3AAE00 004AAE00 14731026 */  addiu      $16, $16, %lo(D_00887314)
    /* 3AAE04 004AAE04 03000424 */  addiu      $4, $0, 0x3
    /* 3AAE08 004AAE08 4001A527 */  addiu      $5, $29, 0x140
    /* 3AAE0C 004AAE0C 04000624 */  addiu      $6, $0, 0x4
    /* 3AAE10 004AAE10 7100073C */  lui        $7, %hi(D_00714368)
    /* 3AAE14 004AAE14 6843E724 */  addiu      $7, $7, %lo(D_00714368)
    /* 3AAE18 004AAE18 06000824 */  addiu      $8, $0, 0x6
    /* 3AAE1C 004AAE1C 0000028E */  lw         $2, 0x0($16)
    /* 3AAE20 004AAE20 09F84000 */  jalr       $2
    /* 3AAE24 004AAE24 00000000 */   nop
    /* 3AAE28 004AAE28 0028120C */  jal        func_0048a000
    /* 3AAE2C 004AAE2C 00000000 */   nop
    /* 3AAE30 004AAE30 4C02A28F */  lw         $2, 0x24C($29)
    /* 3AAE34 004AAE34 10004534 */  ori        $5, $2, 0x10
    /* 3AAE38 004AAE38 02000424 */  addiu      $4, $0, 0x2
    /* 3AAE3C 004AAE3C 10D90F0C */  jal        func_003f6440
    /* 3AAE40 004AAE40 00000000 */   nop
    /* 3AAE44 004AAE44 0C004426 */  addiu      $4, $18, 0xC
    /* 3AAE48 004AAE48 4000A527 */  addiu      $5, $29, 0x40
    /* 3AAE4C 004AAE4C B0A1120C */  jal        func_004a86c0
    /* 3AAE50 004AAE50 00000000 */   nop
    /* 3AAE54 004AAE54 01000424 */  addiu      $4, $0, 0x1
    /* 3AAE58 004AAE58 2D280000 */  daddu      $5, $0, $0
    /* 3AAE5C 004AAE5C 0000228E */  lw         $2, 0x0($17)
    /* 3AAE60 004AAE60 09F84000 */  jalr       $2
    /* 3AAE64 004AAE64 00000000 */   nop
    /* 3AAE68 004AAE68 03000424 */  addiu      $4, $0, 0x3
    /* 3AAE6C 004AAE6C 0300023C */  lui        $2, (0x31001 >> 16)
    /* 3AAE70 004AAE70 01104534 */  ori        $5, $2, (0x31001 & 0xFFFF)
    /* 3AAE74 004AAE74 10D90F0C */  jal        func_003f6440
    /* 3AAE78 004AAE78 00000000 */   nop
    /* 3AAE7C 004AAE7C 03000424 */  addiu      $4, $0, 0x3
    /* 3AAE80 004AAE80 4000A527 */  addiu      $5, $29, 0x40
    /* 3AAE84 004AAE84 04000624 */  addiu      $6, $0, 0x4
    /* 3AAE88 004AAE88 7100073C */  lui        $7, %hi(D_00714368)
    /* 3AAE8C 004AAE8C 6843E724 */  addiu      $7, $7, %lo(D_00714368)
    /* 3AAE90 004AAE90 06000824 */  addiu      $8, $0, 0x6
    /* 3AAE94 004AAE94 0000028E */  lw         $2, 0x0($16)
    /* 3AAE98 004AAE98 09F84000 */  jalr       $2
    /* 3AAE9C 004AAE9C 00000000 */   nop
    /* 3AAEA0 004AAEA0 03000424 */  addiu      $4, $0, 0x3
    /* 3AAEA4 004AAEA4 4802A58F */  lw         $5, 0x248($29)
    /* 3AAEA8 004AAEA8 10D90F0C */  jal        func_003f6440
    /* 3AAEAC 004AAEAC 00000000 */   nop
    /* 3AAEB0 004AAEB0 02000424 */  addiu      $4, $0, 0x2
    /* 3AAEB4 004AAEB4 4C02A58F */  lw         $5, 0x24C($29)
    /* 3AAEB8 004AAEB8 10D90F0C */  jal        func_003f6440
    /* 3AAEBC 004AAEBC 00000000 */   nop
  .L004AAEC0:
    /* 3AAEC0 004AAEC0 3000BFDF */  ld         $31, 0x30($29)
    /* 3AAEC4 004AAEC4 2000B27B */  lq         $18, 0x20($29)
    /* 3AAEC8 004AAEC8 1000B17B */  lq         $17, 0x10($29)
    /* 3AAECC 004AAECC 0000B07B */  lq         $16, 0x0($29)
    /* 3AAED0 004AAED0 5002BD27 */  addiu      $29, $29, 0x250
    /* 3AAED4 004AAED4 0800E003 */  jr         $31
    /* 3AAED8 004AAED8 00000000 */   nop
    /* 3AAEDC 004AAEDC 00000000 */  nop
.size func_004aad30, 0x1b0

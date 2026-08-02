.section .text
.set noat
.set noreorder
glabel func_004a09e0
    /* 3A09E0 004A09E0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3A09E4 004A09E4 3000BFFF */  sd         $31, 0x30($29)
    /* 3A09E8 004A09E8 2000B27F */  sq         $18, 0x20($29)
    /* 3A09EC 004A09EC 1000B17F */  sq         $17, 0x10($29)
    /* 3A09F0 004A09F0 0000B07F */  sq         $16, 0x0($29)
    /* 3A09F4 004A09F4 2D888000 */  daddu      $17, $4, $0
    /* 3A09F8 004A09F8 2D80A000 */  daddu      $16, $5, $0
    /* 3A09FC 004A09FC 3800828C */  lw         $2, 0x38($4)
    /* 3A0A00 004A0A00 40910200 */  sll        $18, $2, 5
    /* 3A0A04 004A0A04 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 3A0A08 004A0A08 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 3A0A0C 004A0A0C F10A0524 */  addiu      $5, $0, 0xAF1
    /* 3A0A10 004A0A10 A43A110C */  jal        func_0044ea90
    /* 3A0A14 004A0A14 00000000 */   nop
    /* 3A0A18 004A0A18 10004426 */  addiu      $4, $18, 0x10
    /* 3A0A1C 004A0A1C 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3A0A20 004A0A20 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3A0A24 004A0A24 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3A0A28 004A0A28 09F84000 */  jalr       $2
    /* 3A0A2C 004A0A2C 00000000 */   nop
    /* 3A0A30 004A0A30 2D904000 */  daddu      $18, $2, $0
    /* 3A0A34 004A0A34 06004016 */  bnez       $18, .L004A0A50
    /* 3A0A38 004A0A38 00000000 */   nop
    /* 3A0A3C 004A0A3C 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 3A0A40 004A0A40 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 3A0A44 004A0A44 F20A0524 */  addiu      $5, $0, 0xAF2
    /* 3A0A48 004A0A48 CCB5110C */  jal        func_0046d730
    /* 3A0A4C 004A0A4C 00000000 */   nop
  .L004A0A50:
    /* 3A0A50 004A0A50 10004226 */  addiu      $2, $18, 0x10
    /* 3A0A54 004A0A54 000042AE */  sw         $2, 0x0($18)
    /* 3A0A58 004A0A58 080052AE */  sw         $18, 0x8($18)
    /* 3A0A5C 004A0A5C 38002496 */  lhu        $4, 0x38($17)
    /* 3A0A60 004A0A60 02000524 */  addiu      $5, $0, 0x2
    /* 3A0A64 004A0A64 04000624 */  addiu      $6, $0, 0x4
    /* 3A0A68 004A0A68 7100073C */  lui        $7, %hi(D_00713408)
    /* 3A0A6C 004A0A6C 0834E724 */  addiu      $7, $7, %lo(D_00713408)
    /* 3A0A70 004A0A70 4C000824 */  addiu      $8, $0, 0x4C
    /* 3A0A74 004A0A74 DC0B120C */  jal        func_00482f70
    /* 3A0A78 004A0A78 00000000 */   nop
    /* 3A0A7C 004A0A7C 040042AE */  sw         $2, 0x4($18)
    /* 3A0A80 004A0A80 0B000016 */  bnez       $16, .L004A0AB0
    /* 3A0A84 004A0A84 00000000 */   nop
    /* 3A0A88 004A0A88 13000424 */  addiu      $4, $0, 0x13
    /* 3A0A8C 004A0A8C C004120C */  jal        func_00481300
    /* 3A0A90 004A0A90 00000000 */   nop
    /* 3A0A94 004A0A94 0400438E */  lw         $3, 0x4($18)
    /* 3A0A98 004A0A98 1400648C */  lw         $4, 0x14($3)
    /* 3A0A9C 004A0A9C 2D284000 */  daddu      $5, $2, $0
    /* 3A0AA0 004A0AA0 AC100F0C */  jal        func_003c42b0
    /* 3A0AA4 004A0AA4 00000000 */   nop
    /* 3A0AA8 004A0AA8 05000010 */  b          .L004A0AC0
    /* 3A0AAC 004A0AAC 00000000 */   nop
  .L004A0AB0:
    /* 3A0AB0 004A0AB0 0400448E */  lw         $4, 0x4($18)
    /* 3A0AB4 004A0AB4 2D280002 */  daddu      $5, $16, $0
    /* 3A0AB8 004A0AB8 5C0E120C */  jal        func_00483970
    /* 3A0ABC 004A0ABC 00000000 */   nop
  .L004A0AC0:
    /* 3A0AC0 004A0AC0 2D204002 */  daddu      $4, $18, $0
    /* 3A0AC4 004A0AC4 2D282002 */  daddu      $5, $17, $0
    /* 3A0AC8 004A0AC8 2882120C */  jal        func_004a08a0
    /* 3A0ACC 004A0ACC 00000000 */   nop
    /* 3A0AD0 004A0AD0 2D104002 */  daddu      $2, $18, $0
    /* 3A0AD4 004A0AD4 3000BFDF */  ld         $31, 0x30($29)
    /* 3A0AD8 004A0AD8 2000B27B */  lq         $18, 0x20($29)
    /* 3A0ADC 004A0ADC 1000B17B */  lq         $17, 0x10($29)
    /* 3A0AE0 004A0AE0 0000B07B */  lq         $16, 0x0($29)
    /* 3A0AE4 004A0AE4 4000BD27 */  addiu      $29, $29, 0x40
    /* 3A0AE8 004A0AE8 0800E003 */  jr         $31
    /* 3A0AEC 004A0AEC 00000000 */   nop
.size func_004a09e0, 0x110

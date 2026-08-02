.section .text
.set noat
.set noreorder
glabel func_0015f9b0
    /* 5F9B0 0015F9B0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 5F9B4 0015F9B4 4000BFFF */  sd         $31, 0x40($29)
    /* 5F9B8 0015F9B8 3000B37F */  sq         $19, 0x30($29)
    /* 5F9BC 0015F9BC 2000B27F */  sq         $18, 0x20($29)
    /* 5F9C0 0015F9C0 1000B17F */  sq         $17, 0x10($29)
    /* 5F9C4 0015F9C4 0000B07F */  sq         $16, 0x0($29)
    /* 5F9C8 0015F9C8 2D888000 */  daddu      $17, $4, $0
    /* 5F9CC 0015F9CC 2D80A000 */  daddu      $16, $5, $0
    /* 5F9D0 0015F9D0 2D98C000 */  daddu      $19, $6, $0
    /* 5F9D4 0015F9D4 2D90E000 */  daddu      $18, $7, $0
    /* 5F9D8 0015F9D8 04002016 */  bnez       $17, .L0015F9EC
    /* 5F9DC 0015F9DC 00000000 */   nop
    /* 5F9E0 0015F9E0 01000224 */  addiu      $2, $0, 0x1
    /* 5F9E4 0015F9E4 3E000010 */  b          .L0015FAE0
    /* 5F9E8 0015F9E8 00000000 */   nop
  .L0015F9EC:
    /* 5F9EC 0015F9EC B03B050C */  jal        func_0014eec0
    /* 5F9F0 0015F9F0 00000000 */   nop
    /* 5F9F4 0015F9F4 09004014 */  bnez       $2, .L0015FA1C
    /* 5F9F8 0015F9F8 00000000 */   nop
    /* 5F9FC 0015F9FC 2D202002 */  daddu      $4, $17, $0
    /* 5FA00 0015FA00 F054110C */  jal        func_004553c0
    /* 5FA04 0015FA04 00000000 */   nop
    /* 5FA08 0015FA08 04004014 */  bnez       $2, .L0015FA1C
    /* 5FA0C 0015FA0C 00000000 */   nop
    /* 5FA10 0015FA10 2D100000 */  daddu      $2, $0, $0
    /* 5FA14 0015FA14 32000010 */  b          .L0015FAE0
    /* 5FA18 0015FA18 00000000 */   nop
  .L0015FA1C:
    /* 5FA1C 0015FA1C B03B050C */  jal        func_0014eec0
    /* 5FA20 0015FA20 00000000 */   nop
    /* 5FA24 0015FA24 06004014 */  bnez       $2, .L0015FA40
    /* 5FA28 0015FA28 00000000 */   nop
    /* 5FA2C 0015FA2C 1801228E */  lw         $2, 0x118($17)
    /* 5FA30 0015FA30 9C00A2AF */  sw         $2, 0x9C($29)
    /* 5FA34 0015FA34 1001328E */  lw         $18, 0x110($17)
    /* 5FA38 0015FA38 0D000010 */  b          .L0015FA70
    /* 5FA3C 0015FA3C 00000000 */   nop
  .L0015FA40:
    /* 5FA40 0015FA40 FFFF6632 */  andi       $6, $19, 0xFFFF
    /* 5FA44 0015FA44 FFFF4732 */  andi       $7, $18, 0xFFFF
    /* 5FA48 0015FA48 5000A427 */  addiu      $4, $29, 0x50
    /* 5FA4C 0015FA4C 5F00053C */  lui        $5, %hi(D_005F1150)
    /* 5FA50 0015FA50 5011A524 */  addiu      $5, $5, %lo(D_005F1150)
    /* 5FA54 0015FA54 2208110C */  jal        func_00442088
    /* 5FA58 0015FA58 00000000 */   nop
    /* 5FA5C 0015FA5C 5000A427 */  addiu      $4, $29, 0x50
    /* 5FA60 0015FA60 9C00A527 */  addiu      $5, $29, 0x9C
    /* 5FA64 0015FA64 DC57110C */  jal        func_00455f70
    /* 5FA68 0015FA68 00000000 */   nop
    /* 5FA6C 0015FA6C 2D904000 */  daddu      $18, $2, $0
  .L0015FA70:
    /* 5FA70 0015FA70 13004012 */  beqz       $18, .L0015FAC0
    /* 5FA74 0015FA74 00000000 */   nop
    /* 5FA78 0015FA78 5F00043C */  lui        $4, %hi(D_005F1108)
    /* 5FA7C 0015FA7C 08118424 */  addiu      $4, $4, %lo(D_005F1108)
    /* 5FA80 0015FA80 AE010524 */  addiu      $5, $0, 0x1AE
    /* 5FA84 0015FA84 A43A110C */  jal        func_0044ea90
    /* 5FA88 0015FA88 00000000 */   nop
    /* 5FA8C 0015FA8C 9C00A58F */  lw         $5, 0x9C($29)
    /* 5FA90 0015FA90 01000424 */  addiu      $4, $0, 0x1
    /* 5FA94 0015FA94 0400063C */  lui        $6, (0x40000 >> 16)
    /* 5FA98 0015FA98 8800023C */  lui        $2, %hi(D_008873F4)
    /* 5FA9C 0015FA9C F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 5FAA0 0015FAA0 09F84000 */  jalr       $2
    /* 5FAA4 0015FAA4 00000000 */   nop
    /* 5FAA8 0015FAA8 000002AE */  sw         $2, 0x0($16)
    /* 5FAAC 0015FAAC 9C00A68F */  lw         $6, 0x9C($29)
    /* 5FAB0 0015FAB0 2D204000 */  daddu      $4, $2, $0
    /* 5FAB4 0015FAB4 2D284002 */  daddu      $5, $18, $0
    /* 5FAB8 0015FAB8 04FE100C */  jal        func_0043f810
    /* 5FABC 0015FABC 00000000 */   nop
  .L0015FAC0:
    /* 5FAC0 0015FAC0 B03B050C */  jal        func_0014eec0
    /* 5FAC4 0015FAC4 00000000 */   nop
    /* 5FAC8 0015FAC8 04004014 */  bnez       $2, .L0015FADC
    /* 5FACC 0015FACC 00000000 */   nop
    /* 5FAD0 0015FAD0 2D202002 */  daddu      $4, $17, $0
    /* 5FAD4 0015FAD4 F452110C */  jal        func_00454bd0
    /* 5FAD8 0015FAD8 00000000 */   nop
  .L0015FADC:
    /* 5FADC 0015FADC 01000224 */  addiu      $2, $0, 0x1
  .L0015FAE0:
    /* 5FAE0 0015FAE0 4000BFDF */  ld         $31, 0x40($29)
    /* 5FAE4 0015FAE4 3000B37B */  lq         $19, 0x30($29)
    /* 5FAE8 0015FAE8 2000B27B */  lq         $18, 0x20($29)
    /* 5FAEC 0015FAEC 1000B17B */  lq         $17, 0x10($29)
    /* 5FAF0 0015FAF0 0000B07B */  lq         $16, 0x0($29)
    /* 5FAF4 0015FAF4 A000BD27 */  addiu      $29, $29, 0xA0
    /* 5FAF8 0015FAF8 0800E003 */  jr         $31
    /* 5FAFC 0015FAFC 00000000 */   nop
.size func_0015f9b0, 0x150

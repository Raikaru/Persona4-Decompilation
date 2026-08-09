.section .text
.set noat
.set noreorder
glabel func_004ca8b0
    /* 3CA8B0 004CA8B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA8B4 004CA8B4 7200033C */  lui        $3, %hi(D_007188A0)
    /* 3CA8B8 004CA8B8 0000B0FF */  sd         $16, 0x0($29)
    /* 3CA8BC 004CA8BC A0886324 */  addiu      $3, $3, %lo(D_007188A0)
    /* 3CA8C0 004CA8C0 0800BFFF */  sd         $31, 0x8($29)
    /* 3CA8C4 004CA8C4 0000628C */  lw         $2, 0x0($3)
    /* 3CA8C8 004CA8C8 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3CA8CC 004CA8CC 2C004014 */  bnez       $2, .L004CA980
    /* 3CA8D0 004CA8D0 000062AC */   sw        $2, 0x0($3)
    /* 3CA8D4 004CA8D4 7300103C */  lui        $16, %hi(D_0073249C)
    /* 3CA8D8 004CA8D8 9C241026 */  addiu      $16, $16, %lo(D_0073249C)
    /* 3CA8DC 004CA8DC B84F130C */  jal        func_004d3ee0
    /* 3CA8E0 004CA8E0 000000AE */   sw        $0, 0x0($16)
    /* 3CA8E4 004CA8E4 9A35130C */  jal        func_004cd668
    /* 3CA8E8 004CA8E8 00000000 */   nop
    /* 3CA8EC 004CA8EC 7A1B130C */  jal        func_004c6de8
    /* 3CA8F0 004CA8F0 00000000 */   nop
    /* 3CA8F4 004CA8F4 5646130C */  jal        func_004d1958
    /* 3CA8F8 004CA8F8 00000000 */   nop
    /* 3CA8FC 004CA8FC 66A6130C */  jal        func_004e9998
    /* 3CA900 004CA900 00000000 */   nop
    /* 3CA904 004CA904 2A15130C */  jal        func_004c54a8
    /* 3CA908 004CA908 00000000 */   nop
    /* 3CA90C 004CA90C 02000424 */  addiu      $4, $0, 0x2
    /* 3CA910 004CA910 E2C2130C */  jal        func_004f0b88
    /* 3CA914 004CA914 01000524 */   addiu     $5, $0, 0x1
    /* 3CA918 004CA918 7200023C */  lui        $2, %hi(D_007188B4)
    /* 3CA91C 004CA91C B488458C */  lw         $5, %lo(D_007188B4)($2)
    /* 3CA920 004CA920 E2C2130C */  jal        func_004f0b88
    /* 3CA924 004CA924 04000424 */   addiu     $4, $0, 0x4
    /* 3CA928 004CA928 7200023C */  lui        $2, %hi(D_007188A8)
    /* 3CA92C 004CA92C A888458C */  lw         $5, %lo(D_007188A8)($2)
    /* 3CA930 004CA930 E2C2130C */  jal        func_004f0b88
    /* 3CA934 004CA934 05000424 */   addiu     $4, $0, 0x5
    /* 3CA938 004CA938 88C4130C */  jal        func_004f1220
    /* 3CA93C 004CA93C 00000000 */   nop
    /* 3CA940 004CA940 8C36130C */  jal        func_004cda30
    /* 3CA944 004CA944 00000000 */   nop
    /* 3CA948 004CA948 8E1A130C */  jal        func_004c6a38
    /* 3CA94C 004CA94C 00000000 */   nop
    /* 3CA950 004CA950 60B5130C */  jal        func_004ed580
    /* 3CA954 004CA954 00000000 */   nop
    /* 3CA958 004CA958 E6B7130C */  jal        func_004edf98
    /* 3CA95C 004CA95C 00000000 */   nop
    /* 3CA960 004CA960 E8BA130C */  jal        func_004eeba0
    /* 3CA964 004CA964 00000000 */   nop
    /* 3CA968 004CA968 3015130C */  jal        func_004c54c0
    /* 3CA96C 004CA96C 00000000 */   nop
    /* 3CA970 004CA970 1E15130C */  jal        func_004c5478
    /* 3CA974 004CA974 00000000 */   nop
    /* 3CA978 004CA978 01000224 */  addiu      $2, $0, 0x1
    /* 3CA97C 004CA97C 000002AE */  sw         $2, 0x0($16)
  .L004CA980:
    /* 3CA980 004CA980 0000B0DF */  ld         $16, 0x0($29)
    /* 3CA984 004CA984 0800BFDF */  ld         $31, 0x8($29)
    /* 3CA988 004CA988 0800E003 */  jr         $31
    /* 3CA98C 004CA98C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca8b0, 0xe0

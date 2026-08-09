.section .text
.set noat
.set noreorder
glabel func_004ce0c8
    /* 3CE0C8 004CE0C8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CE0CC 004CE0CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CE0D0 004CE0D0 0800B1FF */  sd         $17, 0x8($29)
    /* 3CE0D4 004CE0D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CE0D8 004CE0D8 2D908000 */  daddu      $18, $4, $0
    /* 3CE0DC 004CE0DC 1800B3FF */  sd         $19, 0x18($29)
    /* 3CE0E0 004CE0E0 2D980000 */  daddu      $19, $0, $0
    /* 3CE0E4 004CE0E4 2800B5FF */  sd         $21, 0x28($29)
    /* 3CE0E8 004CE0E8 2DA8E000 */  daddu      $21, $7, $0
    /* 3CE0EC 004CE0EC 3000B6FF */  sd         $22, 0x30($29)
    /* 3CE0F0 004CE0F0 2DB0A000 */  daddu      $22, $5, $0
    /* 3CE0F4 004CE0F4 3800B7FF */  sd         $23, 0x38($29)
    /* 3CE0F8 004CE0F8 2DB8C000 */  daddu      $23, $6, $0
    /* 3CE0FC 004CE0FC 2000B4FF */  sd         $20, 0x20($29)
    /* 3CE100 004CE100 1C005126 */  addiu      $17, $18, 0x1C
    /* 3CE104 004CE104 4000BFFF */  sd         $31, 0x40($29)
    /* 3CE108 004CE108 0C005026 */  addiu      $16, $18, 0xC
    /* 3CE10C 004CE10C 08000010 */  b          .L004CE130
    /* 3CE110 004CE110 0C00548E */   lw        $20, 0xC($18)
    /* 3CE114 004CE114 00000000 */  nop
  .L004CE118:
    /* 3CE118 004CE118 0000028E */  lw         $2, 0x0($16)
    /* 3CE11C 004CE11C 04001026 */  addiu      $16, $16, 0x4
    /* 3CE120 004CE120 0000438C */  lw         $3, 0x0($2)
    /* 3CE124 004CE124 1800688C */  lw         $8, 0x18($3)
    /* 3CE128 004CE128 09F80001 */  jalr       $8
    /* 3CE12C 004CE12C 2D204000 */   daddu     $4, $2, $0
  .L004CE130:
    /* 3CE130 004CE130 F40E130C */  jal        func_004c3bd0
    /* 3CE134 004CE134 0400448E */   lw        $4, 0x4($18)
    /* 3CE138 004CE138 2D280000 */  daddu      $5, $0, $0
    /* 3CE13C 004CE13C 2A106202 */  slt        $2, $19, $2
    /* 3CE140 004CE140 01007326 */  addiu      $19, $19, 0x1
    /* 3CE144 004CE144 2D382002 */  daddu      $7, $17, $0
    /* 3CE148 004CE148 08003126 */  addiu      $17, $17, 0x8
    /* 3CE14C 004CE14C F2FF4014 */  bnez       $2, .L004CE118
    /* 3CE150 004CE150 00400624 */   addiu     $6, $0, 0x4000
    /* 3CE154 004CE154 9CBA130C */  jal        func_004eea70
    /* 3CE158 004CE158 2D208002 */   daddu     $4, $20, $0
    /* 3CE15C 004CE15C 1C00438E */  lw         $3, 0x1C($18)
    /* 3CE160 004CE160 23186200 */  subu       $3, $3, $2
    /* 3CE164 004CE164 C2170300 */  srl        $2, $3, 31
    /* 3CE168 004CE168 21186200 */  addu       $3, $3, $2
    /* 3CE16C 004CE16C 43180300 */  sra        $3, $3, 1
    /* 3CE170 004CE170 0000C3AE */  sw         $3, 0x0($22)
    /* 3CE174 004CE174 2000428E */  lw         $2, 0x20($18)
    /* 3CE178 004CE178 3800448E */  lw         $4, 0x38($18)
    /* 3CE17C 004CE17C C21F0200 */  srl        $3, $2, 31
    /* 3CE180 004CE180 21104300 */  addu       $2, $2, $3
    /* 3CE184 004CE184 43100200 */  sra        $2, $2, 1
    /* 3CE188 004CE188 2A184400 */  slt        $3, $2, $4
    /* 3CE18C 004CE18C 0B204300 */  movn       $4, $2, $3
    /* 3CE190 004CE190 0000E4AE */  sw         $4, 0x0($23)
    /* 3CE194 004CE194 3C00438E */  lw         $3, 0x3C($18)
    /* 3CE198 004CE198 05006204 */  bltzl      $3, .L004CE1B0
    /* 3CE19C 004CE19C FF1F023C */   lui       $2, (0x1FFFFFFF >> 16)
    /* 3CE1A0 004CE1A0 4000428E */  lw         $2, 0x40($18)
    /* 3CE1A4 004CE1A4 03000010 */  b          .L004CE1B4
    /* 3CE1A8 004CE1A8 23106200 */   subu      $2, $3, $2
    /* 3CE1AC 004CE1AC 00000000 */  nop
  .L004CE1B0:
    /* 3CE1B0 004CE1B0 FFFF4234 */  ori        $2, $2, (0x1FFFFFFF & 0xFFFF)
  .L004CE1B4:
    /* 3CE1B4 004CE1B4 0000A2AE */  sw         $2, 0x0($21)
    /* 3CE1B8 004CE1B8 0400448E */  lw         $4, 0x4($18)
    /* 3CE1BC 004CE1BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CE1C0 004CE1C0 0800B1DF */  ld         $17, 0x8($29)
    /* 3CE1C4 004CE1C4 1000B2DF */  ld         $18, 0x10($29)
    /* 3CE1C8 004CE1C8 1800B3DF */  ld         $19, 0x18($29)
    /* 3CE1CC 004CE1CC 2000B4DF */  ld         $20, 0x20($29)
    /* 3CE1D0 004CE1D0 2800B5DF */  ld         $21, 0x28($29)
    /* 3CE1D4 004CE1D4 3000B6DF */  ld         $22, 0x30($29)
    /* 3CE1D8 004CE1D8 3800B7DF */  ld         $23, 0x38($29)
    /* 3CE1DC 004CE1DC 4000BFDF */  ld         $31, 0x40($29)
    /* 3CE1E0 004CE1E0 EE0E1308 */  j          func_004c3bb8
    /* 3CE1E4 004CE1E4 5000BD27 */   addiu     $29, $29, 0x50
.size func_004ce0c8, 0x120

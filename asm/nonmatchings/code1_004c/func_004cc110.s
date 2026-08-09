.section .text
.set noat
.set noreorder
glabel func_004cc110
    /* 3CC110 004CC110 4D00023C */  lui        $2, %hi(func_004cbbb0)
    /* 3CC114 004CC114 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC118 004CC118 2D38A000 */  daddu      $7, $5, $0
    /* 3CC11C 004CC11C 2D188000 */  daddu      $3, $4, $0
    /* 3CC120 004CC120 B0BB4224 */  addiu      $2, $2, %lo(func_004cbbb0)
    /* 3CC124 004CC124 3000B0FF */  sd         $16, 0x30($29)
    /* 3CC128 004CC128 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC12C 004CC12C 2D30E000 */  daddu      $6, $7, $0
    /* 3CC130 004CC130 2D286000 */  daddu      $5, $3, $0
    /* 3CC134 004CC134 08006014 */  bnez       $3, .L004CC158
    /* 3CC138 004CC138 0400A2AF */   sw        $2, 0x4($29)
    /* 3CC13C 004CC13C 7200023C */  lui        $2, %hi(D_0071F2C0)
    /* 3CC140 004CC140 00200324 */  addiu      $3, $0, 0x2000
    /* 3CC144 004CC144 C0F24224 */  addiu      $2, $2, %lo(D_0071F2C0)
    /* 3CC148 004CC148 0C00A3AF */  sw         $3, 0xC($29)
    /* 3CC14C 004CC14C 07000010 */  b          .L004CC16C
    /* 3CC150 004CC150 0800A2AF */   sw        $2, 0x8($29)
    /* 3CC154 004CC154 00000000 */  nop
  .L004CC158:
    /* 3CC158 004CC158 7600043C */  lui        $4, %hi(D_00758980)
    /* 3CC15C 004CC15C 0800A3AF */  sw         $3, 0x8($29)
    /* 3CC160 004CC160 80898424 */  addiu      $4, $4, %lo(D_00758980)
    /* 3CC164 004CC164 FC34130C */  jal        func_004cd3f0
    /* 3CC168 004CC168 0C00A7AF */   sw        $7, 0xC($29)
  .L004CC16C:
    /* 3CC16C 004CC16C 7200053C */  lui        $5, %hi(D_007212C8)
    /* 3CC170 004CC170 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CC174 004CC174 C812A38C */  lw         $3, %lo(D_007212C8)($5)
    /* 3CC178 004CC178 2D20A003 */  daddu      $4, $29, $0
    /* 3CC17C 004CC17C F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CC180 004CC180 7200103C */  lui        $16, %hi(D_00719A40)
    /* 3CC184 004CC184 1400A3AF */  sw         $3, 0x14($29)
    /* 3CC188 004CC188 409A1026 */  addiu      $16, $16, %lo(D_00719A40)
    /* 3CC18C 004CC18C 7885100C */  jal        func_004215e0
    /* 3CC190 004CC190 1000A2AF */   sw        $2, 0x10($29)
    /* 3CC194 004CC194 000002AE */  sw         $2, 0x0($16)
    /* 3CC198 004CC198 2D280000 */  daddu      $5, $0, $0
    /* 3CC19C 004CC19C 0000028E */  lw         $2, 0x0($16)
    /* 3CC1A0 004CC1A0 488A100C */  jal        func_00422920
    /* 3CC1A4 004CC1A4 0000048E */   lw        $4, 0x0($16)
    /* 3CC1A8 004CC1A8 0000048E */  lw         $4, 0x0($16)
    /* 3CC1AC 004CC1AC 7200023C */  lui        $2, %hi(D_007199BC)
    /* 3CC1B0 004CC1B0 9C85100C */  jal        func_00421670
    /* 3CC1B4 004CC1B4 BC99458C */   lw        $5, %lo(D_007199BC)($2)
    /* 3CC1B8 004CC1B8 0000048E */  lw         $4, 0x0($16)
    /* 3CC1BC 004CC1BC 6A2F130C */  jal        func_004cbda8
    /* 3CC1C0 004CC1C0 00000000 */   nop
    /* 3CC1C4 004CC1C4 7200033C */  lui        $3, %hi(D_00719A3C)
    /* 3CC1C8 004CC1C8 3C9A6324 */  addiu      $3, $3, %lo(D_00719A3C)
    /* 3CC1CC 004CC1CC 3000B0DF */  ld         $16, 0x30($29)
    /* 3CC1D0 004CC1D0 0000628C */  lw         $2, 0x0($3)
    /* 3CC1D4 004CC1D4 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC1D8 004CC1D8 0800E003 */  jr         $31
    /* 3CC1DC 004CC1DC 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cc110, 0xd0

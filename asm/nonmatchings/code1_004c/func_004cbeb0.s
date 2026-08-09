.section .text
.set noat
.set noreorder
glabel func_004cbeb0
    /* 3CBEB0 004CBEB0 4D00023C */  lui        $2, %hi(func_004cb7e8)
    /* 3CBEB4 004CBEB4 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBEB8 004CBEB8 2D38A000 */  daddu      $7, $5, $0
    /* 3CBEBC 004CBEBC 2D188000 */  daddu      $3, $4, $0
    /* 3CBEC0 004CBEC0 E8B74224 */  addiu      $2, $2, %lo(func_004cb7e8)
    /* 3CBEC4 004CBEC4 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBEC8 004CBEC8 3800BFFF */  sd         $31, 0x38($29)
    /* 3CBECC 004CBECC 2D30E000 */  daddu      $6, $7, $0
    /* 3CBED0 004CBED0 2D286000 */  daddu      $5, $3, $0
    /* 3CBED4 004CBED4 08006014 */  bnez       $3, .L004CBEF8
    /* 3CBED8 004CBED8 0400A2AF */   sw        $2, 0x4($29)
    /* 3CBEDC 004CBEDC 7200023C */  lui        $2, %hi(D_0071A2C0)
    /* 3CBEE0 004CBEE0 00100324 */  addiu      $3, $0, 0x1000
    /* 3CBEE4 004CBEE4 C0A24224 */  addiu      $2, $2, %lo(D_0071A2C0)
    /* 3CBEE8 004CBEE8 0C00A3AF */  sw         $3, 0xC($29)
    /* 3CBEEC 004CBEEC 07000010 */  b          .L004CBF0C
    /* 3CBEF0 004CBEF0 0800A2AF */   sw        $2, 0x8($29)
    /* 3CBEF4 004CBEF4 00000000 */  nop
  .L004CBEF8:
    /* 3CBEF8 004CBEF8 7600043C */  lui        $4, %hi(D_00758940)
    /* 3CBEFC 004CBEFC 0800A3AF */  sw         $3, 0x8($29)
    /* 3CBF00 004CBF00 40898424 */  addiu      $4, $4, %lo(D_00758940)
    /* 3CBF04 004CBF04 FC34130C */  jal        func_004cd3f0
    /* 3CBF08 004CBF08 0C00A7AF */   sw        $7, 0xC($29)
  .L004CBF0C:
    /* 3CBF0C 004CBF0C 7200053C */  lui        $5, %hi(D_007212C8)
    /* 3CBF10 004CBF10 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CBF14 004CBF14 C812A38C */  lw         $3, %lo(D_007212C8)($5)
    /* 3CBF18 004CBF18 2D20A003 */  daddu      $4, $29, $0
    /* 3CBF1C 004CBF1C F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CBF20 004CBF20 7200103C */  lui        $16, %hi(D_00719A2C)
    /* 3CBF24 004CBF24 2C9A1026 */  addiu      $16, $16, %lo(D_00719A2C)
    /* 3CBF28 004CBF28 1000A2AF */  sw         $2, 0x10($29)
    /* 3CBF2C 004CBF2C 7885100C */  jal        func_004215e0
    /* 3CBF30 004CBF30 1400A3AF */   sw        $3, 0x14($29)
    /* 3CBF34 004CBF34 000002AE */  sw         $2, 0x0($16)
    /* 3CBF38 004CBF38 2D280000 */  daddu      $5, $0, $0
    /* 3CBF3C 004CBF3C 0000028E */  lw         $2, 0x0($16)
    /* 3CBF40 004CBF40 488A100C */  jal        func_00422920
    /* 3CBF44 004CBF44 0000048E */   lw        $4, 0x0($16)
    /* 3CBF48 004CBF48 0000048E */  lw         $4, 0x0($16)
    /* 3CBF4C 004CBF4C 7200023C */  lui        $2, %hi(D_007199A8)
    /* 3CBF50 004CBF50 9C85100C */  jal        func_00421670
    /* 3CBF54 004CBF54 A899458C */   lw        $5, %lo(D_007199A8)($2)
    /* 3CBF58 004CBF58 3000B0DF */  ld         $16, 0x30($29)
    /* 3CBF5C 004CBF5C 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBF60 004CBF60 0800E003 */  jr         $31
    /* 3CBF64 004CBF64 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cbeb0, 0xb8

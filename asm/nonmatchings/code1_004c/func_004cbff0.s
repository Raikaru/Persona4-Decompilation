.section .text
.set noat
.set noreorder
glabel func_004cbff0
    /* 3CBFF0 004CBFF0 7200023C */  lui        $2, %hi(D_007212C8)
    /* 3CBFF4 004CBFF4 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBFF8 004CBFF8 C812478C */  lw         $7, %lo(D_007212C8)($2)
    /* 3CBFFC 004CBFFC 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CC000 004CC000 4D00053C */  lui        $5, %hi(func_004cb988)
    /* 3CC004 004CC004 7200033C */  lui        $3, %hi(D_0071C2C0)
    /* 3CC008 004CC008 3000B0FF */  sd         $16, 0x30($29)
    /* 3CC00C 004CC00C 7200103C */  lui        $16, %hi(D_00719A34)
    /* 3CC010 004CC010 C0C26324 */  addiu      $3, $3, %lo(D_0071C2C0)
    /* 3CC014 004CC014 2D20A003 */  daddu      $4, $29, $0
    /* 3CC018 004CC018 00100624 */  addiu      $6, $0, 0x1000
    /* 3CC01C 004CC01C 88B9A524 */  addiu      $5, $5, %lo(func_004cb988)
    /* 3CC020 004CC020 F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CC024 004CC024 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC028 004CC028 0400A5AF */  sw         $5, 0x4($29)
    /* 3CC02C 004CC02C 349A1026 */  addiu      $16, $16, %lo(D_00719A34)
    /* 3CC030 004CC030 0800A3AF */  sw         $3, 0x8($29)
    /* 3CC034 004CC034 0C00A6AF */  sw         $6, 0xC($29)
    /* 3CC038 004CC038 1400A7AF */  sw         $7, 0x14($29)
    /* 3CC03C 004CC03C 7885100C */  jal        func_004215e0
    /* 3CC040 004CC040 1000A2AF */   sw        $2, 0x10($29)
    /* 3CC044 004CC044 000002AE */  sw         $2, 0x0($16)
    /* 3CC048 004CC048 2D280000 */  daddu      $5, $0, $0
    /* 3CC04C 004CC04C 0000028E */  lw         $2, 0x0($16)
    /* 3CC050 004CC050 488A100C */  jal        func_00422920
    /* 3CC054 004CC054 0000048E */   lw        $4, 0x0($16)
    /* 3CC058 004CC058 0000048E */  lw         $4, 0x0($16)
    /* 3CC05C 004CC05C 7200023C */  lui        $2, %hi(D_007199B0)
    /* 3CC060 004CC060 9C85100C */  jal        func_00421670
    /* 3CC064 004CC064 B099458C */   lw        $5, %lo(D_007199B0)($2)
    /* 3CC068 004CC068 3000B0DF */  ld         $16, 0x30($29)
    /* 3CC06C 004CC06C 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC070 004CC070 0800E003 */  jr         $31
    /* 3CC074 004CC074 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cbff0, 0x88

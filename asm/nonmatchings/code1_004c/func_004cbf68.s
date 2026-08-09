.section .text
.set noat
.set noreorder
glabel func_004cbf68
    /* 3CBF68 004CBF68 7200023C */  lui        $2, %hi(D_007212C8)
    /* 3CBF6C 004CBF6C C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBF70 004CBF70 C812478C */  lw         $7, %lo(D_007212C8)($2)
    /* 3CBF74 004CBF74 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CBF78 004CBF78 4D00053C */  lui        $5, %hi(func_004cb880)
    /* 3CBF7C 004CBF7C 7200033C */  lui        $3, %hi(D_0071B2C0)
    /* 3CBF80 004CBF80 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBF84 004CBF84 7200103C */  lui        $16, %hi(D_00719A30)
    /* 3CBF88 004CBF88 C0B26324 */  addiu      $3, $3, %lo(D_0071B2C0)
    /* 3CBF8C 004CBF8C 2D20A003 */  daddu      $4, $29, $0
    /* 3CBF90 004CBF90 00100624 */  addiu      $6, $0, 0x1000
    /* 3CBF94 004CBF94 80B8A524 */  addiu      $5, $5, %lo(func_004cb880)
    /* 3CBF98 004CBF98 F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CBF9C 004CBF9C 3800BFFF */  sd         $31, 0x38($29)
    /* 3CBFA0 004CBFA0 0400A5AF */  sw         $5, 0x4($29)
    /* 3CBFA4 004CBFA4 309A1026 */  addiu      $16, $16, %lo(D_00719A30)
    /* 3CBFA8 004CBFA8 0800A3AF */  sw         $3, 0x8($29)
    /* 3CBFAC 004CBFAC 0C00A6AF */  sw         $6, 0xC($29)
    /* 3CBFB0 004CBFB0 1400A7AF */  sw         $7, 0x14($29)
    /* 3CBFB4 004CBFB4 7885100C */  jal        func_004215e0
    /* 3CBFB8 004CBFB8 1000A2AF */   sw        $2, 0x10($29)
    /* 3CBFBC 004CBFBC 000002AE */  sw         $2, 0x0($16)
    /* 3CBFC0 004CBFC0 2D280000 */  daddu      $5, $0, $0
    /* 3CBFC4 004CBFC4 0000028E */  lw         $2, 0x0($16)
    /* 3CBFC8 004CBFC8 488A100C */  jal        func_00422920
    /* 3CBFCC 004CBFCC 0000048E */   lw        $4, 0x0($16)
    /* 3CBFD0 004CBFD0 0000048E */  lw         $4, 0x0($16)
    /* 3CBFD4 004CBFD4 7200023C */  lui        $2, %hi(D_007199AC)
    /* 3CBFD8 004CBFD8 9C85100C */  jal        func_00421670
    /* 3CBFDC 004CBFDC AC99458C */   lw        $5, %lo(D_007199AC)($2)
    /* 3CBFE0 004CBFE0 3000B0DF */  ld         $16, 0x30($29)
    /* 3CBFE4 004CBFE4 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBFE8 004CBFE8 0800E003 */  jr         $31
    /* 3CBFEC 004CBFEC 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cbf68, 0x88

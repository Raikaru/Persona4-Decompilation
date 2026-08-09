.section .text
.set noat
.set noreorder
glabel func_004cc078
    /* 3CC078 004CC078 7200023C */  lui        $2, %hi(D_007212C8)
    /* 3CC07C 004CC07C C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CC080 004CC080 C812478C */  lw         $7, %lo(D_007212C8)($2)
    /* 3CC084 004CC084 7700023C */  lui        $2, %hi(D_007690F0)
    /* 3CC088 004CC088 4D00053C */  lui        $5, %hi(func_004cba78)
    /* 3CC08C 004CC08C 7200033C */  lui        $3, %hi(D_0071D2C0)
    /* 3CC090 004CC090 3000B0FF */  sd         $16, 0x30($29)
    /* 3CC094 004CC094 7200103C */  lui        $16, %hi(D_00719A3C)
    /* 3CC098 004CC098 C0D26324 */  addiu      $3, $3, %lo(D_0071D2C0)
    /* 3CC09C 004CC09C 2D20A003 */  daddu      $4, $29, $0
    /* 3CC0A0 004CC0A0 00200624 */  addiu      $6, $0, 0x2000
    /* 3CC0A4 004CC0A4 78BAA524 */  addiu      $5, $5, %lo(func_004cba78)
    /* 3CC0A8 004CC0A8 F0904224 */  addiu      $2, $2, %lo(D_007690F0)
    /* 3CC0AC 004CC0AC 3C9A1026 */  addiu      $16, $16, %lo(D_00719A3C)
    /* 3CC0B0 004CC0B0 3800BFFF */  sd         $31, 0x38($29)
    /* 3CC0B4 004CC0B4 0400A5AF */  sw         $5, 0x4($29)
    /* 3CC0B8 004CC0B8 0800A3AF */  sw         $3, 0x8($29)
    /* 3CC0BC 004CC0BC 0C00A6AF */  sw         $6, 0xC($29)
    /* 3CC0C0 004CC0C0 1400A7AF */  sw         $7, 0x14($29)
    /* 3CC0C4 004CC0C4 7885100C */  jal        func_004215e0
    /* 3CC0C8 004CC0C8 1000A2AF */   sw        $2, 0x10($29)
    /* 3CC0CC 004CC0CC 000002AE */  sw         $2, 0x0($16)
    /* 3CC0D0 004CC0D0 2D280000 */  daddu      $5, $0, $0
    /* 3CC0D4 004CC0D4 0000028E */  lw         $2, 0x0($16)
    /* 3CC0D8 004CC0D8 488A100C */  jal        func_00422920
    /* 3CC0DC 004CC0DC 0000048E */   lw        $4, 0x0($16)
    /* 3CC0E0 004CC0E0 0000048E */  lw         $4, 0x0($16)
    /* 3CC0E4 004CC0E4 7200023C */  lui        $2, %hi(D_007199B8)
    /* 3CC0E8 004CC0E8 9C85100C */  jal        func_00421670
    /* 3CC0EC 004CC0EC B899458C */   lw        $5, %lo(D_007199B8)($2)
    /* 3CC0F0 004CC0F0 0000048E */  lw         $4, 0x0($16)
    /* 3CC0F4 004CC0F4 6A2F130C */  jal        func_004cbda8
    /* 3CC0F8 004CC0F8 00000000 */   nop
    /* 3CC0FC 004CC0FC 0000038E */  lw         $3, 0x0($16)
    /* 3CC100 004CC100 3800BFDF */  ld         $31, 0x38($29)
    /* 3CC104 004CC104 3000B0DF */  ld         $16, 0x30($29)
    /* 3CC108 004CC108 0800E003 */  jr         $31
    /* 3CC10C 004CC10C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cc078, 0x98

.section .text
.set noat
.set noreorder
glabel func_0039b290
    /* 29B290 0039B290 F0B5858F */  lw         $5, -0x4A10($28)
    /* 29B294 0039B294 2D108000 */  daddu      $2, $4, $0
    /* 29B298 0039B298 3A00033C */  lui        $3, %hi(func_0039b250)
    /* 29B29C 0039B29C 50B26324 */  addiu      $3, $3, %lo(func_0039b250)
    /* 29B2A0 0039B2A0 21208500 */  addu       $4, $4, $5
    /* 29B2A4 0039B2A4 000080AC */  sw         $0, 0x0($4)
    /* 29B2A8 0039B2A8 080080AC */  sw         $0, 0x8($4)
    /* 29B2AC 0039B2AC 0800E003 */  jr         $31
    /* 29B2B0 0039B2B0 040083AC */   sw        $3, 0x4($4)
    /* 29B2B4 0039B2B4 00000000 */  nop
    /* 29B2B8 0039B2B8 00000000 */  nop
    /* 29B2BC 0039B2BC 00000000 */  nop
.size func_0039b290, 0x30

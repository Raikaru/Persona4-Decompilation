.section .text
.set noat
.set noreorder
glabel func_00422cf8
    /* 322CF8 00422CF8 8900023C */  lui        $2, %hi(D_0088D7C0)
    /* 322CFC 00422CFC C0D74324 */  addiu      $3, $2, %lo(D_0088D7C0)
    /* 322D00 00422D00 C0D744AC */  sw         $4, %lo(D_0088D7C0)($2)
    /* 322D04 00422D04 10006424 */  addiu      $4, $3, 0x10
    /* 322D08 00422D08 2D106000 */  daddu      $2, $3, $0
    /* 322D0C 00422D0C 080064AC */  sw         $4, 0x8($3)
    /* 322D10 00422D10 040060AC */  sw         $0, 0x4($3)
    /* 322D14 00422D14 0800E003 */  jr         $31
    /* 322D18 00422D18 0C0064AC */   sw        $4, 0xC($3)
    /* 322D1C 00422D1C 00000000 */  nop
.size func_00422cf8, 0x28

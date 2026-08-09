.section .text
.set noat
.set noreorder
glabel func_00407bd0
    /* 307BD0 00407BD0 80B985AF */  sw         $5, -0x4680($28)
    /* 307BD4 00407BD4 8900073C */  lui        $7, %hi(D_0088CAC0)
    /* 307BD8 00407BD8 1C00A884 */  lh         $8, 0x1C($5)
    /* 307BDC 00407BDC 8900063C */  lui        $6, %hi(D_0088CAC4)
    /* 307BE0 00407BE0 8900043C */  lui        $4, %hi(D_0088CAC8)
    /* 307BE4 00407BE4 8900033C */  lui        $3, %hi(D_0088CACC)
    /* 307BE8 00407BE8 01000224 */  addiu      $2, $0, 0x1
    /* 307BEC 00407BEC C0CAE8AC */  sw         $8, %lo(D_0088CAC0)($7)
    /* 307BF0 00407BF0 1E00A784 */  lh         $7, 0x1E($5)
    /* 307BF4 00407BF4 C4CAC7AC */  sw         $7, %lo(D_0088CAC4)($6)
    /* 307BF8 00407BF8 0C00A68C */  lw         $6, 0xC($5)
    /* 307BFC 00407BFC C8CA86AC */  sw         $6, %lo(D_0088CAC8)($4)
    /* 307C00 00407C00 1000A48C */  lw         $4, 0x10($5)
    /* 307C04 00407C04 0800E003 */  jr         $31
    /* 307C08 00407C08 CCCA64AC */   sw        $4, %lo(D_0088CACC)($3)
    /* 307C0C 00407C0C 00000000 */  nop
.size func_00407bd0, 0x40

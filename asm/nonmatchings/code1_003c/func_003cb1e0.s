.section .text
.set noat
.set noreorder
glabel func_003cb1e0
    /* 2CB1E0 003CB1E0 14B7858F */  lw         $5, -0x48EC($28)
    /* 2CB1E4 003CB1E4 3D00033C */  lui        $3, %hi(func_003caef0)
    /* 2CB1E8 003CB1E8 F0AE6324 */  addiu      $3, $3, %lo(func_003caef0)
    /* 2CB1EC 003CB1EC 2D108000 */  daddu      $2, $4, $0
    /* 2CB1F0 003CB1F0 21308500 */  addu       $6, $4, $5
    /* 2CB1F4 003CB1F4 0000C0AC */  sw         $0, 0x0($6)
    /* 2CB1F8 003CB1F8 1000858C */  lw         $5, 0x10($4)
    /* 2CB1FC 003CB1FC 0400C5AC */  sw         $5, 0x4($6)
    /* 2CB200 003CB200 0800E003 */  jr         $31
    /* 2CB204 003CB204 100083AC */   sw        $3, 0x10($4)
    /* 2CB208 003CB208 00000000 */  nop
    /* 2CB20C 003CB20C 00000000 */  nop
.size func_003cb1e0, 0x30

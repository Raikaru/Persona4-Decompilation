.section .text
.set noat
.set noreorder
glabel func_003ca830
    /* 2CA830 003CA830 08B7878F */  lw         $7, -0x48F8($28)
    /* 2CA834 003CA834 3D00063C */  lui        $6, %hi(func_003ca740 + 0x60)
    /* 2CA838 003CA838 3D00053C */  lui        $5, %hi(func_003ca740)
    /* 2CA83C 003CA83C 3D00033C */  lui        $3, %hi(func_003ca740 + 0x40)
    /* 2CA840 003CA840 A0A7C624 */  addiu      $6, $6, %lo(func_003ca740 + 0x60)
    /* 2CA844 003CA844 40A7A524 */  addiu      $5, $5, %lo(func_003ca740)
    /* 2CA848 003CA848 80A76324 */  addiu      $3, $3, %lo(func_003ca740 + 0x40)
    /* 2CA84C 003CA84C 2D108000 */  daddu      $2, $4, $0
    /* 2CA850 003CA850 21408700 */  addu       $8, $4, $7
    /* 2CA854 003CA854 000000AD */  sw         $0, 0x0($8)
    /* 2CA858 003CA858 040000AD */  sw         $0, 0x4($8)
    /* 2CA85C 003CA85C 080000AD */  sw         $0, 0x8($8)
    /* 2CA860 003CA860 1800878C */  lw         $7, 0x18($4)
    /* 2CA864 003CA864 100007AD */  sw         $7, 0x10($8)
    /* 2CA868 003CA868 1C00878C */  lw         $7, 0x1C($4)
    /* 2CA86C 003CA86C 140007AD */  sw         $7, 0x14($8)
    /* 2CA870 003CA870 1000878C */  lw         $7, 0x10($4)
    /* 2CA874 003CA874 180007AD */  sw         $7, 0x18($8)
    /* 2CA878 003CA878 100086AC */  sw         $6, 0x10($4)
    /* 2CA87C 003CA87C 180085AC */  sw         $5, 0x18($4)
    /* 2CA880 003CA880 1C0083AC */  sw         $3, 0x1C($4)
    /* 2CA884 003CA884 0800E003 */  jr         $31
    /* 2CA888 003CA888 0C0000AD */   sw        $0, 0xC($8)
    /* 2CA88C 003CA88C 00000000 */  nop
.size func_003ca830, 0x60

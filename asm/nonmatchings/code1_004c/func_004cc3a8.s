.section .text
.set noat
.set noreorder
glabel func_004cc3a8
    /* 3CC3A8 004CC3A8 7200033C */  lui        $3, %hi(D_00719A48)
    /* 3CC3AC 004CC3AC 7200043C */  lui        $4, %hi(D_00719A58)
    /* 3CC3B0 004CC3B0 7200053C */  lui        $5, %hi(D_00719A68)
    /* 3CC3B4 004CC3B4 7200063C */  lui        $6, %hi(D_00719A78)
    /* 3CC3B8 004CC3B8 7200073C */  lui        $7, %hi(D_00719A88)
    /* 3CC3BC 004CC3BC 7200083C */  lui        $8, %hi(D_00719A98)
    /* 3CC3C0 004CC3C0 01000224 */  addiu      $2, $0, 0x1
    /* 3CC3C4 004CC3C4 489A6324 */  addiu      $3, $3, %lo(D_00719A48)
    /* 3CC3C8 004CC3C8 589A8424 */  addiu      $4, $4, %lo(D_00719A58)
    /* 3CC3CC 004CC3CC 689AA524 */  addiu      $5, $5, %lo(D_00719A68)
    /* 3CC3D0 004CC3D0 789AC624 */  addiu      $6, $6, %lo(D_00719A78)
    /* 3CC3D4 004CC3D4 889AE724 */  addiu      $7, $7, %lo(D_00719A88)
    /* 3CC3D8 004CC3D8 989A0825 */  addiu      $8, $8, %lo(D_00719A98)
    /* 3CC3DC 004CC3DC 000062FC */  sd         $2, 0x0($3)
    /* 3CC3E0 004CC3E0 000082FC */  sd         $2, 0x0($4)
    /* 3CC3E4 004CC3E4 0000A2FC */  sd         $2, 0x0($5)
    /* 3CC3E8 004CC3E8 0000C2FC */  sd         $2, 0x0($6)
    /* 3CC3EC 004CC3EC 0000E2FC */  sd         $2, 0x0($7)
    /* 3CC3F0 004CC3F0 0800E003 */  jr         $31
    /* 3CC3F4 004CC3F4 000002FD */   sd        $2, 0x0($8)
.size func_004cc3a8, 0x50

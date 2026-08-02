.section .text
.set noat
.set noreorder
glabel func_0011de40
    /* 1DE40 0011DE40 3800868C */  lw         $6, 0x38($4)
    /* 1DE44 0011DE44 FF00A530 */  andi       $5, $5, 0xFF
    /* 1DE48 0011DE48 0800C38C */  lw         $3, 0x8($6)
    /* 1DE4C 0011DE4C 00FF0424 */  addiu      $4, $0, -0x100
    /* 1DE50 0011DE50 24186400 */  and        $3, $3, $4
    /* 1DE54 0011DE54 25186500 */  or         $3, $3, $5
    /* 1DE58 0011DE58 0800C3AC */  sw         $3, 0x8($6)
    /* 1DE5C 0011DE5C 0C00C38C */  lw         $3, 0xC($6)
    /* 1DE60 0011DE60 24186400 */  and        $3, $3, $4
    /* 1DE64 0011DE64 25186500 */  or         $3, $3, $5
    /* 1DE68 0011DE68 0C00C3AC */  sw         $3, 0xC($6)
    /* 1DE6C 0011DE6C 0800E003 */  jr         $31
    /* 1DE70 0011DE70 00000000 */   nop
    /* 1DE74 0011DE74 00000000 */  nop
    /* 1DE78 0011DE78 00000000 */  nop
    /* 1DE7C 0011DE7C 00000000 */  nop
.size func_0011de40, 0x40

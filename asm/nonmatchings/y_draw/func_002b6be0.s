.section .text
.set noat
.set noreorder
glabel func_002b6be0
    /* 1B6BE0 002B6BE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B6BE4 002B6BE4 0800A5FF */  sd         $5, 0x8($29)
    /* 1B6BE8 002B6BE8 3800858C */  lw         $5, 0x38($4)
    /* 1B6BEC 002B6BEC 1000A384 */  lh         $3, 0x10($5)
    /* 1B6BF0 002B6BF0 01006334 */  ori        $3, $3, 0x1
    /* 1B6BF4 002B6BF4 1000A3A4 */  sh         $3, 0x10($5)
    /* 1B6BF8 002B6BF8 3800838C */  lw         $3, 0x38($4)
    /* 1B6BFC 002B6BFC 14006CE4 */  swc1       $f12, 0x14($3)
    /* 1B6C00 002B6C00 3800838C */  lw         $3, 0x38($4)
    /* 1B6C04 002B6C04 080066AC */  sw         $6, 0x8($3)
    /* 1B6C08 002B6C08 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 1B6C0C 002B6C0C 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1B6C10 002B6C10 3800A1E4 */  swc1       $f1, 0x38($5)
    /* 1B6C14 002B6C14 3C00A0E4 */  swc1       $f0, 0x3C($5)
    /* 1B6C18 002B6C18 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B6C1C 002B6C1C 0800E003 */  jr         $31
    /* 1B6C20 002B6C20 00000000 */   nop
    /* 1B6C24 002B6C24 00000000 */  nop
    /* 1B6C28 002B6C28 00000000 */  nop
    /* 1B6C2C 002B6C2C 00000000 */  nop
.size func_002b6be0, 0x50

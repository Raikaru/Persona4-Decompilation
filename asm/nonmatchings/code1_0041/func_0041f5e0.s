.section .text
.set noat
.set noreorder
glabel func_0041f5e0
    /* 31F5E0 0041F5E0 4000868C */  lw         $6, 0x40($4)
    /* 31F5E4 0041F5E4 01000324 */  addiu      $3, $0, 0x1
    /* 31F5E8 0041F5E8 01000224 */  addiu      $2, $0, 0x1
    /* 31F5EC 0041F5EC 0801C3AC */  sw         $3, 0x108($6)
    /* 31F5F0 0041F5F0 0800E003 */  jr         $31
    /* 31F5F4 0041F5F4 0001C5FC */   sd        $5, 0x100($6)
.size func_0041f5e0, 0x18

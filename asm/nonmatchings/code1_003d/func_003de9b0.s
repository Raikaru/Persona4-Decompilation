.section .text
.set noat
.set noreorder
glabel func_003de9b0
    /* 2DE9B0 003DE9B0 01000224 */  addiu      $2, $0, 0x1
    /* 2DE9B4 003DE9B4 0800E003 */  jr         $31
    /* 2DE9B8 003DE9B8 380082AC */   sw        $2, 0x38($4)
    /* 2DE9BC 003DE9BC 00000000 */  nop
.size func_003de9b0, 0x10

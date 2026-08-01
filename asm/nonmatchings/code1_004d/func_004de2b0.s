.section .text
.set noat
.set noreorder
glabel func_004de2b0
    /* 3DE2B0 004DE2B0 01000224 */  addiu      $2, $0, 0x1
    /* 3DE2B4 004DE2B4 0800E003 */  jr         $31
    /* 3DE2B8 004DE2B8 080082AC */   sw        $2, 0x8($4)
    /* 3DE2BC 004DE2BC 00000000 */  nop
.size func_004de2b0, 0x10

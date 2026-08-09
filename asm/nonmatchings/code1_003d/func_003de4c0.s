.section .text
.set noat
.set noreorder
glabel func_003de4c0
    /* 2DE4C0 003DE4C0 01000224 */  addiu      $2, $0, 0x1
    /* 2DE4C4 003DE4C4 380082AC */  sw         $2, 0x38($4)
    /* 2DE4C8 003DE4C8 E09B1008 */  j          func_00426f80
    /* 2DE4CC 003DE4CC 6000848C */   lw        $4, 0x60($4)
.size func_003de4c0, 0x10

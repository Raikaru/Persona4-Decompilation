.section .text
.set noat
.set noreorder
glabel func_0042b3d0
    /* 32B3D0 0042B3D0 ABFF0324 */  addiu      $3, $0, -0x55
    /* 32B3D4 0042B3D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B3D8 0042B3D8 0800E003 */  jr         $31
    /* 32B3DC 0042B3DC 00000000 */   nop
.size func_0042b3d0, 0x10

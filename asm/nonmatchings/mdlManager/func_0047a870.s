.section .text
.set noat
.set noreorder
glabel func_0047a870
    /* 37A870 0047A870 D800858C */  lw         $5, 0xD8($4)
    /* 37A874 0047A874 DFFF0324 */  addiu      $3, $0, -0x21
    /* 37A878 0047A878 2418A300 */  and        $3, $5, $3
    /* 37A87C 0047A87C D80083AC */  sw         $3, 0xD8($4)
    /* 37A880 0047A880 0800E003 */  jr         $31
    /* 37A884 0047A884 00000000 */   nop
    /* 37A888 0047A888 00000000 */  nop
    /* 37A88C 0047A88C 00000000 */  nop
.size func_0047a870, 0x20

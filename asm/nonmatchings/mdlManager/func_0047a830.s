.section .text
.set noat
.set noreorder
glabel func_0047a830
    /* 37A830 0047A830 D800858C */  lw         $5, 0xD8($4)
    /* 37A834 0047A834 FEFF0324 */  addiu      $3, $0, -0x2
    /* 37A838 0047A838 2418A300 */  and        $3, $5, $3
    /* 37A83C 0047A83C D80083AC */  sw         $3, 0xD8($4)
    /* 37A840 0047A840 0800E003 */  jr         $31
    /* 37A844 0047A844 00000000 */   nop
    /* 37A848 0047A848 00000000 */  nop
    /* 37A84C 0047A84C 00000000 */  nop
.size func_0047a830, 0x20

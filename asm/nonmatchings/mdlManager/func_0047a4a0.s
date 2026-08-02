.section .text
.set noat
.set noreorder
glabel func_0047a4a0
    /* 37A4A0 0047A4A0 0000A28C */  lw         $2, 0x0($5)
    /* 37A4A4 0047A4A4 1800858C */  lw         $5, 0x18($4)
    /* 37A4A8 0047A4A8 27184000 */  not        $3, $2
    /* 37A4AC 0047A4AC 0800A28C */  lw         $2, 0x8($5)
    /* 37A4B0 0047A4B0 24104300 */  and        $2, $2, $3
    /* 37A4B4 0047A4B4 0800A2AC */  sw         $2, 0x8($5)
    /* 37A4B8 0047A4B8 2D108000 */  daddu      $2, $4, $0
    /* 37A4BC 0047A4BC 0800E003 */  jr         $31
    /* 37A4C0 0047A4C0 00000000 */   nop
    /* 37A4C4 0047A4C4 00000000 */  nop
    /* 37A4C8 0047A4C8 00000000 */  nop
    /* 37A4CC 0047A4CC 00000000 */  nop
.size func_0047a4a0, 0x30

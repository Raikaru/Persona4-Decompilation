.section .text
.set noat
.set noreorder
glabel func_0047d090
    /* 37D090 0047D090 2CBB84AF */  sw         $4, -0x44D4($28)
    /* 37D094 0047D094 30BB85AF */  sw         $5, -0x44D0($28)
    /* 37D098 0047D098 34BB86AF */  sw         $6, -0x44CC($28)
    /* 37D09C 0047D09C 38BB87AF */  sw         $7, -0x44C8($28)
    /* 37D0A0 0047D0A0 3CBB88AF */  sw         $8, -0x44C4($28)
    /* 37D0A4 0047D0A4 01000224 */  addiu      $2, $0, 0x1
    /* 37D0A8 0047D0A8 0800E003 */  jr         $31
    /* 37D0AC 0047D0AC 00000000 */   nop
.size func_0047d090, 0x20

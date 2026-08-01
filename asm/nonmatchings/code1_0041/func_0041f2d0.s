.section .text
.set noat
.set noreorder
glabel func_0041f2d0
    /* 31F2D0 0041F2D0 4000888C */  lw         $8, 0x40($4)
    /* 31F2D4 0041F2D4 A800028D */  lw         $2, 0xA8($8)
    /* 31F2D8 0041F2D8 0000A2AC */  sw         $2, 0x0($5)
    /* 31F2DC 0041F2DC AC00038D */  lw         $3, 0xAC($8)
    /* 31F2E0 0041F2E0 0000C3AC */  sw         $3, 0x0($6)
    /* 31F2E4 0041F2E4 B000028D */  lw         $2, 0xB0($8)
    /* 31F2E8 0041F2E8 0800E003 */  jr         $31
    /* 31F2EC 0041F2EC 0000E2AC */   sw        $2, 0x0($7)
.size func_0041f2d0, 0x20

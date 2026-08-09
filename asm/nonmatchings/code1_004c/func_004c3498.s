.section .text
.set noat
.set noreorder
glabel func_004c3498
    /* 3C3498 004C3498 8C00888C */  lw         $8, 0x8C($4)
    /* 3C349C 004C349C 3C00828C */  lw         $2, 0x3C($4)
    /* 3C34A0 004C34A0 0000A8AC */  sw         $8, 0x0($5)
    /* 3C34A4 004C34A4 8C00858C */  lw         $5, 0x8C($4)
    /* 3C34A8 004C34A8 4000838C */  lw         $3, 0x40($4)
    /* 3C34AC 004C34AC 23186500 */  subu       $3, $3, $5
    /* 3C34B0 004C34B0 0000C3AC */  sw         $3, 0x0($6)
    /* 3C34B4 004C34B4 1800858C */  lw         $5, 0x18($4)
    /* 3C34B8 004C34B8 8800838C */  lw         $3, 0x88($4)
    /* 3C34BC 004C34BC 2328A300 */  subu       $5, $5, $3
    /* 3C34C0 004C34C0 0800E003 */  jr         $31
    /* 3C34C4 004C34C4 0000E5AC */   sw        $5, 0x0($7)
.size func_004c3498, 0x30

.section .text
.set noat
.set noreorder
glabel func_004fb500
    /* 3FB500 004FB500 100080AC */  sw         $0, 0x10($4)
    /* 3FB504 004FB504 000080AC */  sw         $0, 0x0($4)
    /* 3FB508 004FB508 040080AC */  sw         $0, 0x4($4)
    /* 3FB50C 004FB50C 080080AC */  sw         $0, 0x8($4)
    /* 3FB510 004FB510 0800E003 */  jr         $31
    /* 3FB514 004FB514 0C0080AC */   sw        $0, 0xC($4)
.size func_004fb500, 0x18

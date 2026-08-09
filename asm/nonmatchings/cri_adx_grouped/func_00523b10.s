.section .text
.set noat
.set noreorder
glabel func_00523b10
    /* 423B10 00523B10 100080AC */  sw         $0, 0x10($4)
    /* 423B14 00523B14 000080AC */  sw         $0, 0x0($4)
    /* 423B18 00523B18 040080AC */  sw         $0, 0x4($4)
    /* 423B1C 00523B1C 080080AC */  sw         $0, 0x8($4)
    /* 423B20 00523B20 0800E003 */  jr         $31
    /* 423B24 00523B24 0C0080AC */   sw        $0, 0xC($4)
.size func_00523b10, 0x18

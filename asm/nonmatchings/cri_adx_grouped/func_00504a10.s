.section .text
.set noat
.set noreorder
glabel func_00504a10
    /* 404A10 00504A10 100080AC */  sw         $0, 0x10($4)
    /* 404A14 00504A14 000080AC */  sw         $0, 0x0($4)
    /* 404A18 00504A18 040080AC */  sw         $0, 0x4($4)
    /* 404A1C 00504A1C 080080AC */  sw         $0, 0x8($4)
    /* 404A20 00504A20 0800E003 */  jr         $31
    /* 404A24 00504A24 0C0080AC */   sw        $0, 0xC($4)
.size func_00504a10, 0x18

.section .text
.set noat
.set noreorder
glabel func_00517ab8
    /* 417AB8 00517AB8 100080AC */  sw         $0, 0x10($4)
    /* 417ABC 00517ABC 000080AC */  sw         $0, 0x0($4)
    /* 417AC0 00517AC0 040080AC */  sw         $0, 0x4($4)
    /* 417AC4 00517AC4 080080AC */  sw         $0, 0x8($4)
    /* 417AC8 00517AC8 0800E003 */  jr         $31
    /* 417ACC 00517ACC 0C0080AC */   sw        $0, 0xC($4)
.size func_00517ab8, 0x18

.section .text
.set noat
.set noreorder
glabel func_004e5390
    /* 3E5390 004E5390 2C0080AC */  sw         $0, 0x2C($4)
    /* 3E5394 004E5394 200080AC */  sw         $0, 0x20($4)
    /* 3E5398 004E5398 240080AC */  sw         $0, 0x24($4)
    /* 3E539C 004E539C 0800E003 */  jr         $31
    /* 3E53A0 004E53A0 280080AC */   sw        $0, 0x28($4)
    /* 3E53A4 004E53A4 00000000 */  nop
.size func_004e5390, 0x18

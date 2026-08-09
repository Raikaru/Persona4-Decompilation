.section .text
.set noat
.set noreorder
glabel func_001bc7f0
    /* BC7F0 001BC7F0 ACB3828F */  lw         $2, -0x4C54($28)
    /* BC7F4 001BC7F4 F4004294 */  lhu        $2, 0xF4($2)
    /* BC7F8 001BC7F8 0800E003 */  jr         $31
    /* BC7FC 001BC7FC 00000000 */   nop
.size func_001bc7f0, 0x10

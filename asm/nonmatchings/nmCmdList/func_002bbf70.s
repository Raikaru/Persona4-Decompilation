.section .text
.set noat
.set noreorder
glabel func_002bbf70
    /* 1BBF70 002BBF70 8800023C */  lui        $2, %hi(D_00882F60)
    /* 1BBF74 002BBF74 602F4224 */  addiu      $2, $2, %lo(D_00882F60)
    /* 1BBF78 002BBF78 0800E003 */  jr         $31
    /* 1BBF7C 002BBF7C 00000000 */   nop
.size func_002bbf70, 0x10

.section .text
.set noat
.set noreorder
glabel func_002bbf60
    /* 1BBF60 002BBF60 01000324 */  addiu      $3, $0, 0x1
    /* 1BBF64 002BBF64 78B583A3 */  sb         $3, -0x4A88($28)
    /* 1BBF68 002BBF68 0800E003 */  jr         $31
    /* 1BBF6C 002BBF6C 00000000 */   nop
.size func_002bbf60, 0x10

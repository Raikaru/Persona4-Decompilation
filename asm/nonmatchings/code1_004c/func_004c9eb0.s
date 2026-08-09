.section .text
.set noat
.set noreorder
glabel func_004c9eb0
    /* 3C9EB0 004C9EB0 002C0500 */  sll        $5, $5, 16
    /* 3C9EB4 004C9EB4 032C0500 */  sra        $5, $5, 16
    /* 3C9EB8 004C9EB8 02120500 */  srl        $2, $5, 8
    /* 3C9EBC 004C9EBC 010085A0 */  sb         $5, 0x1($4)
    /* 3C9EC0 004C9EC0 0800E003 */  jr         $31
    /* 3C9EC4 004C9EC4 000082A0 */   sb        $2, 0x0($4)
.size func_004c9eb0, 0x18

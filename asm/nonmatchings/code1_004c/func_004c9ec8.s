.section .text
.set noat
.set noreorder
glabel func_004c9ec8
    /* 3C9EC8 004C9EC8 002C0500 */  sll        $5, $5, 16
    /* 3C9ECC 004C9ECC 032C0500 */  sra        $5, $5, 16
    /* 3C9ED0 004C9ED0 02120500 */  srl        $2, $5, 8
    /* 3C9ED4 004C9ED4 000085A0 */  sb         $5, 0x0($4)
    /* 3C9ED8 004C9ED8 0800E003 */  jr         $31
    /* 3C9EDC 004C9EDC 010082A0 */   sb        $2, 0x1($4)
.size func_004c9ec8, 0x18

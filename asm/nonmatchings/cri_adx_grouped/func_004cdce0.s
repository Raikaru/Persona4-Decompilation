.section .text
.set noat
.set noreorder
glabel func_004cdce0
    /* 3CDCE0 004CDCE0 80280500 */  sll        $5, $5, 2
    /* 3CDCE4 004CDCE4 21208500 */  addu       $4, $4, $5
    /* 3CDCE8 004CDCE8 0800E003 */  jr         $31
    /* 3CDCEC 004CDCEC 0C0086AC */   sw        $6, 0xC($4)
.size func_004cdce0, 0x10

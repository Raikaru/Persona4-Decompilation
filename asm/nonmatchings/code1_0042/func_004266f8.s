.section .text
.set noat
.set noreorder
glabel func_004266f8
    /* 3266F8 004266F8 7100023C */  lui        $2, %hi(D_0070C684)
    /* 3266FC 004266FC 00861008 */  j          func_00421800
    /* 326700 00426700 84C6448C */   lw        $4, %lo(D_0070C684)($2)
    /* 326704 00426704 00000000 */  nop
.size func_004266f8, 0x10

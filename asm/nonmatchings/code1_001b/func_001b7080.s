.section .text
.set noat
.set noreorder
glabel func_001b7080
    /* B7080 001B7080 80FF023C */  lui        $2, (0xFF808080 >> 16)
    /* B7084 001B7084 80804234 */  ori        $2, $2, (0xFF808080 & 0xFFFF)
    /* B7088 001B7088 0800E003 */  jr         $31
    /* B708C 001B708C 00000000 */   nop
.size func_001b7080, 0x10

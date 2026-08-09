.section .text
.set noat
.set noreorder
glabel func_00506dd0
    /* 406DD0 00506DD0 FF0F033C */  lui        $3, (0xFFFFFFF >> 16)
    /* 406DD4 00506DD4 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 406DD8 00506DD8 FFFF6334 */  ori        $3, $3, (0xFFFFFFF & 0xFFFF)
    /* 406DDC 00506DDC 24208300 */  and        $4, $4, $3
    /* 406DE0 00506DE0 0800E003 */  jr         $31
    /* 406DE4 00506DE4 25108200 */   or        $2, $4, $2
.size func_00506dd0, 0x18

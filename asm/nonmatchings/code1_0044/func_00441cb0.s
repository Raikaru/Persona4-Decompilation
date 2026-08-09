.section .text
.set noat
.set noreorder
glabel func_00441cb0
    /* 341CB0 00441CB0 FF7F0D3C */  lui        $13, (0x7FFFFFFF >> 16)
    /* 341CB4 00441CB4 3F780400 */  dsra32     $15, $4, 0
    /* 341CB8 00441CB8 3F600500 */  dsra32     $12, $5, 0
    /* 341CBC 00441CBC FFFFAD35 */  ori        $13, $13, (0x7FFFFFFF & 0xFFFF)
    /* 341CC0 00441CC0 00800E3C */  lui        $14, (0x80000000 >> 16)
    /* 341CC4 00441CC4 2478ED01 */  and        $15, $15, $13
    /* 341CC8 00441CC8 24608E01 */  and        $12, $12, $14
    /* 341CCC 00441CCC 3C680400 */  dsll32     $13, $4, 0
    /* 341CD0 00441CD0 2578EC01 */  or         $15, $15, $12
    /* 341CD4 00441CD4 3E680D00 */  dsrl32     $13, $13, 0
    /* 341CD8 00441CD8 3C780F00 */  dsll32     $15, $15, 0
    /* 341CDC 00441CDC 3E780F00 */  dsrl32     $15, $15, 0
    /* 341CE0 00441CE0 3C780F00 */  dsll32     $15, $15, 0
    /* 341CE4 00441CE4 0800E003 */  jr         $31
    /* 341CE8 00441CE8 2510AF01 */   or        $2, $13, $15
    /* 341CEC 00441CEC 00000000 */  nop
.size func_00441cb0, 0x40

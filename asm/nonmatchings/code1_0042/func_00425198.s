.section .text
.set noat
.set noreorder
glabel func_00425198
    /* 325198 00425198 1000838C */  lw         $3, 0x10($4)
    /* 32519C 0042519C FFFF023C */  lui        $2, (0xFFFFFFFE >> 16)
    /* 3251A0 004251A0 FEFF4234 */  ori        $2, $2, (0xFFFFFFFE & 0xFFFF)
    /* 3251A4 004251A4 180080AC */  sw         $0, 0x18($4)
    /* 3251A8 004251A8 24186200 */  and        $3, $3, $2
    /* 3251AC 004251AC 0800E003 */  jr         $31
    /* 3251B0 004251B0 100083AC */   sw        $3, 0x10($4)
    /* 3251B4 004251B4 00000000 */  nop
.size func_00425198, 0x20

.section .text
.set noat
.set noreorder
glabel func_0041bec8
    /* 31BEC8 0041BEC8 0010023C */  lui        $2, (0x10002010 >> 16)
    /* 31BECC 0041BECC 0080053C */  lui        $5, (0x80004000 >> 16)
    /* 31BED0 0041BED0 10204234 */  ori        $2, $2, (0x10002010 & 0xFFFF)
    /* 31BED4 0041BED4 0040A534 */  ori        $5, $5, (0x80004000 & 0xFFFF)
    /* 31BED8 0041BED8 0000438C */  lw         $3, 0x0($2)
    /* 31BEDC 0041BEDC 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 31BEE0 0041BEE0 24186500 */  and        $3, $3, $5
    /* 31BEE4 0041BEE4 03006214 */  bne        $3, $2, .L0041BEF4
    /* 31BEE8 0041BEE8 00000000 */   nop
    /* 31BEEC 0041BEEC 746E1008 */  j          func_0041b9d0
    /* 31BEF0 0041BEF0 00000000 */   nop
  .L0041BEF4:
    /* 31BEF4 0041BEF4 0800E003 */  jr         $31
    /* 31BEF8 0041BEF8 00000000 */   nop
    /* 31BEFC 0041BEFC 00000000 */  nop
.size func_0041bec8, 0x38

.section .text
.set noat
.set noreorder
glabel func_0042ba70
    /* 32BA70 0042BA70 00600240 */  mfc0       $2, $12 /* handwritten instruction */
    /* 32BA74 0042BA74 0100033C */  lui        $3, (0x10000 >> 16)
    /* 32BA78 0042BA78 24104300 */  and        $2, $2, $3
    /* 32BA7C 0042BA7C 38000042 */  ei /* handwritten instruction */
    /* 32BA80 0042BA80 0800E003 */  jr         $31
    /* 32BA84 0042BA84 2B100200 */   sltu      $2, $0, $2
.size func_0042ba70, 0x18

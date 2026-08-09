.section .text
.set noat
.set noreorder
glabel func_0033d390
    /* 23D390 0033D390 3800828C */  lw         $2, 0x38($4)
    /* 23D394 0033D394 04004384 */  lh         $3, 0x4($2)
    /* 23D398 0033D398 01000224 */  addiu      $2, $0, 0x1
    /* 23D39C 0033D39C 0410A200 */  sllv       $2, $2, $5
    /* 23D3A0 0033D3A0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 23D3A4 0033D3A4 24106200 */  and        $2, $3, $2
    /* 23D3A8 0033D3A8 0710A200 */  srav       $2, $2, $5
    /* 23D3AC 0033D3AC 0800E003 */  jr         $31
    /* 23D3B0 0033D3B0 00000000 */   nop
    /* 23D3B4 0033D3B4 00000000 */  nop
    /* 23D3B8 0033D3B8 00000000 */  nop
    /* 23D3BC 0033D3BC 00000000 */  nop
.size func_0033d390, 0x30

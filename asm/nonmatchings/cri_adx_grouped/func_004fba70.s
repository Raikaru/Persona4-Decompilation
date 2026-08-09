.section .text
.set noat
.set noreorder
glabel func_004fba70
    /* 3FBA70 004FBA70 40100500 */  sll        $2, $5, 1
    /* 3FBA74 004FBA74 21104500 */  addu       $2, $2, $5
    /* 3FBA78 004FBA78 80100200 */  sll        $2, $2, 2
    /* 3FBA7C 004FBA7C 21208200 */  addu       $4, $4, $2
    /* 3FBA80 004FBA80 18018424 */  addiu      $4, $4, 0x118
    /* 3FBA84 004FBA84 080088AC */  sw         $8, 0x8($4)
    /* 3FBA88 004FBA88 000086AC */  sw         $6, 0x0($4)
    /* 3FBA8C 004FBA8C 0800E003 */  jr         $31
    /* 3FBA90 004FBA90 040087AC */   sw        $7, 0x4($4)
    /* 3FBA94 004FBA94 00000000 */  nop
.size func_004fba70, 0x28

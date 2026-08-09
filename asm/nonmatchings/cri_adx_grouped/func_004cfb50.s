.section .text
.set noat
.set noreorder
glabel func_004cfb50
    /* 3CFB50 004CFB50 40280500 */  sll        $5, $5, 1
    /* 3CFB54 004CFB54 2D100000 */  daddu      $2, $0, $0
    /* 3CFB58 004CFB58 02008010 */  beqz       $4, .L004CFB64
    /* 3CFB5C 004CFB5C 2128A400 */   addu      $5, $5, $4
    /* 3CFB60 004CFB60 1800A284 */  lh         $2, 0x18($5)
  .L004CFB64:
    /* 3CFB64 004CFB64 0800E003 */  jr         $31
    /* 3CFB68 004CFB68 00000000 */   nop
    /* 3CFB6C 004CFB6C 00000000 */  nop
.size func_004cfb50, 0x20

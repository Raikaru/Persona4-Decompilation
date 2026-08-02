.section .text
.set noat
.set noreorder
glabel func_0010abd0
    /* ABD0 0010ABD0 3C1C0400 */  dsll32     $3, $4, 16
    /* ABD4 0010ABD4 3F1C0300 */  dsra32     $3, $3, 16
    /* ABD8 0010ABD8 40100300 */  sll        $2, $3, 1
    /* ABDC 0010ABDC 21104300 */  addu       $2, $2, $3
    /* ABE0 0010ABE0 00190200 */  sll        $3, $2, 4
    /* ABE4 0010ABE4 7900023C */  lui        $2, %hi(D_00797F8C)
    /* ABE8 0010ABE8 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* ABEC 0010ABEC 21104300 */  addu       $2, $2, $3
    /* ABF0 0010ABF0 00004294 */  lhu        $2, 0x0($2)
    /* ABF4 0010ABF4 01004230 */  andi       $2, $2, 0x1
    /* ABF8 0010ABF8 2B100200 */  sltu       $2, $0, $2
    /* ABFC 0010ABFC 0800E003 */  jr         $31
    /* AC00 0010AC00 00000000 */   nop
    /* AC04 0010AC04 00000000 */  nop
    /* AC08 0010AC08 00000000 */  nop
    /* AC0C 0010AC0C 00000000 */  nop
.size func_0010abd0, 0x40

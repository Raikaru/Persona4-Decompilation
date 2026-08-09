.section .text
.set noat
.set noreorder
glabel func_0043fbe0
    /* 33FBE0 0043FBE0 0800A010 */  beqz       $5, .L0043FC04
    /* 33FBE4 0043FBE4 00000000 */   nop
    /* 33FBE8 0043FBE8 0400AF8C */  lw         $15, 0x4($5)
    /* 33FBEC 0043FBEC 4C008D8C */  lw         $13, 0x4C($4)
    /* 33FBF0 0043FBF0 80780F00 */  sll        $15, $15, 2
    /* 33FBF4 0043FBF4 2178ED01 */  addu       $15, $15, $13
    /* 33FBF8 0043FBF8 0000EE8D */  lw         $14, 0x0($15)
    /* 33FBFC 0043FBFC 0000AEAC */  sw         $14, 0x0($5)
    /* 33FC00 0043FC00 0000E5AD */  sw         $5, 0x0($15)
  .L0043FC04:
    /* 33FC04 0043FC04 0800E003 */  jr         $31
    /* 33FC08 0043FC08 00000000 */   nop
    /* 33FC0C 0043FC0C 00000000 */  nop
.size func_0043fbe0, 0x30

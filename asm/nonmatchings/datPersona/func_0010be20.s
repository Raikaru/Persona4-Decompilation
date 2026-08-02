.section .text
.set noat
.set noreorder
glabel func_0010be20
    /* BE20 0010BE20 02008394 */  lhu        $3, 0x2($4)
    /* BE24 0010BE24 C0006228 */  slti       $2, $3, 0xC0
    /* BE28 0010BE28 07004014 */  bnez       $2, .L0010BE48
    /* BE2C 0010BE2C 00000000 */   nop
    /* BE30 0010BE30 D8006128 */  slti       $1, $3, 0xD8
    /* BE34 0010BE34 04002010 */  beqz       $1, .L0010BE48
    /* BE38 0010BE38 00000000 */   nop
    /* BE3C 0010BE3C 01000224 */  addiu      $2, $0, 0x1
    /* BE40 0010BE40 02000010 */  b          .L0010BE4C
    /* BE44 0010BE44 00000000 */   nop
  .L0010BE48:
    /* BE48 0010BE48 2D100000 */  daddu      $2, $0, $0
  .L0010BE4C:
    /* BE4C 0010BE4C 0800E003 */  jr         $31
    /* BE50 0010BE50 00000000 */   nop
    /* BE54 0010BE54 00000000 */  nop
    /* BE58 0010BE58 00000000 */  nop
    /* BE5C 0010BE5C 00000000 */  nop
.size func_0010be20, 0x40

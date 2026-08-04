.section .text
.set noat
.set noreorder
glabel func_001bbf40
    /* BBF40 001BBF40 7042033C */  lui        $3, (0x42700000 >> 16)
    /* BBF44 001BBF44 00008344 */  mtc1       $3, $f0
    /* BBF48 001BBF48 00000000 */  nop
    /* BBF4C 001BBF4C 42000C46 */  mul.s      $f1, $f0, $f12
    /* BBF50 001BBF50 0040033C */  lui        $3, (0x40000000 >> 16)
    /* BBF54 001BBF54 00008344 */  mtc1       $3, $f0
    /* BBF58 001BBF58 00000000 */  nop
    /* BBF5C 001BBF5C 03080046 */  div.s      $f0, $f1, $f0
    /* BBF60 001BBF60 840080E4 */  swc1       $f0, 0x84($4)
    /* BBF64 001BBF64 00008394 */  lhu        $3, 0x0($4)
    /* BBF68 001BBF68 FDFF6330 */  andi       $3, $3, 0xFFFD
    /* BBF6C 001BBF6C 000083A4 */  sh         $3, 0x0($4)
    /* BBF70 001BBF70 00008394 */  lhu        $3, 0x0($4)
    /* BBF74 001BBF74 FBFF6330 */  andi       $3, $3, 0xFFFB
    /* BBF78 001BBF78 000083A4 */  sh         $3, 0x0($4)
    /* BBF7C 001BBF7C 00008394 */  lhu        $3, 0x0($4)
    /* BBF80 001BBF80 F7FF6330 */  andi       $3, $3, 0xFFF7
    /* BBF84 001BBF84 000083A4 */  sh         $3, 0x0($4)
    /* BBF88 001BBF88 0800E003 */  jr         $31
    /* BBF8C 001BBF8C 00000000 */   nop
.size func_001bbf40, 0x50

.section .text
.set noat
.set noreorder
glabel func_0047ea70
    /* 37EA70 0047EA70 000080AC */  sw         $0, 0x0($4)
    /* 37EA74 0047EA74 FFFF0324 */  addiu      $3, $0, -0x1
    /* 37EA78 0047EA78 080083A4 */  sh         $3, 0x8($4)
    /* 37EA7C 0047EA7C 160083A4 */  sh         $3, 0x16($4)
    /* 37EA80 0047EA80 240083A4 */  sh         $3, 0x24($4)
    /* 37EA84 0047EA84 260083A4 */  sh         $3, 0x26($4)
    /* 37EA88 0047EA88 10008394 */  lhu        $3, 0x10($4)
    /* 37EA8C 0047EA8C 20006334 */  ori        $3, $3, 0x20
    /* 37EA90 0047EA90 100083A4 */  sh         $3, 0x10($4)
    /* 37EA94 0047EA94 0800E003 */  jr         $31
    /* 37EA98 0047EA98 00000000 */   nop
    /* 37EA9C 0047EA9C 00000000 */  nop
.size func_0047ea70, 0x30

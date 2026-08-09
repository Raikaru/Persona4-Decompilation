.section .text
.set noat
.set noreorder
glabel func_003c1b90
    /* 2C1B90 003C1B90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C1B94 003C1B94 1000BFFF */  sd         $31, 0x10($29)
    /* 2C1B98 003C1B98 0000B07F */  sq         $16, 0x0($29)
    /* 2C1B9C 003C1B9C 48BF0F0C */  jal        func_003efd20
    /* 2C1BA0 003C1BA0 2D808000 */   daddu     $16, $4, $0
    /* 2C1BA4 003C1BA4 03000392 */  lbu        $3, 0x3($16)
    /* 2C1BA8 003C1BA8 2D100002 */  daddu      $2, $16, $0
    /* 2C1BAC 003C1BAC 01006334 */  ori        $3, $3, 0x1
    /* 2C1BB0 003C1BB0 030003A2 */  sb         $3, 0x3($16)
    /* 2C1BB4 003C1BB4 1000BFDF */  ld         $31, 0x10($29)
    /* 2C1BB8 003C1BB8 0000B07B */  lq         $16, 0x0($29)
    /* 2C1BBC 003C1BBC 0800E003 */  jr         $31
    /* 2C1BC0 003C1BC0 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C1BC4 003C1BC4 00000000 */  nop
    /* 2C1BC8 003C1BC8 00000000 */  nop
    /* 2C1BCC 003C1BCC 00000000 */  nop
.size func_003c1b90, 0x40

.section .text
.set noat
.set noreorder
glabel func_001db8d0
    /* DB8D0 001DB8D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB8D4 001DB8D4 0000BFFF */  sd         $31, 0x0($29)
    /* DB8D8 001DB8D8 3000828C */  lw         $2, 0x30($4)
    /* DB8DC 001DB8DC 640A448C */  lw         $4, 0xA64($2)
    /* DB8E0 001DB8E0 30D0080C */  jal        func_002340c0
    /* DB8E4 001DB8E4 00000000 */   nop
    /* DB8E8 001DB8E8 2B100200 */  sltu       $2, $0, $2
    /* DB8EC 001DB8EC 0000BFDF */  ld         $31, 0x0($29)
    /* DB8F0 001DB8F0 1000BD27 */  addiu      $29, $29, 0x10
    /* DB8F4 001DB8F4 0800E003 */  jr         $31
    /* DB8F8 001DB8F8 00000000 */   nop
    /* DB8FC 001DB8FC 00000000 */  nop
.size func_001db8d0, 0x30

.section .text
.set noat
.set noreorder
glabel func_00511eb0
    /* 411EB0 00511EB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411EB4 00511EB4 0000BFFF */  sd         $31, 0x0($29)
    /* 411EB8 00511EB8 6847140C */  jal        func_00511da0
    /* 411EBC 00511EBC 00000000 */   nop
    /* 411EC0 00511EC0 01004238 */  xori       $2, $2, 0x1
    /* 411EC4 00511EC4 0000BFDF */  ld         $31, 0x0($29)
    /* 411EC8 00511EC8 2B100200 */  sltu       $2, $0, $2
    /* 411ECC 00511ECC 0800E003 */  jr         $31
    /* 411ED0 00511ED0 1000BD27 */   addiu     $29, $29, 0x10
    /* 411ED4 00511ED4 00000000 */  nop
.size func_00511eb0, 0x28

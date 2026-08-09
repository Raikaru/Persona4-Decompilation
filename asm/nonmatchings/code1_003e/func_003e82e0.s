.section .text
.set noat
.set noreorder
glabel func_003e82e0
    /* 2E82E0 003E82E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E82E4 003E82E4 1000BFFF */  sd         $31, 0x10($29)
    /* 2E82E8 003E82E8 0000B07F */  sq         $16, 0x0($29)
    /* 2E82EC 003E82EC 2D808000 */  daddu      $16, $4, $0
    /* 2E82F0 003E82F0 20B10F0C */  jal        func_003ec480
    /* 2E82F4 003E82F4 6000848C */   lw        $4, 0x60($4)
    /* 2E82F8 003E82F8 0A800200 */  movz       $16, $0, $2
    /* 2E82FC 003E82FC 2D100002 */  daddu      $2, $16, $0
    /* 2E8300 003E8300 1000BFDF */  ld         $31, 0x10($29)
    /* 2E8304 003E8304 0000B07B */  lq         $16, 0x0($29)
    /* 2E8308 003E8308 0800E003 */  jr         $31
    /* 2E830C 003E830C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003e82e0, 0x30

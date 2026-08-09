.section .text
.set noat
.set noreorder
glabel func_0025ec10
    /* 15EC10 0025EC10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 15EC14 0025EC14 1000BFFF */  sd         $31, 0x10($29)
    /* 15EC18 0025EC18 0000B07F */  sq         $16, 0x0($29)
    /* 15EC1C 0025EC1C 2D80A000 */  daddu      $16, $5, $0
    /* 15EC20 0025EC20 2D200002 */  daddu      $4, $16, $0
    /* 15EC24 0025EC24 01000524 */  addiu      $5, $0, 0x1
    /* 15EC28 0025EC28 E0AC110C */  jal        func_0046b380
    /* 15EC2C 0025EC2C 00000000 */   nop
    /* 15EC30 0025EC30 2D200002 */  daddu      $4, $16, $0
    /* 15EC34 0025EC34 A0B4110C */  jal        func_0046d280
    /* 15EC38 0025EC38 00000000 */   nop
    /* 15EC3C 0025EC3C 1000BFDF */  ld         $31, 0x10($29)
    /* 15EC40 0025EC40 0000B07B */  lq         $16, 0x0($29)
    /* 15EC44 0025EC44 2000BD27 */  addiu      $29, $29, 0x20
    /* 15EC48 0025EC48 0800E003 */  jr         $31
    /* 15EC4C 0025EC4C 00000000 */   nop
.size func_0025ec10, 0x40

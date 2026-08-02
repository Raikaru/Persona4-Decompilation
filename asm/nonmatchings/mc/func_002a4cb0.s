.section .text
.set noat
.set noreorder
glabel func_002a4cb0
    /* 1A4CB0 002A4CB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1A4CB4 002A4CB4 1000BFFF */  sd         $31, 0x10($29)
    /* 1A4CB8 002A4CB8 0000B07F */  sq         $16, 0x0($29)
    /* 1A4CBC 002A4CBC 5849110C */  jal        func_00452560
    /* 1A4CC0 002A4CC0 00000000 */   nop
    /* 1A4CC4 002A4CC4 2D804000 */  daddu      $16, $2, $0
    /* 1A4CC8 002A4CC8 A403448C */  lw         $4, 0x3A4($2)
    /* 1A4CCC 002A4CCC 04008010 */  beqz       $4, .L002A4CE0
    /* 1A4CD0 002A4CD0 00000000 */   nop
    /* 1A4CD4 002A4CD4 F452110C */  jal        func_00454bd0
    /* 1A4CD8 002A4CD8 00000000 */   nop
    /* 1A4CDC 002A4CDC A40300AE */  sw         $0, 0x3A4($16)
  .L002A4CE0:
    /* 1A4CE0 002A4CE0 9803048E */  lw         $4, 0x398($16)
    /* 1A4CE4 002A4CE4 8C7C090C */  jal        func_0025f230
    /* 1A4CE8 002A4CE8 00000000 */   nop
    /* 1A4CEC 002A4CEC 2D200002 */  daddu      $4, $16, $0
    /* 1A4CF0 002A4CF0 ACA80A0C */  jal        func_002aa2b0
    /* 1A4CF4 002A4CF4 00000000 */   nop
    /* 1A4CF8 002A4CF8 1000BFDF */  ld         $31, 0x10($29)
    /* 1A4CFC 002A4CFC 0000B07B */  lq         $16, 0x0($29)
    /* 1A4D00 002A4D00 2000BD27 */  addiu      $29, $29, 0x20
    /* 1A4D04 002A4D04 0800E003 */  jr         $31
    /* 1A4D08 002A4D08 00000000 */   nop
    /* 1A4D0C 002A4D0C 00000000 */  nop
.size func_002a4cb0, 0x60

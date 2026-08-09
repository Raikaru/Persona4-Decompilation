.section .text
.set noat
.set noreorder
glabel func_00515cc8
    /* 415CC8 00515CC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 415CCC 00515CCC 31000524 */  addiu      $5, $0, 0x31
    /* 415CD0 00515CD0 0000B0FF */  sd         $16, 0x0($29)
    /* 415CD4 00515CD4 0800BFFF */  sd         $31, 0x8($29)
    /* 415CD8 00515CD8 2694140C */  jal        func_00525098
    /* 415CDC 00515CDC 2D808000 */   daddu     $16, $4, $0
    /* 415CE0 00515CE0 2D200002 */  daddu      $4, $16, $0
    /* 415CE4 00515CE4 05004014 */  bnez       $2, .L00515CFC
    /* 415CE8 00515CE8 39000524 */   addiu     $5, $0, 0x39
    /* 415CEC 00515CEC 2694140C */  jal        func_00525098
    /* 415CF0 00515CF0 00000000 */   nop
    /* 415CF4 00515CF4 03004010 */  beqz       $2, .L00515D04
    /* 415CF8 00515CF8 0000B0DF */   ld        $16, 0x0($29)
  .L00515CFC:
    /* 415CFC 00515CFC 01000224 */  addiu      $2, $0, 0x1
    /* 415D00 00515D00 0000B0DF */  ld         $16, 0x0($29)
  .L00515D04:
    /* 415D04 00515D04 0800BFDF */  ld         $31, 0x8($29)
    /* 415D08 00515D08 0800E003 */  jr         $31
    /* 415D0C 00515D0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00515cc8, 0x48

.section .text
.set noat
.set noreorder
glabel func_003cb210
    /* 2CB210 003CB210 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB214 003CB214 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB218 003CB218 0000B07F */  sq         $16, 0x0($29)
    /* 2CB21C 003CB21C 14B7828F */  lw         $2, -0x48EC($28)
    /* 2CB220 003CB220 2D808000 */  daddu      $16, $4, $0
    /* 2CB224 003CB224 2110A200 */  addu       $2, $5, $2
    /* 2CB228 003CB228 0000448C */  lw         $4, 0x0($2)
    /* 2CB22C 003CB22C 03008010 */  beqz       $4, .L003CB23C
    /* 2CB230 003CB230 00000000 */   nop
    /* 2CB234 003CB234 A02F0F0C */  jal        func_003cbe80
    /* 2CB238 003CB238 2D280002 */   daddu     $5, $16, $0
  .L003CB23C:
    /* 2CB23C 003CB23C 2D100002 */  daddu      $2, $16, $0
    /* 2CB240 003CB240 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB244 003CB244 0000B07B */  lq         $16, 0x0($29)
    /* 2CB248 003CB248 0800E003 */  jr         $31
    /* 2CB24C 003CB24C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb210, 0x40

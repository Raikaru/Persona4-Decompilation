.section .text
.set noat
.set noreorder
glabel func_0019bf80
    /* 9BF80 0019BF80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9BF84 0019BF84 1000BFFF */  sd         $31, 0x10($29)
    /* 9BF88 0019BF88 0000B07F */  sq         $16, 0x0($29)
    /* 9BF8C 0019BF8C 2D808000 */  daddu      $16, $4, $0
    /* 9BF90 0019BF90 0000838C */  lw         $3, 0x0($4)
    /* 9BF94 0019BF94 0C00828C */  lw         $2, 0xC($4)
    /* 9BF98 0019BF98 0B004014 */  bnez       $2, .L0019BFC8
    /* 9BF9C 0019BF9C 00000000 */   nop
    /* 9BFA0 0019BFA0 000A648C */  lw         $4, 0xA00($3)
    /* 9BFA4 0019BFA4 D002828C */  lw         $2, 0x2D0($4)
    /* 9BFA8 0019BFA8 03004014 */  bnez       $2, .L0019BFB8
    /* 9BFAC 0019BFAC 00000000 */   nop
    /* 9BFB0 0019BFB0 5CF4110C */  jal        func_0047d170
    /* 9BFB4 0019BFB4 00000000 */   nop
  .L0019BFB8:
    /* 9BFB8 0019BFB8 01000224 */  addiu      $2, $0, 0x1
    /* 9BFBC 0019BFBC 0C0002AE */  sw         $2, 0xC($16)
    /* 9BFC0 0019BFC0 0A000010 */  b          .L0019BFEC
    /* 9BFC4 0019BFC4 00000000 */   nop
  .L0019BFC8:
    /* 9BFC8 0019BFC8 000A628C */  lw         $2, 0xA00($3)
    /* 9BFCC 0019BFCC D0024424 */  addiu      $4, $2, 0x2D0
    /* 9BFD0 0019BFD0 BCF9110C */  jal        func_0047e6f0
    /* 9BFD4 0019BFD4 00000000 */   nop
    /* 9BFD8 0019BFD8 04004010 */  beqz       $2, .L0019BFEC
    /* 9BFDC 0019BFDC 00000000 */   nop
    /* 9BFE0 0019BFE0 01000224 */  addiu      $2, $0, 0x1
    /* 9BFE4 0019BFE4 02000010 */  b          .L0019BFF0
    /* 9BFE8 0019BFE8 00000000 */   nop
  .L0019BFEC:
    /* 9BFEC 0019BFEC 2D100000 */  daddu      $2, $0, $0
  .L0019BFF0:
    /* 9BFF0 0019BFF0 1000BFDF */  ld         $31, 0x10($29)
    /* 9BFF4 0019BFF4 0000B07B */  lq         $16, 0x0($29)
    /* 9BFF8 0019BFF8 2000BD27 */  addiu      $29, $29, 0x20
    /* 9BFFC 0019BFFC 0800E003 */  jr         $31
    /* 9C000 0019C000 00000000 */   nop
    /* 9C004 0019C004 00000000 */  nop
    /* 9C008 0019C008 00000000 */  nop
    /* 9C00C 0019C00C 00000000 */  nop
.size func_0019bf80, 0x90

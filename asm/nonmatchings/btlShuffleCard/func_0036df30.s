.section .text
.set noat
.set noreorder
glabel func_0036df30
    /* 26DF30 0036DF30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26DF34 0036DF34 1000BFFF */  sd         $31, 0x10($29)
    /* 26DF38 0036DF38 0000B07F */  sq         $16, 0x0($29)
    /* 26DF3C 0036DF3C 2D808000 */  daddu      $16, $4, $0
    /* 26DF40 0036DF40 A80F858C */  lw         $5, 0xFA8($4)
    /* 26DF44 0036DF44 0400A010 */  beqz       $5, .L0036DF58
    /* 26DF48 0036DF48 00000000 */   nop
    /* 26DF4C 0036DF4C 00060426 */  addiu      $4, $16, 0x600
    /* 26DF50 0036DF50 8CAD0D0C */  jal        func_0036b630
    /* 26DF54 0036DF54 00000000 */   nop
  .L0036DF58:
    /* 26DF58 0036DF58 2D200002 */  daddu      $4, $16, $0
    /* 26DF5C 0036DF5C A0A30D0C */  jal        func_00368e80
    /* 26DF60 0036DF60 00000000 */   nop
    /* 26DF64 0036DF64 2D200002 */  daddu      $4, $16, $0
    /* 26DF68 0036DF68 34A50D0C */  jal        func_003694d0
    /* 26DF6C 0036DF6C 00000000 */   nop
    /* 26DF70 0036DF70 1000BFDF */  ld         $31, 0x10($29)
    /* 26DF74 0036DF74 0000B07B */  lq         $16, 0x0($29)
    /* 26DF78 0036DF78 2000BD27 */  addiu      $29, $29, 0x20
    /* 26DF7C 0036DF7C 0800E003 */  jr         $31
    /* 26DF80 0036DF80 00000000 */   nop
    /* 26DF84 0036DF84 00000000 */  nop
    /* 26DF88 0036DF88 00000000 */  nop
    /* 26DF8C 0036DF8C 00000000 */  nop
.size func_0036df30, 0x60

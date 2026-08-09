.section .text
.set noat
.set noreorder
glabel func_003cfa30
    /* 2CFA30 003CFA30 07008010 */  beqz       $4, .L003CFA50
    /* 2CFA34 003CFA34 00000000 */   nop
    /* 2CFA38 003CFA38 1400828C */  lw         $2, 0x14($4)
    /* 2CFA3C 003CFA3C 06004010 */  beqz       $2, .L003CFA58
    /* 2CFA40 003CFA40 00000000 */   nop
    /* 2CFA44 003CFA44 180045AC */  sw         $5, 0x18($2)
    /* 2CFA48 003CFA48 04000010 */  b          .L003CFA5C
    /* 2CFA4C 003CFA4C 2D108000 */   daddu     $2, $4, $0
  .L003CFA50:
    /* 2CFA50 003CFA50 02000010 */  b          .L003CFA5C
    /* 2CFA54 003CFA54 2D100000 */   daddu     $2, $0, $0
  .L003CFA58:
    /* 2CFA58 003CFA58 2D100000 */  daddu      $2, $0, $0
  .L003CFA5C:
    /* 2CFA5C 003CFA5C 0800E003 */  jr         $31
    /* 2CFA60 003CFA60 00000000 */   nop
    /* 2CFA64 003CFA64 00000000 */  nop
    /* 2CFA68 003CFA68 00000000 */  nop
    /* 2CFA6C 003CFA6C 00000000 */  nop
.size func_003cfa30, 0x40

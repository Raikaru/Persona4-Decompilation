.section .text
.set noat
.set noreorder
glabel func_00519e90
    /* 419E90 00519E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419E94 00519E94 0000B0FF */  sd         $16, 0x0($29)
    /* 419E98 00519E98 2D808000 */  daddu      $16, $4, $0
    /* 419E9C 00519E9C 0800BFFF */  sd         $31, 0x8($29)
    /* 419EA0 00519EA0 B036038E */  lw         $3, 0x36B0($16)
    /* 419EA4 00519EA4 09006010 */  beqz       $3, .L00519ECC
    /* 419EA8 00519EA8 2D100000 */   daddu     $2, $0, $0
    /* 419EAC 00519EAC B867140C */  jal        func_00519ee0
    /* 419EB0 00519EB0 00000000 */   nop
    /* 419EB4 00519EB4 04004058 */  blezl      $2, .L00519EC8
    /* 419EB8 00519EB8 B036028E */   lw        $2, 0x36B0($16)
    /* 419EBC 00519EBC 03000010 */  b          .L00519ECC
    /* 419EC0 00519EC0 2D100000 */   daddu     $2, $0, $0
    /* 419EC4 00519EC4 00000000 */  nop
  .L00519EC8:
    /* 419EC8 00519EC8 A0084224 */  addiu      $2, $2, 0x8A0
  .L00519ECC:
    /* 419ECC 00519ECC 0000B0DF */  ld         $16, 0x0($29)
    /* 419ED0 00519ED0 0800BFDF */  ld         $31, 0x8($29)
    /* 419ED4 00519ED4 0800E003 */  jr         $31
    /* 419ED8 00519ED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 419EDC 00519EDC 00000000 */  nop
.size func_00519e90, 0x50

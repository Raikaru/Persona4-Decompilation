.section .text
.set noat
.set noreorder
glabel func_003cffa0
    /* 2CFFA0 003CFFA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CFFA4 003CFFA4 2D18A000 */  daddu      $3, $5, $0
    /* 2CFFA8 003CFFA8 1000BFFF */  sd         $31, 0x10($29)
    /* 2CFFAC 003CFFAC 0000B07F */  sq         $16, 0x0($29)
    /* 2CFFB0 003CFFB0 02008290 */  lbu        $2, 0x2($4)
    /* 2CFFB4 003CFFB4 01004230 */  andi       $2, $2, 0x1
    /* 2CFFB8 003CFFB8 03004014 */  bnez       $2, .L003CFFC8
    /* 2CFFBC 003CFFBC 2D808000 */   daddu     $16, $4, $0
  .L003CFFC0:
    /* 2CFFC0 003CFFC0 07000010 */  b          .L003CFFE0
    /* 2CFFC4 003CFFC4 2D100002 */   daddu     $2, $16, $0
  .L003CFFC8:
    /* 2CFFC8 003CFFC8 50006CC4 */  lwc1       $f12, 0x50($3)
    /* 2CFFCC 003CFFCC 54006DC4 */  lwc1       $f13, 0x54($3)
    /* 2CFFD0 003CFFD0 A03E0F0C */  jal        func_003cfa80
    /* 2CFFD4 003CFFD4 10006524 */   addiu     $5, $3, 0x10
    /* 2CFFD8 003CFFD8 F9FF0010 */  b          .L003CFFC0
    /* 2CFFDC 003CFFDC 00000000 */   nop
  .L003CFFE0:
    /* 2CFFE0 003CFFE0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CFFE4 003CFFE4 0000B07B */  lq         $16, 0x0($29)
    /* 2CFFE8 003CFFE8 0800E003 */  jr         $31
    /* 2CFFEC 003CFFEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cffa0, 0x50

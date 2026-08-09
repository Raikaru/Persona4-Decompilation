.section .text
.set noat
.set noreorder
glabel func_001fac80
    /* FAC80 001FAC80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FAC84 001FAC84 1000BFFF */  sd         $31, 0x10($29)
    /* FAC88 001FAC88 0000B07F */  sq         $16, 0x0($29)
    /* FAC8C 001FAC8C 2D808000 */  daddu      $16, $4, $0
    /* FAC90 001FAC90 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAC94 001FAC94 0C00438C */  lw         $3, 0xC($2)
    /* FAC98 001FAC98 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAC9C 001FAC9C 24106200 */  and        $2, $3, $2
    /* FACA0 001FACA0 15004010 */  beqz       $2, .L001FACF8
    /* FACA4 001FACA4 00000000 */   nop
    /* FACA8 001FACA8 40AF080C */  jal        func_0022bd00
    /* FACAC 001FACAC 00000000 */   nop
    /* FACB0 001FACB0 0B004014 */  bnez       $2, .L001FACE0
    /* FACB4 001FACB4 00000000 */   nop
    /* FACB8 001FACB8 ACB3838F */  lw         $3, -0x4C54($28)
    /* FACBC 001FACBC 400B628C */  lw         $2, 0xB40($3)
    /* FACC0 001FACC0 07004010 */  beqz       $2, .L001FACE0
    /* FACC4 001FACC4 00000000 */   nop
    /* FACC8 001FACC8 480B648C */  lw         $4, 0xB48($3)
    /* FACCC 001FACCC 09F84000 */  jalr       $2
    /* FACD0 001FACD0 00000000 */   nop
    /* FACD4 001FACD4 01000224 */  addiu      $2, $0, 0x1
    /* FACD8 001FACD8 08000010 */  b          .L001FACFC
    /* FACDC 001FACDC 00000000 */   nop
  .L001FACE0:
    /* FACE0 001FACE0 2D200002 */  daddu      $4, $16, $0
    /* FACE4 001FACE4 03000524 */  addiu      $5, $0, 0x3
    /* FACE8 001FACE8 B4AE080C */  jal        func_0022bad0
    /* FACEC 001FACEC 00000000 */   nop
    /* FACF0 001FACF0 02000010 */  b          .L001FACFC
    /* FACF4 001FACF4 00000000 */   nop
  .L001FACF8:
    /* FACF8 001FACF8 2D100000 */  daddu      $2, $0, $0
  .L001FACFC:
    /* FACFC 001FACFC 1000BFDF */  ld         $31, 0x10($29)
    /* FAD00 001FAD00 0000B07B */  lq         $16, 0x0($29)
    /* FAD04 001FAD04 2000BD27 */  addiu      $29, $29, 0x20
    /* FAD08 001FAD08 0800E003 */  jr         $31
    /* FAD0C 001FAD0C 00000000 */   nop
.size func_001fac80, 0x90

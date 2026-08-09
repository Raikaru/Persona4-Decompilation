.section .text
.set noat
.set noreorder
glabel func_001fad10
    /* FAD10 001FAD10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FAD14 001FAD14 1000BFFF */  sd         $31, 0x10($29)
    /* FAD18 001FAD18 0000B07F */  sq         $16, 0x0($29)
    /* FAD1C 001FAD1C 2D800000 */  daddu      $16, $0, $0
    /* FAD20 001FAD20 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAD24 001FAD24 0C00438C */  lw         $3, 0xC($2)
    /* FAD28 001FAD28 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAD2C 001FAD2C 24106200 */  and        $2, $3, $2
    /* FAD30 001FAD30 1B004010 */  beqz       $2, .L001FADA0
    /* FAD34 001FAD34 00000000 */   nop
    /* FAD38 001FAD38 40AF080C */  jal        func_0022bd00
    /* FAD3C 001FAD3C 00000000 */   nop
    /* FAD40 001FAD40 11004014 */  bnez       $2, .L001FAD88
    /* FAD44 001FAD44 00000000 */   nop
    /* FAD48 001FAD48 ACB3838F */  lw         $3, -0x4C54($28)
    /* FAD4C 001FAD4C 440B628C */  lw         $2, 0xB44($3)
    /* FAD50 001FAD50 0D004010 */  beqz       $2, .L001FAD88
    /* FAD54 001FAD54 00000000 */   nop
    /* FAD58 001FAD58 480B648C */  lw         $4, 0xB48($3)
    /* FAD5C 001FAD5C 09F84000 */  jalr       $2
    /* FAD60 001FAD60 00000000 */   nop
    /* FAD64 001FAD64 2D804000 */  daddu      $16, $2, $0
    /* FAD68 001FAD68 07000016 */  bnez       $16, .L001FAD88
    /* FAD6C 001FAD6C 00000000 */   nop
    /* FAD70 001FAD70 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAD74 001FAD74 400B40AC */  sw         $0, 0xB40($2)
    /* FAD78 001FAD78 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAD7C 001FAD7C 440B40AC */  sw         $0, 0xB44($2)
    /* FAD80 001FAD80 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAD84 001FAD84 480B40AC */  sw         $0, 0xB48($2)
  .L001FAD88:
    /* FAD88 001FAD88 05000016 */  bnez       $16, .L001FADA0
    /* FAD8C 001FAD8C 00000000 */   nop
    /* FAD90 001FAD90 03000424 */  addiu      $4, $0, 0x3
    /* FAD94 001FAD94 20AF080C */  jal        func_0022bc80
    /* FAD98 001FAD98 00000000 */   nop
    /* FAD9C 001FAD9C 2D804000 */  daddu      $16, $2, $0
  .L001FADA0:
    /* FADA0 001FADA0 2D100002 */  daddu      $2, $16, $0
    /* FADA4 001FADA4 1000BFDF */  ld         $31, 0x10($29)
    /* FADA8 001FADA8 0000B07B */  lq         $16, 0x0($29)
    /* FADAC 001FADAC 2000BD27 */  addiu      $29, $29, 0x20
    /* FADB0 001FADB0 0800E003 */  jr         $31
    /* FADB4 001FADB4 00000000 */   nop
    /* FADB8 001FADB8 00000000 */  nop
    /* FADBC 001FADBC 00000000 */  nop
.size func_001fad10, 0xb0

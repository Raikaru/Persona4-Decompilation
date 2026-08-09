.section .text
.set noat
.set noreorder
glabel func_003cfa80
    /* 2CFA80 003CFA80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2CFA84 003CFA84 3000BFFF */  sd         $31, 0x30($29)
    /* 2CFA88 003CFA88 2000B27F */  sq         $18, 0x20($29)
    /* 2CFA8C 003CFA8C 01009290 */  lbu        $18, 0x1($4)
    /* 2CFA90 003CFA90 1000B17F */  sq         $17, 0x10($29)
    /* 2CFA94 003CFA94 0000B07F */  sq         $16, 0x0($29)
    /* 2CFA98 003CFA98 2D888000 */  daddu      $17, $4, $0
    /* 2CFA9C 003CFA9C 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFAA0 003CFAA0 0400848C */  lw         $4, 0x4($4)
    /* 2CFAA4 003CFAA4 7C00612C */  sltiu      $1, $3, 0x7C
    /* 2CFAA8 003CFAA8 36012010 */  beqz       $1, .L003CFF84
    /* 2CFAAC 003CFAAC 18003026 */   addiu     $16, $17, 0x18
    /* 2CFAB0 003CFAB0 53006014 */  bnez       $3, .L003CFC00
    /* 2CFAB4 003CFAB4 00000000 */   nop
    /* 2CFAB8 003CFAB8 EC00A010 */  beqz       $5, .L003CFE6C
    /* 2CFABC 003CFABC 00000000 */   nop
    /* 2CFAC0 003CFAC0 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2CFAC4 003CFAC4 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFAC8 003CFAC8 0400AAC4 */  lwc1       $f10, 0x4($5)
    /* 2CFACC 003CFACC 0800A9C4 */  lwc1       $f9, 0x8($5)
    /* 2CFAD0 003CFAD0 1000A8C4 */  lwc1       $f8, 0x10($5)
    /* 2CFAD4 003CFAD4 1400A7C4 */  lwc1       $f7, 0x14($5)
    /* 2CFAD8 003CFAD8 1800A6C4 */  lwc1       $f6, 0x18($5)
    /* 2CFADC 003CFADC 000060E4 */  swc1       $f0, 0x0($3)
    /* 2CFAE0 003CFAE0 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFAE4 003CFAE4 2000A5C4 */  lwc1       $f5, 0x20($5)
    /* 2CFAE8 003CFAE8 2400A4C4 */  lwc1       $f4, 0x24($5)
    /* 2CFAEC 003CFAEC 2800A3C4 */  lwc1       $f3, 0x28($5)
    /* 2CFAF0 003CFAF0 3000A2C4 */  lwc1       $f2, 0x30($5)
    /* 2CFAF4 003CFAF4 3400A1C4 */  lwc1       $f1, 0x34($5)
    /* 2CFAF8 003CFAF8 3800A0C4 */  lwc1       $f0, 0x38($5)
    /* 2CFAFC 003CFAFC 0400C324 */  addiu      $3, $6, 0x4
    /* 2CFB00 003CFB00 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB04 003CFB04 0400CAE4 */  swc1       $f10, 0x4($6)
    /* 2CFB08 003CFB08 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB0C 003CFB0C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB10 003CFB10 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB14 003CFB14 0400A9E4 */  swc1       $f9, 0x4($5)
    /* 2CFB18 003CFB18 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB1C 003CFB1C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB20 003CFB20 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB24 003CFB24 0400ACE4 */  swc1       $f12, 0x4($5)
    /* 2CFB28 003CFB28 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB2C 003CFB2C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB30 003CFB30 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB34 003CFB34 0400A8E4 */  swc1       $f8, 0x4($5)
    /* 2CFB38 003CFB38 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB3C 003CFB3C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB40 003CFB40 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB44 003CFB44 0400A7E4 */  swc1       $f7, 0x4($5)
    /* 2CFB48 003CFB48 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB4C 003CFB4C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB50 003CFB50 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB54 003CFB54 0400A6E4 */  swc1       $f6, 0x4($5)
    /* 2CFB58 003CFB58 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB5C 003CFB5C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB60 003CFB60 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB64 003CFB64 0400ACE4 */  swc1       $f12, 0x4($5)
    /* 2CFB68 003CFB68 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB6C 003CFB6C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB70 003CFB70 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB74 003CFB74 0400A5E4 */  swc1       $f5, 0x4($5)
    /* 2CFB78 003CFB78 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB7C 003CFB7C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB80 003CFB80 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB84 003CFB84 0400A4E4 */  swc1       $f4, 0x4($5)
    /* 2CFB88 003CFB88 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB8C 003CFB8C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFB90 003CFB90 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFB94 003CFB94 0400A3E4 */  swc1       $f3, 0x4($5)
    /* 2CFB98 003CFB98 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFB9C 003CFB9C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFBA0 003CFBA0 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFBA4 003CFBA4 0400ACE4 */  swc1       $f12, 0x4($5)
    /* 2CFBA8 003CFBA8 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFBAC 003CFBAC 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFBB0 003CFBB0 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFBB4 003CFBB4 0400A2E4 */  swc1       $f2, 0x4($5)
    /* 2CFBB8 003CFBB8 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFBBC 003CFBBC 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFBC0 003CFBC0 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFBC4 003CFBC4 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2CFBC8 003CFBC8 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFBCC 003CFBCC 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFBD0 003CFBD0 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFBD4 003CFBD4 0400A0E4 */  swc1       $f0, 0x4($5)
    /* 2CFBD8 003CFBD8 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFBDC 003CFBDC 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFBE0 003CFBE0 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFBE4 003CFBE4 0400ADE4 */  swc1       $f13, 0x4($5)
    /* 2CFBE8 003CFBE8 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFBEC 003CFBEC 04006324 */  addiu      $3, $3, 0x4
    /* 2CFBF0 003CFBF0 24B783AF */  sw         $3, -0x48DC($28)
  .L003CFBF4:
    /* 2CFBF4 003CFBF4 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFBF8 003CFBF8 04006324 */  addiu      $3, $3, 0x4
    /* 2CFBFC 003CFBFC 20B783AF */  sw         $3, -0x48E0($28)
  .L003CFC00:
    /* 2CFC00 003CFC00 DD008010 */  beqz       $4, .L003CFF78
    /* 2CFC04 003CFC04 00000000 */   nop
    /* 2CFC08 003CFC08 C0A50F0C */  jal        func_003e9700
    /* 2CFC0C 003CFC0C 00000000 */   nop
    /* 2CFC10 003CFC10 20004324 */  addiu      $3, $2, 0x20
    /* 2CFC14 003CFC14 30004424 */  addiu      $4, $2, 0x30
  .L003CFC18:
    /* 2CFC18 003CFC18 000002C6 */  lwc1       $f2, 0x0($16)
    /* 2CFC1C 003CFC1C 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFC20 003CFC20 040001C6 */  lwc1       $f1, 0x4($16)
    /* 2CFC24 003CFC24 080000C6 */  lwc1       $f0, 0x8($16)
    /* 2CFC28 003CFC28 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2CFC2C 003CFC2C 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFC30 003CFC30 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2CFC34 003CFC34 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFC38 003CFC38 0800A0E4 */  swc1       $f0, 0x8($5)
    /* 2CFC3C 003CFC3C 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFC40 003CFC40 D0004012 */  beqz       $18, .L003CFF84
    /* 2CFC44 003CFC44 0C00B2AC */   sw        $18, 0xC($5)
    /* 2CFC48 003CFC48 82000524 */  addiu      $5, $0, 0x82
    /* 2CFC4C 003CFC4C 51004512 */  beq        $18, $5, .L003CFD94
    /* 2CFC50 003CFC50 00000000 */   nop
    /* 2CFC54 003CFC54 81000524 */  addiu      $5, $0, 0x81
    /* 2CFC58 003CFC58 4E004512 */  beq        $18, $5, .L003CFD94
    /* 2CFC5C 003CFC5C 00000000 */   nop
    /* 2CFC60 003CFC60 80000524 */  addiu      $5, $0, 0x80
    /* 2CFC64 003CFC64 2D004512 */  beq        $18, $5, .L003CFD1C
    /* 2CFC68 003CFC68 00000000 */   nop
    /* 2CFC6C 003CFC6C 02000424 */  addiu      $4, $0, 0x2
    /* 2CFC70 003CFC70 23004412 */  beq        $18, $4, .L003CFD00
    /* 2CFC74 003CFC74 00000000 */   nop
    /* 2CFC78 003CFC78 01000424 */  addiu      $4, $0, 0x1
    /* 2CFC7C 003CFC7C 03004412 */  beq        $18, $4, .L003CFC8C
    /* 2CFC80 003CFC80 00000000 */   nop
    /* 2CFC84 003CFC84 77000010 */  b          .L003CFE64
    /* 2CFC88 003CFC88 00000000 */   nop
  .L003CFC8C:
    /* 2CFC8C 003CFC8C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFC90 003CFC90 10008424 */  addiu      $4, $4, 0x10
    /* 2CFC94 003CFC94 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFC98 003CFC98 000060C4 */  lwc1       $f0, 0x0($3)
    /* 2CFC9C 003CFC9C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCA0 003CFCA0 000080E4 */  swc1       $f0, 0x0($4)
    /* 2CFCA4 003CFCA4 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCA8 003CFCA8 04008424 */  addiu      $4, $4, 0x4
    /* 2CFCAC 003CFCAC 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFCB0 003CFCB0 040060C4 */  lwc1       $f0, 0x4($3)
    /* 2CFCB4 003CFCB4 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCB8 003CFCB8 000080E4 */  swc1       $f0, 0x0($4)
    /* 2CFCBC 003CFCBC 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCC0 003CFCC0 04008424 */  addiu      $4, $4, 0x4
    /* 2CFCC4 003CFCC4 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFCC8 003CFCC8 080060C4 */  lwc1       $f0, 0x8($3)
    /* 2CFCCC 003CFCCC 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFCD0 003CFCD0 000060E4 */  swc1       $f0, 0x0($3)
    /* 2CFCD4 003CFCD4 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCD8 003CFCD8 04008324 */  addiu      $3, $4, 0x4
    /* 2CFCDC 003CFCDC 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFCE0 003CFCE0 040080AC */  sw         $0, 0x4($4)
    /* 2CFCE4 003CFCE4 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFCE8 003CFCE8 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFCEC 003CFCEC 04008424 */  addiu      $4, $4, 0x4
    /* 2CFCF0 003CFCF0 02006324 */  addiu      $3, $3, 0x2
    /* 2CFCF4 003CFCF4 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFCF8 003CFCF8 5A000010 */  b          .L003CFE64
    /* 2CFCFC 003CFCFC 20B783AF */   sw        $3, -0x48E0($28)
  .L003CFD00:
    /* 2CFD00 003CFD00 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFD04 003CFD04 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFD08 003CFD08 10008424 */  addiu      $4, $4, 0x10
    /* 2CFD0C 003CFD0C 01006324 */  addiu      $3, $3, 0x1
    /* 2CFD10 003CFD10 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFD14 003CFD14 53000010 */  b          .L003CFE64
    /* 2CFD18 003CFD18 20B783AF */   sw        $3, -0x48E0($28)
  .L003CFD1C:
    /* 2CFD1C 003CFD1C 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD20 003CFD20 140020C6 */  lwc1       $f0, 0x14($17)
    /* 2CFD24 003CFD24 10006324 */  addiu      $3, $3, 0x10
    /* 2CFD28 003CFD28 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFD2C 003CFD2C 000081C4 */  lwc1       $f1, 0x0($4)
    /* 2CFD30 003CFD30 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD34 003CFD34 000061E4 */  swc1       $f1, 0x0($3)
    /* 2CFD38 003CFD38 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD3C 003CFD3C 04006324 */  addiu      $3, $3, 0x4
    /* 2CFD40 003CFD40 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFD44 003CFD44 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2CFD48 003CFD48 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD4C 003CFD4C 000061E4 */  swc1       $f1, 0x0($3)
    /* 2CFD50 003CFD50 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD54 003CFD54 04006324 */  addiu      $3, $3, 0x4
    /* 2CFD58 003CFD58 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFD5C 003CFD5C 080081C4 */  lwc1       $f1, 0x8($4)
    /* 2CFD60 003CFD60 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFD64 003CFD64 000061E4 */  swc1       $f1, 0x0($3)
    /* 2CFD68 003CFD68 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFD6C 003CFD6C 04008324 */  addiu      $3, $4, 0x4
    /* 2CFD70 003CFD70 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFD74 003CFD74 040080E4 */  swc1       $f0, 0x4($4)
    /* 2CFD78 003CFD78 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFD7C 003CFD7C 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFD80 003CFD80 04008424 */  addiu      $4, $4, 0x4
    /* 2CFD84 003CFD84 02006324 */  addiu      $3, $3, 0x2
    /* 2CFD88 003CFD88 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFD8C 003CFD8C 35000010 */  b          .L003CFE64
    /* 2CFD90 003CFD90 20B783AF */   sw        $3, -0x48E0($28)
  .L003CFD94:
    /* 2CFD94 003CFD94 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFD98 003CFD98 140021C6 */  lwc1       $f1, 0x14($17)
    /* 2CFD9C 003CFD9C 280020C6 */  lwc1       $f0, 0x28($17)
    /* 2CFDA0 003CFDA0 1000A524 */  addiu      $5, $5, 0x10
    /* 2CFDA4 003CFDA4 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFDA8 003CFDA8 000082C4 */  lwc1       $f2, 0x0($4)
    /* 2CFDAC 003CFDAC 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFDB0 003CFDB0 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2CFDB4 003CFDB4 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFDB8 003CFDB8 0400A524 */  addiu      $5, $5, 0x4
    /* 2CFDBC 003CFDBC 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFDC0 003CFDC0 040082C4 */  lwc1       $f2, 0x4($4)
    /* 2CFDC4 003CFDC4 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFDC8 003CFDC8 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2CFDCC 003CFDCC 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFDD0 003CFDD0 0400A524 */  addiu      $5, $5, 0x4
    /* 2CFDD4 003CFDD4 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFDD8 003CFDD8 080082C4 */  lwc1       $f2, 0x8($4)
    /* 2CFDDC 003CFDDC 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFDE0 003CFDE0 000082E4 */  swc1       $f2, 0x0($4)
    /* 2CFDE4 003CFDE4 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFDE8 003CFDE8 0400A424 */  addiu      $4, $5, 0x4
    /* 2CFDEC 003CFDEC 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFDF0 003CFDF0 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2CFDF4 003CFDF4 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFDF8 003CFDF8 04008424 */  addiu      $4, $4, 0x4
    /* 2CFDFC 003CFDFC 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFE00 003CFE00 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2CFE04 003CFE04 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE08 003CFE08 000081E4 */  swc1       $f1, 0x0($4)
    /* 2CFE0C 003CFE0C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE10 003CFE10 04008424 */  addiu      $4, $4, 0x4
    /* 2CFE14 003CFE14 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFE18 003CFE18 040061C4 */  lwc1       $f1, 0x4($3)
    /* 2CFE1C 003CFE1C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE20 003CFE20 000081E4 */  swc1       $f1, 0x0($4)
    /* 2CFE24 003CFE24 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE28 003CFE28 04008424 */  addiu      $4, $4, 0x4
    /* 2CFE2C 003CFE2C 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFE30 003CFE30 080061C4 */  lwc1       $f1, 0x8($3)
    /* 2CFE34 003CFE34 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFE38 003CFE38 000061E4 */  swc1       $f1, 0x0($3)
    /* 2CFE3C 003CFE3C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE40 003CFE40 04008324 */  addiu      $3, $4, 0x4
    /* 2CFE44 003CFE44 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFE48 003CFE48 040080E4 */  swc1       $f0, 0x4($4)
    /* 2CFE4C 003CFE4C 24B7848F */  lw         $4, -0x48DC($28)
    /* 2CFE50 003CFE50 20B7838F */  lw         $3, -0x48E0($28)
    /* 2CFE54 003CFE54 04008424 */  addiu      $4, $4, 0x4
    /* 2CFE58 003CFE58 03006324 */  addiu      $3, $3, 0x3
    /* 2CFE5C 003CFE5C 24B784AF */  sw         $4, -0x48DC($28)
    /* 2CFE60 003CFE60 20B783AF */  sw         $3, -0x48E0($28)
  .L003CFE64:
    /* 2CFE64 003CFE64 48000010 */  b          .L003CFF88
    /* 2CFE68 003CFE68 3000BFDF */   ld        $31, 0x30($29)
  .L003CFE6C:
    /* 2CFE6C 003CFE6C 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFE70 003CFE70 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2CFE74 003CFE74 0000A3AC */  sw         $3, 0x0($5)
    /* 2CFE78 003CFE78 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFE7C 003CFE7C 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFE80 003CFE80 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFE84 003CFE84 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFE88 003CFE88 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFE8C 003CFE8C 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFE90 003CFE90 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFE94 003CFE94 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFE98 003CFE98 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFE9C 003CFE9C 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFEA0 003CFEA0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFEA4 003CFEA4 0400CCE4 */  swc1       $f12, 0x4($6)
    /* 2CFEA8 003CFEA8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFEAC 003CFEAC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFEB0 003CFEB0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFEB4 003CFEB4 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFEB8 003CFEB8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFEBC 003CFEBC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFEC0 003CFEC0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFEC4 003CFEC4 0400C3AC */  sw         $3, 0x4($6)
    /* 2CFEC8 003CFEC8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFECC 003CFECC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFED0 003CFED0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFED4 003CFED4 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFED8 003CFED8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFEDC 003CFEDC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFEE0 003CFEE0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFEE4 003CFEE4 0400CCE4 */  swc1       $f12, 0x4($6)
    /* 2CFEE8 003CFEE8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFEEC 003CFEEC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFEF0 003CFEF0 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFEF4 003CFEF4 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFEF8 003CFEF8 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFEFC 003CFEFC 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFF00 003CFF00 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFF04 003CFF04 0400C0AC */  sw         $0, 0x4($6)
    /* 2CFF08 003CFF08 24B7868F */  lw         $6, -0x48DC($28)
    /* 2CFF0C 003CFF0C 0400C524 */  addiu      $5, $6, 0x4
    /* 2CFF10 003CFF10 24B785AF */  sw         $5, -0x48DC($28)
    /* 2CFF14 003CFF14 0400C3AC */  sw         $3, 0x4($6)
    /* 2CFF18 003CFF18 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFF1C 003CFF1C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFF20 003CFF20 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFF24 003CFF24 0400ACE4 */  swc1       $f12, 0x4($5)
    /* 2CFF28 003CFF28 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFF2C 003CFF2C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFF30 003CFF30 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFF34 003CFF34 0400A0AC */  sw         $0, 0x4($5)
    /* 2CFF38 003CFF38 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFF3C 003CFF3C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFF40 003CFF40 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFF44 003CFF44 0400A0AC */  sw         $0, 0x4($5)
    /* 2CFF48 003CFF48 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFF4C 003CFF4C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFF50 003CFF50 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFF54 003CFF54 0400A0AC */  sw         $0, 0x4($5)
    /* 2CFF58 003CFF58 24B7858F */  lw         $5, -0x48DC($28)
    /* 2CFF5C 003CFF5C 0400A324 */  addiu      $3, $5, 0x4
    /* 2CFF60 003CFF60 24B783AF */  sw         $3, -0x48DC($28)
    /* 2CFF64 003CFF64 0400ADE4 */  swc1       $f13, 0x4($5)
    /* 2CFF68 003CFF68 24B7838F */  lw         $3, -0x48DC($28)
    /* 2CFF6C 003CFF6C 04006324 */  addiu      $3, $3, 0x4
    /* 2CFF70 003CFF70 20FF0010 */  b          .L003CFBF4
    /* 2CFF74 003CFF74 24B783AF */   sw        $3, -0x48DC($28)
  .L003CFF78:
    /* 2CFF78 003CFF78 2D200000 */  daddu      $4, $0, $0
    /* 2CFF7C 003CFF7C 26FF0010 */  b          .L003CFC18
    /* 2CFF80 003CFF80 2D180000 */   daddu     $3, $0, $0
  .L003CFF84:
    /* 2CFF84 003CFF84 3000BFDF */  ld         $31, 0x30($29)
  .L003CFF88:
    /* 2CFF88 003CFF88 2000B27B */  lq         $18, 0x20($29)
    /* 2CFF8C 003CFF8C 1000B17B */  lq         $17, 0x10($29)
    /* 2CFF90 003CFF90 0000B07B */  lq         $16, 0x0($29)
    /* 2CFF94 003CFF94 0800E003 */  jr         $31
    /* 2CFF98 003CFF98 4000BD27 */   addiu     $29, $29, 0x40
    /* 2CFF9C 003CFF9C 00000000 */  nop
.size func_003cfa80, 0x520

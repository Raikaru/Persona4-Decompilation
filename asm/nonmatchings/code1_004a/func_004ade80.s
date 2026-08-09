.section .text
.set noat
.set noreorder
glabel func_004ade80
    /* 3ADE80 004ADE80 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3ADE84 004ADE84 3000BFFF */  sd         $31, 0x30($29)
    /* 3ADE88 004ADE88 2000B27F */  sq         $18, 0x20($29)
    /* 3ADE8C 004ADE8C 1000B17F */  sq         $17, 0x10($29)
    /* 3ADE90 004ADE90 0000B07F */  sq         $16, 0x0($29)
    /* 3ADE94 004ADE94 2D888000 */  daddu      $17, $4, $0
    /* 3ADE98 004ADE98 9C00838C */  lw         $3, 0x9C($4)
    /* 3ADE9C 004ADE9C 24006014 */  bnez       $3, .L004ADF30
    /* 3ADEA0 004ADEA0 00000000 */   nop
    /* 3ADEA4 004ADEA4 FF000324 */  addiu      $3, $0, 0xFF
    /* 3ADEA8 004ADEA8 8C00A3A3 */  sb         $3, 0x8C($29)
    /* 3ADEAC 004ADEAC 8D00A3A3 */  sb         $3, 0x8D($29)
    /* 3ADEB0 004ADEB0 8E00A0A3 */  sb         $0, 0x8E($29)
    /* 3ADEB4 004ADEB4 8F00A3A3 */  sb         $3, 0x8F($29)
    /* 3ADEB8 004ADEB8 2D800000 */  daddu      $16, $0, $0
    /* 3ADEBC 004ADEBC 16000010 */  b          .L004ADF18
    /* 3ADEC0 004ADEC0 00000000 */   nop
  .L004ADEC4:
    /* 3ADEC4 004ADEC4 A000248E */  lw         $4, 0xA0($17)
    /* 3ADEC8 004ADEC8 2D280002 */  daddu      $5, $16, $0
    /* 3ADECC 004ADECC 4000A627 */  addiu      $6, $29, 0x40
    /* 3ADED0 004ADED0 44E9110C */  jal        func_0047a510
    /* 3ADED4 004ADED4 00000000 */   nop
    /* 3ADED8 004ADED8 0E004010 */  beqz       $2, .L004ADF14
    /* 3ADEDC 004ADEDC 00000000 */   nop
    /* 3ADEE0 004ADEE0 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 3ADEE4 004ADEE4 00608244 */  mtc1       $2, $f12
    /* 3ADEE8 004ADEE8 7000A427 */  addiu      $4, $29, 0x70
    /* 3ADEEC 004ADEEC 8C00A527 */  addiu      $5, $29, 0x8C
    /* 3ADEF0 004ADEF0 01000624 */  addiu      $6, $0, 0x1
    /* 3ADEF4 004ADEF4 2C7C110C */  jal        func_0045f0b0
    /* 3ADEF8 004ADEF8 00000000 */   nop
    /* 3ADEFC 004ADEFC F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 3ADF00 004ADF00 00608244 */  mtc1       $2, $f12
    /* 3ADF04 004ADF04 4000A427 */  addiu      $4, $29, 0x40
    /* 3ADF08 004ADF08 01000524 */  addiu      $5, $0, 0x1
    /* 3ADF0C 004ADF0C 807E110C */  jal        func_0045fa00
    /* 3ADF10 004ADF10 00000000 */   nop
  .L004ADF14:
    /* 3ADF14 004ADF14 01001026 */  addiu      $16, $16, 0x1
  .L004ADF18:
    /* 3ADF18 004ADF18 2800238E */  lw         $3, 0x28($17)
    /* 3ADF1C 004ADF1C 2B180302 */  sltu       $3, $16, $3
    /* 3ADF20 004ADF20 E8FF6014 */  bnez       $3, .L004ADEC4
    /* 3ADF24 004ADF24 00000000 */   nop
    /* 3ADF28 004ADF28 15000010 */  b          .L004ADF80
    /* 3ADF2C 004ADF2C 00000000 */   nop
  .L004ADF30:
    /* 3ADF30 004ADF30 9000248E */  lw         $4, 0x90($17)
    /* 3ADF34 004ADF34 2800328E */  lw         $18, 0x28($17)
    /* 3ADF38 004ADF38 9800308E */  lw         $16, 0x98($17)
    /* 3ADF3C 004ADF3C 2C00238E */  lw         $3, 0x2C($17)
    /* 3ADF40 004ADF40 2A186400 */  slt        $3, $3, $4
    /* 3ADF44 004ADF44 03006014 */  bnez       $3, .L004ADF54
    /* 3ADF48 004ADF48 00000000 */   nop
    /* 3ADF4C 004ADF4C 0C008014 */  bnez       $4, .L004ADF80
    /* 3ADF50 004ADF50 00000000 */   nop
  .L004ADF54:
    /* 3ADF54 004ADF54 2D880000 */  daddu      $17, $0, $0
    /* 3ADF58 004ADF58 06000010 */  b          .L004ADF74
    /* 3ADF5C 004ADF5C 00000000 */   nop
  .L004ADF60:
    /* 3ADF60 004ADF60 0000048E */  lw         $4, 0x0($16)
    /* 3ADF64 004ADF64 1C16120C */  jal        func_00485870
    /* 3ADF68 004ADF68 00000000 */   nop
    /* 3ADF6C 004ADF6C 04001026 */  addiu      $16, $16, 0x4
    /* 3ADF70 004ADF70 01003126 */  addiu      $17, $17, 0x1
  .L004ADF74:
    /* 3ADF74 004ADF74 2B183202 */  sltu       $3, $17, $18
    /* 3ADF78 004ADF78 F9FF6014 */  bnez       $3, .L004ADF60
    /* 3ADF7C 004ADF7C 00000000 */   nop
  .L004ADF80:
    /* 3ADF80 004ADF80 3000BFDF */  ld         $31, 0x30($29)
    /* 3ADF84 004ADF84 2000B27B */  lq         $18, 0x20($29)
    /* 3ADF88 004ADF88 1000B17B */  lq         $17, 0x10($29)
    /* 3ADF8C 004ADF8C 0000B07B */  lq         $16, 0x0($29)
    /* 3ADF90 004ADF90 9000BD27 */  addiu      $29, $29, 0x90
    /* 3ADF94 004ADF94 0800E003 */  jr         $31
    /* 3ADF98 004ADF98 00000000 */   nop
    /* 3ADF9C 004ADF9C 00000000 */  nop
.size func_004ade80, 0x120

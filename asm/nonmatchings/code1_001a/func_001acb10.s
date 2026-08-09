.section .text
.set noat
.set noreorder
glabel func_001acb10
    /* ACB10 001ACB10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* ACB14 001ACB14 0000BFFF */  sd         $31, 0x0($29)
    /* ACB18 001ACB18 F4038594 */  lhu        $5, 0x3F4($4)
    /* ACB1C 001ACB1C 10020324 */  addiu      $3, $0, 0x210
    /* ACB20 001ACB20 0D00A310 */  beq        $5, $3, .L001ACB58
    /* ACB24 001ACB24 00000000 */   nop
    /* ACB28 001ACB28 0F020324 */  addiu      $3, $0, 0x20F
    /* ACB2C 001ACB2C 0300A310 */  beq        $5, $3, .L001ACB3C
    /* ACB30 001ACB30 00000000 */   nop
    /* ACB34 001ACB34 0D000010 */  b          .L001ACB6C
    /* ACB38 001ACB38 00000000 */   nop
  .L001ACB3C:
    /* ACB3C 001ACB3C 3000838C */  lw         $3, 0x30($4)
    /* ACB40 001ACB40 640A658C */  lw         $5, 0xA64($3)
    /* ACB44 001ACB44 0000A394 */  lhu        $3, 0x0($5)
    /* ACB48 001ACB48 00046334 */  ori        $3, $3, 0x400
    /* ACB4C 001ACB4C 0000A3A4 */  sh         $3, 0x0($5)
    /* ACB50 001ACB50 06000010 */  b          .L001ACB6C
    /* ACB54 001ACB54 00000000 */   nop
  .L001ACB58:
    /* ACB58 001ACB58 3000838C */  lw         $3, 0x30($4)
    /* ACB5C 001ACB5C 640A658C */  lw         $5, 0xA64($3)
    /* ACB60 001ACB60 0000A394 */  lhu        $3, 0x0($5)
    /* ACB64 001ACB64 00086334 */  ori        $3, $3, 0x800
    /* ACB68 001ACB68 0000A3A4 */  sh         $3, 0x0($5)
  .L001ACB6C:
    /* ACB6C 001ACB6C F4038394 */  lhu        $3, 0x3F4($4)
    /* ACB70 001ACB70 09006014 */  bnez       $3, .L001ACB98
    /* ACB74 001ACB74 00000000 */   nop
    /* ACB78 001ACB78 3000858C */  lw         $5, 0x30($4)
    /* ACB7C 001ACB7C 9C00A38C */  lw         $3, 0x9C($5)
    /* ACB80 001ACB80 EFFF0224 */  addiu      $2, $0, -0x11
    /* ACB84 001ACB84 24106200 */  and        $2, $3, $2
    /* ACB88 001ACB88 9C00A2AC */  sw         $2, 0x9C($5)
    /* ACB8C 001ACB8C 30048594 */  lhu        $5, 0x430($4)
    /* ACB90 001ACB90 00C2060C */  jal        func_001b0800
    /* ACB94 001ACB94 00000000 */   nop
  .L001ACB98:
    /* ACB98 001ACB98 0000BFDF */  ld         $31, 0x0($29)
    /* ACB9C 001ACB9C 1000BD27 */  addiu      $29, $29, 0x10
    /* ACBA0 001ACBA0 0800E003 */  jr         $31
    /* ACBA4 001ACBA4 00000000 */   nop
    /* ACBA8 001ACBA8 00000000 */  nop
    /* ACBAC 001ACBAC 00000000 */  nop
.size func_001acb10, 0xa0

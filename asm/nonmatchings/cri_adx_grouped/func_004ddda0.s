.section .text
.set noat
.set noreorder
glabel func_004ddda0
    /* 3DDDA0 004DDDA0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3DDDA4 004DDDA4 01000224 */  addiu      $2, $0, 0x1
    /* 3DDDA8 004DDDA8 2800B1FF */  sd         $17, 0x28($29)
    /* 3DDDAC 004DDDAC 2D888000 */  daddu      $17, $4, $0
    /* 3DDDB0 004DDDB0 5000B6FF */  sd         $22, 0x50($29)
    /* 3DDDB4 004DDDB4 14003626 */  addiu      $22, $17, 0x14
    /* 3DDDB8 004DDDB8 2000B0FF */  sd         $16, 0x20($29)
    /* 3DDDBC 004DDDBC 3000B2FF */  sd         $18, 0x30($29)
    /* 3DDDC0 004DDDC0 3800B3FF */  sd         $19, 0x38($29)
    /* 3DDDC4 004DDDC4 4000B4FF */  sd         $20, 0x40($29)
    /* 3DDDC8 004DDDC8 4800B5FF */  sd         $21, 0x48($29)
    /* 3DDDCC 004DDDCC 5800BFFF */  sd         $31, 0x58($29)
    /* 3DDDD0 004DDDD0 07003082 */  lb         $16, 0x7($17)
    /* 3DDDD4 004DDDD4 0000358E */  lw         $21, 0x0($17)
    /* 3DDDD8 004DDDD8 0B000216 */  bne        $16, $2, .L004DDE08
    /* 3DDDDC 004DDDDC 1000248E */   lw        $4, 0x10($17)
    /* 3DDDE0 004DDDE0 0000838C */  lw         $3, 0x0($4)
    /* 3DDDE4 004DDDE4 2400628C */  lw         $2, 0x24($3)
    /* 3DDDE8 004DDDE8 09F84000 */  jalr       $2
    /* 3DDDEC 004DDDEC 01000524 */   addiu     $5, $0, 0x1
    /* 3DDDF0 004DDDF0 05004014 */  bnez       $2, .L004DDE08
    /* 3DDDF4 004DDDF4 00000000 */   nop
    /* 3DDDF8 004DDDF8 2066130C */  jal        func_004d9880
    /* 3DDDFC 004DDDFC 0C00248E */   lw        $4, 0xC($17)
    /* 3DDE00 004DDE00 26005050 */  beql       $2, $16, .L004DDE9C
    /* 3DDE04 004DDE04 2C00238E */   lw        $3, 0x2C($17)
  .L004DDE08:
    /* 3DDE08 004DDE08 6C78130C */  jal        func_004de1b0
    /* 3DDE0C 004DDE0C 2D202002 */   daddu     $4, $17, $0
    /* 3DDE10 004DDE10 2D202002 */  daddu      $4, $17, $0
    /* 3DDE14 004DDE14 6678130C */  jal        func_004de198
    /* 3DDE18 004DDE18 2DA04000 */   daddu     $20, $2, $0
    /* 3DDE1C 004DDE1C 1400248E */  lw         $4, 0x14($17)
    /* 3DDE20 004DDE20 07004524 */  addiu      $5, $2, 0x7
    /* 3DDE24 004DDE24 00004328 */  slti       $3, $2, 0x0
    /* 3DDE28 004DDE28 0000868C */  lw         $6, 0x0($4)
    /* 3DDE2C 004DDE2C 0B10A300 */  movn       $2, $5, $3
    /* 3DDE30 004DDE30 2D280000 */  daddu      $5, $0, $0
    /* 3DDE34 004DDE34 2400C38C */  lw         $3, 0x24($6)
    /* 3DDE38 004DDE38 09F86000 */  jalr       $3
    /* 3DDE3C 004DDE3C C3900200 */   sra       $18, $2, 3
    /* 3DDE40 004DDE40 01004052 */  beql       $18, $0, .L004DDE48
    /* 3DDE44 004DDE44 CD010000 */   break     0, 7
  .L004DDE48:
    /* 3DDE48 004DDE48 1A005200 */  div        $0, $2, $18
    /* 3DDE4C 004DDE4C 12100000 */  mflo       $2
    /* 3DDE50 004DDE50 2A105400 */  slt        $2, $2, $20
    /* 3DDE54 004DDE54 72004014 */  bnez       $2, .L004DE020
    /* 3DDE58 004DDE58 2000B0DF */   ld        $16, 0x20($29)
    /* 3DDE5C 004DDE5C B668130C */  jal        func_004da2d8
    /* 3DDE60 004DDE60 2D20A002 */   daddu     $4, $21, $0
    /* 3DDE64 004DDE64 18004050 */  beql       $2, $0, .L004DDEC8
    /* 3DDE68 004DDE68 0000C48E */   lw        $4, 0x0($22)
    /* 3DDE6C 004DDE6C 8275130C */  jal        func_004dd608
    /* 3DDE70 004DDE70 00000000 */   nop
    /* 3DDE74 004DDE74 7300033C */  lui        $3, %hi(D_00729A80)
    /* 3DDE78 004DDE78 809A7024 */  addiu      $16, $3, %lo(D_00729A80)
    /* 3DDE7C 004DDE7C 2D20A002 */  daddu      $4, $21, $0
    /* 3DDE80 004DDE80 7E68130C */  jal        func_004da1f8
    /* 3DDE84 004DDE84 080002AE */   sw        $2, 0x8($16)
    /* 3DDE88 004DDE88 2D184000 */  daddu      $3, $2, $0
    /* 3DDE8C 004DDE8C 01000224 */  addiu      $2, $0, 0x1
    /* 3DDE90 004DDE90 07006214 */  bne        $3, $2, .L004DDEB0
    /* 3DDE94 004DDE94 FFFF0224 */   addiu     $2, $0, -0x1
    /* 3DDE98 004DDE98 2C00238E */  lw         $3, 0x2C($17)
  .L004DDE9C:
    /* 3DDE9C 004DDE9C 03000224 */  addiu      $2, $0, 0x3
    /* 3DDEA0 004DDEA0 050022A2 */  sb         $2, 0x5($17)
    /* 3DDEA4 004DDEA4 5D000010 */  b          .L004DE01C
    /* 3DDEA8 004DDEA8 200023AE */   sw        $3, 0x20($17)
    /* 3DDEAC 004DDEAC 00000000 */  nop
  .L004DDEB0:
    /* 3DDEB0 004DDEB0 5B006250 */  beql       $3, $2, .L004DE020
    /* 3DDEB4 004DDEB4 2000B0DF */   ld        $16, 0x20($29)
    /* 3DDEB8 004DDEB8 8275130C */  jal        func_004dd608
    /* 3DDEBC 004DDEBC 00000000 */   nop
    /* 3DDEC0 004DDEC0 0C0002AE */  sw         $2, 0xC($16)
    /* 3DDEC4 004DDEC4 0000C48E */  lw         $4, 0x0($22)
  .L004DDEC8:
    /* 3DDEC8 004DDEC8 18009202 */  mult       $0, $20, $18
    /* 3DDECC 004DDECC 2D280000 */  daddu      $5, $0, $0
    /* 3DDED0 004DDED0 0000828C */  lw         $2, 0x0($4)
    /* 3DDED4 004DDED4 1800438C */  lw         $3, 0x18($2)
    /* 3DDED8 004DDED8 12300000 */  mflo       $6
    /* 3DDEDC 004DDEDC 09F86000 */  jalr       $3
    /* 3DDEE0 004DDEE0 2D38A003 */   daddu     $7, $29, $0
    /* 3DDEE4 004DDEE4 0400A28F */  lw         $2, 0x4($29)
    /* 3DDEE8 004DDEE8 42100200 */  srl        $2, $2, 1
    /* 3DDEEC 004DDEEC 0A005410 */  beq        $2, $20, .L004DDF18
    /* 3DDEF0 004DDEF0 0000B38F */   lw        $19, 0x0($29)
    /* 3DDEF4 004DDEF4 0000C48E */  lw         $4, 0x0($22)
    /* 3DDEF8 004DDEF8 2D280000 */  daddu      $5, $0, $0
    /* 3DDEFC 004DDEFC 0000838C */  lw         $3, 0x0($4)
    /* 3DDF00 004DDF00 1C00628C */  lw         $2, 0x1C($3)
    /* 3DDF04 004DDF04 09F84000 */  jalr       $2
    /* 3DDF08 004DDF08 2D30A003 */   daddu     $6, $29, $0
    /* 3DDF0C 004DDF0C 44000010 */  b          .L004DE020
    /* 3DDF10 004DDF10 2000B0DF */   ld        $16, 0x20($29)
    /* 3DDF14 004DDF14 00000000 */  nop
  .L004DDF18:
    /* 3DDF18 004DDF18 8275130C */  jal        func_004dd608
    /* 3DDF1C 004DDF1C 7300103C */   lui       $16, %hi(D_00729A80)
    /* 3DDF20 004DDF20 809A1026 */  addiu      $16, $16, %lo(D_00729A80)
    /* 3DDF24 004DDF24 2D286002 */  daddu      $5, $19, $0
    /* 3DDF28 004DDF28 000002AE */  sw         $2, 0x0($16)
    /* 3DDF2C 004DDF2C 2D20A002 */  daddu      $4, $21, $0
    /* 3DDF30 004DDF30 2D388002 */  daddu      $7, $20, $0
    /* 3DDF34 004DDF34 BA68130C */  jal        func_004da2e8
    /* 3DDF38 004DDF38 2D300000 */   daddu     $6, $0, $0
    /* 3DDF3C 004DDF3C 8275130C */  jal        func_004dd608
    /* 3DDF40 004DDF40 2D984000 */   daddu     $19, $2, $0
    /* 3DDF44 004DDF44 18007202 */  mult       $0, $19, $18
    /* 3DDF48 004DDF48 1000B227 */  addiu      $18, $29, 0x10
    /* 3DDF4C 004DDF4C 040002AE */  sw         $2, 0x4($16)
    /* 3DDF50 004DDF50 2D20A003 */  daddu      $4, $29, $0
    /* 3DDF54 004DDF54 2D30A003 */  daddu      $6, $29, $0
    /* 3DDF58 004DDF58 12280000 */  mflo       $5
    /* 3DDF5C 004DDF5C 2EBE130C */  jal        func_004ef8b8
    /* 3DDF60 004DDF60 2D384002 */   daddu     $7, $18, $0
    /* 3DDF64 004DDF64 4800228E */  lw         $2, 0x48($17)
    /* 3DDF68 004DDF68 05004010 */  beqz       $2, .L004DDF80
    /* 3DDF6C 004DDF6C 0000A68F */   lw        $6, 0x0($29)
    /* 3DDF70 004DDF70 4C00248E */  lw         $4, 0x4C($17)
    /* 3DDF74 004DDF74 2D280000 */  daddu      $5, $0, $0
    /* 3DDF78 004DDF78 09F84000 */  jalr       $2
    /* 3DDF7C 004DDF7C 0400A78F */   lw        $7, 0x4($29)
  .L004DDF80:
    /* 3DDF80 004DDF80 0000C48E */  lw         $4, 0x0($22)
    /* 3DDF84 004DDF84 2D30A003 */  daddu      $6, $29, $0
    /* 3DDF88 004DDF88 0000838C */  lw         $3, 0x0($4)
    /* 3DDF8C 004DDF8C 2000628C */  lw         $2, 0x20($3)
    /* 3DDF90 004DDF90 09F84000 */  jalr       $2
    /* 3DDF94 004DDF94 01000524 */   addiu     $5, $0, 0x1
    /* 3DDF98 004DDF98 0000C48E */  lw         $4, 0x0($22)
    /* 3DDF9C 004DDF9C 2D304002 */  daddu      $6, $18, $0
    /* 3DDFA0 004DDFA0 0000828C */  lw         $2, 0x0($4)
    /* 3DDFA4 004DDFA4 1C00438C */  lw         $3, 0x1C($2)
    /* 3DDFA8 004DDFA8 09F86000 */  jalr       $3
    /* 3DDFAC 004DDFAC 2D280000 */   daddu     $5, $0, $0
    /* 3DDFB0 004DDFB0 2000228E */  lw         $2, 0x20($17)
    /* 3DDFB4 004DDFB4 0C00248E */  lw         $4, 0xC($17)
    /* 3DDFB8 004DDFB8 21105300 */  addu       $2, $2, $19
    /* 3DDFBC 004DDFBC 1E66130C */  jal        func_004d9878
    /* 3DDFC0 004DDFC0 200022AE */   sw        $2, 0x20($17)
    /* 3DDFC4 004DDFC4 2800258E */  lw         $5, 0x28($17)
    /* 3DDFC8 004DDFC8 07004424 */  addiu      $4, $2, 0x7
    /* 3DDFCC 004DDFCC 0E004224 */  addiu      $2, $2, 0xE
    /* 3DDFD0 004DDFD0 3400268E */  lw         $6, 0x34($17)
    /* 3DDFD4 004DDFD4 00008328 */  slti       $3, $4, 0x0
    /* 3DDFD8 004DDFD8 0B204300 */  movn       $4, $2, $3
    /* 3DDFDC 004DDFDC 3000238E */  lw         $3, 0x30($17)
    /* 3DDFE0 004DDFE0 2110D300 */  addu       $2, $6, $19
    /* 3DDFE4 004DDFE4 C3200400 */  sra        $4, $4, 3
    /* 3DDFE8 004DDFE8 2128B300 */  addu       $5, $5, $19
    /* 3DDFEC 004DDFEC 240024AE */  sw         $4, 0x24($17)
    /* 3DDFF0 004DDFF0 280025AE */  sw         $5, 0x28($17)
    /* 3DDFF4 004DDFF4 09006004 */  bltz       $3, .L004DE01C
    /* 3DDFF8 004DDFF8 340022AE */   sw        $2, 0x34($17)
    /* 3DDFFC 004DDFFC 2A104300 */  slt        $2, $2, $3
    /* 3DE000 004DE000 07004014 */  bnez       $2, .L004DE020
    /* 3DE004 004DE004 2000B0DF */   ld        $16, 0x20($29)
    /* 3DE008 004DE008 4000228E */  lw         $2, 0x40($17)
    /* 3DE00C 004DE00C 05004050 */  beql       $2, $0, .L004DE024
    /* 3DE010 004DE010 2800B1DF */   ld        $17, 0x28($29)
    /* 3DE014 004DE014 09F84000 */  jalr       $2
    /* 3DE018 004DE018 4400248E */   lw        $4, 0x44($17)
  .L004DE01C:
    /* 3DE01C 004DE01C 2000B0DF */  ld         $16, 0x20($29)
  .L004DE020:
    /* 3DE020 004DE020 2800B1DF */  ld         $17, 0x28($29)
  .L004DE024:
    /* 3DE024 004DE024 3000B2DF */  ld         $18, 0x30($29)
    /* 3DE028 004DE028 3800B3DF */  ld         $19, 0x38($29)
    /* 3DE02C 004DE02C 4000B4DF */  ld         $20, 0x40($29)
    /* 3DE030 004DE030 4800B5DF */  ld         $21, 0x48($29)
    /* 3DE034 004DE034 5000B6DF */  ld         $22, 0x50($29)
    /* 3DE038 004DE038 5800BFDF */  ld         $31, 0x58($29)
    /* 3DE03C 004DE03C 0800E003 */  jr         $31
    /* 3DE040 004DE040 6000BD27 */   addiu     $29, $29, 0x60
    /* 3DE044 004DE044 00000000 */  nop
.size func_004ddda0, 0x2a8

.section .text
.set noat
.set noreorder
glabel func_001bdeb0
    /* BDEB0 001BDEB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BDEB4 001BDEB4 2000BFFF */  sd         $31, 0x20($29)
    /* BDEB8 001BDEB8 1000B17F */  sq         $17, 0x10($29)
    /* BDEBC 001BDEBC 0000B07F */  sq         $16, 0x0($29)
    /* BDEC0 001BDEC0 2D888000 */  daddu      $17, $4, $0
    /* BDEC4 001BDEC4 E000858C */  lw         $5, 0xE0($4)
    /* BDEC8 001BDEC8 5B00A010 */  beqz       $5, .L001BE038
    /* BDECC 001BDECC 00000000 */   nop
    /* BDED0 001BDED0 6A00A494 */  lhu        $4, 0x6A($5)
    /* BDED4 001BDED4 40012396 */  lhu        $3, 0x140($17)
    /* BDED8 001BDED8 57008314 */  bne        $4, $3, .L001BE038
    /* BDEDC 001BDEDC 00000000 */   nop
    /* BDEE0 001BDEE0 3401248E */  lw         $4, 0x134($17)
    /* BDEE4 001BDEE4 54008010 */  beqz       $4, .L001BE038
    /* BDEE8 001BDEE8 00000000 */   nop
    /* BDEEC 001BDEEC 3800A38C */  lw         $3, 0x38($5)
    /* BDEF0 001BDEF0 51008314 */  bne        $4, $3, .L001BE038
    /* BDEF4 001BDEF4 00000000 */   nop
    /* BDEF8 001BDEF8 1A00A394 */  lhu        $3, 0x1A($5)
    /* BDEFC 001BDEFC 01006330 */  andi       $3, $3, 0x1
    /* BDF00 001BDF00 4D006010 */  beqz       $3, .L001BE038
    /* BDF04 001BDF04 00000000 */   nop
    /* BDF08 001BDF08 EC002426 */  addiu      $4, $17, 0xEC
    /* BDF0C 001BDF0C 3444070C */  jal        func_001d10d0
    /* BDF10 001BDF10 00000000 */   nop
    /* BDF14 001BDF14 05004010 */  beqz       $2, .L001BDF2C
    /* BDF18 001BDF18 00000000 */   nop
    /* BDF1C 001BDF1C 2D202002 */  daddu      $4, $17, $0
    /* BDF20 001BDF20 EC002526 */  addiu      $5, $17, 0xEC
    /* BDF24 001BDF24 F841070C */  jal        func_001d07e0
    /* BDF28 001BDF28 00000000 */   nop
  .L001BDF2C:
    /* BDF2C 001BDF2C EC002426 */  addiu      $4, $17, 0xEC
    /* BDF30 001BDF30 8044070C */  jal        func_001d1200
    /* BDF34 001BDF34 00000000 */   nop
    /* BDF38 001BDF38 3F004010 */  beqz       $2, .L001BE038
    /* BDF3C 001BDF3C 00000000 */   nop
    /* BDF40 001BDF40 1C004494 */  lhu        $4, 0x1C($2)
    /* BDF44 001BDF44 01000324 */  addiu      $3, $0, 0x1
    /* BDF48 001BDF48 13008314 */  bne        $4, $3, .L001BDF98
    /* BDF4C 001BDF4C 00000000 */   nop
    /* BDF50 001BDF50 42012396 */  lhu        $3, 0x142($17)
    /* BDF54 001BDF54 02006330 */  andi       $3, $3, 0x2
    /* BDF58 001BDF58 0F006014 */  bnez       $3, .L001BDF98
    /* BDF5C 001BDF5C 00000000 */   nop
    /* BDF60 001BDF60 3C01238E */  lw         $3, 0x13C($17)
    /* BDF64 001BDF64 08006010 */  beqz       $3, .L001BDF88
    /* BDF68 001BDF68 00000000 */   nop
    /* BDF6C 001BDF6C 00608044 */  mtc1       $0, $f12
    /* BDF70 001BDF70 E000248E */  lw         $4, 0xE0($17)
    /* BDF74 001BDF74 2D280000 */  daddu      $5, $0, $0
    /* BDF78 001BDF78 2D300000 */  daddu      $6, $0, $0
    /* BDF7C 001BDF7C 01020724 */  addiu      $7, $0, 0x201
    /* BDF80 001BDF80 50F3060C */  jal        func_001bcd40
    /* BDF84 001BDF84 00000000 */   nop
  .L001BDF88:
    /* BDF88 001BDF88 01000324 */  addiu      $3, $0, 0x1
    /* BDF8C 001BDF8C 380123AE */  sw         $3, 0x138($17)
    /* BDF90 001BDF90 29000010 */  b          .L001BE038
    /* BDF94 001BDF94 00000000 */   nop
  .L001BDF98:
    /* BDF98 001BDF98 3801238E */  lw         $3, 0x138($17)
    /* BDF9C 001BDF9C 01000224 */  addiu      $2, $0, 0x1
    /* BDFA0 001BDFA0 04006214 */  bne        $3, $2, .L001BDFB4
    /* BDFA4 001BDFA4 00000000 */   nop
    /* BDFA8 001BDFA8 03000224 */  addiu      $2, $0, 0x3
    /* BDFAC 001BDFAC 02000010 */  b          .L001BDFB8
    /* BDFB0 001BDFB0 00000000 */   nop
  .L001BDFB4:
    /* BDFB4 001BDFB4 C3000224 */  addiu      $2, $0, 0xC3
  .L001BDFB8:
    /* BDFB8 001BDFB8 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* BDFBC 001BDFBC 3C01228E */  lw         $2, 0x13C($17)
    /* BDFC0 001BDFC0 15004014 */  bnez       $2, .L001BE018
    /* BDFC4 001BDFC4 00000000 */   nop
    /* BDFC8 001BDFC8 3401228E */  lw         $2, 0x134($17)
    /* BDFCC 001BDFCC 3000428C */  lw         $2, 0x30($2)
    /* BDFD0 001BDFD0 640A448C */  lw         $4, 0xA64($2)
    /* BDFD4 001BDFD4 2D280000 */  daddu      $5, $0, $0
    /* BDFD8 001BDFD8 3C0A090C */  jal        func_002428f0
    /* BDFDC 001BDFDC 00000000 */   nop
    /* BDFE0 001BDFE0 14004014 */  bnez       $2, .L001BE034
    /* BDFE4 001BDFE4 00000000 */   nop
    /* BDFE8 001BDFE8 3401228E */  lw         $2, 0x134($17)
    /* BDFEC 001BDFEC 3000438C */  lw         $3, 0x30($2)
    /* BDFF0 001BDFF0 4842023C */  lui        $2, (0x42480000 >> 16)
    /* BDFF4 001BDFF4 00608244 */  mtc1       $2, $f12
    /* BDFF8 001BDFF8 E000248E */  lw         $4, 0xE0($17)
    /* BDFFC 001BDFFC 9C002526 */  addiu      $5, $17, 0x9C
    /* BE000 001BE000 04006624 */  addiu      $6, $3, 0x4
    /* BE004 001BE004 2D380002 */  daddu      $7, $16, $0
    /* BE008 001BE008 50F3060C */  jal        func_001bcd40
    /* BE00C 001BE00C 00000000 */   nop
    /* BE010 001BE010 08000010 */  b          .L001BE034
    /* BE014 001BE014 00000000 */   nop
  .L001BE018:
    /* BE018 001BE018 00608044 */  mtc1       $0, $f12
    /* BE01C 001BE01C E000248E */  lw         $4, 0xE0($17)
    /* BE020 001BE020 2D280000 */  daddu      $5, $0, $0
    /* BE024 001BE024 2D300000 */  daddu      $6, $0, $0
    /* BE028 001BE028 2D380002 */  daddu      $7, $16, $0
    /* BE02C 001BE02C 50F3060C */  jal        func_001bcd40
    /* BE030 001BE030 00000000 */   nop
  .L001BE034:
    /* BE034 001BE034 380120AE */  sw         $0, 0x138($17)
  .L001BE038:
    /* BE038 001BE038 2000BFDF */  ld         $31, 0x20($29)
    /* BE03C 001BE03C 1000B17B */  lq         $17, 0x10($29)
    /* BE040 001BE040 0000B07B */  lq         $16, 0x0($29)
    /* BE044 001BE044 3000BD27 */  addiu      $29, $29, 0x30
    /* BE048 001BE048 0800E003 */  jr         $31
    /* BE04C 001BE04C 00000000 */   nop
.size func_001bdeb0, 0x1a0

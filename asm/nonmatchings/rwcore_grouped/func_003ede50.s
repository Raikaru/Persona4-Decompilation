.section .text
.set noat
.set noreorder
glabel func_003ede50
    /* 2EDE50 003EDE50 40FDBD27 */  addiu      $29, $29, -0x2C0
    /* 2EDE54 003EDE54 9000BFFF */  sd         $31, 0x90($29)
    /* 2EDE58 003EDE58 8000BE7F */  sq         $30, 0x80($29)
    /* 2EDE5C 003EDE5C 7000B77F */  sq         $23, 0x70($29)
    /* 2EDE60 003EDE60 2DF04001 */  daddu      $30, $10, $0
    /* 2EDE64 003EDE64 6000B67F */  sq         $22, 0x60($29)
    /* 2EDE68 003EDE68 2DB82001 */  daddu      $23, $9, $0
    /* 2EDE6C 003EDE6C 5000B57F */  sq         $21, 0x50($29)
    /* 2EDE70 003EDE70 2DB0C000 */  daddu      $22, $6, $0
    /* 2EDE74 003EDE74 4000B47F */  sq         $20, 0x40($29)
    /* 2EDE78 003EDE78 2DA88000 */  daddu      $21, $4, $0
    /* 2EDE7C 003EDE7C 3000B37F */  sq         $19, 0x30($29)
    /* 2EDE80 003EDE80 2DA0A000 */  daddu      $20, $5, $0
    /* 2EDE84 003EDE84 2000B27F */  sq         $18, 0x20($29)
    /* 2EDE88 003EDE88 2D98E000 */  daddu      $19, $7, $0
    /* 2EDE8C 003EDE8C 1000B17F */  sq         $17, 0x10($29)
    /* 2EDE90 003EDE90 2D900001 */  daddu      $18, $8, $0
    /* 2EDE94 003EDE94 8800113C */  lui        $17, %hi(D_008873B0)
    /* 2EDE98 003EDE98 0000B07F */  sq         $16, 0x0($29)
    /* 2EDE9C 003EDE9C B0733126 */  addiu      $17, $17, %lo(D_008873B0)
    /* 2EDEA0 003EDEA0 A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EDEA4 003EDEA4 0000228E */  lw         $2, 0x0($17)
    /* 2EDEA8 003EDEA8 2D28A002 */  daddu      $5, $21, $0
    /* 2EDEAC 003EDEAC 09F84000 */  jalr       $2
    /* 2EDEB0 003EDEB0 00010624 */   addiu     $6, $0, 0x100
    /* 2EDEB4 003EDEB4 8800103C */  lui        $16, %hi(D_008873D4)
    /* 2EDEB8 003EDEB8 D4731026 */  addiu      $16, $16, %lo(D_008873D4)
    /* 2EDEBC 003EDEBC 0000028E */  lw         $2, 0x0($16)
    /* 2EDEC0 003EDEC0 09F84000 */  jalr       $2
    /* 2EDEC4 003EDEC4 2D20A002 */   daddu     $4, $21, $0
    /* 2EDEC8 003EDEC8 0001412C */  sltiu      $1, $2, 0x100
    /* 2EDECC 003EDECC 56002010 */  beqz       $1, .L003EE028
    /* 2EDED0 003EDED0 00000000 */   nop
  .L003EDED4:
    /* 2EDED4 003EDED4 70AC0F0C */  jal        func_003eb1c0
    /* 2EDED8 003EDED8 2D20A002 */   daddu     $4, $21, $0
    /* 2EDEDC 003EDEDC 06004010 */  beqz       $2, .L003EDEF8
    /* 2EDEE0 003EDEE0 00000000 */   nop
    /* 2EDEE4 003EDEE4 2D284000 */  daddu      $5, $2, $0
    /* 2EDEE8 003EDEE8 8800023C */  lui        $2, %hi(D_008873B4)
    /* 2EDEEC 003EDEEC B473428C */  lw         $2, %lo(D_008873B4)($2)
    /* 2EDEF0 003EDEF0 09F84000 */  jalr       $2
    /* 2EDEF4 003EDEF4 A001A427 */   addiu     $4, $29, 0x1A0
  .L003EDEF8:
    /* 2EDEF8 003EDEF8 18008012 */  beqz       $20, .L003EDF5C
    /* 2EDEFC 003EDEFC A000A0A3 */   sb        $0, 0xA0($29)
    /* 2EDF00 003EDF00 00008282 */  lb         $2, 0x0($20)
    /* 2EDF04 003EDF04 15004010 */  beqz       $2, .L003EDF5C
    /* 2EDF08 003EDF08 00000000 */   nop
    /* 2EDF0C 003EDF0C 0000228E */  lw         $2, 0x0($17)
    /* 2EDF10 003EDF10 A000A427 */  addiu      $4, $29, 0xA0
    /* 2EDF14 003EDF14 2D288002 */  daddu      $5, $20, $0
    /* 2EDF18 003EDF18 09F84000 */  jalr       $2
    /* 2EDF1C 003EDF1C 00010624 */   addiu     $6, $0, 0x100
    /* 2EDF20 003EDF20 0000028E */  lw         $2, 0x0($16)
    /* 2EDF24 003EDF24 09F84000 */  jalr       $2
    /* 2EDF28 003EDF28 2D208002 */   daddu     $4, $20, $0
    /* 2EDF2C 003EDF2C 0001412C */  sltiu      $1, $2, 0x100
    /* 2EDF30 003EDF30 4B002010 */  beqz       $1, .L003EE060
    /* 2EDF34 003EDF34 00000000 */   nop
  .L003EDF38:
    /* 2EDF38 003EDF38 70AC0F0C */  jal        func_003eb1c0
    /* 2EDF3C 003EDF3C 2D208002 */   daddu     $4, $20, $0
    /* 2EDF40 003EDF40 06004010 */  beqz       $2, .L003EDF5C
    /* 2EDF44 003EDF44 00000000 */   nop
    /* 2EDF48 003EDF48 2D284000 */  daddu      $5, $2, $0
    /* 2EDF4C 003EDF4C 8800023C */  lui        $2, %hi(D_008873B4)
    /* 2EDF50 003EDF50 B473428C */  lw         $2, %lo(D_008873B4)($2)
    /* 2EDF54 003EDF54 09F84000 */  jalr       $2
    /* 2EDF58 003EDF58 A000A427 */   addiu     $4, $29, 0xA0
  .L003EDF5C:
    /* 2EDF5C 003EDF5C A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EDF60 003EDF60 ECAC0F0C */  jal        func_003eb3b0
    /* 2EDF64 003EDF64 A000A527 */   addiu     $5, $29, 0xA0
    /* 2EDF68 003EDF68 4B004010 */  beqz       $2, .L003EE098
    /* 2EDF6C 003EDF6C BC02A2AF */   sw        $2, 0x2BC($29)
    /* 2EDF70 003EDF70 0000638E */  lw         $3, 0x0($19)
    /* 2EDF74 003EDF74 4A006010 */  beqz       $3, .L003EE0A0
    /* 2EDF78 003EDF78 00000000 */   nop
    /* 2EDF7C 003EDF7C 0000438E */  lw         $3, 0x0($18)
    /* 2EDF80 003EDF80 47006010 */  beqz       $3, .L003EE0A0
    /* 2EDF84 003EDF84 00000000 */   nop
  .L003EDF88:
    /* 2EDF88 003EDF88 BC02A58F */  lw         $5, 0x2BC($29)
    /* 2EDF8C 003EDF8C 0000628E */  lw         $2, 0x0($19)
    /* 2EDF90 003EDF90 0400A48C */  lw         $4, 0x4($5)
    /* 2EDF94 003EDF94 05008214 */  bne        $4, $2, .L003EDFAC
    /* 2EDF98 003EDF98 00000000 */   nop
    /* 2EDF9C 003EDF9C 0800A38C */  lw         $3, 0x8($5)
    /* 2EDFA0 003EDFA0 0000428E */  lw         $2, 0x0($18)
    /* 2EDFA4 003EDFA4 1E006210 */  beq        $3, $2, .L003EE020
    /* 2EDFA8 003EDFA8 00000000 */   nop
  .L003EDFAC:
    /* 2EDFAC 003EDFAC 0C00B18C */  lw         $17, 0xC($5)
    /* 2EDFB0 003EDFB0 20000624 */  addiu      $6, $0, 0x20
    /* 2EDFB4 003EDFB4 4F002616 */  bne        $17, $6, .L003EE0F4
    /* 2EDFB8 003EDFB8 00000000 */   nop
    /* 2EDFBC 003EDFBC 0000648E */  lw         $4, 0x0($19)
  .L003EDFC0:
    /* 2EDFC0 003EDFC0 0000458E */  lw         $5, 0x0($18)
    /* 2EDFC4 003EDFC4 B0A80F0C */  jal        func_003ea2c0
    /* 2EDFC8 003EDFC8 20000624 */   addiu     $6, $0, 0x20
    /* 2EDFCC 003EDFCC 2D804000 */  daddu      $16, $2, $0
    /* 2EDFD0 003EDFD0 62000012 */  beqz       $16, .L003EE15C
    /* 2EDFD4 003EDFD4 00000000 */   nop
    /* 2EDFD8 003EDFD8 F8A80F0C */  jal        func_003ea3e0
    /* 2EDFDC 003EDFDC 2D200002 */   daddu     $4, $16, $0
    /* 2EDFE0 003EDFE0 62004010 */  beqz       $2, .L003EE16C
    /* 2EDFE4 003EDFE4 00000000 */   nop
    /* 2EDFE8 003EDFE8 BC02A58F */  lw         $5, 0x2BC($29)
    /* 2EDFEC 003EDFEC 2CB40F0C */  jal        func_003ed0b0
    /* 2EDFF0 003EDFF0 2D200002 */   daddu     $4, $16, $0
    /* 2EDFF4 003EDFF4 DCA80F0C */  jal        func_003ea370
    /* 2EDFF8 003EDFF8 BC02A48F */   lw        $4, 0x2BC($29)
    /* 2EDFFC 003EDFFC 04000224 */  addiu      $2, $0, 0x4
    /* 2EE000 003EE000 60002212 */  beq        $17, $2, .L003EE184
    /* 2EE004 003EE004 BC02B0AF */   sw        $16, 0x2BC($29)
    /* 2EE008 003EE008 08000224 */  addiu      $2, $0, 0x8
    /* 2EE00C 003EE00C 04002216 */  bne        $17, $2, .L003EE020
    /* 2EE010 003EE010 00000000 */   nop
    /* 2EE014 003EE014 2D282002 */  daddu      $5, $17, $0
    /* 2EE018 003EE018 CCB60F0C */  jal        func_003edb30
    /* 2EE01C 003EE01C BC02A427 */   addiu     $4, $29, 0x2BC
  .L003EE020:
    /* 2EE020 003EE020 5D000010 */  b          .L003EE198
    /* 2EE024 003EE024 BC02A28F */   lw        $2, 0x2BC($29)
  .L003EE028:
    /* 2EE028 003EE028 FF00A882 */  lb         $8, 0xFF($21)
    /* 2EE02C 003EE02C 01000224 */  addiu      $2, $0, 0x1
    /* 2EE030 003EE030 B002A2AF */  sw         $2, 0x2B0($29)
    /* 2EE034 003EE034 2D28A002 */  daddu      $5, $21, $0
    /* 2EE038 003EE038 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE03C 003EE03C 00010624 */  addiu      $6, $0, 0x100
    /* 2EE040 003EE040 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE044 003EE044 647D0F0C */  jal        func_003df590
    /* 2EE048 003EE048 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE04C 003EE04C B402A2AF */  sw         $2, 0x2B4($29)
    /* 2EE050 003EE050 347D0F0C */  jal        func_003df4d0
    /* 2EE054 003EE054 B002A427 */   addiu     $4, $29, 0x2B0
    /* 2EE058 003EE058 9EFF0010 */  b          .L003EDED4
    /* 2EE05C 003EE05C 9F02A0A3 */   sb        $0, 0x29F($29)
  .L003EE060:
    /* 2EE060 003EE060 FF008882 */  lb         $8, 0xFF($20)
    /* 2EE064 003EE064 01000224 */  addiu      $2, $0, 0x1
    /* 2EE068 003EE068 A802A2AF */  sw         $2, 0x2A8($29)
    /* 2EE06C 003EE06C 2D288002 */  daddu      $5, $20, $0
    /* 2EE070 003EE070 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE074 003EE074 00010624 */  addiu      $6, $0, 0x100
    /* 2EE078 003EE078 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE07C 003EE07C 647D0F0C */  jal        func_003df590
    /* 2EE080 003EE080 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE084 003EE084 AC02A2AF */  sw         $2, 0x2AC($29)
    /* 2EE088 003EE088 347D0F0C */  jal        func_003df4d0
    /* 2EE08C 003EE08C A802A427 */   addiu     $4, $29, 0x2A8
    /* 2EE090 003EE090 A9FF0010 */  b          .L003EDF38
    /* 2EE094 003EE094 9F01A0A3 */   sb        $0, 0x19F($29)
  .L003EE098:
    /* 2EE098 003EE098 3F000010 */  b          .L003EE198
    /* 2EE09C 003EE09C 2D100000 */   daddu     $2, $0, $0
  .L003EE0A0:
    /* 2EE0A0 003EE0A0 2D28C002 */  daddu      $5, $22, $0
    /* 2EE0A4 003EE0A4 2D40E002 */  daddu      $8, $23, $0
    /* 2EE0A8 003EE0A8 2D48C003 */  daddu      $9, $30, $0
    /* 2EE0AC 003EE0AC 2D204000 */  daddu      $4, $2, $0
    /* 2EE0B0 003EE0B0 2D306002 */  daddu      $6, $19, $0
    /* 2EE0B4 003EE0B4 7CB00F0C */  jal        func_003ec1f0
    /* 2EE0B8 003EE0B8 2D384002 */   daddu     $7, $18, $0
    /* 2EE0BC 003EE0BC B2FF4014 */  bnez       $2, .L003EDF88
    /* 2EE0C0 003EE0C0 00000000 */   nop
    /* 2EE0C4 003EE0C4 DCA80F0C */  jal        func_003ea370
    /* 2EE0C8 003EE0C8 BC02A48F */   lw        $4, 0x2BC($29)
    /* 2EE0CC 003EE0CC 01000324 */  addiu      $3, $0, 0x1
    /* 2EE0D0 003EE0D0 0080023C */  lui        $2, (0x80000009 >> 16)
    /* 2EE0D4 003EE0D4 A002A3AF */  sw         $3, 0x2A0($29)
    /* 2EE0D8 003EE0D8 647D0F0C */  jal        func_003df590
    /* 2EE0DC 003EE0DC 09004434 */   ori       $4, $2, (0x80000009 & 0xFFFF)
    /* 2EE0E0 003EE0E0 A402A2AF */  sw         $2, 0x2A4($29)
    /* 2EE0E4 003EE0E4 347D0F0C */  jal        func_003df4d0
    /* 2EE0E8 003EE0E8 A002A427 */   addiu     $4, $29, 0x2A0
    /* 2EE0EC 003EE0EC 2A000010 */  b          .L003EE198
    /* 2EE0F0 003EE0F0 2D100000 */   daddu     $2, $0, $0
  .L003EE0F4:
    /* 2EE0F4 003EE0F4 BC02B08F */  lw         $16, 0x2BC($29)
    /* 2EE0F8 003EE0F8 B0A80F0C */  jal        func_003ea2c0
    /* 2EE0FC 003EE0FC 0800058E */   lw        $5, 0x8($16)
    /* 2EE100 003EE100 0C004010 */  beqz       $2, .L003EE134
    /* 2EE104 003EE104 BC02A2AF */   sw        $2, 0x2BC($29)
    /* 2EE108 003EE108 F8A80F0C */  jal        func_003ea3e0
    /* 2EE10C 003EE10C 2D204000 */   daddu     $4, $2, $0
    /* 2EE110 003EE110 0C004010 */  beqz       $2, .L003EE144
    /* 2EE114 003EE114 00000000 */   nop
    /* 2EE118 003EE118 BC02A48F */  lw         $4, 0x2BC($29)
    /* 2EE11C 003EE11C B0AE0F0C */  jal        func_003ebac0
    /* 2EE120 003EE120 2D280002 */   daddu     $5, $16, $0
    /* 2EE124 003EE124 DCA80F0C */  jal        func_003ea370
    /* 2EE128 003EE128 2D200002 */   daddu     $4, $16, $0
    /* 2EE12C 003EE12C A4FF0010 */  b          .L003EDFC0
    /* 2EE130 003EE130 0000648E */   lw        $4, 0x0($19)
  .L003EE134:
    /* 2EE134 003EE134 DCA80F0C */  jal        func_003ea370
    /* 2EE138 003EE138 2D200002 */   daddu     $4, $16, $0
    /* 2EE13C 003EE13C 16000010 */  b          .L003EE198
    /* 2EE140 003EE140 2D100000 */   daddu     $2, $0, $0
  .L003EE144:
    /* 2EE144 003EE144 DCA80F0C */  jal        func_003ea370
    /* 2EE148 003EE148 BC02A48F */   lw        $4, 0x2BC($29)
    /* 2EE14C 003EE14C DCA80F0C */  jal        func_003ea370
    /* 2EE150 003EE150 2D200002 */   daddu     $4, $16, $0
    /* 2EE154 003EE154 10000010 */  b          .L003EE198
    /* 2EE158 003EE158 2D100000 */   daddu     $2, $0, $0
  .L003EE15C:
    /* 2EE15C 003EE15C DCA80F0C */  jal        func_003ea370
    /* 2EE160 003EE160 BC02A48F */   lw        $4, 0x2BC($29)
    /* 2EE164 003EE164 0C000010 */  b          .L003EE198
    /* 2EE168 003EE168 2D100000 */   daddu     $2, $0, $0
  .L003EE16C:
    /* 2EE16C 003EE16C DCA80F0C */  jal        func_003ea370
    /* 2EE170 003EE170 2D200002 */   daddu     $4, $16, $0
    /* 2EE174 003EE174 DCA80F0C */  jal        func_003ea370
    /* 2EE178 003EE178 BC02A48F */   lw        $4, 0x2BC($29)
    /* 2EE17C 003EE17C 06000010 */  b          .L003EE198
    /* 2EE180 003EE180 2D100000 */   daddu     $2, $0, $0
  .L003EE184:
    /* 2EE184 003EE184 2D282002 */  daddu      $5, $17, $0
    /* 2EE188 003EE188 CCB60F0C */  jal        func_003edb30
    /* 2EE18C 003EE18C BC02A427 */   addiu     $4, $29, 0x2BC
    /* 2EE190 003EE190 A3FF0010 */  b          .L003EE020
    /* 2EE194 003EE194 00000000 */   nop
  .L003EE198:
    /* 2EE198 003EE198 9000BFDF */  ld         $31, 0x90($29)
    /* 2EE19C 003EE19C 8000BE7B */  lq         $30, 0x80($29)
    /* 2EE1A0 003EE1A0 7000B77B */  lq         $23, 0x70($29)
    /* 2EE1A4 003EE1A4 6000B67B */  lq         $22, 0x60($29)
    /* 2EE1A8 003EE1A8 5000B57B */  lq         $21, 0x50($29)
    /* 2EE1AC 003EE1AC 4000B47B */  lq         $20, 0x40($29)
    /* 2EE1B0 003EE1B0 3000B37B */  lq         $19, 0x30($29)
    /* 2EE1B4 003EE1B4 2000B27B */  lq         $18, 0x20($29)
    /* 2EE1B8 003EE1B8 1000B17B */  lq         $17, 0x10($29)
    /* 2EE1BC 003EE1BC 0000B07B */  lq         $16, 0x0($29)
    /* 2EE1C0 003EE1C0 0800E003 */  jr         $31
    /* 2EE1C4 003EE1C4 C002BD27 */   addiu     $29, $29, 0x2C0
    /* 2EE1C8 003EE1C8 00000000 */  nop
    /* 2EE1CC 003EE1CC 00000000 */  nop
.size func_003ede50, 0x380

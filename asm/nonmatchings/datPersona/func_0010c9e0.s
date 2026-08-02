.section .text
.set noat
.set noreorder
glabel func_0010c9e0
    /* C9E0 0010C9E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* C9E4 0010C9E4 1000BFFF */  sd         $31, 0x10($29)
    /* C9E8 0010C9E8 0000B07F */  sq         $16, 0x0($29)
    /* C9EC 0010C9EC 2D808000 */  daddu      $16, $4, $0
    /* C9F0 0010C9F0 06000016 */  bnez       $16, .L0010CA0C
    /* C9F4 0010C9F4 00000000 */   nop
    /* C9F8 0010C9F8 5E00043C */  lui        $4, %hi(D_005E4318)
    /* C9FC 0010C9FC 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CA00 0010CA00 9D060524 */  addiu      $5, $0, 0x69D
    /* CA04 0010CA04 CCB5110C */  jal        func_0046d730
    /* CA08 0010CA08 00000000 */   nop
  .L0010CA0C:
    /* CA0C 0010CA0C 2D380000 */  daddu      $7, $0, $0
    /* CA10 0010CA10 2D300000 */  daddu      $6, $0, $0
    /* CA14 0010CA14 08000424 */  addiu      $4, $0, 0x8
    /* CA18 0010CA18 23000010 */  b          .L0010CAA8
    /* CA1C 0010CA1C 00000000 */   nop
  .L0010CA20:
    /* CA20 0010CA20 40180700 */  sll        $3, $7, 1
    /* CA24 0010CA24 21180302 */  addu       $3, $16, $3
    /* CA28 0010CA28 0C006524 */  addiu      $5, $3, 0xC
    /* CA2C 0010CA2C 0C006394 */  lhu        $3, 0xC($3)
    /* CA30 0010CA30 0F006014 */  bnez       $3, .L0010CA70
    /* CA34 0010CA34 00000000 */   nop
    /* CA38 0010CA38 0100E624 */  addiu      $6, $7, 0x1
    /* CA3C 0010CA3C 07000010 */  b          .L0010CA5C
    /* CA40 0010CA40 00000000 */   nop
  .L0010CA44:
    /* CA44 0010CA44 40180600 */  sll        $3, $6, 1
    /* CA48 0010CA48 21180302 */  addu       $3, $16, $3
    /* CA4C 0010CA4C 0C006394 */  lhu        $3, 0xC($3)
    /* CA50 0010CA50 05006014 */  bnez       $3, .L0010CA68
    /* CA54 0010CA54 00000000 */   nop
    /* CA58 0010CA58 0100C624 */  addiu      $6, $6, 0x1
  .L0010CA5C:
    /* CA5C 0010CA5C 0800C328 */  slti       $3, $6, 0x8
    /* CA60 0010CA60 F8FF6014 */  bnez       $3, .L0010CA44
    /* CA64 0010CA64 00000000 */   nop
  .L0010CA68:
    /* CA68 0010CA68 1200C410 */  beq        $6, $4, .L0010CAB4
    /* CA6C 0010CA6C 00000000 */   nop
  .L0010CA70:
    /* CA70 0010CA70 0B00E610 */  beq        $7, $6, .L0010CAA0
    /* CA74 0010CA74 00000000 */   nop
    /* CA78 0010CA78 0800C128 */  slti       $1, $6, 0x8
    /* CA7C 0010CA7C 07002010 */  beqz       $1, .L0010CA9C
    /* CA80 0010CA80 00000000 */   nop
    /* CA84 0010CA84 40180600 */  sll        $3, $6, 1
    /* CA88 0010CA88 21180302 */  addu       $3, $16, $3
    /* CA8C 0010CA8C 0C006394 */  lhu        $3, 0xC($3)
    /* CA90 0010CA90 0000A3A4 */  sh         $3, 0x0($5)
    /* CA94 0010CA94 02000010 */  b          .L0010CAA0
    /* CA98 0010CA98 00000000 */   nop
  .L0010CA9C:
    /* CA9C 0010CA9C 0000A0A4 */  sh         $0, 0x0($5)
  .L0010CAA0:
    /* CAA0 0010CAA0 0100E724 */  addiu      $7, $7, 0x1
    /* CAA4 0010CAA4 0100C624 */  addiu      $6, $6, 0x1
  .L0010CAA8:
    /* CAA8 0010CAA8 0800E328 */  slti       $3, $7, 0x8
    /* CAAC 0010CAAC DCFF6014 */  bnez       $3, .L0010CA20
    /* CAB0 0010CAB0 00000000 */   nop
  .L0010CAB4:
    /* CAB4 0010CAB4 1000BFDF */  ld         $31, 0x10($29)
    /* CAB8 0010CAB8 0000B07B */  lq         $16, 0x0($29)
    /* CABC 0010CABC 2000BD27 */  addiu      $29, $29, 0x20
    /* CAC0 0010CAC0 0800E003 */  jr         $31
    /* CAC4 0010CAC4 00000000 */   nop
    /* CAC8 0010CAC8 00000000 */  nop
    /* CACC 0010CACC 00000000 */  nop
.size func_0010c9e0, 0xf0

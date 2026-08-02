.section .text
.set noat
.set noreorder
glabel func_0010cad0
    /* CAD0 0010CAD0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* CAD4 0010CAD4 3000BFFF */  sd         $31, 0x30($29)
    /* CAD8 0010CAD8 2000B27F */  sq         $18, 0x20($29)
    /* CADC 0010CADC 1000B17F */  sq         $17, 0x10($29)
    /* CAE0 0010CAE0 0000B07F */  sq         $16, 0x0($29)
    /* CAE4 0010CAE4 2D908000 */  daddu      $18, $4, $0
    /* CAE8 0010CAE8 2D88A000 */  daddu      $17, $5, $0
    /* CAEC 0010CAEC 06004016 */  bnez       $18, .L0010CB08
    /* CAF0 0010CAF0 00000000 */   nop
    /* CAF4 0010CAF4 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CAF8 0010CAF8 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CAFC 0010CAFC C2060524 */  addiu      $5, $0, 0x6C2
    /* CB00 0010CB00 CCB5110C */  jal        func_0046d730
    /* CB04 0010CB04 00000000 */   nop
  .L0010CB08:
    /* CB08 0010CB08 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* CB0C 0010CB0C 04004010 */  beqz       $2, .L0010CB20
    /* CB10 0010CB10 00000000 */   nop
    /* CB14 0010CB14 00014228 */  slti       $2, $2, 0x100
    /* CB18 0010CB18 06004014 */  bnez       $2, .L0010CB34
    /* CB1C 0010CB1C 00000000 */   nop
  .L0010CB20:
    /* CB20 0010CB20 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CB24 0010CB24 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CB28 0010CB28 C3060524 */  addiu      $5, $0, 0x6C3
    /* CB2C 0010CB2C CCB5110C */  jal        func_0046d730
    /* CB30 0010CB30 00000000 */   nop
  .L0010CB34:
    /* CB34 0010CB34 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* CB38 0010CB38 C0100300 */  sll        $2, $3, 3
    /* CB3C 0010CB3C 23104300 */  subu       $2, $2, $3
    /* CB40 0010CB40 40800200 */  sll        $16, $2, 1
    /* CB44 0010CB44 D4B3828F */  lw         $2, -0x4C2C($28)
    /* CB48 0010CB48 21185000 */  addu       $3, $2, $16
    /* CB4C 0010CB4C 020051A6 */  sh         $17, 0x2($18)
    /* CB50 0010CB50 03006290 */  lbu        $2, 0x3($3)
    /* CB54 0010CB54 040042A2 */  sb         $2, 0x4($18)
    /* CB58 0010CB58 09006290 */  lbu        $2, 0x9($3)
    /* CB5C 0010CB5C 050042A2 */  sb         $2, 0x5($18)
    /* CB60 0010CB60 03006590 */  lbu        $5, 0x3($3)
    /* CB64 0010CB64 2D204002 */  daddu      $4, $18, $0
    /* CB68 0010CB68 D431040C */  jal        func_0010c750
    /* CB6C 0010CB6C 00000000 */   nop
    /* CB70 0010CB70 080042AE */  sw         $2, 0x8($18)
    /* CB74 0010CB74 2C0040AE */  sw         $0, 0x2C($18)
    /* CB78 0010CB78 D4B3828F */  lw         $2, -0x4C2C($28)
    /* CB7C 0010CB7C 21105000 */  addu       $2, $2, $16
    /* CB80 0010CB80 1C004426 */  addiu      $4, $18, 0x1C
    /* CB84 0010CB84 04004524 */  addiu      $5, $2, 0x4
    /* CB88 0010CB88 05000624 */  addiu      $6, $0, 0x5
    /* CB8C 0010CB8C 04FE100C */  jal        func_0043f810
    /* CB90 0010CB90 00000000 */   nop
    /* CB94 0010CB94 21004426 */  addiu      $4, $18, 0x21
    /* CB98 0010CB98 2D280000 */  daddu      $5, $0, $0
    /* CB9C 0010CB9C 05000624 */  addiu      $6, $0, 0x5
    /* CBA0 0010CBA0 72FE100C */  jal        func_0043f9c8
    /* CBA4 0010CBA4 00000000 */   nop
    /* CBA8 0010CBA8 26004426 */  addiu      $4, $18, 0x26
    /* CBAC 0010CBAC 2D280000 */  daddu      $5, $0, $0
    /* CBB0 0010CBB0 05000624 */  addiu      $6, $0, 0x5
    /* CBB4 0010CBB4 72FE100C */  jal        func_0043f9c8
    /* CBB8 0010CBB8 00000000 */   nop
    /* CBBC 0010CBBC 0C004426 */  addiu      $4, $18, 0xC
    /* CBC0 0010CBC0 2D280000 */  daddu      $5, $0, $0
    /* CBC4 0010CBC4 10000624 */  addiu      $6, $0, 0x10
    /* CBC8 0010CBC8 72FE100C */  jal        func_0043f9c8
    /* CBCC 0010CBCC 00000000 */   nop
    /* CBD0 0010CBD0 2D204002 */  daddu      $4, $18, $0
    /* CBD4 0010CBD4 4000A527 */  addiu      $5, $29, 0x40
    /* CBD8 0010CBD8 2D300000 */  daddu      $6, $0, $0
    /* CBDC 0010CBDC 982F040C */  jal        func_0010be60
    /* CBE0 0010CBE0 00000000 */   nop
    /* CBE4 0010CBE4 2D204002 */  daddu      $4, $18, $0
    /* CBE8 0010CBE8 4000A527 */  addiu      $5, $29, 0x40
    /* CBEC 0010CBEC 6831040C */  jal        func_0010c5a0
    /* CBF0 0010CBF0 00000000 */   nop
    /* CBF4 0010CBF4 2D204002 */  daddu      $4, $18, $0
    /* CBF8 0010CBF8 5434040C */  jal        func_0010d150
    /* CBFC 0010CBFC 00000000 */   nop
    /* CC00 0010CC00 3000BFDF */  ld         $31, 0x30($29)
    /* CC04 0010CC04 2000B27B */  lq         $18, 0x20($29)
    /* CC08 0010CC08 1000B17B */  lq         $17, 0x10($29)
    /* CC0C 0010CC0C 0000B07B */  lq         $16, 0x0($29)
    /* CC10 0010CC10 D000BD27 */  addiu      $29, $29, 0xD0
    /* CC14 0010CC14 0800E003 */  jr         $31
    /* CC18 0010CC18 00000000 */   nop
    /* CC1C 0010CC1C 00000000 */  nop
.size func_0010cad0, 0x150

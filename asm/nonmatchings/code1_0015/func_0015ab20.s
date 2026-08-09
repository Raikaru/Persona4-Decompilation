.section .text
.set noat
.set noreorder
glabel func_0015ab20
    /* 5AB20 0015AB20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 5AB24 0015AB24 3000BFFF */  sd         $31, 0x30($29)
    /* 5AB28 0015AB28 2000B27F */  sq         $18, 0x20($29)
    /* 5AB2C 0015AB2C 1000B17F */  sq         $17, 0x10($29)
    /* 5AB30 0015AB30 0000B07F */  sq         $16, 0x0($29)
    /* 5AB34 0015AB34 2D90A000 */  daddu      $18, $5, $0
    /* 5AB38 0015AB38 2D88C000 */  daddu      $17, $6, $0
    /* 5AB3C 0015AB3C 2D300000 */  daddu      $6, $0, $0
    /* 5AB40 0015AB40 5F00033C */  lui        $3, %hi(D_005F05D0)
    /* 5AB44 0015AB44 D0056324 */  addiu      $3, $3, %lo(D_005F05D0)
    /* 5AB48 0015AB48 05000010 */  b          .L0015AB60
    /* 5AB4C 0015AB4C 00000000 */   nop
  .L0015AB50:
    /* 5AB50 0015AB50 2A108200 */  slt        $2, $4, $2
    /* 5AB54 0015AB54 07004014 */  bnez       $2, .L0015AB74
    /* 5AB58 0015AB58 00000000 */   nop
    /* 5AB5C 0015AB5C 0100C624 */  addiu      $6, $6, 0x1
  .L0015AB60:
    /* 5AB60 0015AB60 40280600 */  sll        $5, $6, 1
    /* 5AB64 0015AB64 21106500 */  addu       $2, $3, $5
    /* 5AB68 0015AB68 00004284 */  lh         $2, 0x0($2)
    /* 5AB6C 0015AB6C F8FF4104 */  bgez       $2, .L0015AB50
    /* 5AB70 0015AB70 00000000 */   nop
  .L0015AB74:
    /* 5AB74 0015AB74 0400C014 */  bnez       $6, .L0015AB88
    /* 5AB78 0015AB78 00000000 */   nop
    /* 5AB7C 0015AB7C 2D100000 */  daddu      $2, $0, $0
    /* 5AB80 0015AB80 30000010 */  b          .L0015AC44
    /* 5AB84 0015AB84 00000000 */   nop
  .L0015AB88:
    /* 5AB88 0015AB88 5F00023C */  lui        $2, %hi(D_005F05CE)
    /* 5AB8C 0015AB8C CE054224 */  addiu      $2, $2, %lo(D_005F05CE)
    /* 5AB90 0015AB90 21104500 */  addu       $2, $2, $5
    /* 5AB94 0015AB94 00004284 */  lh         $2, 0x0($2)
    /* 5AB98 0015AB98 23808200 */  subu       $16, $4, $2
    /* 5AB9C 0015AB9C 1400022A */  slti       $2, $16, 0x14
    /* 5ABA0 0015ABA0 06004014 */  bnez       $2, .L0015ABBC
    /* 5ABA4 0015ABA4 00000000 */   nop
    /* 5ABA8 0015ABA8 5F00043C */  lui        $4, %hi(D_005F05E8)
    /* 5ABAC 0015ABAC E8058424 */  addiu      $4, $4, %lo(D_005F05E8)
    /* 5ABB0 0015ABB0 E3080524 */  addiu      $5, $0, 0x8E3
    /* 5ABB4 0015ABB4 CCB5110C */  jal        func_0046d730
    /* 5ABB8 0015ABB8 00000000 */   nop
  .L0015ABBC:
    /* 5ABBC 0015ABBC 7D00023C */  lui        $2, %hi(D_007D3E10)
    /* 5ABC0 0015ABC0 103E4224 */  addiu      $2, $2, %lo(D_007D3E10)
    /* 5ABC4 0015ABC4 21105000 */  addu       $2, $2, $16
    /* 5ABC8 0015ABC8 00004390 */  lbu        $3, 0x0($2)
    /* 5ABCC 0015ABCC 01000224 */  addiu      $2, $0, 0x1
    /* 5ABD0 0015ABD0 16006214 */  bne        $3, $2, .L0015AC2C
    /* 5ABD4 0015ABD4 00000000 */   nop
    /* 5ABD8 0015ABD8 A054050C */  jal        func_00155280
    /* 5ABDC 0015ABDC 00000000 */   nop
    /* 5ABE0 0015ABE0 001A1100 */  sll        $3, $17, 8
    /* 5ABE4 0015ABE4 21184300 */  addu       $3, $2, $3
    /* 5ABE8 0015ABE8 00111200 */  sll        $2, $18, 4
    /* 5ABEC 0015ABEC 21106200 */  addu       $2, $3, $2
    /* 5ABF0 0015ABF0 5F004490 */  lbu        $4, 0x5F($2)
    /* 5ABF4 0015ABF4 40101000 */  sll        $2, $16, 1
    /* 5ABF8 0015ABF8 21105000 */  addu       $2, $2, $16
    /* 5ABFC 0015ABFC 801A0200 */  sll        $3, $2, 10
    /* 5AC00 0015AC00 7D00023C */  lui        $2, %hi(D_007D3E2B)
    /* 5AC04 0015AC04 2B3E4224 */  addiu      $2, $2, %lo(D_007D3E2B)
    /* 5AC08 0015AC08 21184300 */  addu       $3, $2, $3
    /* 5AC0C 0015AC0C C0111100 */  sll        $2, $17, 7
    /* 5AC10 0015AC10 21184300 */  addu       $3, $2, $3
    /* 5AC14 0015AC14 C0101200 */  sll        $2, $18, 3
    /* 5AC18 0015AC18 21104300 */  addu       $2, $2, $3
    /* 5AC1C 0015AC1C 000044A0 */  sb         $4, 0x0($2)
    /* 5AC20 0015AC20 01000224 */  addiu      $2, $0, 0x1
    /* 5AC24 0015AC24 07000010 */  b          .L0015AC44
    /* 5AC28 0015AC28 00000000 */   nop
  .L0015AC2C:
    /* 5AC2C 0015AC2C 5F00043C */  lui        $4, %hi(D_005F05E8)
    /* 5AC30 0015AC30 E8058424 */  addiu      $4, $4, %lo(D_005F05E8)
    /* 5AC34 0015AC34 ED080524 */  addiu      $5, $0, 0x8ED
    /* 5AC38 0015AC38 CCB5110C */  jal        func_0046d730
    /* 5AC3C 0015AC3C 00000000 */   nop
    /* 5AC40 0015AC40 2D100000 */  daddu      $2, $0, $0
  .L0015AC44:
    /* 5AC44 0015AC44 3000BFDF */  ld         $31, 0x30($29)
    /* 5AC48 0015AC48 2000B27B */  lq         $18, 0x20($29)
    /* 5AC4C 0015AC4C 1000B17B */  lq         $17, 0x10($29)
    /* 5AC50 0015AC50 0000B07B */  lq         $16, 0x0($29)
    /* 5AC54 0015AC54 4000BD27 */  addiu      $29, $29, 0x40
    /* 5AC58 0015AC58 0800E003 */  jr         $31
    /* 5AC5C 0015AC5C 00000000 */   nop
.size func_0015ab20, 0x140

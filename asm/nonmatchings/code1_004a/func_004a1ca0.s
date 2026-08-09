.section .text
.set noat
.set noreorder
glabel func_004a1ca0
    /* 3A1CA0 004A1CA0 3C00858C */  lw         $5, 0x3C($4)
    /* 3A1CA4 004A1CA4 0000A78C */  lw         $7, 0x0($5)
    /* 3A1CA8 004A1CA8 4000838C */  lw         $3, 0x40($4)
    /* 3A1CAC 004A1CAC 3800648C */  lw         $4, 0x38($3)
    /* 3A1CB0 004A1CB0 2D300000 */  daddu      $6, $0, $0
    /* 3A1CB4 004A1CB4 FF000324 */  addiu      $3, $0, 0xFF
    /* 3A1CB8 004A1CB8 FE000E24 */  addiu      $14, $0, 0xFE
    /* 3A1CBC 004A1CBC FFFF0924 */  addiu      $9, $0, -0x1
    /* 3A1CC0 004A1CC0 26000010 */  b          .L004A1D5C
    /* 3A1CC4 004A1CC4 00000000 */   nop
  .L004A1CC8:
    /* 3A1CC8 004A1CC8 0400AB8C */  lw         $11, 0x4($5)
    /* 3A1CCC 004A1CCC 67BB8893 */  lbu        $8, -0x4499($28)
    /* 3A1CD0 004A1CD0 10000311 */  beq        $8, $3, .L004A1D14
    /* 3A1CD4 004A1CD4 00000000 */   nop
    /* 3A1CD8 004A1CD8 FFFFC830 */  andi       $8, $6, 0xFFFF
    /* 3A1CDC 004A1CDC 80500800 */  sll        $10, $8, 2
    /* 3A1CE0 004A1CE0 5400688D */  lw         $8, 0x54($11)
    /* 3A1CE4 004A1CE4 21400A01 */  addu       $8, $8, $10
    /* 3A1CE8 004A1CE8 00000D8D */  lw         $13, 0x0($8)
    /* 3A1CEC 004A1CEC 64BB8C93 */  lbu        $12, -0x449C($28)
    /* 3A1CF0 004A1CF0 65BB8B93 */  lbu        $11, -0x449B($28)
    /* 3A1CF4 004A1CF4 66BB8A93 */  lbu        $10, -0x449A($28)
    /* 3A1CF8 004A1CF8 67BB8893 */  lbu        $8, -0x4499($28)
    /* 3A1CFC 004A1CFC 0400ACA1 */  sb         $12, 0x4($13)
    /* 3A1D00 004A1D00 0500ABA1 */  sb         $11, 0x5($13)
    /* 3A1D04 004A1D04 0600AAA1 */  sb         $10, 0x6($13)
    /* 3A1D08 004A1D08 0700A8A1 */  sb         $8, 0x7($13)
    /* 3A1D0C 004A1D0C 10000010 */  b          .L004A1D50
    /* 3A1D10 004A1D10 00000000 */   nop
  .L004A1D14:
    /* 3A1D14 004A1D14 67BB8EA3 */  sb         $14, -0x4499($28)
    /* 3A1D18 004A1D18 FFFFC830 */  andi       $8, $6, 0xFFFF
    /* 3A1D1C 004A1D1C 80500800 */  sll        $10, $8, 2
    /* 3A1D20 004A1D20 5400688D */  lw         $8, 0x54($11)
    /* 3A1D24 004A1D24 21400A01 */  addu       $8, $8, $10
    /* 3A1D28 004A1D28 00000D8D */  lw         $13, 0x0($8)
    /* 3A1D2C 004A1D2C 64BB8C93 */  lbu        $12, -0x449C($28)
    /* 3A1D30 004A1D30 65BB8B93 */  lbu        $11, -0x449B($28)
    /* 3A1D34 004A1D34 66BB8A93 */  lbu        $10, -0x449A($28)
    /* 3A1D38 004A1D38 67BB8893 */  lbu        $8, -0x4499($28)
    /* 3A1D3C 004A1D3C 0400ACA1 */  sb         $12, 0x4($13)
    /* 3A1D40 004A1D40 0500ABA1 */  sb         $11, 0x5($13)
    /* 3A1D44 004A1D44 0600AAA1 */  sb         $10, 0x6($13)
    /* 3A1D48 004A1D48 0700A8A1 */  sb         $8, 0x7($13)
    /* 3A1D4C 004A1D4C 67BB83A3 */  sb         $3, -0x4499($28)
  .L004A1D50:
    /* 3A1D50 004A1D50 0000E9AC */  sw         $9, 0x0($7)
    /* 3A1D54 004A1D54 0100C624 */  addiu      $6, $6, 0x1
    /* 3A1D58 004A1D58 3000E724 */  addiu      $7, $7, 0x30
  .L004A1D5C:
    /* 3A1D5C 004A1D5C 2B40C400 */  sltu       $8, $6, $4
    /* 3A1D60 004A1D60 D9FF0015 */  bnez       $8, .L004A1CC8
    /* 3A1D64 004A1D64 00000000 */   nop
    /* 3A1D68 004A1D68 0800E003 */  jr         $31
    /* 3A1D6C 004A1D6C 00000000 */   nop
.size func_004a1ca0, 0xd0

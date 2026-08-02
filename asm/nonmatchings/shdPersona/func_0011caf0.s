.section .text
.set noat
.set noreorder
glabel func_0011caf0
    /* 1CAF0 0011CAF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1CAF4 0011CAF4 0000BFFF */  sd         $31, 0x0($29)
    /* 1CAF8 0011CAF8 3800868C */  lw         $6, 0x38($4)
    /* 1CAFC 0011CAFC 3405C58C */  lw         $5, 0x534($6)
    /* 1CB00 0011CB00 0008A330 */  andi       $3, $5, 0x800
    /* 1CB04 0011CB04 2B180300 */  sltu       $3, $0, $3
    /* 1CB08 0011CB08 05006010 */  beqz       $3, .L0011CB20
    /* 1CB0C 0011CB0C 00000000 */   nop
    /* 1CB10 0011CB10 8800C480 */  lb         $4, 0x88($6)
    /* 1CB14 0011CB14 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1CB18 0011CB18 03008314 */  bne        $4, $3, .L0011CB28
    /* 1CB1C 0011CB1C 00000000 */   nop
  .L0011CB20:
    /* 1CB20 0011CB20 0F000010 */  b          .L0011CB60
    /* 1CB24 0011CB24 00000000 */   nop
  .L0011CB28:
    /* 1CB28 0011CB28 1000023C */  lui        $2, (0x100000 >> 16)
    /* 1CB2C 0011CB2C 2410A200 */  and        $2, $5, $2
    /* 1CB30 0011CB30 2B280200 */  sltu       $5, $0, $2
    /* 1CB34 0011CB34 8400C424 */  addiu      $4, $6, 0x84
    /* 1CB38 0011CB38 0854040C */  jal        func_00115020
    /* 1CB3C 0011CB3C 00000000 */   nop
    /* 1CB40 0011CB40 07004010 */  beqz       $2, .L0011CB60
    /* 1CB44 0011CB44 00000000 */   nop
    /* 1CB48 0011CB48 2D200000 */  daddu      $4, $0, $0
    /* 1CB4C 0011CB4C 2D280000 */  daddu      $5, $0, $0
    /* 1CB50 0011CB50 2D300000 */  daddu      $6, $0, $0
    /* 1CB54 0011CB54 2D380000 */  daddu      $7, $0, $0
    /* 1CB58 0011CB58 D86B110C */  jal        func_0045af60
    /* 1CB5C 0011CB5C 00000000 */   nop
  .L0011CB60:
    /* 1CB60 0011CB60 0000BFDF */  ld         $31, 0x0($29)
    /* 1CB64 0011CB64 1000BD27 */  addiu      $29, $29, 0x10
    /* 1CB68 0011CB68 0800E003 */  jr         $31
    /* 1CB6C 0011CB6C 00000000 */   nop
.size func_0011caf0, 0x80

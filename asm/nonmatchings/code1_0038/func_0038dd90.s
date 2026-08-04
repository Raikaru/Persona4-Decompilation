.section .text
.set noat
.set noreorder
glabel func_0038dd90
    /* 28DD90 0038DD90 000080AC */  sw         $0, 0x0($4)
    /* 28DD94 0038DD94 FF000324 */  addiu      $3, $0, 0xFF
    /* 28DD98 0038DD98 2C1283A0 */  sb         $3, 0x122C($4)
    /* 28DD9C 0038DD9C 2D1283A0 */  sb         $3, 0x122D($4)
    /* 28DDA0 0038DDA0 2E1283A0 */  sb         $3, 0x122E($4)
    /* 28DDA4 0038DDA4 2F1283A0 */  sb         $3, 0x122F($4)
    /* 28DDA8 0038DDA8 2D280000 */  daddu      $5, $0, $0
    /* 28DDAC 0038DDAC 07000010 */  b          .L0038DDCC
    /* 28DDB0 0038DDB0 00000000 */   nop
  .L0038DDB4:
    /* 28DDB4 0038DDB4 C0180500 */  sll        $3, $5, 3
    /* 28DDB8 0038DDB8 21186500 */  addu       $3, $3, $5
    /* 28DDBC 0038DDBC 00190300 */  sll        $3, $3, 4
    /* 28DDC0 0038DDC0 21188300 */  addu       $3, $4, $3
    /* 28DDC4 0038DDC4 040060AC */  sw         $0, 0x4($3)
    /* 28DDC8 0038DDC8 0100A524 */  addiu      $5, $5, 0x1
  .L0038DDCC:
    /* 28DDCC 0038DDCC 2000A328 */  slti       $3, $5, 0x20
    /* 28DDD0 0038DDD0 F8FF6014 */  bnez       $3, .L0038DDB4
    /* 28DDD4 0038DDD4 00000000 */   nop
    /* 28DDD8 0038DDD8 B0B584AF */  sw         $4, -0x4A50($28)
    /* 28DDDC 0038DDDC 0800E003 */  jr         $31
    /* 28DDE0 0038DDE0 00000000 */   nop
    /* 28DDE4 0038DDE4 00000000 */  nop
    /* 28DDE8 0038DDE8 00000000 */  nop
    /* 28DDEC 0038DDEC 00000000 */  nop
.size func_0038dd90, 0x60

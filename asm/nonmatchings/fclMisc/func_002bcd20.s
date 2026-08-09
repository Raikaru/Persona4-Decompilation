.section .text
.set noat
.set noreorder
glabel func_002bcd20
    /* 1BCD20 002BCD20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BCD24 002BCD24 2000BFFF */  sd         $31, 0x20($29)
    /* 1BCD28 002BCD28 1000B17F */  sq         $17, 0x10($29)
    /* 1BCD2C 002BCD2C 0000B07F */  sq         $16, 0x0($29)
    /* 1BCD30 002BCD30 8800103C */  lui        $16, %hi(D_00882F30)
    /* 1BCD34 002BCD34 302F1026 */  addiu      $16, $16, %lo(D_00882F30)
    /* 1BCD38 002BCD38 A0000424 */  addiu      $4, $0, 0xA0
    /* 1BCD3C 002BCD3C 2D280000 */  daddu      $5, $0, $0
    /* 1BCD40 002BCD40 2D300000 */  daddu      $6, $0, $0
    /* 1BCD44 002BCD44 2D380000 */  daddu      $7, $0, $0
    /* 1BCD48 002BCD48 6C870B0C */  jal        func_002e1db0
    /* 1BCD4C 002BCD4C 00000000 */   nop
    /* 1BCD50 002BCD50 2400518C */  lw         $17, 0x24($2)
    /* 1BCD54 002BCD54 000022AE */  sw         $2, 0x0($17)
    /* 1BCD58 002BCD58 0C000424 */  addiu      $4, $0, 0xC
    /* 1BCD5C 002BCD5C 2D280000 */  daddu      $5, $0, $0
    /* 1BCD60 002BCD60 2D300000 */  daddu      $6, $0, $0
    /* 1BCD64 002BCD64 2D380000 */  daddu      $7, $0, $0
    /* 1BCD68 002BCD68 6C870B0C */  jal        func_002e1db0
    /* 1BCD6C 002BCD6C 00000000 */   nop
    /* 1BCD70 002BCD70 180022AE */  sw         $2, 0x18($17)
    /* 1BCD74 002BCD74 0400228E */  lw         $2, 0x4($17)
    /* 1BCD78 002BCD78 01004234 */  ori        $2, $2, 0x1
    /* 1BCD7C 002BCD7C 040022AE */  sw         $2, 0x4($17)
    /* 1BCD80 002BCD80 7CB591AF */  sw         $17, -0x4A84($28)
    /* 1BCD84 002BCD84 2D100002 */  daddu      $2, $16, $0
    /* 1BCD88 002BCD88 09004010 */  beqz       $2, .L002BCDB0
    /* 1BCD8C 002BCD8C 00000000 */   nop
    /* 1BCD90 002BCD90 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BCD94 002BCD94 000002AE */  sw         $2, 0x0($16)
    /* 1BCD98 002BCD98 040000A2 */  sb         $0, 0x4($16)
    /* 1BCD9C 002BCD9C 050000A2 */  sb         $0, 0x5($16)
    /* 1BCDA0 002BCDA0 080002AE */  sw         $2, 0x8($16)
    /* 1BCDA4 002BCDA4 01000224 */  addiu      $2, $0, 0x1
    /* 1BCDA8 002BCDA8 0C0002A2 */  sb         $2, 0xC($16)
    /* 1BCDAC 002BCDAC 0D0002A2 */  sb         $2, 0xD($16)
  .L002BCDB0:
    /* 1BCDB0 002BCDB0 6400043C */  lui        $4, %hi(D_0063F398)
    /* 1BCDB4 002BCDB4 98F38424 */  addiu      $4, $4, %lo(D_0063F398)
    /* 1BCDB8 002BCDB8 0F000524 */  addiu      $5, $0, 0xF
    /* 1BCDBC 002BCDBC 2D300000 */  daddu      $6, $0, $0
    /* 1BCDC0 002BCDC0 2D380000 */  daddu      $7, $0, $0
    /* 1BCDC4 002BCDC4 2C00083C */  lui        $8, %hi(func_002bce00)
    /* 1BCDC8 002BCDC8 00CE0825 */  addiu      $8, $8, %lo(func_002bce00)
    /* 1BCDCC 002BCDCC 2D480000 */  daddu      $9, $0, $0
    /* 1BCDD0 002BCDD0 2D500000 */  daddu      $10, $0, $0
    /* 1BCDD4 002BCDD4 7847110C */  jal        func_00451de0
    /* 1BCDD8 002BCDD8 00000000 */   nop
    /* 1BCDDC 002BCDDC 2000BFDF */  ld         $31, 0x20($29)
    /* 1BCDE0 002BCDE0 1000B17B */  lq         $17, 0x10($29)
    /* 1BCDE4 002BCDE4 0000B07B */  lq         $16, 0x0($29)
    /* 1BCDE8 002BCDE8 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BCDEC 002BCDEC 0800E003 */  jr         $31
    /* 1BCDF0 002BCDF0 00000000 */   nop
    /* 1BCDF4 002BCDF4 00000000 */  nop
    /* 1BCDF8 002BCDF8 00000000 */  nop
    /* 1BCDFC 002BCDFC 00000000 */  nop
.size func_002bcd20, 0xe0

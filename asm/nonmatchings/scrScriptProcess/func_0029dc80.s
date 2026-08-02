.section .text
.set noat
.set noreorder
glabel func_0029dc80
    /* 19DC80 0029DC80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 19DC84 0029DC84 1000BFFF */  sd         $31, 0x10($29)
    /* 19DC88 0029DC88 0000B07F */  sq         $16, 0x0($29)
    /* 19DC8C 0029DC8C 2D808000 */  daddu      $16, $4, $0
    /* 19DC90 0029DC90 2C01828C */  lw         $2, 0x12C($4)
    /* 19DC94 0029DC94 40190200 */  sll        $3, $2, 5
    /* 19DC98 0029DC98 1801828C */  lw         $2, 0x118($4)
    /* 19DC9C 0029DC9C 21284300 */  addu       $5, $2, $3
    /* 19DCA0 0029DCA0 6400043C */  lui        $4, %hi(D_0063E548)
    /* 19DCA4 0029DCA4 48E58424 */  addiu      $4, $4, %lo(D_0063E548)
    /* 19DCA8 0029DCA8 DA02110C */  jal        func_00440b68
    /* 19DCAC 0029DCAC 00000000 */   nop
    /* 19DCB0 0029DCB0 2C01028E */  lw         $2, 0x12C($16)
    /* 19DCB4 0029DCB4 40190200 */  sll        $3, $2, 5
    /* 19DCB8 0029DCB8 1801028E */  lw         $2, 0x118($16)
    /* 19DCBC 0029DCBC 21284300 */  addu       $5, $2, $3
    /* 19DCC0 0029DCC0 6400043C */  lui        $4, %hi(D_0063E560)
    /* 19DCC4 0029DCC4 60E58424 */  addiu      $4, $4, %lo(D_0063E560)
    /* 19DCC8 0029DCC8 3C41110C */  jal        func_004504f0
    /* 19DCCC 0029DCCC 00000000 */   nop
    /* 19DCD0 0029DCD0 24B5848F */  lw         $4, -0x4ADC($28)
    /* 19DCD4 0029DCD4 4001058E */  lw         $5, 0x140($16)
    /* 19DCD8 0029DCD8 70740A0C */  jal        func_0029d1c0
    /* 19DCDC 0029DCDC 00000000 */   nop
    /* 19DCE0 0029DCE0 3001048E */  lw         $4, 0x130($16)
    /* 19DCE4 0029DCE4 07008004 */  bltz       $4, .L0029DD04
    /* 19DCE8 0029DCE8 00000000 */   nop
    /* 19DCEC 0029DCEC FCDD090C */  jal        func_002777f0
    /* 19DCF0 0029DCF0 00000000 */   nop
    /* 19DCF4 0029DCF4 6400043C */  lui        $4, %hi(D_0063E580)
    /* 19DCF8 0029DCF8 80E58424 */  addiu      $4, $4, %lo(D_0063E580)
    /* 19DCFC 0029DCFC DA02110C */  jal        func_00440b68
    /* 19DD00 0029DD00 00000000 */   nop
  .L0029DD04:
    /* 19DD04 0029DD04 3C01048E */  lw         $4, 0x13C($16)
    /* 19DD08 0029DD08 07008010 */  beqz       $4, .L0029DD28
    /* 19DD0C 0029DD0C 00000000 */   nop
    /* 19DD10 0029DD10 D0A8110C */  jal        func_0046a340
    /* 19DD14 0029DD14 00000000 */   nop
    /* 19DD18 0029DD18 6400043C */  lui        $4, %hi(D_0063E5A0)
    /* 19DD1C 0029DD1C A0E58424 */  addiu      $4, $4, %lo(D_0063E5A0)
    /* 19DD20 0029DD20 DA02110C */  jal        func_00440b68
    /* 19DD24 0029DD24 00000000 */   nop
  .L0029DD28:
    /* 19DD28 0029DD28 18B5828F */  lw         $2, -0x4AE8($28)
    /* 19DD2C 0029DD2C 05005014 */  bne        $2, $16, .L0029DD44
    /* 19DD30 0029DD30 00000000 */   nop
    /* 19DD34 0029DD34 5001028E */  lw         $2, 0x150($16)
    /* 19DD38 0029DD38 18B582AF */  sw         $2, -0x4AE8($28)
    /* 19DD3C 0029DD3C 04000010 */  b          .L0029DD50
    /* 19DD40 0029DD40 00000000 */   nop
  .L0029DD44:
    /* 19DD44 0029DD44 5001038E */  lw         $3, 0x150($16)
    /* 19DD48 0029DD48 4C01028E */  lw         $2, 0x14C($16)
    /* 19DD4C 0029DD4C 500143AC */  sw         $3, 0x150($2)
  .L0029DD50:
    /* 19DD50 0029DD50 1CB5828F */  lw         $2, -0x4AE4($28)
    /* 19DD54 0029DD54 05005014 */  bne        $2, $16, .L0029DD6C
    /* 19DD58 0029DD58 00000000 */   nop
    /* 19DD5C 0029DD5C 4C01028E */  lw         $2, 0x14C($16)
    /* 19DD60 0029DD60 1CB582AF */  sw         $2, -0x4AE4($28)
    /* 19DD64 0029DD64 04000010 */  b          .L0029DD78
    /* 19DD68 0029DD68 00000000 */   nop
  .L0029DD6C:
    /* 19DD6C 0029DD6C 4C01038E */  lw         $3, 0x14C($16)
    /* 19DD70 0029DD70 5001028E */  lw         $2, 0x150($16)
    /* 19DD74 0029DD74 4C0143AC */  sw         $3, 0x14C($2)
  .L0029DD78:
    /* 19DD78 0029DD78 4C0100AE */  sw         $0, 0x14C($16)
    /* 19DD7C 0029DD7C 500100AE */  sw         $0, 0x150($16)
    /* 19DD80 0029DD80 14B5828F */  lw         $2, -0x4AEC($28)
    /* 19DD84 0029DD84 FFFF4224 */  addiu      $2, $2, -0x1
    /* 19DD88 0029DD88 14B582AF */  sw         $2, -0x4AEC($28)
    /* 19DD8C 0029DD8C 20B5848F */  lw         $4, -0x4AE0($28)
    /* 19DD90 0029DD90 2D280002 */  daddu      $5, $16, $0
    /* 19DD94 0029DD94 70740A0C */  jal        func_0029d1c0
    /* 19DD98 0029DD98 00000000 */   nop
    /* 19DD9C 0029DD9C 1000BFDF */  ld         $31, 0x10($29)
    /* 19DDA0 0029DDA0 0000B07B */  lq         $16, 0x0($29)
    /* 19DDA4 0029DDA4 2000BD27 */  addiu      $29, $29, 0x20
    /* 19DDA8 0029DDA8 0800E003 */  jr         $31
    /* 19DDAC 0029DDAC 00000000 */   nop
.size func_0029dc80, 0x130

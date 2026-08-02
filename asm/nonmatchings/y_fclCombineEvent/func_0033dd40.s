.section .text
.set noat
.set noreorder
glabel func_0033dd40
    /* 23DD40 0033DD40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23DD44 0033DD44 1000BFFF */  sd         $31, 0x10($29)
    /* 23DD48 0033DD48 0000B07F */  sq         $16, 0x0($29)
    /* 23DD4C 0033DD4C 3800908C */  lw         $16, 0x38($4)
    /* 23DD50 0033DD50 CC160A0C */  jal        func_00285b30
    /* 23DD54 0033DD54 00000000 */   nop
    /* 23DD58 0033DD58 04004228 */  slti       $2, $2, 0x4
    /* 23DD5C 0033DD5C 31004014 */  bnez       $2, .L0033DE24
    /* 23DD60 0033DD60 00000000 */   nop
    /* 23DD64 0033DD64 CC160A0C */  jal        func_00285b30
    /* 23DD68 0033DD68 00000000 */   nop
    /* 23DD6C 0033DD6C 1D014228 */  slti       $2, $2, 0x11D
    /* 23DD70 0033DD70 09004014 */  bnez       $2, .L0033DD98
    /* 23DD74 0033DD74 00000000 */   nop
    /* 23DD78 0033DD78 CC160A0C */  jal        func_00285b30
    /* 23DD7C 0033DD7C 00000000 */   nop
    /* 23DD80 0033DD80 2C014128 */  slti       $1, $2, 0x12C
    /* 23DD84 0033DD84 04002010 */  beqz       $1, .L0033DD98
    /* 23DD88 0033DD88 00000000 */   nop
    /* 23DD8C 0033DD8C 2D100000 */  daddu      $2, $0, $0
    /* 23DD90 0033DD90 25000010 */  b          .L0033DE28
    /* 23DD94 0033DD94 00000000 */   nop
  .L0033DD98:
    /* 23DD98 0033DD98 CC160A0C */  jal        func_00285b30
    /* 23DD9C 0033DD9C 00000000 */   nop
    /* 23DDA0 0033DDA0 A5014228 */  slti       $2, $2, 0x1A5
    /* 23DDA4 0033DDA4 09004014 */  bnez       $2, .L0033DDCC
    /* 23DDA8 0033DDA8 00000000 */   nop
    /* 23DDAC 0033DDAC CC160A0C */  jal        func_00285b30
    /* 23DDB0 0033DDB0 00000000 */   nop
    /* 23DDB4 0033DDB4 BD014128 */  slti       $1, $2, 0x1BD
    /* 23DDB8 0033DDB8 04002010 */  beqz       $1, .L0033DDCC
    /* 23DDBC 0033DDBC 00000000 */   nop
    /* 23DDC0 0033DDC0 2D100000 */  daddu      $2, $0, $0
    /* 23DDC4 0033DDC4 18000010 */  b          .L0033DE28
    /* 23DDC8 0033DDC8 00000000 */   nop
  .L0033DDCC:
    /* 23DDCC 0033DDCC 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 23DDD0 0033DDD0 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 23DDD4 0033DDD4 00086230 */  andi       $2, $3, 0x800
    /* 23DDD8 0033DDD8 08004010 */  beqz       $2, .L0033DDFC
    /* 23DDDC 0033DDDC 00000000 */   nop
    /* 23DDE0 0033DDE0 0000048E */  lw         $4, 0x0($16)
    /* 23DDE4 0033DDE4 01000524 */  addiu      $5, $0, 0x1
    /* 23DDE8 0033DDE8 E418040C */  jal        func_00106390
    /* 23DDEC 0033DDEC 00000000 */   nop
    /* 23DDF0 0033DDF0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 23DDF4 0033DDF4 0C000010 */  b          .L0033DE28
    /* 23DDF8 0033DDF8 00000000 */   nop
  .L0033DDFC:
    /* 23DDFC 0033DDFC 40006230 */  andi       $2, $3, 0x40
    /* 23DE00 0033DE00 08004010 */  beqz       $2, .L0033DE24
    /* 23DE04 0033DE04 00000000 */   nop
    /* 23DE08 0033DE08 0000048E */  lw         $4, 0x0($16)
    /* 23DE0C 0033DE0C 01000524 */  addiu      $5, $0, 0x1
    /* 23DE10 0033DE10 E418040C */  jal        func_00106390
    /* 23DE14 0033DE14 00000000 */   nop
    /* 23DE18 0033DE18 FFFF0224 */  addiu      $2, $0, -0x1
    /* 23DE1C 0033DE1C 02000010 */  b          .L0033DE28
    /* 23DE20 0033DE20 00000000 */   nop
  .L0033DE24:
    /* 23DE24 0033DE24 2D100000 */  daddu      $2, $0, $0
  .L0033DE28:
    /* 23DE28 0033DE28 1000BFDF */  ld         $31, 0x10($29)
    /* 23DE2C 0033DE2C 0000B07B */  lq         $16, 0x0($29)
    /* 23DE30 0033DE30 2000BD27 */  addiu      $29, $29, 0x20
    /* 23DE34 0033DE34 0800E003 */  jr         $31
    /* 23DE38 0033DE38 00000000 */   nop
    /* 23DE3C 0033DE3C 00000000 */  nop
.size func_0033dd40, 0x100

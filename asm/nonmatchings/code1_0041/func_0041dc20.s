.section .text
.set noat
.set noreorder
glabel func_0041dc20
    /* 31DC20 0041DC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 31DC24 0041DC24 04000524 */  addiu      $5, $0, 0x4
    /* 31DC28 0041DC28 0000B0FF */  sd         $16, 0x0($29)
    /* 31DC2C 0041DC2C 1000BFFF */  sd         $31, 0x10($29)
    /* 31DC30 0041DC30 2E6F100C */  jal        func_0041bcb8
    /* 31DC34 0041DC34 2D808000 */   daddu     $16, $4, $0
    /* 31DC38 0041DC38 740102AE */  sw         $2, 0x174($16)
    /* 31DC3C 0041DC3C 2D200002 */  daddu      $4, $16, $0
    /* 31DC40 0041DC40 2E6F100C */  jal        func_0041bcb8
    /* 31DC44 0041DC44 04000524 */   addiu     $5, $0, 0x4
    /* 31DC48 0041DC48 780102AE */  sw         $2, 0x178($16)
    /* 31DC4C 0041DC4C 2D200002 */  daddu      $4, $16, $0
    /* 31DC50 0041DC50 2E6F100C */  jal        func_0041bcb8
    /* 31DC54 0041DC54 04000524 */   addiu     $5, $0, 0x4
    /* 31DC58 0041DC58 7C0102AE */  sw         $2, 0x17C($16)
    /* 31DC5C 0041DC5C 2D200002 */  daddu      $4, $16, $0
    /* 31DC60 0041DC60 2E6F100C */  jal        func_0041bcb8
    /* 31DC64 0041DC64 04000524 */   addiu     $5, $0, 0x4
    /* 31DC68 0041DC68 800102AE */  sw         $2, 0x180($16)
    /* 31DC6C 0041DC6C 2D200002 */  daddu      $4, $16, $0
    /* 31DC70 0041DC70 2E6F100C */  jal        func_0041bcb8
    /* 31DC74 0041DC74 02000524 */   addiu     $5, $0, 0x2
    /* 31DC78 0041DC78 0010073C */  lui        $7, (0x10002010 >> 16)
    /* 31DC7C 0041DC7C FCFF063C */  lui        $6, (0xFFFCFFFF >> 16)
    /* 31DC80 0041DC80 1020E734 */  ori        $7, $7, (0x10002010 & 0xFFFF)
    /* 31DC84 0041DC84 FFFFC634 */  ori        $6, $6, (0xFFFCFFFF & 0xFFFF)
    /* 31DC88 0041DC88 0000E38C */  lw         $3, 0x0($7)
    /* 31DC8C 0041DC8C 00140200 */  sll        $2, $2, 16
    /* 31DC90 0041DC90 2D200002 */  daddu      $4, $16, $0
    /* 31DC94 0041DC94 02000524 */  addiu      $5, $0, 0x2
    /* 31DC98 0041DC98 24186600 */  and        $3, $3, $6
    /* 31DC9C 0041DC9C 25186200 */  or         $3, $3, $2
    /* 31DCA0 0041DCA0 2E6F100C */  jal        func_0041bcb8
    /* 31DCA4 0041DCA4 0000E3AC */   sw        $3, 0x0($7)
    /* 31DCA8 0041DCA8 2D184000 */  daddu      $3, $2, $0
    /* 31DCAC 0041DCAC E800028E */  lw         $2, 0xE8($16)
    /* 31DCB0 0041DCB0 02004014 */  bnez       $2, .L0041DCBC
    /* 31DCB4 0041DCB4 840103AE */   sw        $3, 0x184($16)
    /* 31DCB8 0041DCB8 E80003AE */  sw         $3, 0xE8($16)
  .L0041DCBC:
    /* 31DCBC 0041DCBC 2D200002 */  daddu      $4, $16, $0
    /* 31DCC0 0041DCC0 2E6F100C */  jal        func_0041bcb8
    /* 31DCC4 0041DCC4 01000524 */   addiu     $5, $0, 0x1
    /* 31DCC8 0041DCC8 880102AE */  sw         $2, 0x188($16)
    /* 31DCCC 0041DCCC 2D200002 */  daddu      $4, $16, $0
    /* 31DCD0 0041DCD0 2E6F100C */  jal        func_0041bcb8
    /* 31DCD4 0041DCD4 01000524 */   addiu     $5, $0, 0x1
    /* 31DCD8 0041DCD8 8C0102AE */  sw         $2, 0x18C($16)
    /* 31DCDC 0041DCDC 2D200002 */  daddu      $4, $16, $0
    /* 31DCE0 0041DCE0 2E6F100C */  jal        func_0041bcb8
    /* 31DCE4 0041DCE4 01000524 */   addiu     $5, $0, 0x1
    /* 31DCE8 0041DCE8 900102AE */  sw         $2, 0x190($16)
    /* 31DCEC 0041DCEC 2D200002 */  daddu      $4, $16, $0
    /* 31DCF0 0041DCF0 2E6F100C */  jal        func_0041bcb8
    /* 31DCF4 0041DCF4 01000524 */   addiu     $5, $0, 0x1
    /* 31DCF8 0041DCF8 0010063C */  lui        $6, (0x10002010 >> 16)
    /* 31DCFC 0041DCFC 1020C68C */  lw         $6, (0x10002010 & 0xFFFF)($6)
    /* 31DD00 0041DD00 BFFF033C */  lui        $3, (0xFFBFFFFF >> 16)
    /* 31DD04 0041DD04 FFFF6334 */  ori        $3, $3, (0xFFBFFFFF & 0xFFFF)
    /* 31DD08 0041DD08 80150200 */  sll        $2, $2, 22
    /* 31DD0C 0041DD0C 2430C300 */  and        $6, $6, $3
    /* 31DD10 0041DD10 2D200002 */  daddu      $4, $16, $0
    /* 31DD14 0041DD14 2530C200 */  or         $6, $6, $2
    /* 31DD18 0041DD18 01000524 */  addiu      $5, $0, 0x1
    /* 31DD1C 0041DD1C 0010013C */  lui        $1, (0x10002010 >> 16)
    /* 31DD20 0041DD20 2E6F100C */  jal        func_0041bcb8
    /* 31DD24 0041DD24 102026AC */   sw        $6, (0x10002010 & 0xFFFF)($1)
    /* 31DD28 0041DD28 0010063C */  lui        $6, (0x10002010 >> 16)
    /* 31DD2C 0041DD2C 1020C68C */  lw         $6, (0x10002010 & 0xFFFF)($6)
    /* 31DD30 0041DD30 DFFF033C */  lui        $3, (0xFFDFFFFF >> 16)
    /* 31DD34 0041DD34 FFFF6334 */  ori        $3, $3, (0xFFDFFFFF & 0xFFFF)
    /* 31DD38 0041DD38 40150200 */  sll        $2, $2, 21
    /* 31DD3C 0041DD3C 2430C300 */  and        $6, $6, $3
    /* 31DD40 0041DD40 2D200002 */  daddu      $4, $16, $0
    /* 31DD44 0041DD44 2530C200 */  or         $6, $6, $2
    /* 31DD48 0041DD48 01000524 */  addiu      $5, $0, 0x1
    /* 31DD4C 0041DD4C 0010013C */  lui        $1, (0x10002010 >> 16)
    /* 31DD50 0041DD50 2E6F100C */  jal        func_0041bcb8
    /* 31DD54 0041DD54 102026AC */   sw        $6, (0x10002010 & 0xFFFF)($1)
    /* 31DD58 0041DD58 0010063C */  lui        $6, (0x10002010 >> 16)
    /* 31DD5C 0041DD5C 1020C68C */  lw         $6, (0x10002010 & 0xFFFF)($6)
    /* 31DD60 0041DD60 EFFF033C */  lui        $3, (0xFFEFFFFF >> 16)
    /* 31DD64 0041DD64 FFFF6334 */  ori        $3, $3, (0xFFEFFFFF & 0xFFFF)
    /* 31DD68 0041DD68 00150200 */  sll        $2, $2, 20
    /* 31DD6C 0041DD6C 2430C300 */  and        $6, $6, $3
    /* 31DD70 0041DD70 2D200002 */  daddu      $4, $16, $0
    /* 31DD74 0041DD74 2530C200 */  or         $6, $6, $2
    /* 31DD78 0041DD78 01000524 */  addiu      $5, $0, 0x1
    /* 31DD7C 0041DD7C 0010013C */  lui        $1, (0x10002010 >> 16)
    /* 31DD80 0041DD80 2E6F100C */  jal        func_0041bcb8
    /* 31DD84 0041DD84 102026AC */   sw        $6, (0x10002010 & 0xFFFF)($1)
    /* 31DD88 0041DD88 940102AE */  sw         $2, 0x194($16)
    /* 31DD8C 0041DD8C 2D200002 */  daddu      $4, $16, $0
    /* 31DD90 0041DD90 2E6F100C */  jal        func_0041bcb8
    /* 31DD94 0041DD94 01000524 */   addiu     $5, $0, 0x1
    /* 31DD98 0041DD98 2D200002 */  daddu      $4, $16, $0
    /* 31DD9C 0041DD9C 2E6F100C */  jal        func_0041bcb8
    /* 31DDA0 0041DDA0 01000524 */   addiu     $5, $0, 0x1
    /* 31DDA4 0041DDA4 980102AE */  sw         $2, 0x198($16)
    /* 31DDA8 0041DDA8 2D200002 */  daddu      $4, $16, $0
    /* 31DDAC 0041DDAC 2E6F100C */  jal        func_0041bcb8
    /* 31DDB0 0041DDB0 01000524 */   addiu     $5, $0, 0x1
    /* 31DDB4 0041DDB4 0F004010 */  beqz       $2, .L0041DDF4
    /* 31DDB8 0041DDB8 2D200002 */   daddu     $4, $16, $0
    /* 31DDBC 0041DDBC 2E6F100C */  jal        func_0041bcb8
    /* 31DDC0 0041DDC0 01000524 */   addiu     $5, $0, 0x1
    /* 31DDC4 0041DDC4 2D200002 */  daddu      $4, $16, $0
    /* 31DDC8 0041DDC8 2E6F100C */  jal        func_0041bcb8
    /* 31DDCC 0041DDCC 03000524 */   addiu     $5, $0, 0x3
    /* 31DDD0 0041DDD0 2D200002 */  daddu      $4, $16, $0
    /* 31DDD4 0041DDD4 2E6F100C */  jal        func_0041bcb8
    /* 31DDD8 0041DDD8 01000524 */   addiu     $5, $0, 0x1
    /* 31DDDC 0041DDDC 2D200002 */  daddu      $4, $16, $0
    /* 31DDE0 0041DDE0 2E6F100C */  jal        func_0041bcb8
    /* 31DDE4 0041DDE4 07000524 */   addiu     $5, $0, 0x7
    /* 31DDE8 0041DDE8 2D200002 */  daddu      $4, $16, $0
    /* 31DDEC 0041DDEC 2E6F100C */  jal        func_0041bcb8
    /* 31DDF0 0041DDF0 08000524 */   addiu     $5, $0, 0x8
  .L0041DDF4:
    /* 31DDF4 0041DDF4 1000BFDF */  ld         $31, 0x10($29)
    /* 31DDF8 0041DDF8 0000B0DF */  ld         $16, 0x0($29)
    /* 31DDFC 0041DDFC 0800E003 */  jr         $31
    /* 31DE00 0041DE00 2000BD27 */   addiu     $29, $29, 0x20
    /* 31DE04 0041DE04 00000000 */  nop
.size func_0041dc20, 0x1e8

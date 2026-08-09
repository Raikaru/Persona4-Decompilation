.section .text
.set noat
.set noreorder
glabel func_004da9d8
    /* 3DA9D8 004DA9D8 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3DA9DC 004DA9DC 0000C28C */  lw         $2, 0x0($6)
    /* 3DA9E0 004DA9E0 1000B0FF */  sd         $16, 0x10($29)
    /* 3DA9E4 004DA9E4 2D80A000 */  daddu      $16, $5, $0
    /* 3DA9E8 004DA9E8 2000B2FF */  sd         $18, 0x20($29)
    /* 3DA9EC 004DA9EC 2D908000 */  daddu      $18, $4, $0
    /* 3DA9F0 004DA9F0 4000B6FF */  sd         $22, 0x40($29)
    /* 3DA9F4 004DA9F4 2DB0E000 */  daddu      $22, $7, $0
    /* 3DA9F8 004DA9F8 1800B1FF */  sd         $17, 0x18($29)
    /* 3DA9FC 004DA9FC 2800B3FF */  sd         $19, 0x28($29)
    /* 3DAA00 004DAA00 3000B4FF */  sd         $20, 0x30($29)
    /* 3DAA04 004DAA04 3800B5FF */  sd         $21, 0x38($29)
    /* 3DAA08 004DAA08 4800B7FF */  sd         $23, 0x48($29)
    /* 3DAA0C 004DAA0C 5000BEFF */  sd         $30, 0x50($29)
    /* 3DAA10 004DAA10 5800BFFF */  sd         $31, 0x58($29)
    /* 3DAA14 004DAA14 0000A6AF */  sw         $6, 0x0($29)
    /* 3DAA18 004DAA18 0400A8AF */  sw         $8, 0x4($29)
    /* 3DAA1C 004DAA1C 10001E8E */  lw         $30, 0x10($16)
    /* 3DAA20 004DAA20 05004010 */  beqz       $2, .L004DAA38
    /* 3DAA24 004DAA24 0400158E */   lw        $21, 0x4($16)
    /* 3DAA28 004DAA28 F265130C */  jal        func_004d97c8
    /* 3DAA2C 004DAA2C 02000524 */   addiu     $5, $0, 0x2
    /* 3DAA30 004DAA30 02000010 */  b          .L004DAA3C
    /* 3DAA34 004DAA34 0000C2AE */   sw        $2, 0x0($22)
  .L004DAA38:
    /* 3DAA38 004DAA38 0000C0AE */  sw         $0, 0x0($22)
  .L004DAA3C:
    /* 3DAA3C 004DAA3C 0000C28E */  lw         $2, 0x0($22)
    /* 3DAA40 004DAA40 01001324 */  addiu      $19, $0, 0x1
    /* 3DAA44 004DAA44 2A187E02 */  slt        $3, $19, $30
    /* 3DAA48 004DAA48 40100200 */  sll        $2, $2, 1
    /* 3DAA4C 004DAA4C 21105000 */  addu       $2, $2, $16
    /* 3DAA50 004DAA50 11006010 */  beqz       $3, .L004DAA98
    /* 3DAA54 004DAA54 34005184 */   lh        $17, 0x34($2)
  .L004DAA58:
    /* 3DAA58 004DAA58 0000A38F */  lw         $3, 0x0($29)
    /* 3DAA5C 004DAA5C 80801300 */  sll        $16, $19, 2
    /* 3DAA60 004DAA60 21100302 */  addu       $2, $16, $3
    /* 3DAA64 004DAA64 0000438C */  lw         $3, 0x0($2)
    /* 3DAA68 004DAA68 08006010 */  beqz       $3, .L004DAA8C
    /* 3DAA6C 004DAA6C 01007326 */   addiu     $19, $19, 0x1
    /* 3DAA70 004DAA70 2D204002 */  daddu      $4, $18, $0
    /* 3DAA74 004DAA74 F265130C */  jal        func_004d97c8
    /* 3DAA78 004DAA78 02000524 */   addiu     $5, $0, 0x2
    /* 3DAA7C 004DAA7C 21181602 */  addu       $3, $16, $22
    /* 3DAA80 004DAA80 03002432 */  andi       $4, $17, 0x3
    /* 3DAA84 004DAA84 26104400 */  xor        $2, $2, $4
    /* 3DAA88 004DAA88 000062AC */  sw         $2, 0x0($3)
  .L004DAA8C:
    /* 3DAA8C 004DAA8C 2A107E02 */  slt        $2, $19, $30
    /* 3DAA90 004DAA90 F1FF4014 */  bnez       $2, .L004DAA58
    /* 3DAA94 004DAA94 83881100 */   sra       $17, $17, 2
  .L004DAA98:
    /* 3DAA98 004DAA98 2D98C003 */  daddu      $19, $30, $0
    /* 3DAA9C 004DAA9C 2000622A */  slti       $2, $19, 0x20
    /* 3DAAA0 004DAAA0 12004010 */  beqz       $2, .L004DAAEC
    /* 3DAAA4 004DAAA4 00000000 */   nop
  .L004DAAA8:
    /* 3DAAA8 004DAAA8 0D00A05A */  blezl      $21, .L004DAAE0
    /* 3DAAAC 004DAAAC 01007326 */   addiu     $19, $19, 0x1
    /* 3DAAB0 004DAAB0 80101300 */  sll        $2, $19, 2
    /* 3DAAB4 004DAAB4 2D88A002 */  daddu      $17, $21, $0
    /* 3DAAB8 004DAAB8 21105600 */  addu       $2, $2, $22
    /* 3DAABC 004DAABC 00000000 */  nop
  .L004DAAC0:
    /* 3DAAC0 004DAAC0 FFFF3126 */  addiu      $17, $17, -0x1
    /* 3DAAC4 004DAAC4 000040AC */  sw         $0, 0x0($2)
    /* 3DAAC8 004DAAC8 00000000 */  nop
    /* 3DAACC 004DAACC 00000000 */  nop
    /* 3DAAD0 004DAAD0 00000000 */  nop
    /* 3DAAD4 004DAAD4 FAFF2016 */  bnez       $17, .L004DAAC0
    /* 3DAAD8 004DAAD8 80004224 */   addiu     $2, $2, 0x80
    /* 3DAADC 004DAADC 01007326 */  addiu      $19, $19, 0x1
  .L004DAAE0:
    /* 3DAAE0 004DAAE0 2000622A */  slti       $2, $19, 0x20
    /* 3DAAE4 004DAAE4 F0FF4014 */  bnez       $2, .L004DAAA8
    /* 3DAAE8 004DAAE8 00000000 */   nop
  .L004DAAEC:
    /* 3DAAEC 004DAAEC 4D00C01B */  blez       $30, .L004DAC24
    /* 3DAAF0 004DAAF0 2D980000 */   daddu     $19, $0, $0
    /* 3DAAF4 004DAAF4 00000000 */  nop
  .L004DAAF8:
    /* 3DAAF8 004DAAF8 4700A05A */  blezl      $21, .L004DAC18
    /* 3DAAFC 004DAAFC 01007326 */   addiu     $19, $19, 0x1
    /* 3DAB00 004DAB00 0400A48F */  lw         $4, 0x4($29)
    /* 3DAB04 004DAB04 80101300 */  sll        $2, $19, 2
    /* 3DAB08 004DAB08 3F001724 */  addiu      $23, $0, 0x3F
    /* 3DAB0C 004DAB0C 2DA04000 */  daddu      $20, $2, $0
    /* 3DAB10 004DAB10 21804400 */  addu       $16, $2, $4
    /* 3DAB14 004DAB14 2D88A002 */  daddu      $17, $21, $0
  .L004DAB18:
    /* 3DAB18 004DAB18 0000A38F */  lw         $3, 0x0($29)
    /* 3DAB1C 004DAB1C 21108302 */  addu       $2, $20, $3
    /* 3DAB20 004DAB20 0000438C */  lw         $3, 0x0($2)
    /* 3DAB24 004DAB24 34006010 */  beqz       $3, .L004DABF8
    /* 3DAB28 004DAB28 21109602 */   addu      $2, $20, $22
    /* 3DAB2C 004DAB2C 01000324 */  addiu      $3, $0, 0x1
    /* 3DAB30 004DAB30 0000448C */  lw         $4, 0x0($2)
    /* 3DAB34 004DAB34 14008350 */  beql       $4, $3, .L004DAB88
    /* 3DAB38 004DAB38 2D204002 */   daddu     $4, $18, $0
    /* 3DAB3C 004DAB3C 08008050 */  beql       $4, $0, .L004DAB60
    /* 3DAB40 004DAB40 2D204002 */   daddu     $4, $18, $0
    /* 3DAB44 004DAB44 02000224 */  addiu      $2, $0, 0x2
    /* 3DAB48 004DAB48 23008210 */  beq        $4, $2, .L004DABD8
    /* 3DAB4C 004DAB4C 03000224 */   addiu     $2, $0, 0x3
    /* 3DAB50 004DAB50 17008210 */  beq        $4, $2, .L004DABB0
    /* 3DAB54 004DAB54 2D204002 */   daddu     $4, $18, $0
    /* 3DAB58 004DAB58 2B000010 */  b          .L004DAC08
    /* 3DAB5C 004DAB5C FFFF3126 */   addiu     $17, $17, -0x1
  .L004DAB60:
    /* 3DAB60 004DAB60 F265130C */  jal        func_004d97c8
    /* 3DAB64 004DAB64 06000524 */   addiu     $5, $0, 0x6
    /* 3DAB68 004DAB68 2D204002 */  daddu      $4, $18, $0
    /* 3DAB6C 004DAB6C 000002AE */  sw         $2, 0x0($16)
    /* 3DAB70 004DAB70 F265130C */  jal        func_004d97c8
    /* 3DAB74 004DAB74 06000524 */   addiu     $5, $0, 0x6
    /* 3DAB78 004DAB78 2D204002 */  daddu      $4, $18, $0
    /* 3DAB7C 004DAB7C 800002AE */  sw         $2, 0x80($16)
    /* 3DAB80 004DAB80 07000010 */  b          .L004DABA0
    /* 3DAB84 004DAB84 06000524 */   addiu     $5, $0, 0x6
  .L004DAB88:
    /* 3DAB88 004DAB88 F265130C */  jal        func_004d97c8
    /* 3DAB8C 004DAB8C 06000524 */   addiu     $5, $0, 0x6
    /* 3DAB90 004DAB90 2D204002 */  daddu      $4, $18, $0
    /* 3DAB94 004DAB94 000002AE */  sw         $2, 0x0($16)
    /* 3DAB98 004DAB98 06000524 */  addiu      $5, $0, 0x6
    /* 3DAB9C 004DAB9C 800002AE */  sw         $2, 0x80($16)
  .L004DABA0:
    /* 3DABA0 004DABA0 F265130C */  jal        func_004d97c8
    /* 3DABA4 004DABA4 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3DABA8 004DABA8 17000010 */  b          .L004DAC08
    /* 3DABAC 004DABAC 000102AE */   sw        $2, 0x100($16)
  .L004DABB0:
    /* 3DABB0 004DABB0 F265130C */  jal        func_004d97c8
    /* 3DABB4 004DABB4 06000524 */   addiu     $5, $0, 0x6
    /* 3DABB8 004DABB8 2D204002 */  daddu      $4, $18, $0
    /* 3DABBC 004DABBC 000002AE */  sw         $2, 0x0($16)
    /* 3DABC0 004DABC0 F265130C */  jal        func_004d97c8
    /* 3DABC4 004DABC4 06000524 */   addiu     $5, $0, 0x6
    /* 3DABC8 004DABC8 800002AE */  sw         $2, 0x80($16)
    /* 3DABCC 004DABCC 0D000010 */  b          .L004DAC04
    /* 3DABD0 004DABD0 000102AE */   sw        $2, 0x100($16)
    /* 3DABD4 004DABD4 00000000 */  nop
  .L004DABD8:
    /* 3DABD8 004DABD8 2D204002 */  daddu      $4, $18, $0
    /* 3DABDC 004DABDC F265130C */  jal        func_004d97c8
    /* 3DABE0 004DABE0 06000524 */   addiu     $5, $0, 0x6
    /* 3DABE4 004DABE4 000002AE */  sw         $2, 0x0($16)
    /* 3DABE8 004DABE8 000102AE */  sw         $2, 0x100($16)
    /* 3DABEC 004DABEC 05000010 */  b          .L004DAC04
    /* 3DABF0 004DABF0 800002AE */   sw        $2, 0x80($16)
    /* 3DABF4 004DABF4 00000000 */  nop
  .L004DABF8:
    /* 3DABF8 004DABF8 000117AE */  sw         $23, 0x100($16)
    /* 3DABFC 004DABFC 800017AE */  sw         $23, 0x80($16)
    /* 3DAC00 004DAC00 000017AE */  sw         $23, 0x0($16)
  .L004DAC04:
    /* 3DAC04 004DAC04 FFFF3126 */  addiu      $17, $17, -0x1
  .L004DAC08:
    /* 3DAC08 004DAC08 80011026 */  addiu      $16, $16, 0x180
    /* 3DAC0C 004DAC0C C2FF2016 */  bnez       $17, .L004DAB18
    /* 3DAC10 004DAC10 80009426 */   addiu     $20, $20, 0x80
    /* 3DAC14 004DAC14 01007326 */  addiu      $19, $19, 0x1
  .L004DAC18:
    /* 3DAC18 004DAC18 2A107E02 */  slt        $2, $19, $30
    /* 3DAC1C 004DAC1C B6FF4014 */  bnez       $2, .L004DAAF8
    /* 3DAC20 004DAC20 00000000 */   nop
  .L004DAC24:
    /* 3DAC24 004DAC24 2D98C003 */  daddu      $19, $30, $0
    /* 3DAC28 004DAC28 2000622A */  slti       $2, $19, 0x20
    /* 3DAC2C 004DAC2C 16004050 */  beql       $2, $0, .L004DAC88
    /* 3DAC30 004DAC30 1000B0DF */   ld        $16, 0x10($29)
    /* 3DAC34 004DAC34 00000000 */  nop
  .L004DAC38:
    /* 3DAC38 004DAC38 0F00A05A */  blezl      $21, .L004DAC78
    /* 3DAC3C 004DAC3C 01007326 */   addiu     $19, $19, 0x1
    /* 3DAC40 004DAC40 0400A48F */  lw         $4, 0x4($29)
    /* 3DAC44 004DAC44 80101300 */  sll        $2, $19, 2
    /* 3DAC48 004DAC48 3F000324 */  addiu      $3, $0, 0x3F
    /* 3DAC4C 004DAC4C 2D88A002 */  daddu      $17, $21, $0
    /* 3DAC50 004DAC50 21104400 */  addu       $2, $2, $4
    /* 3DAC54 004DAC54 00000000 */  nop
  .L004DAC58:
    /* 3DAC58 004DAC58 FFFF3126 */  addiu      $17, $17, -0x1
    /* 3DAC5C 004DAC5C 000143AC */  sw         $3, 0x100($2)
    /* 3DAC60 004DAC60 800043AC */  sw         $3, 0x80($2)
    /* 3DAC64 004DAC64 000043AC */  sw         $3, 0x0($2)
    /* 3DAC68 004DAC68 00000000 */  nop
    /* 3DAC6C 004DAC6C FAFF2016 */  bnez       $17, .L004DAC58
    /* 3DAC70 004DAC70 80014224 */   addiu     $2, $2, 0x180
    /* 3DAC74 004DAC74 01007326 */  addiu      $19, $19, 0x1
  .L004DAC78:
    /* 3DAC78 004DAC78 2000622A */  slti       $2, $19, 0x20
    /* 3DAC7C 004DAC7C EEFF4014 */  bnez       $2, .L004DAC38
    /* 3DAC80 004DAC80 00000000 */   nop
    /* 3DAC84 004DAC84 1000B0DF */  ld         $16, 0x10($29)
  .L004DAC88:
    /* 3DAC88 004DAC88 1800B1DF */  ld         $17, 0x18($29)
    /* 3DAC8C 004DAC8C 2000B2DF */  ld         $18, 0x20($29)
    /* 3DAC90 004DAC90 2800B3DF */  ld         $19, 0x28($29)
    /* 3DAC94 004DAC94 3000B4DF */  ld         $20, 0x30($29)
    /* 3DAC98 004DAC98 3800B5DF */  ld         $21, 0x38($29)
    /* 3DAC9C 004DAC9C 4000B6DF */  ld         $22, 0x40($29)
    /* 3DACA0 004DACA0 4800B7DF */  ld         $23, 0x48($29)
    /* 3DACA4 004DACA4 5000BEDF */  ld         $30, 0x50($29)
    /* 3DACA8 004DACA8 5800BFDF */  ld         $31, 0x58($29)
    /* 3DACAC 004DACAC 0800E003 */  jr         $31
    /* 3DACB0 004DACB0 6000BD27 */   addiu     $29, $29, 0x60
    /* 3DACB4 004DACB4 00000000 */  nop
.size func_004da9d8, 0x2e0

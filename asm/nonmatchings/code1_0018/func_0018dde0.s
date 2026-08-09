.section .text
.set noat
.set noreorder
glabel func_0018dde0
    /* 8DDE0 0018DDE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8DDE4 0018DDE4 1000BFFF */  sd         $31, 0x10($29)
    /* 8DDE8 0018DDE8 0000B07F */  sq         $16, 0x0($29)
    /* 8DDEC 0018DDEC 3800908C */  lw         $16, 0x38($4)
    /* 8DDF0 0018DDF0 0400038E */  lw         $3, 0x4($16)
    /* 8DDF4 0018DDF4 01000224 */  addiu      $2, $0, 0x1
    /* 8DDF8 0018DDF8 04006214 */  bne        $3, $2, .L0018DE0C
    /* 8DDFC 0018DDFC 00000000 */   nop
    /* 8DE00 0018DE00 2D100000 */  daddu      $2, $0, $0
    /* 8DE04 0018DE04 44000010 */  b          .L0018DF18
    /* 8DE08 0018DE08 00000000 */   nop
  .L0018DE0C:
    /* 8DE0C 0018DE0C B8740A0C */  jal        func_0029d2e0
    /* 8DE10 0018DE10 00000000 */   nop
    /* 8DE14 0018DE14 04004018 */  blez       $2, .L0018DE28
    /* 8DE18 0018DE18 00000000 */   nop
    /* 8DE1C 0018DE1C 2D100000 */  daddu      $2, $0, $0
    /* 8DE20 0018DE20 3D000010 */  b          .L0018DF18
    /* 8DE24 0018DE24 00000000 */   nop
  .L0018DE28:
    /* 8DE28 0018DE28 0000038E */  lw         $3, 0x0($16)
    /* 8DE2C 0018DE2C 03000224 */  addiu      $2, $0, 0x3
    /* 8DE30 0018DE30 35006210 */  beq        $3, $2, .L0018DF08
    /* 8DE34 0018DE34 00000000 */   nop
    /* 8DE38 0018DE38 02000224 */  addiu      $2, $0, 0x2
    /* 8DE3C 0018DE3C 23006210 */  beq        $3, $2, .L0018DECC
    /* 8DE40 0018DE40 00000000 */   nop
    /* 8DE44 0018DE44 01000224 */  addiu      $2, $0, 0x1
    /* 8DE48 0018DE48 0A006210 */  beq        $3, $2, .L0018DE74
    /* 8DE4C 0018DE4C 00000000 */   nop
    /* 8DE50 0018DE50 03006010 */  beqz       $3, .L0018DE60
    /* 8DE54 0018DE54 00000000 */   nop
    /* 8DE58 0018DE58 2E000010 */  b          .L0018DF14
    /* 8DE5C 0018DE5C 00000000 */   nop
  .L0018DE60:
    /* 8DE60 0018DE60 9CB1828F */  lw         $2, -0x4E64($28)
    /* 8DE64 0018DE64 0C0002AE */  sw         $2, 0xC($16)
    /* 8DE68 0018DE68 0000028E */  lw         $2, 0x0($16)
    /* 8DE6C 0018DE6C 01004224 */  addiu      $2, $2, 0x1
    /* 8DE70 0018DE70 000002AE */  sw         $2, 0x0($16)
  .L0018DE74:
    /* 8DE74 0018DE74 0C00038E */  lw         $3, 0xC($16)
    /* 8DE78 0018DE78 9CB1828F */  lw         $2, -0x4E64($28)
    /* 8DE7C 0018DE7C 23184300 */  subu       $3, $2, $3
    /* 8DE80 0018DE80 0800028E */  lw         $2, 0x8($16)
    /* 8DE84 0018DE84 2B084300 */  sltu       $1, $2, $3
    /* 8DE88 0018DE88 22002010 */  beqz       $1, .L0018DF14
    /* 8DE8C 0018DE8C 00000000 */   nop
    /* 8DE90 0018DE90 78B2868F */  lw         $6, -0x4D88($28)
    /* 8DE94 0018DE94 0F000424 */  addiu      $4, $0, 0xF
    /* 8DE98 0018DE98 7CB2858F */  lw         $5, -0x4D84($28)
    /* 8DE9C 0018DE9C 2D380000 */  daddu      $7, $0, $0
    /* 8DEA0 0018DEA0 D4760A0C */  jal        func_0029db50
    /* 8DEA4 0018DEA4 00000000 */   nop
    /* 8DEA8 0018DEA8 100002AE */  sw         $2, 0x10($16)
    /* 8DEAC 0018DEAC 02000224 */  addiu      $2, $0, 0x2
    /* 8DEB0 0018DEB0 000002AE */  sw         $2, 0x0($16)
    /* 8DEB4 0018DEB4 84030224 */  addiu      $2, $0, 0x384
    /* 8DEB8 0018DEB8 080002AE */  sw         $2, 0x8($16)
    /* 8DEBC 0018DEBC 9CB1828F */  lw         $2, -0x4E64($28)
    /* 8DEC0 0018DEC0 0C0002AE */  sw         $2, 0xC($16)
    /* 8DEC4 0018DEC4 13000010 */  b          .L0018DF14
    /* 8DEC8 0018DEC8 00000000 */   nop
  .L0018DECC:
    /* 8DECC 0018DECC 1000048E */  lw         $4, 0x10($16)
    /* 8DED0 0018DED0 2449110C */  jal        func_00452490
    /* 8DED4 0018DED4 00000000 */   nop
    /* 8DED8 0018DED8 01000324 */  addiu      $3, $0, 0x1
    /* 8DEDC 0018DEDC 04004314 */  bne        $2, $3, .L0018DEF0
    /* 8DEE0 0018DEE0 00000000 */   nop
    /* 8DEE4 0018DEE4 2D100000 */  daddu      $2, $0, $0
    /* 8DEE8 0018DEE8 0B000010 */  b          .L0018DF18
    /* 8DEEC 0018DEEC 00000000 */   nop
  .L0018DEF0:
    /* 8DEF0 0018DEF0 100000AE */  sw         $0, 0x10($16)
    /* 8DEF4 0018DEF4 9CB1828F */  lw         $2, -0x4E64($28)
    /* 8DEF8 0018DEF8 0C0002AE */  sw         $2, 0xC($16)
    /* 8DEFC 0018DEFC 000003AE */  sw         $3, 0x0($16)
    /* 8DF00 0018DF00 04000010 */  b          .L0018DF14
    /* 8DF04 0018DF04 00000000 */   nop
  .L0018DF08:
    /* 8DF08 0018DF08 FFFF0224 */  addiu      $2, $0, -0x1
    /* 8DF0C 0018DF0C 02000010 */  b          .L0018DF18
    /* 8DF10 0018DF10 00000000 */   nop
  .L0018DF14:
    /* 8DF14 0018DF14 2D100000 */  daddu      $2, $0, $0
  .L0018DF18:
    /* 8DF18 0018DF18 1000BFDF */  ld         $31, 0x10($29)
    /* 8DF1C 0018DF1C 0000B07B */  lq         $16, 0x0($29)
    /* 8DF20 0018DF20 2000BD27 */  addiu      $29, $29, 0x20
    /* 8DF24 0018DF24 0800E003 */  jr         $31
    /* 8DF28 0018DF28 00000000 */   nop
    /* 8DF2C 0018DF2C 00000000 */  nop
.size func_0018dde0, 0x150

.section .text
.set noat
.set noreorder
glabel func_0050ddf8
    /* 40DDF8 0050DDF8 50FEBD27 */  addiu      $29, $29, -0x1B0
    /* 40DDFC 0050DDFC 9001B0FF */  sd         $16, 0x190($29)
    /* 40DE00 0050DE00 2D80A000 */  daddu      $16, $5, $0
    /* 40DE04 0050DE04 9801B1FF */  sd         $17, 0x198($29)
    /* 40DE08 0050DE08 A001B2FF */  sd         $18, 0x1A0($29)
    /* 40DE0C 0050DE0C A801BFFF */  sd         $31, 0x1A8($29)
    /* 40DE10 0050DE10 0A35140C */  jal        func_0050d428
    /* 40DE14 0050DE14 2D888000 */   daddu     $17, $4, $0
    /* 40DE18 0050DE18 7600043C */  lui        $4, %hi(D_0075F5B8)
    /* 40DE1C 0050DE1C 01000324 */  addiu      $3, $0, 0x1
    /* 40DE20 0050DE20 09004310 */  beq        $2, $3, .L0050DE48
    /* 40DE24 0050DE24 B8F58424 */   addiu     $4, $4, %lo(D_0075F5B8)
    /* 40DE28 0050DE28 8844140C */  jal        func_00511220
    /* 40DE2C 0050DE2C 00000000 */   nop
    /* 40DE30 0050DE30 2D200002 */  daddu      $4, $16, $0
    /* 40DE34 0050DE34 2D280000 */  daddu      $5, $0, $0
    /* 40DE38 0050DE38 72FE100C */  jal        func_0043f9c8
    /* 40DE3C 0050DE3C 18000624 */   addiu     $6, $0, 0x18
    /* 40DE40 0050DE40 23000010 */  b          .L0050DED0
    /* 40DE44 0050DE44 9001B0DF */   ld        $16, 0x190($29)
  .L0050DE48:
    /* 40DE48 0050DE48 9833140C */  jal        func_0050ce60
    /* 40DE4C 0050DE4C 2D202002 */   daddu     $4, $17, $0
    /* 40DE50 0050DE50 2D200002 */  daddu      $4, $16, $0
    /* 40DE54 0050DE54 2D904000 */  daddu      $18, $2, $0
    /* 40DE58 0050DE58 2D28A003 */  daddu      $5, $29, $0
    /* 40DE5C 0050DE5C 06004016 */  bnez       $18, .L0050DE78
    /* 40DE60 0050DE60 18000624 */   addiu     $6, $0, 0x18
    /* 40DE64 0050DE64 72FE100C */  jal        func_0043f9c8
    /* 40DE68 0050DE68 2D280000 */   daddu     $5, $0, $0
    /* 40DE6C 0050DE6C 18000010 */  b          .L0050DED0
    /* 40DE70 0050DE70 9001B0DF */   ld        $16, 0x190($29)
    /* 40DE74 0050DE74 00000000 */  nop
  .L0050DE78:
    /* 40DE78 0050DE78 6094140C */  jal        func_00525180
    /* 40DE7C 0050DE7C 2D204002 */   daddu     $4, $18, $0
    /* 40DE80 0050DE80 C033140C */  jal        func_0050cf00
    /* 40DE84 0050DE84 2D202002 */   daddu     $4, $17, $0
    /* 40DE88 0050DE88 2D202002 */  daddu      $4, $17, $0
    /* 40DE8C 0050DE8C DA33140C */  jal        func_0050cf68
    /* 40DE90 0050DE90 000002AE */   sw        $2, 0x0($16)
    /* 40DE94 0050DE94 2D202002 */  daddu      $4, $17, $0
    /* 40DE98 0050DE98 3A2B140C */  jal        func_0050ace8
    /* 40DE9C 0050DE9C 040002AE */   sw        $2, 0x4($16)
    /* 40DEA0 0050DEA0 2D202002 */  daddu      $4, $17, $0
    /* 40DEA4 0050DEA4 3437140C */  jal        func_0050dcd0
    /* 40DEA8 0050DEA8 080002AE */   sw        $2, 0x8($16)
    /* 40DEAC 0050DEAC 2D204002 */  daddu      $4, $18, $0
    /* 40DEB0 0050DEB0 2400A38F */  lw         $3, 0x24($29)
    /* 40DEB4 0050DEB4 B000A527 */  addiu      $5, $29, 0xB0
    /* 40DEB8 0050DEB8 0C0002AE */  sw         $2, 0xC($16)
    /* 40DEBC 0050DEBC 8894140C */  jal        func_00525220
    /* 40DEC0 0050DEC0 100003AE */   sw        $3, 0x10($16)
    /* 40DEC4 0050DEC4 8C01A0C7 */  lwc1       $f0, 0x18C($29)
    /* 40DEC8 0050DEC8 140000E6 */  swc1       $f0, 0x14($16)
    /* 40DECC 0050DECC 9001B0DF */  ld         $16, 0x190($29)
  .L0050DED0:
    /* 40DED0 0050DED0 9801B1DF */  ld         $17, 0x198($29)
    /* 40DED4 0050DED4 A001B2DF */  ld         $18, 0x1A0($29)
    /* 40DED8 0050DED8 A801BFDF */  ld         $31, 0x1A8($29)
    /* 40DEDC 0050DEDC 0800E003 */  jr         $31
    /* 40DEE0 0050DEE0 B001BD27 */   addiu     $29, $29, 0x1B0
    /* 40DEE4 0050DEE4 00000000 */  nop
.size func_0050ddf8, 0xf0

.section .text
.set noat
.set noreorder
glabel func_001eafb0
    /* EAFB0 001EAFB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* EAFB4 001EAFB4 2000BFFF */  sd         $31, 0x20($29)
    /* EAFB8 001EAFB8 1000B17F */  sq         $17, 0x10($29)
    /* EAFBC 001EAFBC 0000B07F */  sq         $16, 0x0($29)
    /* EAFC0 001EAFC0 2D200000 */  daddu      $4, $0, $0
    /* EAFC4 001EAFC4 00730A0C */  jal        func_0029cc00
    /* EAFC8 001EAFC8 00000000 */   nop
    /* EAFCC 001EAFCC 2D884000 */  daddu      $17, $2, $0
    /* EAFD0 001EAFD0 01000424 */  addiu      $4, $0, 0x1
    /* EAFD4 001EAFD4 00730A0C */  jal        func_0029cc00
    /* EAFD8 001EAFD8 00000000 */   nop
    /* EAFDC 001EAFDC 2D804000 */  daddu      $16, $2, $0
    /* EAFE0 001EAFE0 02000424 */  addiu      $4, $0, 0x2
    /* EAFE4 001EAFE4 54730A0C */  jal        func_0029cd50
    /* EAFE8 001EAFE8 00000000 */   nop
    /* EAFEC 001EAFEC 3000A0E7 */  swc1       $f0, 0x30($29)
    /* EAFF0 001EAFF0 03000424 */  addiu      $4, $0, 0x3
    /* EAFF4 001EAFF4 54730A0C */  jal        func_0029cd50
    /* EAFF8 001EAFF8 00000000 */   nop
    /* EAFFC 001EAFFC 3400A0E7 */  swc1       $f0, 0x34($29)
    /* EB000 001EB000 04000424 */  addiu      $4, $0, 0x4
    /* EB004 001EB004 54730A0C */  jal        func_0029cd50
    /* EB008 001EB008 00000000 */   nop
    /* EB00C 001EB00C 3800A0E7 */  swc1       $f0, 0x38($29)
    /* EB010 001EB010 2D200000 */  daddu      $4, $0, $0
    /* EB014 001EB014 04002016 */  bnez       $17, .L001EB028
    /* EB018 001EB018 00000000 */   nop
    /* EB01C 001EB01C 2D100000 */  daddu      $2, $0, $0
    /* EB020 001EB020 02000010 */  b          .L001EB02C
    /* EB024 001EB024 00000000 */   nop
  .L001EB028:
    /* EB028 001EB028 01000224 */  addiu      $2, $0, 0x1
  .L001EB02C:
    /* EB02C 001EB02C C0180200 */  sll        $3, $2, 3
    /* EB030 001EB030 ACB3828F */  lw         $2, -0x4C54($28)
    /* EB034 001EB034 21106200 */  addu       $2, $3, $2
    /* EB038 001EB038 7C01518C */  lw         $17, 0x17C($2)
    /* EB03C 001EB03C 10000010 */  b          .L001EB080
    /* EB040 001EB040 00000000 */   nop
  .L001EB044:
    /* EB044 001EB044 0C000416 */  bne        $16, $4, .L001EB078
    /* EB048 001EB048 00000000 */   nop
    /* EB04C 001EB04C 94002426 */  addiu      $4, $17, 0x94
    /* EB050 001EB050 96002526 */  addiu      $5, $17, 0x96
    /* EB054 001EB054 3000A627 */  addiu      $6, $29, 0x30
    /* EB058 001EB058 B4B1070C */  jal        func_001ec6d0
    /* EB05C 001EB05C 00000000 */   nop
    /* EB060 001EB060 2D202002 */  daddu      $4, $17, $0
    /* EB064 001EB064 3000A527 */  addiu      $5, $29, 0x30
    /* EB068 001EB068 B853060C */  jal        func_00194ee0
    /* EB06C 001EB06C 00000000 */   nop
    /* EB070 001EB070 05000010 */  b          .L001EB088
    /* EB074 001EB074 00000000 */   nop
  .L001EB078:
    /* EB078 001EB078 01008424 */  addiu      $4, $4, 0x1
    /* EB07C 001EB07C 680A318E */  lw         $17, 0xA68($17)
  .L001EB080:
    /* EB080 001EB080 F0FF2016 */  bnez       $17, .L001EB044
    /* EB084 001EB084 00000000 */   nop
  .L001EB088:
    /* EB088 001EB088 01000224 */  addiu      $2, $0, 0x1
    /* EB08C 001EB08C 2000BFDF */  ld         $31, 0x20($29)
    /* EB090 001EB090 1000B17B */  lq         $17, 0x10($29)
    /* EB094 001EB094 0000B07B */  lq         $16, 0x0($29)
    /* EB098 001EB098 4000BD27 */  addiu      $29, $29, 0x40
    /* EB09C 001EB09C 0800E003 */  jr         $31
    /* EB0A0 001EB0A0 00000000 */   nop
    /* EB0A4 001EB0A4 00000000 */  nop
    /* EB0A8 001EB0A8 00000000 */  nop
    /* EB0AC 001EB0AC 00000000 */  nop
.size func_001eafb0, 0x100

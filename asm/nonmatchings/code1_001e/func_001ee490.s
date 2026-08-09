.section .text
.set noat
.set noreorder
glabel func_001ee490
    /* EE490 001EE490 C0FFBD27 */  addiu      $29, $29, -0x40
    /* EE494 001EE494 2000BFFF */  sd         $31, 0x20($29)
    /* EE498 001EE498 1000B07F */  sq         $16, 0x10($29)
    /* EE49C 001EE49C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EE4A0 001EE4A0 2D808000 */  daddu      $16, $4, $0
    /* EE4A4 001EE4A4 9C00828C */  lw         $2, 0x9C($4)
    /* EE4A8 001EE4A8 04004230 */  andi       $2, $2, 0x4
    /* EE4AC 001EE4AC 04004014 */  bnez       $2, .L001EE4C0
    /* EE4B0 001EE4B0 00000000 */   nop
    /* EE4B4 001EE4B4 2D100000 */  daddu      $2, $0, $0
    /* EE4B8 001EE4B8 4F000010 */  b          .L001EE5F8
    /* EE4BC 001EE4BC 00000000 */   nop
  .L001EE4C0:
    /* EE4C0 001EE4C0 3000A527 */  addiu      $5, $29, 0x30
    /* EE4C4 001EE4C4 1456060C */  jal        func_00195850
    /* EE4C8 001EE4C8 00000000 */   nop
    /* EE4CC 001EE4CC 900001C6 */  lwc1       $f1, 0x90($16)
    /* EE4D0 001EE4D0 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* EE4D4 001EE4D4 020D0046 */  mul.s      $f20, $f1, $f0
    /* EE4D8 001EE4D8 D6060224 */  addiu      $2, $0, 0x6D6
    /* EE4DC 001EE4DC 00008244 */  mtc1       $2, $f0
    /* EE4E0 001EE4E0 00000000 */  nop
    /* EE4E4 001EE4E4 60008046 */  cvt.s.w    $f1, $f0
    /* EE4E8 001EE4E8 3000A0C7 */  lwc1       $f0, 0x30($29)
    /* EE4EC 001EE4EC 00080046 */  add.s      $f0, $f1, $f0
    /* EE4F0 001EE4F0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* EE4F4 001EE4F4 00000544 */  mfc1       $5, $f0
    /* EE4F8 001EE4F8 3800A0C7 */  lwc1       $f0, 0x38($29)
    /* EE4FC 001EE4FC 00080046 */  add.s      $f0, $f1, $f0
    /* EE500 001EE500 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* EE504 001EE504 00000444 */  mfc1       $4, $f0
    /* EE508 001EE508 19000324 */  addiu      $3, $0, 0x19
    /* EE50C 001EE50C 1A00A300 */  div        $0, $5, $3
    /* EE510 001EE510 12100000 */  mflo       $2
    /* EE514 001EE514 3C3C0200 */  dsll32     $7, $2, 16
    /* EE518 001EE518 3F3C0700 */  dsra32     $7, $7, 16
    /* EE51C 001EE51C 1A008370 */  div1       $0, $4, $3
    /* EE520 001EE520 12100070 */  mflo1      $2
    /* EE524 001EE524 3C340200 */  dsll32     $6, $2, 16
    /* EE528 001EE528 3F340600 */  dsra32     $6, $6, 16
    /* EE52C 001EE52C 1A00A300 */  div        $0, $5, $3
    /* EE530 001EE530 10100000 */  mfhi       $2
    /* EE534 001EE534 0D004128 */  slti       $1, $2, 0xD
    /* EE538 001EE538 04002014 */  bnez       $1, .L001EE54C
    /* EE53C 001EE53C 00000000 */   nop
    /* EE540 001EE540 0100E224 */  addiu      $2, $7, 0x1
    /* EE544 001EE544 3C3C0200 */  dsll32     $7, $2, 16
    /* EE548 001EE548 3F3C0700 */  dsra32     $7, $7, 16
  .L001EE54C:
    /* EE54C 001EE54C 19000224 */  addiu      $2, $0, 0x19
    /* EE550 001EE550 1A008200 */  div        $0, $4, $2
    /* EE554 001EE554 10100000 */  mfhi       $2
    /* EE558 001EE558 0D004128 */  slti       $1, $2, 0xD
    /* EE55C 001EE55C 04002014 */  bnez       $1, .L001EE570
    /* EE560 001EE560 00000000 */   nop
    /* EE564 001EE564 0100C224 */  addiu      $2, $6, 0x1
    /* EE568 001EE568 3C340200 */  dsll32     $6, $2, 16
    /* EE56C 001EE56C 3F340600 */  dsra32     $6, $6, 16
  .L001EE570:
    /* EE570 001EE570 3E00A227 */  addiu      $2, $29, 0x3E
    /* EE574 001EE574 02004010 */  beqz       $2, .L001EE580
    /* EE578 001EE578 00000000 */   nop
    /* EE57C 001EE57C 3E00A7A7 */  sh         $7, 0x3E($29)
  .L001EE580:
    /* EE580 001EE580 3C00A227 */  addiu      $2, $29, 0x3C
    /* EE584 001EE584 02004010 */  beqz       $2, .L001EE590
    /* EE588 001EE588 00000000 */   nop
    /* EE58C 001EE58C 3C00A6A7 */  sh         $6, 0x3C($29)
  .L001EE590:
    /* EE590 001EE590 3E00A587 */  lh         $5, 0x3E($29)
    /* EE594 001EE594 08050286 */  lh         $2, 0x508($16)
    /* EE598 001EE598 09004514 */  bne        $2, $5, .L001EE5C0
    /* EE59C 001EE59C 00000000 */   nop
    /* EE5A0 001EE5A0 0A050386 */  lh         $3, 0x50A($16)
    /* EE5A4 001EE5A4 3C00A287 */  lh         $2, 0x3C($29)
    /* EE5A8 001EE5A8 05006214 */  bne        $3, $2, .L001EE5C0
    /* EE5AC 001EE5AC 00000000 */   nop
    /* EE5B0 001EE5B0 0C0500C6 */  lwc1       $f0, 0x50C($16)
    /* EE5B4 001EE5B4 32001446 */  c.eq.s     $f0, $f20
    /* EE5B8 001EE5B8 0E000145 */  bc1t       .L001EE5F4
    /* EE5BC 001EE5BC 00000000 */   nop
  .L001EE5C0:
    /* EE5C0 001EE5C0 2D200002 */  daddu      $4, $16, $0
    /* EE5C4 001EE5C4 3C00A687 */  lh         $6, 0x3C($29)
    /* EE5C8 001EE5C8 06A30046 */  mov.s      $f12, $f20
    /* EE5CC 001EE5CC E4B1070C */  jal        func_001ec790
    /* EE5D0 001EE5D0 00000000 */   nop
    /* EE5D4 001EE5D4 3E00A287 */  lh         $2, 0x3E($29)
    /* EE5D8 001EE5D8 080502A6 */  sh         $2, 0x508($16)
    /* EE5DC 001EE5DC 3C00A287 */  lh         $2, 0x3C($29)
    /* EE5E0 001EE5E0 0A0502A6 */  sh         $2, 0x50A($16)
    /* EE5E4 001EE5E4 0C0514E6 */  swc1       $f20, 0x50C($16)
    /* EE5E8 001EE5E8 01000224 */  addiu      $2, $0, 0x1
    /* EE5EC 001EE5EC 02000010 */  b          .L001EE5F8
    /* EE5F0 001EE5F0 00000000 */   nop
  .L001EE5F4:
    /* EE5F4 001EE5F4 2D100000 */  daddu      $2, $0, $0
  .L001EE5F8:
    /* EE5F8 001EE5F8 2000BFDF */  ld         $31, 0x20($29)
    /* EE5FC 001EE5FC 1000B07B */  lq         $16, 0x10($29)
    /* EE600 001EE600 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EE604 001EE604 4000BD27 */  addiu      $29, $29, 0x40
    /* EE608 001EE608 0800E003 */  jr         $31
    /* EE60C 001EE60C 00000000 */   nop
.size func_001ee490, 0x180

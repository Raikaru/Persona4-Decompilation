.section .text
.set noat
.set noreorder
glabel func_001cb540
    /* CB540 001CB540 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CB544 001CB544 1000BFFF */  sd         $31, 0x10($29)
    /* CB548 001CB548 0000B07F */  sq         $16, 0x0($29)
    /* CB54C 001CB54C 2D808000 */  daddu      $16, $4, $0
    /* CB550 001CB550 E000848C */  lw         $4, 0xE0($4)
    /* CB554 001CB554 FCC3070C */  jal        func_001f0ff0
    /* CB558 001CB558 00000000 */   nop
    /* CB55C 001CB55C 06004010 */  beqz       $2, .L001CB578
    /* CB560 001CB560 00000000 */   nop
    /* CB564 001CB564 2D200002 */  daddu      $4, $16, $0
    /* CB568 001CB568 ACF7060C */  jal        func_001bdeb0
    /* CB56C 001CB56C 00000000 */   nop
    /* CB570 001CB570 20000010 */  b          .L001CB5F4
    /* CB574 001CB574 00000000 */   nop
  .L001CB578:
    /* CB578 001CB578 E000048E */  lw         $4, 0xE0($16)
    /* CB57C 001CB57C 1D008010 */  beqz       $4, .L001CB5F4
    /* CB580 001CB580 00000000 */   nop
    /* CB584 001CB584 D800038E */  lw         $3, 0xD8($16)
    /* CB588 001CB588 1A006014 */  bnez       $3, .L001CB5F4
    /* CB58C 001CB58C 00000000 */   nop
    /* CB590 001CB590 18008010 */  beqz       $4, .L001CB5F4
    /* CB594 001CB594 00000000 */   nop
    /* CB598 001CB598 1A008394 */  lhu        $3, 0x1A($4)
    /* CB59C 001CB59C 01006330 */  andi       $3, $3, 0x1
    /* CB5A0 001CB5A0 14006010 */  beqz       $3, .L001CB5F4
    /* CB5A4 001CB5A4 00000000 */   nop
    /* CB5A8 001CB5A8 DC00028E */  lw         $2, 0xDC($16)
    /* CB5AC 001CB5AC 07004014 */  bnez       $2, .L001CB5CC
    /* CB5B0 001CB5B0 00000000 */   nop
    /* CB5B4 001CB5B4 00608044 */  mtc1       $0, $f12
    /* CB5B8 001CB5B8 2D280000 */  daddu      $5, $0, $0
    /* CB5BC 001CB5BC 2D300000 */  daddu      $6, $0, $0
    /* CB5C0 001CB5C0 11000724 */  addiu      $7, $0, 0x11
    /* CB5C4 001CB5C4 50F3060C */  jal        func_001bcd40
    /* CB5C8 001CB5C8 00000000 */   nop
  .L001CB5CC:
    /* CB5CC 001CB5CC 2D200002 */  daddu      $4, $16, $0
    /* CB5D0 001CB5D0 2C01058E */  lw         $5, 0x12C($16)
    /* CB5D4 001CB5D4 58F1060C */  jal        func_001bc560
    /* CB5D8 001CB5D8 00000000 */   nop
    /* CB5DC 001CB5DC 05004010 */  beqz       $2, .L001CB5F4
    /* CB5E0 001CB5E0 00000000 */   nop
    /* CB5E4 001CB5E4 2C01048E */  lw         $4, 0x12C($16)
    /* CB5E8 001CB5E8 30010596 */  lhu        $5, 0x130($16)
    /* CB5EC 001CB5EC 9C77060C */  jal        func_0019de70
    /* CB5F0 001CB5F0 00000000 */   nop
  .L001CB5F4:
    /* CB5F4 001CB5F4 1000BFDF */  ld         $31, 0x10($29)
    /* CB5F8 001CB5F8 0000B07B */  lq         $16, 0x0($29)
    /* CB5FC 001CB5FC 2000BD27 */  addiu      $29, $29, 0x20
    /* CB600 001CB600 0800E003 */  jr         $31
    /* CB604 001CB604 00000000 */   nop
    /* CB608 001CB608 00000000 */  nop
    /* CB60C 001CB60C 00000000 */  nop
.size func_001cb540, 0xd0

.section .text
.set noat
.set noreorder
glabel func_001ec5e0
    /* EC5E0 001EC5E0 00008CE4 */  swc1       $f12, 0x0($4)
    /* EC5E4 001EC5E4 04008CE4 */  swc1       $f12, 0x4($4)
    /* EC5E8 001EC5E8 00008044 */  mtc1       $0, $f0
    /* EC5EC 001EC5EC 0C0080AC */  sw         $0, 0xC($4)
    /* EC5F0 001EC5F0 100080AC */  sw         $0, 0x10($4)
    /* EC5F4 001EC5F4 32000C46 */  c.eq.s     $f0, $f12
    /* EC5F8 001EC5F8 0B000145 */  bc1t       .L001EC628
    /* EC5FC 001EC5FC 00000000 */   nop
    /* EC600 001EC600 42600C46 */  mul.s      $f1, $f12, $f12
    /* EC604 001EC604 8040033C */  lui        $3, (0x40800000 >> 16)
    /* EC608 001EC608 00008344 */  mtc1       $3, $f0
    /* EC60C 001EC60C 00000000 */  nop
    /* EC610 001EC610 43080046 */  div.s      $f1, $f1, $f0
    /* EC614 001EC614 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* EC618 001EC618 00008344 */  mtc1       $3, $f0
    /* EC61C 001EC61C 00000000 */  nop
    /* EC620 001EC620 03000146 */  div.s      $f0, $f0, $f1
    /* EC624 001EC624 080080E4 */  swc1       $f0, 0x8($4)
  .L001EC628:
    /* EC628 001EC628 0800E003 */  jr         $31
    /* EC62C 001EC62C 00000000 */   nop
.size func_001ec5e0, 0x50

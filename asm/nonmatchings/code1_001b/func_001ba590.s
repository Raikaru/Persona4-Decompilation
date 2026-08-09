.section .text
.set noat
.set noreorder
glabel func_001ba590
    /* BA590 001BA590 B0FFBD27 */  addiu      $29, $29, -0x50
    /* BA594 001BA594 0000BFFF */  sd         $31, 0x0($29)
    /* BA598 001BA598 2400828C */  lw         $2, 0x24($4)
    /* BA59C 001BA59C 0A004014 */  bnez       $2, .L001BA5C8
    /* BA5A0 001BA5A0 00000000 */   nop
    /* BA5A4 001BA5A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* BA5A8 001BA5A8 0C0243C4 */  lwc1       $f3, 0x20C($2)
    /* BA5AC 001BA5AC 100242C4 */  lwc1       $f2, 0x210($2)
    /* BA5B0 001BA5B0 140241C4 */  lwc1       $f1, 0x214($2)
    /* BA5B4 001BA5B4 180240C4 */  lwc1       $f0, 0x218($2)
    /* BA5B8 001BA5B8 100083E4 */  swc1       $f3, 0x10($4)
    /* BA5BC 001BA5BC 140082E4 */  swc1       $f2, 0x14($4)
    /* BA5C0 001BA5C0 180081E4 */  swc1       $f1, 0x18($4)
    /* BA5C4 001BA5C4 1C0080E4 */  swc1       $f0, 0x1C($4)
  .L001BA5C8:
    /* BA5C8 001BA5C8 2400838C */  lw         $3, 0x24($4)
    /* BA5CC 001BA5CC 2000828C */  lw         $2, 0x20($4)
    /* BA5D0 001BA5D0 2B106200 */  sltu       $2, $3, $2
    /* BA5D4 001BA5D4 46004014 */  bnez       $2, .L001BA6F0
    /* BA5D8 001BA5D8 00000000 */   nop
    /* BA5DC 001BA5DC 040084C4 */  lwc1       $f4, 0x4($4)
    /* BA5E0 001BA5E0 00008CC4 */  lwc1       $f12, 0x0($4)
    /* BA5E4 001BA5E4 08008BC4 */  lwc1       $f11, 0x8($4)
    /* BA5E8 001BA5E8 0C0083C4 */  lwc1       $f3, 0xC($4)
    /* BA5EC 001BA5EC 1A200446 */  mula.s     $f4, $f4
    /* BA5F0 001BA5F0 1E600C46 */  madda.s    $f12, $f12
    /* BA5F4 001BA5F4 1E580B46 */  madda.s    $f11, $f11
    /* BA5F8 001BA5F8 5C180346 */  madd.s     $f1, $f3, $f3
    /* BA5FC 001BA5FC 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BA600 001BA600 00008244 */  mtc1       $2, $f0
    /* BA604 001BA604 00000000 */  nop
    /* BA608 001BA608 03000146 */  div.s      $f0, $f0, $f1
    /* BA60C 001BA60C 82600046 */  mul.s      $f2, $f12, $f0
    /* BA610 001BA610 42200046 */  mul.s      $f1, $f4, $f0
    /* BA614 001BA614 02580046 */  mul.s      $f0, $f11, $f0
    /* BA618 001BA618 82120346 */  mul.s      $f10, $f2, $f3
    /* BA61C 001BA61C 420A0346 */  mul.s      $f9, $f1, $f3
    /* BA620 001BA620 02020346 */  mul.s      $f8, $f0, $f3
    /* BA624 001BA624 C2610246 */  mul.s      $f7, $f12, $f2
    /* BA628 001BA628 82210146 */  mul.s      $f6, $f4, $f1
    /* BA62C 001BA62C 42590046 */  mul.s      $f5, $f11, $f0
    /* BA630 001BA630 02210046 */  mul.s      $f4, $f4, $f0
    /* BA634 001BA634 C2580246 */  mul.s      $f3, $f11, $f2
    /* BA638 001BA638 82600146 */  mul.s      $f2, $f12, $f1
    /* BA63C 001BA63C 00300546 */  add.s      $f0, $f6, $f5
    /* BA640 001BA640 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BA644 001BA644 00088244 */  mtc1       $2, $f1
    /* BA648 001BA648 00000000 */  nop
    /* BA64C 001BA64C 01080046 */  sub.s      $f0, $f1, $f0
    /* BA650 001BA650 1000A0E7 */  swc1       $f0, 0x10($29)
    /* BA654 001BA654 00100846 */  add.s      $f0, $f2, $f8
    /* BA658 001BA658 1400A0E7 */  swc1       $f0, 0x14($29)
    /* BA65C 001BA65C 01180946 */  sub.s      $f0, $f3, $f9
    /* BA660 001BA660 1800A0E7 */  swc1       $f0, 0x18($29)
    /* BA664 001BA664 01100846 */  sub.s      $f0, $f2, $f8
    /* BA668 001BA668 2000A0E7 */  swc1       $f0, 0x20($29)
    /* BA66C 001BA66C 00280746 */  add.s      $f0, $f5, $f7
    /* BA670 001BA670 01080046 */  sub.s      $f0, $f1, $f0
    /* BA674 001BA674 2400A0E7 */  swc1       $f0, 0x24($29)
    /* BA678 001BA678 00200A46 */  add.s      $f0, $f4, $f10
    /* BA67C 001BA67C 2800A0E7 */  swc1       $f0, 0x28($29)
    /* BA680 001BA680 00180946 */  add.s      $f0, $f3, $f9
    /* BA684 001BA684 3000A0E7 */  swc1       $f0, 0x30($29)
    /* BA688 001BA688 01200A46 */  sub.s      $f0, $f4, $f10
    /* BA68C 001BA68C 3400A0E7 */  swc1       $f0, 0x34($29)
    /* BA690 001BA690 00380646 */  add.s      $f0, $f7, $f6
    /* BA694 001BA694 01080046 */  sub.s      $f0, $f1, $f0
    /* BA698 001BA698 3800A0E7 */  swc1       $f0, 0x38($29)
    /* BA69C 001BA69C 4000A0AF */  sw         $0, 0x40($29)
    /* BA6A0 001BA6A0 4400A0AF */  sw         $0, 0x44($29)
    /* BA6A4 001BA6A4 4800A0AF */  sw         $0, 0x48($29)
    /* BA6A8 001BA6A8 03000224 */  addiu      $2, $0, 0x3
    /* BA6AC 001BA6AC 1C00A2AF */  sw         $2, 0x1C($29)
    /* BA6B0 001BA6B0 542B050C */  jal        func_0014ad50
    /* BA6B4 001BA6B4 00000000 */   nop
    /* BA6B8 001BA6B8 1000A627 */  addiu      $6, $29, 0x10
    /* BA6BC 001BA6BC 08000524 */  addiu      $5, $0, 0x8
  .L001BA6C0:
    /* BA6C0 001BA6C0 0000C48C */  lw         $4, 0x0($6)
    /* BA6C4 001BA6C4 0400C38C */  lw         $3, 0x4($6)
    /* BA6C8 001BA6C8 0800C624 */  addiu      $6, $6, 0x8
    /* BA6CC 001BA6CC FFFFA524 */  addiu      $5, $5, -0x1
    /* BA6D0 001BA6D0 000044AC */  sw         $4, 0x0($2)
    /* BA6D4 001BA6D4 040043AC */  sw         $3, 0x4($2)
    /* BA6D8 001BA6D8 08004224 */  addiu      $2, $2, 0x8
    /* BA6DC 001BA6DC F8FFA01C */  bgtz       $5, .L001BA6C0
    /* BA6E0 001BA6E0 00000000 */   nop
    /* BA6E4 001BA6E4 01000224 */  addiu      $2, $0, 0x1
    /* BA6E8 001BA6E8 04000010 */  b          .L001BA6FC
    /* BA6EC 001BA6EC 00000000 */   nop
  .L001BA6F0:
    /* BA6F0 001BA6F0 01006224 */  addiu      $2, $3, 0x1
    /* BA6F4 001BA6F4 240082AC */  sw         $2, 0x24($4)
    /* BA6F8 001BA6F8 2D100000 */  daddu      $2, $0, $0
  .L001BA6FC:
    /* BA6FC 001BA6FC 0000BFDF */  ld         $31, 0x0($29)
    /* BA700 001BA700 5000BD27 */  addiu      $29, $29, 0x50
    /* BA704 001BA704 0800E003 */  jr         $31
    /* BA708 001BA708 00000000 */   nop
    /* BA70C 001BA70C 00000000 */  nop
.size func_001ba590, 0x180

.section .text
.set noat
.set noreorder
glabel func_002ca770
    /* 1CA770 002CA770 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1CA774 002CA774 3000BFFF */  sd         $31, 0x30($29)
    /* 1CA778 002CA778 2000B27F */  sq         $18, 0x20($29)
    /* 1CA77C 002CA77C 1000B17F */  sq         $17, 0x10($29)
    /* 1CA780 002CA780 0000B07F */  sq         $16, 0x0($29)
    /* 1CA784 002CA784 2D908000 */  daddu      $18, $4, $0
    /* 1CA788 002CA788 3800908C */  lw         $16, 0x38($4)
    /* 1CA78C 002CA78C 2D880000 */  daddu      $17, $0, $0
    /* 1CA790 002CA790 08000010 */  b          .L002CA7B4
    /* 1CA794 002CA794 00000000 */   nop
  .L002CA798:
    /* 1CA798 002CA798 21100302 */  addu       $2, $16, $3
    /* 1CA79C 002CA79C 730F4480 */  lb         $4, 0xF73($2)
    /* 1CA7A0 002CA7A0 E015040C */  jal        func_00105780
    /* 1CA7A4 002CA7A4 00000000 */   nop
    /* 1CA7A8 002CA7A8 01002226 */  addiu      $2, $17, 0x1
    /* 1CA7AC 002CA7AC 3C8C0200 */  dsll32     $17, $2, 16
    /* 1CA7B0 002CA7B0 3F8C1100 */  dsra32     $17, $17, 16
  .L002CA7B4:
    /* 1CA7B4 002CA7B4 3C1C1100 */  dsll32     $3, $17, 16
    /* 1CA7B8 002CA7B8 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CA7BC 002CA7BC 09000282 */  lb         $2, 0x9($16)
    /* 1CA7C0 002CA7C0 2A106200 */  slt        $2, $3, $2
    /* 1CA7C4 002CA7C4 F4FF4014 */  bnez       $2, .L002CA798
    /* 1CA7C8 002CA7C8 00000000 */   nop
    /* 1CA7CC 002CA7CC 280F048E */  lw         $4, 0xF28($16)
    /* 1CA7D0 002CA7D0 04008010 */  beqz       $4, .L002CA7E4
    /* 1CA7D4 002CA7D4 00000000 */   nop
    /* 1CA7D8 002CA7D8 34AC110C */  jal        func_0046b0d0
    /* 1CA7DC 002CA7DC 00000000 */   nop
    /* 1CA7E0 002CA7E0 280F00AE */  sw         $0, 0xF28($16)
  .L002CA7E4:
    /* 1CA7E4 002CA7E4 2C0F048E */  lw         $4, 0xF2C($16)
    /* 1CA7E8 002CA7E8 03008010 */  beqz       $4, .L002CA7F8
    /* 1CA7EC 002CA7EC 00000000 */   nop
    /* 1CA7F0 002CA7F0 F452110C */  jal        func_00454bd0
    /* 1CA7F4 002CA7F4 00000000 */   nop
  .L002CA7F8:
    /* 1CA7F8 002CA7F8 688A0B0C */  jal        func_002e29a0
    /* 1CA7FC 002CA7FC 00000000 */   nop
    /* 1CA800 002CA800 3800448E */  lw         $4, 0x38($18)
    /* 1CA804 002CA804 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1CA808 002CA808 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1CA80C 002CA80C 09F84000 */  jalr       $2
    /* 1CA810 002CA810 00000000 */   nop
    /* 1CA814 002CA814 3000BFDF */  ld         $31, 0x30($29)
    /* 1CA818 002CA818 2000B27B */  lq         $18, 0x20($29)
    /* 1CA81C 002CA81C 1000B17B */  lq         $17, 0x10($29)
    /* 1CA820 002CA820 0000B07B */  lq         $16, 0x0($29)
    /* 1CA824 002CA824 4000BD27 */  addiu      $29, $29, 0x40
    /* 1CA828 002CA828 0800E003 */  jr         $31
    /* 1CA82C 002CA82C 00000000 */   nop
.size func_002ca770, 0xc0

.section .text
.set noat
.set noreorder
glabel func_001cd6c0
    /* CD6C0 001CD6C0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* CD6C4 001CD6C4 3000BFFF */  sd         $31, 0x30($29)
    /* CD6C8 001CD6C8 2000B27F */  sq         $18, 0x20($29)
    /* CD6CC 001CD6CC 1000B17F */  sq         $17, 0x10($29)
    /* CD6D0 001CD6D0 0000B07F */  sq         $16, 0x0($29)
    /* CD6D4 001CD6D4 2D888000 */  daddu      $17, $4, $0
    /* CD6D8 001CD6D8 2D800000 */  daddu      $16, $0, $0
    /* CD6DC 001CD6DC ACB3828F */  lw         $2, -0x4C54($28)
    /* CD6E0 001CD6E0 7C01528C */  lw         $18, 0x17C($2)
    /* CD6E4 001CD6E4 0E000010 */  b          .L001CD720
    /* CD6E8 001CD6E8 00000000 */   nop
  .L001CD6EC:
    /* CD6EC 001CD6EC 9C00428E */  lw         $2, 0x9C($18)
    /* CD6F0 001CD6F0 08004230 */  andi       $2, $2, 0x8
    /* CD6F4 001CD6F4 09004010 */  beqz       $2, .L001CD71C
    /* CD6F8 001CD6F8 00000000 */   nop
    /* CD6FC 001CD6FC 640A448E */  lw         $4, 0xA64($18)
    /* CD700 001CD700 2D280000 */  daddu      $5, $0, $0
    /* CD704 001CD704 3C0A090C */  jal        func_002428f0
    /* CD708 001CD708 00000000 */   nop
    /* CD70C 001CD70C 03004014 */  bnez       $2, .L001CD71C
    /* CD710 001CD710 00000000 */   nop
    /* CD714 001CD714 01000226 */  addiu      $2, $16, 0x1
    /* CD718 001CD718 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001CD71C:
    /* CD71C 001CD71C 680A528E */  lw         $18, 0xA68($18)
  .L001CD720:
    /* CD720 001CD720 F2FF4016 */  bnez       $18, .L001CD6EC
    /* CD724 001CD724 00000000 */   nop
    /* CD728 001CD728 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CD72C 001CD72C 04004238 */  xori       $2, $2, 0x4
    /* CD730 001CD730 2B800200 */  sltu       $16, $0, $2
    /* CD734 001CD734 2D200000 */  daddu      $4, $0, $0
    /* CD738 001CD738 14F4120C */  jal        func_004bd050
    /* CD73C 001CD73C 00000000 */   nop
    /* CD740 001CD740 01004330 */  andi       $3, $2, 0x1
    /* CD744 001CD744 00110300 */  sll        $2, $3, 4
    /* CD748 001CD748 23104300 */  subu       $2, $2, $3
    /* CD74C 001CD74C 80100200 */  sll        $2, $2, 2
    /* CD750 001CD750 21104300 */  addu       $2, $2, $3
    /* CD754 001CD754 80200200 */  sll        $4, $2, 2
    /* CD758 001CD758 00111000 */  sll        $2, $16, 4
    /* CD75C 001CD75C 23105000 */  subu       $2, $2, $16
    /* CD760 001CD760 80100200 */  sll        $2, $2, 2
    /* CD764 001CD764 21105000 */  addu       $2, $2, $16
    /* CD768 001CD768 C0180200 */  sll        $3, $2, 3
    /* CD76C 001CD76C 6000023C */  lui        $2, %hi(D_005FDE00)
    /* CD770 001CD770 00DE4224 */  addiu      $2, $2, %lo(D_005FDE00)
    /* CD774 001CD774 21104300 */  addu       $2, $2, $3
    /* CD778 001CD778 21288200 */  addu       $5, $4, $2
    /* CD77C 001CD77C 2D202002 */  daddu      $4, $17, $0
    /* CD780 001CD780 02000624 */  addiu      $6, $0, 0x2
    /* CD784 001CD784 60F7060C */  jal        func_001bdd80
    /* CD788 001CD788 00000000 */   nop
    /* CD78C 001CD78C 3000BFDF */  ld         $31, 0x30($29)
    /* CD790 001CD790 2000B27B */  lq         $18, 0x20($29)
    /* CD794 001CD794 1000B17B */  lq         $17, 0x10($29)
    /* CD798 001CD798 0000B07B */  lq         $16, 0x0($29)
    /* CD79C 001CD79C 4000BD27 */  addiu      $29, $29, 0x40
    /* CD7A0 001CD7A0 0800E003 */  jr         $31
    /* CD7A4 001CD7A4 00000000 */   nop
    /* CD7A8 001CD7A8 00000000 */  nop
    /* CD7AC 001CD7AC 00000000 */  nop
.size func_001cd6c0, 0xf0

.section .text
.set noat
.set noreorder
glabel func_004ac640
    /* 3AC640 004AC640 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AC644 004AC644 3000BFFF */  sd         $31, 0x30($29)
    /* 3AC648 004AC648 2000B27F */  sq         $18, 0x20($29)
    /* 3AC64C 004AC64C 1000B17F */  sq         $17, 0x10($29)
    /* 3AC650 004AC650 0000B07F */  sq         $16, 0x0($29)
    /* 3AC654 004AC654 2D908000 */  daddu      $18, $4, $0
    /* 3AC658 004AC658 7100043C */  lui        $4, %hi(D_007144B8)
    /* 3AC65C 004AC65C B8448424 */  addiu      $4, $4, %lo(D_007144B8)
    /* 3AC660 004AC660 71010524 */  addiu      $5, $0, 0x171
    /* 3AC664 004AC664 A43A110C */  jal        func_0044ea90
    /* 3AC668 004AC668 00000000 */   nop
    /* 3AC66C 004AC66C BC000424 */  addiu      $4, $0, 0xBC
    /* 3AC670 004AC670 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AC674 004AC674 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AC678 004AC678 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AC67C 004AC67C 09F84000 */  jalr       $2
    /* 3AC680 004AC680 00000000 */   nop
    /* 3AC684 004AC684 2D884000 */  daddu      $17, $2, $0
    /* 3AC688 004AC688 2D202002 */  daddu      $4, $17, $0
    /* 3AC68C 004AC68C 2D280000 */  daddu      $5, $0, $0
    /* 3AC690 004AC690 BC000624 */  addiu      $6, $0, 0xBC
    /* 3AC694 004AC694 72FE100C */  jal        func_0043f9c8
    /* 3AC698 004AC698 00000000 */   nop
    /* 3AC69C 004AC69C 06002016 */  bnez       $17, .L004AC6B8
    /* 3AC6A0 004AC6A0 00000000 */   nop
    /* 3AC6A4 004AC6A4 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC6A8 004AC6A8 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC6AC 004AC6AC 8A010524 */  addiu      $5, $0, 0x18A
    /* 3AC6B0 004AC6B0 CCB5110C */  jal        func_0046d730
    /* 3AC6B4 004AC6B4 00000000 */   nop
  .L004AC6B8:
    /* 3AC6B8 004AC6B8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3AC6BC 004AC6BC 0C0022AE */  sw         $2, 0xC($17)
    /* 3AC6C0 004AC6C0 7C004012 */  beqz       $18, .L004AC8B4
    /* 3AC6C4 004AC6C4 00000000 */   nop
    /* 3AC6C8 004AC6C8 2D204002 */  daddu      $4, $18, $0
    /* 3AC6CC 004AC6CC 2411120C */  jal        func_00484490
    /* 3AC6D0 004AC6D0 00000000 */   nop
    /* 3AC6D4 004AC6D4 2D804000 */  daddu      $16, $2, $0
    /* 3AC6D8 004AC6D8 06000016 */  bnez       $16, .L004AC6F4
    /* 3AC6DC 004AC6DC 00000000 */   nop
    /* 3AC6E0 004AC6E0 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC6E4 004AC6E4 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC6E8 004AC6E8 96010524 */  addiu      $5, $0, 0x196
    /* 3AC6EC 004AC6EC CCB5110C */  jal        func_0046d730
    /* 3AC6F0 004AC6F0 00000000 */   nop
  .L004AC6F4:
    /* 3AC6F4 004AC6F4 10002426 */  addiu      $4, $17, 0x10
    /* 3AC6F8 004AC6F8 2D280002 */  daddu      $5, $16, $0
    /* 3AC6FC 004AC6FC A4000624 */  addiu      $6, $0, 0xA4
    /* 3AC700 004AC700 04FE100C */  jal        func_0043f810
    /* 3AC704 004AC704 00000000 */   nop
    /* 3AC708 004AC708 2D204002 */  daddu      $4, $18, $0
    /* 3AC70C 004AC70C 3411120C */  jal        func_004844d0
    /* 3AC710 004AC710 00000000 */   nop
    /* 3AC714 004AC714 2D804000 */  daddu      $16, $2, $0
    /* 3AC718 004AC718 66000012 */  beqz       $16, .L004AC8B4
    /* 3AC71C 004AC71C 00000000 */   nop
    /* 3AC720 004AC720 1C004396 */  lhu        $3, 0x1C($18)
    /* 3AC724 004AC724 03000224 */  addiu      $2, $0, 0x3
    /* 3AC728 004AC728 06006210 */  beq        $3, $2, .L004AC744
    /* 3AC72C 004AC72C 00000000 */   nop
    /* 3AC730 004AC730 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC734 004AC734 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC738 004AC738 9D010524 */  addiu      $5, $0, 0x19D
    /* 3AC73C 004AC73C CCB5110C */  jal        func_0046d730
    /* 3AC740 004AC740 00000000 */   nop
  .L004AC744:
    /* 3AC744 004AC744 2400528E */  lw         $18, 0x24($18)
    /* 3AC748 004AC748 04000010 */  b          .L004AC75C
    /* 3AC74C 004AC74C 00000000 */   nop
  .L004AC750:
    /* 3AC750 004AC750 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3AC754 004AC754 01004224 */  addiu      $2, $2, 0x1
    /* 3AC758 004AC758 90BB82A7 */  sh         $2, -0x4470($28)
  .L004AC75C:
    /* 3AC75C 004AC75C 06000424 */  addiu      $4, $0, 0x6
    /* 3AC760 004AC760 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3AC764 004AC764 2D300000 */  daddu      $6, $0, $0
    /* 3AC768 004AC768 10DF110C */  jal        func_00477c40
    /* 3AC76C 004AC76C 00000000 */   nop
    /* 3AC770 004AC770 F7FF4014 */  bnez       $2, .L004AC750
    /* 3AC774 004AC774 00000000 */   nop
    /* 3AC778 004AC778 06000424 */  addiu      $4, $0, 0x6
    /* 3AC77C 004AC77C 90BB8597 */  lhu        $5, -0x4470($28)
    /* 3AC780 004AC780 2D300002 */  daddu      $6, $16, $0
    /* 3AC784 004AC784 2D384002 */  daddu      $7, $18, $0
    /* 3AC788 004AC788 01000824 */  addiu      $8, $0, 0x1
    /* 3AC78C 004AC78C C4DF110C */  jal        func_00477f10
    /* 3AC790 004AC790 00000000 */   nop
    /* 3AC794 004AC794 2D804000 */  daddu      $16, $2, $0
    /* 3AC798 004AC798 2D200002 */  daddu      $4, $16, $0
    /* 3AC79C 004AC79C A8E8110C */  jal        func_0047a2a0
    /* 3AC7A0 004AC7A0 00000000 */   nop
    /* 3AC7A4 004AC7A4 2D200002 */  daddu      $4, $16, $0
    /* 3AC7A8 004AC7A8 2D280000 */  daddu      $5, $0, $0
    /* 3AC7AC 004AC7AC 28E7110C */  jal        func_00479ca0
    /* 3AC7B0 004AC7B0 00000000 */   nop
    /* 3AC7B4 004AC7B4 0E004010 */  beqz       $2, .L004AC7F0
    /* 3AC7B8 004AC7B8 00000000 */   nop
    /* 3AC7BC 004AC7BC 2D200002 */  daddu      $4, $16, $0
    /* 3AC7C0 004AC7C0 2D280000 */  daddu      $5, $0, $0
    /* 3AC7C4 004AC7C4 2D300000 */  daddu      $6, $0, $0
    /* 3AC7C8 004AC7C8 2D380000 */  daddu      $7, $0, $0
    /* 3AC7CC 004AC7CC 2D400000 */  daddu      $8, $0, $0
    /* 3AC7D0 004AC7D0 50E6110C */  jal        func_00479940
    /* 3AC7D4 004AC7D4 00000000 */   nop
    /* 3AC7D8 004AC7D8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AC7DC 004AC7DC 00608244 */  mtc1       $2, $f12
    /* 3AC7E0 004AC7E0 2D200002 */  daddu      $4, $16, $0
    /* 3AC7E4 004AC7E4 2D280000 */  daddu      $5, $0, $0
    /* 3AC7E8 004AC7E8 38E8110C */  jal        func_0047a0e0
    /* 3AC7EC 004AC7EC 00000000 */   nop
  .L004AC7F0:
    /* 3AC7F0 004AC7F0 D800038E */  lw         $3, 0xD8($16)
    /* 3AC7F4 004AC7F4 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3AC7F8 004AC7F8 24106200 */  and        $2, $3, $2
    /* 3AC7FC 004AC7FC D80002AE */  sw         $2, 0xD8($16)
    /* 3AC800 004AC800 2D200002 */  daddu      $4, $16, $0
    /* 3AC804 004AC804 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3AC808 004AC808 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3AC80C 004AC80C 2D300002 */  daddu      $6, $16, $0
    /* 3AC810 004AC810 ACE3110C */  jal        func_00478eb0
    /* 3AC814 004AC814 00000000 */   nop
    /* 3AC818 004AC818 90BB8297 */  lhu        $2, -0x4470($28)
    /* 3AC81C 004AC81C 01004224 */  addiu      $2, $2, 0x1
    /* 3AC820 004AC820 90BB82A7 */  sh         $2, -0x4470($28)
    /* 3AC824 004AC824 B40030AE */  sw         $16, 0xB4($17)
    /* 3AC828 004AC828 2D200002 */  daddu      $4, $16, $0
    /* 3AC82C 004AC82C 4B00053C */  lui        $5, %hi(func_004accc0)
    /* 3AC830 004AC830 C0CCA524 */  addiu      $5, $5, %lo(func_004accc0)
    /* 3AC834 004AC834 2D302002 */  daddu      $6, $17, $0
    /* 3AC838 004AC838 A8E3110C */  jal        func_00478ea0
    /* 3AC83C 004AC83C 00000000 */   nop
    /* 3AC840 004AC840 A0002292 */  lbu        $2, 0xA0($17)
    /* 3AC844 004AC844 05004014 */  bnez       $2, .L004AC85C
    /* 3AC848 004AC848 00000000 */   nop
    /* 3AC84C 004AC84C B400248E */  lw         $4, 0xB4($17)
    /* 3AC850 004AC850 20000524 */  addiu      $5, $0, 0x20
    /* 3AC854 004AC854 34E9110C */  jal        func_0047a4d0
    /* 3AC858 004AC858 00000000 */   nop
  .L004AC85C:
    /* 3AC85C 004AC85C A400228E */  lw         $2, 0xA4($17)
    /* 3AC860 004AC860 06004010 */  beqz       $2, .L004AC87C
    /* 3AC864 004AC864 00000000 */   nop
    /* 3AC868 004AC868 B400248E */  lw         $4, 0xB4($17)
    /* 3AC86C 004AC86C D800838C */  lw         $3, 0xD8($4)
    /* 3AC870 004AC870 0400023C */  lui        $2, (0x40000 >> 16)
    /* 3AC874 004AC874 25106200 */  or         $2, $3, $2
    /* 3AC878 004AC878 D80082AC */  sw         $2, 0xD8($4)
  .L004AC87C:
    /* 3AC87C 004AC87C 7000238E */  lw         $3, 0x70($17)
    /* 3AC880 004AC880 0B006004 */  bltz       $3, .L004AC8B0
    /* 3AC884 004AC884 00000000 */   nop
    /* 3AC888 004AC888 7400228E */  lw         $2, 0x74($17)
    /* 3AC88C 004AC88C 08004004 */  bltz       $2, .L004AC8B0
    /* 3AC890 004AC890 00000000 */   nop
    /* 3AC894 004AC894 2A104300 */  slt        $2, $2, $3
    /* 3AC898 004AC898 05004014 */  bnez       $2, .L004AC8B0
    /* 3AC89C 004AC89C 00000000 */   nop
    /* 3AC8A0 004AC8A0 01000224 */  addiu      $2, $0, 0x1
    /* 3AC8A4 004AC8A4 B80022A2 */  sb         $2, 0xB8($17)
    /* 3AC8A8 004AC8A8 02000010 */  b          .L004AC8B4
    /* 3AC8AC 004AC8AC 00000000 */   nop
  .L004AC8B0:
    /* 3AC8B0 004AC8B0 B80020A2 */  sb         $0, 0xB8($17)
  .L004AC8B4:
    /* 3AC8B4 004AC8B4 2D102002 */  daddu      $2, $17, $0
    /* 3AC8B8 004AC8B8 3000BFDF */  ld         $31, 0x30($29)
    /* 3AC8BC 004AC8BC 2000B27B */  lq         $18, 0x20($29)
    /* 3AC8C0 004AC8C0 1000B17B */  lq         $17, 0x10($29)
    /* 3AC8C4 004AC8C4 0000B07B */  lq         $16, 0x0($29)
    /* 3AC8C8 004AC8C8 4000BD27 */  addiu      $29, $29, 0x40
    /* 3AC8CC 004AC8CC 0800E003 */  jr         $31
    /* 3AC8D0 004AC8D0 00000000 */   nop
    /* 3AC8D4 004AC8D4 00000000 */  nop
    /* 3AC8D8 004AC8D8 00000000 */  nop
    /* 3AC8DC 004AC8DC 00000000 */  nop
.size func_004ac640, 0x2a0

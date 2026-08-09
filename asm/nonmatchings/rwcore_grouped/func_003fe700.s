.section .text
.set noat
.set noreorder
glabel func_003fe700
    /* 2FE700 003FE700 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2FE704 003FE704 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2FE708 003FE708 3000BFFF */  sd         $31, 0x30($29)
    /* 2FE70C 003FE70C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 2FE710 003FE710 2000B17F */  sq         $17, 0x20($29)
    /* 2FE714 003FE714 25184300 */  or         $3, $2, $3
    /* 2FE718 003FE718 1000B07F */  sq         $16, 0x10($29)
    /* 2FE71C 003FE71C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2FE720 003FE720 00608340 */  mtc0       $3, $12 /* handwritten instruction */
    /* 2FE724 003FE724 0005023C */  lui        $2, (0x5000000 >> 16)
    /* 2FE728 003FE728 2D880000 */  daddu      $17, $0, $0
    /* 2FE72C 003FE72C 3C200200 */  dsll32     $4, $2, 0
    /* 2FE730 003FE730 0001023C */  lui        $2, (0x1000102 >> 16)
    /* 2FE734 003FE734 02014334 */  ori        $3, $2, (0x1000102 & 0xFFFF)
    /* 2FE738 003FE738 00F00234 */  ori        $2, $0, 0xF000
    /* 2FE73C 003FE73C 25206400 */  or         $4, $3, $4
    /* 2FE740 003FE740 38140200 */  dsll       $2, $2, 16
    /* 2FE744 003FE744 0D004334 */  ori        $3, $2, 0xD
    /* 2FE748 003FE748 8900023C */  lui        $2, %hi(D_0088C5F0)
    /* 2FE74C 003FE74C 891B8370 */  pcpyld     $3, $4, $3
    /* 2FE750 003FE750 F0C5437C */  sq         $3, %lo(D_0088C5F0)($2)
    /* 2FE754 003FE754 8900023C */  lui        $2, %hi(D_0088C6D0)
    /* 2FE758 003FE758 D0C6437C */  sq         $3, %lo(D_0088C6D0)($2)
    /* 2FE75C 003FE75C 8900023C */  lui        $2, %hi(D_0088C7B0)
    /* 2FE760 003FE760 B0C7437C */  sq         $3, %lo(D_0088C7B0)($2)
    /* 2FE764 003FE764 8900023C */  lui        $2, %hi(D_0088C890)
    /* 2FE768 003FE768 90C8437C */  sq         $3, %lo(D_0088C890)($2)
    /* 2FE76C 003FE76C 3071023C */  lui        $2, (0x71304202 >> 16)
    /* 2FE770 003FE770 01404634 */  ori        $6, $2, (0x71304001 & 0xFFFF)
    /* 2FE774 003FE774 02424234 */  ori        $2, $2, (0x71304202 & 0xFFFF)
    /* 2FE778 003FE778 3C200200 */  dsll32     $4, $2, 0
    /* 2FE77C 003FE77C 3F3F023C */  lui        $2, (0x3F3F3F3F >> 16)
    /* 2FE780 003FE780 3F3F4334 */  ori        $3, $2, (0x3F3F3F3F & 0xFFFF)
    /* 2FE784 003FE784 3C280300 */  dsll32     $5, $3, 0
    /* 2FE788 003FE788 0020023C */  lui        $2, (0x20000000 >> 16)
    /* 2FE78C 003FE78C 25284500 */  or         $5, $2, $5
    /* 2FE790 003FE790 8900033C */  lui        $3, %hi(D_0088C600)
    /* 2FE794 003FE794 892BC570 */  pcpyld     $5, $6, $5
    /* 2FE798 003FE798 00C6657C */  sq         $5, %lo(D_0088C600)($3)
    /* 2FE79C 003FE79C 8900023C */  lui        $2, %hi(D_0088C6E0)
    /* 2FE7A0 003FE7A0 8900033C */  lui        $3, %hi(D_0088C7C0)
    /* 2FE7A4 003FE7A4 E0C6457C */  sq         $5, %lo(D_0088C6E0)($2)
    /* 2FE7A8 003FE7A8 C0C7657C */  sq         $5, %lo(D_0088C7C0)($3)
    /* 2FE7AC 003FE7AC 8900023C */  lui        $2, %hi(D_0088C8A0)
    /* 2FE7B0 003FE7B0 2D180000 */  daddu      $3, $0, $0
    /* 2FE7B4 003FE7B4 A0C8457C */  sq         $5, %lo(D_0088C8A0)($2)
    /* 2FE7B8 003FE7B8 89238370 */  pcpyld     $4, $4, $3
    /* 2FE7BC 003FE7BC 8900033C */  lui        $3, %hi(D_0088C660)
    /* 2FE7C0 003FE7C0 8900023C */  lui        $2, %hi(D_0088C740)
    /* 2FE7C4 003FE7C4 60C6647C */  sq         $4, %lo(D_0088C660)($3)
    /* 2FE7C8 003FE7C8 40C7447C */  sq         $4, %lo(D_0088C740)($2)
    /* 2FE7CC 003FE7CC 8900033C */  lui        $3, %hi(D_0088C820)
    /* 2FE7D0 003FE7D0 8900023C */  lui        $2, %hi(D_0088C900)
    /* 2FE7D4 003FE7D4 20C8647C */  sq         $4, %lo(D_0088C820)($3)
    /* 2FE7D8 003FE7D8 00C9447C */  sq         $4, %lo(D_0088C900)($2)
  .L003FE7DC:
    /* 2FE7DC 003FE7DC 5F000224 */  addiu      $2, $0, 0x5F
    /* 2FE7E0 003FE7E0 23285100 */  subu       $5, $2, $17
    /* 2FE7E4 003FE7E4 0400A104 */  bgez       $5, .L003FE7F8
    /* 2FE7E8 003FE7E8 0100A230 */   andi      $2, $5, 0x1
    /* 2FE7EC 003FE7EC 02004010 */  beqz       $2, .L003FE7F8
    /* 2FE7F0 003FE7F0 00000000 */   nop
    /* 2FE7F4 003FE7F4 FEFF4224 */  addiu      $2, $2, -0x2
  .L003FE7F8:
    /* 2FE7F8 003FE7F8 3B004014 */  bnez       $2, .L003FE8E8
    /* 2FE7FC 003FE7FC 00000000 */   nop
    /* 2FE800 003FE800 2B40023C */  lui        $2, (0x402BC9EF >> 16)
    /* 2FE804 003FE804 7F43043C */  lui        $4, (0x437F0000 >> 16)
    /* 2FE808 003FE808 EFC94334 */  ori        $3, $2, (0x402BC9EF & 0xFFFF)
    /* 2FE80C 003FE80C FEFF0224 */  addiu      $2, $0, -0x2
    /* 2FE810 003FE810 00189144 */  mtc1       $17, $f3
    /* 2FE814 003FE814 2480A200 */  and        $16, $5, $2
    /* 2FE818 003FE818 8900023C */  lui        $2, %hi(D_0088C890)
    /* 2FE81C 003FE81C 00208344 */  mtc1       $3, $f4
    /* 2FE820 003FE820 90C84224 */  addiu      $2, $2, %lo(D_0088C890)
    /* 2FE824 003FE824 E0188046 */  cvt.s.w    $f3, $f3
    /* 2FE828 003FE828 21185000 */  addu       $3, $2, $16
    /* 2FE82C 003FE82C BE42023C */  lui        $2, (0x42BE0000 >> 16)
    /* 2FE830 003FE830 00008244 */  mtc1       $2, $f0
    /* 2FE834 003FE834 00108444 */  mtc1       $4, $f2
    /* 2FE838 003FE838 00000000 */  nop
    /* 2FE83C 003FE83C 031D0046 */  div.s      $f20, $f3, $f0
    /* 2FE840 003FE840 8043023C */  lui        $2, (0x43800000 >> 16)
    /* 2FE844 003FE844 00088044 */  mtc1       $0, $f1
    /* 2FE848 003FE848 00608244 */  mtc1       $2, $f12
    /* 2FE84C 003FE84C 18080246 */  adda.s     $f1, $f2
    /* 2FE850 003FE850 5D200346 */  msub.s     $f1, $f4, $f3
    /* 2FE854 003FE854 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE858 003FE858 00000244 */  mfc1       $2, $f0
    /* 2FE85C 003FE85C 46A30046 */  mov.s      $f13, $f20
    /* 2FE860 003FE860 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 2FE864 003FE864 00110200 */  sll        $2, $2, 4
    /* 2FE868 003FE868 602E110C */  jal        func_0044b980
    /* 2FE86C 003FE86C 1C0062A4 */   sh        $2, 0x1C($3)
    /* 2FE870 003FE870 7F43043C */  lui        $4, (0x437F0000 >> 16)
    /* 2FE874 003FE874 8043023C */  lui        $2, (0x43800000 >> 16)
    /* 2FE878 003FE878 00088444 */  mtc1       $4, $f1
    /* 2FE87C 003FE87C 8900033C */  lui        $3, %hi(D_0088C7B0)
    /* 2FE880 003FE880 B0C76324 */  addiu      $3, $3, %lo(D_0088C7B0)
    /* 2FE884 003FE884 03080046 */  div.s      $f0, $f1, $f0
    /* 2FE888 003FE888 21187000 */  addu       $3, $3, $16
    /* 2FE88C 003FE88C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE890 003FE890 00608244 */  mtc1       $2, $f12
    /* 2FE894 003FE894 42A31446 */  mul.s      $f13, $f20, $f20
    /* 2FE898 003FE898 00000244 */  mfc1       $2, $f0
    /* 2FE89C 003FE89C 00000000 */  nop
    /* 2FE8A0 003FE8A0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 2FE8A4 003FE8A4 00110200 */  sll        $2, $2, 4
    /* 2FE8A8 003FE8A8 602E110C */  jal        func_0044b980
    /* 2FE8AC 003FE8AC 1C0062A4 */   sh        $2, 0x1C($3)
    /* 2FE8B0 003FE8B0 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 2FE8B4 003FE8B4 8900023C */  lui        $2, %hi(D_0088C6D0)
    /* 2FE8B8 003FE8B8 00088344 */  mtc1       $3, $f1
    /* 2FE8BC 003FE8BC D0C64224 */  addiu      $2, $2, %lo(D_0088C6D0)
    /* 2FE8C0 003FE8C0 21105000 */  addu       $2, $2, $16
    /* 2FE8C4 003FE8C4 03080046 */  div.s      $f0, $f1, $f0
    /* 2FE8C8 003FE8C8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE8CC 003FE8CC 00000344 */  mfc1       $3, $f0
    /* 2FE8D0 003FE8D0 00000000 */  nop
    /* 2FE8D4 003FE8D4 FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 2FE8D8 003FE8D8 00190300 */  sll        $3, $3, 4
    /* 2FE8DC 003FE8DC 3A000010 */  b          .L003FE9C8
    /* 2FE8E0 003FE8E0 1C0043A4 */   sh        $3, 0x1C($2)
    /* 2FE8E4 003FE8E4 00000000 */  nop
  .L003FE8E8:
    /* 2FE8E8 003FE8E8 2B40023C */  lui        $2, (0x402BC9EF >> 16)
    /* 2FE8EC 003FE8EC EFC94234 */  ori        $2, $2, (0x402BC9EF & 0xFFFF)
    /* 2FE8F0 003FE8F0 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 2FE8F4 003FE8F4 00188244 */  mtc1       $2, $f3
    /* 2FE8F8 003FE8F8 00109144 */  mtc1       $17, $f2
    /* 2FE8FC 003FE8FC FEFF0224 */  addiu      $2, $0, -0x2
    /* 2FE900 003FE900 2480A200 */  and        $16, $5, $2
    /* 2FE904 003FE904 8900023C */  lui        $2, %hi(D_0088C890)
    /* 2FE908 003FE908 00088344 */  mtc1       $3, $f1
    /* 2FE90C 003FE90C 90C84224 */  addiu      $2, $2, %lo(D_0088C890)
    /* 2FE910 003FE910 A0108046 */  cvt.s.w    $f2, $f2
    /* 2FE914 003FE914 21185000 */  addu       $3, $2, $16
    /* 2FE918 003FE918 BE42023C */  lui        $2, (0x42BE0000 >> 16)
    /* 2FE91C 003FE91C 00008244 */  mtc1       $2, $f0
    /* 2FE920 003FE920 00000000 */  nop
    /* 2FE924 003FE924 03150046 */  div.s      $f20, $f2, $f0
    /* 2FE928 003FE928 8043023C */  lui        $2, (0x43800000 >> 16)
    /* 2FE92C 003FE92C 00008044 */  mtc1       $0, $f0
    /* 2FE930 003FE930 00608244 */  mtc1       $2, $f12
    /* 2FE934 003FE934 18000146 */  adda.s     $f0, $f1
    /* 2FE938 003FE938 1D180246 */  msub.s     $f0, $f3, $f2
    /* 2FE93C 003FE93C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE940 003FE940 00000244 */  mfc1       $2, $f0
    /* 2FE944 003FE944 46A30046 */  mov.s      $f13, $f20
    /* 2FE948 003FE948 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 2FE94C 003FE94C 00110200 */  sll        $2, $2, 4
    /* 2FE950 003FE950 602E110C */  jal        func_0044b980
    /* 2FE954 003FE954 800062A4 */   sh        $2, 0x80($3)
    /* 2FE958 003FE958 7F43043C */  lui        $4, (0x437F0000 >> 16)
    /* 2FE95C 003FE95C 8043023C */  lui        $2, (0x43800000 >> 16)
    /* 2FE960 003FE960 00088444 */  mtc1       $4, $f1
    /* 2FE964 003FE964 8900033C */  lui        $3, %hi(D_0088C7B0)
    /* 2FE968 003FE968 B0C76324 */  addiu      $3, $3, %lo(D_0088C7B0)
    /* 2FE96C 003FE96C 03080046 */  div.s      $f0, $f1, $f0
    /* 2FE970 003FE970 21187000 */  addu       $3, $3, $16
    /* 2FE974 003FE974 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE978 003FE978 00608244 */  mtc1       $2, $f12
    /* 2FE97C 003FE97C 42A31446 */  mul.s      $f13, $f20, $f20
    /* 2FE980 003FE980 00000244 */  mfc1       $2, $f0
    /* 2FE984 003FE984 00000000 */  nop
    /* 2FE988 003FE988 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 2FE98C 003FE98C 00110200 */  sll        $2, $2, 4
    /* 2FE990 003FE990 602E110C */  jal        func_0044b980
    /* 2FE994 003FE994 800062A4 */   sh        $2, 0x80($3)
    /* 2FE998 003FE998 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 2FE99C 003FE99C 8900023C */  lui        $2, %hi(D_0088C6D0)
    /* 2FE9A0 003FE9A0 00088344 */  mtc1       $3, $f1
    /* 2FE9A4 003FE9A4 D0C64224 */  addiu      $2, $2, %lo(D_0088C6D0)
    /* 2FE9A8 003FE9A8 21105000 */  addu       $2, $2, $16
    /* 2FE9AC 003FE9AC 03080046 */  div.s      $f0, $f1, $f0
    /* 2FE9B0 003FE9B0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2FE9B4 003FE9B4 00000344 */  mfc1       $3, $f0
    /* 2FE9B8 003FE9B8 00000000 */  nop
    /* 2FE9BC 003FE9BC FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 2FE9C0 003FE9C0 00190300 */  sll        $3, $3, 4
    /* 2FE9C4 003FE9C4 800043A4 */  sh         $3, 0x80($2)
  .L003FE9C8:
    /* 2FE9C8 003FE9C8 01003126 */  addiu      $17, $17, 0x1
    /* 2FE9CC 003FE9CC 6000222A */  slti       $2, $17, 0x60
    /* 2FE9D0 003FE9D0 82FF4014 */  bnez       $2, .L003FE7DC
    /* 2FE9D4 003FE9D4 00000000 */   nop
    /* 2FE9D8 003FE9D8 8900023C */  lui        $2, %hi(D_0088C970)
    /* 2FE9DC 003FE9DC 8900043C */  lui        $4, %hi(D_0088C890)
    /* 2FE9E0 003FE9E0 70C94224 */  addiu      $2, $2, %lo(D_0088C970)
    /* 2FE9E4 003FE9E4 90C88424 */  addiu      $4, $4, %lo(D_0088C890)
    /* 2FE9E8 003FE9E8 3688100C */  jal        func_004220d8
    /* 2FE9EC 003FE9EC 7F004524 */   addiu     $5, $2, 0x7F
    /* 2FE9F0 003FE9F0 8900023C */  lui        $2, %hi(D_0088C890)
    /* 2FE9F4 003FE9F4 8900043C */  lui        $4, %hi(D_0088C7B0)
    /* 2FE9F8 003FE9F8 90C84224 */  addiu      $2, $2, %lo(D_0088C890)
    /* 2FE9FC 003FE9FC B0C78424 */  addiu      $4, $4, %lo(D_0088C7B0)
    /* 2FEA00 003FEA00 3688100C */  jal        func_004220d8
    /* 2FEA04 003FEA04 7F004524 */   addiu     $5, $2, 0x7F
    /* 2FEA08 003FEA08 8900023C */  lui        $2, %hi(D_0088C7B0)
    /* 2FEA0C 003FEA0C 8900043C */  lui        $4, %hi(D_0088C6D0)
    /* 2FEA10 003FEA10 B0C74224 */  addiu      $2, $2, %lo(D_0088C7B0)
    /* 2FEA14 003FEA14 D0C68424 */  addiu      $4, $4, %lo(D_0088C6D0)
    /* 2FEA18 003FEA18 3688100C */  jal        func_004220d8
    /* 2FEA1C 003FEA1C 7F004524 */   addiu     $5, $2, 0x7F
    /* 2FEA20 003FEA20 8900023C */  lui        $2, %hi(D_0088C6D0)
    /* 2FEA24 003FEA24 8900043C */  lui        $4, %hi(D_0088C5F0)
    /* 2FEA28 003FEA28 D0C64224 */  addiu      $2, $2, %lo(D_0088C6D0)
    /* 2FEA2C 003FEA2C F0C58424 */  addiu      $4, $4, %lo(D_0088C5F0)
    /* 2FEA30 003FEA30 3688100C */  jal        func_004220d8
    /* 2FEA34 003FEA34 7F004524 */   addiu     $5, $2, 0x7F
    /* 2FEA38 003FEA38 8900023C */  lui        $2, %hi(D_0088C890)
    /* 2FEA3C 003FEA3C 90C84224 */  addiu      $2, $2, %lo(D_0088C890)
    /* 2FEA40 003FEA40 64B982AF */  sw         $2, -0x469C($28)
    /* 2FEA44 003FEA44 59000224 */  addiu      $2, $0, 0x59
    /* 2FEA48 003FEA48 60B982AF */  sw         $2, -0x46A0($28)
    /* 2FEA4C 003FEA4C 7100023C */  lui        $2, %hi(D_0070C0A0)
    /* 2FEA50 003FEA50 A0C0438C */  lw         $3, %lo(D_0070C0A0)($2)
    /* 2FEA54 003FEA54 20000224 */  addiu      $2, $0, 0x20
    /* 2FEA58 003FEA58 04006214 */  bne        $3, $2, .L003FEA6C
    /* 2FEA5C 003FEA5C 58B980AF */   sw        $0, -0x46A8($28)
    /* 2FEA60 003FEA60 00050224 */  addiu      $2, $0, 0x500
    /* 2FEA64 003FEA64 03000010 */  b          .L003FEA74
    /* 2FEA68 003FEA68 5CB982AF */   sw        $2, -0x46A4($28)
  .L003FEA6C:
    /* 2FEA6C 003FEA6C 00010224 */  addiu      $2, $0, 0x100
    /* 2FEA70 003FEA70 5CB982AF */  sw         $2, -0x46A4($28)
  .L003FEA74:
    /* 2FEA74 003FEA74 3000BFDF */  ld         $31, 0x30($29)
    /* 2FEA78 003FEA78 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2FEA7C 003FEA7C 2000B17B */  lq         $17, 0x20($29)
    /* 2FEA80 003FEA80 01000224 */  addiu      $2, $0, 0x1
    /* 2FEA84 003FEA84 1000B07B */  lq         $16, 0x10($29)
    /* 2FEA88 003FEA88 0800E003 */  jr         $31
    /* 2FEA8C 003FEA8C 4000BD27 */   addiu     $29, $29, 0x40
.size func_003fe700, 0x390

.section .text
.set noat
.set noreorder
glabel func_0042b6c0
    /* 32B6C0 0042B6C0 89001A3C */  lui        $26, %hi(D_00892400) /* handwritten instruction */
    /* 32B6C4 0042B6C4 00245A27 */  addiu      $26, $26, %lo(D_00892400) /* handwritten instruction */
    /* 32B6C8 0042B6C8 1000417F */  sq         $1, 0x10($26) /* handwritten instruction */
    /* 32B6CC 0042B6CC 2000427F */  sq         $2, 0x20($26) /* handwritten instruction */
    /* 32B6D0 0042B6D0 3000437F */  sq         $3, 0x30($26) /* handwritten instruction */
    /* 32B6D4 0042B6D4 4000447F */  sq         $4, 0x40($26) /* handwritten instruction */
    /* 32B6D8 0042B6D8 5000457F */  sq         $5, 0x50($26) /* handwritten instruction */
    /* 32B6DC 0042B6DC 6000467F */  sq         $6, 0x60($26) /* handwritten instruction */
    /* 32B6E0 0042B6E0 7000477F */  sq         $7, 0x70($26) /* handwritten instruction */
    /* 32B6E4 0042B6E4 8000487F */  sq         $8, 0x80($26) /* handwritten instruction */
    /* 32B6E8 0042B6E8 9000497F */  sq         $9, 0x90($26) /* handwritten instruction */
    /* 32B6EC 0042B6EC A0004A7F */  sq         $10, 0xA0($26) /* handwritten instruction */
    /* 32B6F0 0042B6F0 B0004B7F */  sq         $11, 0xB0($26) /* handwritten instruction */
    /* 32B6F4 0042B6F4 C0004C7F */  sq         $12, 0xC0($26) /* handwritten instruction */
    /* 32B6F8 0042B6F8 D0004D7F */  sq         $13, 0xD0($26) /* handwritten instruction */
    /* 32B6FC 0042B6FC E0004E7F */  sq         $14, 0xE0($26) /* handwritten instruction */
    /* 32B700 0042B700 F0004F7F */  sq         $15, 0xF0($26) /* handwritten instruction */
    /* 32B704 0042B704 0001507F */  sq         $16, 0x100($26) /* handwritten instruction */
    /* 32B708 0042B708 1001517F */  sq         $17, 0x110($26) /* handwritten instruction */
    /* 32B70C 0042B70C 2001527F */  sq         $18, 0x120($26) /* handwritten instruction */
    /* 32B710 0042B710 3001537F */  sq         $19, 0x130($26) /* handwritten instruction */
    /* 32B714 0042B714 4001547F */  sq         $20, 0x140($26) /* handwritten instruction */
    /* 32B718 0042B718 5001557F */  sq         $21, 0x150($26) /* handwritten instruction */
    /* 32B71C 0042B71C 6001567F */  sq         $22, 0x160($26) /* handwritten instruction */
    /* 32B720 0042B720 7001577F */  sq         $23, 0x170($26) /* handwritten instruction */
    /* 32B724 0042B724 8001587F */  sq         $24, 0x180($26) /* handwritten instruction */
    /* 32B728 0042B728 9001597F */  sq         $25, 0x190($26) /* handwritten instruction */
    /* 32B72C 0042B72C C0015C7F */  sq         $28, 0x1C0($26) /* handwritten instruction */
    /* 32B730 0042B730 D0015D7F */  sq         $29, 0x1D0($26) /* handwritten instruction */
    /* 32B734 0042B734 E0015E7F */  sq         $30, 0x1E0($26) /* handwritten instruction */
    /* 32B738 0042B738 F0015F7F */  sq         $31, 0x1F0($26) /* handwritten instruction */
    /* 32B73C 0042B73C 10100000 */  mfhi       $2
    /* 32B740 0042B740 8900013C */  lui        $1, %hi(D_00892600)
    /* 32B744 0042B744 002622FC */  sd         $2, %lo(D_00892600)($1)
    /* 32B748 0042B748 10100070 */  mfhi1      $2
    /* 32B74C 0042B74C 8900013C */  lui        $1, %hi(D_00892608)
    /* 32B750 0042B750 082622FC */  sd         $2, %lo(D_00892608)($1)
    /* 32B754 0042B754 12100000 */  mflo       $2
    /* 32B758 0042B758 8900013C */  lui        $1, %hi(D_00892610)
    /* 32B75C 0042B75C 102622FC */  sd         $2, %lo(D_00892610)($1)
    /* 32B760 0042B760 12100070 */  mflo1      $2
    /* 32B764 0042B764 8900013C */  lui        $1, %hi(D_00892618)
    /* 32B768 0042B768 182622FC */  sd         $2, %lo(D_00892618)($1)
    /* 32B76C 0042B76C 28100000 */  mfsa       $2
    /* 32B770 0042B770 8900013C */  lui        $1, %hi(D_00892620)
    /* 32B774 0042B774 202622FC */  sd         $2, %lo(D_00892620)($1)
    /* 32B778 0042B778 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 32B77C 0042B77C 00680540 */  mfc0       $5, $13 /* handwritten instruction */
    /* 32B780 0042B780 00700640 */  mfc0       $6, $14 /* handwritten instruction */
    /* 32B784 0042B784 00400740 */  mfc0       $7, $8 /* handwritten instruction */
    /* 32B788 0042B788 8900083C */  lui        $8, %hi(D_00892400)
    /* 32B78C 0042B78C 00240825 */  addiu      $8, $8, %lo(D_00892400)
    /* 32B790 0042B790 8900013C */  lui        $1, %hi(D_00892628)
    /* 32B794 0042B794 282626AC */  sw         $6, %lo(D_00892628)($1)
    /* 32B798 0042B798 4300013C */  lui        $1, %hi(D_0042B7C0)
    /* 32B79C 0042B79C C0B72124 */  addiu      $1, $1, %lo(D_0042B7C0)
    /* 32B7A0 0042B7A0 00708140 */  mtc0       $1, $14 /* handwritten instruction */
    /* 32B7A4 0042B7A4 0F040000 */  sync.p
    /* 32B7A8 0042B7A8 00600140 */  mfc0       $1, $12 /* handwritten instruction */
    /* 32B7AC 0042B7AC FEFF0224 */  addiu      $2, $0, -0x2
    /* 32B7B0 0042B7B0 24082200 */  and        $1, $1, $2
    /* 32B7B4 0042B7B4 00608140 */  mtc0       $1, $12 /* handwritten instruction */
    /* 32B7B8 0042B7B8 0F040000 */  sync.p
    /* 32B7BC 0042B7BC 18000042 */  eret /* handwritten instruction */
  alabel D_0042B7C0
    /* 32B7C0 0042B7C0 7100013C */  lui        $1, %hi(D_0070C9D8)
    /* 32B7C4 0042B7C4 D8C9218C */  lw         $1, %lo(D_0070C9D8)($1)
    /* 32B7C8 0042B7C8 89001D3C */  lui        $29, %hi(D_00892400)
    /* 32B7CC 0042B7CC 09F82000 */  jalr       $1
    /* 32B7D0 0042B7D0 0024BD27 */   addiu     $29, $29, %lo(D_00892400)
    /* 32B7D4 0042B7D4 ACFF0324 */  addiu      $3, $0, -0x54
    /* 32B7D8 0042B7D8 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B7DC 0042B7DC 00000000 */  nop
    /* 32B7E0 0042B7E0 00000000 */  nop
    /* 32B7E4 0042B7E4 00000000 */  nop
    /* 32B7E8 0042B7E8 00000000 */  nop
    /* 32B7EC 0042B7EC 00000000 */  nop
    /* 32B7F0 0042B7F0 00000000 */  nop
    /* 32B7F4 0042B7F4 00000000 */  nop
    /* 32B7F8 0042B7F8 00000000 */  nop
    /* 32B7FC 0042B7FC 00000000 */  nop
    /* 32B800 0042B800 00600140 */  mfc0       $1, $12 /* handwritten instruction */
    /* 32B804 0042B804 E4FF1A24 */  addiu      $26, $0, -0x1C /* handwritten instruction */
    /* 32B808 0042B808 24083A00 */  and        $1, $1, $26
    /* 32B80C 0042B80C 00608140 */  mtc0       $1, $12 /* handwritten instruction */
    /* 32B810 0042B810 0F040000 */  sync.p
    /* 32B814 0042B814 8900023C */  lui        $2, %hi(D_00892628)
    /* 32B818 0042B818 2826428C */  lw         $2, %lo(D_00892628)($2)
    /* 32B81C 0042B81C 00708240 */  mtc0       $2, $14 /* handwritten instruction */
    /* 32B820 0042B820 0F040000 */  sync.p
    /* 32B824 0042B824 8900023C */  lui        $2, %hi(D_00892600)
    /* 32B828 0042B828 002642DC */  ld         $2, %lo(D_00892600)($2)
    /* 32B82C 0042B82C 11004000 */  mthi       $2
    /* 32B830 0042B830 8900023C */  lui        $2, %hi(D_00892608)
    /* 32B834 0042B834 082642DC */  ld         $2, %lo(D_00892608)($2)
    /* 32B838 0042B838 11004070 */  mthi1      $2
    /* 32B83C 0042B83C 8900023C */  lui        $2, %hi(D_00892610)
    /* 32B840 0042B840 102642DC */  ld         $2, %lo(D_00892610)($2)
    /* 32B844 0042B844 13004000 */  mtlo       $2
    /* 32B848 0042B848 8900023C */  lui        $2, %hi(D_00892618)
    /* 32B84C 0042B84C 182642DC */  ld         $2, %lo(D_00892618)($2)
    /* 32B850 0042B850 13004070 */  mtlo1      $2
    /* 32B854 0042B854 8900023C */  lui        $2, %hi(D_00892620)
    /* 32B858 0042B858 202642DC */  ld         $2, %lo(D_00892620)($2)
    /* 32B85C 0042B85C 29004000 */  mtsa       $2
    /* 32B860 0042B860 0F040000 */  sync.p
    /* 32B864 0042B864 89001A3C */  lui        $26, %hi(D_00892400) /* handwritten instruction */
    /* 32B868 0042B868 00245A27 */  addiu      $26, $26, %lo(D_00892400) /* handwritten instruction */
    /* 32B86C 0042B86C 1000417B */  lq         $1, 0x10($26) /* handwritten instruction */
    /* 32B870 0042B870 2000427B */  lq         $2, 0x20($26) /* handwritten instruction */
    /* 32B874 0042B874 3000437B */  lq         $3, 0x30($26) /* handwritten instruction */
    /* 32B878 0042B878 4000447B */  lq         $4, 0x40($26) /* handwritten instruction */
    /* 32B87C 0042B87C 5000457B */  lq         $5, 0x50($26) /* handwritten instruction */
    /* 32B880 0042B880 6000467B */  lq         $6, 0x60($26) /* handwritten instruction */
    /* 32B884 0042B884 7000477B */  lq         $7, 0x70($26) /* handwritten instruction */
    /* 32B888 0042B888 8000487B */  lq         $8, 0x80($26) /* handwritten instruction */
    /* 32B88C 0042B88C 9000497B */  lq         $9, 0x90($26) /* handwritten instruction */
    /* 32B890 0042B890 A0004A7B */  lq         $10, 0xA0($26) /* handwritten instruction */
    /* 32B894 0042B894 B0004B7B */  lq         $11, 0xB0($26) /* handwritten instruction */
    /* 32B898 0042B898 C0004C7B */  lq         $12, 0xC0($26) /* handwritten instruction */
    /* 32B89C 0042B89C D0004D7B */  lq         $13, 0xD0($26) /* handwritten instruction */
    /* 32B8A0 0042B8A0 E0004E7B */  lq         $14, 0xE0($26) /* handwritten instruction */
    /* 32B8A4 0042B8A4 F0004F7B */  lq         $15, 0xF0($26) /* handwritten instruction */
    /* 32B8A8 0042B8A8 0001507B */  lq         $16, 0x100($26) /* handwritten instruction */
    /* 32B8AC 0042B8AC 1001517B */  lq         $17, 0x110($26) /* handwritten instruction */
    /* 32B8B0 0042B8B0 2001527B */  lq         $18, 0x120($26) /* handwritten instruction */
    /* 32B8B4 0042B8B4 3001537B */  lq         $19, 0x130($26) /* handwritten instruction */
    /* 32B8B8 0042B8B8 4001547B */  lq         $20, 0x140($26) /* handwritten instruction */
    /* 32B8BC 0042B8BC 5001557B */  lq         $21, 0x150($26) /* handwritten instruction */
    /* 32B8C0 0042B8C0 6001567B */  lq         $22, 0x160($26) /* handwritten instruction */
    /* 32B8C4 0042B8C4 7001577B */  lq         $23, 0x170($26) /* handwritten instruction */
    /* 32B8C8 0042B8C8 8001587B */  lq         $24, 0x180($26) /* handwritten instruction */
    /* 32B8CC 0042B8CC 9001597B */  lq         $25, 0x190($26) /* handwritten instruction */
    /* 32B8D0 0042B8D0 C0015C7B */  lq         $28, 0x1C0($26) /* handwritten instruction */
    /* 32B8D4 0042B8D4 D0015D7B */  lq         $29, 0x1D0($26) /* handwritten instruction */
    /* 32B8D8 0042B8D8 E0015E7B */  lq         $30, 0x1E0($26) /* handwritten instruction */
    /* 32B8DC 0042B8DC F0015F7B */  lq         $31, 0x1F0($26) /* handwritten instruction */
    /* 32B8E0 0042B8E0 00601A40 */  mfc0       $26, $12 /* handwritten instruction */
    /* 32B8E4 0042B8E4 13005A37 */  ori        $26, $26, 0x13 /* handwritten instruction */
    /* 32B8E8 0042B8E8 00609A40 */  mtc0       $26, $12 /* handwritten instruction */
    /* 32B8EC 0042B8EC 0F040000 */  sync.p
    /* 32B8F0 0042B8F0 18000042 */  eret /* handwritten instruction */
    /* 32B8F4 0042B8F4 00000000 */  nop
    /* 32B8F8 0042B8F8 00000000 */  nop
    /* 32B8FC 0042B8FC 00000000 */  nop
  alabel D_0042B900
    /* 32B900 0042B900 89001A3C */  lui        $26, %hi(D_00892400) /* handwritten instruction */
    /* 32B904 0042B904 00245A27 */  addiu      $26, $26, %lo(D_00892400) /* handwritten instruction */
    /* 32B908 0042B908 1000417F */  sq         $1, 0x10($26) /* handwritten instruction */
    /* 32B90C 0042B90C 2000427F */  sq         $2, 0x20($26) /* handwritten instruction */
    /* 32B910 0042B910 3000437F */  sq         $3, 0x30($26) /* handwritten instruction */
    /* 32B914 0042B914 4000447F */  sq         $4, 0x40($26) /* handwritten instruction */
    /* 32B918 0042B918 5000457F */  sq         $5, 0x50($26) /* handwritten instruction */
    /* 32B91C 0042B91C 6000467F */  sq         $6, 0x60($26) /* handwritten instruction */
    /* 32B920 0042B920 7000477F */  sq         $7, 0x70($26) /* handwritten instruction */
    /* 32B924 0042B924 8000487F */  sq         $8, 0x80($26) /* handwritten instruction */
    /* 32B928 0042B928 9000497F */  sq         $9, 0x90($26) /* handwritten instruction */
    /* 32B92C 0042B92C A0004A7F */  sq         $10, 0xA0($26) /* handwritten instruction */
    /* 32B930 0042B930 B0004B7F */  sq         $11, 0xB0($26) /* handwritten instruction */
    /* 32B934 0042B934 C0004C7F */  sq         $12, 0xC0($26) /* handwritten instruction */
    /* 32B938 0042B938 D0004D7F */  sq         $13, 0xD0($26) /* handwritten instruction */
    /* 32B93C 0042B93C E0004E7F */  sq         $14, 0xE0($26) /* handwritten instruction */
    /* 32B940 0042B940 F0004F7F */  sq         $15, 0xF0($26) /* handwritten instruction */
    /* 32B944 0042B944 0001507F */  sq         $16, 0x100($26) /* handwritten instruction */
    /* 32B948 0042B948 1001517F */  sq         $17, 0x110($26) /* handwritten instruction */
    /* 32B94C 0042B94C 2001527F */  sq         $18, 0x120($26) /* handwritten instruction */
    /* 32B950 0042B950 3001537F */  sq         $19, 0x130($26) /* handwritten instruction */
    /* 32B954 0042B954 4001547F */  sq         $20, 0x140($26) /* handwritten instruction */
    /* 32B958 0042B958 5001557F */  sq         $21, 0x150($26) /* handwritten instruction */
    /* 32B95C 0042B95C 6001567F */  sq         $22, 0x160($26) /* handwritten instruction */
    /* 32B960 0042B960 7001577F */  sq         $23, 0x170($26) /* handwritten instruction */
    /* 32B964 0042B964 8001587F */  sq         $24, 0x180($26) /* handwritten instruction */
    /* 32B968 0042B968 9001597F */  sq         $25, 0x190($26) /* handwritten instruction */
    /* 32B96C 0042B96C C0015C7F */  sq         $28, 0x1C0($26) /* handwritten instruction */
    /* 32B970 0042B970 D0015D7F */  sq         $29, 0x1D0($26) /* handwritten instruction */
    /* 32B974 0042B974 E0015E7F */  sq         $30, 0x1E0($26) /* handwritten instruction */
    /* 32B978 0042B978 F0015F7F */  sq         $31, 0x1F0($26) /* handwritten instruction */
    /* 32B97C 0042B97C 10100000 */  mfhi       $2
    /* 32B980 0042B980 8900013C */  lui        $1, %hi(D_00892600)
    /* 32B984 0042B984 002622FC */  sd         $2, %lo(D_00892600)($1)
    /* 32B988 0042B988 10100070 */  mfhi1      $2
    /* 32B98C 0042B98C 8900013C */  lui        $1, %hi(D_00892608)
    /* 32B990 0042B990 082622FC */  sd         $2, %lo(D_00892608)($1)
    /* 32B994 0042B994 12100000 */  mflo       $2
    /* 32B998 0042B998 8900013C */  lui        $1, %hi(D_00892610)
    /* 32B99C 0042B99C 102622FC */  sd         $2, %lo(D_00892610)($1)
    /* 32B9A0 0042B9A0 12100070 */  mflo1      $2
    /* 32B9A4 0042B9A4 8900013C */  lui        $1, %hi(D_00892618)
    /* 32B9A8 0042B9A8 182622FC */  sd         $2, %lo(D_00892618)($1)
    /* 32B9AC 0042B9AC 28100000 */  mfsa       $2
    /* 32B9B0 0042B9B0 8900013C */  lui        $1, %hi(D_00892620)
    /* 32B9B4 0042B9B4 202622FC */  sd         $2, %lo(D_00892620)($1)
    /* 32B9B8 0042B9B8 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 32B9BC 0042B9BC 00680540 */  mfc0       $5, $13 /* handwritten instruction */
    /* 32B9C0 0042B9C0 00700640 */  mfc0       $6, $14 /* handwritten instruction */
    /* 32B9C4 0042B9C4 00400740 */  mfc0       $7, $8 /* handwritten instruction */
    /* 32B9C8 0042B9C8 00B80840 */  mfc0       $8, $23 /* handwritten instruction */
    /* 32B9CC 0042B9CC 8900093C */  lui        $9, %hi(D_00892400)
    /* 32B9D0 0042B9D0 00242925 */  addiu      $9, $9, %lo(D_00892400)
    /* 32B9D4 0042B9D4 4300013C */  lui        $1, %hi(D_0042B9FC)
    /* 32B9D8 0042B9D8 FCB92124 */  addiu      $1, $1, %lo(D_0042B9FC)
    /* 32B9DC 0042B9DC 00708140 */  mtc0       $1, $14 /* handwritten instruction */
    /* 32B9E0 0042B9E0 0F040000 */  sync.p
    /* 32B9E4 0042B9E4 00600140 */  mfc0       $1, $12 /* handwritten instruction */
    /* 32B9E8 0042B9E8 FEFF0224 */  addiu      $2, $0, -0x2
    /* 32B9EC 0042B9EC 24082200 */  and        $1, $1, $2
    /* 32B9F0 0042B9F0 00608140 */  mtc0       $1, $12 /* handwritten instruction */
    /* 32B9F4 0042B9F4 0F040000 */  sync.p
    /* 32B9F8 0042B9F8 18000042 */  eret /* handwritten instruction */
  alabel D_0042B9FC
    /* 32B9FC 0042B9FC 7C00A230 */  andi       $2, $5, 0x7C
    /* 32BA00 0042BA00 7100013C */  lui        $1, %hi(D_0070C9E0)
    /* 32BA04 0042BA04 21082200 */  addu       $1, $1, $2
    /* 32BA08 0042BA08 E0C9218C */  lw         $1, %lo(D_0070C9E0)($1)
    /* 32BA0C 0042BA0C 89001D3C */  lui        $29, %hi(D_00892400)
    /* 32BA10 0042BA10 09F82000 */  jalr       $1
    /* 32BA14 0042BA14 0024BD27 */   addiu     $29, $29, %lo(D_00892400)
    /* 32BA18 0042BA18 CDFFFF03 */  break      1023, 1023
    /* 32BA1C 0042BA1C 00000000 */  nop
.size func_0042b6c0, 0x360

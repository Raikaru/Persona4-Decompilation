.section .text
.set noat
.set noreorder
glabel func_002ab790
    /* 1AB790 002AB790 B0FEBD27 */  addiu      $29, $29, -0x150
    /* 1AB794 002AB794 9000BFFF */  sd         $31, 0x90($29)
    /* 1AB798 002AB798 8000B77F */  sq         $23, 0x80($29)
    /* 1AB79C 002AB79C 7000B67F */  sq         $22, 0x70($29)
    /* 1AB7A0 002AB7A0 6000B57F */  sq         $21, 0x60($29)
    /* 1AB7A4 002AB7A4 5000B47F */  sq         $20, 0x50($29)
    /* 1AB7A8 002AB7A8 4000B37F */  sq         $19, 0x40($29)
    /* 1AB7AC 002AB7AC 3000B27F */  sq         $18, 0x30($29)
    /* 1AB7B0 002AB7B0 2000B17F */  sq         $17, 0x20($29)
    /* 1AB7B4 002AB7B4 1000B07F */  sq         $16, 0x10($29)
    /* 1AB7B8 002AB7B8 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 1AB7BC 002AB7BC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1AB7C0 002AB7C0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1AB7C4 002AB7C4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AB7C8 002AB7C8 C6650046 */  mov.s      $f23, $f12
    /* 1AB7CC 002AB7CC 866D0046 */  mov.s      $f22, $f13
    /* 1AB7D0 002AB7D0 46750046 */  mov.s      $f21, $f14
    /* 1AB7D4 002AB7D4 2DA88000 */  daddu      $21, $4, $0
    /* 1AB7D8 002AB7D8 2DA0A000 */  daddu      $20, $5, $0
    /* 1AB7DC 002AB7DC 067D0046 */  mov.s      $f20, $f15
    /* 1AB7E0 002AB7E0 2DB0C000 */  daddu      $22, $6, $0
    /* 1AB7E4 002AB7E4 2D98E000 */  daddu      $19, $7, $0
    /* 1AB7E8 002AB7E8 2D900001 */  daddu      $18, $8, $0
    /* 1AB7EC 002AB7EC 2D206002 */  daddu      $4, $19, $0
    /* 1AB7F0 002AB7F0 BCE8110C */  jal        func_0047a2f0
    /* 1AB7F4 002AB7F4 00000000 */   nop
    /* 1AB7F8 002AB7F8 2DB84000 */  daddu      $23, $2, $0
    /* 1AB7FC 002AB7FC 24B00046 */  .word      0x4600B024                    # cvt.w.s    $f0, $f22 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AB800 002AB800 00001144 */  mfc1       $17, $f0
    /* 1AB804 002AB804 24B80046 */  .word      0x4600B824                    # cvt.w.s    $f0, $f23 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AB808 002AB808 00001044 */  mfc1       $16, $f0
    /* 1AB80C 002AB80C 2001A427 */  addiu      $4, $29, 0x120
    /* 1AB810 002AB810 2D280002 */  daddu      $5, $16, $0
    /* 1AB814 002AB814 2D302002 */  daddu      $6, $17, $0
    /* 1AB818 002AB818 06AB0046 */  mov.s      $f12, $f21
    /* 1AB81C 002AB81C BC40040C */  jal        func_001102f0
    /* 1AB820 002AB820 00000000 */   nop
    /* 1AB824 002AB824 485C110C */  jal        func_00457120
    /* 1AB828 002AB828 00000000 */   nop
    /* 1AB82C 002AB82C 0400448C */  lw         $4, 0x4($2)
    /* 1AB830 002AB830 C0A50F0C */  jal        func_003e9700
    /* 1AB834 002AB834 00000000 */   nop
    /* 1AB838 002AB838 E000A627 */  addiu      $6, $29, 0xE0
    /* 1AB83C 002AB83C 08000524 */  addiu      $5, $0, 0x8
  .L002AB840:
    /* 1AB840 002AB840 0000448C */  lw         $4, 0x0($2)
    /* 1AB844 002AB844 0400438C */  lw         $3, 0x4($2)
    /* 1AB848 002AB848 08004224 */  addiu      $2, $2, 0x8
    /* 1AB84C 002AB84C FFFFA524 */  addiu      $5, $5, -0x1
    /* 1AB850 002AB850 0000C4AC */  sw         $4, 0x0($6)
    /* 1AB854 002AB854 0400C3AC */  sw         $3, 0x4($6)
    /* 1AB858 002AB858 0800C624 */  addiu      $6, $6, 0x8
    /* 1AB85C 002AB85C F8FFA01C */  bgtz       $5, .L002AB840
    /* 1AB860 002AB860 00000000 */   nop
    /* 1AB864 002AB864 2001A1C7 */  lwc1       $f1, 0x120($29)
    /* 1AB868 002AB868 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* 1AB86C 002AB86C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AB870 002AB870 0001A0E7 */  swc1       $f0, 0x100($29)
    /* 1AB874 002AB874 2401A1C7 */  lwc1       $f1, 0x124($29)
    /* 1AB878 002AB878 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* 1AB87C 002AB87C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AB880 002AB880 0401A0E7 */  swc1       $f0, 0x104($29)
    /* 1AB884 002AB884 2801A1C7 */  lwc1       $f1, 0x128($29)
    /* 1AB888 002AB888 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* 1AB88C 002AB88C 01080046 */  sub.s      $f0, $f1, $f0
    /* 1AB890 002AB890 0801A0E7 */  swc1       $f0, 0x108($29)
    /* 1AB894 002AB894 0001A427 */  addiu      $4, $29, 0x100
    /* 1AB898 002AB898 2D288000 */  daddu      $5, $4, $0
    /* 1AB89C 002AB89C 2C900F0C */  jal        func_003e40b0
    /* 1AB8A0 002AB8A0 00000000 */   nop
    /* 1AB8A4 002AB8A4 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* 1AB8A8 002AB8A8 01000046 */  sub.s      $f0, $f0, $f0
    /* 1AB8AC 002AB8AC 1001A0E7 */  swc1       $f0, 0x110($29)
    /* 1AB8B0 002AB8B0 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* 1AB8B4 002AB8B4 01000046 */  sub.s      $f0, $f0, $f0
    /* 1AB8B8 002AB8B8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* 1AB8BC 002AB8BC 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* 1AB8C0 002AB8C0 01000046 */  sub.s      $f0, $f0, $f0
    /* 1AB8C4 002AB8C4 1801A0E7 */  swc1       $f0, 0x118($29)
    /* 1AB8C8 002AB8C8 E000A427 */  addiu      $4, $29, 0xE0
    /* 1AB8CC 002AB8CC 74810F0C */  jal        func_003e05d0
    /* 1AB8D0 002AB8D0 00000000 */   nop
    /* 1AB8D4 002AB8D4 3801B4E7 */  swc1       $f20, 0x138($29)
    /* 1AB8D8 002AB8D8 3401B4E7 */  swc1       $f20, 0x134($29)
    /* 1AB8DC 002AB8DC 3001B4E7 */  swc1       $f20, 0x130($29)
    /* 1AB8E0 002AB8E0 E000A427 */  addiu      $4, $29, 0xE0
    /* 1AB8E4 002AB8E4 3001A527 */  addiu      $5, $29, 0x130
    /* 1AB8E8 002AB8E8 2D300000 */  daddu      $6, $0, $0
    /* 1AB8EC 002AB8EC A4820F0C */  jal        func_003e0a90
    /* 1AB8F0 002AB8F0 00000000 */   nop
    /* 1AB8F4 002AB8F4 A000A427 */  addiu      $4, $29, 0xA0
    /* 1AB8F8 002AB8F8 E000A527 */  addiu      $5, $29, 0xE0
    /* 1AB8FC 002AB8FC 2D30E002 */  daddu      $6, $23, $0
    /* 1AB900 002AB900 7C810F0C */  jal        func_003e05f0
    /* 1AB904 002AB904 00000000 */   nop
    /* 1AB908 002AB908 A000A527 */  addiu      $5, $29, 0xA0
    /* 1AB90C 002AB90C E000A427 */  addiu      $4, $29, 0xE0
    /* 1AB910 002AB910 04000324 */  addiu      $3, $0, 0x4
  .L002AB914:
    /* 1AB914 002AB914 0000A278 */  lq         $2, 0x0($5)
    /* 1AB918 002AB918 1000A524 */  addiu      $5, $5, 0x10
    /* 1AB91C 002AB91C FFFF6324 */  addiu      $3, $3, -0x1
    /* 1AB920 002AB920 0000827C */  sq         $2, 0x0($4)
    /* 1AB924 002AB924 10008424 */  addiu      $4, $4, 0x10
    /* 1AB928 002AB928 FAFF601C */  bgtz       $3, .L002AB914
    /* 1AB92C 002AB92C 00000000 */   nop
    /* 1AB930 002AB930 0900C012 */  beqz       $22, .L002AB958
    /* 1AB934 002AB934 00000000 */   nop
    /* 1AB938 002AB938 4001A427 */  addiu      $4, $29, 0x140
    /* 1AB93C 002AB93C 2D280002 */  daddu      $5, $16, $0
    /* 1AB940 002AB940 2D302002 */  daddu      $6, $17, $0
    /* 1AB944 002AB944 06AB0046 */  mov.s      $f12, $f21
    /* 1AB948 002AB948 BC40040C */  jal        func_001102f0
    /* 1AB94C 002AB94C 00000000 */   nop
    /* 1AB950 002AB950 04000010 */  b          .L002AB964
    /* 1AB954 002AB954 00000000 */   nop
  .L002AB958:
    /* 1AB958 002AB958 4001B7E7 */  swc1       $f23, 0x140($29)
    /* 1AB95C 002AB95C 4401B6E7 */  swc1       $f22, 0x144($29)
    /* 1AB960 002AB960 4801B5E7 */  swc1       $f21, 0x148($29)
  .L002AB964:
    /* 1AB964 002AB964 E000A427 */  addiu      $4, $29, 0xE0
    /* 1AB968 002AB968 4001A527 */  addiu      $5, $29, 0x140
    /* 1AB96C 002AB96C 02000624 */  addiu      $6, $0, 0x2
    /* 1AB970 002AB970 24830F0C */  jal        func_003e0c90
    /* 1AB974 002AB974 00000000 */   nop
    /* 1AB978 002AB978 6400043C */  lui        $4, %hi(D_0063EE50)
    /* 1AB97C 002AB97C 50EE8424 */  addiu      $4, $4, %lo(D_0063EE50)
    /* 1AB980 002AB980 6B010524 */  addiu      $5, $0, 0x16B
    /* 1AB984 002AB984 A43A110C */  jal        func_0044ea90
    /* 1AB988 002AB988 00000000 */   nop
    /* 1AB98C 002AB98C 01000424 */  addiu      $4, $0, 0x1
    /* 1AB990 002AB990 60000524 */  addiu      $5, $0, 0x60
    /* 1AB994 002AB994 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AB998 002AB998 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AB99C 002AB99C F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AB9A0 002AB9A0 09F84000 */  jalr       $2
    /* 1AB9A4 002AB9A4 00000000 */   nop
    /* 1AB9A8 002AB9A8 2D804000 */  daddu      $16, $2, $0
    /* 1AB9AC 002AB9AC 001A1500 */  sll        $3, $21, 8
    /* 1AB9B0 002AB9B0 25187400 */  or         $3, $3, $20
    /* 1AB9B4 002AB9B4 000043AC */  sw         $3, 0x0($2)
    /* 1AB9B8 002AB9B8 D800638E */  lw         $3, 0xD8($19)
    /* 1AB9BC 002AB9BC 500043AC */  sw         $3, 0x50($2)
    /* 1AB9C0 002AB9C0 E000A627 */  addiu      $6, $29, 0xE0
    /* 1AB9C4 002AB9C4 10000526 */  addiu      $5, $16, 0x10
    /* 1AB9C8 002AB9C8 08000424 */  addiu      $4, $0, 0x8
  .L002AB9CC:
    /* 1AB9CC 002AB9CC 0000C38C */  lw         $3, 0x0($6)
    /* 1AB9D0 002AB9D0 0400C28C */  lw         $2, 0x4($6)
    /* 1AB9D4 002AB9D4 0800C624 */  addiu      $6, $6, 0x8
    /* 1AB9D8 002AB9D8 FFFF8424 */  addiu      $4, $4, -0x1
    /* 1AB9DC 002AB9DC 0000A3AC */  sw         $3, 0x0($5)
    /* 1AB9E0 002AB9E0 0400A2AC */  sw         $2, 0x4($5)
    /* 1AB9E4 002AB9E4 0800A524 */  addiu      $5, $5, 0x8
    /* 1AB9E8 002AB9E8 F8FF801C */  bgtz       $4, .L002AB9CC
    /* 1AB9EC 002AB9EC 00000000 */   nop
    /* 1AB9F0 002AB9F0 540013AE */  sw         $19, 0x54($16)
    /* 1AB9F4 002AB9F4 0D004012 */  beqz       $18, .L002ABA2C
    /* 1AB9F8 002AB9F8 00000000 */   nop
    /* 1AB9FC 002AB9FC 6482110C */  jal        func_00460990
    /* 1ABA00 002ABA00 00000000 */   nop
    /* 1ABA04 002ABA04 2D284000 */  daddu      $5, $2, $0
    /* 1ABA08 002ABA08 2B00033C */  lui        $3, %hi(func_002ab4b0)
    /* 1ABA0C 002ABA0C B0B46324 */  addiu      $3, $3, %lo(func_002ab4b0)
    /* 1ABA10 002ABA10 080043AC */  sw         $3, 0x8($2)
    /* 1ABA14 002ABA14 100050AC */  sw         $16, 0x10($2)
    /* 1ABA18 002ABA18 2D204002 */  daddu      $4, $18, $0
    /* 1ABA1C 002ABA1C B082110C */  jal        func_00460ac0
    /* 1ABA20 002ABA20 00000000 */   nop
    /* 1ABA24 002ABA24 2F000010 */  b          .L002ABAE4
    /* 1ABA28 002ABA28 00000000 */   nop
  .L002ABA2C:
    /* 1ABA2C 002ABA2C 2D206002 */  daddu      $4, $19, $0
    /* 1ABA30 002ABA30 BCE8110C */  jal        func_0047a2f0
    /* 1ABA34 002ABA34 00000000 */   nop
    /* 1ABA38 002ABA38 E000A627 */  addiu      $6, $29, 0xE0
    /* 1ABA3C 002ABA3C 08000524 */  addiu      $5, $0, 0x8
  .L002ABA40:
    /* 1ABA40 002ABA40 0000448C */  lw         $4, 0x0($2)
    /* 1ABA44 002ABA44 0400438C */  lw         $3, 0x4($2)
    /* 1ABA48 002ABA48 08004224 */  addiu      $2, $2, 0x8
    /* 1ABA4C 002ABA4C FFFFA524 */  addiu      $5, $5, -0x1
    /* 1ABA50 002ABA50 0000C4AC */  sw         $4, 0x0($6)
    /* 1ABA54 002ABA54 0400C3AC */  sw         $3, 0x4($6)
    /* 1ABA58 002ABA58 0800C624 */  addiu      $6, $6, 0x8
    /* 1ABA5C 002ABA5C F8FFA01C */  bgtz       $5, .L002ABA40
    /* 1ABA60 002ABA60 00000000 */   nop
    /* 1ABA64 002ABA64 0000038E */  lw         $3, 0x0($16)
    /* 1ABA68 002ABA68 02160300 */  srl        $2, $3, 24
    /* 1ABA6C 002ABA6C 4C01A2A3 */  sb         $2, 0x14C($29)
    /* 1ABA70 002ABA70 02140300 */  srl        $2, $3, 16
    /* 1ABA74 002ABA74 4D01A2A3 */  sb         $2, 0x14D($29)
    /* 1ABA78 002ABA78 02120300 */  srl        $2, $3, 8
    /* 1ABA7C 002ABA7C 4E01A2A3 */  sb         $2, 0x14E($29)
    /* 1ABA80 002ABA80 4F01A3A3 */  sb         $3, 0x14F($29)
    /* 1ABA84 002ABA84 5400128E */  lw         $18, 0x54($16)
    /* 1ABA88 002ABA88 D800518E */  lw         $17, 0xD8($18)
    /* 1ABA8C 002ABA8C 5000028E */  lw         $2, 0x50($16)
    /* 1ABA90 002ABA90 D80042AE */  sw         $2, 0xD8($18)
    /* 1ABA94 002ABA94 2D204002 */  daddu      $4, $18, $0
    /* 1ABA98 002ABA98 10000526 */  addiu      $5, $16, 0x10
    /* 1ABA9C 002ABA9C 2D300000 */  daddu      $6, $0, $0
    /* 1ABAA0 002ABAA0 70E8110C */  jal        func_0047a1c0
    /* 1ABAA4 002ABAA4 00000000 */   nop
    /* 1ABAA8 002ABAA8 2D204002 */  daddu      $4, $18, $0
    /* 1ABAAC 002ABAAC 4C01A527 */  addiu      $5, $29, 0x14C
    /* 1ABAB0 002ABAB0 54AD0A0C */  jal        func_002ab550
    /* 1ABAB4 002ABAB4 00000000 */   nop
    /* 1ABAB8 002ABAB8 D80051AE */  sw         $17, 0xD8($18)
    /* 1ABABC 002ABABC 2D200002 */  daddu      $4, $16, $0
    /* 1ABAC0 002ABAC0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1ABAC4 002ABAC4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1ABAC8 002ABAC8 09F84000 */  jalr       $2
    /* 1ABACC 002ABACC 00000000 */   nop
    /* 1ABAD0 002ABAD0 2D206002 */  daddu      $4, $19, $0
    /* 1ABAD4 002ABAD4 E000A527 */  addiu      $5, $29, 0xE0
    /* 1ABAD8 002ABAD8 2D300000 */  daddu      $6, $0, $0
    /* 1ABADC 002ABADC 70E8110C */  jal        func_0047a1c0
    /* 1ABAE0 002ABAE0 00000000 */   nop
  .L002ABAE4:
    /* 1ABAE4 002ABAE4 9000BFDF */  ld         $31, 0x90($29)
    /* 1ABAE8 002ABAE8 8000B77B */  lq         $23, 0x80($29)
    /* 1ABAEC 002ABAEC 7000B67B */  lq         $22, 0x70($29)
    /* 1ABAF0 002ABAF0 6000B57B */  lq         $21, 0x60($29)
    /* 1ABAF4 002ABAF4 5000B47B */  lq         $20, 0x50($29)
    /* 1ABAF8 002ABAF8 4000B37B */  lq         $19, 0x40($29)
    /* 1ABAFC 002ABAFC 3000B27B */  lq         $18, 0x30($29)
    /* 1ABB00 002ABB00 2000B17B */  lq         $17, 0x20($29)
    /* 1ABB04 002ABB04 1000B07B */  lq         $16, 0x10($29)
    /* 1ABB08 002ABB08 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 1ABB0C 002ABB0C 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1ABB10 002ABB10 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1ABB14 002ABB14 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1ABB18 002ABB18 5001BD27 */  addiu      $29, $29, 0x150
    /* 1ABB1C 002ABB1C 0800E003 */  jr         $31
    /* 1ABB20 002ABB20 00000000 */   nop
    /* 1ABB24 002ABB24 00000000 */  nop
    /* 1ABB28 002ABB28 00000000 */  nop
    /* 1ABB2C 002ABB2C 00000000 */  nop
.size func_002ab790, 0x3a0

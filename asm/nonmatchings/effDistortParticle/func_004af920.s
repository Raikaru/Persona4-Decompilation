.section .text
.set noat
.set noreorder
glabel func_004af920
    /* 3AF920 004AF920 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AF924 004AF924 3000BFFF */  sd         $31, 0x30($29)
    /* 3AF928 004AF928 2000B27F */  sq         $18, 0x20($29)
    /* 3AF92C 004AF92C 1000B17F */  sq         $17, 0x10($29)
    /* 3AF930 004AF930 0000B07F */  sq         $16, 0x0($29)
    /* 3AF934 004AF934 2D888000 */  daddu      $17, $4, $0
    /* 3AF938 004AF938 5C00828C */  lw         $2, 0x5C($4)
    /* 3AF93C 004AF93C 06004014 */  bnez       $2, .L004AF958
    /* 3AF940 004AF940 00000000 */   nop
    /* 3AF944 004AF944 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AF948 004AF948 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AF94C 004AF94C B3000524 */  addiu      $5, $0, 0xB3
    /* 3AF950 004AF950 CCB5110C */  jal        func_0046d730
    /* 3AF954 004AF954 00000000 */   nop
  .L004AF958:
    /* 3AF958 004AF958 5C00228E */  lw         $2, 0x5C($17)
    /* 3AF95C 004AF95C 2400508C */  lw         $16, 0x24($2)
    /* 3AF960 004AF960 06000016 */  bnez       $16, .L004AF97C
    /* 3AF964 004AF964 00000000 */   nop
    /* 3AF968 004AF968 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AF96C 004AF96C 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AF970 004AF970 B5000524 */  addiu      $5, $0, 0xB5
    /* 3AF974 004AF974 CCB5110C */  jal        func_0046d730
    /* 3AF978 004AF978 00000000 */   nop
  .L004AF97C:
    /* 3AF97C 004AF97C 2000038E */  lw         $3, 0x20($16)
    /* 3AF980 004AF980 06006014 */  bnez       $3, .L004AF99C
    /* 3AF984 004AF984 00000000 */   nop
    /* 3AF988 004AF988 B800038E */  lw         $3, 0xB8($16)
    /* 3AF98C 004AF98C 2400028E */  lw         $2, 0x24($16)
    /* 3AF990 004AF990 18206200 */  mult       $4, $3, $2
    /* 3AF994 004AF994 03000010 */  b          .L004AF9A4
    /* 3AF998 004AF998 00000000 */   nop
  .L004AF99C:
    /* 3AF99C 004AF99C 2400028E */  lw         $2, 0x24($16)
    /* 3AF9A0 004AF9A0 18206200 */  mult       $4, $3, $2
  .L004AF9A4:
    /* 3AF9A4 004AF9A4 6500812C */  sltiu      $1, $4, 0x65
    /* 3AF9A8 004AF9A8 02002014 */  bnez       $1, .L004AF9B4
    /* 3AF9AC 004AF9AC 00000000 */   nop
    /* 3AF9B0 004AF9B0 64000424 */  addiu      $4, $0, 0x64
  .L004AF9B4:
    /* 3AF9B4 004AF9B4 A0BD120C */  jal        func_004af680
    /* 3AF9B8 004AF9B8 00000000 */   nop
    /* 3AF9BC 004AF9BC 2D904000 */  daddu      $18, $2, $0
    /* 3AF9C0 004AF9C0 06004016 */  bnez       $18, .L004AF9DC
    /* 3AF9C4 004AF9C4 00000000 */   nop
    /* 3AF9C8 004AF9C8 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AF9CC 004AF9CC 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AF9D0 004AF9D0 B7000524 */  addiu      $5, $0, 0xB7
    /* 3AF9D4 004AF9D4 CCB5110C */  jal        func_0046d730
    /* 3AF9D8 004AF9D8 00000000 */   nop
  .L004AF9DC:
    /* 3AF9DC 004AF9DC 0C004426 */  addiu      $4, $18, 0xC
    /* 3AF9E0 004AF9E0 0C002526 */  addiu      $5, $17, 0xC
    /* 3AF9E4 004AF9E4 48000624 */  addiu      $6, $0, 0x48
    /* 3AF9E8 004AF9E8 04FE100C */  jal        func_0043f810
    /* 3AF9EC 004AF9EC 00000000 */   nop
    /* 3AF9F0 004AF9F0 5C00228E */  lw         $2, 0x5C($17)
    /* 3AF9F4 004AF9F4 00004594 */  lhu        $5, 0x0($2)
    /* 3AF9F8 004AF9F8 2D204002 */  daddu      $4, $18, $0
    /* 3AF9FC 004AF9FC 2D300002 */  daddu      $6, $16, $0
    /* 3AFA00 004AFA00 C4BE120C */  jal        func_004afb10
    /* 3AFA04 004AFA04 00000000 */   nop
    /* 3AFA08 004AFA08 5C00428E */  lw         $2, 0x5C($18)
    /* 3AFA0C 004AFA0C 0800428C */  lw         $2, 0x8($2)
    /* 3AFA10 004AFA10 04004014 */  bnez       $2, .L004AFA24
    /* 3AFA14 004AFA14 00000000 */   nop
    /* 3AFA18 004AFA18 2D104002 */  daddu      $2, $18, $0
    /* 3AFA1C 004AFA1C 06000010 */  b          .L004AFA38
    /* 3AFA20 004AFA20 00000000 */   nop
  .L004AFA24:
    /* 3AFA24 004AFA24 2D204002 */  daddu      $4, $18, $0
    /* 3AFA28 004AFA28 2D282002 */  daddu      $5, $17, $0
    /* 3AFA2C 004AFA2C A8BE120C */  jal        func_004afaa0
    /* 3AFA30 004AFA30 00000000 */   nop
    /* 3AFA34 004AFA34 2D104002 */  daddu      $2, $18, $0
  .L004AFA38:
    /* 3AFA38 004AFA38 3000BFDF */  ld         $31, 0x30($29)
    /* 3AFA3C 004AFA3C 2000B27B */  lq         $18, 0x20($29)
    /* 3AFA40 004AFA40 1000B17B */  lq         $17, 0x10($29)
    /* 3AFA44 004AFA44 0000B07B */  lq         $16, 0x0($29)
    /* 3AFA48 004AFA48 4000BD27 */  addiu      $29, $29, 0x40
    /* 3AFA4C 004AFA4C 0800E003 */  jr         $31
    /* 3AFA50 004AFA50 00000000 */   nop
    /* 3AFA54 004AFA54 00000000 */  nop
    /* 3AFA58 004AFA58 00000000 */  nop
    /* 3AFA5C 004AFA5C 00000000 */  nop
.size func_004af920, 0x140

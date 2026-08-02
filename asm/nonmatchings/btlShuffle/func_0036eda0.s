.section .text
.set noat
.set noreorder
glabel func_0036eda0
    /* 26EDA0 0036EDA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 26EDA4 0036EDA4 2000BFFF */  sd         $31, 0x20($29)
    /* 26EDA8 0036EDA8 1000B17F */  sq         $17, 0x10($29)
    /* 26EDAC 0036EDAC 0000B07F */  sq         $16, 0x0($29)
    /* 26EDB0 0036EDB0 FDFF9124 */  addiu      $17, $4, -0x3
    /* 26EDB4 0036EDB4 04002106 */  bgez       $17, .L0036EDC8
    /* 26EDB8 0036EDB8 00000000 */   nop
    /* 26EDBC 0036EDBC 2D880000 */  daddu      $17, $0, $0
    /* 26EDC0 0036EDC0 05000010 */  b          .L0036EDD8
    /* 26EDC4 0036EDC4 00000000 */   nop
  .L0036EDC8:
    /* 26EDC8 0036EDC8 0600222E */  sltiu      $2, $17, 0x6
    /* 26EDCC 0036EDCC 02004014 */  bnez       $2, .L0036EDD8
    /* 26EDD0 0036EDD0 00000000 */   nop
    /* 26EDD4 0036EDD4 05001124 */  addiu      $17, $0, 0x5
  .L0036EDD8:
    /* 26EDD8 0036EDD8 64000424 */  addiu      $4, $0, 0x64
    /* 26EDDC 0036EDDC 5CC7080C */  jal        func_00231d70
    /* 26EDE0 0036EDE0 00000000 */   nop
    /* 26EDE4 0036EDE4 03001024 */  addiu      $16, $0, 0x3
    /* 26EDE8 0036EDE8 80201100 */  sll        $4, $17, 2
    /* 26EDEC 0036EDEC 6500033C */  lui        $3, %hi(D_0064E5D0)
    /* 26EDF0 0036EDF0 D0E56324 */  addiu      $3, $3, %lo(D_0064E5D0)
    /* 26EDF4 0036EDF4 21206400 */  addu       $4, $3, $4
    /* 26EDF8 0036EDF8 07000010 */  b          .L0036EE18
    /* 26EDFC 0036EDFC 00000000 */   nop
  .L0036EE00:
    /* 26EE00 0036EE00 21189000 */  addu       $3, $4, $16
    /* 26EE04 0036EE04 00006390 */  lbu        $3, 0x0($3)
    /* 26EE08 0036EE08 2A084300 */  slt        $1, $2, $3
    /* 26EE0C 0036EE0C 04002014 */  bnez       $1, .L0036EE20
    /* 26EE10 0036EE10 00000000 */   nop
    /* 26EE14 0036EE14 FFFF1026 */  addiu      $16, $16, -0x1
  .L0036EE18:
    /* 26EE18 0036EE18 F9FF001E */  bgtz       $16, .L0036EE00
    /* 26EE1C 0036EE1C 00000000 */   nop
  .L0036EE20:
    /* 26EE20 0036EE20 06000106 */  bgez       $16, .L0036EE3C
    /* 26EE24 0036EE24 00000000 */   nop
    /* 26EE28 0036EE28 6500043C */  lui        $4, %hi(D_0064E790)
    /* 26EE2C 0036EE2C 90E78424 */  addiu      $4, $4, %lo(D_0064E790)
    /* 26EE30 0036EE30 07030524 */  addiu      $5, $0, 0x307
    /* 26EE34 0036EE34 CCB5110C */  jal        func_0046d730
    /* 26EE38 0036EE38 00000000 */   nop
  .L0036EE3C:
    /* 26EE3C 0036EE3C 01000226 */  addiu      $2, $16, 0x1
    /* 26EE40 0036EE40 2000BFDF */  ld         $31, 0x20($29)
    /* 26EE44 0036EE44 1000B17B */  lq         $17, 0x10($29)
    /* 26EE48 0036EE48 0000B07B */  lq         $16, 0x0($29)
    /* 26EE4C 0036EE4C 3000BD27 */  addiu      $29, $29, 0x30
    /* 26EE50 0036EE50 0800E003 */  jr         $31
    /* 26EE54 0036EE54 00000000 */   nop
    /* 26EE58 0036EE58 00000000 */  nop
    /* 26EE5C 0036EE5C 00000000 */  nop
.size func_0036eda0, 0xc0

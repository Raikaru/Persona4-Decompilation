.section .text
.set noat
.set noreorder
glabel func_002bc890
    /* 1BC890 002BC890 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1BC894 002BC894 3000BFFF */  sd         $31, 0x30($29)
    /* 1BC898 002BC898 2000B27F */  sq         $18, 0x20($29)
    /* 1BC89C 002BC89C 1000B17F */  sq         $17, 0x10($29)
    /* 1BC8A0 002BC8A0 0000B07F */  sq         $16, 0x0($29)
    /* 1BC8A4 002BC8A4 2D908000 */  daddu      $18, $4, $0
    /* 1BC8A8 002BC8A8 2D88A000 */  daddu      $17, $5, $0
    /* 1BC8AC 002BC8AC 06004016 */  bnez       $18, .L002BC8C8
    /* 1BC8B0 002BC8B0 00000000 */   nop
    /* 1BC8B4 002BC8B4 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BC8B8 002BC8B8 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BC8BC 002BC8BC 41050524 */  addiu      $5, $0, 0x541
    /* 1BC8C0 002BC8C0 CCB5110C */  jal        func_0046d730
    /* 1BC8C4 002BC8C4 00000000 */   nop
  .L002BC8C8:
    /* 1BC8C8 002BC8C8 04002006 */  bltz       $17, .L002BC8DC
    /* 1BC8CC 002BC8CC 00000000 */   nop
    /* 1BC8D0 002BC8D0 0C00212A */  slti       $1, $17, 0xC
    /* 1BC8D4 002BC8D4 06002014 */  bnez       $1, .L002BC8F0
    /* 1BC8D8 002BC8D8 00000000 */   nop
  .L002BC8DC:
    /* 1BC8DC 002BC8DC 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BC8E0 002BC8E0 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BC8E4 002BC8E4 42050524 */  addiu      $5, $0, 0x542
    /* 1BC8E8 002BC8E8 CCB5110C */  jal        func_0046d730
    /* 1BC8EC 002BC8EC 00000000 */   nop
  .L002BC8F0:
    /* 1BC8F0 002BC8F0 40101100 */  sll        $2, $17, 1
    /* 1BC8F4 002BC8F4 21105100 */  addu       $2, $2, $17
    /* 1BC8F8 002BC8F8 80100200 */  sll        $2, $2, 2
    /* 1BC8FC 002BC8FC 21104202 */  addu       $2, $18, $2
    /* 1BC900 002BC900 1C005024 */  addiu      $16, $2, 0x1C
    /* 1BC904 002BC904 1C00438C */  lw         $3, 0x1C($2)
    /* 1BC908 002BC908 02006230 */  andi       $2, $3, 0x2
    /* 1BC90C 002BC90C 24004014 */  bnez       $2, .L002BC9A0
    /* 1BC910 002BC910 00000000 */   nop
    /* 1BC914 002BC914 1800428E */  lw         $2, 0x18($18)
    /* 1BC918 002BC918 0400448C */  lw         $4, 0x4($2)
    /* 1BC91C 002BC91C 08000010 */  b          .L002BC940
    /* 1BC920 002BC920 00000000 */   nop
  .L002BC924:
    /* 1BC924 002BC924 1400858C */  lw         $5, 0x14($4)
    /* 1BC928 002BC928 0400A28C */  lw         $2, 0x4($5)
    /* 1BC92C 002BC92C 03005114 */  bne        $2, $17, .L002BC93C
    /* 1BC930 002BC930 00000000 */   nop
    /* 1BC934 002BC934 05000010 */  b          .L002BC94C
    /* 1BC938 002BC938 00000000 */   nop
  .L002BC93C:
    /* 1BC93C 002BC93C 1000848C */  lw         $4, 0x10($4)
  .L002BC940:
    /* 1BC940 002BC940 F8FF8014 */  bnez       $4, .L002BC924
    /* 1BC944 002BC944 00000000 */   nop
    /* 1BC948 002BC948 2D280000 */  daddu      $5, $0, $0
  .L002BC94C:
    /* 1BC94C 002BC94C 1400A014 */  bnez       $5, .L002BC9A0
    /* 1BC950 002BC950 00000000 */   nop
    /* 1BC954 002BC954 040011AE */  sw         $17, 0x4($16)
    /* 1BC958 002BC958 1800448E */  lw         $4, 0x18($18)
    /* 1BC95C 002BC95C 10008294 */  lhu        $2, 0x10($4)
    /* 1BC960 002BC960 01004524 */  addiu      $5, $2, 0x1
    /* 1BC964 002BC964 2D300000 */  daddu      $6, $0, $0
    /* 1BC968 002BC968 5C880B0C */  jal        func_002e2170
    /* 1BC96C 002BC96C 00000000 */   nop
    /* 1BC970 002BC970 2D884000 */  daddu      $17, $2, $0
    /* 1BC974 002BC974 06002016 */  bnez       $17, .L002BC990
    /* 1BC978 002BC978 00000000 */   nop
    /* 1BC97C 002BC97C 7500043C */  lui        $4, %hi(D_007488E8)
    /* 1BC980 002BC980 E8888424 */  addiu      $4, $4, %lo(D_007488E8)
    /* 1BC984 002BC984 52000524 */  addiu      $5, $0, 0x52
    /* 1BC988 002BC988 CCB5110C */  jal        func_0046d730
    /* 1BC98C 002BC98C 00000000 */   nop
  .L002BC990:
    /* 1BC990 002BC990 140030AE */  sw         $16, 0x14($17)
    /* 1BC994 002BC994 01000224 */  addiu      $2, $0, 0x1
    /* 1BC998 002BC998 08000010 */  b          .L002BC9BC
    /* 1BC99C 002BC99C 00000000 */   nop
  .L002BC9A0:
    /* 1BC9A0 002BC9A0 04006230 */  andi       $2, $3, 0x4
    /* 1BC9A4 002BC9A4 04004010 */  beqz       $2, .L002BC9B8
    /* 1BC9A8 002BC9A8 00000000 */   nop
    /* 1BC9AC 002BC9AC FBFF0224 */  addiu      $2, $0, -0x5
    /* 1BC9B0 002BC9B0 24106200 */  and        $2, $3, $2
    /* 1BC9B4 002BC9B4 000002AE */  sw         $2, 0x0($16)
  .L002BC9B8:
    /* 1BC9B8 002BC9B8 2D100000 */  daddu      $2, $0, $0
  .L002BC9BC:
    /* 1BC9BC 002BC9BC 3000BFDF */  ld         $31, 0x30($29)
    /* 1BC9C0 002BC9C0 2000B27B */  lq         $18, 0x20($29)
    /* 1BC9C4 002BC9C4 1000B17B */  lq         $17, 0x10($29)
    /* 1BC9C8 002BC9C8 0000B07B */  lq         $16, 0x0($29)
    /* 1BC9CC 002BC9CC 4000BD27 */  addiu      $29, $29, 0x40
    /* 1BC9D0 002BC9D0 0800E003 */  jr         $31
    /* 1BC9D4 002BC9D4 00000000 */   nop
    /* 1BC9D8 002BC9D8 00000000 */  nop
    /* 1BC9DC 002BC9DC 00000000 */  nop
.size func_002bc890, 0x150

.section .text
.set noat
.set noreorder
glabel func_0019d990
    /* 9D990 0019D990 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9D994 0019D994 1000BFFF */  sd         $31, 0x10($29)
    /* 9D998 0019D998 0000B07F */  sq         $16, 0x0($29)
    /* 9D99C 0019D99C 2D808000 */  daddu      $16, $4, $0
    /* 9D9A0 0019D9A0 9800838C */  lw         $3, 0x98($4)
    /* 9D9A4 0019D9A4 02006330 */  andi       $3, $3, 0x2
    /* 9D9A8 0019D9A8 5D006010 */  beqz       $3, .L0019DB20
    /* 9D9AC 0019D9AC 00000000 */   nop
    /* 9D9B0 0019D9B0 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* 9D9B4 0019D9B4 0700612C */  sltiu      $1, $3, 0x7
    /* 9D9B8 0019D9B8 59002010 */  beqz       $1, .L0019DB20
    /* 9D9BC 0019D9BC 00000000 */   nop
    /* 9D9C0 0019D9C0 7400043C */  lui        $4, %hi(jtbl_00746F90)
    /* 9D9C4 0019D9C4 906F8424 */  addiu      $4, $4, %lo(jtbl_00746F90)
    /* 9D9C8 0019D9C8 80180300 */  sll        $3, $3, 2
    /* 9D9CC 0019D9CC 21186400 */  addu       $3, $3, $4
    /* 9D9D0 0019D9D0 0000638C */  lw         $3, 0x0($3)
    /* 9D9D4 0019D9D4 08006000 */  jr         $3
    /* 9D9D8 0019D9D8 00000000 */   nop
    /* 9D9DC 0019D9DC FE090596 */  lhu        $5, 0x9FE($16)
    /* 9D9E0 0019D9E0 4F00A010 */  beqz       $5, .L0019DB20
    /* 9D9E4 0019D9E4 00000000 */   nop
    /* 9D9E8 0019D9E8 0F00033C */  lui        $3, (0xFFC00 >> 16)
    /* 9D9EC 0019D9EC 00FC6334 */  ori        $3, $3, (0xFFC00 & 0xFFFF)
    /* 9D9F0 0019D9F0 2418A300 */  and        $3, $5, $3
    /* 9D9F4 0019D9F4 83220300 */  sra        $4, $3, 10
    /* 9D9F8 0019D9F8 01000324 */  addiu      $3, $0, 0x1
    /* 9D9FC 0019D9FC 48008314 */  bne        $4, $3, .L0019DB20
    /* 9DA00 0019DA00 00000000 */   nop
    /* 9DA04 0019DA04 B09D828F */  lw         $2, -0x6250($28)
    /* 9DA08 0019DA08 0800448C */  lw         $4, 0x8($2)
    /* 9DA0C 0019DA0C 4C1D050C */  jal        func_00147530
    /* 9DA10 0019DA10 00000000 */   nop
    /* 9DA14 0019DA14 2800448C */  lw         $4, 0x28($2)
    /* 9DA18 0019DA18 FFFB033C */  lui        $3, (0xFBFFFFFF >> 16)
    /* 9DA1C 0019DA1C FFFF6334 */  ori        $3, $3, (0xFBFFFFFF & 0xFFFF)
    /* 9DA20 0019DA20 24188300 */  and        $3, $4, $3
    /* 9DA24 0019DA24 280043AC */  sw         $3, 0x28($2)
    /* 9DA28 0019DA28 3D000010 */  b          .L0019DB20
    /* 9DA2C 0019DA2C 00000000 */   nop
    /* 9DA30 0019DA30 000A048E */  lw         $4, 0xA00($16)
    /* 9DA34 0019DA34 0CEA110C */  jal        func_0047a830
    /* 9DA38 0019DA38 00000000 */   nop
    /* 9DA3C 0019DA3C 000A048E */  lw         $4, 0xA00($16)
    /* 9DA40 0019DA40 60028390 */  lbu        $3, 0x260($4)
    /* 9DA44 0019DA44 E2006330 */  andi       $3, $3, 0xE2
    /* 9DA48 0019DA48 600283A0 */  sb         $3, 0x260($4)
    /* 9DA4C 0019DA4C 34000010 */  b          .L0019DB20
    /* 9DA50 0019DA50 00000000 */   nop
    /* 9DA54 0019DA54 000A048E */  lw         $4, 0xA00($16)
    /* 9DA58 0019DA58 1CEA110C */  jal        func_0047a870
    /* 9DA5C 0019DA5C 00000000 */   nop
    /* 9DA60 0019DA60 2F000010 */  b          .L0019DB20
    /* 9DA64 0019DA64 00000000 */   nop
    /* 9DA68 0019DA68 000A048E */  lw         $4, 0xA00($16)
    /* 9DA6C 0019DA6C 3C808CC7 */  lwc1       $f12, -0x7FC4($28)
    /* 9DA70 0019DA70 24EA110C */  jal        func_0047a890
    /* 9DA74 0019DA74 00000000 */   nop
    /* 9DA78 0019DA78 8C42023C */  lui        $2, (0x428C0000 >> 16)
    /* 9DA7C 0019DA7C 00608244 */  mtc1       $2, $f12
    /* 9DA80 0019DA80 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 9DA84 0019DA84 00688244 */  mtc1       $2, $f13
    /* 9DA88 0019DA88 000A048E */  lw         $4, 0xA00($16)
    /* 9DA8C 0019DA8C 28EA110C */  jal        func_0047a8a0
    /* 9DA90 0019DA90 00000000 */   nop
    /* 9DA94 0019DA94 000A048E */  lw         $4, 0xA00($16)
    /* 9DA98 0019DA98 6CEA110C */  jal        func_0047a9b0
    /* 9DA9C 0019DA9C 00000000 */   nop
    /* 9DAA0 0019DAA0 000A048E */  lw         $4, 0xA00($16)
    /* 9DAA4 0019DAA4 64EA110C */  jal        func_0047a990
    /* 9DAA8 0019DAA8 00000000 */   nop
    /* 9DAAC 0019DAAC 000A048E */  lw         $4, 0xA00($16)
    /* 9DAB0 0019DAB0 80EA110C */  jal        func_0047aa00
    /* 9DAB4 0019DAB4 00000000 */   nop
    /* 9DAB8 0019DAB8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 9DABC 0019DABC FFDF0224 */  addiu      $2, $0, -0x2001
    /* 9DAC0 0019DAC0 24106200 */  and        $2, $3, $2
    /* 9DAC4 0019DAC4 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* 9DAC8 0019DAC8 000A048E */  lw         $4, 0xA00($16)
    /* 9DACC 0019DACC 7CEA110C */  jal        func_0047a9f0
    /* 9DAD0 0019DAD0 00000000 */   nop
    /* 9DAD4 0019DAD4 000A048E */  lw         $4, 0xA00($16)
    /* 9DAD8 0019DAD8 80EA110C */  jal        func_0047aa00
    /* 9DADC 0019DADC 00000000 */   nop
    /* 9DAE0 0019DAE0 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 9DAE4 0019DAE4 FFEF0224 */  addiu      $2, $0, -0x1001
    /* 9DAE8 0019DAE8 24106200 */  and        $2, $3, $2
    /* 9DAEC 0019DAEC FFFF4530 */  andi       $5, $2, 0xFFFF
    /* 9DAF0 0019DAF0 000A048E */  lw         $4, 0xA00($16)
    /* 9DAF4 0019DAF4 7CEA110C */  jal        func_0047a9f0
    /* 9DAF8 0019DAF8 00000000 */   nop
    /* 9DAFC 0019DAFC B00000A6 */  sh         $0, 0xB0($16)
    /* 9DB00 0019DB00 07000010 */  b          .L0019DB20
    /* 9DB04 0019DB04 00000000 */   nop
    /* 9DB08 0019DB08 000A048E */  lw         $4, 0xA00($16)
    /* 9DB0C 0019DB0C E0028394 */  lhu        $3, 0x2E0($4)
    /* 9DB10 0019DB10 EFFF6330 */  andi       $3, $3, 0xFFEF
    /* 9DB14 0019DB14 E00283A4 */  sh         $3, 0x2E0($4)
    /* 9DB18 0019DB18 000A038E */  lw         $3, 0xA00($16)
    /* 9DB1C 0019DB1C DC0260AC */  sw         $0, 0x2DC($3)
  .L0019DB20:
    /* 9DB20 0019DB20 1000BFDF */  ld         $31, 0x10($29)
    /* 9DB24 0019DB24 0000B07B */  lq         $16, 0x0($29)
    /* 9DB28 0019DB28 2000BD27 */  addiu      $29, $29, 0x20
    /* 9DB2C 0019DB2C 0800E003 */  jr         $31
    /* 9DB30 0019DB30 00000000 */   nop
    /* 9DB34 0019DB34 00000000 */  nop
    /* 9DB38 0019DB38 00000000 */  nop
    /* 9DB3C 0019DB3C 00000000 */  nop
.size func_0019d990, 0x1b0

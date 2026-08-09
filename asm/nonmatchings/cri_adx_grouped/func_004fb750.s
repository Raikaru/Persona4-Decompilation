.section .text
.set noat
.set noreorder
glabel func_004fb750
    /* 3FB750 004FB750 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FB754 004FB754 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB758 004FB758 2D808000 */  daddu      $16, $4, $0
    /* 3FB75C 004FB75C 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB760 004FB760 1000BFFF */  sd         $31, 0x10($29)
    /* 3FB764 004FB764 1E04140C */  jal        func_00501078
    /* 3FB768 004FB768 2D88A000 */   daddu     $17, $5, $0
    /* 3FB76C 004FB76C 08004010 */  beqz       $2, .L004FB790
    /* 3FB770 004FB770 2D200000 */   daddu     $4, $0, $0
    /* 3FB774 004FB774 03FF053C */  lui        $5, (0xFF03020C >> 16)
    /* 3FB778 004FB778 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB77C 004FB77C 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB780 004FB780 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB784 004FB784 0C02A534 */  ori        $5, $5, (0xFF03020C & 0xFFFF)
    /* 3FB788 004FB788 82ED1308 */  j          func_004fb608
    /* 3FB78C 004FB78C 2000BD27 */   addiu     $29, $29, 0x20
  .L004FB790:
    /* 3FB790 004FB790 2D282002 */  daddu      $5, $17, $0
    /* 3FB794 004FB794 58000326 */  addiu      $3, $16, 0x58
    /* 3FB798 004FB798 25106500 */  or         $2, $3, $5
    /* 3FB79C 004FB79C 07004230 */  andi       $2, $2, 0x7
    /* 3FB7A0 004FB7A0 19004010 */  beqz       $2, .L004FB808
    /* 3FB7A4 004FB7A4 D8000426 */   addiu     $4, $16, 0xD8
  .L004FB7A8:
    /* 3FB7A8 004FB7A8 07006268 */  ldl        $2, 0x7($3)
    /* 3FB7AC 004FB7AC 0000626C */  ldr        $2, 0x0($3)
    /* 3FB7B0 004FB7B0 0F006668 */  ldl        $6, 0xF($3)
    /* 3FB7B4 004FB7B4 0800666C */  ldr        $6, 0x8($3)
    /* 3FB7B8 004FB7B8 17006768 */  ldl        $7, 0x17($3)
    /* 3FB7BC 004FB7BC 1000676C */  ldr        $7, 0x10($3)
    /* 3FB7C0 004FB7C0 1F006868 */  ldl        $8, 0x1F($3)
    /* 3FB7C4 004FB7C4 1800686C */  ldr        $8, 0x18($3)
    /* 3FB7C8 004FB7C8 0700A2B0 */  sdl        $2, 0x7($5)
    /* 3FB7CC 004FB7CC 0000A2B4 */  sdr        $2, 0x0($5)
    /* 3FB7D0 004FB7D0 0F00A6B0 */  sdl        $6, 0xF($5)
    /* 3FB7D4 004FB7D4 0800A6B4 */  sdr        $6, 0x8($5)
    /* 3FB7D8 004FB7D8 1700A7B0 */  sdl        $7, 0x17($5)
    /* 3FB7DC 004FB7DC 1000A7B4 */  sdr        $7, 0x10($5)
    /* 3FB7E0 004FB7E0 1F00A8B0 */  sdl        $8, 0x1F($5)
    /* 3FB7E4 004FB7E4 1800A8B4 */  sdr        $8, 0x18($5)
    /* 3FB7E8 004FB7E8 20006324 */  addiu      $3, $3, 0x20
    /* 3FB7EC 004FB7EC 00000000 */  nop
    /* 3FB7F0 004FB7F0 00000000 */  nop
    /* 3FB7F4 004FB7F4 ECFF6414 */  bne        $3, $4, .L004FB7A8
    /* 3FB7F8 004FB7F8 2000A524 */   addiu     $5, $5, 0x20
    /* 3FB7FC 004FB7FC 10000010 */  b          .L004FB840
    /* 3FB800 004FB800 0000B0DF */   ld        $16, 0x0($29)
    /* 3FB804 004FB804 00000000 */  nop
  .L004FB808:
    /* 3FB808 004FB808 000062DC */  ld         $2, 0x0($3)
    /* 3FB80C 004FB80C 080066DC */  ld         $6, 0x8($3)
    /* 3FB810 004FB810 100067DC */  ld         $7, 0x10($3)
    /* 3FB814 004FB814 180068DC */  ld         $8, 0x18($3)
    /* 3FB818 004FB818 0000A2FC */  sd         $2, 0x0($5)
    /* 3FB81C 004FB81C 0800A6FC */  sd         $6, 0x8($5)
    /* 3FB820 004FB820 1000A7FC */  sd         $7, 0x10($5)
    /* 3FB824 004FB824 1800A8FC */  sd         $8, 0x18($5)
    /* 3FB828 004FB828 20006324 */  addiu      $3, $3, 0x20
    /* 3FB82C 004FB82C 00000000 */  nop
    /* 3FB830 004FB830 00000000 */  nop
    /* 3FB834 004FB834 F4FF6414 */  bne        $3, $4, .L004FB808
    /* 3FB838 004FB838 2000A524 */   addiu     $5, $5, 0x20
    /* 3FB83C 004FB83C 0000B0DF */  ld         $16, 0x0($29)
  .L004FB840:
    /* 3FB840 004FB840 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB844 004FB844 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB848 004FB848 0800E003 */  jr         $31
    /* 3FB84C 004FB84C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004fb750, 0x100

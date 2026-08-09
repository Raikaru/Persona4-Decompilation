.section .text
.set noat
.set noreorder
glabel func_001fa7a0
    /* FA7A0 001FA7A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FA7A4 001FA7A4 2000BFFF */  sd         $31, 0x20($29)
    /* FA7A8 001FA7A8 1000B17F */  sq         $17, 0x10($29)
    /* FA7AC 001FA7AC 0000B07F */  sq         $16, 0x0($29)
    /* FA7B0 001FA7B0 2D808000 */  daddu      $16, $4, $0
    /* FA7B4 001FA7B4 ACB3848F */  lw         $4, -0x4C54($28)
    /* FA7B8 001FA7B8 7C0B8394 */  lhu        $3, 0xB7C($4)
    /* FA7BC 001FA7BC 05000224 */  addiu      $2, $0, 0x5
    /* FA7C0 001FA7C0 0E006214 */  bne        $3, $2, .L001FA7FC
    /* FA7C4 001FA7C4 00000000 */   nop
    /* FA7C8 001FA7C8 880B848C */  lw         $4, 0xB88($4)
    /* FA7CC 001FA7CC 04008014 */  bnez       $4, .L001FA7E0
    /* FA7D0 001FA7D0 00000000 */   nop
    /* FA7D4 001FA7D4 01000224 */  addiu      $2, $0, 0x1
    /* FA7D8 001FA7D8 3C000010 */  b          .L001FA8CC
    /* FA7DC 001FA7DC 00000000 */   nop
  .L001FA7E0:
    /* FA7E0 001FA7E0 0000028E */  lw         $2, 0x0($16)
    /* FA7E4 001FA7E4 38004014 */  bnez       $2, .L001FA8C8
    /* FA7E8 001FA7E8 00000000 */   nop
    /* FA7EC 001FA7EC C083040C */  jal        func_00120f00
    /* FA7F0 001FA7F0 00000000 */   nop
    /* FA7F4 001FA7F4 34000010 */  b          .L001FA8C8
    /* FA7F8 001FA7F8 00000000 */   nop
  .L001FA7FC:
    /* FA7FC 001FA7FC 800B848C */  lw         $4, 0xB80($4)
    /* FA800 001FA800 04008014 */  bnez       $4, .L001FA814
    /* FA804 001FA804 00000000 */   nop
    /* FA808 001FA808 01000224 */  addiu      $2, $0, 0x1
    /* FA80C 001FA80C 2F000010 */  b          .L001FA8CC
    /* FA810 001FA810 00000000 */   nop
  .L001FA814:
    /* FA814 001FA814 48C5120C */  jal        func_004b1520
    /* FA818 001FA818 00000000 */   nop
    /* FA81C 001FA81C 21004014 */  bnez       $2, .L001FA8A4
    /* FA820 001FA820 00000000 */   nop
    /* FA824 001FA824 0000028E */  lw         $2, 0x0($16)
    /* FA828 001FA828 07004014 */  bnez       $2, .L001FA848
    /* FA82C 001FA82C 00000000 */   nop
    /* FA830 001FA830 01000424 */  addiu      $4, $0, 0x1
    /* FA834 001FA834 0E000524 */  addiu      $5, $0, 0xE
    /* FA838 001FA838 02000624 */  addiu      $6, $0, 0x2
    /* FA83C 001FA83C 10000724 */  addiu      $7, $0, 0x10
    /* FA840 001FA840 D86B110C */  jal        func_0045af60
    /* FA844 001FA844 00000000 */   nop
  .L001FA848:
    /* FA848 001FA848 1405120C */  jal        func_00481450
    /* FA84C 001FA84C 00000000 */   nop
    /* FA850 001FA850 2D884000 */  daddu      $17, $2, $0
    /* FA854 001FA854 5E00043C */  lui        $4, %hi(D_005DC8CC)
    /* FA858 001FA858 CCC88424 */  addiu      $4, $4, %lo(D_005DC8CC)
    /* FA85C 001FA85C 1005120C */  jal        func_00481440
    /* FA860 001FA860 00000000 */   nop
    /* FA864 001FA864 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA868 001FA868 800B448C */  lw         $4, 0xB80($2)
    /* FA86C 001FA86C 8C15120C */  jal        func_00485630
    /* FA870 001FA870 00000000 */   nop
    /* FA874 001FA874 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA878 001FA878 800B448C */  lw         $4, 0xB80($2)
    /* FA87C 001FA87C 1C16120C */  jal        func_00485870
    /* FA880 001FA880 00000000 */   nop
    /* FA884 001FA884 2D202002 */  daddu      $4, $17, $0
    /* FA888 001FA888 1005120C */  jal        func_00481440
    /* FA88C 001FA88C 00000000 */   nop
    /* FA890 001FA890 0000028E */  lw         $2, 0x0($16)
    /* FA894 001FA894 01004224 */  addiu      $2, $2, 0x1
    /* FA898 001FA898 000002AE */  sw         $2, 0x0($16)
    /* FA89C 001FA89C 0A000010 */  b          .L001FA8C8
    /* FA8A0 001FA8A0 00000000 */   nop
  .L001FA8A4:
    /* FA8A4 001FA8A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA8A8 001FA8A8 800B448C */  lw         $4, 0xB80($2)
    /* FA8AC 001FA8AC C816120C */  jal        func_00485b20
    /* FA8B0 001FA8B0 00000000 */   nop
    /* FA8B4 001FA8B4 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA8B8 001FA8B8 800B40AC */  sw         $0, 0xB80($2)
    /* FA8BC 001FA8BC 01000224 */  addiu      $2, $0, 0x1
    /* FA8C0 001FA8C0 02000010 */  b          .L001FA8CC
    /* FA8C4 001FA8C4 00000000 */   nop
  .L001FA8C8:
    /* FA8C8 001FA8C8 2D100000 */  daddu      $2, $0, $0
  .L001FA8CC:
    /* FA8CC 001FA8CC 2000BFDF */  ld         $31, 0x20($29)
    /* FA8D0 001FA8D0 1000B17B */  lq         $17, 0x10($29)
    /* FA8D4 001FA8D4 0000B07B */  lq         $16, 0x0($29)
    /* FA8D8 001FA8D8 3000BD27 */  addiu      $29, $29, 0x30
    /* FA8DC 001FA8DC 0800E003 */  jr         $31
    /* FA8E0 001FA8E0 00000000 */   nop
    /* FA8E4 001FA8E4 00000000 */  nop
    /* FA8E8 001FA8E8 00000000 */  nop
    /* FA8EC 001FA8EC 00000000 */  nop
.size func_001fa7a0, 0x150

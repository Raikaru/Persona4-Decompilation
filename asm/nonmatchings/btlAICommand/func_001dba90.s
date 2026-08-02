.section .text
.set noat
.set noreorder
glabel func_001dba90
    /* DBA90 001DBA90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DBA94 001DBA94 0000BFFF */  sd         $31, 0x0($29)
    /* DBA98 001DBA98 3000828C */  lw         $2, 0x30($4)
    /* DBA9C 001DBA9C A2004290 */  lbu        $2, 0xA2($2)
    /* DBAA0 001DBAA0 04004014 */  bnez       $2, .L001DBAB4
    /* DBAA4 001DBAA4 00000000 */   nop
    /* DBAA8 001DBAA8 01000224 */  addiu      $2, $0, 0x1
    /* DBAAC 001DBAAC 02000010 */  b          .L001DBAB8
    /* DBAB0 001DBAB0 00000000 */   nop
  .L001DBAB4:
    /* DBAB4 001DBAB4 2D100000 */  daddu      $2, $0, $0
  .L001DBAB8:
    /* DBAB8 001DBAB8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DBABC 001DBABC 01000224 */  addiu      $2, $0, 0x1
    /* DBAC0 001DBAC0 04106200 */  sllv       $2, $2, $3
    /* DBAC4 001DBAC4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DBAC8 001DBAC8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DBACC 001DBACC 0A000824 */  addiu      $8, $0, 0xA
    /* DBAD0 001DBAD0 1E00093C */  lui        $9, %hi(func_001db9f0)
    /* DBAD4 001DBAD4 F0B92925 */  addiu      $9, $9, %lo(func_001db9f0)
    /* DBAD8 001DBAD8 3465070C */  jal        func_001d94d0
    /* DBADC 001DBADC 00000000 */   nop
    /* DBAE0 001DBAE0 0000BFDF */  ld         $31, 0x0($29)
    /* DBAE4 001DBAE4 1000BD27 */  addiu      $29, $29, 0x10
    /* DBAE8 001DBAE8 0800E003 */  jr         $31
    /* DBAEC 001DBAEC 00000000 */   nop
.size func_001dba90, 0x60

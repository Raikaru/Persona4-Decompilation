.section .text
.set noat
.set noreorder
glabel func_004beaa0
    /* 3BEAA0 004BEAA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEAA4 004BEAA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BEAA8 004BEAA8 2D808000 */  daddu      $16, $4, $0
    /* 3BEAAC 004BEAAC 0800BFFF */  sd         $31, 0x8($29)
    /* 3BEAB0 004BEAB0 5000028E */  lw         $2, 0x50($16)
    /* 3BEAB4 004BEAB4 08004054 */  bnel       $2, $0, .L004BEAD8
    /* 3BEAB8 004BEAB8 3400048E */   lw        $4, 0x34($16)
    /* 3BEABC 004BEABC 7500043C */  lui        $4, %hi(D_00756D80)
    /* 3BEAC0 004BEAC0 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEAC4 004BEAC4 0800BFDF */  ld         $31, 0x8($29)
    /* 3BEAC8 004BEAC8 806D8424 */  addiu      $4, $4, %lo(D_00756D80)
    /* 3BEACC 004BEACC A8F51208 */  j          func_004bd6a0
    /* 3BEAD0 004BEAD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEAD4 004BEAD4 00000000 */  nop
  .L004BEAD8:
    /* 3BEAD8 004BEAD8 00010624 */  addiu      $6, $0, 0x100
    /* 3BEADC 004BEADC 7A0B110C */  jal        func_00442de8
    /* 3BEAE0 004BEAE0 300000AE */   sw        $0, 0x30($16)
    /* 3BEAE4 004BEAE4 2D200002 */  daddu      $4, $16, $0
    /* 3BEAE8 004BEAE8 0800BFDF */  ld         $31, 0x8($29)
    /* 3BEAEC 004BEAEC 30008524 */  addiu      $5, $4, 0x30
    /* 3BEAF0 004BEAF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEAF4 004BEAF4 28FF1208 */  j          func_004bfca0
    /* 3BEAF8 004BEAF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEAFC 004BEAFC 00000000 */  nop
.size func_004beaa0, 0x60

.section .text
.set noat
.set noreorder
glabel func_004beec8
    /* 3BEEC8 004BEEC8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BEECC 004BEECC 0000B0FF */  sd         $16, 0x0($29)
    /* 3BEED0 004BEED0 1000B2FF */  sd         $18, 0x10($29)
    /* 3BEED4 004BEED4 2D908000 */  daddu      $18, $4, $0
    /* 3BEED8 004BEED8 0800B1FF */  sd         $17, 0x8($29)
    /* 3BEEDC 004BEEDC 1800B3FF */  sd         $19, 0x18($29)
    /* 3BEEE0 004BEEE0 2000BFFF */  sd         $31, 0x20($29)
    /* 3BEEE4 004BEEE4 5000428E */  lw         $2, 0x50($18)
    /* 3BEEE8 004BEEE8 0B004014 */  bnez       $2, .L004BEF18
    /* 3BEEEC 004BEEEC 2D80A000 */   daddu     $16, $5, $0
    /* 3BEEF0 004BEEF0 7500043C */  lui        $4, %hi(D_00756F48)
    /* 3BEEF4 004BEEF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEEF8 004BEEF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3BEEFC 004BEEFC 486F8424 */  addiu      $4, $4, %lo(D_00756F48)
    /* 3BEF00 004BEF00 1000B2DF */  ld         $18, 0x10($29)
    /* 3BEF04 004BEF04 1800B3DF */  ld         $19, 0x18($29)
    /* 3BEF08 004BEF08 2000BFDF */  ld         $31, 0x20($29)
    /* 3BEF0C 004BEF0C A8F51208 */  j          func_004bd6a0
    /* 3BEF10 004BEF10 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BEF14 004BEF14 00000000 */  nop
  .L004BEF18:
    /* 3BEF18 004BEF18 96F5120C */  jal        func_004bd658
    /* 3BEF1C 004BEF1C 00000000 */   nop
    /* 3BEF20 004BEF20 01000524 */  addiu      $5, $0, 0x1
    /* 3BEF24 004BEF24 1000438E */  lw         $3, 0x10($18)
    /* 3BEF28 004BEF28 01000624 */  addiu      $6, $0, 0x1
    /* 3BEF2C 004BEF2C BC0050AE */  sw         $16, 0xBC($18)
    /* 3BEF30 004BEF30 40100300 */  sll        $2, $3, 1
    /* 3BEF34 004BEF34 21104300 */  addu       $2, $2, $3
    /* 3BEF38 004BEF38 80100200 */  sll        $2, $2, 2
    /* 3BEF3C 004BEF3C 21104202 */  addu       $2, $18, $2
    /* 3BEF40 004BEF40 18005324 */  addiu      $19, $2, 0x18
    /* 3BEF44 004BEF44 04006382 */  lb         $3, 0x4($19)
    /* 3BEF48 004BEF48 19006610 */  beq        $3, $6, .L004BEFB0
    /* 3BEF4C 004BEF4C 2D204002 */   daddu     $4, $18, $0
    /* 3BEF50 004BEF50 7000130C */  jal        func_004c01c0
    /* 3BEF54 004BEF54 00000000 */   nop
    /* 3BEF58 004BEF58 2D380000 */  daddu      $7, $0, $0
    /* 3BEF5C 004BEF5C 0800718E */  lw         $17, 0x8($19)
    /* 3BEF60 004BEF60 2D280002 */  daddu      $5, $16, $0
    /* 3BEF64 004BEF64 B800488E */  lw         $8, 0xB8($18)
    /* 3BEF68 004BEF68 4C00103C */  lui        $16, %hi(func_004c0658)
    /* 3BEF6C 004BEF6C B000468E */  lw         $6, 0xB0($18)
    /* 3BEF70 004BEF70 2D202002 */  daddu      $4, $17, $0
    /* 3BEF74 004BEF74 E4F5120C */  jal        func_004bd790
    /* 3BEF78 004BEF78 58061026 */   addiu     $16, $16, %lo(func_004c0658)
    /* 3BEF7C 004BEF7C 02000724 */  addiu      $7, $0, 0x2
    /* 3BEF80 004BEF80 2D202002 */  daddu      $4, $17, $0
    /* 3BEF84 004BEF84 2D280002 */  daddu      $5, $16, $0
    /* 3BEF88 004BEF88 76F6120C */  jal        func_004bd9d8
    /* 3BEF8C 004BEF8C 2D304002 */   daddu     $6, $18, $0
    /* 3BEF90 004BEF90 2D202002 */  daddu      $4, $17, $0
    /* 3BEF94 004BEF94 2D280002 */  daddu      $5, $16, $0
    /* 3BEF98 004BEF98 2D304002 */  daddu      $6, $18, $0
    /* 3BEF9C 004BEF9C 7AF6120C */  jal        func_004bd9e8
    /* 3BEFA0 004BEFA0 05000724 */   addiu     $7, $0, 0x5
    /* 3BEFA4 004BEFA4 03000224 */  addiu      $2, $0, 0x3
    /* 3BEFA8 004BEFA8 040062A2 */  sb         $2, 0x4($19)
    /* 3BEFAC 004BEFAC 050060A2 */  sb         $0, 0x5($19)
  .L004BEFB0:
    /* 3BEFB0 004BEFB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEFB4 004BEFB4 0800B1DF */  ld         $17, 0x8($29)
    /* 3BEFB8 004BEFB8 1000B2DF */  ld         $18, 0x10($29)
    /* 3BEFBC 004BEFBC 1800B3DF */  ld         $19, 0x18($29)
    /* 3BEFC0 004BEFC0 2000BFDF */  ld         $31, 0x20($29)
    /* 3BEFC4 004BEFC4 9CF51208 */  j          func_004bd670
    /* 3BEFC8 004BEFC8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BEFCC 004BEFCC 00000000 */  nop
.size func_004beec8, 0x108

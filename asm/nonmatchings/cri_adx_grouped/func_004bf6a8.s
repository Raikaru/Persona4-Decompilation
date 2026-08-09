.section .text
.set noat
.set noreorder
glabel func_004bf6a8
    /* 3BF6A8 004BF6A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF6AC 004BF6AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF6B0 004BF6B0 5000828C */  lw         $2, 0x50($4)
    /* 3BF6B4 004BF6B4 06004054 */  bnel       $2, $0, .L004BF6D0
    /* 3BF6B8 004BF6B8 9400838C */   lw        $3, 0x94($4)
    /* 3BF6BC 004BF6BC 7500043C */  lui        $4, %hi(D_007571E8)
    /* 3BF6C0 004BF6C0 A8F5120C */  jal        func_004bd6a0
    /* 3BF6C4 004BF6C4 E8718424 */   addiu     $4, $4, %lo(D_007571E8)
    /* 3BF6C8 004BF6C8 10000010 */  b          .L004BF70C
    /* 3BF6CC 004BF6CC 2D100000 */   daddu     $2, $0, $0
  .L004BF6D0:
    /* 3BF6D0 004BF6D0 0E006010 */  beqz       $3, .L004BF70C
    /* 3BF6D4 004BF6D4 2D100000 */   daddu     $2, $0, $0
    /* 3BF6D8 004BF6D8 0D00A004 */  bltz       $5, .L004BF710
    /* 3BF6DC 004BF6DC 0000BFDF */   ld        $31, 0x0($29)
    /* 3BF6E0 004BF6E0 A000828C */  lw         $2, 0xA0($4)
    /* 3BF6E4 004BF6E4 2A10A200 */  slt        $2, $5, $2
    /* 3BF6E8 004BF6E8 09004010 */  beqz       $2, .L004BF710
    /* 3BF6EC 004BF6EC 2D100000 */   daddu     $2, $0, $0
    /* 3BF6F0 004BF6F0 80100500 */  sll        $2, $5, 2
    /* 3BF6F4 004BF6F4 21108200 */  addu       $2, $4, $2
    /* 3BF6F8 004BF6F8 0000448C */  lw         $4, 0x0($2)
    /* 3BF6FC 004BF6FC 0000838C */  lw         $3, 0x0($4)
    /* 3BF700 004BF700 3C00628C */  lw         $2, 0x3C($3)
    /* 3BF704 004BF704 09F84000 */  jalr       $2
    /* 3BF708 004BF708 00000000 */   nop
  .L004BF70C:
    /* 3BF70C 004BF70C 0000BFDF */  ld         $31, 0x0($29)
  .L004BF710:
    /* 3BF710 004BF710 0800E003 */  jr         $31
    /* 3BF714 004BF714 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bf6a8, 0x70

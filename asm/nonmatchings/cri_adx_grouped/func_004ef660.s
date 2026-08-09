.section .text
.set noat
.set noreorder
glabel func_004ef660
    /* 3EF660 004EF660 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EF664 004EF664 06008014 */  bnez       $4, .L004EF680
    /* 3EF668 004EF668 1000BFFF */   sd        $31, 0x10($29)
    /* 3EF66C 004EF66C 7600043C */  lui        $4, %hi(D_0075D028)
    /* 3EF670 004EF670 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF674 004EF674 28D08424 */  addiu      $4, $4, %lo(D_0075D028)
    /* 3EF678 004EF678 08000010 */  b          .L004EF69C
    /* 3EF67C 004EF67C F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
  .L004EF680:
    /* 3EF680 004EF680 04008280 */  lb         $2, 0x4($4)
    /* 3EF684 004EF684 0A004054 */  bnel       $2, $0, .L004EF6B0
    /* 3EF688 004EF688 0400A22C */   sltiu     $2, $5, 0x4
    /* 3EF68C 004EF68C 7600043C */  lui        $4, %hi(D_0075D038)
    /* 3EF690 004EF690 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF694 004EF694 38D08424 */  addiu      $4, $4, %lo(D_0075D038)
    /* 3EF698 004EF698 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
  .L004EF69C:
    /* 3EF69C 004EF69C B6BA130C */  jal        func_004eead8
    /* 3EF6A0 004EF6A0 00000000 */   nop
    /* 3EF6A4 004EF6A4 1D000010 */  b          .L004EF71C
    /* 3EF6A8 004EF6A8 2D100000 */   daddu     $2, $0, $0
    /* 3EF6AC 004EF6AC 00000000 */  nop
  .L004EF6B0:
    /* 3EF6B0 004EF6B0 09004014 */  bnez       $2, .L004EF6D8
    /* 3EF6B4 004EF6B4 0000E0AC */   sw        $0, 0x0($7)
    /* 3EF6B8 004EF6B8 2800828C */  lw         $2, 0x28($4)
    /* 3EF6BC 004EF6BC 17004050 */  beql       $2, $0, .L004EF71C
    /* 3EF6C0 004EF6C0 2D100000 */   daddu     $2, $0, $0
    /* 3EF6C4 004EF6C4 2C00848C */  lw         $4, 0x2C($4)
    /* 3EF6C8 004EF6C8 09F84000 */  jalr       $2
    /* 3EF6CC 004EF6CC FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EF6D0 004EF6D0 12000010 */  b          .L004EF71C
    /* 3EF6D4 004EF6D4 2D100000 */   daddu     $2, $0, $0
  .L004EF6D8:
    /* 3EF6D8 004EF6D8 80180500 */  sll        $3, $5, 2
    /* 3EF6DC 004EF6DC 21186400 */  addu       $3, $3, $4
    /* 3EF6E0 004EF6E0 1800638C */  lw         $3, 0x18($3)
    /* 3EF6E4 004EF6E4 0D006010 */  beqz       $3, .L004EF71C
    /* 3EF6E8 004EF6E8 2D100000 */   daddu     $2, $0, $0
    /* 3EF6EC 004EF6EC 0F006268 */  ldl        $2, 0xF($3)
    /* 3EF6F0 004EF6F0 0800626C */  ldr        $2, 0x8($3)
    /* 3EF6F4 004EF6F4 0700A2B3 */  sdl        $2, 0x7($29)
    /* 3EF6F8 004EF6F8 0000A2B7 */  sdr        $2, 0x0($29)
    /* 3EF6FC 004EF6FC 01000324 */  addiu      $3, $0, 0x1
    /* 3EF700 004EF700 0400A58F */  lw         $5, 0x4($29)
    /* 3EF704 004EF704 0000E5AC */  sw         $5, 0x0($7)
    /* 3EF708 004EF708 05008280 */  lb         $2, 0x5($4)
    /* 3EF70C 004EF70C 02004354 */  bnel       $2, $3, .L004EF718
    /* 3EF710 004EF710 2610A600 */   xor       $2, $5, $6
    /* 3EF714 004EF714 2A10A600 */  slt        $2, $5, $6
  .L004EF718:
    /* 3EF718 004EF718 0100422C */  sltiu      $2, $2, 0x1
  .L004EF71C:
    /* 3EF71C 004EF71C 1000BFDF */  ld         $31, 0x10($29)
    /* 3EF720 004EF720 0800E003 */  jr         $31
    /* 3EF724 004EF724 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ef660, 0xc8

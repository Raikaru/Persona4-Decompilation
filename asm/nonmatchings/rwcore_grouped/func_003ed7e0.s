.section .text
.set noat
.set noreorder
glabel func_003ed7e0
    /* 2ED7E0 003ED7E0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2ED7E4 003ED7E4 2000BFFF */  sd         $31, 0x20($29)
    /* 2ED7E8 003ED7E8 1000B17F */  sq         $17, 0x10($29)
    /* 2ED7EC 003ED7EC 0000B07F */  sq         $16, 0x0($29)
    /* 2ED7F0 003ED7F0 8800103C */  lui        $16, %hi(D_0088739C)
    /* 2ED7F4 003ED7F4 9C731026 */  addiu      $16, $16, %lo(D_0088739C)
    /* 2ED7F8 003ED7F8 0000118E */  lw         $17, 0x0($16)
    /* 2ED7FC 003ED7FC 08003012 */  beq        $17, $16, .L003ED820
    /* 2ED800 003ED800 00000000 */   nop
  .L003ED804:
    /* 2ED804 003ED804 94B50F0C */  jal        func_003ed650
    /* 2ED808 003ED808 F8FF2426 */   addiu     $4, $17, -0x8
    /* 2ED80C 003ED80C 0000318E */  lw         $17, 0x0($17)
    /* 2ED810 003ED810 00000000 */  nop
    /* 2ED814 003ED814 00000000 */  nop
    /* 2ED818 003ED818 FAFF3016 */  bne        $17, $16, .L003ED804
    /* 2ED81C 003ED81C 00000000 */   nop
  .L003ED820:
    /* 2ED820 003ED820 8800033C */  lui        $3, %hi(D_008873A0)
    /* 2ED824 003ED824 000010AE */  sw         $16, 0x0($16)
    /* 2ED828 003ED828 01000224 */  addiu      $2, $0, 0x1
    /* 2ED82C 003ED82C A07370AC */  sw         $16, %lo(D_008873A0)($3)
    /* 2ED830 003ED830 2000BFDF */  ld         $31, 0x20($29)
    /* 2ED834 003ED834 1000B17B */  lq         $17, 0x10($29)
    /* 2ED838 003ED838 0000B07B */  lq         $16, 0x0($29)
    /* 2ED83C 003ED83C 0800E003 */  jr         $31
    /* 2ED840 003ED840 3000BD27 */   addiu     $29, $29, 0x30
    /* 2ED844 003ED844 00000000 */  nop
    /* 2ED848 003ED848 00000000 */  nop
    /* 2ED84C 003ED84C 00000000 */  nop
.size func_003ed7e0, 0x70

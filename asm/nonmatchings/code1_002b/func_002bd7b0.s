.section .text
.set noat
.set noreorder
glabel func_002bd7b0
    /* 1BD7B0 002BD7B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BD7B4 002BD7B4 1000BFFF */  sd         $31, 0x10($29)
    /* 1BD7B8 002BD7B8 0000B07F */  sq         $16, 0x0($29)
    /* 1BD7BC 002BD7BC 8800103C */  lui        $16, %hi(D_00882F60)
    /* 1BD7C0 002BD7C0 602F1026 */  addiu      $16, $16, %lo(D_00882F60)
    /* 1BD7C4 002BD7C4 09000012 */  beqz       $16, .L002BD7EC
    /* 1BD7C8 002BD7C8 00000000 */   nop
    /* 1BD7CC 002BD7CC FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BD7D0 002BD7D0 000002AE */  sw         $2, 0x0($16)
    /* 1BD7D4 002BD7D4 040000A2 */  sb         $0, 0x4($16)
    /* 1BD7D8 002BD7D8 050000A2 */  sb         $0, 0x5($16)
    /* 1BD7DC 002BD7DC 080002AE */  sw         $2, 0x8($16)
    /* 1BD7E0 002BD7E0 01000224 */  addiu      $2, $0, 0x1
    /* 1BD7E4 002BD7E4 0C0002A2 */  sb         $2, 0xC($16)
    /* 1BD7E8 002BD7E8 0D0002A2 */  sb         $2, 0xD($16)
  .L002BD7EC:
    /* 1BD7EC 002BD7EC 0000028E */  lw         $2, 0x0($16)
    /* 1BD7F0 002BD7F0 0B004104 */  bgez       $2, .L002BD820
    /* 1BD7F4 002BD7F4 00000000 */   nop
    /* 1BD7F8 002BD7F8 34DD090C */  jal        func_002774d0
    /* 1BD7FC 002BD7FC 00000000 */   nop
    /* 1BD800 002BD800 000002AE */  sw         $2, 0x0($16)
    /* 1BD804 002BD804 2D204000 */  daddu      $4, $2, $0
    /* 1BD808 002BD808 01000524 */  addiu      $5, $0, 0x1
    /* 1BD80C 002BD80C 84E1090C */  jal        func_00278610
    /* 1BD810 002BD810 00000000 */   nop
    /* 1BD814 002BD814 01000224 */  addiu      $2, $0, 0x1
    /* 1BD818 002BD818 02000010 */  b          .L002BD824
    /* 1BD81C 002BD81C 00000000 */   nop
  .L002BD820:
    /* 1BD820 002BD820 2D100000 */  daddu      $2, $0, $0
  .L002BD824:
    /* 1BD824 002BD824 1000BFDF */  ld         $31, 0x10($29)
    /* 1BD828 002BD828 0000B07B */  lq         $16, 0x0($29)
    /* 1BD82C 002BD82C 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BD830 002BD830 0800E003 */  jr         $31
    /* 1BD834 002BD834 00000000 */   nop
    /* 1BD838 002BD838 00000000 */  nop
    /* 1BD83C 002BD83C 00000000 */  nop
.size func_002bd7b0, 0x90

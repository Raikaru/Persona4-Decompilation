.section .text
.set noat
.set noreorder
glabel func_004bd790
    /* 3BD790 004BD790 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BD794 004BD794 0000B0FF */  sd         $16, 0x0($29)
    /* 3BD798 004BD798 2D80A000 */  daddu      $16, $5, $0
    /* 3BD79C 004BD79C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BD7A0 004BD7A0 2D880001 */  daddu      $17, $8, $0
    /* 3BD7A4 004BD7A4 1000B2FF */  sd         $18, 0x10($29)
    /* 3BD7A8 004BD7A8 2D90E000 */  daddu      $18, $7, $0
    /* 3BD7AC 004BD7AC 1800B3FF */  sd         $19, 0x18($29)
    /* 3BD7B0 004BD7B0 2D98C000 */  daddu      $19, $6, $0
    /* 3BD7B4 004BD7B4 2000B4FF */  sd         $20, 0x20($29)
    /* 3BD7B8 004BD7B8 2DA08000 */  daddu      $20, $4, $0
    /* 3BD7BC 004BD7BC 2800BFFF */  sd         $31, 0x28($29)
    /* 3BD7C0 004BD7C0 2D300002 */  daddu      $6, $16, $0
    /* 3BD7C4 004BD7C4 2D386002 */  daddu      $7, $19, $0
    /* 3BD7C8 004BD7C8 2400828E */  lw         $2, 0x24($20)
    /* 3BD7CC 004BD7CC 1C00858E */  lw         $5, 0x1C($20)
    /* 3BD7D0 004BD7D0 240090AE */  sw         $16, 0x24($20)
    /* 3BD7D4 004BD7D4 9AF6120C */  jal        func_004bda68
    /* 3BD7D8 004BD7D8 280082AE */   sw        $2, 0x28($20)
    /* 3BD7DC 004BD7DC 2D208002 */  daddu      $4, $20, $0
    /* 3BD7E0 004BD7E0 2D280002 */  daddu      $5, $16, $0
    /* 3BD7E4 004BD7E4 040082AE */  sw         $2, 0x4($20)
    /* 3BD7E8 004BD7E8 100092AE */  sw         $18, 0x10($20)
    /* 3BD7EC 004BD7EC 140091AE */  sw         $17, 0x14($20)
    /* 3BD7F0 004BD7F0 080080AE */  sw         $0, 0x8($20)
    /* 3BD7F4 004BD7F4 0C00601E */  bgtz       $19, .L004BD828
    /* 3BD7F8 004BD7F8 0C0080AE */   sw        $0, 0xC($20)
    /* 3BD7FC 004BD7FC 02000224 */  addiu      $2, $0, 0x2
    /* 3BD800 004BD800 0000B0DF */  ld         $16, 0x0($29)
    /* 3BD804 004BD804 000082A2 */  sb         $2, 0x0($20)
    /* 3BD808 004BD808 0800B1DF */  ld         $17, 0x8($29)
    /* 3BD80C 004BD80C 1000B2DF */  ld         $18, 0x10($29)
    /* 3BD810 004BD810 1800B3DF */  ld         $19, 0x18($29)
    /* 3BD814 004BD814 2000B4DF */  ld         $20, 0x20($29)
    /* 3BD818 004BD818 2800BFDF */  ld         $31, 0x28($29)
    /* 3BD81C 004BD81C D8F51208 */  j          func_004bd760
    /* 3BD820 004BD820 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BD824 004BD824 00000000 */  nop
  .L004BD828:
    /* 3BD828 004BD828 01000224 */  addiu      $2, $0, 0x1
    /* 3BD82C 004BD82C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BD830 004BD830 000082A2 */  sb         $2, 0x0($20)
    /* 3BD834 004BD834 0800B1DF */  ld         $17, 0x8($29)
    /* 3BD838 004BD838 1000B2DF */  ld         $18, 0x10($29)
    /* 3BD83C 004BD83C 1800B3DF */  ld         $19, 0x18($29)
    /* 3BD840 004BD840 2000B4DF */  ld         $20, 0x20($29)
    /* 3BD844 004BD844 2800BFDF */  ld         $31, 0x28($29)
    /* 3BD848 004BD848 0800E003 */  jr         $31
    /* 3BD84C 004BD84C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004bd790, 0xc0

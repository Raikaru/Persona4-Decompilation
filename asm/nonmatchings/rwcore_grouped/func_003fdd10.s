.section .text
.set noat
.set noreorder
glabel func_003fdd10
    /* 2FDD10 003FDD10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2FDD14 003FDD14 2000BFFF */  sd         $31, 0x20($29)
    /* 2FDD18 003FDD18 1000B17F */  sq         $17, 0x10($29)
    /* 2FDD1C 003FDD1C 0000B07F */  sq         $16, 0x0($29)
    /* 2FDD20 003FDD20 2D888000 */  daddu      $17, $4, $0
    /* 2FDD24 003FDD24 000080AC */  sw         $0, 0x0($4)
    /* 2FDD28 003FDD28 2D80A000 */  daddu      $16, $5, $0
    /* 2FDD2C 003FDD2C 0000828C */  lw         $2, 0x0($4)
    /* 2FDD30 003FDD30 14004224 */  addiu      $2, $2, 0x14
    /* 2FDD34 003FDD34 000082AC */  sw         $2, 0x0($4)
    /* 2FDD38 003FDD38 B4920F0C */  jal        func_003e4ad0
    /* 2FDD3C 003FDD3C 10000426 */   addiu     $4, $16, 0x10
    /* 2FDD40 003FDD40 0C004324 */  addiu      $3, $2, 0xC
    /* 2FDD44 003FDD44 30000426 */  addiu      $4, $16, 0x30
    /* 2FDD48 003FDD48 0000228E */  lw         $2, 0x0($17)
    /* 2FDD4C 003FDD4C 21104300 */  addu       $2, $2, $3
    /* 2FDD50 003FDD50 B4920F0C */  jal        func_003e4ad0
    /* 2FDD54 003FDD54 000022AE */   sw        $2, 0x0($17)
    /* 2FDD58 003FDD58 0000238E */  lw         $3, 0x0($17)
    /* 2FDD5C 003FDD5C 0C004424 */  addiu      $4, $2, 0xC
    /* 2FDD60 003FDD60 4C000624 */  addiu      $6, $0, 0x4C
    /* 2FDD64 003FDD64 01000224 */  addiu      $2, $0, 0x1
    /* 2FDD68 003FDD68 21186400 */  addu       $3, $3, $4
    /* 2FDD6C 003FDD6C 000023AE */  sw         $3, 0x0($17)
    /* 2FDD70 003FDD70 0000058E */  lw         $5, 0x0($16)
    /* 2FDD74 003FDD74 38B9848F */  lw         $4, -0x46C8($28)
    /* 2FDD78 003FDD78 0000238E */  lw         $3, 0x0($17)
    /* 2FDD7C 003FDD7C 2120A400 */  addu       $4, $5, $4
    /* 2FDD80 003FDD80 2800858C */  lw         $5, 0x28($4)
    /* 2FDD84 003FDD84 2C00848C */  lw         $4, 0x2C($4)
    /* 2FDD88 003FDD88 2120A400 */  addu       $4, $5, $4
    /* 2FDD8C 003FDD8C 0C008424 */  addiu      $4, $4, 0xC
    /* 2FDD90 003FDD90 2120C400 */  addu       $4, $6, $4
    /* 2FDD94 003FDD94 0C008424 */  addiu      $4, $4, 0xC
    /* 2FDD98 003FDD98 21186400 */  addu       $3, $3, $4
    /* 2FDD9C 003FDD9C 000023AE */  sw         $3, 0x0($17)
    /* 2FDDA0 003FDDA0 2000BFDF */  ld         $31, 0x20($29)
    /* 2FDDA4 003FDDA4 1000B17B */  lq         $17, 0x10($29)
    /* 2FDDA8 003FDDA8 0000B07B */  lq         $16, 0x0($29)
    /* 2FDDAC 003FDDAC 0800E003 */  jr         $31
    /* 2FDDB0 003FDDB0 3000BD27 */   addiu     $29, $29, 0x30
    /* 2FDDB4 003FDDB4 00000000 */  nop
    /* 2FDDB8 003FDDB8 00000000 */  nop
    /* 2FDDBC 003FDDBC 00000000 */  nop
.size func_003fdd10, 0xb0

.section .text
.set noat
.set noreorder
glabel func_004e4698
    /* 3E4698 004E4698 7300033C */  lui        $3, %hi(D_00731C44)
    /* 3E469C 004E469C 00160400 */  sll        $2, $4, 24
    /* 3E46A0 004E46A0 441C6324 */  addiu      $3, $3, %lo(D_00731C44)
    /* 3E46A4 004E46A4 03160200 */  sra        $2, $2, 24
    /* 3E46A8 004E46A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E46AC 004E46AC 7300063C */  lui        $6, %hi(D_00731C74)
    /* 3E46B0 004E46B0 0000BFFF */  sd         $31, 0x0($29)
    /* 3E46B4 004E46B4 01000524 */  addiu      $5, $0, 0x1
    /* 3E46B8 004E46B8 000062AC */  sw         $2, 0x0($3)
    /* 3E46BC 004E46BC 0000628C */  lw         $2, 0x0($3)
    /* 3E46C0 004E46C0 07008514 */  bne        $4, $5, .L004E46E0
    /* 3E46C4 004E46C4 741CC2AC */   sw        $2, %lo(D_00731C74)($6)
    /* 3E46C8 004E46C8 7600043C */  lui        $4, %hi(D_0075ACE8)
    /* 3E46CC 004E46CC 0000BFDF */  ld         $31, 0x0($29)
    /* 3E46D0 004E46D0 E8AC8424 */  addiu      $4, $4, %lo(D_0075ACE8)
    /* 3E46D4 004E46D4 32911008 */  j          func_004244c8
    /* 3E46D8 004E46D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E46DC 004E46DC 00000000 */  nop
  .L004E46E0:
    /* 3E46E0 004E46E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E46E4 004E46E4 0800E003 */  jr         $31
    /* 3E46E8 004E46E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E46EC 004E46EC 00000000 */  nop
.size func_004e4698, 0x58

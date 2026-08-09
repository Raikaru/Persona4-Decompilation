.section .text
.set noat
.set noreorder
glabel func_002a1f20
    /* 1A1F20 002A1F20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1A1F24 002A1F24 1000BFFF */  sd         $31, 0x10($29)
    /* 1A1F28 002A1F28 0000B07F */  sq         $16, 0x0($29)
    /* 1A1F2C 002A1F2C 2D808000 */  daddu      $16, $4, $0
    /* 1A1F30 002A1F30 3800828C */  lw         $2, 0x38($4)
    /* 1A1F34 002A1F34 0400438C */  lw         $3, 0x4($2)
    /* 1A1F38 002A1F38 03000224 */  addiu      $2, $0, 0x3
    /* 1A1F3C 002A1F3C 0E006210 */  beq        $3, $2, .L002A1F78
    /* 1A1F40 002A1F40 00000000 */   nop
    /* 1A1F44 002A1F44 6482110C */  jal        func_00460990
    /* 1A1F48 002A1F48 00000000 */   nop
    /* 1A1F4C 002A1F4C 2D284000 */  daddu      $5, $2, $0
    /* 1A1F50 002A1F50 2A00033C */  lui        $3, %hi(func_002a1ef0)
    /* 1A1F54 002A1F54 F01E6324 */  addiu      $3, $3, %lo(func_002a1ef0)
    /* 1A1F58 002A1F58 080043AC */  sw         $3, 0x8($2)
    /* 1A1F5C 002A1F5C 100050AC */  sw         $16, 0x10($2)
    /* 1A1F60 002A1F60 7900043C */  lui        $4, %hi(D_00795E60)
    /* 1A1F64 002A1F64 605E8424 */  addiu      $4, $4, %lo(D_00795E60)
    /* 1A1F68 002A1F68 B082110C */  jal        func_00460ac0
    /* 1A1F6C 002A1F6C 00000000 */   nop
    /* 1A1F70 002A1F70 04000010 */  b          .L002A1F84
    /* 1A1F74 002A1F74 00000000 */   nop
  .L002A1F78:
    /* 1A1F78 002A1F78 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1A1F7C 002A1F7C 02000010 */  b          .L002A1F88
    /* 1A1F80 002A1F80 00000000 */   nop
  .L002A1F84:
    /* 1A1F84 002A1F84 2D100000 */  daddu      $2, $0, $0
  .L002A1F88:
    /* 1A1F88 002A1F88 1000BFDF */  ld         $31, 0x10($29)
    /* 1A1F8C 002A1F8C 0000B07B */  lq         $16, 0x0($29)
    /* 1A1F90 002A1F90 2000BD27 */  addiu      $29, $29, 0x20
    /* 1A1F94 002A1F94 0800E003 */  jr         $31
    /* 1A1F98 002A1F98 00000000 */   nop
    /* 1A1F9C 002A1F9C 00000000 */  nop
.size func_002a1f20, 0x80

.section .text
.set noat
.set noreorder
glabel func_004e5d68
    /* 3E5D68 004E5D68 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3E5D6C 004E5D6C 3000B0FF */  sd         $16, 0x30($29)
    /* 3E5D70 004E5D70 2D808000 */  daddu      $16, $4, $0
    /* 3E5D74 004E5D74 3800B1FF */  sd         $17, 0x38($29)
    /* 3E5D78 004E5D78 05000016 */  bnez       $16, .L004E5D90
    /* 3E5D7C 004E5D7C 4000BFFF */   sd        $31, 0x40($29)
    /* 3E5D80 004E5D80 7600053C */  lui        $5, %hi(D_0075B068)
    /* 3E5D84 004E5D84 1E000010 */  b          .L004E5E00
    /* 3E5D88 004E5D88 68B0A524 */   addiu     $5, $5, %lo(D_0075B068)
    /* 3E5D8C 004E5D8C 00000000 */  nop
  .L004E5D90:
    /* 3E5D90 004E5D90 AC9B130C */  jal        func_004e6eb0
    /* 3E5D94 004E5D94 2D28A003 */   daddu     $5, $29, $0
    /* 3E5D98 004E5D98 7300033C */  lui        $3, %hi(D_00733C80)
    /* 3E5D9C 004E5D9C 0400A28F */  lw         $2, 0x4($29)
    /* 3E5DA0 004E5DA0 803C7124 */  addiu      $17, $3, %lo(D_00733C80)
    /* 3E5DA4 004E5DA4 2D200002 */  daddu      $4, $16, $0
    /* 3E5DA8 004E5DA8 1A004014 */  bnez       $2, .L004E5E14
    /* 3E5DAC 004E5DAC 2D282002 */   daddu     $5, $17, $0
    /* 3E5DB0 004E5DB0 9099130C */  jal        func_004e6640
    /* 3E5DB4 004E5DB4 00000000 */   nop
    /* 3E5DB8 004E5DB8 8691130C */  jal        func_004e4618
    /* 3E5DBC 004E5DBC 00820434 */   ori       $4, $0, 0x8200
    /* 3E5DC0 004E5DC0 F2B9100C */  jal        func_0042e7c8
    /* 3E5DC4 004E5DC4 2D200000 */   daddu     $4, $0, $0
    /* 3E5DC8 004E5DC8 8691130C */  jal        func_004e4618
    /* 3E5DCC 004E5DCC 01820434 */   ori       $4, $0, 0x8201
    /* 3E5DD0 004E5DD0 2D282002 */  daddu      $5, $17, $0
    /* 3E5DD4 004E5DD4 9A96130C */  jal        func_004e5a68
    /* 3E5DD8 004E5DD8 2D20A003 */   daddu     $4, $29, $0
    /* 3E5DDC 004E5DDC 7600043C */  lui        $4, %hi(D_0075B098)
    /* 3E5DE0 004E5DE0 98B08424 */  addiu      $4, $4, %lo(D_0075B098)
    /* 3E5DE4 004E5DE4 0A004014 */  bnez       $2, .L004E5E10
    /* 3E5DE8 004E5DE8 2D282002 */   daddu     $5, $17, $0
    /* 3E5DEC 004E5DEC FC34130C */  jal        func_004cd3f0
    /* 3E5DF0 004E5DF0 00000000 */   nop
    /* 3E5DF4 004E5DF4 7600053C */  lui        $5, %hi(D_0075B0C0)
    /* 3E5DF8 004E5DF8 C0B0A524 */  addiu      $5, $5, %lo(D_0075B0C0)
    /* 3E5DFC 004E5DFC 2D200000 */  daddu      $4, $0, $0
  .L004E5E00:
    /* 3E5E00 004E5E00 8E96130C */  jal        func_004e5a38
    /* 3E5E04 004E5E04 00000000 */   nop
    /* 3E5E08 004E5E08 02000010 */  b          .L004E5E14
    /* 3E5E0C 004E5E0C 2D100000 */   daddu     $2, $0, $0
  .L004E5E10:
    /* 3E5E10 004E5E10 0400A28F */  lw         $2, 0x4($29)
  .L004E5E14:
    /* 3E5E14 004E5E14 3000B0DF */  ld         $16, 0x30($29)
    /* 3E5E18 004E5E18 3800B1DF */  ld         $17, 0x38($29)
    /* 3E5E1C 004E5E1C 4000BFDF */  ld         $31, 0x40($29)
    /* 3E5E20 004E5E20 0800E003 */  jr         $31
    /* 3E5E24 004E5E24 5000BD27 */   addiu     $29, $29, 0x50
.size func_004e5d68, 0xc0

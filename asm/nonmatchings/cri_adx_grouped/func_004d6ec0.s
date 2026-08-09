.section .text
.set noat
.set noreorder
glabel func_004d6ec0
    /* 3D6EC0 004D6EC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D6EC4 004D6EC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6EC8 004D6EC8 2D808000 */  daddu      $16, $4, $0
    /* 3D6ECC 004D6ECC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6ED0 004D6ED0 2D88A000 */  daddu      $17, $5, $0
    /* 3D6ED4 004D6ED4 1000B2FF */  sd         $18, 0x10($29)
    /* 3D6ED8 004D6ED8 2D90C000 */  daddu      $18, $6, $0
    /* 3D6EDC 004D6EDC 1800B3FF */  sd         $19, 0x18($29)
    /* 3D6EE0 004D6EE0 2D98E000 */  daddu      $19, $7, $0
    /* 3D6EE4 004D6EE4 03000012 */  beqz       $16, .L004D6EF4
    /* 3D6EE8 004D6EE8 2000BFFF */   sd        $31, 0x20($29)
    /* 3D6EEC 004D6EEC 0A002016 */  bnez       $17, .L004D6F18
    /* 3D6EF0 004D6EF0 00000000 */   nop
  .L004D6EF4:
    /* 3D6EF4 004D6EF4 7600043C */  lui        $4, %hi(D_00759370)
    /* 3D6EF8 004D6EF8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6EFC 004D6EFC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6F00 004D6F00 70938424 */  addiu      $4, $4, %lo(D_00759370)
    /* 3D6F04 004D6F04 1000B2DF */  ld         $18, 0x10($29)
    /* 3D6F08 004D6F08 1800B3DF */  ld         $19, 0x18($29)
    /* 3D6F0C 004D6F0C 2000BFDF */  ld         $31, 0x20($29)
    /* 3D6F10 004D6F10 A61A1308 */  j          func_004c6a98
    /* 3D6F14 004D6F14 3000BD27 */   addiu     $29, $29, 0x30
  .L004D6F18:
    /* 3D6F18 004D6F18 C250130C */  jal        func_004d4308
    /* 3D6F1C 004D6F1C 00000000 */   nop
    /* 3D6F20 004D6F20 B000048E */  lw         $4, 0xB0($16)
    /* 3D6F24 004D6F24 0C0A110C */  jal        func_00442830
    /* 3D6F28 004D6F28 2D282002 */   daddu     $5, $17, $0
    /* 3D6F2C 004D6F2C B000038E */  lw         $3, 0xB0($16)
    /* 3D6F30 004D6F30 01000224 */  addiu      $2, $0, 0x1
    /* 3D6F34 004D6F34 BC0012AE */  sw         $18, 0xBC($16)
    /* 3D6F38 004D6F38 C00013AE */  sw         $19, 0xC0($16)
    /* 3D6F3C 004D6F3C 2D200002 */  daddu      $4, $16, $0
    /* 3D6F40 004D6F40 B40003AE */  sw         $3, 0xB4($16)
    /* 3D6F44 004D6F44 2D280000 */  daddu      $5, $0, $0
    /* 3D6F48 004D6F48 AC0002A2 */  sb         $2, 0xAC($16)
    /* 3D6F4C 004D6F4C B80000AE */  sw         $0, 0xB8($16)
    /* 3D6F50 004D6F50 010002A2 */  sb         $2, 0x1($16)
    /* 3D6F54 004D6F54 020000A2 */  sb         $0, 0x2($16)
    /* 3D6F58 004D6F58 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6F5C 004D6F5C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6F60 004D6F60 1000B2DF */  ld         $18, 0x10($29)
    /* 3D6F64 004D6F64 1800B3DF */  ld         $19, 0x18($29)
    /* 3D6F68 004D6F68 2000BFDF */  ld         $31, 0x20($29)
    /* 3D6F6C 004D6F6C 6E591308 */  j          func_004d65b8
    /* 3D6F70 004D6F70 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D6F74 004D6F74 00000000 */  nop
.size func_004d6ec0, 0xb8

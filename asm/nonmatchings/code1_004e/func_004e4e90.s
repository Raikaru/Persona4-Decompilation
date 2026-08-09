.section .text
.set noat
.set noreorder
glabel func_004e4e90
    /* 3E4E90 004E4E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E4E94 004E4E94 7300023C */  lui        $2, %hi(D_00731C84)
    /* 3E4E98 004E4E98 0000B0FF */  sd         $16, 0x0($29)
    /* 3E4E9C 004E4E9C 841C5024 */  addiu      $16, $2, %lo(D_00731C84)
    /* 3E4EA0 004E4EA0 0800BFFF */  sd         $31, 0x8($29)
    /* 3E4EA4 004E4EA4 7600043C */  lui        $4, %hi(D_0075AEB8)
    /* 3E4EA8 004E4EA8 B8AE8424 */  addiu      $4, $4, %lo(D_0075AEB8)
    /* 3E4EAC 004E4EAC FC34130C */  jal        func_004cd3f0
    /* 3E4EB0 004E4EB0 0000058E */   lw        $5, 0x0($16)
    /* 3E4EB4 004E4EB4 7300043C */  lui        $4, %hi(D_00731C88)
    /* 3E4EB8 004E4EB8 0000028E */  lw         $2, 0x0($16)
    /* 3E4EBC 004E4EBC 881C8424 */  addiu      $4, $4, %lo(D_00731C88)
    /* 3E4EC0 004E4EC0 2D280000 */  daddu      $5, $0, $0
    /* 3E4EC4 004E4EC4 04004014 */  bnez       $2, .L004E4ED8
    /* 3E4EC8 004E4EC8 00080624 */   addiu     $6, $0, 0x800
    /* 3E4ECC 004E4ECC 72FE100C */  jal        func_0043f9c8
    /* 3E4ED0 004E4ED0 00000000 */   nop
    /* 3E4ED4 004E4ED4 0000028E */  lw         $2, 0x0($16)
  .L004E4ED8:
    /* 3E4ED8 004E4ED8 01004224 */  addiu      $2, $2, 0x1
    /* 3E4EDC 004E4EDC 7600043C */  lui        $4, %hi(D_0075AED0)
    /* 3E4EE0 004E4EE0 000002AE */  sw         $2, 0x0($16)
    /* 3E4EE4 004E4EE4 D0AE8424 */  addiu      $4, $4, %lo(D_0075AED0)
    /* 3E4EE8 004E4EE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3E4EEC 004E4EEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3E4EF0 004E4EF0 FC341308 */  j          func_004cd3f0
    /* 3E4EF4 004E4EF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e4e90, 0x68

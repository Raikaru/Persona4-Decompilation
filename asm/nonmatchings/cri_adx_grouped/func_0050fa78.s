.section .text
.set noat
.set noreorder
glabel func_0050fa78
    /* 40FA78 0050FA78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40FA7C 0050FA7C 0000B0FF */  sd         $16, 0x0($29)
    /* 40FA80 0050FA80 2D808000 */  daddu      $16, $4, $0
    /* 40FA84 0050FA84 0800B1FF */  sd         $17, 0x8($29)
    /* 40FA88 0050FA88 1000BFFF */  sd         $31, 0x10($29)
    /* 40FA8C 0050FA8C 0A35140C */  jal        func_0050d428
    /* 40FA90 0050FA90 2D88A000 */   daddu     $17, $5, $0
    /* 40FA94 0050FA94 01000324 */  addiu      $3, $0, 0x1
    /* 40FA98 0050FA98 09004310 */  beq        $2, $3, .L0050FAC0
    /* 40FA9C 0050FA9C 2D200002 */   daddu     $4, $16, $0
    /* 40FAA0 0050FAA0 7600043C */  lui        $4, %hi(D_0075FC08)
    /* 40FAA4 0050FAA4 0000B0DF */  ld         $16, 0x0($29)
    /* 40FAA8 0050FAA8 0800B1DF */  ld         $17, 0x8($29)
    /* 40FAAC 0050FAAC 08FC8424 */  addiu      $4, $4, %lo(D_0075FC08)
    /* 40FAB0 0050FAB0 1000BFDF */  ld         $31, 0x10($29)
    /* 40FAB4 0050FAB4 88441408 */  j          func_00511220
    /* 40FAB8 0050FAB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FABC 0050FABC 00000000 */  nop
  .L0050FAC0:
    /* 40FAC0 0050FAC0 2E39140C */  jal        func_0050e4b8
    /* 40FAC4 0050FAC4 00000000 */   nop
    /* 40FAC8 0050FAC8 2D282002 */  daddu      $5, $17, $0
    /* 40FACC 0050FACC 0000B0DF */  ld         $16, 0x0($29)
    /* 40FAD0 0050FAD0 2D204000 */  daddu      $4, $2, $0
    /* 40FAD4 0050FAD4 0800B1DF */  ld         $17, 0x8($29)
    /* 40FAD8 0050FAD8 1000BFDF */  ld         $31, 0x10($29)
    /* 40FADC 0050FADC 34AF1408 */  j          func_0052bcd0
    /* 40FAE0 0050FAE0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FAE4 0050FAE4 00000000 */  nop
.size func_0050fa78, 0x70

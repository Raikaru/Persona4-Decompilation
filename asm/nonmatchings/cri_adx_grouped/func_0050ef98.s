.section .text
.set noat
.set noreorder
glabel func_0050ef98
    /* 40EF98 0050EF98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40EF9C 0050EF9C 0000B0FF */  sd         $16, 0x0($29)
    /* 40EFA0 0050EFA0 2D808000 */  daddu      $16, $4, $0
    /* 40EFA4 0050EFA4 0800B1FF */  sd         $17, 0x8($29)
    /* 40EFA8 0050EFA8 1000BFFF */  sd         $31, 0x10($29)
    /* 40EFAC 0050EFAC 0A35140C */  jal        func_0050d428
    /* 40EFB0 0050EFB0 2D88A000 */   daddu     $17, $5, $0
    /* 40EFB4 0050EFB4 01000324 */  addiu      $3, $0, 0x1
    /* 40EFB8 0050EFB8 09004310 */  beq        $2, $3, .L0050EFE0
    /* 40EFBC 0050EFBC 2D200002 */   daddu     $4, $16, $0
    /* 40EFC0 0050EFC0 7600043C */  lui        $4, %hi(D_0075F9F0)
    /* 40EFC4 0050EFC4 0000B0DF */  ld         $16, 0x0($29)
    /* 40EFC8 0050EFC8 0800B1DF */  ld         $17, 0x8($29)
    /* 40EFCC 0050EFCC F0F98424 */  addiu      $4, $4, %lo(D_0075F9F0)
    /* 40EFD0 0050EFD0 1000BFDF */  ld         $31, 0x10($29)
    /* 40EFD4 0050EFD4 88441408 */  j          func_00511220
    /* 40EFD8 0050EFD8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EFDC 0050EFDC 00000000 */  nop
  .L0050EFE0:
    /* 40EFE0 0050EFE0 2E39140C */  jal        func_0050e4b8
    /* 40EFE4 0050EFE4 00000000 */   nop
    /* 40EFE8 0050EFE8 2D282002 */  daddu      $5, $17, $0
    /* 40EFEC 0050EFEC 0000B0DF */  ld         $16, 0x0($29)
    /* 40EFF0 0050EFF0 2D204000 */  daddu      $4, $2, $0
    /* 40EFF4 0050EFF4 0800B1DF */  ld         $17, 0x8($29)
    /* 40EFF8 0050EFF8 1000BFDF */  ld         $31, 0x10($29)
    /* 40EFFC 0050EFFC F2AE1408 */  j          func_0052bbc8
    /* 40F000 0050F000 2000BD27 */   addiu     $29, $29, 0x20
    /* 40F004 0050F004 00000000 */  nop
.size func_0050ef98, 0x70

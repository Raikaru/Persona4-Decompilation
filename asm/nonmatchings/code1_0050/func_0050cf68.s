.section .text
.set noat
.set noreorder
glabel func_0050cf68
    /* 40CF68 0050CF68 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 40CF6C 0050CF6C B000B0FF */  sd         $16, 0xB0($29)
    /* 40CF70 0050CF70 B800BFFF */  sd         $31, 0xB8($29)
    /* 40CF74 0050CF74 0A35140C */  jal        func_0050d428
    /* 40CF78 0050CF78 2D808000 */   daddu     $16, $4, $0
    /* 40CF7C 0050CF7C 01000324 */  addiu      $3, $0, 0x1
    /* 40CF80 0050CF80 07004310 */  beq        $2, $3, .L0050CFA0
    /* 40CF84 0050CF84 2D200002 */   daddu     $4, $16, $0
    /* 40CF88 0050CF88 7600043C */  lui        $4, %hi(D_0075F0F8)
    /* 40CF8C 0050CF8C 8844140C */  jal        func_00511220
    /* 40CF90 0050CF90 F8F08424 */   addiu     $4, $4, %lo(D_0075F0F8)
    /* 40CF94 0050CF94 0D000010 */  b          .L0050CFCC
    /* 40CF98 0050CF98 2D100000 */   daddu     $2, $0, $0
    /* 40CF9C 0050CF9C 00000000 */  nop
  .L0050CFA0:
    /* 40CFA0 0050CFA0 9833140C */  jal        func_0050ce60
    /* 40CFA4 0050CFA4 00000000 */   nop
    /* 40CFA8 0050CFA8 2D184000 */  daddu      $3, $2, $0
    /* 40CFAC 0050CFAC 2D28A003 */  daddu      $5, $29, $0
    /* 40CFB0 0050CFB0 06006010 */  beqz       $3, .L0050CFCC
    /* 40CFB4 0050CFB4 2D206000 */   daddu     $4, $3, $0
    /* 40CFB8 0050CFB8 6094140C */  jal        func_00525180
    /* 40CFBC 0050CFBC 00000000 */   nop
    /* 40CFC0 0050CFC0 0400A38F */  lw         $3, 0x4($29)
    /* 40CFC4 0050CFC4 1000A28F */  lw         $2, 0x10($29)
    /* 40CFC8 0050CFC8 23106200 */  subu       $2, $3, $2
  .L0050CFCC:
    /* 40CFCC 0050CFCC B000B0DF */  ld         $16, 0xB0($29)
    /* 40CFD0 0050CFD0 B800BFDF */  ld         $31, 0xB8($29)
    /* 40CFD4 0050CFD4 0800E003 */  jr         $31
    /* 40CFD8 0050CFD8 C000BD27 */   addiu     $29, $29, 0xC0
    /* 40CFDC 0050CFDC 00000000 */  nop
.size func_0050cf68, 0x78

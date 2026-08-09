.section .text
.set noat
.set noreorder
glabel func_0050ceb0
    /* 40CEB0 0050CEB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CEB4 0050CEB4 0000B0FF */  sd         $16, 0x0($29)
    /* 40CEB8 0050CEB8 0800BFFF */  sd         $31, 0x8($29)
    /* 40CEBC 0050CEBC 0A35140C */  jal        func_0050d428
    /* 40CEC0 0050CEC0 2D808000 */   daddu     $16, $4, $0
    /* 40CEC4 0050CEC4 01000324 */  addiu      $3, $0, 0x1
    /* 40CEC8 0050CEC8 09004310 */  beq        $2, $3, .L0050CEF0
    /* 40CECC 0050CECC 2D200002 */   daddu     $4, $16, $0
    /* 40CED0 0050CED0 7600043C */  lui        $4, %hi(D_0075F098)
    /* 40CED4 0050CED4 8844140C */  jal        func_00511220
    /* 40CED8 0050CED8 98F08424 */   addiu     $4, $4, %lo(D_0075F098)
    /* 40CEDC 0050CEDC 2D100000 */  daddu      $2, $0, $0
    /* 40CEE0 0050CEE0 0000B0DF */  ld         $16, 0x0($29)
    /* 40CEE4 0050CEE4 0800BFDF */  ld         $31, 0x8($29)
    /* 40CEE8 0050CEE8 0800E003 */  jr         $31
    /* 40CEEC 0050CEEC 1000BD27 */   addiu     $29, $29, 0x10
  .L0050CEF0:
    /* 40CEF0 0050CEF0 0000B0DF */  ld         $16, 0x0($29)
    /* 40CEF4 0050CEF4 0800BFDF */  ld         $31, 0x8($29)
    /* 40CEF8 0050CEF8 12351408 */  j          func_0050d448
    /* 40CEFC 0050CEFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ceb0, 0x50

.section .text
.set noat
.set noreorder
glabel func_0050ffc8
    /* 40FFC8 0050FFC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FFCC 0050FFCC 0000B0FF */  sd         $16, 0x0($29)
    /* 40FFD0 0050FFD0 0800BFFF */  sd         $31, 0x8($29)
    /* 40FFD4 0050FFD4 0A35140C */  jal        func_0050d428
    /* 40FFD8 0050FFD8 2D808000 */   daddu     $16, $4, $0
    /* 40FFDC 0050FFDC 01000324 */  addiu      $3, $0, 0x1
    /* 40FFE0 0050FFE0 2D200002 */  daddu      $4, $16, $0
    /* 40FFE4 0050FFE4 08004310 */  beq        $2, $3, .L00510008
    /* 40FFE8 0050FFE8 2D280000 */   daddu     $5, $0, $0
    /* 40FFEC 0050FFEC 7600043C */  lui        $4, %hi(D_0075FDD0)
    /* 40FFF0 0050FFF0 0000B0DF */  ld         $16, 0x0($29)
    /* 40FFF4 0050FFF4 0800BFDF */  ld         $31, 0x8($29)
    /* 40FFF8 0050FFF8 D0FD8424 */  addiu      $4, $4, %lo(D_0075FDD0)
    /* 40FFFC 0050FFFC 88441408 */  j          func_00511220
    /* 410000 00510000 1000BD27 */   addiu     $29, $29, 0x10
    /* 410004 00510004 00000000 */  nop
  .L00510008:
    /* 410008 00510008 B03F140C */  jal        func_0050fec0
    /* 41000C 0051000C 00000000 */   nop
    /* 410010 00510010 2D200002 */  daddu      $4, $16, $0
    /* 410014 00510014 0800BFDF */  ld         $31, 0x8($29)
    /* 410018 00510018 0000B0DF */  ld         $16, 0x0($29)
    /* 41001C 0051001C 0A401408 */  j          func_00510028
    /* 410020 00510020 1000BD27 */   addiu     $29, $29, 0x10
    /* 410024 00510024 00000000 */  nop
.size func_0050ffc8, 0x60

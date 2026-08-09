.section .text
.set noat
.set noreorder
glabel func_00521c98
    /* 421C98 00521C98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 421C9C 00521C9C 0000B0FF */  sd         $16, 0x0($29)
    /* 421CA0 00521CA0 0800BFFF */  sd         $31, 0x8($29)
    /* 421CA4 00521CA4 3287140C */  jal        func_00521cc8
    /* 421CA8 00521CA8 2D808000 */   daddu     $16, $4, $0
    /* 421CAC 00521CAC 5C87140C */  jal        func_00521d70
    /* 421CB0 00521CB0 2D200002 */   daddu     $4, $16, $0
    /* 421CB4 00521CB4 2D200002 */  daddu      $4, $16, $0
    /* 421CB8 00521CB8 0800BFDF */  ld         $31, 0x8($29)
    /* 421CBC 00521CBC 0000B0DF */  ld         $16, 0x0($29)
    /* 421CC0 00521CC0 7E871408 */  j          func_00521df8
    /* 421CC4 00521CC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00521c98, 0x30

.section .text
.set noat
.set noreorder
glabel func_00521ab8
    /* 421AB8 00521AB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 421ABC 00521ABC 0000B0FF */  sd         $16, 0x0($29)
    /* 421AC0 00521AC0 0800BFFF */  sd         $31, 0x8($29)
    /* 421AC4 00521AC4 B886140C */  jal        func_00521ae0
    /* 421AC8 00521AC8 2D808000 */   daddu     $16, $4, $0
    /* 421ACC 00521ACC 0800BFDF */  ld         $31, 0x8($29)
    /* 421AD0 00521AD0 2D200002 */  daddu      $4, $16, $0
    /* 421AD4 00521AD4 0000B0DF */  ld         $16, 0x0($29)
    /* 421AD8 00521AD8 B4901408 */  j          func_005242d0
    /* 421ADC 00521ADC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00521ab8, 0x28

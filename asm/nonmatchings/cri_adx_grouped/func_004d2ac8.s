.section .text
.set noat
.set noreorder
glabel func_004d2ac8
    /* 3D2AC8 004D2AC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2ACC 004D2ACC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D2AD0 004D2AD0 3246130C */  jal        func_004d18c8
    /* 3D2AD4 004D2AD4 00000000 */   nop
    /* 3D2AD8 004D2AD8 BC4A130C */  jal        func_004d2af0
    /* 3D2ADC 004D2ADC 00000000 */   nop
    /* 3D2AE0 004D2AE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D2AE4 004D2AE4 34461308 */  j          func_004d18d0
    /* 3D2AE8 004D2AE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2AEC 004D2AEC 00000000 */  nop
.size func_004d2ac8, 0x28

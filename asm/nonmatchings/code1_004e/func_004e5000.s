.section .text
.set noat
.set noreorder
glabel func_004e5000
    /* 3E5000 004E5000 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5004 004E5004 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5008 004E5008 0800BFFF */  sd         $31, 0x8($29)
    /* 3E500C 004E500C 14B5130C */  jal        func_004ed450
    /* 3E5010 004E5010 2D808000 */   daddu     $16, $4, $0
    /* 3E5014 004E5014 0800BFDF */  ld         $31, 0x8($29)
    /* 3E5018 004E5018 000000A2 */  sb         $0, 0x0($16)
    /* 3E501C 004E501C 0000B0DF */  ld         $16, 0x0($29)
    /* 3E5020 004E5020 1AB51308 */  j          func_004ed468
    /* 3E5024 004E5024 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e5000, 0x28

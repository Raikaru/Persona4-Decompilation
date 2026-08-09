.section .text
.set noat
.set noreorder
glabel func_004ee210
    /* 3EE210 004EE210 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE214 004EE214 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE218 004EE218 0800BFFF */  sd         $31, 0x8($29)
    /* 3EE21C 004EE21C 14B5130C */  jal        func_004ed450
    /* 3EE220 004EE220 2D808000 */   daddu     $16, $4, $0
    /* 3EE224 004EE224 90B8130C */  jal        func_004ee240
    /* 3EE228 004EE228 2D200002 */   daddu     $4, $16, $0
    /* 3EE22C 004EE22C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE230 004EE230 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE234 004EE234 1AB51308 */  j          func_004ed468
    /* 3EE238 004EE238 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE23C 004EE23C 00000000 */  nop
.size func_004ee210, 0x30

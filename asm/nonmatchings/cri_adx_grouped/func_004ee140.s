.section .text
.set noat
.set noreorder
glabel func_004ee140
    /* 3EE140 004EE140 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE144 004EE144 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE148 004EE148 0800BFFF */  sd         $31, 0x8($29)
    /* 3EE14C 004EE14C 14B5130C */  jal        func_004ed450
    /* 3EE150 004EE150 2D808000 */   daddu     $16, $4, $0
    /* 3EE154 004EE154 5CB8130C */  jal        func_004ee170
    /* 3EE158 004EE158 2D200002 */   daddu     $4, $16, $0
    /* 3EE15C 004EE15C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE160 004EE160 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE164 004EE164 1AB51308 */  j          func_004ed468
    /* 3EE168 004EE168 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE16C 004EE16C 00000000 */  nop
.size func_004ee140, 0x30

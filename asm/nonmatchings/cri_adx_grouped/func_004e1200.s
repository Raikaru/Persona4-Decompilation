.section .text
.set noat
.set noreorder
glabel func_004e1200
    /* 3E1200 004E1200 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E1204 004E1204 0000B0FF */  sd         $16, 0x0($29)
    /* 3E1208 004E1208 0800BFFF */  sd         $31, 0x8($29)
    /* 3E120C 004E120C E080130C */  jal        func_004e0380
    /* 3E1210 004E1210 2D808000 */   daddu     $16, $4, $0
    /* 3E1214 004E1214 8C84130C */  jal        func_004e1230
    /* 3E1218 004E1218 2D200002 */   daddu     $4, $16, $0
    /* 3E121C 004E121C 0000B0DF */  ld         $16, 0x0($29)
    /* 3E1220 004E1220 0800BFDF */  ld         $31, 0x8($29)
    /* 3E1224 004E1224 E6801308 */  j          func_004e0398
    /* 3E1228 004E1228 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E122C 004E122C 00000000 */  nop
.size func_004e1200, 0x30

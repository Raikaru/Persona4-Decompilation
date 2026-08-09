.section .text
.set noat
.set noreorder
glabel func_004df220
    /* 3DF220 004DF220 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DF224 004DF224 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF228 004DF228 2D808000 */  daddu      $16, $4, $0
    /* 3DF22C 004DF22C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF230 004DF230 1000BFFF */  sd         $31, 0x10($29)
    /* 3DF234 004DF234 E080130C */  jal        func_004e0380
    /* 3DF238 004DF238 2D88A000 */   daddu     $17, $5, $0
    /* 3DF23C 004DF23C 2D200002 */  daddu      $4, $16, $0
    /* 3DF240 004DF240 987C130C */  jal        func_004df260
    /* 3DF244 004DF244 2D282002 */   daddu     $5, $17, $0
    /* 3DF248 004DF248 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF24C 004DF24C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF250 004DF250 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF254 004DF254 E6801308 */  j          func_004e0398
    /* 3DF258 004DF258 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF25C 004DF25C 00000000 */  nop
.size func_004df220, 0x40

.section .text
.set noat
.set noreorder
glabel func_001fc280
    /* FC280 001FC280 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FC284 001FC284 0000BFFF */  sd         $31, 0x0($29)
    /* FC288 001FC288 01000424 */  addiu      $4, $0, 0x1
    /* FC28C 001FC28C 69B484A3 */  sb         $4, -0x4B97($28)
    /* FC290 001FC290 2D288000 */  daddu      $5, $4, $0
    /* FC294 001FC294 4889040C */  jal        func_00122520
    /* FC298 001FC298 00000000 */   nop
    /* FC29C 001FC29C FF000424 */  addiu      $4, $0, 0xFF
    /* FC2A0 001FC2A0 2D288000 */  daddu      $5, $4, $0
    /* FC2A4 001FC2A4 2D308000 */  daddu      $6, $4, $0
    /* FC2A8 001FC2A8 288A040C */  jal        func_001228a0
    /* FC2AC 001FC2AC 00000000 */   nop
    /* FC2B0 001FC2B0 0000BFDF */  ld         $31, 0x0($29)
    /* FC2B4 001FC2B4 1000BD27 */  addiu      $29, $29, 0x10
    /* FC2B8 001FC2B8 0800E003 */  jr         $31
    /* FC2BC 001FC2BC 00000000 */   nop
.size func_001fc280, 0x40

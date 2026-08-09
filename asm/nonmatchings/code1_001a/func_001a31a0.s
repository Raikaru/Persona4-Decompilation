.section .text
.set noat
.set noreorder
glabel func_001a31a0
    /* A31A0 001A31A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A31A4 001A31A4 1000BFFF */  sd         $31, 0x10($29)
    /* A31A8 001A31A8 0000B07F */  sq         $16, 0x0($29)
    /* A31AC 001A31AC 2D808000 */  daddu      $16, $4, $0
    /* A31B0 001A31B0 34DB070C */  jal        func_001f6cd0
    /* A31B4 001A31B4 00000000 */   nop
    /* A31B8 001A31B8 01000324 */  addiu      $3, $0, 0x1
    /* A31BC 001A31BC 1C0403AE */  sw         $3, 0x41C($16)
    /* A31C0 001A31C0 200400AE */  sw         $0, 0x420($16)
    /* A31C4 001A31C4 1000BFDF */  ld         $31, 0x10($29)
    /* A31C8 001A31C8 0000B07B */  lq         $16, 0x0($29)
    /* A31CC 001A31CC 2000BD27 */  addiu      $29, $29, 0x20
    /* A31D0 001A31D0 0800E003 */  jr         $31
    /* A31D4 001A31D4 00000000 */   nop
    /* A31D8 001A31D8 00000000 */  nop
    /* A31DC 001A31DC 00000000 */  nop
.size func_001a31a0, 0x40

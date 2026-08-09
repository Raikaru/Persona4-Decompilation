.section .text
.set noat
.set noreorder
glabel func_004d21e8
    /* 3D21E8 004D21E8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D21EC 004D21EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D21F0 004D21F0 2D808000 */  daddu      $16, $4, $0
    /* 3D21F4 004D21F4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D21F8 004D21F8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D21FC 004D21FC 2A15130C */  jal        func_004c54a8
    /* 3D2200 004D2200 2D88A000 */   daddu     $17, $5, $0
    /* 3D2204 004D2204 3C48130C */  jal        func_004d20f0
    /* 3D2208 004D2208 2D200002 */   daddu     $4, $16, $0
    /* 3D220C 004D220C 3015130C */  jal        func_004c54c0
    /* 3D2210 004D2210 5C0011AE */   sw        $17, 0x5C($16)
    /* 3D2214 004D2214 01000224 */  addiu      $2, $0, 0x1
    /* 3D2218 004D2218 0000B0DF */  ld         $16, 0x0($29)
    /* 3D221C 004D221C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2220 004D2220 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2224 004D2224 0800E003 */  jr         $31
    /* 3D2228 004D2228 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D222C 004D222C 00000000 */  nop
.size func_004d21e8, 0x48

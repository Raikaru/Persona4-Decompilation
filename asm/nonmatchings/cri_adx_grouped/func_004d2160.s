.section .text
.set noat
.set noreorder
glabel func_004d2160
    /* 3D2160 004D2160 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2164 004D2164 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2168 004D2168 0800BFFF */  sd         $31, 0x8($29)
    /* 3D216C 004D216C 2A15130C */  jal        func_004c54a8
    /* 3D2170 004D2170 2D808000 */   daddu     $16, $4, $0
    /* 3D2174 004D2174 3C48130C */  jal        func_004d20f0
    /* 3D2178 004D2178 2D200002 */   daddu     $4, $16, $0
    /* 3D217C 004D217C 0F00023C */  lui        $2, (0xFFFFF >> 16)
    /* 3D2180 004D2180 FFFF4234 */  ori        $2, $2, (0xFFFFF & 0xFFFF)
    /* 3D2184 004D2184 3015130C */  jal        func_004c54c0
    /* 3D2188 004D2188 5C0002AE */   sw        $2, 0x5C($16)
    /* 3D218C 004D218C 01000224 */  addiu      $2, $0, 0x1
    /* 3D2190 004D2190 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2194 004D2194 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2198 004D2198 0800E003 */  jr         $31
    /* 3D219C 004D219C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2160, 0x40

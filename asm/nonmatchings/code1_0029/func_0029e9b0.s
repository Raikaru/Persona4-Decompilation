.section .text
.set noat
.set noreorder
glabel func_0029e9b0
    /* 19E9B0 0029E9B0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 19E9B4 0029E9B4 1800A5FF */  sd         $5, 0x18($29)
    /* 19E9B8 0029E9B8 2000A6FF */  sd         $6, 0x20($29)
    /* 19E9BC 0029E9BC 2800A7FF */  sd         $7, 0x28($29)
    /* 19E9C0 0029E9C0 3000A8FF */  sd         $8, 0x30($29)
    /* 19E9C4 0029E9C4 3800A9FF */  sd         $9, 0x38($29)
    /* 19E9C8 0029E9C8 4000AAFF */  sd         $10, 0x40($29)
    /* 19E9CC 0029E9CC 4800ABFF */  sd         $11, 0x48($29)
    /* 19E9D0 0029E9D0 5000BD27 */  addiu      $29, $29, 0x50
    /* 19E9D4 0029E9D4 0800E003 */  jr         $31
    /* 19E9D8 0029E9D8 00000000 */   nop
    /* 19E9DC 0029E9DC 00000000 */  nop
.size func_0029e9b0, 0x30

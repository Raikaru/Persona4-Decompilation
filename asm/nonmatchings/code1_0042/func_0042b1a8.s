.section .text
.set noat
.set noreorder
glabel func_0042b1a8
    /* 32B1A8 0042B1A8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32B1AC 0042B1AC 7100023C */  lui        $2, %hi(D_0070C9D8)
    /* 32B1B0 0042B1B0 0000B0FF */  sd         $16, 0x0($29)
    /* 32B1B4 0042B1B4 1000B1FF */  sd         $17, 0x10($29)
    /* 32B1B8 0042B1B8 4300103C */  lui        $16, %hi(func_0042b6c0)
    /* 32B1BC 0042B1BC C0B61026 */  addiu      $16, $16, %lo(func_0042b6c0)
    /* 32B1C0 0042B1C0 2D888000 */  daddu      $17, $4, $0
    /* 32B1C4 0042B1C4 D8C951AC */  sw         $17, %lo(D_0070C9D8)($2)
    /* 32B1C8 0042B1C8 2D280002 */  daddu      $5, $16, $0
    /* 32B1CC 0042B1CC 2000BFFF */  sd         $31, 0x20($29)
    /* 32B1D0 0042B1D0 2485100C */  jal        func_00421490
    /* 32B1D4 0042B1D4 01000424 */   addiu     $4, $0, 0x1
    /* 32B1D8 0042B1D8 2D280002 */  daddu      $5, $16, $0
    /* 32B1DC 0042B1DC 2485100C */  jal        func_00421490
    /* 32B1E0 0042B1E0 02000424 */   addiu     $4, $0, 0x2
    /* 32B1E4 0042B1E4 2D280002 */  daddu      $5, $16, $0
    /* 32B1E8 0042B1E8 2485100C */  jal        func_00421490
    /* 32B1EC 0042B1EC 03000424 */   addiu     $4, $0, 0x3
    /* 32B1F0 0042B1F0 2D102002 */  daddu      $2, $17, $0
    /* 32B1F4 0042B1F4 2000BFDF */  ld         $31, 0x20($29)
    /* 32B1F8 0042B1F8 1000B1DF */  ld         $17, 0x10($29)
    /* 32B1FC 0042B1FC 0000B0DF */  ld         $16, 0x0($29)
    /* 32B200 0042B200 0800E003 */  jr         $31
    /* 32B204 0042B204 3000BD27 */   addiu     $29, $29, 0x30
.size func_0042b1a8, 0x60

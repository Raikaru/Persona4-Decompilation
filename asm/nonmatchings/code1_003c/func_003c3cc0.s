.section .text
.set noat
.set noreorder
glabel func_003c3cc0
    /* 2C3CC0 003C3CC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C3CC4 003C3CC4 1000BFFF */  sd         $31, 0x10($29)
    /* 2C3CC8 003C3CC8 0000B07F */  sq         $16, 0x0($29)
    /* 2C3CCC 003C3CCC 2D808000 */  daddu      $16, $4, $0
    /* 2C3CD0 003C3CD0 7100043C */  lui        $4, %hi(D_0070AFD0)
    /* 2C3CD4 003C3CD4 2D280002 */  daddu      $5, $16, $0
    /* 2C3CD8 003C3CD8 088F0F0C */  jal        func_003e3c20
    /* 2C3CDC 003C3CDC D0AF8424 */   addiu     $4, $4, %lo(D_0070AFD0)
    /* 2C3CE0 003C3CE0 68BF0F0C */  jal        func_003efda0
    /* 2C3CE4 003C3CE4 2D200002 */   daddu     $4, $16, $0
    /* 2C3CE8 003C3CE8 D0B6848F */  lw         $4, -0x4930($28)
    /* 2C3CEC 003C3CEC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2C3CF0 003C3CF0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2C3CF4 003C3CF4 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2C3CF8 003C3CF8 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2C3CFC 003C3CFC 21186400 */  addu       $3, $3, $4
    /* 2C3D00 003C3D00 0000648C */  lw         $4, 0x0($3)
    /* 2C3D04 003C3D04 09F84000 */  jalr       $2
    /* 2C3D08 003C3D08 2D280002 */   daddu     $5, $16, $0
    /* 2C3D0C 003C3D0C 1000BFDF */  ld         $31, 0x10($29)
    /* 2C3D10 003C3D10 01000224 */  addiu      $2, $0, 0x1
    /* 2C3D14 003C3D14 0000B07B */  lq         $16, 0x0($29)
    /* 2C3D18 003C3D18 0800E003 */  jr         $31
    /* 2C3D1C 003C3D1C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003c3cc0, 0x60

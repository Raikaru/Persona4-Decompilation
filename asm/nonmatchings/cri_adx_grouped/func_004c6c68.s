.section .text
.set noat
.set noreorder
glabel func_004c6c68
    /* 3C6C68 004C6C68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C6C6C 004C6C6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6C70 004C6C70 2D80C000 */  daddu      $16, $6, $0
    /* 3C6C74 004C6C74 0800B1FF */  sd         $17, 0x8($29)
    /* 3C6C78 004C6C78 2D88E000 */  daddu      $17, $7, $0
    /* 3C6C7C 004C6C7C 1000B2FF */  sd         $18, 0x10($29)
    /* 3C6C80 004C6C80 2D90A000 */  daddu      $18, $5, $0
    /* 3C6C84 004C6C84 2D302002 */  daddu      $6, $17, $0
    /* 3C6C88 004C6C88 1800BFFF */  sd         $31, 0x18($29)
    /* 3C6C8C 004C6C8C D81A130C */  jal        func_004c6b60
    /* 3C6C90 004C6C90 2D280002 */   daddu     $5, $16, $0
    /* 3C6C94 004C6C94 520A110C */  jal        func_00442948
    /* 3C6C98 004C6C98 2D200002 */   daddu     $4, $16, $0
    /* 3C6C9C 004C6C9C 7500053C */  lui        $5, %hi(D_00757EA0)
    /* 3C6CA0 004C6CA0 23882202 */  subu       $17, $17, $2
    /* 3C6CA4 004C6CA4 A07EA524 */  addiu      $5, $5, %lo(D_00757EA0)
    /* 3C6CA8 004C6CA8 FFFF2626 */  addiu      $6, $17, -0x1
    /* 3C6CAC 004C6CAC A00A110C */  jal        func_00442a80
    /* 3C6CB0 004C6CB0 2D200002 */   daddu     $4, $16, $0
    /* 3C6CB4 004C6CB4 520A110C */  jal        func_00442948
    /* 3C6CB8 004C6CB8 2D200002 */   daddu     $4, $16, $0
    /* 3C6CBC 004C6CBC 2D200002 */  daddu      $4, $16, $0
    /* 3C6CC0 004C6CC0 520A110C */  jal        func_00442948
    /* 3C6CC4 004C6CC4 21800202 */   addu      $16, $16, $2
    /* 3C6CC8 004C6CC8 0800B1DF */  ld         $17, 0x8($29)
    /* 3C6CCC 004C6CCC 2D204002 */  daddu      $4, $18, $0
    /* 3C6CD0 004C6CD0 2D280002 */  daddu      $5, $16, $0
    /* 3C6CD4 004C6CD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6CD8 004C6CD8 04000624 */  addiu      $6, $0, 0x4
    /* 3C6CDC 004C6CDC 1000B2DF */  ld         $18, 0x10($29)
    /* 3C6CE0 004C6CE0 1800BFDF */  ld         $31, 0x18($29)
    /* 3C6CE4 004C6CE4 2330C200 */  subu       $6, $6, $2
    /* 3C6CE8 004C6CE8 D81A1308 */  j          func_004c6b60
    /* 3C6CEC 004C6CEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c6c68, 0x88

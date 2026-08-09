.section .text
.set noat
.set noreorder
glabel func_004d1ca0
    /* 3D1CA0 004D1CA0 2D188000 */  daddu      $3, $4, $0
    /* 3D1CA4 004D1CA4 2D200000 */  daddu      $4, $0, $0
    /* 3D1CA8 004D1CA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1CAC 004D1CAC 0001A228 */  slti       $2, $5, 0x100
    /* 3D1CB0 004D1CB0 0000BFFF */  sd         $31, 0x0($29)
    /* 3D1CB4 004D1CB4 2D386000 */  daddu      $7, $3, $0
    /* 3D1CB8 004D1CB8 05004010 */  beqz       $2, .L004D1CD0
    /* 3D1CBC 004D1CBC 2D280000 */   daddu     $5, $0, $0
    /* 3D1CC0 004D1CC0 AC46130C */  jal        func_004d1ab0
    /* 3D1CC4 004D1CC4 2D300000 */   daddu     $6, $0, $0
    /* 3D1CC8 004D1CC8 04000010 */  b          .L004D1CDC
    /* 3D1CCC 004D1CCC 0000BFDF */   ld        $31, 0x0($29)
  .L004D1CD0:
    /* 3D1CD0 004D1CD0 E246130C */  jal        func_004d1b88
    /* 3D1CD4 004D1CD4 2D300000 */   daddu     $6, $0, $0
    /* 3D1CD8 004D1CD8 0000BFDF */  ld         $31, 0x0($29)
  .L004D1CDC:
    /* 3D1CDC 004D1CDC 0800E003 */  jr         $31
    /* 3D1CE0 004D1CE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1CE4 004D1CE4 00000000 */  nop
.size func_004d1ca0, 0x48

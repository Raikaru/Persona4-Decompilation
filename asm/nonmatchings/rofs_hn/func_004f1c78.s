.section .text
.set noat
.set noreorder
glabel func_004f1c78
    /* 3F1C78 004F1C78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1C7C 004F1C7C 08008014 */  bnez       $4, .L004F1CA0
    /* 3F1C80 004F1C80 0000BFFF */   sd        $31, 0x0($29)
    /* 3F1C84 004F1C84 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1C88 004F1C88 7600063C */  lui        $6, %hi(D_0075D448)
    /* 3F1C8C 004F1C8C 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1C90 004F1C90 48D4C624 */  addiu      $6, $6, %lo(D_0075D448)
    /* 3F1C94 004F1C94 0A000010 */  b          .L004F1CC0
    /* 3F1C98 004F1C98 CF010524 */   addiu     $5, $0, 0x1CF
    /* 3F1C9C 004F1C9C 00000000 */  nop
  .L004F1CA0:
    /* 3F1CA0 004F1CA0 34008284 */  lh         $2, 0x34($4)
    /* 3F1CA4 004F1CA4 0A004054 */  bnel       $2, $0, .L004F1CD0
    /* 3F1CA8 004F1CA8 38008284 */   lh        $2, 0x38($4)
    /* 3F1CAC 004F1CAC 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1CB0 004F1CB0 7600063C */  lui        $6, %hi(D_0075D448)
    /* 3F1CB4 004F1CB4 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1CB8 004F1CB8 48D4C624 */  addiu      $6, $6, %lo(D_0075D448)
    /* 3F1CBC 004F1CBC D3010524 */  addiu      $5, $0, 0x1D3
  .L004F1CC0:
    /* 3F1CC0 004F1CC0 2D380000 */  daddu      $7, $0, $0
    /* 3F1CC4 004F1CC4 F0D4130C */  jal        func_004f53c0
    /* 3F1CC8 004F1CC8 9BFF0824 */   addiu     $8, $0, -0x65
    /* 3F1CCC 004F1CCC 03000224 */  addiu      $2, $0, 0x3
  .L004F1CD0:
    /* 3F1CD0 004F1CD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1CD4 004F1CD4 0800E003 */  jr         $31
    /* 3F1CD8 004F1CD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1CDC 004F1CDC 00000000 */  nop
.size func_004f1c78, 0x68

.section .text
.set noat
.set noreorder
glabel func_004dd9c8
    /* 3DD9C8 004DD9C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DD9CC 004DD9CC 7300033C */  lui        $3, %hi(D_00729A38)
    /* 3DD9D0 004DD9D0 0000B0FF */  sd         $16, 0x0($29)
    /* 3DD9D4 004DD9D4 389A7024 */  addiu      $16, $3, %lo(D_00729A38)
    /* 3DD9D8 004DD9D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3DD9DC 004DD9DC 7300023C */  lui        $2, %hi(D_00729A3C)
    /* 3DD9E0 004DD9E0 0000058E */  lw         $5, 0x0($16)
    /* 3DD9E4 004DD9E4 3C9A4224 */  addiu      $2, $2, %lo(D_00729A3C)
    /* 3DD9E8 004DD9E8 0000438C */  lw         $3, 0x0($2)
    /* 3DD9EC 004DD9EC 0000448C */  lw         $4, 0x0($2)
    /* 3DD9F0 004DD9F0 0A00A054 */  bnel       $5, $0, .L004DDA1C
    /* 3DD9F4 004DD9F4 0100A224 */   addiu     $2, $5, 0x1
    /* 3DD9F8 004DD9F8 5A67130C */  jal        func_004d9d68
    /* 3DD9FC 004DD9FC 00000000 */   nop
    /* 3DDA00 004DDA00 7300043C */  lui        $4, %hi(D_00729A40)
    /* 3DDA04 004DDA04 2D280000 */  daddu      $5, $0, $0
    /* 3DDA08 004DDA08 409A8424 */  addiu      $4, $4, %lo(D_00729A40)
    /* 3DDA0C 004DDA0C 72FE100C */  jal        func_0043f9c8
    /* 3DDA10 004DDA10 40000624 */   addiu     $6, $0, 0x40
    /* 3DDA14 004DDA14 0000058E */  lw         $5, 0x0($16)
    /* 3DDA18 004DDA18 0100A224 */  addiu      $2, $5, 0x1
  .L004DDA1C:
    /* 3DDA1C 004DDA1C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DDA20 004DDA20 000002AE */  sw         $2, 0x0($16)
    /* 3DDA24 004DDA24 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDA28 004DDA28 0800E003 */  jr         $31
    /* 3DDA2C 004DDA2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004dd9c8, 0x68

.section .text
.set noat
.set noreorder
glabel func_004cb240
    /* 3CB240 004CB240 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB244 004CB244 06008014 */  bnez       $4, .L004CB260
    /* 3CB248 004CB248 0000BFFF */   sd        $31, 0x0($29)
    /* 3CB24C 004CB24C 7600043C */  lui        $4, %hi(D_007588B0)
    /* 3CB250 004CB250 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB254 004CB254 B0888424 */  addiu      $4, $4, %lo(D_007588B0)
    /* 3CB258 004CB258 A61A1308 */  j          func_004c6a98
    /* 3CB25C 004CB25C 1000BD27 */   addiu     $29, $29, 0x10
  .L004CB260:
    /* 3CB260 004CB260 01008280 */  lb         $2, 0x1($4)
    /* 3CB264 004CB264 04004014 */  bnez       $2, .L004CB278
    /* 3CB268 004CB268 0000BFDF */   ld        $31, 0x0($29)
    /* 3CB26C 004CB26C 9400848C */  lw         $4, 0x94($4)
    /* 3CB270 004CB270 94A41308 */  j          func_004e9250
    /* 3CB274 004CB274 1000BD27 */   addiu     $29, $29, 0x10
  .L004CB278:
    /* 3CB278 004CB278 0800E003 */  jr         $31
    /* 3CB27C 004CB27C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb240, 0x40

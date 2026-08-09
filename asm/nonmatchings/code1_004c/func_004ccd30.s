.section .text
.set noat
.set noreorder
glabel func_004ccd30
    /* 3CCD30 004CCD30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CCD34 004CCD34 2D108000 */  daddu      $2, $4, $0
    /* 3CCD38 004CCD38 0F004010 */  beqz       $2, .L004CCD78
    /* 3CCD3C 004CCD3C 2000BFFF */   sd        $31, 0x20($29)
    /* 3CCD40 004CCD40 0800468C */  lw         $6, 0x8($2)
    /* 3CCD44 004CCD44 19000724 */  addiu      $7, $0, 0x19
    /* 3CCD48 004CCD48 0C00448C */  lw         $4, 0xC($2)
    /* 3CCD4C 004CCD4C 2D40A003 */  daddu      $8, $29, $0
    /* 3CCD50 004CCD50 0000438C */  lw         $3, 0x0($2)
    /* 3CCD54 004CCD54 0100C524 */  addiu      $5, $6, 0x1
    /* 3CCD58 004CCD58 0400428C */  lw         $2, 0x4($2)
    /* 3CCD5C 004CCD5C 1000A4AF */  sw         $4, 0x10($29)
    /* 3CCD60 004CCD60 0000A3AF */  sw         $3, 0x0($29)
    /* 3CCD64 004CCD64 0400A2AF */  sw         $2, 0x4($29)
    /* 3CCD68 004CCD68 0C00A5AF */  sw         $5, 0xC($29)
    /* 3CCD6C 004CCD6C 1400A7AF */  sw         $7, 0x14($29)
    /* 3CCD70 004CCD70 02000010 */  b          .L004CCD7C
    /* 3CCD74 004CCD74 0800A6AF */   sw        $6, 0x8($29)
  .L004CCD78:
    /* 3CCD78 004CCD78 2D400000 */  daddu      $8, $0, $0
  .L004CCD7C:
    /* 3CCD7C 004CCD7C 8630130C */  jal        func_004cc218
    /* 3CCD80 004CCD80 2D200001 */   daddu     $4, $8, $0
    /* 3CCD84 004CCD84 2000BFDF */  ld         $31, 0x20($29)
    /* 3CCD88 004CCD88 0800E003 */  jr         $31
    /* 3CCD8C 004CCD8C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004ccd30, 0x60

.section .text
.set noat
.set noreorder
glabel func_004dee48
    /* 3DEE48 004DEE48 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DEE4C 004DEE4C 1000B0FF */  sd         $16, 0x10($29)
    /* 3DEE50 004DEE50 2D80A000 */  daddu      $16, $5, $0
    /* 3DEE54 004DEE54 1800B1FF */  sd         $17, 0x18($29)
    /* 3DEE58 004DEE58 2D88C000 */  daddu      $17, $6, $0
    /* 3DEE5C 004DEE5C 2000BFFF */  sd         $31, 0x20($29)
    /* 3DEE60 004DEE60 2D28A003 */  daddu      $5, $29, $0
    /* 3DEE64 004DEE64 06008014 */  bnez       $4, .L004DEE80
    /* 3DEE68 004DEE68 0400A627 */   addiu     $6, $29, 0x4
    /* 3DEE6C 004DEE6C 7600043C */  lui        $4, %hi(D_007597F8)
    /* 3DEE70 004DEE70 B078130C */  jal        func_004de2c0
    /* 3DEE74 004DEE74 F8978424 */   addiu     $4, $4, %lo(D_007597F8)
    /* 3DEE78 004DEE78 0C000010 */  b          .L004DEEAC
    /* 3DEE7C 004DEE7C 1000B0DF */   ld        $16, 0x10($29)
  .L004DEE80:
    /* 3DEE80 004DEE80 0C00848C */  lw         $4, 0xC($4)
    /* 3DEE84 004DEE84 0000A0AF */  sw         $0, 0x0($29)
    /* 3DEE88 004DEE88 DE51130C */  jal        func_004d4778
    /* 3DEE8C 004DEE8C 0400A0AF */   sw        $0, 0x4($29)
    /* 3DEE90 004DEE90 02000012 */  beqz       $16, .L004DEE9C
    /* 3DEE94 004DEE94 0000A28F */   lw        $2, 0x0($29)
    /* 3DEE98 004DEE98 000002AE */  sw         $2, 0x0($16)
  .L004DEE9C:
    /* 3DEE9C 004DEE9C 02002012 */  beqz       $17, .L004DEEA8
    /* 3DEEA0 004DEEA0 0400A28F */   lw        $2, 0x4($29)
    /* 3DEEA4 004DEEA4 000022AE */  sw         $2, 0x0($17)
  .L004DEEA8:
    /* 3DEEA8 004DEEA8 1000B0DF */  ld         $16, 0x10($29)
  .L004DEEAC:
    /* 3DEEAC 004DEEAC 1800B1DF */  ld         $17, 0x18($29)
    /* 3DEEB0 004DEEB0 2000BFDF */  ld         $31, 0x20($29)
    /* 3DEEB4 004DEEB4 0800E003 */  jr         $31
    /* 3DEEB8 004DEEB8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEEBC 004DEEBC 00000000 */  nop
.size func_004dee48, 0x78

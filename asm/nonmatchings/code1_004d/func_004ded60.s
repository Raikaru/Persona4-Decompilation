.section .text
.set noat
.set noreorder
glabel func_004ded60
    /* 3DED60 004DED60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DED64 004DED64 0000B0FF */  sd         $16, 0x0($29)
    /* 3DED68 004DED68 2D808000 */  daddu      $16, $4, $0
    /* 3DED6C 004DED6C 08000016 */  bnez       $16, .L004DED90
    /* 3DED70 004DED70 0800BFFF */   sd        $31, 0x8($29)
    /* 3DED74 004DED74 7600043C */  lui        $4, %hi(D_00759798)
    /* 3DED78 004DED78 0000B0DF */  ld         $16, 0x0($29)
    /* 3DED7C 004DED7C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DED80 004DED80 98978424 */  addiu      $4, $4, %lo(D_00759798)
    /* 3DED84 004DED84 B0781308 */  j          func_004de2c0
    /* 3DED88 004DED88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DED8C 004DED8C 00000000 */  nop
  .L004DED90:
    /* 3DED90 004DED90 FC7F130C */  jal        func_004dfff0
    /* 3DED94 004DED94 00000000 */   nop
    /* 3DED98 004DED98 0800028E */  lw         $2, 0x8($16)
    /* 3DED9C 004DED9C 03004010 */  beqz       $2, .L004DEDAC
    /* 3DEDA0 004DEDA0 2D204000 */   daddu     $4, $2, $0
    /* 3DEDA4 004DEDA4 8C48130C */  jal        func_004d2230
    /* 3DEDA8 004DEDA8 00000000 */   nop
  .L004DEDAC:
    /* 3DEDAC 004DEDAC E080130C */  jal        func_004e0380
    /* 3DEDB0 004DEDB0 00000000 */   nop
    /* 3DEDB4 004DEDB4 0400028E */  lw         $2, 0x4($16)
    /* 3DEDB8 004DEDB8 03004010 */  beqz       $2, .L004DEDC8
    /* 3DEDBC 004DEDBC 2D204000 */   daddu     $4, $2, $0
    /* 3DEDC0 004DEDC0 7481130C */  jal        func_004e05d0
    /* 3DEDC4 004DEDC4 00000000 */   nop
  .L004DEDC8:
    /* 3DEDC8 004DEDC8 DC01038E */  lw         $3, 0x1DC($16)
    /* 3DEDCC 004DEDCC 02000224 */  addiu      $2, $0, 0x2
    /* 3DEDD0 004DEDD0 0A006254 */  bnel       $3, $2, .L004DEDFC
    /* 3DEDD4 004DEDD4 AC0100AE */   sw        $0, 0x1AC($16)
    /* 3DEDD8 004DEDD8 9000028E */  lw         $2, 0x90($16)
    /* 3DEDDC 004DEDDC 900000AE */  sw         $0, 0x90($16)
    /* 3DEDE0 004DEDE0 05004010 */  beqz       $2, .L004DEDF8
    /* 3DEDE4 004DEDE4 2D204000 */   daddu     $4, $2, $0
    /* 3DEDE8 004DEDE8 0000428C */  lw         $2, 0x0($2)
    /* 3DEDEC 004DEDEC 0C00438C */  lw         $3, 0xC($2)
    /* 3DEDF0 004DEDF0 09F86000 */  jalr       $3
    /* 3DEDF4 004DEDF4 00000000 */   nop
  .L004DEDF8:
    /* 3DEDF8 004DEDF8 AC0100AE */  sw         $0, 0x1AC($16)
  .L004DEDFC:
    /* 3DEDFC 004DEDFC 900000AE */  sw         $0, 0x90($16)
    /* 3DEE00 004DEE00 010000A2 */  sb         $0, 0x1($16)
    /* 3DEE04 004DEE04 0800BFDF */  ld         $31, 0x8($29)
    /* 3DEE08 004DEE08 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEE0C 004DEE0C E6801308 */  j          func_004e0398
    /* 3DEE10 004DEE10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DEE14 004DEE14 00000000 */  nop
.size func_004ded60, 0xb8

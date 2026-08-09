.section .text
.set noat
.set noreorder
glabel func_004ddcb8
    /* 3DDCB8 004DDCB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DDCBC 004DDCBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDCC0 004DDCC0 0800BFFF */  sd         $31, 0x8($29)
    /* 3DDCC4 004DDCC4 A276130C */  jal        func_004dda88
    /* 3DDCC8 004DDCC8 2D808000 */   daddu     $16, $4, $0
    /* 3DDCCC 004DDCCC 0C00028E */  lw         $2, 0xC($16)
    /* 3DDCD0 004DDCD0 03004010 */  beqz       $2, .L004DDCE0
    /* 3DDCD4 004DDCD4 2D204000 */   daddu     $4, $2, $0
    /* 3DDCD8 004DDCD8 1E65130C */  jal        func_004d9478
    /* 3DDCDC 004DDCDC 0C0000AE */   sw        $0, 0xC($16)
  .L004DDCE0:
    /* 3DDCE0 004DDCE0 D264130C */  jal        func_004d9348
    /* 3DDCE4 004DDCE4 1000048E */   lw        $4, 0x10($16)
    /* 3DDCE8 004DDCE8 0000048E */  lw         $4, 0x0($16)
    /* 3DDCEC 004DDCEC 0C0002AE */  sw         $2, 0xC($16)
    /* 3DDCF0 004DDCF0 0668130C */  jal        func_004da018
    /* 3DDCF4 004DDCF4 2D284000 */   daddu     $5, $2, $0
    /* 3DDCF8 004DDCF8 01000224 */  addiu      $2, $0, 0x1
    /* 3DDCFC 004DDCFC 050002A2 */  sb         $2, 0x5($16)
    /* 3DDD00 004DDD00 0800BFDF */  ld         $31, 0x8($29)
    /* 3DDD04 004DDD04 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDD08 004DDD08 0800E003 */  jr         $31
    /* 3DDD0C 004DDD0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ddcb8, 0x58

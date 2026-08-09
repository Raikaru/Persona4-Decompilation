.section .text
.set noat
.set noreorder
glabel func_004da1f8
    /* 3DA1F8 004DA1F8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DA1FC 004DA1FC FFFF0224 */  addiu      $2, $0, -0x1
    /* 3DA200 004DA200 1000B2FF */  sd         $18, 0x10($29)
    /* 3DA204 004DA204 2D908000 */  daddu      $18, $4, $0
    /* 3DA208 004DA208 0000B0FF */  sd         $16, 0x0($29)
    /* 3DA20C 004DA20C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DA210 004DA210 1800B3FF */  sd         $19, 0x18($29)
    /* 3DA214 004DA214 2000BFFF */  sd         $31, 0x20($29)
    /* 3DA218 004DA218 AC01438E */  lw         $3, 0x1AC($18)
    /* 3DA21C 004DA21C 27006010 */  beqz       $3, .L004DA2BC
    /* 3DA220 004DA220 2D206000 */   daddu     $4, $3, $0
    /* 3DA224 004DA224 6666130C */  jal        func_004d9998
    /* 3DA228 004DA228 00000000 */   nop
    /* 3DA22C 004DA22C FFFF0324 */  addiu      $3, $0, -0x1
    /* 3DA230 004DA230 2D204000 */  daddu      $4, $2, $0
    /* 3DA234 004DA234 21008310 */  beq        $4, $3, .L004DA2BC
    /* 3DA238 004DA238 01001324 */   addiu     $19, $0, 0x1
    /* 3DA23C 004DA23C 1F009314 */  bne        $4, $19, .L004DA2BC
    /* 3DA240 004DA240 01000224 */   addiu     $2, $0, 0x1
    /* 3DA244 004DA244 AC01448E */  lw         $4, 0x1AC($18)
    /* 3DA248 004DA248 DA65130C */  jal        func_004d9768
    /* 3DA24C 004DA24C 14000524 */   addiu     $5, $0, 0x14
    /* 3DA250 004DA250 06004010 */  beqz       $2, .L004DA26C
    /* 3DA254 004DA254 B4015026 */   addiu     $16, $18, 0x1B4
    /* 3DA258 004DA258 AC01448E */  lw         $4, 0x1AC($18)
    /* 3DA25C 004DA25C 8C69130C */  jal        func_004da630
    /* 3DA260 004DA260 2D280002 */   daddu     $5, $16, $0
    /* 3DA264 004DA264 04004104 */  bgez       $2, .L004DA278
    /* 3DA268 004DA268 2D200002 */   daddu     $4, $16, $0
  .L004DA26C:
    /* 3DA26C 004DA26C 13000010 */  b          .L004DA2BC
    /* 3DA270 004DA270 FFFF0224 */   addiu     $2, $0, -0x1
    /* 3DA274 004DA274 00000000 */  nop
  .L004DA278:
    /* 3DA278 004DA278 E4015026 */  addiu      $16, $18, 0x1E4
    /* 3DA27C 004DA27C 20025126 */  addiu      $17, $18, 0x220
    /* 3DA280 004DA280 DA69130C */  jal        func_004da768
    /* 3DA284 004DA284 2D280002 */   daddu     $5, $16, $0
    /* 3DA288 004DA288 AC01448E */  lw         $4, 0x1AC($18)
    /* 3DA28C 004DA28C 2D280002 */  daddu      $5, $16, $0
    /* 3DA290 004DA290 146A130C */  jal        func_004da850
    /* 3DA294 004DA294 2D302002 */   daddu     $6, $17, $0
    /* 3DA298 004DA298 AC01448E */  lw         $4, 0x1AC($18)
    /* 3DA29C 004DA29C 2D280002 */  daddu      $5, $16, $0
    /* 3DA2A0 004DA2A0 2D302002 */  daddu      $6, $17, $0
    /* 3DA2A4 004DA2A4 20034726 */  addiu      $7, $18, 0x320
    /* 3DA2A8 004DA2A8 766A130C */  jal        func_004da9d8
    /* 3DA2AC 004DA2AC 20044826 */   addiu     $8, $18, 0x420
    /* 3DA2B0 004DA2B0 A50153A2 */  sb         $19, 0x1A5($18)
    /* 3DA2B4 004DA2B4 A80140AE */  sw         $0, 0x1A8($18)
    /* 3DA2B8 004DA2B8 2D100000 */  daddu      $2, $0, $0
  .L004DA2BC:
    /* 3DA2BC 004DA2BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3DA2C0 004DA2C0 0800B1DF */  ld         $17, 0x8($29)
    /* 3DA2C4 004DA2C4 1000B2DF */  ld         $18, 0x10($29)
    /* 3DA2C8 004DA2C8 1800B3DF */  ld         $19, 0x18($29)
    /* 3DA2CC 004DA2CC 2000BFDF */  ld         $31, 0x20($29)
    /* 3DA2D0 004DA2D0 0800E003 */  jr         $31
    /* 3DA2D4 004DA2D4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004da1f8, 0xe0

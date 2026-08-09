.section .text
.set noat
.set noreorder
glabel func_004ddd40
    /* 3DDD40 004DDD40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DDD44 004DDD44 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDD48 004DDD48 2D808000 */  daddu      $16, $4, $0
    /* 3DDD4C 004DDD4C 0800BFFF */  sd         $31, 0x8($29)
    /* 3DDD50 004DDD50 1000048E */  lw         $4, 0x10($16)
    /* 3DDD54 004DDD54 0000838C */  lw         $3, 0x0($4)
    /* 3DDD58 004DDD58 2400628C */  lw         $2, 0x24($3)
    /* 3DDD5C 004DDD5C 09F84000 */  jalr       $2
    /* 3DDD60 004DDD60 01000524 */   addiu     $5, $0, 0x1
    /* 3DDD64 004DDD64 24004228 */  slti       $2, $2, 0x24
    /* 3DDD68 004DDD68 0A004054 */  bnel       $2, $0, .L004DDD94
    /* 3DDD6C 004DDD6C 0000B0DF */   ld        $16, 0x0($29)
    /* 3DDD70 004DDD70 1468130C */  jal        func_004da050
    /* 3DDD74 004DDD74 0000048E */   lw        $4, 0x0($16)
    /* 3DDD78 004DDD78 7E68130C */  jal        func_004da1f8
    /* 3DDD7C 004DDD7C 0000048E */   lw        $4, 0x0($16)
    /* 3DDD80 004DDD80 01000324 */  addiu      $3, $0, 0x1
    /* 3DDD84 004DDD84 02000224 */  addiu      $2, $0, 0x2
    /* 3DDD88 004DDD88 070003A2 */  sb         $3, 0x7($16)
    /* 3DDD8C 004DDD8C 050002A2 */  sb         $2, 0x5($16)
    /* 3DDD90 004DDD90 0000B0DF */  ld         $16, 0x0($29)
  .L004DDD94:
    /* 3DDD94 004DDD94 0800BFDF */  ld         $31, 0x8($29)
    /* 3DDD98 004DDD98 0800E003 */  jr         $31
    /* 3DDD9C 004DDD9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ddd40, 0x60

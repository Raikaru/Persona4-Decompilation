.section .text
.set noat
.set noreorder
glabel func_004defe8
    /* 3DEFE8 004DEFE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DEFEC 004DEFEC 0000B0FF */  sd         $16, 0x0($29)
    /* 3DEFF0 004DEFF0 0800B1FF */  sd         $17, 0x8($29)
    /* 3DEFF4 004DEFF4 1800B4E7 */  swc1       $f20, 0x18($29)
    /* 3DEFF8 004DEFF8 1000BFFF */  sd         $31, 0x10($29)
    /* 3DEFFC 004DEFFC 327D130C */  jal        func_004df4c8
    /* 3DF000 004DF000 2D808000 */   daddu     $16, $4, $0
    /* 3DF004 004DF004 00A08044 */  mtc1       $0, $f20
    /* 3DF008 004DF008 2D884000 */  daddu      $17, $2, $0
    /* 3DF00C 004DF00C 0F002012 */  beqz       $17, .L004DF04C
    /* 3DF010 004DF010 06A00046 */   mov.s     $f0, $f20
    /* 3DF014 004DF014 9000038E */  lw         $3, 0x90($16)
    /* 3DF018 004DF018 0C006010 */  beqz       $3, .L004DF04C
    /* 3DF01C 004DF01C 2D206000 */   daddu     $4, $3, $0
    /* 3DF020 004DF020 0000638C */  lw         $3, 0x0($3)
    /* 3DF024 004DF024 2400628C */  lw         $2, 0x24($3)
    /* 3DF028 004DF028 09F84000 */  jalr       $2
    /* 3DF02C 004DF02C 01000524 */   addiu     $5, $0, 0x1
    /* 3DF030 004DF030 00089144 */  mtc1       $17, $f1
    /* 3DF034 004DF034 60088046 */  cvt.s.w    $f1, $f1
    /* 3DF038 004DF038 00008244 */  mtc1       $2, $f0
    /* 3DF03C 004DF03C 20008046 */  cvt.s.w    $f0, $f0
    /* 3DF040 004DF040 00000000 */  nop
    /* 3DF044 004DF044 00000000 */  nop
    /* 3DF048 004DF048 03000146 */  div.s      $f0, $f0, $f1
  .L004DF04C:
    /* 3DF04C 004DF04C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF050 004DF050 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF054 004DF054 1000BFDF */  ld         $31, 0x10($29)
    /* 3DF058 004DF058 1800B4C7 */  lwc1       $f20, 0x18($29)
    /* 3DF05C 004DF05C 0800E003 */  jr         $31
    /* 3DF060 004DF060 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF064 004DF064 00000000 */  nop
.size func_004defe8, 0x80

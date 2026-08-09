.section .text
.set noat
.set noreorder
glabel func_004deec0
    /* 3DEEC0 004DEEC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DEEC4 004DEEC4 2100A228 */  slti       $2, $5, 0x21
    /* 3DEEC8 004DEEC8 05008014 */  bnez       $4, .L004DEEE0
    /* 3DEECC 004DEECC 0000BFFF */   sd        $31, 0x0($29)
    /* 3DEED0 004DEED0 7600043C */  lui        $4, %hi(D_00759828)
    /* 3DEED4 004DEED4 06000010 */  b          .L004DEEF0
    /* 3DEED8 004DEED8 28988424 */   addiu     $4, $4, %lo(D_00759828)
    /* 3DEEDC 004DEEDC 00000000 */  nop
  .L004DEEE0:
    /* 3DEEE0 004DEEE0 07004014 */  bnez       $2, .L004DEF00
    /* 3DEEE4 004DEEE4 80180500 */   sll       $3, $5, 2
    /* 3DEEE8 004DEEE8 7600043C */  lui        $4, %hi(D_00759858)
    /* 3DEEEC 004DEEEC 58988424 */  addiu      $4, $4, %lo(D_00759858)
  .L004DEEF0:
    /* 3DEEF0 004DEEF0 B078130C */  jal        func_004de2c0
    /* 3DEEF4 004DEEF4 00000000 */   nop
    /* 3DEEF8 004DEEF8 03000010 */  b          .L004DEF08
    /* 3DEEFC 004DEEFC 2D100000 */   daddu     $2, $0, $0
  .L004DEF00:
    /* 3DEF00 004DEF00 21188300 */  addu       $3, $4, $3
    /* 3DEF04 004DEF04 0C00628C */  lw         $2, 0xC($3)
  .L004DEF08:
    /* 3DEF08 004DEF08 0000BFDF */  ld         $31, 0x0($29)
    /* 3DEF0C 004DEF0C 0800E003 */  jr         $31
    /* 3DEF10 004DEF10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DEF14 004DEF14 00000000 */  nop
.size func_004deec0, 0x58

.section .text
.set noat
.set noreorder
glabel func_004e3c10
    /* 3E3C10 004E3C10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E3C14 004E3C14 0000B0FF */  sd         $16, 0x0($29)
    /* 3E3C18 004E3C18 0800BFFF */  sd         $31, 0x8($29)
    /* 3E3C1C 004E3C1C 8EC1130C */  jal        func_004f0638
    /* 3E3C20 004E3C20 2D808000 */   daddu     $16, $4, $0
    /* 3E3C24 004E3C24 7600043C */  lui        $4, %hi(D_0075AAE0)
    /* 3E3C28 004E3C28 01000324 */  addiu      $3, $0, 0x1
    /* 3E3C2C 004E3C2C 06000016 */  bnez       $16, .L004E3C48
    /* 3E3C30 004E3C30 E0AA8424 */   addiu     $4, $4, %lo(D_0075AAE0)
    /* 3E3C34 004E3C34 3291100C */  jal        func_004244c8
    /* 3E3C38 004E3C38 00000000 */   nop
    /* 3E3C3C 004E3C3C 0B000010 */  b          .L004E3C6C
    /* 3E3C40 004E3C40 0000B0DF */   ld        $16, 0x0($29)
    /* 3E3C44 004E3C44 00000000 */  nop
  .L004E3C48:
    /* 3E3C48 004E3C48 0400028E */  lw         $2, 0x4($16)
    /* 3E3C4C 004E3C4C 06004354 */  bnel       $2, $3, .L004E3C68
    /* 3E3C50 004E3C50 040003AE */   sw        $3, 0x4($16)
    /* 3E3C54 004E3C54 7600043C */  lui        $4, %hi(D_0075AB00)
    /* 3E3C58 004E3C58 3291100C */  jal        func_004244c8
    /* 3E3C5C 004E3C5C 00AB8424 */   addiu     $4, $4, %lo(D_0075AB00)
    /* 3E3C60 004E3C60 02000010 */  b          .L004E3C6C
    /* 3E3C64 004E3C64 0000B0DF */   ld        $16, 0x0($29)
  .L004E3C68:
    /* 3E3C68 004E3C68 0000B0DF */  ld         $16, 0x0($29)
  .L004E3C6C:
    /* 3E3C6C 004E3C6C 0800BFDF */  ld         $31, 0x8($29)
    /* 3E3C70 004E3C70 ACC11308 */  j          func_004f06b0
    /* 3E3C74 004E3C74 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e3c10, 0x68

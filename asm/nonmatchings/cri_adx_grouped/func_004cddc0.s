.section .text
.set noat
.set noreorder
glabel func_004cddc0
    /* 3CDDC0 004CDDC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CDDC4 004CDDC4 01000524 */  addiu      $5, $0, 0x1
    /* 3CDDC8 004CDDC8 3800B3FF */  sd         $19, 0x38($29)
    /* 3CDDCC 004CDDCC 2D988000 */  daddu      $19, $4, $0
    /* 3CDDD0 004CDDD0 2000B0FF */  sd         $16, 0x20($29)
    /* 3CDDD4 004CDDD4 00C80634 */  ori        $6, $0, 0xC800
    /* 3CDDD8 004CDDD8 2800B1FF */  sd         $17, 0x28($29)
    /* 3CDDDC 004CDDDC 2D38A003 */  daddu      $7, $29, $0
    /* 3CDDE0 004CDDE0 3000B2FF */  sd         $18, 0x30($29)
    /* 3CDDE4 004CDDE4 4000B4FF */  sd         $20, 0x40($29)
    /* 3CDDE8 004CDDE8 4800BFFF */  sd         $31, 0x48($29)
    /* 3CDDEC 004CDDEC 0800708E */  lw         $16, 0x8($19)
    /* 3CDDF0 004CDDF0 0400728E */  lw         $18, 0x4($19)
    /* 3CDDF4 004CDDF4 0000038E */  lw         $3, 0x0($16)
    /* 3CDDF8 004CDDF8 1800628C */  lw         $2, 0x18($3)
    /* 3CDDFC 004CDDFC 09F84000 */  jalr       $2
    /* 3CDE00 004CDE00 2D200002 */   daddu     $4, $16, $0
    /* 3CDE04 004CDE04 0400A48F */  lw         $4, 0x4($29)
    /* 3CDE08 004CDE08 12008018 */  blez       $4, .L004CDE54
    /* 3CDE0C 004CDE0C 2D280000 */   daddu     $5, $0, $0
    /* 3CDE10 004CDE10 0000A38F */  lw         $3, 0x0($29)
    /* 3CDE14 004CDE14 00006280 */  lb         $2, 0x0($3)
    /* 3CDE18 004CDE18 0F004014 */  bnez       $2, .L004CDE58
    /* 3CDE1C 004CDE1C C2170500 */   srl       $2, $5, 31
    /* 3CDE20 004CDE20 2D308000 */  daddu      $6, $4, $0
    /* 3CDE24 004CDE24 2D206000 */  daddu      $4, $3, $0
    /* 3CDE28 004CDE28 0100A524 */  addiu      $5, $5, 0x1
    /* 3CDE2C 004CDE2C 00000000 */  nop
  .L004CDE30:
    /* 3CDE30 004CDE30 2A10A600 */  slt        $2, $5, $6
    /* 3CDE34 004CDE34 07004010 */  beqz       $2, .L004CDE54
    /* 3CDE38 004CDE38 21188500 */   addu      $3, $4, $5
    /* 3CDE3C 004CDE3C 00006280 */  lb         $2, 0x0($3)
    /* 3CDE40 004CDE40 00000000 */  nop
    /* 3CDE44 004CDE44 00000000 */  nop
    /* 3CDE48 004CDE48 00000000 */  nop
    /* 3CDE4C 004CDE4C F8FF4050 */  beql       $2, $0, .L004CDE30
    /* 3CDE50 004CDE50 0100A524 */   addiu     $5, $5, 0x1
  .L004CDE54:
    /* 3CDE54 004CDE54 C2170500 */  srl        $2, $5, 31
  .L004CDE58:
    /* 3CDE58 004CDE58 FFFFA324 */  addiu      $3, $5, -0x1
    /* 3CDE5C 004CDE5C 2110A200 */  addu       $2, $5, $2
    /* 3CDE60 004CDE60 43100200 */  sra        $2, $2, 1
    /* 3CDE64 004CDE64 40100200 */  sll        $2, $2, 1
    /* 3CDE68 004CDE68 13004314 */  bne        $2, $3, .L004CDEB8
    /* 3CDE6C 004CDE6C 1000B427 */   addiu     $20, $29, 0x10
    /* 3CDE70 004CDE70 0000038E */  lw         $3, 0x0($16)
    /* 3CDE74 004CDE74 2D200002 */  daddu      $4, $16, $0
    /* 3CDE78 004CDE78 01000524 */  addiu      $5, $0, 0x1
    /* 3CDE7C 004CDE7C 1C00628C */  lw         $2, 0x1C($3)
    /* 3CDE80 004CDE80 09F84000 */  jalr       $2
    /* 3CDE84 004CDE84 2D30A003 */   daddu     $6, $29, $0
    /* 3CDE88 004CDE88 040D130C */  jal        func_004c3410
    /* 3CDE8C 004CDE8C 00000000 */   nop
    /* 3CDE90 004CDE90 84004054 */  bnel       $2, $0, .L004CE0A4
    /* 3CDE94 004CDE94 04000224 */   addiu     $2, $0, 0x4
    /* 3CDE98 004CDE98 7600043C */  lui        $4, %hi(D_007589E0)
    /* 3CDE9C 004CDE9C 7600053C */  lui        $5, %hi(D_00758A00)
    /* 3CDEA0 004CDEA0 E0898424 */  addiu      $4, $4, %lo(D_007589E0)
    /* 3CDEA4 004CDEA4 BC1A130C */  jal        func_004c6af0
    /* 3CDEA8 004CDEA8 008AA524 */   addiu     $5, $5, %lo(D_00758A00)
    /* 3CDEAC 004CDEAC 7D000010 */  b          .L004CE0A4
    /* 3CDEB0 004CDEB0 04000224 */   addiu     $2, $0, 0x4
    /* 3CDEB4 004CDEB4 00000000 */  nop
  .L004CDEB8:
    /* 3CDEB8 004CDEB8 2D20A003 */  daddu      $4, $29, $0
    /* 3CDEBC 004CDEBC 2D308002 */  daddu      $6, $20, $0
    /* 3CDEC0 004CDEC0 2EBE130C */  jal        func_004ef8b8
    /* 3CDEC4 004CDEC4 2D38A003 */   daddu     $7, $29, $0
    /* 3CDEC8 004CDEC8 0000038E */  lw         $3, 0x0($16)
    /* 3CDECC 004CDECC 2D308002 */  daddu      $6, $20, $0
    /* 3CDED0 004CDED0 2D200002 */  daddu      $4, $16, $0
    /* 3CDED4 004CDED4 2000628C */  lw         $2, 0x20($3)
    /* 3CDED8 004CDED8 09F84000 */  jalr       $2
    /* 3CDEDC 004CDEDC 2D280000 */   daddu     $5, $0, $0
    /* 3CDEE0 004CDEE0 0400A68F */  lw         $6, 0x4($29)
    /* 3CDEE4 004CDEE4 1000C228 */  slti       $2, $6, 0x10
    /* 3CDEE8 004CDEE8 0B004054 */  bnel       $2, $0, .L004CDF18
    /* 3CDEEC 004CDEEC 0000038E */   lw        $3, 0x0($16)
    /* 3CDEF0 004CDEF0 0000A58F */  lw         $5, 0x0($29)
    /* 3CDEF4 004CDEF4 880E130C */  jal        func_004c3a20
    /* 3CDEF8 004CDEF8 2D204002 */   daddu     $4, $18, $0
    /* 3CDEFC 004CDEFC 2D884000 */  daddu      $17, $2, $0
    /* 3CDF00 004CDF00 04002012 */  beqz       $17, .L004CDF14
    /* 3CDF04 004CDF04 0400A28F */   lw        $2, 0x4($29)
    /* 3CDF08 004CDF08 2A105100 */  slt        $2, $2, $17
    /* 3CDF0C 004CDF0C 0A004010 */  beqz       $2, .L004CDF38
    /* 3CDF10 004CDF10 00000000 */   nop
  .L004CDF14:
    /* 3CDF14 004CDF14 0000038E */  lw         $3, 0x0($16)
  .L004CDF18:
    /* 3CDF18 004CDF18 2D200002 */  daddu      $4, $16, $0
    /* 3CDF1C 004CDF1C 01000524 */  addiu      $5, $0, 0x1
    /* 3CDF20 004CDF20 1C00628C */  lw         $2, 0x1C($3)
    /* 3CDF24 004CDF24 09F84000 */  jalr       $2
    /* 3CDF28 004CDF28 2D30A003 */   daddu     $6, $29, $0
    /* 3CDF2C 004CDF2C 5F000010 */  b          .L004CE0AC
    /* 3CDF30 004CDF30 2000B0DF */   ld        $16, 0x20($29)
    /* 3CDF34 004CDF34 00000000 */  nop
  .L004CDF38:
    /* 3CDF38 004CDF38 1B002306 */  bgezl      $17, .L004CDFA8
    /* 3CDF3C 004CDF3C 980071AE */   sw        $17, 0x98($19)
    /* 3CDF40 004CDF40 9A004286 */  lh         $2, 0x9A($18)
    /* 3CDF44 004CDF44 06004010 */  beqz       $2, .L004CDF60
    /* 3CDF48 004CDF48 2D204002 */   daddu     $4, $18, $0
    /* 3CDF4C 004CDF4C 600E130C */  jal        func_004c3980
    /* 3CDF50 004CDF50 2D880000 */   daddu     $17, $0, $0
    /* 3CDF54 004CDF54 14000010 */  b          .L004CDFA8
    /* 3CDF58 004CDF58 980071AE */   sw        $17, 0x98($19)
    /* 3CDF5C 004CDF5C 00000000 */  nop
  .L004CDF60:
    /* 3CDF60 004CDF60 0000038E */  lw         $3, 0x0($16)
    /* 3CDF64 004CDF64 2D200002 */  daddu      $4, $16, $0
    /* 3CDF68 004CDF68 01000524 */  addiu      $5, $0, 0x1
    /* 3CDF6C 004CDF6C 1C00628C */  lw         $2, 0x1C($3)
    /* 3CDF70 004CDF70 09F84000 */  jalr       $2
    /* 3CDF74 004CDF74 2D30A003 */   daddu     $6, $29, $0
    /* 3CDF78 004CDF78 040D130C */  jal        func_004c3410
    /* 3CDF7C 004CDF7C 00000000 */   nop
    /* 3CDF80 004CDF80 48004054 */  bnel       $2, $0, .L004CE0A4
    /* 3CDF84 004CDF84 04000224 */   addiu     $2, $0, 0x4
    /* 3CDF88 004CDF88 7600043C */  lui        $4, %hi(D_00758A20)
    /* 3CDF8C 004CDF8C 7600053C */  lui        $5, %hi(D_00758A40)
    /* 3CDF90 004CDF90 208A8424 */  addiu      $4, $4, %lo(D_00758A20)
    /* 3CDF94 004CDF94 BC1A130C */  jal        func_004c6af0
    /* 3CDF98 004CDF98 408AA524 */   addiu     $5, $5, %lo(D_00758A40)
    /* 3CDF9C 004CDF9C 41000010 */  b          .L004CE0A4
    /* 3CDFA0 004CDFA0 04000224 */   addiu     $2, $0, 0x4
    /* 3CDFA4 004CDFA4 00000000 */  nop
  .L004CDFA8:
    /* 3CDFA8 004CDFA8 F00E130C */  jal        func_004c3bc0
    /* 3CDFAC 004CDFAC 2D204002 */   daddu     $4, $18, $0
    /* 3CDFB0 004CDFB0 04000324 */  addiu      $3, $0, 0x4
    /* 3CDFB4 004CDFB4 02004314 */  bne        $2, $3, .L004CDFC0
    /* 3CDFB8 004CDFB8 01000224 */   addiu     $2, $0, 0x1
    /* 3CDFBC 004CDFBC 030062A2 */  sb         $2, 0x3($19)
  .L004CDFC0:
    /* 3CDFC0 004CDFC0 F00E130C */  jal        func_004c3bc0
    /* 3CDFC4 004CDFC4 2D204002 */   daddu     $4, $18, $0
    /* 3CDFC8 004CDFC8 02000324 */  addiu      $3, $0, 0x2
    /* 3CDFCC 004CDFCC 07004314 */  bne        $2, $3, .L004CDFEC
    /* 3CDFD0 004CDFD0 40000324 */   addiu     $3, $0, 0x40
    /* 3CDFD4 004CDFD4 0400A68F */  lw         $6, 0x4($29)
    /* 3CDFD8 004CDFD8 0000A58F */  lw         $5, 0x0($29)
    /* 3CDFDC 004CDFDC 58006426 */  addiu      $4, $19, 0x58
    /* 3CDFE0 004CDFE0 4100C228 */  slti       $2, $6, 0x41
    /* 3CDFE4 004CDFE4 04FE100C */  jal        func_0043f810
    /* 3CDFE8 004CDFE8 0A306200 */   movz      $6, $3, $2
  .L004CDFEC:
    /* 3CDFEC 004CDFEC F00E130C */  jal        func_004c3bc0
    /* 3CDFF0 004CDFF0 2D204002 */   daddu     $4, $18, $0
    /* 3CDFF4 004CDFF4 2D184000 */  daddu      $3, $2, $0
    /* 3CDFF8 004CDFF8 F6FF6224 */  addiu      $2, $3, -0xA
    /* 3CDFFC 004CDFFC 0300422C */  sltiu      $2, $2, 0x3
    /* 3CE000 004CE000 07004054 */  bnel       $2, $0, .L004CE020
    /* 3CE004 004CE004 0000038E */   lw        $3, 0x0($16)
    /* 3CE008 004CE008 14000224 */  addiu      $2, $0, 0x14
    /* 3CE00C 004CE00C 03006210 */  beq        $3, $2, .L004CE01C
    /* 3CE010 004CE010 0F000224 */   addiu     $2, $0, 0xF
    /* 3CE014 004CE014 0A006214 */  bne        $3, $2, .L004CE040
    /* 3CE018 004CE018 2D20A003 */   daddu     $4, $29, $0
  .L004CE01C:
    /* 3CE01C 004CE01C 0000038E */  lw         $3, 0x0($16)
  .L004CE020:
    /* 3CE020 004CE020 2D200002 */  daddu      $4, $16, $0
    /* 3CE024 004CE024 01000524 */  addiu      $5, $0, 0x1
    /* 3CE028 004CE028 1C00628C */  lw         $2, 0x1C($3)
    /* 3CE02C 004CE02C 09F84000 */  jalr       $2
    /* 3CE030 004CE030 2D30A003 */   daddu     $6, $29, $0
    /* 3CE034 004CE034 13000010 */  b          .L004CE084
    /* 3CE038 004CE038 E800428E */   lw        $2, 0xE8($18)
    /* 3CE03C 004CE03C 00000000 */  nop
  .L004CE040:
    /* 3CE040 004CE040 2D30A003 */  daddu      $6, $29, $0
    /* 3CE044 004CE044 2D282002 */  daddu      $5, $17, $0
    /* 3CE048 004CE048 2EBE130C */  jal        func_004ef8b8
    /* 3CE04C 004CE04C 2D388002 */   daddu     $7, $20, $0
    /* 3CE050 004CE050 0000038E */  lw         $3, 0x0($16)
    /* 3CE054 004CE054 2D200002 */  daddu      $4, $16, $0
    /* 3CE058 004CE058 2D280000 */  daddu      $5, $0, $0
    /* 3CE05C 004CE05C 2000628C */  lw         $2, 0x20($3)
    /* 3CE060 004CE060 09F84000 */  jalr       $2
    /* 3CE064 004CE064 2D30A003 */   daddu     $6, $29, $0
    /* 3CE068 004CE068 0000038E */  lw         $3, 0x0($16)
    /* 3CE06C 004CE06C 2D200002 */  daddu      $4, $16, $0
    /* 3CE070 004CE070 2D308002 */  daddu      $6, $20, $0
    /* 3CE074 004CE074 1C00628C */  lw         $2, 0x1C($3)
    /* 3CE078 004CE078 09F84000 */  jalr       $2
    /* 3CE07C 004CE07C 01000524 */   addiu     $5, $0, 0x1
    /* 3CE080 004CE080 E800428E */  lw         $2, 0xE8($18)
  .L004CE084:
    /* 3CE084 004CE084 06004010 */  beqz       $2, .L004CE0A0
    /* 3CE088 004CE088 7200023C */   lui       $2, %hi(D_007212E4)
    /* 3CE08C 004CE08C E412428C */  lw         $2, %lo(D_007212E4)($2)
    /* 3CE090 004CE090 03004010 */  beqz       $2, .L004CE0A0
    /* 3CE094 004CE094 2D204002 */   daddu     $4, $18, $0
    /* 3CE098 004CE098 09F84000 */  jalr       $2
    /* 3CE09C 004CE09C 1400858C */   lw        $5, 0x14($4)
  .L004CE0A0:
    /* 3CE0A0 004CE0A0 02000224 */  addiu      $2, $0, 0x2
  .L004CE0A4:
    /* 3CE0A4 004CE0A4 010062A2 */  sb         $2, 0x1($19)
    /* 3CE0A8 004CE0A8 2000B0DF */  ld         $16, 0x20($29)
  .L004CE0AC:
    /* 3CE0AC 004CE0AC 2800B1DF */  ld         $17, 0x28($29)
    /* 3CE0B0 004CE0B0 3000B2DF */  ld         $18, 0x30($29)
    /* 3CE0B4 004CE0B4 3800B3DF */  ld         $19, 0x38($29)
    /* 3CE0B8 004CE0B8 4000B4DF */  ld         $20, 0x40($29)
    /* 3CE0BC 004CE0BC 4800BFDF */  ld         $31, 0x48($29)
    /* 3CE0C0 004CE0C0 0800E003 */  jr         $31
    /* 3CE0C4 004CE0C4 5000BD27 */   addiu     $29, $29, 0x50
.size func_004cddc0, 0x308

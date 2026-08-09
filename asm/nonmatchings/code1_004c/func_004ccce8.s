.section .text
.set noat
.set noreorder
glabel func_004ccce8
    /* 3CCCE8 004CCCE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCCEC 004CCCEC 7200023C */  lui        $2, %hi(D_00719AA8)
    /* 3CCCF0 004CCCF0 0000B0FF */  sd         $16, 0x0($29)
    /* 3CCCF4 004CCCF4 A89A5024 */  addiu      $16, $2, %lo(D_00719AA8)
    /* 3CCCF8 004CCCF8 0000038E */  lw         $3, 0x0($16)
    /* 3CCCFC 004CCCFC 07006014 */  bnez       $3, .L004CCD1C
    /* 3CCD00 004CCD00 0800BFFF */   sd        $31, 0x8($29)
    /* 3CCD04 004CCD04 01000224 */  addiu      $2, $0, 0x1
    /* 3CCD08 004CCD08 CC56130C */  jal        func_004d5b30
    /* 3CCD0C 004CCD0C 000002AE */   sw        $2, 0x0($16)
    /* 3CCD10 004CCD10 5227130C */  jal        func_004c9d48
    /* 3CCD14 004CCD14 00000000 */   nop
    /* 3CCD18 004CCD18 000000AE */  sw         $0, 0x0($16)
  .L004CCD1C:
    /* 3CCD1C 004CCD1C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CCD20 004CCD20 2D100000 */  daddu      $2, $0, $0
    /* 3CCD24 004CCD24 0800BFDF */  ld         $31, 0x8($29)
    /* 3CCD28 004CCD28 0800E003 */  jr         $31
    /* 3CCD2C 004CCD2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ccce8, 0x48

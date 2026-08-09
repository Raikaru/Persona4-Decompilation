.section .text
.set noat
.set noreorder
glabel func_004ccda8
    /* 3CCDA8 004CCDA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCDAC 004CCDAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CCDB0 004CCDB0 0800BFFF */  sd         $31, 0x8($29)
    /* 3CCDB4 004CCDB4 7432130C */  jal        func_004cc9d0
    /* 3CCDB8 004CCDB8 00000000 */   nop
    /* 3CCDBC 004CCDBC 7200023C */  lui        $2, %hi(D_00719AA8)
    /* 3CCDC0 004CCDC0 A89A5024 */  addiu      $16, $2, %lo(D_00719AA8)
    /* 3CCDC4 004CCDC4 0000038E */  lw         $3, 0x0($16)
    /* 3CCDC8 004CCDC8 0D006054 */  bnel       $3, $0, .L004CCE00
    /* 3CCDCC 004CCDCC 0000B0DF */   ld        $16, 0x0($29)
    /* 3CCDD0 004CCDD0 01000224 */  addiu      $2, $0, 0x1
    /* 3CCDD4 004CCDD4 7A32130C */  jal        func_004cc9e8
    /* 3CCDD8 004CCDD8 000002AE */   sw        $2, 0x0($16)
    /* 3CCDDC 004CCDDC CC56130C */  jal        func_004d5b30
    /* 3CCDE0 004CCDE0 00000000 */   nop
    /* 3CCDE4 004CCDE4 5227130C */  jal        func_004c9d48
    /* 3CCDE8 004CCDE8 00000000 */   nop
    /* 3CCDEC 004CCDEC 000000AE */  sw         $0, 0x0($16)
    /* 3CCDF0 004CCDF0 0800BFDF */  ld         $31, 0x8($29)
    /* 3CCDF4 004CCDF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CCDF8 004CCDF8 0800E003 */  jr         $31
    /* 3CCDFC 004CCDFC 1000BD27 */   addiu     $29, $29, 0x10
  .L004CCE00:
    /* 3CCE00 004CCE00 0800BFDF */  ld         $31, 0x8($29)
    /* 3CCE04 004CCE04 7A321308 */  j          func_004cc9e8
    /* 3CCE08 004CCE08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCE0C 004CCE0C 00000000 */  nop
.size func_004ccda8, 0x68

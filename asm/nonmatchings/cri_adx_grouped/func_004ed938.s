.section .text
.set noat
.set noreorder
glabel func_004ed938
    /* 3ED938 004ED938 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED93C 004ED93C 08008014 */  bnez       $4, .L004ED960
    /* 3ED940 004ED940 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED944 004ED944 7600043C */  lui        $4, %hi(D_0075CCD0)
    /* 3ED948 004ED948 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3ED94C 004ED94C 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED950 004ED950 D0CC8424 */  addiu      $4, $4, %lo(D_0075CCD0)
    /* 3ED954 004ED954 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3ED958 004ED958 2EB51308 */  j          func_004ed4b8
    /* 3ED95C 004ED95C 1000BD27 */   addiu     $29, $29, 0x10
  .L004ED960:
    /* 3ED960 004ED960 0400828C */  lw         $2, 0x4($4)
    /* 3ED964 004ED964 08004054 */  bnel       $2, $0, .L004ED988
    /* 3ED968 004ED968 1800828C */   lw        $2, 0x18($4)
    /* 3ED96C 004ED96C 7600043C */  lui        $4, %hi(D_0075CCE0)
    /* 3ED970 004ED970 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3ED974 004ED974 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED978 004ED978 E0CC8424 */  addiu      $4, $4, %lo(D_0075CCE0)
    /* 3ED97C 004ED97C 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3ED980 004ED980 2EB51308 */  j          func_004ed4b8
    /* 3ED984 004ED984 1000BD27 */   addiu     $29, $29, 0x10
  .L004ED988:
    /* 3ED988 004ED988 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED98C 004ED98C 100080AC */  sw         $0, 0x10($4)
    /* 3ED990 004ED990 0C0082AC */  sw         $2, 0xC($4)
    /* 3ED994 004ED994 0800E003 */  jr         $31
    /* 3ED998 004ED998 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED99C 004ED99C 00000000 */  nop
.size func_004ed938, 0x68

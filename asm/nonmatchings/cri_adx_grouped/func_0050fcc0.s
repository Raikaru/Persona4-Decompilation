.section .text
.set noat
.set noreorder
glabel func_0050fcc0
    /* 40FCC0 0050FCC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40FCC4 0050FCC4 1000B0FF */  sd         $16, 0x10($29)
    /* 40FCC8 0050FCC8 1800BFFF */  sd         $31, 0x18($29)
    /* 40FCCC 0050FCCC 3A3B140C */  jal        func_0050ece8
    /* 40FCD0 0050FCD0 2D808000 */   daddu     $16, $4, $0
    /* 40FCD4 0050FCD4 1400058E */  lw         $5, 0x14($16)
    /* 40FCD8 0050FCD8 2D304000 */  daddu      $6, $2, $0
    /* 40FCDC 0050FCDC 1000048E */  lw         $4, 0x10($16)
    /* 40FCE0 0050FCE0 2D38A003 */  daddu      $7, $29, $0
    /* 40FCE4 0050FCE4 0400A827 */  addiu      $8, $29, 0x4
    /* 40FCE8 0050FCE8 62AD140C */  jal        func_0052b588
    /* 40FCEC 0050FCEC 0800A927 */   addiu     $9, $29, 0x8
    /* 40FCF0 0050FCF0 1000B0DF */  ld         $16, 0x10($29)
    /* 40FCF4 0050FCF4 1800BFDF */  ld         $31, 0x18($29)
    /* 40FCF8 0050FCF8 0800E003 */  jr         $31
    /* 40FCFC 0050FCFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050fcc0, 0x40

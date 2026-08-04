.section .text
.set noat
.set noreorder
glabel func_0043de58
    /* 33DE58 0043DE58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33DE5C 0043DE5C 0000B0FF */  sd         $16, 0x0($29)
    /* 33DE60 0043DE60 1000B2FF */  sd         $18, 0x10($29)
    /* 33DE64 0043DE64 58001024 */  addiu      $16, $0, 0x58
    /* 33DE68 0043DE68 0800B1FF */  sd         $17, 0x8($29)
    /* 33DE6C 0043DE6C 1880B000 */  mult       $16, $5, $16
    /* 33DE70 0043DE70 1800BFFF */  sd         $31, 0x18($29)
    /* 33DE74 0043DE74 2D90A000 */  daddu      $18, $5, $0
    /* 33DE78 0043DE78 E0FB100C */  jal        func_0043ef80
    /* 33DE7C 0043DE7C 0C000526 */   addiu     $5, $16, 0xC
    /* 33DE80 0043DE80 0C004F24 */  addiu      $15, $2, 0xC
    /* 33DE84 0043DE84 2D884000 */  daddu      $17, $2, $0
    /* 33DE88 0043DE88 2D300002 */  daddu      $6, $16, $0
    /* 33DE8C 0043DE8C 2D20E001 */  daddu      $4, $15, $0
    /* 33DE90 0043DE90 2D280000 */  daddu      $5, $0, $0
    /* 33DE94 0043DE94 06002012 */  beqz       $17, .L0043DEB0
    /* 33DE98 0043DE98 2D100000 */   daddu     $2, $0, $0
    /* 33DE9C 0043DE9C 040032AE */  sw         $18, 0x4($17)
    /* 33DEA0 0043DEA0 000020AE */  sw         $0, 0x0($17)
    /* 33DEA4 0043DEA4 72FE100C */  jal        func_0043f9c8
    /* 33DEA8 0043DEA8 08002FAE */   sw        $15, 0x8($17)
    /* 33DEAC 0043DEAC 2D102002 */  daddu      $2, $17, $0
  .L0043DEB0:
    /* 33DEB0 0043DEB0 0000B0DF */  ld         $16, 0x0($29)
    /* 33DEB4 0043DEB4 0800B1DF */  ld         $17, 0x8($29)
    /* 33DEB8 0043DEB8 1000B2DF */  ld         $18, 0x10($29)
    /* 33DEBC 0043DEBC 1800BFDF */  ld         $31, 0x18($29)
    /* 33DEC0 0043DEC0 0800E003 */  jr         $31
    /* 33DEC4 0043DEC4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0043de58, 0x70

.section .text
.set noat
.set noreorder
glabel func_003be910
    /* 2BE910 003BE910 6C00828C */  lw         $2, 0x6C($4)
    /* 2BE914 003BE914 06004010 */  beqz       $2, .L003BE930
    /* 2BE918 003BE918 00000000 */   nop
    /* 2BE91C 003BE91C 2C00428C */  lw         $2, 0x2C($2)
    /* 2BE920 003BE920 03004010 */  beqz       $2, .L003BE930
    /* 2BE924 003BE924 00000000 */   nop
    /* 2BE928 003BE928 02000010 */  b          .L003BE934
    /* 2BE92C 003BE92C 08000224 */   addiu     $2, $0, 0x8
  .L003BE930:
    /* 2BE930 003BE930 2D100000 */  daddu      $2, $0, $0
  .L003BE934:
    /* 2BE934 003BE934 0800E003 */  jr         $31
    /* 2BE938 003BE938 00000000 */   nop
    /* 2BE93C 003BE93C 00000000 */  nop
.size func_003be910, 0x30

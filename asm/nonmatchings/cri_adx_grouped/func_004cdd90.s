.section .text
.set noat
.set noreorder
glabel func_004cdd90
    /* 3CDD90 004CDD90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CDD94 004CDD94 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDD98 004CDD98 2D808000 */  daddu      $16, $4, $0
    /* 3CDD9C 004CDD9C 0800BFFF */  sd         $31, 0x8($29)
    /* 3CDDA0 004CDDA0 FC0F130C */  jal        func_004c3ff0
    /* 3CDDA4 004CDDA4 0400048E */   lw        $4, 0x4($16)
    /* 3CDDA8 004CDDA8 010000A2 */  sb         $0, 0x1($16)
    /* 3CDDAC 004CDDAC 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDDB0 004CDDB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDDB4 004CDDB4 0800E003 */  jr         $31
    /* 3CDDB8 004CDDB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CDDBC 004CDDBC 00000000 */  nop
.size func_004cdd90, 0x30

.section .text
.set noat
.set noreorder
glabel func_004f5bd0
    /* 3F5BD0 004F5BD0 7400023C */  lui        $2, %hi(D_00743A50)
    /* 3F5BD4 004F5BD4 503A438C */  lw         $3, %lo(D_00743A50)($2)
    /* 3F5BD8 004F5BD8 03006010 */  beqz       $3, .L004F5BE8
    /* 3F5BDC 004F5BDC 10270224 */   addiu     $2, $0, 0x2710
    /* 3F5BE0 004F5BE0 18108200 */  mult       $2, $4, $2
    /* 3F5BE4 004F5BE4 1C0062AC */  sw         $2, 0x1C($3)
  .L004F5BE8:
    /* 3F5BE8 004F5BE8 0800E003 */  jr         $31
    /* 3F5BEC 004F5BEC 00000000 */   nop
.size func_004f5bd0, 0x20

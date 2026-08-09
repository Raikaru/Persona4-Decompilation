.section .text
.set noat
.set noreorder
glabel func_00529f98
    /* 429F98 00529F98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 429F9C 00529F9C FFFF0224 */  addiu      $2, $0, -0x1
    /* 429FA0 00529FA0 1000B2FF */  sd         $18, 0x10($29)
    /* 429FA4 00529FA4 2D90C000 */  daddu      $18, $6, $0
    /* 429FA8 00529FA8 0000B0FF */  sd         $16, 0x0($29)
    /* 429FAC 00529FAC FF00B030 */  andi       $16, $5, 0xFF
    /* 429FB0 00529FB0 000042AE */  sw         $2, 0x0($18)
    /* 429FB4 00529FB4 0800B1FF */  sd         $17, 0x8($29)
    /* 429FB8 00529FB8 1800BFFF */  sd         $31, 0x18($29)
    /* 429FBC 00529FBC BEA6140C */  jal        func_00529af8
    /* 429FC0 00529FC0 2D280002 */   daddu     $5, $16, $0
    /* 429FC4 00529FC4 2D884000 */  daddu      $17, $2, $0
    /* 429FC8 00529FC8 2D200002 */  daddu      $4, $16, $0
    /* 429FCC 00529FCC 08002012 */  beqz       $17, .L00529FF0
    /* 429FD0 00529FD0 2D282002 */   daddu     $5, $17, $0
    /* 429FD4 00529FD4 ECA8140C */  jal        func_0052a3b0
    /* 429FD8 00529FD8 00000000 */   nop
    /* 429FDC 00529FDC 05004010 */  beqz       $2, .L00529FF4
    /* 429FE0 00529FE0 0000B0DF */   ld        $16, 0x0($29)
    /* 429FE4 00529FE4 22002392 */  lbu        $3, 0x22($17)
    /* 429FE8 00529FE8 01000224 */  addiu      $2, $0, 0x1
    /* 429FEC 00529FEC 000043AE */  sw         $3, 0x0($18)
  .L00529FF0:
    /* 429FF0 00529FF0 0000B0DF */  ld         $16, 0x0($29)
  .L00529FF4:
    /* 429FF4 00529FF4 0800B1DF */  ld         $17, 0x8($29)
    /* 429FF8 00529FF8 1000B2DF */  ld         $18, 0x10($29)
    /* 429FFC 00529FFC 1800BFDF */  ld         $31, 0x18($29)
    /* 42A000 0052A000 0800E003 */  jr         $31
    /* 42A004 0052A004 2000BD27 */   addiu     $29, $29, 0x20
.size func_00529f98, 0x70

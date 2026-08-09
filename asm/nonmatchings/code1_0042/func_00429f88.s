.section .text
.set noat
.set noreorder
glabel func_00429f88
    /* 329F88 00429F88 7100023C */  lui        $2, %hi(D_0070C698)
    /* 329F8C 00429F8C D0FFBD27 */  addiu      $29, $29, -0x30
    /* 329F90 00429F90 98C6438C */  lw         $3, %lo(D_0070C698)($2)
    /* 329F94 00429F94 2000BFFF */  sd         $31, 0x20($29)
    /* 329F98 00429F98 03006104 */  bgez       $3, .L00429FA8
    /* 329F9C 00429F9C 1000B0FF */   sd        $16, 0x10($29)
    /* 329FA0 00429FA0 11000010 */  b          .L00429FE8
    /* 329FA4 00429FA4 2D100000 */   daddu     $2, $0, $0
  .L00429FA8:
    /* 329FA8 00429FA8 8900043C */  lui        $4, %hi(D_00890F80)
    /* 329FAC 00429FAC 8900103C */  lui        $16, %hi(D_00890FC0)
    /* 329FB0 00429FB0 800F8424 */  addiu      $4, $4, %lo(D_00890F80)
    /* 329FB4 00429FB4 0000A0AF */  sw         $0, 0x0($29)
    /* 329FB8 00429FB8 06000524 */  addiu      $5, $0, 0x6
    /* 329FBC 00429FBC 2D300000 */  daddu      $6, $0, $0
    /* 329FC0 00429FC0 2D380000 */  daddu      $7, $0, $0
    /* 329FC4 00429FC4 2D400000 */  daddu      $8, $0, $0
    /* 329FC8 00429FC8 C00F0926 */  addiu      $9, $16, %lo(D_00890FC0)
    /* 329FCC 00429FCC 04000A24 */  addiu      $10, $0, 0x4
    /* 329FD0 00429FD0 2C96100C */  jal        func_004258b0
    /* 329FD4 00429FD4 2D580000 */   daddu     $11, $0, $0
    /* 329FD8 00429FD8 03004304 */  bgezl      $2, .L00429FE8
    /* 329FDC 00429FDC C00F028E */   lw        $2, %lo(D_00890FC0)($16)
    /* 329FE0 00429FE0 FFFF023C */  lui        $2, (0xFFFFFFFF >> 16)
    /* 329FE4 00429FE4 FFFF4234 */  ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
  .L00429FE8:
    /* 329FE8 00429FE8 2000BFDF */  ld         $31, 0x20($29)
    /* 329FEC 00429FEC 1000B0DF */  ld         $16, 0x10($29)
    /* 329FF0 00429FF0 0800E003 */  jr         $31
    /* 329FF4 00429FF4 3000BD27 */   addiu     $29, $29, 0x30
.size func_00429f88, 0x70

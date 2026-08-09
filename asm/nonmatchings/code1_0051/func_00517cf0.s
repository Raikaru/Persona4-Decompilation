.section .text
.set noat
.set noreorder
glabel func_00517cf0
    /* 417CF0 00517CF0 06008010 */  beqz       $4, .L00517D0C
    /* 417CF4 00517CF4 FFFF0224 */   addiu     $2, $0, -0x1
    /* 417CF8 00517CF8 4800838C */  lw         $3, 0x48($4)
    /* 417CFC 00517CFC 03006010 */  beqz       $3, .L00517D0C
    /* 417D00 00517D00 7400033C */   lui       $3, %hi(D_007458B8)
    /* 417D04 00517D04 2D100000 */  daddu      $2, $0, $0
    /* 417D08 00517D08 B85864AC */  sw         $4, %lo(D_007458B8)($3)
  .L00517D0C:
    /* 417D0C 00517D0C 0800E003 */  jr         $31
    /* 417D10 00517D10 00000000 */   nop
    /* 417D14 00517D14 00000000 */  nop
.size func_00517cf0, 0x28

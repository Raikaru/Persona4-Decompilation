.section .text
.set noat
.set noreorder
glabel func_0052bb88
    /* 42BB88 0052BB88 14008424 */  addiu      $4, $4, 0x14
    /* 42BB8C 0052BB8C 01000324 */  addiu      $3, $0, 0x1
    /* 42BB90 0052BB90 0000828C */  lw         $2, 0x0($4)
    /* 42BB94 0052BB94 04004350 */  beql       $2, $3, .L0052BBA8
    /* 42BB98 0052BB98 0800828C */   lw        $2, 0x8($4)
    /* 42BB9C 0052BB9C 0000A0AC */  sw         $0, 0x0($5)
    /* 42BBA0 0052BBA0 0800E003 */  jr         $31
    /* 42BBA4 0052BBA4 0000C0AC */   sw        $0, 0x0($6)
  .L0052BBA8:
    /* 42BBA8 0052BBA8 0400838C */  lw         $3, 0x4($4)
    /* 42BBAC 0052BBAC 0000C2AC */  sw         $2, 0x0($6)
    /* 42BBB0 0052BBB0 0800E003 */  jr         $31
    /* 42BBB4 0052BBB4 0000A3AC */   sw        $3, 0x0($5)
.size func_0052bb88, 0x30

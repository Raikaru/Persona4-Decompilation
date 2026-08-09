.section .text
.set noat
.set noreorder
glabel func_0043c710
    /* 33C710 0043C710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33C714 0043C714 2D788000 */  daddu      $15, $4, $0
    /* 33C718 0043C718 0000BFFF */  sd         $31, 0x0($29)
    /* 33C71C 0043C71C 71000E3C */  lui        $14, %hi(D_00710070)
    /* 33C720 0043C720 2D30A000 */  daddu      $6, $5, $0
    /* 33C724 0043C724 7000C48D */  lw         $4, %lo(D_00710070)($14)
    /* 33C728 0043C728 0000BFDF */  ld         $31, 0x0($29)
    /* 33C72C 0043C72C 2D28E001 */  daddu      $5, $15, $0
    /* 33C730 0043C730 CEF11008 */  j          func_0043c738
    /* 33C734 0043C734 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043c710, 0x28

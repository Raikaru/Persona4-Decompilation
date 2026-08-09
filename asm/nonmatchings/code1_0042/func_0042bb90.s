.section .text
.set noat
.set noreorder
glabel func_0042bb90
    /* 32BB90 0042BB90 7100023C */  lui        $2, %hi(D_0070CCF8)
    /* 32BB94 0042BB94 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32BB98 0042BB98 F8CC458C */  lw         $5, %lo(D_0070CCF8)($2)
    /* 32BB9C 0042BB9C 80180400 */  sll        $3, $4, 2
    /* 32BBA0 0042BBA0 1000BFFF */  sd         $31, 0x10($29)
    /* 32BBA4 0042BBA4 2D20A003 */  daddu      $4, $29, $0
    /* 32BBA8 0042BBA8 04000624 */  addiu      $6, $0, 0x4
    /* 32BBAC 0042BBAC BEAE100C */  jal        func_0042baf8
    /* 32BBB0 0042BBB0 2128A300 */   addu      $5, $5, $3
    /* 32BBB4 0042BBB4 0000A28F */  lw         $2, 0x0($29)
    /* 32BBB8 0042BBB8 1000BFDF */  ld         $31, 0x10($29)
    /* 32BBBC 0042BBBC 0800E003 */  jr         $31
    /* 32BBC0 0042BBC0 2000BD27 */   addiu     $29, $29, 0x20
    /* 32BBC4 0042BBC4 00000000 */  nop
.size func_0042bb90, 0x38

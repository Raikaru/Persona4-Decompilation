.section .text
.set noat
.set noreorder
glabel func_00108dc0
    /* 8DC0 00108DC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 8DC4 00108DC4 0000BFFF */  sd         $31, 0x0($29)
    /* 8DC8 00108DC8 5E00043C */  lui        $4, %hi(D_005E4308)
    /* 8DCC 00108DCC 08438424 */  addiu      $4, $4, %lo(D_005E4308)
    /* 8DD0 00108DD0 E048110C */  jal        func_00452380
    /* 8DD4 00108DD4 00000000 */   nop
    /* 8DD8 00108DD8 06004010 */  beqz       $2, .L00108DF4
    /* 8DDC 00108DDC 00000000 */   nop
    /* 8DE0 00108DE0 2D204000 */  daddu      $4, $2, $0
    /* 8DE4 00108DE4 5849110C */  jal        func_00452560
    /* 8DE8 00108DE8 00000000 */   nop
    /* 8DEC 00108DEC 02000010 */  b          .L00108DF8
    /* 8DF0 00108DF0 00000000 */   nop
  .L00108DF4:
    /* 8DF4 00108DF4 2D100000 */  daddu      $2, $0, $0
  .L00108DF8:
    /* 8DF8 00108DF8 0000BFDF */  ld         $31, 0x0($29)
    /* 8DFC 00108DFC 1000BD27 */  addiu      $29, $29, 0x10
    /* 8E00 00108E00 0800E003 */  jr         $31
    /* 8E04 00108E04 00000000 */   nop
    /* 8E08 00108E08 00000000 */  nop
    /* 8E0C 00108E0C 00000000 */  nop
.size func_00108dc0, 0x50

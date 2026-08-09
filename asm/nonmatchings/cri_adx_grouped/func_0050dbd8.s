.section .text
.set noat
.set noreorder
glabel func_0050dbd8
    /* 40DBD8 0050DBD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DBDC 0050DBDC 2D108000 */  daddu      $2, $4, $0
    /* 40DBE0 0050DBE0 2D18A000 */  daddu      $3, $5, $0
    /* 40DBE4 0050DBE4 04000524 */  addiu      $5, $0, 0x4
    /* 40DBE8 0050DBE8 0000BFFF */  sd         $31, 0x0($29)
    /* 40DBEC 0050DBEC 02004010 */  beqz       $2, .L0050DBF8
    /* 40DBF0 0050DBF0 2D200000 */   daddu     $4, $0, $0
    /* 40DBF4 0050DBF4 3C00448C */  lw         $4, 0x3C($2)
  .L0050DBF8:
    /* 40DBF8 0050DBF8 01000224 */  addiu      $2, $0, 0x1
    /* 40DBFC 0050DBFC 04006214 */  bne        $3, $2, .L0050DC10
    /* 40DC00 0050DC00 0000BFDF */   ld        $31, 0x0($29)
    /* 40DC04 0050DC04 01000624 */  addiu      $6, $0, 0x1
    /* 40DC08 0050DC08 70681408 */  j          func_0051a1c0
    /* 40DC0C 0050DC0C 1000BD27 */   addiu     $29, $29, 0x10
  .L0050DC10:
    /* 40DC10 0050DC10 04000524 */  addiu      $5, $0, 0x4
    /* 40DC14 0050DC14 2D300000 */  daddu      $6, $0, $0
    /* 40DC18 0050DC18 70681408 */  j          func_0051a1c0
    /* 40DC1C 0050DC1C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050dbd8, 0x48

.section .text
.set noat
.set noreorder
glabel func_004b11d0
    /* 3B11D0 004B11D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3B11D4 004B11D4 1000BFFF */  sd         $31, 0x10($29)
    /* 3B11D8 004B11D8 0000B07F */  sq         $16, 0x0($29)
    /* 3B11DC 004B11DC 2D80A000 */  daddu      $16, $5, $0
    /* 3B11E0 004B11E0 03008010 */  beqz       $4, .L004B11F0
    /* 3B11E4 004B11E4 00000000 */   nop
    /* 3B11E8 004B11E8 1005120C */  jal        func_00481440
    /* 3B11EC 004B11EC 00000000 */   nop
  .L004B11F0:
    /* 3B11F0 004B11F0 2D200002 */  daddu      $4, $16, $0
    /* 3B11F4 004B11F4 1C16120C */  jal        func_00485870
    /* 3B11F8 004B11F8 00000000 */   nop
    /* 3B11FC 004B11FC 1000BFDF */  ld         $31, 0x10($29)
    /* 3B1200 004B1200 0000B07B */  lq         $16, 0x0($29)
    /* 3B1204 004B1204 2000BD27 */  addiu      $29, $29, 0x20
    /* 3B1208 004B1208 0800E003 */  jr         $31
    /* 3B120C 004B120C 00000000 */   nop
.size func_004b11d0, 0x40

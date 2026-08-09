.section .text
.set noat
.set noreorder
glabel func_004c7098
    /* 3C7098 004C7098 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C709C 004C709C 1800B1FF */  sd         $17, 0x18($29)
    /* 3C70A0 004C70A0 2D888000 */  daddu      $17, $4, $0
    /* 3C70A4 004C70A4 1000B0FF */  sd         $16, 0x10($29)
    /* 3C70A8 004C70A8 2D282002 */  daddu      $5, $17, $0
    /* 3C70AC 004C70AC 0D002012 */  beqz       $17, .L004C70E4
    /* 3C70B0 004C70B0 2000BFFF */   sd        $31, 0x20($29)
    /* 3C70B4 004C70B4 7500103C */  lui        $16, %hi(D_00757EF8)
    /* 3C70B8 004C70B8 2D30A003 */  daddu      $6, $29, $0
    /* 3C70BC 004C70BC F87E1026 */  addiu      $16, $16, %lo(D_00757EF8)
    /* 3C70C0 004C70C0 6C8C130C */  jal        func_004e31b0
    /* 3C70C4 004C70C4 2D200002 */   daddu     $4, $16, $0
    /* 3C70C8 004C70C8 2D200002 */  daddu      $4, $16, $0
    /* 3C70CC 004C70CC 05004004 */  bltz       $2, .L004C70E4
    /* 3C70D0 004C70D0 2D282002 */   daddu     $5, $17, $0
    /* 3C70D4 004C70D4 3C8C130C */  jal        func_004e30f0
    /* 3C70D8 004C70D8 00000000 */   nop
    /* 3C70DC 004C70DC 0A88130C */  jal        func_004e2028
    /* 3C70E0 004C70E0 0400A48F */   lw        $4, 0x4($29)
  .L004C70E4:
    /* 3C70E4 004C70E4 1000B0DF */  ld         $16, 0x10($29)
    /* 3C70E8 004C70E8 1800B1DF */  ld         $17, 0x18($29)
    /* 3C70EC 004C70EC 2000BFDF */  ld         $31, 0x20($29)
    /* 3C70F0 004C70F0 0800E003 */  jr         $31
    /* 3C70F4 004C70F4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004c7098, 0x60

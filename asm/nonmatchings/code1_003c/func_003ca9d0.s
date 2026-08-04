.section .text
.set noat
.set noreorder
glabel func_003ca9d0
    /* 2CA9D0 003CA9D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CA9D4 003CA9D4 0000BFFF */  sd         $31, 0x0($29)
    /* 2CA9D8 003CA9D8 0800828C */  lw         $2, 0x8($4)
    /* 2CA9DC 003CA9DC 18004010 */  beqz       $2, .L003CAA40
    /* 2CA9E0 003CA9E0 2D288000 */   daddu     $5, $4, $0
    /* 2CA9E4 003CA9E4 1400A28C */  lw         $2, 0x14($5)
    /* 2CA9E8 003CA9E8 15004010 */  beqz       $2, .L003CAA40
    /* 2CA9EC 003CA9EC 00000000 */   nop
    /* 2CA9F0 003CA9F0 0C00A68C */  lw         $6, 0xC($5)
    /* 2CA9F4 003CA9F4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CA9F8 003CA9F8 1000A48C */  lw         $4, 0x10($5)
    /* 2CA9FC 003CA9FC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CAA00 003CAA00 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2CAA04 003CAA04 000086AC */  sw         $6, 0x0($4)
    /* 2CAA08 003CAA08 1000A68C */  lw         $6, 0x10($5)
    /* 2CAA0C 003CAA0C 0C00A48C */  lw         $4, 0xC($5)
    /* 2CAA10 003CAA10 040086AC */  sw         $6, 0x4($4)
    /* 2CAA14 003CAA14 0000A68C */  lw         $6, 0x0($5)
    /* 2CAA18 003CAA18 0400A48C */  lw         $4, 0x4($5)
    /* 2CAA1C 003CAA1C 000086AC */  sw         $6, 0x0($4)
    /* 2CAA20 003CAA20 0400A68C */  lw         $6, 0x4($5)
    /* 2CAA24 003CAA24 0000A48C */  lw         $4, 0x0($5)
    /* 2CAA28 003CAA28 040086AC */  sw         $6, 0x4($4)
    /* 2CAA2C 003CAA2C 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CAA30 003CAA30 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2CAA34 003CAA34 21186400 */  addu       $3, $3, $4
    /* 2CAA38 003CAA38 09F84000 */  jalr       $2
    /* 2CAA3C 003CAA3C 0000648C */   lw        $4, 0x0($3)
  .L003CAA40:
    /* 2CAA40 003CAA40 0000BFDF */  ld         $31, 0x0($29)
    /* 2CAA44 003CAA44 01000224 */  addiu      $2, $0, 0x1
    /* 2CAA48 003CAA48 0800E003 */  jr         $31
    /* 2CAA4C 003CAA4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_003ca9d0, 0x80

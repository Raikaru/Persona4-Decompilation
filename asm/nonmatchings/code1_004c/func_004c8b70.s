.section .text
.set noat
.set noreorder
glabel func_004c8b70
    /* 3C8B70 004C8B70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8B74 004C8B74 7100023C */  lui        $2, %hi(D_00715DB0)
    /* 3C8B78 004C8B78 1800BFFF */  sd         $31, 0x18($29)
    /* 3C8B7C 004C8B7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8B80 004C8B80 B05D5024 */  addiu      $16, $2, %lo(D_00715DB0)
    /* 3C8B84 004C8B84 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8B88 004C8B88 0F001124 */  addiu      $17, $0, 0xF
    /* 3C8B8C 004C8B8C 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8B90 004C8B90 01001224 */  addiu      $18, $0, 0x1
    /* 3C8B94 004C8B94 00000000 */  nop
  .L004C8B98:
    /* 3C8B98 004C8B98 00000282 */  lb         $2, 0x0($16)
    /* 3C8B9C 004C8B9C 04005254 */  bnel       $2, $18, .L004C8BB0
    /* 3C8BA0 004C8BA0 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3C8BA4 004C8BA4 A422130C */  jal        func_004c8a90
    /* 3C8BA8 004C8BA8 2D200002 */   daddu     $4, $16, $0
    /* 3C8BAC 004C8BAC FFFF3126 */  addiu      $17, $17, -0x1
  .L004C8BB0:
    /* 3C8BB0 004C8BB0 F9FF2106 */  bgez       $17, .L004C8B98
    /* 3C8BB4 004C8BB4 44001026 */   addiu     $16, $16, 0x44
    /* 3C8BB8 004C8BB8 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8BBC 004C8BBC 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8BC0 004C8BC0 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8BC4 004C8BC4 1800BFDF */  ld         $31, 0x18($29)
    /* 3C8BC8 004C8BC8 0800E003 */  jr         $31
    /* 3C8BCC 004C8BCC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c8b70, 0x60

.section .text
.set noat
.set noreorder
glabel func_004c6af0
    /* 3C6AF0 004C6AF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C6AF4 004C6AF4 7100023C */  lui        $2, %hi(D_00715CA8)
    /* 3C6AF8 004C6AF8 0800B1FF */  sd         $17, 0x8($29)
    /* 3C6AFC 004C6AFC A85C5124 */  addiu      $17, $2, %lo(D_00715CA8)
    /* 3C6B00 004C6B00 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6B04 004C6B04 2D80A000 */  daddu      $16, $5, $0
    /* 3C6B08 004C6B08 FF000624 */  addiu      $6, $0, 0xFF
    /* 3C6B0C 004C6B0C 2D288000 */  daddu      $5, $4, $0
    /* 3C6B10 004C6B10 1000BFFF */  sd         $31, 0x10($29)
    /* 3C6B14 004C6B14 7A0B110C */  jal        func_00442de8
    /* 3C6B18 004C6B18 2D202002 */   daddu     $4, $17, $0
    /* 3C6B1C 004C6B1C 2D202002 */  daddu      $4, $17, $0
    /* 3C6B20 004C6B20 2D280002 */  daddu      $5, $16, $0
    /* 3C6B24 004C6B24 A00A110C */  jal        func_00442a80
    /* 3C6B28 004C6B28 FF000624 */   addiu     $6, $0, 0xFF
    /* 3C6B2C 004C6B2C 7100033C */  lui        $3, %hi(D_00715CA0)
    /* 3C6B30 004C6B30 A05C638C */  lw         $3, %lo(D_00715CA0)($3)
    /* 3C6B34 004C6B34 04006010 */  beqz       $3, .L004C6B48
    /* 3C6B38 004C6B38 2D282002 */   daddu     $5, $17, $0
    /* 3C6B3C 004C6B3C 7100023C */  lui        $2, %hi(D_00715CA4)
    /* 3C6B40 004C6B40 09F86000 */  jalr       $3
    /* 3C6B44 004C6B44 A45C448C */   lw        $4, %lo(D_00715CA4)($2)
  .L004C6B48:
    /* 3C6B48 004C6B48 2D202002 */  daddu      $4, $17, $0
    /* 3C6B4C 004C6B4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C6B50 004C6B50 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6B54 004C6B54 1000BFDF */  ld         $31, 0x10($29)
    /* 3C6B58 004C6B58 CEC11308 */  j          func_004f0738
    /* 3C6B5C 004C6B5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c6af0, 0x70

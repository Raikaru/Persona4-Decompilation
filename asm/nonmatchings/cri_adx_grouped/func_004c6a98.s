.section .text
.set noat
.set noreorder
glabel func_004c6a98
    /* 3C6A98 004C6A98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6A9C 004C6A9C 7100023C */  lui        $2, %hi(D_00715CA8)
    /* 3C6AA0 004C6AA0 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6AA4 004C6AA4 A85C5024 */  addiu      $16, $2, %lo(D_00715CA8)
    /* 3C6AA8 004C6AA8 2D288000 */  daddu      $5, $4, $0
    /* 3C6AAC 004C6AAC 2D200002 */  daddu      $4, $16, $0
    /* 3C6AB0 004C6AB0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C6AB4 004C6AB4 7A0B110C */  jal        func_00442de8
    /* 3C6AB8 004C6AB8 FF000624 */   addiu     $6, $0, 0xFF
    /* 3C6ABC 004C6ABC 7100033C */  lui        $3, %hi(D_00715CA0)
    /* 3C6AC0 004C6AC0 A05C638C */  lw         $3, %lo(D_00715CA0)($3)
    /* 3C6AC4 004C6AC4 04006010 */  beqz       $3, .L004C6AD8
    /* 3C6AC8 004C6AC8 2D280002 */   daddu     $5, $16, $0
    /* 3C6ACC 004C6ACC 7100023C */  lui        $2, %hi(D_00715CA4)
    /* 3C6AD0 004C6AD0 09F86000 */  jalr       $3
    /* 3C6AD4 004C6AD4 A45C448C */   lw        $4, %lo(D_00715CA4)($2)
  .L004C6AD8:
    /* 3C6AD8 004C6AD8 2D200002 */  daddu      $4, $16, $0
    /* 3C6ADC 004C6ADC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6AE0 004C6AE0 0800BFDF */  ld         $31, 0x8($29)
    /* 3C6AE4 004C6AE4 CEC11308 */  j          func_004f0738
    /* 3C6AE8 004C6AE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6AEC 004C6AEC 00000000 */  nop
.size func_004c6a98, 0x58

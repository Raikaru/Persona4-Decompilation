.section .text
.set noat
.set noreorder
glabel func_003e8a50
    /* 2E8A50 003E8A50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E8A54 003E8A54 02000524 */  addiu      $5, $0, 0x2
    /* 2E8A58 003E8A58 1000BFFF */  sd         $31, 0x10($29)
    /* 2E8A5C 003E8A5C 2D300000 */  daddu      $6, $0, $0
    /* 2E8A60 003E8A60 0000B07F */  sq         $16, 0x0($29)
    /* 2E8A64 003E8A64 2D380000 */  daddu      $7, $0, $0
    /* 2E8A68 003E8A68 8800103C */  lui        $16, %hi(D_008872F0)
    /* 2E8A6C 003E8A6C 2D400000 */  daddu      $8, $0, $0
    /* 2E8A70 003E8A70 F0721026 */  addiu      $16, $16, %lo(D_008872F0)
    /* 2E8A74 003E8A74 FCA10F0C */  jal        func_003e87f0
    /* 2E8A78 003E8A78 2D200002 */   daddu     $4, $16, $0
    /* 2E8A7C 003E8A7C 03004014 */  bnez       $2, .L003E8A8C
    /* 2E8A80 003E8A80 00000000 */   nop
  .L003E8A84:
    /* 2E8A84 003E8A84 1C000010 */  b          .L003E8AF8
    /* 2E8A88 003E8A88 2D100000 */   daddu     $2, $0, $0
  .L003E8A8C:
    /* 2E8A8C 003E8A8C 7100043C */  lui        $4, %hi(D_0070B760)
    /* 2E8A90 003E8A90 8800053C */  lui        $5, %hi(D_008872E0)
    /* 2E8A94 003E8A94 60B78424 */  addiu      $4, $4, %lo(D_0070B760)
    /* 2E8A98 003E8A98 DC8E0F0C */  jal        func_003e3b70
    /* 2E8A9C 003E8A9C E072A524 */   addiu     $5, $5, %lo(D_008872E0)
    /* 2E8AA0 003E8AA0 09004014 */  bnez       $2, .L003E8AC8
    /* 2E8AA4 003E8AA4 00000000 */   nop
    /* 2E8AA8 003E8AA8 2D200002 */  daddu      $4, $16, $0
    /* 2E8AAC 003E8AAC 03000524 */  addiu      $5, $0, 0x3
    /* 2E8AB0 003E8AB0 2D300000 */  daddu      $6, $0, $0
    /* 2E8AB4 003E8AB4 2D380000 */  daddu      $7, $0, $0
    /* 2E8AB8 003E8AB8 FCA10F0C */  jal        func_003e87f0
    /* 2E8ABC 003E8ABC 2D400000 */   daddu     $8, $0, $0
    /* 2E8AC0 003E8AC0 F0FF0010 */  b          .L003E8A84
    /* 2E8AC4 003E8AC4 00000000 */   nop
  .L003E8AC8:
    /* 2E8AC8 003E8AC8 FCAF0F0C */  jal        func_003ebff0
    /* 2E8ACC 003E8ACC 00000CC6 */   lwc1      $f12, 0x0($16)
    /* 2E8AD0 003E8AD0 2D200002 */  daddu      $4, $16, $0
    /* 2E8AD4 003E8AD4 11000524 */  addiu      $5, $0, 0x11
    /* 2E8AD8 003E8AD8 2D300000 */  daddu      $6, $0, $0
    /* 2E8ADC 003E8ADC 2D380000 */  daddu      $7, $0, $0
    /* 2E8AE0 003E8AE0 FCA10F0C */  jal        func_003e87f0
    /* 2E8AE4 003E8AE4 2D400000 */   daddu     $8, $0, $0
    /* 2E8AE8 003E8AE8 03000324 */  addiu      $3, $0, 0x3
    /* 2E8AEC 003E8AEC 8800023C */  lui        $2, %hi(D_00887404)
    /* 2E8AF0 003E8AF0 047443AC */  sw         $3, %lo(D_00887404)($2)
    /* 2E8AF4 003E8AF4 01000224 */  addiu      $2, $0, 0x1
  .L003E8AF8:
    /* 2E8AF8 003E8AF8 1000BFDF */  ld         $31, 0x10($29)
    /* 2E8AFC 003E8AFC 0000B07B */  lq         $16, 0x0($29)
    /* 2E8B00 003E8B00 0800E003 */  jr         $31
    /* 2E8B04 003E8B04 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E8B08 003E8B08 00000000 */  nop
    /* 2E8B0C 003E8B0C 00000000 */  nop
.size func_003e8a50, 0xc0

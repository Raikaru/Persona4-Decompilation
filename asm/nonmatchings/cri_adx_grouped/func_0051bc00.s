.section .text
.set noat
.set noreorder
glabel func_0051bc00
    /* 41BC00 0051BC00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41BC04 0051BC04 2D18A000 */  daddu      $3, $5, $0
    /* 41BC08 0051BC08 FEFF0224 */  addiu      $2, $0, -0x2
    /* 41BC0C 0051BC0C 0000BFFF */  sd         $31, 0x0($29)
    /* 41BC10 0051BC10 0D006210 */  beq        $3, $2, .L0051BC48
    /* 41BC14 0051BC14 2D408000 */   daddu     $8, $4, $0
    /* 41BC18 0051BC18 FFFF6228 */  slti       $2, $3, -0x1
    /* 41BC1C 0051BC1C 06004010 */  beqz       $2, .L0051BC38
    /* 41BC20 0051BC20 FDFF0224 */   addiu     $2, $0, -0x3
    /* 41BC24 0051BC24 0E006210 */  beq        $3, $2, .L0051BC60
    /* 41BC28 0051BC28 0000BFDF */   ld        $31, 0x0($29)
    /* 41BC2C 0051BC2C 13000010 */  b          .L0051BC7C
    /* 41BC30 0051BC30 2D200001 */   daddu     $4, $8, $0
    /* 41BC34 0051BC34 00000000 */  nop
  .L0051BC38:
    /* 41BC38 0051BC38 0F006014 */  bnez       $3, .L0051BC78
    /* 41BC3C 0051BC3C 0000BFDF */   ld        $31, 0x0($29)
    /* 41BC40 0051BC40 12000010 */  b          .L0051BC8C
    /* 41BC44 0051BC44 2D100000 */   daddu     $2, $0, $0
  .L0051BC48:
    /* 41BC48 0051BC48 0F00C01C */  bgtz       $6, .L0051BC88
    /* 41BC4C 0051BC4C 2D100000 */   daddu     $2, $0, $0
    /* 41BC50 0051BC50 0000BFDF */  ld         $31, 0x0($29)
    /* 41BC54 0051BC54 B45E1408 */  j          func_00517ad0
    /* 41BC58 0051BC58 1000BD27 */   addiu     $29, $29, 0x10
    /* 41BC5C 0051BC5C 00000000 */  nop
  .L0051BC60:
    /* 41BC60 0051BC60 0900C01C */  bgtz       $6, .L0051BC88
    /* 41BC64 0051BC64 2D100000 */   daddu     $2, $0, $0
    /* 41BC68 0051BC68 0000BFDF */  ld         $31, 0x0($29)
    /* 41BC6C 0051BC6C B45E1408 */  j          func_00517ad0
    /* 41BC70 0051BC70 1000BD27 */   addiu     $29, $29, 0x10
    /* 41BC74 0051BC74 00000000 */  nop
  .L0051BC78:
    /* 41BC78 0051BC78 2D200001 */  daddu      $4, $8, $0
  .L0051BC7C:
    /* 41BC7C 0051BC7C 2D28E000 */  daddu      $5, $7, $0
    /* 41BC80 0051BC80 B45E1408 */  j          func_00517ad0
    /* 41BC84 0051BC84 1000BD27 */   addiu     $29, $29, 0x10
  .L0051BC88:
    /* 41BC88 0051BC88 0000BFDF */  ld         $31, 0x0($29)
  .L0051BC8C:
    /* 41BC8C 0051BC8C 0800E003 */  jr         $31
    /* 41BC90 0051BC90 1000BD27 */   addiu     $29, $29, 0x10
    /* 41BC94 0051BC94 00000000 */  nop
.size func_0051bc00, 0x98

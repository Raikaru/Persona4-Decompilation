.section .text
.set noat
.set noreorder
glabel func_0050e9d8
    /* 40E9D8 0050E9D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E9DC 0050E9DC 0000B0FF */  sd         $16, 0x0($29)
    /* 40E9E0 0050E9E0 01001024 */  addiu      $16, $0, 0x1
    /* 40E9E4 0050E9E4 06008010 */  beqz       $4, .L0050EA00
    /* 40E9E8 0050E9E8 0800BFFF */   sd        $31, 0x8($29)
    /* 40E9EC 0050E9EC 09009010 */  beq        $4, $16, .L0050EA14
    /* 40E9F0 0050E9F0 2D100002 */   daddu     $2, $16, $0
    /* 40E9F4 0050E9F4 04000010 */  b          .L0050EA08
    /* 40E9F8 0050E9F8 7600043C */   lui       $4, %hi(D_0075F720)
    /* 40E9FC 0050E9FC 00000000 */  nop
  .L0050EA00:
    /* 40EA00 0050EA00 03000010 */  b          .L0050EA10
    /* 40EA04 0050EA04 2D800000 */   daddu     $16, $0, $0
  .L0050EA08:
    /* 40EA08 0050EA08 8844140C */  jal        func_00511220
    /* 40EA0C 0050EA0C 20F78424 */   addiu     $4, $4, %lo(D_0075F720)
  .L0050EA10:
    /* 40EA10 0050EA10 2D100002 */  daddu      $2, $16, $0
  .L0050EA14:
    /* 40EA14 0050EA14 0000B0DF */  ld         $16, 0x0($29)
    /* 40EA18 0050EA18 0800BFDF */  ld         $31, 0x8($29)
    /* 40EA1C 0050EA1C 0800E003 */  jr         $31
    /* 40EA20 0050EA20 1000BD27 */   addiu     $29, $29, 0x10
    /* 40EA24 0050EA24 00000000 */  nop
.size func_0050e9d8, 0x50

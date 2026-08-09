.section .text
.set noat
.set noreorder
glabel func_004edf48
    /* 3EDF48 004EDF48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDF4C 004EDF4C 7400023C */  lui        $2, %hi(D_0073DFE8)
    /* 3EDF50 004EDF50 0000B0FF */  sd         $16, 0x0($29)
    /* 3EDF54 004EDF54 E8DF5024 */  addiu      $16, $2, %lo(D_0073DFE8)
    /* 3EDF58 004EDF58 0000028E */  lw         $2, 0x0($16)
    /* 3EDF5C 004EDF5C 07004014 */  bnez       $2, .L004EDF7C
    /* 3EDF60 004EDF60 0800BFFF */   sd        $31, 0x8($29)
    /* 3EDF64 004EDF64 7400043C */  lui        $4, %hi(D_0073DFF0)
    /* 3EDF68 004EDF68 2D280000 */  daddu      $5, $0, $0
    /* 3EDF6C 004EDF6C F0DF8424 */  addiu      $4, $4, %lo(D_0073DFF0)
    /* 3EDF70 004EDF70 72FE100C */  jal        func_0043f9c8
    /* 3EDF74 004EDF74 00400624 */   addiu     $6, $0, 0x4000
    /* 3EDF78 004EDF78 0000028E */  lw         $2, 0x0($16)
  .L004EDF7C:
    /* 3EDF7C 004EDF7C 01004224 */  addiu      $2, $2, 0x1
    /* 3EDF80 004EDF80 0800BFDF */  ld         $31, 0x8($29)
    /* 3EDF84 004EDF84 000002AE */  sw         $2, 0x0($16)
    /* 3EDF88 004EDF88 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDF8C 004EDF8C 0800E003 */  jr         $31
    /* 3EDF90 004EDF90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDF94 004EDF94 00000000 */  nop
.size func_004edf48, 0x50

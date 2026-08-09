.section .text
.set noat
.set noreorder
glabel func_003b3f50
    /* 2B3F50 003B3F50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2B3F54 003B3F54 0000BFFF */  sd         $31, 0x0($29)
    /* 2B3F58 003B3F58 04008C8C */  lw         $12, 0x4($4)
    /* 2B3F5C 003B3F5C 4800CB8C */  lw         $11, 0x48($6)
    /* 2B3F60 003B3F60 4400CE8C */  lw         $14, 0x44($6)
    /* 2B3F64 003B3F64 80180C00 */  sll        $3, $12, 2
    /* 2B3F68 003B3F68 23006311 */  beq        $11, $3, .L003B3FF8
    /* 2B3F6C 003B3F6C 00008F8C */   lw        $15, 0x0($4)
    /* 2B3F70 003B3F70 2A080500 */  slt        $1, $0, $5
    /* 2B3F74 003B3F74 1E002010 */  beqz       $1, .L003B3FF0
    /* 2B3F78 003B3F78 2DC00000 */   daddu     $24, $0, $0
  .L003B3F7C:
    /* 2B3F7C 003B3F7C 2D68C001 */  daddu      $13, $14, $0
    /* 2B3F80 003B3F80 2138EC01 */  addu       $7, $15, $12
    /* 2B3F84 003B3F84 0000A0C5 */  lwc1       $f0, 0x0($13)
    /* 2B3F88 003B3F88 2130EC00 */  addu       $6, $7, $12
    /* 2B3F8C 003B3F8C 01001827 */  addiu      $24, $24, 0x1
    /* 2B3F90 003B3F90 0800CA25 */  addiu      $10, $14, 0x8
    /* 2B3F94 003B3F94 1000C925 */  addiu      $9, $14, 0x10
    /* 2B3F98 003B3F98 1800C825 */  addiu      $8, $14, 0x18
    /* 2B3F9C 003B3F9C 2120CC00 */  addu       $4, $6, $12
    /* 2B3FA0 003B3FA0 2A180503 */  slt        $3, $24, $5
    /* 2B3FA4 003B3FA4 2170CB01 */  addu       $14, $14, $11
    /* 2B3FA8 003B3FA8 0000E0E5 */  swc1       $f0, 0x0($15)
    /* 2B3FAC 003B3FAC 0400A0C5 */  lwc1       $f0, 0x4($13)
    /* 2B3FB0 003B3FB0 0400E0E5 */  swc1       $f0, 0x4($15)
    /* 2B3FB4 003B3FB4 000040C5 */  lwc1       $f0, 0x0($10)
    /* 2B3FB8 003B3FB8 21788C00 */  addu       $15, $4, $12
    /* 2B3FBC 003B3FBC 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2B3FC0 003B3FC0 040040C5 */  lwc1       $f0, 0x4($10)
    /* 2B3FC4 003B3FC4 0400E0E4 */  swc1       $f0, 0x4($7)
    /* 2B3FC8 003B3FC8 000020C5 */  lwc1       $f0, 0x0($9)
    /* 2B3FCC 003B3FCC 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2B3FD0 003B3FD0 040020C5 */  lwc1       $f0, 0x4($9)
    /* 2B3FD4 003B3FD4 0400C0E4 */  swc1       $f0, 0x4($6)
    /* 2B3FD8 003B3FD8 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2B3FDC 003B3FDC 000080E4 */  swc1       $f0, 0x0($4)
    /* 2B3FE0 003B3FE0 040000C5 */  lwc1       $f0, 0x4($8)
    /* 2B3FE4 003B3FE4 E5FF6014 */  bnez       $3, .L003B3F7C
    /* 2B3FE8 003B3FE8 040080E4 */   swc1      $f0, 0x4($4)
    /* 2B3FEC 003B3FEC 00000000 */  nop
  .L003B3FF0:
    /* 2B3FF0 003B3FF0 08000010 */  b          .L003B4014
    /* 2B3FF4 003B3FF4 0000BFDF */   ld        $31, 0x0($29)
  .L003B3FF8:
    /* 2B3FF8 003B3FF8 1810AC00 */  mult       $2, $5, $12
    /* 2B3FFC 003B3FFC 2D20E001 */  daddu      $4, $15, $0
    /* 2B4000 003B4000 80300200 */  sll        $6, $2, 2
    /* 2B4004 003B4004 54930E0C */  jal        func_003a4d50
    /* 2B4008 003B4008 2D28C001 */   daddu     $5, $14, $0
    /* 2B400C 003B400C F8FF0010 */  b          .L003B3FF0
    /* 2B4010 003B4010 00000000 */   nop
  .L003B4014:
    /* 2B4014 003B4014 0800E003 */  jr         $31
    /* 2B4018 003B4018 1000BD27 */   addiu     $29, $29, 0x10
    /* 2B401C 003B401C 00000000 */  nop
.size func_003b3f50, 0xd0

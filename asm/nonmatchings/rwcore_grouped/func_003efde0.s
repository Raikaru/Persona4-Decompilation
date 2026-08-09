.section .text
.set noat
.set noreorder
glabel func_003efde0
    /* 2EFDE0 003EFDE0 0C00858C */  lw         $5, 0xC($4)
    /* 2EFDE4 003EFDE4 20000224 */  addiu      $2, $0, 0x20
    /* 2EFDE8 003EFDE8 0400888C */  lw         $8, 0x4($4)
    /* 2EFDEC 003EFDEC 0800878C */  lw         $7, 0x8($4)
    /* 2EFDF0 003EFDF0 1000868C */  lw         $6, 0x10($4)
    /* 2EFDF4 003EFDF4 2000A210 */  beq        $5, $2, .L003EFE78
    /* 2EFDF8 003EFDF8 2D180000 */   daddu     $3, $0, $0
    /* 2EFDFC 003EFDFC 08000224 */  addiu      $2, $0, 0x8
    /* 2EFE00 003EFE00 0600A210 */  beq        $5, $2, .L003EFE1C
    /* 2EFE04 003EFE04 00000000 */   nop
    /* 2EFE08 003EFE08 04000224 */  addiu      $2, $0, 0x4
    /* 2EFE0C 003EFE0C 0300A210 */  beq        $5, $2, .L003EFE1C
    /* 2EFE10 003EFE10 00000000 */   nop
    /* 2EFE14 003EFE14 2B000010 */  b          .L003EFEC4
    /* 2EFE18 003EFE18 02000224 */   addiu     $2, $0, 0x2
  .L003EFE1C:
    /* 2EFE1C 003EFE1C 14008A8C */  lw         $10, 0x14($4)
    /* 2EFE20 003EFE20 2A080700 */  slt        $1, $0, $7
    /* 2EFE24 003EFE24 1800858C */  lw         $5, 0x18($4)
    /* 2EFE28 003EFE28 25002010 */  beqz       $1, .L003EFEC0
    /* 2EFE2C 003EFE2C 2D580000 */   daddu     $11, $0, $0
    /* 2EFE30 003EFE30 01000424 */  addiu      $4, $0, 0x1
  .L003EFE34:
    /* 2EFE34 003EFE34 2A080800 */  slt        $1, $0, $8
    /* 2EFE38 003EFE38 2D484001 */  daddu      $9, $10, $0
    /* 2EFE3C 003EFE3C 28002010 */  beqz       $1, .L003EFEE0
    /* 2EFE40 003EFE40 2D600000 */   daddu     $12, $0, $0
    /* 2EFE44 003EFE44 00000000 */  nop
  .L003EFE48:
    /* 2EFE48 003EFE48 00002291 */  lbu        $2, 0x0($9)
    /* 2EFE4C 003EFE4C 80100200 */  sll        $2, $2, 2
    /* 2EFE50 003EFE50 2110A200 */  addu       $2, $5, $2
    /* 2EFE54 003EFE54 03004290 */  lbu        $2, 0x3($2)
    /* 2EFE58 003EFE58 F0004128 */  slti       $1, $2, 0xF0
    /* 2EFE5C 003EFE5C 1C002010 */  beqz       $1, .L003EFED0
    /* 2EFE60 003EFE60 00000000 */   nop
    /* 2EFE64 003EFE64 10004128 */  slti       $1, $2, 0x10
    /* 2EFE68 003EFE68 19002014 */  bnez       $1, .L003EFED0
    /* 2EFE6C 003EFE6C 2D188000 */   daddu     $3, $4, $0
    /* 2EFE70 003EFE70 2B000010 */  b          .L003EFF20
    /* 2EFE74 003EFE74 03000224 */   addiu     $2, $0, 0x3
  .L003EFE78:
    /* 2EFE78 003EFE78 14008C8C */  lw         $12, 0x14($4)
    /* 2EFE7C 003EFE7C 2A080700 */  slt        $1, $0, $7
    /* 2EFE80 003EFE80 0F002010 */  beqz       $1, .L003EFEC0
    /* 2EFE84 003EFE84 2D500000 */   daddu     $10, $0, $0
    /* 2EFE88 003EFE88 01000424 */  addiu      $4, $0, 0x1
    /* 2EFE8C 003EFE8C FF000524 */  addiu      $5, $0, 0xFF
  .L003EFE90:
    /* 2EFE90 003EFE90 2A080800 */  slt        $1, $0, $8
    /* 2EFE94 003EFE94 2D588001 */  daddu      $11, $12, $0
    /* 2EFE98 003EFE98 1B002010 */  beqz       $1, .L003EFF08
    /* 2EFE9C 003EFE9C 2D480000 */   daddu     $9, $0, $0
  .L003EFEA0:
    /* 2EFEA0 003EFEA0 03006291 */  lbu        $2, 0x3($11)
    /* 2EFEA4 003EFEA4 14004510 */  beq        $2, $5, .L003EFEF8
    /* 2EFEA8 003EFEA8 00000000 */   nop
    /* 2EFEAC 003EFEAC 10004128 */  slti       $1, $2, 0x10
    /* 2EFEB0 003EFEB0 11002014 */  bnez       $1, .L003EFEF8
    /* 2EFEB4 003EFEB4 2D188000 */   daddu     $3, $4, $0
    /* 2EFEB8 003EFEB8 19000010 */  b          .L003EFF20
    /* 2EFEBC 003EFEBC 03000224 */   addiu     $2, $0, 0x3
  .L003EFEC0:
    /* 2EFEC0 003EFEC0 02000224 */  addiu      $2, $0, 0x2
  .L003EFEC4:
    /* 2EFEC4 003EFEC4 01000424 */  addiu      $4, $0, 0x1
    /* 2EFEC8 003EFEC8 15000010 */  b          .L003EFF20
    /* 2EFECC 003EFECC 0A108300 */   movz      $2, $4, $3
  .L003EFED0:
    /* 2EFED0 003EFED0 01008C25 */  addiu      $12, $12, 0x1
    /* 2EFED4 003EFED4 2A108801 */  slt        $2, $12, $8
    /* 2EFED8 003EFED8 DBFF4014 */  bnez       $2, .L003EFE48
    /* 2EFEDC 003EFEDC 01002925 */   addiu     $9, $9, 0x1
  .L003EFEE0:
    /* 2EFEE0 003EFEE0 01006B25 */  addiu      $11, $11, 0x1
    /* 2EFEE4 003EFEE4 2A106701 */  slt        $2, $11, $7
    /* 2EFEE8 003EFEE8 D2FF4014 */  bnez       $2, .L003EFE34
    /* 2EFEEC 003EFEEC 21504601 */   addu      $10, $10, $6
    /* 2EFEF0 003EFEF0 F3FF0010 */  b          .L003EFEC0
    /* 2EFEF4 003EFEF4 00000000 */   nop
  .L003EFEF8:
    /* 2EFEF8 003EFEF8 01002925 */  addiu      $9, $9, 0x1
    /* 2EFEFC 003EFEFC 2A102801 */  slt        $2, $9, $8
    /* 2EFF00 003EFF00 E7FF4014 */  bnez       $2, .L003EFEA0
    /* 2EFF04 003EFF04 04006B25 */   addiu     $11, $11, 0x4
  .L003EFF08:
    /* 2EFF08 003EFF08 01004A25 */  addiu      $10, $10, 0x1
    /* 2EFF0C 003EFF0C 2A104701 */  slt        $2, $10, $7
    /* 2EFF10 003EFF10 DFFF4014 */  bnez       $2, .L003EFE90
    /* 2EFF14 003EFF14 21608601 */   addu      $12, $12, $6
    /* 2EFF18 003EFF18 E9FF0010 */  b          .L003EFEC0
    /* 2EFF1C 003EFF1C 00000000 */   nop
  .L003EFF20:
    /* 2EFF20 003EFF20 0800E003 */  jr         $31
    /* 2EFF24 003EFF24 00000000 */   nop
    /* 2EFF28 003EFF28 00000000 */  nop
    /* 2EFF2C 003EFF2C 00000000 */  nop
.size func_003efde0, 0x150
